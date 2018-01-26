
#if 0
#define XcodePluginReloadProjectLog(...) NSLog(__VA_ARGS__)
#else
#define XcodePluginReloadProjectLog(...) ((void)0)
#endif

static BOOL fg_ContainerWasGenerated(IDEContainer *_pContainer)
{
	NSNumber *pGenerated = _pContainer.generatedContainer;
	if (!pGenerated)
	{
		do
		{
			DVTFilePath *pFilePath = [_pContainer filePath];
			if (!pFilePath)
				break;
			NSMutableString *pPathString = [NSMutableString stringWithString:[pFilePath pathString]];
			[pPathString appendString:@"/generatedContainer"];

			NSFileManager *fileManager = [NSFileManager defaultManager];
			if ([fileManager fileExistsAtPath: pPathString])
				pGenerated = [NSNumber numberWithBool:YES];
		}
		while (false);

		if (!pGenerated)
			pGenerated = [NSNumber numberWithBool:NO];

		_pContainer.generatedContainer = pGenerated;
	}

	return [pGenerated boolValue];
}


NSHashTable *g_pPendingChanges = NULL;

static _Atomic(int) g_SuspendCount = 0;

// + (void)suspendFilePathChangeNotifications;
static void suspendFilePathChangeNotifications(IDEContainer *_pContainer, SEL _Sel)
{
	++g_SuspendCount;
	XcodePluginReloadProjectLog(@"Suspended: %@ %d\n", _pContainer, g_SuspendCount);

	return ((void(*)(id, SEL))original_suspendFilePathChangeNotifications)(_pContainer, _Sel);
}

//+ (void)resumeFilePathChangeNotifications;
static void resumeFilePathChangeNotifications(IDEContainer *_pContainer, SEL _Sel)
{
	if (g_SuspendCount == 0)
	{
		XcodePluginReloadProjectLog(@"Ignored resume: %@ %d\n", _pContainer, g_SuspendCount);
		return;
	}

	--g_SuspendCount;
	XcodePluginReloadProjectLog(@"Resumed: %@ %d\n", _pContainer, g_SuspendCount);

	return ((void(*)(id, SEL))original_resumeFilePathChangeNotifications)(_pContainer, _Sel);
}

NSObject<IDEContainerReloadingDelegate> *g_pOldDelegate = NULL;
Class Xcode3Project_class = NULL;

static void dispatchClose(IDEDocumentController *_pController, IDEWorkspaceDocument *_pDocument, DVTFilePath *_pFilePath)
{
	dispatch_after
		(
			dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC/10) // 100 ms
			, dispatch_get_main_queue()
			, ^
			{
				if (!_pDocument.isClosed)
				{
					XcodePluginReloadProjectLog(@"Delaying reopen, not closed yet");
					dispatchClose(_pController, _pDocument, _pFilePath);
					return;
				}
				while (g_SuspendCount)
				{
					XcodePluginReloadProjectLog(@"Fixing broken resume count");
					[IDEContainer resumeFilePathChangeNotifications];
				}
				XcodePluginReloadProjectLog(@"Workspace reloading: %@ %d", _pDocument, _pDocument.isClosed);
				[_pController openDocumentWithContentsOfURL: [_pFilePath fileURL] display: YES completionHandler: ^{}];
			}
		)
	;
}

- (int)responseToExternalChangesToBackingFileForContainer:(IDEContainer *)_pContainer fileWasRemoved:(BOOL)arg2
{
	if (!Xcode3Project_class)
		Xcode3Project_class = NSClassFromString(@"Xcode3Project");

	IDEDocumentController *pController = (IDEDocumentController *)g_pOldDelegate;
	if ([_pContainer isKindOfClass:[IDEWorkspace class]])
	{
		XcodePluginReloadProjectLog(@"Workspace: %@", _pContainer);
		IDEWorkspace *pWorkspace = (IDEWorkspace *)_pContainer;

		for (IDEContainer __weak *pContainer in [g_pPendingChanges allObjects])
		{
			if ([pContainer isKindOfClass:Xcode3Project_class])
			{
				XcodePluginReloadProjectLog(@"Remove project: %@", pContainer);
				[g_pPendingChanges removeObject: pContainer];
				continue;
			}
		}

		DVTFilePath *pFilePath = [pWorkspace filePath];
		dispatch_after
			(
				dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC/100) // 10 ms
				, dispatch_get_main_queue()
				, ^
				{
					IDEWorkspaceDocument *pDocument = (IDEWorkspaceDocument *)[pController documentForURL: [pFilePath fileURL]];
					if (!pDocument)
					{
						XcodePluginReloadProjectLog(@"Workspace document not valid: %@", pFilePath);
						return;
					}

					XcodePluginReloadProjectLog(@"Workspace closing: %@", pDocument);
					[pDocument close];

					dispatchClose(pController, pDocument, pFilePath);
				}
			)
		;
		return 1;
	}
	else if ([_pContainer isKindOfClass:Xcode3Project_class])
    {
		XcodePluginReloadProjectLog(@"Project: %@", _pContainer);
        return 0;
    }

	int Ret = [g_pOldDelegate responseToExternalChangesToBackingFileForContainer: _pContainer fileWasRemoved: arg2];

	XcodePluginReloadProjectLog(@"Reload automatically: %@", _pContainer);
	return Ret; // Reload automatically
}

CFTimeInterval g_LastPending = 0.0;

//[IDEWorkspaceDocument close];
//openDocumentWithContentsOfURL:display:completionHandler
static void updateDispatch(void);

static void updatePendingChanges()
{
	if (!g_pPendingChanges || g_pOldDelegate)
	{
		XcodePluginReloadProjectLog(@"!g_pPendingChanges || g_pOldDelegate");
		return;
	}

	if (g_SuspendCount)
	{
		XcodePluginReloadProjectLog(@"Suspended %d", g_SuspendCount);
		updateDispatch();
		return;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (IDEContainer __weak *pContainer in [g_pPendingChanges allObjects])
		{
			if (![pContainer isValid])
			{
				[g_pPendingChanges removeObject: pContainer];
				continue;
			}
			if ([pContainer isKindOfClass:[IDEWorkspace class]] == (i == 0))
			{
				IDEWorkspace *pWorkspace = [pContainer workspace];
				if ([[[pWorkspace executionEnvironment] queuedBuildOperations] count])
				{
					pWorkspace.lastBuilding = [NSNumber numberWithDouble: CACurrentMediaTime()];
					XcodePluginReloadProjectLog(@"Building: %@", pContainer);
					continue;
				}

				CFTimeInterval PendingInterval = CACurrentMediaTime() - g_LastPending;
				if (pWorkspace.lastBuilding)
					PendingInterval = CACurrentMediaTime() - [pWorkspace.lastBuilding doubleValue];

				if (i == 1)
				{
					if (PendingInterval < 0.5)
					{
						XcodePluginReloadProjectLog(@"Delayed: %@ %f", pContainer, PendingInterval);
						continue;
					}
					else
					{
						XcodePluginReloadProjectLog(@"OK: %@, %f", pContainer, PendingInterval);
					}
				}

				XcodePluginReloadProjectLog(@"Dispatching: %@ %f", pContainer, PendingInterval);
				[g_pPendingChanges removeObject: pContainer];
				g_pOldDelegate = [IDEContainer reloadingDelegate];
				[IDEContainer setReloadingDelegate:singleton];
				((void (*)(id self_, SEL _Sel))original_filePathDidChangeWithPendingChangeDictionary)(pContainer, @selector(_filePathDidChangeWithPendingChangeDictionary));
				[IDEContainer setReloadingDelegate:g_pOldDelegate];
				g_pOldDelegate = NULL;
				if (g_SuspendCount)
				{
					updateDispatch();
					return;
				}
			}
		}
	}
	if ([g_pPendingChanges count] == 0)
	{
		g_pPendingChanges = NULL;
		XcodePluginReloadProjectLog(@"g_pPendingChanges = NULL");
		return;
	}
	else
		updateDispatch();
}

static void updateDispatch()
{
	dispatch_after
		(
			dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC / 10) // 100 ms
			, dispatch_get_main_queue()
			, ^
			{
				updatePendingChanges();
			}
		)
	;
}

CFTimeInterval g_First;
// - (void)_filePathDidChangeWithPendingChangeDictionary
static void _filePathDidChangeWithPendingChangeDictionary(IDEContainer *self_, SEL _Sel)
{
	if (!fg_ContainerWasGenerated(self_))
	{
		XcodePluginReloadProjectLog(@"Not generated: %@\n", self_);
		((void (*)(id self_, SEL _Sel))original_filePathDidChangeWithPendingChangeDictionary)(self_, _Sel);
		return;
	}
	IDEContainer *pContainer = self_;
	if (!g_pPendingChanges)
	{
		g_First = CACurrentMediaTime();
		g_pPendingChanges = [NSHashTable hashTableWithOptions:NSPointerFunctionsWeakMemory];
	}

	if (![g_pPendingChanges containsObject: pContainer])
		[g_pPendingChanges addObject: pContainer];

	XcodePluginReloadProjectLog(@"Changed: %@ %f\n", pContainer, CACurrentMediaTime() - g_First);

	g_LastPending = CACurrentMediaTime();

	if ([pContainer isKindOfClass:[IDEWorkspace class]])
		updatePendingChanges();
	else
		updateDispatch();
}

// - (BOOL)_saveContainerForAction:(int)arg1 error:(id *)arg2;
static BOOL _saveContainerForAction(IDEContainer *self_, SEL _Sel, int arg1, id *arg2)
{
	if (!fg_ContainerWasGenerated(self_))
		return ((BOOL (*)(id self_, SEL _Sel, int arg1, id *arg2))original_saveContainerForAction)(self_, _Sel, arg1, arg2);

	if (!Xcode3Project_class)
		Xcode3Project_class = NSClassFromString(@"Xcode3Project");

	//XcodePluginReloadProjectLog(@"Prevented save: %@", self_);

	if ([self_ isKindOfClass:Xcode3Project_class])
	{
		Xcode3Project *pProject = (Xcode3Project *)self_;
		pProject.pbxProjectEdited = NO;
	}

	return TRUE;
}


// - (BOOL)canSaveContainer;
static BOOL canSaveContainer(IDEContainer *self_, SEL _Sel)
{
	if (!fg_ContainerWasGenerated(self_))
		return ((BOOL (*)(id self_, SEL _Sel))original_canSaveContainer)(self_, _Sel);
	return true;
}
