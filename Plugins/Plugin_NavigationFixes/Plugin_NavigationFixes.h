
#ifndef Plugin_NavigationFixes_h
#define Plugin_NavigationFixes_h

#import "Xcode.h"
#import "../Shared Code/XcodePlugin.h"

void *fg_GetLocalSymbol(char const *_pImageName, char const *_pSymbolName);

void Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(id self_, id arg1, SEL _cmd);
void Call_SourceEditor_SourceEditorView_moveWordBackwardAndModifySelection(id self_, id arg1, SEL _cmd);

#endif /* Plugin_NavigationFixes_h */
