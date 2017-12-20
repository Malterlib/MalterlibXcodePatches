//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//

#include "Shared.h"

#import "DVTEmptyContentPlaceholderContainer-Protocol.h"
#import "DVTProgressIndicatorProvidingView-Protocol.h"

@class NSArray, NSEvent, NSFont, NSMapTable, NSString, NSTextFieldCell, NSTrackingArea;

@interface DVTOutlineView : NSOutlineView <DVTProgressIndicatorProvidingView, DVTEmptyContentPlaceholderContainer>
{
    NSMapTable *_progressIndicatorsByItem;
    NSTrackingArea *_mouseHoverTrackingArea;
    NSTextFieldCell *_dataCellForGroupRow;
    NSString *_delegateClassName;
    struct {
        unsigned int breaksCyclicSortDescriptors:1;
        unsigned int delegateRespondsToShouldMouseHover:1;
        unsigned int hasSetCustomNonLocalDraggingSourceOperationMask:1;
        unsigned int hasSetCustomLocalDraggingSourceOperationMask:1;
        unsigned int allowsSizingShorterThanClipView:1;
        unsigned int reserved:2;
    } _dvtOVFlags;
    unsigned long long _gridLineStyleBeforeEmptyContentStringShown;
    BOOL _wantsMouseEnteredExitedAndMovedEvents;
    int _emptyContentStringStyle;
    NSString *_emptyContentString;
    NSString *_emptyContentSubtitle;
    NSFont *_emptyContentFont;
    NSEvent *_event;
    long long _rowUnderHoveredMouse;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
@property BOOL wantsMouseEnteredExitedAndMovedEvents; // @synthesize wantsMouseEnteredExitedAndMovedEvents=_wantsMouseEnteredExitedAndMovedEvents;
@property long long rowUnderHoveredMouse; // @synthesize rowUnderHoveredMouse=_rowUnderHoveredMouse;
@property(retain) NSEvent *event; // @synthesize event=_event;
@property(copy, nonatomic) NSFont *emptyContentFont; // @synthesize emptyContentFont=_emptyContentFont;
@property(nonatomic) int emptyContentStringStyle; // @synthesize emptyContentStringStyle=_emptyContentStringStyle;
@property(copy, nonatomic) NSString *emptyContentSubtitle; // @synthesize emptyContentSubtitle=_emptyContentSubtitle;
@property(copy, nonatomic) NSString *emptyContentString; // @synthesize emptyContentString=_emptyContentString;
// - (void).cxx_destruct;
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
- (BOOL)_isViewBased;
- (void)insertText:(id)arg1;
- (void)doCommandBySelector:(SEL)arg1;
- (void)keyDown:(id)arg1;
- (double)_estimatedWidthForContentAtRow:(long long)arg1;
- (void)viewWillMoveToWindow:(id)arg1;
- (void)viewWillMoveToSuperview:(id)arg1;
- (void)_cleanupWork;
- (void)viewWillDraw;
- (void)willHideEmptyContentString;
- (void)willShowEmptyContentString;
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
- (void)registerDVTTableRowViewNibUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewMultiLineNibUsingIdentifier:(id)arg1;
- (void)registerDVTTableCellViewOneLineNibUsingIdentifier:(id)arg1;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)dvt_commonInit;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

