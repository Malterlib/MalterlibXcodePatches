
#ifdef __aarch64__

	#define DXcodePlugin_ImplementSwiftCallGlue(_Name) \
		__attribute((swiftcall)) void (*g_f##_Name)(id __attribute__((swift_context)) _pContext); \
		__attribute((swiftcall)) __attribute((noinline)) __attribute((naked)) void Call_##_Name(void) \
		{\
			asm("ldr  x9, %0" :: "m"(g_f##_Name));\
			asm("br   x9");\
		}

#else

	#define DXcodePlugin_ImplementSwiftCallGlue(_Name) \
		__attribute((swiftcall)) void (*g_f##_Name)(id __attribute__((swift_context)) _pContext); \
		__attribute((swiftcall)) __attribute((noinline)) __attribute((naked)) void Call_##_Name(void) \
		{\
			asm	{ jmp g_f##_Name};\
		}

#endif

#define DXcodePlugin_ImplementSwiftFieldOffsetGlue(_Name) \
	size_t g_##_Name;

#define DXcodePlugin_InitSwiftCallGlue(_Name, _Module, _MangledName) \
	g_f##_Name = fg_GetLocalSymbol(_Module, _MangledName);

#define DXcodePlugin_InitSwiftFieldOffsetGlue(_Name, _Module, _MangledName) \
	size_t *pTemp##_Name = (size_t *)fg_GetLocalSymbol(_Module, _MangledName);\
	g_##_Name = pTemp##_Name ? *(pTemp##_Name) : 0;

DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors);
DXcodePlugin_ImplementSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_updatePanelModePopup);

void Call_InitFunctiontPointers(void)
{
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB13LayoutManagerC19expandRangeIfNeededySnyAA0aB8PositionVGAGF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_deleteSourceRange, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC06deleteA5Range5range7forward11useKillRingySnyAA0aB8PositionVG_S2btF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_selectTextRange, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC15selectTextRange_15scrollPlacement12alwaysScrollySnyAA0aB8PositionVGSg_AA0jH0OSgSbtF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorView_clearSelectionAnchors, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB4ViewC21clearSelectionAnchorsyyF");
	DXcodePlugin_InitSwiftCallGlue(SourceEditor_SourceEditorTextFindPanel_updatePanelModePopup, "SourceEditor.framework/Versions/A/SourceEditor", "_$s12SourceEditor0aB13TextFindPanelC06updateE9ModePopUpyyF");
}
