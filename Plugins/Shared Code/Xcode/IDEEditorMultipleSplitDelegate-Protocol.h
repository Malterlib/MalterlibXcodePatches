//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class IDEEditorArea, IDEEditorMultipleSplit, IDEViewController;
@protocol IDEEditorMultipleSplitItem;

@protocol IDEEditorMultipleSplitDelegate <NSObject>
- (IDEEditorArea *)editorArea;
- (void)didResizeEditorMultipleSplit:(IDEEditorMultipleSplit *)arg1;
- (void)editorMultipleSplit:(IDEEditorMultipleSplit *)arg1 didRemoveSplitItem:(IDEViewController<IDEEditorMultipleSplitItem> *)arg2 fromIndex:(unsigned long long)arg3;
- (void)editorMultipleSplit:(IDEEditorMultipleSplit *)arg1 willRemoveSplitItem:(IDEViewController<IDEEditorMultipleSplitItem> *)arg2 fromIndex:(unsigned long long)arg3;
- (void)editorMultipleSplit:(IDEEditorMultipleSplit *)arg1 didCreateSplitItem:(IDEViewController<IDEEditorMultipleSplitItem> *)arg2;
@end
