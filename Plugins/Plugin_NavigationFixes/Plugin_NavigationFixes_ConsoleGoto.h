

NSRegularExpression *g_pSourceLocationColumnRegex;

static void mouseDownInConsole(IDEConsoleTextView* self_, SEL _cmd, NSEvent* _pEvent)
{
	if ([_pEvent clickCount] >= 2)
	{
		if (navigateToLineInConsoleTextView(self_))
			return;
	}
	return ((void (*)(id, SEL, id))original_mouseDownInConsole)(self_, _cmd, _pEvent);
}

static bool navigateToNextInLastConsoleText(NSWindow *_pWindow, bool _bBackwards)
{
	NSRange selectedRange = _pWindow.navigationFixesProperties.consoleLastSelectedRange;
	NSString *text = _pWindow.navigationFixesProperties.consoleLastText;

	NSRange lineRange = [text lineRangeForRange:selectedRange];

	bool bWrapped = false;
	while (true)
	{
		if (lineRange.location == 0xffffffffffffffffLL)
			return false;
		NSRange StartRange = lineRange;
		if (_bBackwards)
		{
			if (lineRange.location > 0)
				lineRange.location = lineRange.location - 1;
		}
		else
			lineRange.location = lineRange.location + lineRange.length;
		lineRange.length = 0;

		lineRange = [text lineRangeForRange:lineRange];
		if (NSEqualRanges(lineRange, StartRange))
		{
			if (bWrapped)
				return false;
			bWrapped = true;
			if (_bBackwards)
			{
				lineRange.location = [text length] - 1;
				lineRange.length = 0;
			}
			else
			{
				lineRange.location = 0;
				lineRange.length = 0;
			}
			continue;
		}
		NSString *line = [text substringWithRange:lineRange];

		NSArray *matches = [g_pSourceLocationColumnRegex matchesInString:line
														   options:0
															 range:NSMakeRange(0, [line length])];
		if (matches.count > 0)
		{
			NSTextCheckingResult* pMatch = matches[0];
			NSUInteger nRanges = [pMatch numberOfRanges];
			if (nRanges == 4)
			{
				lineRange.length = 0;
				_pWindow.navigationFixesProperties.consoleLastSelectedRange = lineRange;
				break;
			}
		}
	}

	return navigateToLineInConsoleText(_pWindow);
}

static bool navigateToLineInConsoleText(NSWindow *_pWindow)
{
	NSRange selectedRange = _pWindow.navigationFixesProperties.consoleLastSelectedRange;
	NSString *text = _pWindow.navigationFixesProperties.consoleLastText;

	NSRange lineRange = [text lineRangeForRange:selectedRange];
	NSString *line = [text substringWithRange:lineRange];

	NSArray *matches = [g_pSourceLocationColumnRegex matchesInString:line
													   options:0
														 range:NSMakeRange(0, [line length])];

	NSWindow *pLastSelectedTabitem = NULL;
	if (matches.count > 0)
	{
		NSUInteger nRanges = 0;
		NSTextCheckingResult* pMatch = matches[0];

		nRanges = [pMatch numberOfRanges];
		if (nRanges == 4)
		{
			NSRange SourceRange = [pMatch rangeAtIndex:1];
			NSRange LineRange = [pMatch rangeAtIndex:2];
			NSRange ColumnRange = [pMatch rangeAtIndex:3];
			NSString* pSource = [line substringWithRange:SourceRange];
			NSString* pLine = [line substringWithRange:LineRange];

			NSString* pColumn = nil;

			if (LineRange.length == 0)
				goto End;

			if (ColumnRange.length != 0)
				pColumn = [line substringWithRange:ColumnRange];

			pSource = [pSource stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceCharacterSet]];
//				NSString* pInfo = [line substringWithRange:[pMatch rangeAtIndex:3]];

//				XcodePluginLog(@"Source: %@\n", pSource);
//				XcodePluginLog(@"Line: %@\n", pLine);

			NSWindow *pWindow = _pWindow;
			NSView *pView = getSourceCodeEditorView(pWindow);
			if (!pView)
			{
				NSWindowTabGroup *pTabGroup = [pWindow tabGroup];
				if (pTabGroup.lastValidEditorWindow)
				{
					pWindow = pTabGroup.lastValidEditorWindow;
					pLastSelectedTabitem = pWindow;
				}
			}

			IDEWorkspaceTabController *pTabController = getWorkspaceTabController(pWindow);

			if (pTabController)
			{
				NSFileManager *fileManager = [NSFileManager defaultManager];
				if ([pSource length] > 0 && [fileManager fileExistsAtPath:pSource])
				{
					//+[IDEEditorCoordinator _doOpenEditorOpenSpecifier:forWorkspaceTabController:editorContext:target:takeFocus:] ()

					NSNumber* pTimeStamp = [NSNumber numberWithDouble:[[NSDate date] timeIntervalSince1970]];

					NSURL* pURL = [NSURL fileURLWithPath:pSource isDirectory: false];
					long long LineNumber = [pLine integerValue] - 1;

					DVTTextDocumentLocation *documentLocation;
					if (pColumn)
					{
						long long ColumnNumber = [pColumn integerValue] - 1;
						documentLocation =
							[
								[DVTTextDocumentLocation alloc]
								initWithDocumentURL:pURL
								timestamp:pTimeStamp
								startingColumnNumber:ColumnNumber
								endingColumnNumber:ColumnNumber
								startingLineNumber:LineNumber
								endingLineNumber:LineNumber
								characterRange:NSMakeRange(0x7fffffffffffffffLL, 0)
							]
						;
					}
					else
					{
						documentLocation =
							[
								[DVTTextDocumentLocation alloc]
								initWithDocumentURL:pURL
								timestamp:pTimeStamp
								lineRange:NSMakeRange(LineNumber, 1)
							]
						;
					}

					IDEWorkspaceDocument *pDocument = [pTabController workspaceDocument];

					if (pDocument)
					{
						NSRange NewRange;
						NewRange.location = lineRange.location + SourceRange.location;
						if (pColumn)
							NewRange.length = (ColumnRange.location + ColumnRange.length) - SourceRange.location;
						else
							NewRange.length = (LineRange.location + LineRange.length) - SourceRange.location;

						IDEEditorOpenSpecifier *pSpecifier = [IDEEditorOpenSpecifier structureEditorOpenSpecifierForDocumentLocation:documentLocation
																															inWorkspace:[pDocument workspace]
																																  error:nil];
						pWindow.navigationFixesProperties.consoleLastSelectedRange = NewRange;

						pLastSelectedTabitem = NULL;
						[IDEEditorCoordinator _openEditorOpenSpecifier:pSpecifier forWorkspaceTabController:pTabController target:0 takeFocus:1];
						setEditorFocus(pWindow);
						return true;
					}
				}
				else
					pLastSelectedTabitem = NULL;
			}
		}
	}
End:

	return false;
}

static bool navigateToLineInConsoleTextView(IDEConsoleTextView* _pTextView)
{
	NSWindow *pWindow = [_pTextView window];
	NSRange selectedRange = _pTextView.selectedRange;
	NSString *text = _pTextView.string;

	pWindow.navigationFixesProperties.consoleLastText = text;
	pWindow.navigationFixesProperties.consoleLastSelectedRange = selectedRange;

	if (navigateToLineInConsoleText(pWindow))
	{
		[_pTextView setSelectedRange: pWindow.navigationFixesProperties.consoleLastSelectedRange];
		[_pTextView scrollRangeToVisible: pWindow.navigationFixesProperties.consoleLastSelectedRange];
	}

	return false;
}
