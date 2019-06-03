//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class IDEPathCell, IDEPathComponentCell, NSArray, NSMenu, NSMenuItem, NSString;
@protocol NSObject, IDEPathCellItem;

@protocol IDEPathCellDelegate <NSPathCellDelegate>

@optional
- (void)pathCell:(IDEPathCell *)arg1 didEndDragForComponentCell:(IDEPathComponentCell *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 beginDragForComponentCell:(IDEPathComponentCell *)arg2;
- (NSString *)pathCell:(IDEPathCell *)arg1 toolTipForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCell:(IDEPathCell *)arg1 accessibilityDescriptionForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (long long)pathCell:(IDEPathCell *)arg1 textAlignmentOfTitleForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCell:(IDEPathCell *)arg1 titleForPathComponentCell:(IDEPathComponentCell *)arg2 atIndex:(unsigned long long)arg3;
- (NSString *)pathCellNoSelectionTitle;
- (struct CGPoint)pathCell:(IDEPathCell *)arg1 adjustPopupMenuLocation:(struct CGPoint)arg2;
- (NSMenuItem *)pathCell:(IDEPathCell *)arg1 menuItemForItem:(id <NSObject, IDEPathCellItem>)arg2 defaultMenuItem:(NSMenuItem *)arg3;
- (void)pathCell:(IDEPathCell *)arg1 didUpdateMenu:(NSMenu *)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 performAlternateReveal:(id <NSObject, IDEPathCellItem>)arg2 fromFrame:(struct CGRect)arg3;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldEnableSelection:(id <NSObject, IDEPathCellItem>)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldInitiallyShowMenuSearch:(id <NSObject, IDEPathCellItem>)arg2;
- (NSArray *)pathCell:(IDEPathCell *)arg1 childItemsForItem:(id <NSObject, IDEPathCellItem>)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldPopUpMenuForPathComponentCell:(IDEPathComponentCell *)arg2 item:(id <NSObject, IDEPathCellItem>)arg3;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldSeparateDisplayOfChildItemsForItem:(id <NSObject, IDEPathCellItem>)arg2;
- (BOOL)pathCell:(IDEPathCell *)arg1 shouldDisplayChildrenForItem:(id <NSObject, IDEPathCellItem>)arg2;
- (void)pathCell:(IDEPathCell *)arg1 willDismissMenuDisplayingItems:(NSArray *)arg2;
- (void)pathCell:(IDEPathCell *)arg1 willDisplayChildren:(NSArray *)arg2 mostProximateChildItem:(id <NSObject, IDEPathCellItem>)arg3;
@end

