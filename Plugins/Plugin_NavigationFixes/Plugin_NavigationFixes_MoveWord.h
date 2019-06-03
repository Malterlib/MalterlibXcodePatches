
__attribute((noinline)) void Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(id self_)
{
	return ((void (*)(id, SEL, SEL))original_SourceEditor_SourceEditorView_doCommandBySelector)(self_, @selector(doCommandBySelector:), @selector(moveWordRightAndModifySelection:));
//	((void (*)(id, SEL, id))original_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection)(self_, _cmd, arg1);
}

__attribute((noinline)) void Call_SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection(id self_)
{
	return ((void (*)(id, SEL, SEL))original_SourceEditor_SourceEditorView_doCommandBySelector)(self_, @selector(doCommandBySelector:), @selector(moveWordLeftAndModifySelection:));
//	((void (*)(id, SEL, id))original_SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection)(self_, _cmd, arg1);
}

__attribute((noinline)) static void SourceEditor_SourceEditorView_doCommandBySelector(id _pSourceEditorView, SEL _cmd, SEL _Selector)
{
	//NSLog(@"%@", NSStringFromSelector(arg1));
	if (_Selector == @selector(moveWordRight:))
	{
		if ([XcodePluginNavigationFixes_MoveWord moveWordForward: _pSourceEditorView])
			return;
	}
	else if (_Selector == @selector(moveWordLeft:))
	{
		if ([XcodePluginNavigationFixes_MoveWord moveWordBackward: _pSourceEditorView])
			return;
	}
	else if (_Selector == @selector(moveWordRightAndModifySelection:))
	{
		if ([XcodePluginNavigationFixes_MoveWord moveWordForwardAndModifySelection: _pSourceEditorView])
			return;
	}
	else if (_Selector == @selector(moveWordLeftAndModifySelection:))
	{
		if ([XcodePluginNavigationFixes_MoveWord moveWordBackwardAndModifySelection: _pSourceEditorView])
			return;
	}
	else if (_Selector == @selector(deleteWordForward:))
	{
		if ([XcodePluginNavigationFixes_MoveWord deleteWordForward: _pSourceEditorView])
			return;
	}
	else if (_Selector == @selector(deleteWordBackward:))
	{
		if ([XcodePluginNavigationFixes_MoveWord deleteWordBackward: _pSourceEditorView])
			return;
	}

	return ((void (*)(id, SEL, SEL))original_SourceEditor_SourceEditorView_doCommandBySelector)(_pSourceEditorView, _cmd, _Selector);
}

__attribute((swiftcall)) __attribute((noinline)) id SourceEditor_SourceEditorView_getDataSource(id __attribute__((swift_context)) _pSourceEditorView)
{
	static Ivar s_Ivar = nil;
	if (!s_Ivar)
		s_Ivar = class_getInstanceVariable([_pSourceEditorView class], "dataSource");
	return object_getIvar(_pSourceEditorView, s_Ivar);
}

__attribute((swiftcall)) __attribute((noinline)) id SourceEditor_SourceEditorView_getLayoutManager(id __attribute__((swift_context)) _pSourceEditorView)
{
	static Ivar s_Ivar = nil;
	if (!s_Ivar)
		s_Ivar = class_getInstanceVariable([_pSourceEditorView class], "layoutManager");
	return object_getIvar(_pSourceEditorView, s_Ivar);
}

__attribute((swiftcall)) __attribute((noinline)) void *SourceEditor_SourceEditorView_getSelectionPointer(id __attribute__((swift_context)) _pSourceEditorView)
{
	static Ivar s_Ivar = nil;
	if (!s_Ivar)
		s_Ivar = class_getInstanceVariable([_pSourceEditorView class], "selection");

	ptrdiff_t offset = ivar_getOffset(s_Ivar);
	unsigned char* bytes = (unsigned char *)(__bridge void*)_pSourceEditorView;
	return bytes+offset;
}

