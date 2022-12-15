//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTOutlineView.h"

#import "DVTInvalidation-Protocol.h"

@class DVTDelayedInvocation, DVTNotificationToken, DVTStackBacktrace, DVTTimeSlicedMainThreadWorkQueue, IDENavigableItemFilter, NSArray, NSHashTable, NSMapTable, NSMutableArray, NSString, _IDENavigatorOutlineViewDataSource;
@protocol DVTInvalidation;

@interface IDENavigatorOutlineView : DVTOutlineView <DVTInvalidation>
{
    long long _batchRowUpdateCount;
    NSHashTable *_unfilteredRootItems;
    DVTDelayedInvocation *_delayedInvocation;
    SEL _keyAction;
    NSMapTable *_cachedRowItemsToHeights;
    _IDENavigatorOutlineViewDataSource *_interposedDelegate;
    _IDENavigatorOutlineViewDataSource *_interposedDataSource;
    BOOL _isLiveScrolling;
    BOOL _suspendPushingOutlineViewSelectionToBoundObjects;
    NSMutableArray *_entriesToRestoreToVisibleRect;
    id <DVTInvalidation> _rowSizeStyleChangedObserver;
    DVTNotificationToken *_variableRowHeightLiveScrollStartObserver;
    DVTNotificationToken *_variableRowHeightLiveScrollEndObserver;
    DVTDelayedInvocation *_variableRowHeightVisibleRowsHeightCalculatorInvocation;
    struct {
        unsigned int _needsToPushRowSelection:1;
        unsigned int _needsToRefreshBoundExpandedItems:1;
        unsigned int _suspendRowHeightInvalidation:1;
        unsigned int _doingBatchExpand:1;
        unsigned int _scrollSelectionToVisibleAfterRefreshingSelection:1;
        unsigned int _resettingRootItems:1;
        unsigned int _reloadingItems:1;
        unsigned int _didReceiveKeyDownEvent:1;
        unsigned int _didPublishSelectedObjects:1;
        unsigned int _supportsTrackingAreasForCells:1;
        unsigned int _inSameRunloopForTrackingSelectionVisibleRect:1;
        unsigned int _usesSystemGroupHeaderStyle:1;
        unsigned int _delegateRespondsToShouldInitiallyExpandItem:1;
        unsigned int _invalidating:1;
    } _idenovFlags;
    BOOL _filteringActive;
    BOOL _supportsVariableHeightCells;
    BOOL _tracksSelectionVisibleRect;
    BOOL _useFixedRowHeightWhileAnimatingWorkaround;
    IDENavigableItemFilter *_filter;
    DVTTimeSlicedMainThreadWorkQueue *_expandingItemsWorkQueue;
    long long _filterProgress;
}

+ (id)keyPathsForValuesAffectingFilteringActive;
+ (id)keyPathsForValuesAffectingEmptyContentString;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (void)initialize;
// - (void).cxx_destruct;
@property(readonly) long long filterProgress; // @synthesize filterProgress=_filterProgress;
@property BOOL useFixedRowHeightWhileAnimatingWorkaround; // @synthesize useFixedRowHeightWhileAnimatingWorkaround=_useFixedRowHeightWhileAnimatingWorkaround;
@property(retain) DVTTimeSlicedMainThreadWorkQueue *expandingItemsWorkQueue; // @synthesize expandingItemsWorkQueue=_expandingItemsWorkQueue;
@property BOOL tracksSelectionVisibleRect; // @synthesize tracksSelectionVisibleRect=_tracksSelectionVisibleRect;
@property(nonatomic) BOOL supportsVariableHeightCells; // @synthesize supportsVariableHeightCells=_supportsVariableHeightCells;
@property(nonatomic) SEL keyAction; // @synthesize keyAction=_keyAction;
@property(readonly, getter=isFilteringActive) BOOL filteringActive; // @synthesize filteringActive=_filteringActive;
@property(retain, nonatomic) IDENavigableItemFilter *filter; // @synthesize filter=_filter;
- (void)processPendingChanges;
- (void)scrollSelectionToVisible;
- (BOOL)scrollRectToVisible:(struct CGRect)arg1;
- (struct _NSRange)initialSelectionRangeForCell:(id)arg1 proposedRange:(struct _NSRange)arg2;
- (struct CGRect)frameOfCellAtColumn:(long long)arg1 row:(long long)arg2;
- (struct CGRect)frameOfOutlineCellAtRow:(long long)arg1;
- (double)_indentationForRow:(long long)arg1 withLevel:(long long)arg2 isSourceListGroupRow:(BOOL)arg3;
- (void)accessibilitySetSelectedRowsAttribute:(id)arg1;
- (void)keyUp:(id)arg1;
- (void)keyDown:(id)arg1;
- (void)mouseDown:(id)arg1;
- (void)quickLookWithEvent:(id)arg1;
- (void)setSortDescriptors:(id)arg1;
@property(copy) NSArray *rootItems;
- (void)_updateRootItems:(id)arg1 sortDescriptors:(id)arg2;
- (BOOL)isRootItem:(id)arg1;
- (id)realDelegate;
@property(readonly) id realDataSource;
- (void)setDelegate:(id)arg1;
- (void)setDataSource:(id)arg1;
- (id)_cachedHeightOfItemOrNil:(id)arg1;
- (double)_cachedOrEstimatedOrDefaultHeightOfItem:(id)arg1;
- (void)viewDidEndLiveResize;
- (BOOL)_isVariableRowHeightViewBasedOutlineView;
- (id)makeViewWithIdentifier:(id)arg1 owner:(id)arg2;
- (void)reloadData;
- (void)reloadItem:(id)arg1 reloadChildren:(BOOL)arg2;
- (void)_restoreEntriesToVisibleRect;
- (void)_rememberEntriesToRestoreToVisibleRect;
@property(readonly, getter=isReloadingItems) BOOL reloadingItems;
- (BOOL)sendAction:(SEL)arg1 to:(id)arg2;
- (void)_refreshDisplayForItem:(id)arg1;
- (void)updateBoundExpandedItems;
- (void)updateBoundSelectedObjects;
- (void)_pushOutlineViewSelectionToBoundObjects;
- (void)_updateBoundContentArrayOrSet;
- (void)updateBoundContentSet;
- (void)updateBoundContentArray;
- (void)_refreshBoundExpandedAndSelectedItems:(id)arg1;
- (void)refreshBoundSelectedObjects;
- (void)refreshBoundExpandedItems;
- (id)dvt_extraBindings;
- (void)primitiveInvalidate;
- (void)suspendEditingWhilePerformingBlock:(CDUnknownBlockType)arg1;
- (id)_suspendEditing:(long long *)arg1;
- (void)didRemoveRowView:(id)arg1 forRow:(long long)arg2;
- (void)didAddRowView:(id)arg1 forRow:(long long)arg2;
- (unsigned long long)_outlineTableColumnIndex;
- (void)_recalculateAndCacheHeightForRowView:(id)arg1 row:(long long)arg2;
- (void)noteAllRowHeightsMayHaveChangedAnimated:(BOOL)arg1;
- (void)noteHeightOfRowsWithIndexesChanged:(id)arg1;
- (void)_concludeBatchRowUpdates;
- (void)_beginBatchRowUpdates;
- (void)setShouldSuspendRowHeightInvalidation:(BOOL)arg1;
- (BOOL)shouldSuspendRowHeightInvalidation;
- (void)collapseItem:(id)arg1;
- (void)collapseItem:(id)arg1 collapseChildren:(BOOL)arg2;
- (void)expandItemIncludingAncestors:(id)arg1 expandChildren:(BOOL)arg2;
- (void)expandItem:(id)arg1;
- (void)expandItem:(id)arg1 expandChildren:(BOOL)arg2;
- (void)expandAncestorsForItem:(id)arg1;
- (void)_expandAncestorsForNavigableItem:(id)arg1;
- (BOOL)filteringActive;
- (id)emptyContentString;
- (void)_updateCachedRowHeightsForVisibleRows;
- (void)_updateRowSizeStyleAndHeight;
- (void)_rowSizeStyleChanged;
- (id)init;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)_ide_commonInit;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

