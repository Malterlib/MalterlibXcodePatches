//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTEmptyContentPlaceholderContainer-Protocol.h"
#import "DVTProgressIndicatorProvidingView-Protocol.h"

@class NSArray, NSEvent, NSFont, NSMapTable, NSMutableSet, NSString, NSTextFieldCell, NSTrackingArea;

@interface DVTOutlineView : NSOutlineView <DVTProgressIndicatorProvidingView, DVTEmptyContentPlaceholderContainer>
{
    NSMapTable *_progressIndicatorsByItem;
    NSTrackingArea *_mouseHoverTrackingArea;
    NSTextFieldCell *_dataCellForGroupRow;
    NSString *_delegateClassName;
    NSString *_dvtTableRowViewIdentifier;
    NSMutableSet *_dvtTableCellViewOneLineIdentifiers;
    NSMutableSet *_dvtTableCellViewMultiLineIdentifiers;
    BOOL _hasRunEmptyContentPlaceholderLayout;
    struct {
        unsigned int breaksCyclicSortDescriptors:1;
        unsigned int delegateRespondsToShouldMouseHover:1;
        unsigned int hasSetCustomNonLocalDraggingSourceOperationMask:1;
        unsigned int hasSetCustomLocalDraggingSourceOperationMask:1;
        unsigned int allowsSizingShorterThanClipView:1;
        unsigned int reserved:2;
    } _dvtOVFlags;
    unsigned long long _gridLineStyleBeforeEmptyContentStringShown;
    BOOL _hasContent;
    BOOL _wantsMouseEnteredExitedAndMovedEvents;
    NSString *_emptyContentString;
    NSString *_emptyContentSubtitle;
    NSString *_emptyContentButtonTitle;
    long long _emptyContentStringStyle;
    NSFont *_emptyContentFont;
    NSEvent *_event;
    long long _rowUnderHoveredMouse;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
// - (void).cxx_destruct;
@property BOOL wantsMouseEnteredExitedAndMovedEvents; // @synthesize wantsMouseEnteredExitedAndMovedEvents=_wantsMouseEnteredExitedAndMovedEvents;
@property long long rowUnderHoveredMouse; // @synthesize rowUnderHoveredMouse=_rowUnderHoveredMouse;
@property(retain) NSEvent *event; // @synthesize event=_event;
@property(nonatomic) BOOL hasContent; // @synthesize hasContent=_hasContent;
@property(copy, nonatomic) NSFont *emptyContentFont; // @synthesize emptyContentFont=_emptyContentFont;
@property(nonatomic) long long emptyContentStringStyle; // @synthesize emptyContentStringStyle=_emptyContentStringStyle;
@property(copy, nonatomic) NSString *emptyContentButtonTitle; // @synthesize emptyContentButtonTitle=_emptyContentButtonTitle;
@property(copy, nonatomic) NSString *emptyContentSubtitle; // @synthesize emptyContentSubtitle=_emptyContentSubtitle;
@property(copy, nonatomic) NSString *emptyContentString; // @synthesize emptyContentString=_emptyContentString;
- (unsigned long long)draggingSourceOperationMaskForLocal:(BOOL)arg1;
- (void)setDraggingSourceOperationMask:(unsigned long long)arg1 forLocal:(BOOL)arg2;
- (void)concludeDragOperation:(id)arg1;
- (void)draggingEnded:(id)arg1;
- (unsigned long long)draggingUpdated:(id)arg1;
- (unsigned long long)draggingEntered:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseMoved:(id)arg1;
- (void)_processMouseMovedEvent:(id)arg1;
- (void)_updateDisplayOfItemUnderMouse;
- (id)itemUnderHoveredMouse;
- (void)setRowUnderHoveredMouseAndMarkForRedisplay:(long long)arg1;
- (void)updateTrackingAreas;
- (void)insertText:(id)arg1;
- (void)doCommandBySelector:(SEL)arg1;
- (void)keyDown:(id)arg1;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)viewWillMoveToSuperview:(id)arg1;
- (void)_cleanupWork;
- (void)viewWillDraw;
- (void)layout;
- (void)willHideEmptyContentString;
- (void)willShowEmptyContentString;
- (void)unhideRowsAtIndexes:(id)arg1 withAnimation:(unsigned long long)arg2;
- (void)hideRowsAtIndexes:(id)arg1 withAnimation:(unsigned long long)arg2;
- (void)moveItemAtIndex:(long long)arg1 inParent:(id)arg2 toIndex:(long long)arg3 inParent:(id)arg4;
- (void)removeItemsAtIndexes:(id)arg1 inParent:(id)arg2 withAnimation:(unsigned long long)arg3;
- (void)insertItemsAtIndexes:(id)arg1 inParent:(id)arg2 withAnimation:(unsigned long long)arg3;
- (void)reloadItem:(id)arg1 reloadChildren:(BOOL)arg2;
- (void)noteNumberOfRowsChanged;
- (void)reloadData;
- (void)_synchronizeHasContentPropertyWithRowCount;
- (BOOL)_shouldRemoveProgressIndicator:(id)arg1 forItem:(id)arg2 andVisibleRect:(struct CGRect)arg3;
- (id)preparedCellAtColumn:(long long)arg1 row:(long long)arg2;
- (Class)groupRowCellClassForDataCell:(id)arg1;
- (id)_dataCellForGroupRowWithClass:(Class)arg1;
- (id)groupRowFont;
- (void)_drawRowHeaderSeparatorInClipRect:(struct CGRect)arg1;
- (void)_drawBackgroundForGroupRow:(long long)arg1 clipRect:(struct CGRect)arg2 isButtedUpRow:(BOOL)arg3;
@property(readonly) NSArray *contextMenuSelectedItems;
@property(retain) NSArray *selectedItems;
- (id)itemsAtIndexes:(id)arg1;
- (void)setSortDescriptors:(id)arg1;
- (struct CGSize)_adjustFrameSizeToFitSuperview:(struct CGSize)arg1;
@property BOOL allowsSizingShorterThanClipView;
@property BOOL breaksCyclicSortDescriptors;
- (id)progressIndicatorForItem:(id)arg1 createIfNecessary:(BOOL)arg2 progressIndicatorStyle:(unsigned long long)arg3;
- (void)setDelegate:(id)arg1;
- (void)_registerNibWithName:(id)arg1 usingIdentifier:(id)arg2;
- (void)registerDVTTableCellViewPlaceholderNibUsingIdentifier:(id)arg1;
- (id)makeViewWithIdentifier:(id)arg1 owner:(id)arg2;
- (void)registerDVTTableRowViewNibUsingIdentifier:(id)arg1;
- (void)registerDVTTableRowViewUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewMultiLineNibUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewMultiLineUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewOneLineNibUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewOneLineUsingIdentifier:(id)arg1;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dvt_commonInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(nonatomic) BOOL followsFontAndColorTheme;
@property(readonly) Class superclass;

@end

