//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTExtension, IDEEditor, IDENavigableItemCoordinator;
@protocol IDEEditorHistoryControllerItem;

@protocol IDEEditorContextProtocol <NSObject>
@property(readonly, nonatomic) IDEEditor *editor;
@property(readonly) IDENavigableItemCoordinator *navigableItemCoordinator;
- (BOOL)_openEmptyEditor;
- (void)_giveEditorFocusIfNeeded;
- (BOOL)_openEditorHistoryItem:(id <IDEEditorHistoryControllerItem>)arg1 documentExtension:(DVTExtension *)arg2 options:(unsigned long long)arg3;
- (id <IDEEditorHistoryControllerItem>)currentHistoryItem;
@end

