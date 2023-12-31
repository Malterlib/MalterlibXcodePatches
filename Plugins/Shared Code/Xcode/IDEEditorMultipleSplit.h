//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEditorMultipleSplit_h
#define IDEEditorMultipleSplit_h
#import <Foundation/Foundation.h>

#include "IDEViewController.h"
#include "DVTReplacementViewDelegate-Protocol.h"
#include "IDEEditorArea.h"
#include "IDEEditorMultipleSplit.h"

@protocol IDEEditorMultipleSplitDelegate, IDEEditorMultipleSplitItem, IDEEditorMutableMultipleSplitItem;
@class NSArray, NSMutableArray, NSString, IDEEditorArea;

@interface IDEEditorMultipleSplit : IDEViewController<NSSplitViewDelegate, DVTReplacementViewDelegate, IDEEditorMutableMultipleSplitItem, IDEEditorMultipleSplitItem> {
  /* instance variables */
  id _viewFrameDidChangeNotificationObserver;
}

@property (readonly) NSMutableArray *mutableEditorSplitItems;
@property (retain) NSObject<IDEEditorMultipleSplitDelegate> *delegate;
@property (nonatomic) unsigned long long primaryLayout;
@property (readonly, nonatomic) unsigned long long secondaryLayout;
@property (readonly, nonatomic) BOOL canAddOppositePrimaryLayout;
@property (readonly) NSArray *editorSplitItems;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (retain) IDEEditorMultipleSplit *parentEditorMultipleSplit;
@property (retain) IDEEditorArea *editorArea;
@property (readonly) NSArray *editorAreaSplits;
@property (readonly) struct CGSize minimumContentViewFrameSize;
@property (nonatomic) double safeAreaTopInset;
@property (nonatomic) double safeAreaBottomInset;

/* class methods */
+ (void)initialize;
+ (id)_copyIndexPath:(id)path startingPostion:(long long)postion;
+ (id)_editorAreaSplitStates:(id)states setEditorMode:(long long)mode indexPath:(id)path;
+ (BOOL)anyEditorSplitItemStateHasStaticTabs:(id)tabs;
+ (id)convertEditorSplitItemStateDictionariesToOpenInPlace:(id)place;

/* instance methods */
- (id)_addOppositeLayoutEditorSplitInParentMultipleSplitWithClient:(unsigned long long)client;
- (id)_reparentEditorAreaSplitAtIndex:(unsigned long long)index client:(unsigned long long)client;
- (id)_reparentOnlyChildOfEditorMultipleSplit:(id)split client:(unsigned long long)client;
- (id)_addOppositeLayoutEditorSplitAtIndexInNewChildMultipleSplit:(unsigned long long)split client:(unsigned long long)client;
- (id)splitEditorAreaSplitAtIndex:(unsigned long long)index layout:(unsigned long long)layout client:(unsigned long long)client;
- (BOOL)canCreateAdditionalEditorAreaSplitsAtIndex:(unsigned long long)index layout:(unsigned long long)layout;
- (id)splitEditorAreaSplit:(id)split layout:(unsigned long long)layout client:(unsigned long long)client;
- (BOOL)canCloseEditorAreaSplits;
- (void)closeEditorSplitItem:(id)item;
- (void)closeAllEditorSplitItemsKeeping:(id)keeping;
- (BOOL)moveEditorAreaSplitForward:(id)forward;
- (BOOL)moveEditorAreaSplitBack:(id)back;
- (void)primitiveInvalidate;
- (id)initWithNibName:(id)name bundle:(id)bundle;
- (void)loadView;
- (id)_splitView;
- (BOOL)_editorsAreStackedVertically;
- (BOOL)canResetEditorSizes;
- (void)resetEditorSizes;
- (void)_setupInitialSplit;
- (BOOL)addEditorSplitItemAtIndex:(unsigned long long)index layout:(unsigned long long)layout actuallySplit:(BOOL)split completionBlock:(id /* block */)block;
- (id)addEditorAreaSplitAfterEditorAreaSplit:(id)split copyContent:(BOOL)content layout:(unsigned long long)layout client:(unsigned long long)client;
- (void)didInheritNewSafeAreaInsetsFromParent;
- (id)safeAreaAwareChildren;
- (BOOL)shouldSafeAreaAwareChildInheritTopInset:(id)inset;
- (BOOL)shouldSafeAreaAwareChildInheritBottomInset:(id)inset;
- (void)invalidateSafeAreaForChildren;
- (void)viewWillLayout;
- (void)restoreWithStateDictionaries:(id)dictionaries client:(unsigned long long)client restoreEditorSplitBlock:(id /* block */)block;
- (void)_restoreEditorMultipleSplitAtIndexPath:(id)path stateDictionaries:(id)dictionaries client:(unsigned long long)client restoreEditorSplitBlock:(id /* block */)block;
- (id)editorSplitItemStateDictionaries;
- (BOOL)_removeEditorSplitItemAtIndex:(unsigned long long)index;
- (struct CGSize)minimumSizeForView:(id)view;
- (void)_splitView:(id)view resizeHorizontalSubviewsWithOldSize:(struct CGSize)size;
- (id)_splitViewResizingLogAspect;
- (void)_splitView:(id)view resizeVerticalSubviewsWithOldSize:(struct CGSize)size;
- (void)splitView:(id)view resizeSubviewsWithOldSize:(struct CGSize)size;
- (double)splitView:(id)view constrainMinCoordinate:(double)coordinate ofSubviewAt:(long long)at;
- (double)splitView:(id)view constrainMaxCoordinate:(double)coordinate ofSubviewAt:(long long)at;
- (void)replacementView:(id)view willInstallViewController:(id)controller;
- (void)observeValueForKeyPath:(id)path ofObject:(id)object change:(id)change context:(void *)context;
@end

#endif /* IDEEditorMultipleSplit_h */
