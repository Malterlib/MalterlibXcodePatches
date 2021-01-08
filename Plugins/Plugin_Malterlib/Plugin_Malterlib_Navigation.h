
- (CNavigationHandler) registerNavigationHandler
{
	return ^NSEvent *(NSEvent *event)
	{
		unsigned short keyCode = [event keyCode];
		//XcodePluginLog(@"%d %@ %@\n", keyCode, [event characters], [event charactersIgnoringModifiers]);
		NSUInteger ModifierFlags = [event modifierFlags];

		bool bHandled = false;

		do
		{
			if
				(
					(keyCode == kVK_ANSI_G)
					&& (ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == NSEventModifierFlagCommand
				)
			{
				// Run

				IDEWorkspaceTabController* pTabController = getWorkspaceTabController([event window]);

				if (!pTabController)
					break;

				IDEWorkspace* pWorkspace = [pTabController workspace];
				if (!pWorkspace)
					break;

				IDERunContextManager* pRunContextManager = [pWorkspace runContextManager];
				if (!pRunContextManager)
					break;

				IDEScheme* pActiveScheme = [pRunContextManager activeRunContext];
				if (!pActiveScheme)
					break;

				IDELaunchSchemeAction* pLaunchAction = [pActiveScheme launchSchemeAction];

				if (!pLaunchAction)
					break;

				if ([pLaunchAction runnable])
					break; // User configured runnable

				NSString *pCustomWorkingDir = [pLaunchAction customWorkingDirectory];

				if ([pCustomWorkingDir compare:@"[MulitLaunchSchemes]"] != NSOrderedSame)
					break; // Magic enable for multil launch


				for (_TtC13IDEFoundation27IDECommandLineArgumentEntry* pCommandLineArg in [pLaunchAction commandLineArgumentEntries])
				{
					if (!pCommandLineArg.isEnabled)
						continue;
					for (IDEScheme* pScheme in [pRunContextManager runContexts])
					{
						if ([[pScheme name] compare:[pCommandLineArg argument]] == NSOrderedSame)
						{
							dispatch_after
								(
									dispatch_time(DISPATCH_TIME_NOW, NSEC_PER_SEC / 100) // 10 ms
									, dispatch_get_main_queue()
									, ^
									{
										[pTabController _runWithoutBuildingForScheme:pScheme runDestination:[pRunContextManager activeRunDestination] invocationRecord:nil];
									}
								)
							;

							bHandled = true;
							//[NSThread sleepForTimeInterval:0.0];
							//XcodePluginLog(@"pScheme %@\n", [pScheme name]);
						}
					}
				}
			}
		}
		while (false)
			;
		if (bHandled)
			return nil;
		return event;
	};
}

static NSView* findSubViewWithClassName(NSView* _pView, char const* _pClassName, int _Depth)
{
	char const* pClassName = object_getClassName([_pView class]);
	if (_Depth >= 0)
		NSLog(@"%@%s", [@"" stringByPaddingToLength:_Depth*3 withString: @" " startingAtIndex:0], pClassName);
	if (strcmp(pClassName, _pClassName) == 0)
		return _pView;
	for (NSView * pView in [_pView subviews])
	{
		NSView * pFound;
		if ((pFound = findSubViewWithClassName(pView, _pClassName, _Depth >= 0 ? _Depth + 1 : _Depth)))
			return pFound;
	}
	return NULL;
}


- (void) frameChanged:(NSNotification*)notification {

	NSView *view = [notification object];

	if (view != nil && [view isMemberOfClass: g_SourceEditorViewClass])
		[self addItemToApplicationMenu];
}

static IDEWorkspaceTabController* getWorkspaceTabController(NSWindow *_pWindow)
{
	if (_pWindow == nil)
		_pWindow = [NSApp keyWindow];
	NSTabView* pView = (NSTabView*)findSubViewWithClassName([_pWindow contentView], "DVTControllerContentView_ControlledBy_IDEWorkspaceTabController", -1);
	if (pView)
	{
		NSViewController* pViewController = (NSViewController*)[pView firstAvailableResponderOfClass: [	NSViewController class]];
		if ([pViewController isKindOfClass:NSClassFromString(@"IDEWorkspaceTabController")])
		{
			return (IDEWorkspaceTabController*)pViewController;
		}
	}
	return nil;
}


