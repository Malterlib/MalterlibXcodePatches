
#define DXcodePlugin_ImplementSwiftCallGlue(_Name) \
	__attribute((swiftcall)) void (*g_f##_Name)(id __attribute__((swift_context)) _pContext); \
	__attribute((swiftcall)) __attribute((noinline)) __attribute((naked)) void Call_##_Name(id self_) \
	{\
		asm	{ jmp g_f##_Name};\
	}

#define DXcodePlugin_InitSwiftCallGlue(_Name, _Module, _MangledName) \
	g_f##_Name = fg_GetLocalSymbol(_Module, _MangledName);

DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_recentsMenuItems);

void Call_InitFunctiontPointers()
{
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded, "SourceEditor.framework/Versions/A/SourceEditor", "__T012SourceEditor0aB13LayoutManagerC19expandRangeIfNeededAA0abF0VAFF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange, "SourceEditor.framework/Versions/A/SourceEditor", "__T012SourceEditor0aB4ViewC06deleteA5RangeyAA0abE0V5range_Sb7forwardSb11useKillRingtF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange, "SourceEditor.framework/Versions/A/SourceEditor", "__T012SourceEditor0aB4ViewC15selectTextRangeyAA0abF0VSg_AA15ScrollPlacementOSg06scrollH0Sb06alwaysG0tF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors, "SourceEditor.framework/Versions/A/SourceEditor", "__T012SourceEditor0aB4ViewC21clearSelectionAnchorsyyF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_recentsMenuItems, "SourceEditor.framework/Versions/A/SourceEditor", "__T012SourceEditor0aB13TextFindPanelC16recentsMenuItemsSaySo10NSMenuItemCGyF");
}
