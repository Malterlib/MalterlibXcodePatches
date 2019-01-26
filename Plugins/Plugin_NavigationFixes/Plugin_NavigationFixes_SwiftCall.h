
#define DXcodePlugin_ImplementSwiftCallGlue(_Name) \
	__attribute((swiftcall)) void (*g_f##_Name)(id __attribute__((swift_context)) _pContext); \
	__attribute((swiftcall)) __attribute((noinline)) __attribute((naked)) void Call_##_Name() \
	{\
		asm	{ jmp g_f##_Name};\
	}

#define DXcodePlugin_ImplementSwiftFieldOffsetGlue(_Name) \
	size_t g_##_Name;

#define DXcodePlugin_InitSwiftCallGlue(_Name, _Module, _MangledName) \
	g_f##_Name = fg_GetLocalSymbol(_Module, _MangledName);

#define DXcodePlugin_InitSwiftFieldOffsetGlue(_Name, _Module, _MangledName) \
	g_##_Name = *((size_t *)fg_GetLocalSymbol(_Module, _MangledName));

DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_setSelection);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors);
DXcodePlugin_ImplementSwiftFieldOffsetGlue(SourceEditor_SourceEditorTextFindPanel_panelModePopUp);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_updatePanelModePopup);

void Call_InitFunctiontPointers()
{
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB13LayoutManagerC19expandRangeIfNeededyAA0abF0VAFF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC06deleteA5Range5range7forward11useKillRingyAA0abE0V_S2btF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC15selectTextRange_15scrollPlacement12alwaysScrollyAA0abF0VSg_AA0jH0OSgSbtF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_setSelection, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC12setSelection_15scrollPlacement12alwaysScrollyAA0abE0VSg_AA0iG0OSgSbtF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC21clearSelectionAnchorsyyF");
	DXcodePlugin_InitSwiftFieldOffsetGlue(SourceEditor_SourceEditorTextFindPanel_panelModePopUp, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB13TextFindPanelC14panelModePopUpAA0cdhI6ButtonCSgvpWvd");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_updatePanelModePopup, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB13TextFindPanelC06updateE9ModePopUpyyF");
}
