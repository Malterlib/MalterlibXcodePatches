static bool displayRecentsMenu(NSMenu* _pMenu, NSView* _pView, bool _bPretend)
{
	bool bFoundRecents = false;
	NSMenuItem* pFirstRecentItem = nil;
	for (NSMenuItem* pItem in [_pMenu itemArray])
	{
		if (bFoundRecents)
		{
			pFirstRecentItem = pItem;
			break;
		}
		if ([[pItem title] compare:@"Recent Queries"] == NSOrderedSame || [[pItem title] compare:@"Recent Searches"] == NSOrderedSame)
			bFoundRecents = true;
	}

	if (pFirstRecentItem)
	{
		if (_bPretend)
			return true;
		NSPoint Location;
		Location.x = 0;
		Location.y = 0;
		[_pMenu popUpMenuPositioningItem:pFirstRecentItem atLocation:Location inView:_pView];
		return true;
	}
	return false;
}

static bool findFieldHasFocusInBatchNavigator(IDEFindNavigator* _pNavigator)
{
	IDEProgressSearchField *pField = [_pNavigator.queryParametersController findFieldForField: nil];
	if (pField)
	{
		DVTFindPatternFieldEditor* pFirstResponder = (DVTFindPatternFieldEditor*)[[pField window] firstResponder];
		if ([pFirstResponder isKindOfClass:[DVTFindPatternFieldEditor class]])
		{
			if ((id)[pFirstResponder delegate] == pField)
				return true;
		}
	}
	return false;
}

/*
static bool findFieldHasFocusInFindBar(SourceEditor_SourceEditorTextFindPanel *_pFindBar)
{
	IDEProgressSearchField *pField = [_pFindBar findField];
	if (pField)
	{
		DVTFindPatternFieldEditor* pFirstResponder = (DVTFindPatternFieldEditor*)[[pField window] firstResponder];
		if ([pFirstResponder isKindOfClass:[DVTFindPatternFieldEditor class]])
		{
			if ([pField _fieldEditor] == pFirstResponder)
				return true;
		}
	}
	return false;
}
 */

static long long batchFind_getSelectedQueryAction(IDEFindNavigatorQueryParametersController *_pBatchFindController)
{
	NSNumber *pValue = [_pBatchFindController valueForKey:@"_selectedQueryAction"];
	return pValue.longLongValue;
}

static BOOL batchFind_selectedMatchCase(IDEFindNavigatorQueryParametersController *_pBatchFindController)
{
	NSNumber *pValue = [_pBatchFindController valueForKey:@"_selectedMatchCase"];
	return pValue.boolValue;
}

static BOOL batchFind_selectedAnchoring(IDEFindNavigatorQueryParametersController *_pBatchFindController)
{
	NSNumber *pValue = [_pBatchFindController valueForKey:@"_selectedAnchoring"];
	return pValue.longLongValue;
}

static Class batchFind_selectedQueryClass(IDEFindNavigatorQueryParametersController *_pBatchFindController)
{
	return [_pBatchFindController valueForKey:@"_selectedQueryClass"];
}

static bool replaceEnabled(IDEFindNavigator* _pNavigator)
{
	return batchFind_getSelectedQueryAction(_pNavigator.queryParametersController) == 1;
}

static bool replaceEnabledOnFindBar(SourceEditor_SourceEditorTextFindPanel *_pFindBar)
{
	Ivar ivar = class_getInstanceVariable(NSClassFromString(@"SourceEditor.SourceEditorTextFindPanel"), "mode");

	ptrdiff_t offset = ivar_getOffset(ivar);
	unsigned char* bytes = (unsigned char *)(__bridge void*)_pFindBar;
	int modeValue = *((int *)(bytes+offset));

	return modeValue == 1;
}

static IDEProgressSearchField *getReplaceField(IDEFindNavigator* _pNavigator)
{
	return [_pNavigator.queryParametersController replaceFieldForField: nil];
}

static IDEProgressSearchField *getFindField(IDEFindNavigator* _pNavigator)
{
	return [_pNavigator.queryParametersController findFieldForField: nil];
}

static bool replaceFieldHasFocusInBatchNavigator(IDEFindNavigator* _pNavigator)
{
	IDEProgressSearchField *pField = [_pNavigator.queryParametersController replaceFieldForField: nil];
	if (pField)
	{
		DVTFindPatternFieldEditor* pFirstResponder = (DVTFindPatternFieldEditor*)[[pField window] firstResponder];
		if ([pFirstResponder isKindOfClass:[DVTFindPatternFieldEditor class]])
		{
			if ((id)[pFirstResponder delegate] == pField)
				return true;
		}
	}
	return false;
}

static bool findFieldHasFocus(DVTFindPatternSearchField *_pSearchField)
{
	NSResponder *firstResponder = [[NSApp keyWindow] firstResponder];
	return [firstResponder isKindOfClass:[NSText class]] && [(id)firstResponder delegate] == _pSearchField;
}

typedef NSMenu * (^FSearchMenuGenerate)(void);

static bool handleFieldEditorEvent(unsigned short keyCode, NSUInteger ModifierFlags, NSEvent *event)
{
	NSWindow *window = event.window;
	if (!window)
		window = [NSApp keyWindow];

	SourceEditor_SourceEditorTextFindPanel *pFindBar = getFindBar(window.navigationFixesProperties.respondingPatternFieldEditor);
	IDEFindNavigatorQueryParametersController *pBatchFindController = nil;

	if (!pFindBar)
		pBatchFindController = getBatchFindStrategiesController(window.navigationFixesProperties.respondingPatternFieldEditor);

	if (keyCode == kVK_Return)
	{
		NSObject *firstResponder = window.firstResponder;

		if ([firstResponder isKindOfClass:NSClassFromString(@"IDEFindNavigatorScopeOutlineView")])
		{
			if (!event)
				return true;

			NSOutlineView *pFindScopeOutlineView = (NSOutlineView *)firstResponder;
			IDEFindNavigatorScopeChooserController *scopeChooser = (IDEFindNavigatorScopeChooserController *)pFindScopeOutlineView.delegate;
			pBatchFindController = (IDEFindNavigatorQueryParametersController *)scopeChooser.delegate;

			DVTScopeBarButton *showScopesButton = [pBatchFindController valueForKey:@"_showScopesButton"];
			[showScopesButton performClick:nil];

			[pFindScopeOutlineView.window makeFirstResponder: [pBatchFindController findFieldForField: nil]];

			return true;
		}

	}

	if ((ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == NSEventModifierFlagControl)
	{
		// Control

		if (keyCode == kVK_ANSI_N && pFindBar)
		{
			if (!event)
				return true;
			IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);
			[pEditor.sourceEditorView findNext: nil];
			return true;
		}
		else if (keyCode == kVK_ANSI_R)
		{
			if (pBatchFindController)
			{
				IDEFindNavigator* pNavigator = getBatchFindNavigator(window.navigationFixesProperties.respondingPatternFieldEditor);
				if (pNavigator && replaceEnabled(pNavigator))
				{
					if (!event)
						return true;
					[pBatchFindController replaceSelectedItems: nil];
					return true;
				}
			}
			else if (pFindBar && replaceEnabledOnFindBar(pFindBar))
			{
				if (!event)
					return true;
				IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);
				[pEditor.sourceEditorView replaceAndFindNext: nil];
				return true;
			}
		}
		else if (keyCode == kVK_ANSI_A)
		{
			if (pBatchFindController)
			{
				IDEFindNavigator* pNavigator = getBatchFindNavigator(window.navigationFixesProperties.respondingPatternFieldEditor);
				if (pNavigator && replaceEnabled(pNavigator))
				{
					if (!event)
						return true;

					[pBatchFindController replaceAllItems:nil];
					return true;
				}
			}
			else if (pFindBar && replaceEnabledOnFindBar(pFindBar))
			{
				if (!event)
					return true;
				IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);
				[pEditor.sourceEditorView replaceAll: nil];
				return true;
			}
		}
		else if (keyCode == kVK_ANSI_C)
		{
			if (pBatchFindController)
			{
				if (!event)
					return true;

				[pBatchFindController selectMatchCase:!batchFind_selectedMatchCase(pBatchFindController)];
				return true;
			}
			else if (pFindBar)
			{
				if (!event)
					return true;

				NSButton *button = [pFindBar caseSensitiveButton];

				if (button.state == NSControlStateValueOn)
					button.state = NSControlStateValueOff;
				else
					button.state = NSControlStateValueOn;

				[pFindBar caseSensitiveButtonAction: button];
				return true;
			}
		}
		else if (keyCode == kVK_ANSI_E)
		{
			if (pBatchFindController)
			{
				if (!event)
					return true;
				Class queryClass = batchFind_selectedQueryClass(pBatchFindController);

				// IDEBatchFindRegularExpressionQuery
				if (queryClass == NSClassFromString(@"IDEBatchFindTextQuery"))
					queryClass = NSClassFromString(@"IDEBatchFindRegularExpressionQuery");
				else
					queryClass = NSClassFromString(@"IDEBatchFindTextQuery");

				[pBatchFindController selectQueryClass:queryClass];
				return true;
			}
			else if (pFindBar)
			{
				if (!event)
					return true;

				NSPopUpButton *searchPatternPopUp = [pFindBar searchPatternPopUp];

				if ([searchPatternPopUp.selectedItem.title isEqualToString: @"Regular Expression"])
					[searchPatternPopUp selectItemWithTitle: @"Contains"];
				else
					[searchPatternPopUp selectItemWithTitle: @"Regular Expression"];

				[pFindBar searchPatternPopUpAction: searchPatternPopUp];

				return true;
			}
		}
		else if (keyCode == kVK_ANSI_W)
		{
			if (pBatchFindController)
			{
				if (!event)
					return true;

				long long selectedAnchoring = batchFind_selectedAnchoring(pBatchFindController);

				if (selectedAnchoring == 0)
					selectedAnchoring = 3;
				else
					selectedAnchoring = 0;

				[pBatchFindController selectQueryAnchoring: selectedAnchoring];
				return true;
			}
			else if (pFindBar)
			{
				if (!event)
					return true;

				NSPopUpButton *searchPatternPopUp = [pFindBar searchPatternPopUp];

				if ([searchPatternPopUp.selectedItem.title isEqualToString: @"Matches Word"])
					[searchPatternPopUp selectItemWithTitle: @"Contains"];
				else
					[searchPatternPopUp selectItemWithTitle: @"Matches Word"];

				[pFindBar searchPatternPopUpAction: searchPatternPopUp];

				return true;
			}
		}
		else if (keyCode == kVK_ANSI_L)
		{
			if (pBatchFindController)
			{
				if (!event)
					return true;
				DVTScopeBarButton *showScopesButton = [pBatchFindController valueForKey:@"_showScopesButton"];
				[showScopesButton performClick:nil];

				return true;
			}
		}
		else if (keyCode == kVK_ANSI_H)
		{
			if (!event)
				return true;
			do
			{
				NSWindow* window = nil;
				if (event)
					window = [event window];
				else
					window = [NSApp keyWindow];

				if (!window)
					break;

				IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);

				NSRange LineRange = [pEditor selectedLineRange];

				static Ivar s_AnnotationManagerIvar = nil;
				if (!s_AnnotationManagerIvar)
					s_AnnotationManagerIvar = class_getInstanceVariable(NSClassFromString(@"IDESourceEditor.SourceCodeEditor"), "annotationManager");

				DVTAnnotationManager* pAnnotationManager = object_getIvar(pEditor, s_AnnotationManagerIvar);
				if (!pAnnotationManager)
					break;

				IDEWorkspaceTabController* pTabController = getWorkspaceTabController(window);
				if (!pTabController)
					break;

				IDEWorkspace* pWorkspace = [pTabController workspace];
				if (!pWorkspace)
					break;

				IDEBreakpointManager* pBreakpointManager = [pWorkspace breakpointManager];
				if (!pBreakpointManager)
					break;

				NSMutableArray* pBreakpointsToDelete = [[NSMutableArray alloc] initWithCapacity:16];

				NSMutableArray *pAnnotationProviders = [pAnnotationManager valueForKey:@"annotationProviders"];

				for (NSDictionary* pProviderDict in pAnnotationProviders)
				{
					DVTAnnotationProvider* pProvider = (DVTAnnotationProvider*)[pProviderDict valueForKey:@"annotationProviderObject"];

					if ([pProvider isKindOfClass:NSClassFromString(@"DBGBreakpointAnnotationProvider")])
					{
						DBGBreakpointAnnotationProvider* pBreakpointProvider = (DBGBreakpointAnnotationProvider*)pProvider;

						for (DBGBreakpointAnnotation* pAnnotation in [pBreakpointProvider annotations])
						{
							NSRange BreakpointRange = [pAnnotation paragraphRange];
							if (BreakpointRange.length == 0)
								BreakpointRange.length += 1;

							if (NSIntersectionRange(LineRange, BreakpointRange).length == 0)
								continue;

							if ([[pAnnotation representedObject] isKindOfClass:NSClassFromString(@"IDEBreakpoint")])
							{
								IDEBreakpoint* pBreakpoint = (IDEBreakpoint*)[pAnnotation representedObject];
								[pBreakpointsToDelete addObject:pBreakpoint];
							}
						}
					}
				}

				if ([pBreakpointsToDelete count] > 0)
				{
					for (IDEBreakpoint* pBreakpoint in pBreakpointsToDelete)
						[pBreakpointManager removeBreakpoint:pBreakpoint];
					return true;
				}
				else
				{
					IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);
					[pEditor toggleBreakpointAtCurrentLine: nil];
					return true;
				}
			}
			while (false)
				;
		}
	}
	if ((ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == (NSEventModifierFlagControl | NSEventModifierFlagShift))
	{
		// Control + shift
		if (keyCode == kVK_ANSI_N)
		{
			if (!event)
				return true;

			IDESourceEditor_SourceCodeEditor *pEditor = getEditor(window);
			[pEditor.sourceEditorView findPrevious: nil];
			return true;
		}
	}

	if (!event)
		return false;

	window = event.window;

	if (!window)
		return false;

	if (!pFindBar && !window.navigationFixesProperties.findBarOptionsCtrl && !pBatchFindController)
		return false;

	if ((ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == 0)
	{
		// Alone key
		if (keyCode == kVK_DownArrow)
		{
			if (pBatchFindController)
			{
				IDEFindNavigator* pNavigator = getBatchFindNavigator(window.navigationFixesProperties.respondingPatternFieldEditor);
				if (pNavigator)
				{
					if (findFieldHasFocusInBatchNavigator(pNavigator))
					{
						IDEProgressSearchField *pField = (IDEProgressSearchField *)getFindField(pNavigator);

						FSearchMenuGenerate fSearchMenuGenerate = (FSearchMenuGenerate)[pField searchMenuBlock];
						NSMenu *pMenu = fSearchMenuGenerate();

						if (displayRecentsMenu(pMenu, pField, false))
							return true;
					}
				}
			}
			else if (pFindBar)
			{
				DVTFindPatternSearchField *pFindField = [pFindBar findField];
				if (pFindField && findFieldHasFocus(pFindField))
				{
					[XcodePluginNavigationFixes_Navigation updatePanelModePopup: (SourceEditorTextFindPanel *)pFindBar];

					Ivar ivar = class_getInstanceVariable(NSClassFromString(@"SourceEditor.SourceEditorTextFindPanel"), "panelModePopUp");

					ptrdiff_t offset = ivar_getOffset(ivar);
					unsigned char* bytes = (unsigned char *)(__bridge void*)pFindBar;

					NSPopUpButton *popupButton = (__bridge NSPopUpButton *)*((void **)((size_t)(bytes+offset)));

					NSMenu *pMenu = [popupButton menu];
					pMenu.font = [NSFont menuFontOfSize: 12.0];

					if (displayRecentsMenu(pMenu, pFindField, false))
						return true;
				}
			}
		}
		else if (keyCode == kVK_Escape)
		{
			if (pBatchFindController)
			{
				if (!event)
					return true;

				setEditorFocus([event window]);
				return true;
			}
		}
	}
	if ((ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == NSEventModifierFlagShift
		|| (ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption | NSEventModifierFlagShift)) == 0)
	{
		// Shift key
		if (keyCode == kVK_Tab )
		{
			if (pBatchFindController)
			{
				IDEFindNavigator* pNavigator = getBatchFindNavigator(window.navigationFixesProperties.respondingPatternFieldEditor);
				if (pNavigator)
				{
					if (replaceFieldHasFocusInBatchNavigator(pNavigator))
					{
						IDEProgressSearchField *pFindField = getFindField(pNavigator);
						if (pFindField && replaceEnabled(pNavigator))
						{
							if (!event)
								return true;
							[window makeFirstResponder: pFindField];
							return true;
						}
					}
					else if (findFieldHasFocusInBatchNavigator(pNavigator))
					{
						IDEProgressSearchField *pReplaceField = getReplaceField(pNavigator);
						if (pReplaceField && replaceEnabled(pNavigator))
						{
							[window makeFirstResponder: pReplaceField];
							return true;
						}
					}
				}
			}
			else if (pFindBar)
			{
				DVTFindPatternSearchField *pReplaceField = [pFindBar replaceField];
				DVTFindPatternSearchField *pFindField = [pFindBar findField];
				if (findFieldHasFocus(pReplaceField) && replaceEnabledOnFindBar(pFindBar))
				{
					[window makeFirstResponder: [pFindBar findField]];
					return true;
				}
				else if (findFieldHasFocus(pFindField) && replaceEnabledOnFindBar(pFindBar))
				{
					[window makeFirstResponder: [pFindBar replaceField]];
					return true;
				}
			}
		}
	}


	return false;
}

+ (void) sendKeyToOutlineView: (DVTOutlineView *)outlineView keyCode: (NSUInteger)keyCode characterCode: (unichar)characterCode window:(NSWindow *)window
{
	NSEvent *pEvent = [
		NSEvent keyEventWithType:NSEventTypeKeyDown
		location:[window mouseLocationOutsideOfEventStream]
		modifierFlags:0xa00100
		timestamp:0.0
		windowNumber:[window windowNumber]
		context:nil
		characters:[NSString stringWithFormat: @"%C", characterCode]
		charactersIgnoringModifiers:[NSString stringWithFormat: @"%C", characterCode]
		isARepeat:false
		keyCode:keyCode
	];

	[outlineView keyDown: pEvent];

	NSEvent *pEventUp = [
		NSEvent keyEventWithType:NSEventTypeKeyUp
		location:[window mouseLocationOutsideOfEventStream]
		modifierFlags:0xa00100
		timestamp:0.0
		windowNumber:[window windowNumber]
		context:nil
		characters:[NSString stringWithFormat: @"%C", characterCode]
		charactersIgnoringModifiers:[NSString stringWithFormat: @"%C", characterCode]
		isARepeat:false
		keyCode:keyCode
	];
	[outlineView keyUp: pEventUp];
}

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
			if (handleFieldEditorEvent(keyCode, ModifierFlags, event))
				return nil;

			if
				(
				 ((keyCode == kVK_ANSI_N) && (ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption)) == NSEventModifierFlagCommand)
				 || ((keyCode == kVK_ANSI_N) && (ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption)) == (NSEventModifierFlagCommand | NSEventModifierFlagControl))
				)
			{
				NSWindow *window = [event window];
				if (!window.navigationFixesProperties.initializedPotentialViews)
					potentialView(window);

				bool bExpandNext = (ModifierFlags & (NSEventModifierFlagCommand | NSEventModifierFlagControl | NSEventModifierFlagOption)) == (NSEventModifierFlagCommand | NSEventModifierFlagControl);
				bool bIsValid = (window.navigationFixesProperties.activeDVTExplorerOutlineView && window.navigationFixesProperties.activeDVTExplorerOutlineView.hasContent) || window.navigationFixesProperties.activeFindNavigatorOutlineView;
				NSWindowTabGroup *pTabGroup = [[event window] tabGroup];

				if (!bIsValid)
				{
					if (window.navigationFixesProperties.consoleLastText)
						pTabGroup.preferredNextLocation = EPreferredNextLocation_Console;
				}
				if (pTabGroup.preferredNextLocation == EPreferredNextLocation_Console)
				{
					if (window.navigationFixesProperties.consoleLastText)
					{
						bHandled = true;
						navigateToNextInLastConsoleText(window, ModifierFlags & NSEventModifierFlagShift);
					}
				}
				else if (bIsValid)
				{
					bool bSetEditorFocus = false;

					if (window.navigationFixesProperties.activeFindNavigator)
					{
						IDEFindNavigatorQueryResultsController *pResultsController = window.navigationFixesProperties.activeFindNavigator.resultsController;

						NSSet *pSelected = [pResultsController selectedResults];

						IDEBatchFindAbstractResult* pLastSelected = nil;
						if ([pSelected count] > 0)
							pLastSelected = (IDEBatchFindAbstractResult*)pSelected.anyObject;

						IDEFindNavigatorOutlineView *outlineView = pResultsController.outlineView;
						NSInteger nRows = outlineView.numberOfRows;


						NSInteger row = [outlineView rowForItem: pLastSelected];

						NSInteger startRow = row;

						if (ModifierFlags & NSEventModifierFlagShift)
						{
							--row;
							if (row < 0)
								row = nRows - 1;
						}
						else
						{
							++row;
							if (row == nRows)
								row = 0;
						}

						IDEBatchFindAbstractResult *iResult = [outlineView itemAtRow: row];

						while (iResult && row != startRow && [iResult isKindOfClass: IDEBatchFindFileResult.class])
						{
							if (ModifierFlags & NSEventModifierFlagShift)
							{
								--row;
								if (row < 0)
									row = nRows - 1;
							}
							else
							{
								++row;
								if (row == nRows)
									row = 0;
							}

							iResult = [outlineView itemAtRow: row];
						}

						[outlineView selectRowIndexes: [NSIndexSet indexSetWithIndex: row] byExtendingSelection: NO];
						[outlineView scrollRowToVisible: row];

						bSetEditorFocus = true;
						bHandled = true;
					}
					else if (window.navigationFixesProperties.activeDVTExplorerOutlineView)
					{
						DVTOutlineView *outlineView = window.navigationFixesProperties.activeDVTExplorerOutlineView;

						NSInteger row = outlineView.selectedRowIndexes.lastIndex;
						NSInteger nRows = outlineView.numberOfRows;

						if (ModifierFlags & NSEventModifierFlagShift)
						{
							if (bExpandNext)
								return nil; // Does not work

							if (row == 0)
							{
								[outlineView selectRowIndexes: [NSIndexSet indexSetWithIndex: nRows - 1] byExtendingSelection: NO];
								[outlineView scrollRowToVisible: nRows - 1];

								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_UpArrow characterCode: NSUpArrowFunctionKey window: window];
								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_DownArrow characterCode: NSDownArrowFunctionKey window: window];
							}
							else
							{
								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_UpArrow characterCode: NSUpArrowFunctionKey window: window];
							}
						}
						else
						{
							if (bExpandNext)
							{
								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_RightArrow characterCode: NSRightArrowFunctionKey window: window];
								row = outlineView.selectedRowIndexes.lastIndex;
								nRows = outlineView.numberOfRows;
							}

							if (row == nRows - 1)
							{
								[outlineView selectRowIndexes: [NSIndexSet indexSetWithIndex: 0] byExtendingSelection: NO];
								[outlineView scrollRowToVisible: 0];

								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_DownArrow characterCode: NSDownArrowFunctionKey window: window];
								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_UpArrow characterCode: NSUpArrowFunctionKey window: window];
							}
							else
								[Plugin_NavigationFixes sendKeyToOutlineView: outlineView keyCode: kVK_DownArrow characterCode: NSDownArrowFunctionKey window: window];
						}

						bSetEditorFocus = true;
						bHandled = true;
					}
					if (bSetEditorFocus)
						setEditorFocus(window);
				}
				return nil;
			}
		}
		while (false)
			;
		if (bHandled)
			return nil;
		return event;
	};
}

static void IDEFindNavigatorScopeChooserController_viewDidInstall(IDEFindNavigatorScopeChooserController *self_, SEL _cmd)
{
	((void (*)(id, SEL))original_IDEFindNavigatorScopeChooserController_viewDidInstall)(self_, _cmd);

	NSOutlineView *scopeChooserOutlineView = [self_ valueForKey:@"_scopeChooserOutlineView"];

	[scopeChooserOutlineView.window makeFirstResponder: scopeChooserOutlineView];
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

static NSView *findSubViewWithClass(NSView* _pView, Class _pClassToFind)
{
	if ([_pView isKindOfClass:_pClassToFind])
		 return _pView;
	for (NSView * pView in [_pView subviews])
	{
		NSView * pFound;
		if ((pFound = findSubViewWithClass(pView, _pClassToFind)))
			return pFound;
	}

	return NULL;
}

#if 0
static NSView* findSubViewWithController(NSView* _pView, Class ClassToFind)
{
	NSViewController* pViewController = (NSViewController*)[_pView firstAvailableResponderOfClass:ClassToFind];
	if (pViewController)
		return _pView;
	for (NSView * pView in [_pView subviews])
	{

		NSView * pFound;
		if ((pFound = findSubViewWithController(pView, ClassToFind)))
			return pFound;
	}
	return NULL;
}

static NSViewController *findController(NSView* _pView, Class ClassToFind)
{
	NSViewController *pViewController = (NSViewController*)[_pView firstAvailableResponderOfClass:ClassToFind];
	if (pViewController)
		return pViewController;
	for (NSView *pView in [_pView subviews])
	{
		NSViewController *pFound;
		if ((pFound = findController(pView, ClassToFind)))
			return pFound;
	}
	return NULL;
}
#endif

static NSView* findParentViewWithClassName(NSView* _pView, char const* _pClassName, bool _bTrace)
{
	char const* pClassName = object_getClassName([_pView class]);
	if (_bTrace)
		NSLog(@"%s", pClassName);
	if (strcmp(pClassName, _pClassName) == 0)
		return _pView;
	NSView * pView;
	if ((pView = [_pView superview]))
	{
		NSView * pFound;
		if ((pFound = findParentViewWithClassName(pView, _pClassName, _bTrace)))
			return pFound;
	}
	return NULL;
}

#if 0
static NSView* findParentViewWithController(NSView* _pView, Class ClassToFind)
{
	NSViewController* pViewController = (NSViewController*)[_pView firstAvailableResponderOfClass:ClassToFind];
	if (pViewController)
		return _pView;
	NSView * pView;
	if ((pView = [_pView superview]))
	{
		NSView * pFound;
		if ((pFound = findParentViewWithController(pView, ClassToFind)))
			return pFound;
	}
	return NULL;
}
#endif

- (void)windowDidBecomeKey:(NSNotification *)notification
{
	//pTabGroup.preferredNextLocation = EPreferredNextLocation_Undefined;

	NSWindow *window = [notification object];

	updateLastValidEditorTab(window);
	potentialView(window);
}


- (void)popoverDidShowNotification:(NSNotification *)notification
{
	NSWindow *window = [notification object];
	NSPopover* pPopover = [notification object];
	DVTFindBarOptionsCtrl* pViewController = (DVTFindBarOptionsCtrl*)[pPopover contentViewController];
	if ([pViewController isKindOfClass:[DVTFindBarOptionsCtrl class]])
	{
		window.navigationFixesProperties.findBarOptionsCtrl = pViewController;
	}
}

- (void)popoverWillCloseNotification:(NSNotification *)notification
{
	NSPopover* pPopover = [notification object];
	NSWindow *window = [notification object];
	DVTFindBarOptionsCtrl* pViewController = (DVTFindBarOptionsCtrl*)[pPopover contentViewController];
	if ([pViewController isKindOfClass:[DVTFindBarOptionsCtrl class]])
	{
		if (window.navigationFixesProperties.findBarOptionsCtrl == pViewController)
			window.navigationFixesProperties.findBarOptionsCtrl = nil;
	}
}

static void potentialView(NSWindow* _pWindow)
{
	NSWindow *window = _pWindow;

	//XcodePluginDumpClass([window firstResponder].class);

	//XcodePluginTraceViewHierarchy([_pWindow contentView], 0);

	IDEWorkspaceTabController *pTabController = getWorkspaceTabController(_pWindow);
	if (!pTabController)
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeIssueNavigator = nil;
		window.navigationFixesProperties.activeFindNavigator = nil;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = nil;
		return;
	}

	IDENavigator *pCurrentNavigator = pTabController.navigatorArea.currentNavigator;

	if (!pCurrentNavigator)
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeIssueNavigator = nil;
		window.navigationFixesProperties.activeFindNavigator = nil;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = nil;
		return;
	}

	IDEFindNavigatorOutlineView *pFindNavigatorOutlineView = (IDEFindNavigatorOutlineView *)findSubViewWithClass(pCurrentNavigator.view, IDEFindNavigatorOutlineView.class);
	IDENavigatorOutlineView *pNavigatorOutlineView = (IDENavigatorOutlineView *)findSubViewWithClass(pCurrentNavigator.view, IDENavigatorOutlineView.class);
	DVTOutlineView *pDVTExplorerOutlineView = (DVTOutlineView *)findSubViewWithClass(pCurrentNavigator.view, DVTOutlineView.class);

	if (!window.navigationFixesProperties.initializedPotentialViews)
		window.navigationFixesProperties.initializedPotentialViews = TRUE;

	/*
	 IDEWorkspaceNavigator
	 IDESourceControlUI.SourceControlNavigator
	 IDESymbolNavigator
	 IDEFindNavigator
	 IDEIssueNavigator
	 IDETestNavigator
	 IDEDebugNavigator
	 IDEBreakpointNavigableNavigator
	 IDELogNavigator
	 */

	//XcodePluginDumpClass(pCurrentNavigator.class);

	if ([pCurrentNavigator isKindOfClass:[IDEFindNavigator class]])
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = pFindNavigatorOutlineView;
		window.navigationFixesProperties.activeNavigatorOutlineView = pNavigatorOutlineView;
		window.navigationFixesProperties.activeFindNavigator = (IDEFindNavigator*)pCurrentNavigator;
		window.navigationFixesProperties.activeIssueNavigator = nil;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = pDVTExplorerOutlineView;
	}
	else if ([pCurrentNavigator isKindOfClass:NSClassFromString(@"IDENoticeNavigator")])
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = pFindNavigatorOutlineView;
		window.navigationFixesProperties.activeNavigatorOutlineView = pNavigatorOutlineView;
		window.navigationFixesProperties.activeIssueNavigator = (IDENavigator*)pCurrentNavigator;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = pDVTExplorerOutlineView;
		window.navigationFixesProperties.activeFindNavigator = nil;
	}
	else if ([pCurrentNavigator isKindOfClass:NSClassFromString(@"IDEWorkspaceNavigator")])
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = pFindNavigatorOutlineView;
		window.navigationFixesProperties.activeNavigatorOutlineView = pNavigatorOutlineView;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = pDVTExplorerOutlineView;
		window.navigationFixesProperties.activeIssueNavigator = nil;
		window.navigationFixesProperties.activeFindNavigator = nil;
	}
	else
	{
		window.navigationFixesProperties.activeFindNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeNavigatorOutlineView = nil;
		window.navigationFixesProperties.activeIssueNavigator = nil;
		window.navigationFixesProperties.activeFindNavigator = nil;
		window.navigationFixesProperties.activeDVTExplorerOutlineView = nil;
	}
}

static void updateLastValidEditorTab(NSWindow* _pWindow)
{
	if (![_pWindow isKindOfClass:NSClassFromString(@"IDEWorkspaceWindow")])
		return;

	NSWindowTabGroup *pTabGroup = [_pWindow tabGroup];
	if (!pTabGroup)
		return;

	IDEWorkspaceWindow *pSelectedWindow = [(IDEWorkspaceWindow *)_pWindow currentlySelectedTabbedWindow];
	if (!pSelectedWindow)
		return;

	if (getSourceCodeEditorView(pSelectedWindow))
		pTabGroup.lastValidEditorWindow = pSelectedWindow;
}

typedef void (^FCompletionHandler)(void);

// + (void)openLocation:(id)arg1 inWorkspaceTabController:(id)arg2 targetOriginatingEditor:(BOOL)arg3 completionHandler:(CDUnknownBlockType)arg4;
/*static void openLocation(IDEOpenQuicklyResultOpener *self_, SEL _cmd, id _pLocation, IDEWorkspaceTabController *_pTabController, BOOL _bTargetOriginatingEditor, FCompletionHandler _CompletionHandler)
{
	return ((void (*)(id, SEL, id, id, BOOL, FCompletionHandler))original_openLocation)
		(
			self_
			, _cmd
			, _pLocation
			, _pTabController
			, _bTargetOriginatingEditor
			, ^
			{
				_CompletionHandler();
				[[NSApplication sharedApplication] sendAction: @selector(revealInProjectNavigator:) to: nil from: nil];
				setEditorFocus(_pTabController._kvoWindow);
			}
		)
	;
}*/

static void pushSelectionToChooserViews(IDENavigatorArea *self_, SEL _cmd)
{
	NSWindowTabGroup *pTabGroup = ((NSWindow *)self_._kvoWindow).tabGroup;

	if (pTabGroup.preferredNextLocation != EPreferredNextLocation_Console)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Undefined;
		//NSLog(@"EPreferredNextLocation_Undefined -- pushSelectionToChooserViews");
	}

	NSWindow *window = self_._kvoWindow;
	updateLastValidEditorTab(window);

	potentialView(window);

	return ((void (*)(id, SEL))original_pushSelectionToChooserViews)(self_, _cmd);
}

static BOOL didSelectTabViewItem( NSView *self_, SEL _cmd, NSTabView *_pTabView, NSTabViewItem *_pItem)
{
	NSWindowTabGroup *pTabGroup = self_.window.tabGroup;

	if (pTabGroup.preferredNextLocation != EPreferredNextLocation_Console)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Undefined;
		//NSLog(@"EPreferredNextLocation_Undefined -- didSelectTabViewItem");
	}

	NSWindow *window = [_pTabView window];
	updateLastValidEditorTab(window);

	potentialView(window);

	return ((BOOL (*)(id, SEL, id, id))original_didSelectTabViewItem)(self_, _cmd, _pTabView, _pItem);
}

static NSView* getSourceCodeEditorView(NSWindow *_pWindow)
{
	if (_pWindow == nil)
		_pWindow = [NSApp keyWindow];
	//XcodePluginDumpClass(NSClassFromString(@"IDESourceEditor.IDESourceEditorView"));
	//XcodePluginTraceViewHierarchy([_pWindow contentView], 0);
	return findSubViewWithClassName([_pWindow contentView], "IDESourceEditor.SourceCodeEditorContainerView_ControlledBy_IDESourceEditor.SourceCodeEditor", -1);
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

static BOOL becomeFirstResponder_Console(IDEConsoleTextView* self_, SEL _cmd)
{
	NSWindowTabGroup *pTabGroup = self_.window.tabGroup;

	potentialView(self_.window);
	pTabGroup.preferredNextLocation = EPreferredNextLocation_Console;
	//NSLog(@"EPreferredNextLocation_Console -- becomeFirstResponder_Console");
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_Console)(self_, _cmd);
}

static BOOL becomeFirstResponder_Search(NSView *self_, SEL _cmd)
{
	NSWindowTabGroup *pTabGroup = self_.window.tabGroup;

	potentialView(self_.window);
	pTabGroup.preferredNextLocation = EPreferredNextLocation_Search;
	//NSLog(@"EPreferredNextLocation_Search -- becomeFirstResponder_Search");
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_Search)(self_, _cmd);
}


static BOOL becomeFirstResponder_DVTOutlineView(DVTOutlineView* self_, SEL _cmd)
{
	NSWindow *window = self_.window;
	NSWindowTabGroup *pTabGroup = window.tabGroup;

	potentialView(window);

	if (window.navigationFixesProperties.activeFindNavigator)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Search;
		//NSLog(@"EPreferredNextLocation_Search -- becomeFirstResponder_DVTOutlineView");
	}
	else if (window.navigationFixesProperties.activeIssueNavigator)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Issue;
		//NSLog(@"EPreferredNextLocation_Issue -- becomeFirstResponder_DVTOutlineView");
	}
	else if (window.navigationFixesProperties.activeDVTExplorerOutlineView)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Workspace;
		//NSLog(@"EPreferredNextLocation_Workspace -- becomeFirstResponder_DVTOutlineView");
	}
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_DVTOutlineView)(self_, _cmd);
}


static BOOL becomeFirstResponder_NavigatorOutlineView(IDENavigatorOutlineView* self_, SEL _cmd)
{
	NSWindow *window = self_.window;
	NSWindowTabGroup *pTabGroup = window.tabGroup;

	potentialView(window);

	if (window.navigationFixesProperties.activeFindNavigator)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Search;
		//NSLog(@"EPreferredNextLocation_Search -- becomeFirstResponder_NavigatorOutlineView");
	}
	else if (window.navigationFixesProperties.activeIssueNavigator)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Issue;
		//NSLog(@"EPreferredNextLocation_Issue -- becomeFirstResponder_NavigatorOutlineView");
	}
	else if (window.navigationFixesProperties.activeDVTExplorerOutlineView)
	{
		pTabGroup.preferredNextLocation = EPreferredNextLocation_Workspace;
		//NSLog(@"EPreferredNextLocation_Workspace -- becomeFirstResponder_NavigatorOutlineView");
	}
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_NavigatorOutlineView)(self_, _cmd);
}

static BOOL becomeFirstResponder_DVTFindPatternFieldEditor(DVTFindPatternFieldEditor* self_, SEL _cmd)
{
	NSWindow *window = self_.window;
	window.navigationFixesProperties.respondingPatternFieldEditor = self_;
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_DVTFindPatternFieldEditor)(self_, _cmd);
}

static BOOL becomeFirstResponder_SourceEditor_SourceEditorView(DVTFindPatternFieldEditor* self_, SEL _cmd)
{
	NSWindow *window = self_.window;
	updateLastValidEditorTab(window);
	potentialView(window);
	return ((BOOL (*)(id, SEL))original_becomeFirstResponder_SourceEditor_SourceEditorView)(self_, _cmd);
}

static BOOL resignFirstResponder_DVTFindPatternFieldEditor(DVTFindPatternFieldEditor* self_, SEL _cmd)
{
	NSWindow *window = self_.window;
	if (window.navigationFixesProperties.respondingPatternFieldEditor == self_)
		window.navigationFixesProperties.respondingPatternFieldEditor = nil;
	return ((BOOL (*)(id, SEL))original_resignFirstResponder_DVTFindPatternFieldEditor)(self_, _cmd);
}

static SourceEditor_SourceEditorTextFindPanel* getFindBar(DVTFindPatternFieldEditor* self_)
{
	NSView* pParentView = findParentViewWithClassName(self_, "DVTFindPatternFieldEditor", false);
	if (pParentView)
	{
		SourceEditor_SourceEditorTextFindPanel* pViewController = (SourceEditor_SourceEditorTextFindPanel*)[pParentView firstAvailableResponderOfClass:NSClassFromString(@"SourceEditor.SourceEditorTextFindPanel")];
		if (pViewController)
			return pViewController;
	}

	return nil;
}

static IDEFindNavigatorQueryParametersController *getBatchFindStrategiesController(DVTFindPatternFieldEditor* self_)
{
	NSView* pParentView = findParentViewWithClassName(self_, "IDEFindNavigatorLayoutView_ControlledBy_IDEFindNavigator", false);
	if (pParentView)
	{
		IDEFindNavigator* pViewController = (IDEFindNavigator*)[pParentView firstAvailableResponderOfClass:NSClassFromString(@"IDEFindNavigator")];
		if (pViewController)
			return pViewController.queryParametersController;
	}

	return nil;
}

static IDEFindNavigator* getBatchFindNavigator(DVTFindPatternFieldEditor* self_)
{
	NSView* pParentView = findParentViewWithClassName(self_, "IDEFindNavigatorLayoutView_ControlledBy_IDEFindNavigator", false);
	if (pParentView)
	{
		IDEFindNavigator* pViewController = (IDEFindNavigator*)[pParentView firstAvailableResponderOfClass:NSClassFromString(@"IDEFindNavigator")];
		if (pViewController)
			return pViewController;
	}

	return nil;
}

