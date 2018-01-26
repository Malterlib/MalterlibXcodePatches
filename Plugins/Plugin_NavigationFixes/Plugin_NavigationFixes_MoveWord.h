// - (void) moveWordForward:(id) arg1;
__attribute((noinline)) static void SourceEditor_SourceEditorView_moveWordForward(id self_, SEL _cmd, id arg1)
{
	//XcodePluginDumpClass([self_ class]);
	//((void (*)(id, SEL, id))original_SourceEditor_SourceEditorView_moveWordForward)(self_, _cmd, arg1);
	[XcodePluginNavigationFixes_MoveWord moveWordForward: self_ arg1: arg1];
}
__attribute((noinline)) static void SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(id self_, SEL _cmd, id arg1)
{
	[XcodePluginNavigationFixes_MoveWord moveWordForwardAndModifySelection: self_ arg1: arg1 arg2: _cmd];
}

__attribute((noinline)) void Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(id self_, id arg1, SEL _cmd)
{
	((void (*)(id, SEL, id))original_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection)(self_, _cmd, arg1);
}

// - (void) moveWordForward:(id) arg1;
__attribute((noinline)) static void SourceEditor_SourceEditorView_moveWordBackward(id self_, SEL _cmd, id arg1)
{
	[XcodePluginNavigationFixes_MoveWord moveWordBackward: self_ arg1: arg1];
}

__attribute((noinline)) static void SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection(id self_, SEL _cmd, id arg1)
{
	[XcodePluginNavigationFixes_MoveWord moveWordBackwardAndModifySelection: self_ arg1: arg1 arg2: _cmd];
}

__attribute((noinline)) void Call_SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection(id self_, id arg1, SEL _cmd)
{
	((void (*)(id, SEL, id))original_SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection)(self_, _cmd, arg1);
}

__attribute((noinline)) static void SourceEditor_SourceEditorView_deleteWordForward(id self_, SEL _cmd, id arg1)
{
	[XcodePluginNavigationFixes_MoveWord deleteWordForward: self_ arg1: arg1];
}

__attribute((noinline)) static void SourceEditor_SourceEditorView_deleteWordBackward(id self_, SEL _cmd, id arg1)
{
	[XcodePluginNavigationFixes_MoveWord deleteWordBackward: self_ arg1: arg1];
}
