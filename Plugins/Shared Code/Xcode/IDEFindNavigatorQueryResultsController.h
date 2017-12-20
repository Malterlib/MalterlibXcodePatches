//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"
#import "IDEBatchFindQueryDelegate-Protocol.h"

@class DVTDelayedInvocation, DVTNotificationToken, DVTStackBacktrace, IDEBatchFindAbstractQuery, IDEBatchFindAbstractResult, IDEBatchFindLineWrappingParameters, IDEBatchFindQuerySpecification, IDEFindNavigatorFilteredResultSet, IDEFindNavigatorOutlineView, IDEWorkspaceDocument, NSArray, NSMapTable, NSSet, NSString;
@protocol IDEFindNavigatorQueryResultsControllerDelegate;

@interface IDEFindNavigatorQueryResultsController : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate, IDEBatchFindQueryDelegate, DVTInvalidation>
{
    IDEBatchFindLineWrappingParameters *_lineWrappingParameters;
    IDEFindNavigatorFilteredResultSet *_resultSet;
    IDEBatchFindAbstractResult *_rootResult;
    long long _programaticOutlineViewSelectionBlocks;
    DVTDelayedInvocation *_rowHeightValidator;
    IDEBatchFindAbstractQuery *_query;
    NSArray *_filterMatchStrings;
    NSString *_filterText;
    DVTNotificationToken *_maximumNumberOfLinesObservingToken;
    IDEWorkspaceDocument *_workspaceDocument;
    NSSet *_selectedResults;
    NSMapTable *_searchResultDisplayRecords;
    NSString *_queryPlaceholderText;
    BOOL _completed;
    IDEFindNavigatorOutlineView *_outlineView;
    id <IDEFindNavigatorQueryResultsControllerDelegate> _delegate;
    long long _progress;
    IDEBatchFindQuerySpecification *_specification;
}

+ (void)initialize;
+ (id)lineWrappingParametersForOutlineView:(id)arg1;
@property(readonly) BOOL completed; // @synthesize completed=_completed;
@property(readonly) IDEBatchFindQuerySpecification *specification; // @synthesize specification=_specification;
@property(readonly) IDEBatchFindAbstractQuery *query; // @synthesize query=_query;
@property(readonly) long long progress; // @synthesize progress=_progress;
@property __weak id <IDEFindNavigatorQueryResultsControllerDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) IDEFindNavigatorOutlineView *outlineView; // @synthesize outlineView=_outlineView;
// - (void).cxx_destruct;
- (void)findNavigatorQuery:(id)arg1 didGenerateResults:(id)arg2;
- (BOOL)shouldItemBeInitiallyExpandedWhileFiltered:(id)arg1;
- (void)findNavigatorQuery:(id)arg1 isStalledOnFilePaths:(id)arg2;
- (void)findNavigatorQuery:(id)arg1 didFinishGeneratingLazyChildrenOfResult:(id)arg2;
- (void)findNavigatorQueryDidComplete:(id)arg1;
@property(readonly) NSString *placeholderText;
- (void)findNavigatorQuery:(id)arg1 progressUpdate:(long long)arg2;
- (void)replaceMatchesFromResults:(id)arg1 withText:(id)arg2;
- (id)replaceStateForFindResult:(id)arg1;
- (BOOL)outlineView:(id)arg1 writeItems:(id)arg2 toPasteboard:(id)arg3;
- (BOOL)outlineView:(id)arg1 doCommandBySelector:(SEL)arg2;
- (void)invokeWithReplaceableDocumentForLocation:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)validateRowHeights:(id)arg1;
- (void)validateRowHeightsAnimated:(BOOL)arg1;
- (double)outlineView:(id)arg1 heightOfRowByItem:(id)arg2;
- (id)outlineView:(id)arg1 viewForTableColumn:(id)arg2 item:(id)arg3;
@property(readonly) long long fileCount;
@property(readonly) long long matchCount;
- (BOOL)outlineView:(id)arg1 isItemExpandable:(id)arg2;
- (id)outlineView:(id)arg1 child:(long long)arg2 ofItem:(id)arg3;
- (long long)outlineView:(id)arg1 numberOfChildrenOfItem:(id)arg2;
- (void)outlineViewDoubleClicked:(id)arg1;
- (void)outlineViewClicked:(id)arg1;
- (void)openClickedRowWithEventType:(unsigned long long)arg1;
- (void)outlineViewSelectionDidChange:(id)arg1;
- (void)exportSelectionAllowingImpliedOpenCommand:(BOOL)arg1;
- (void)outlineViewColumnDidResize:(id)arg1;
- (void)outlineViewItemDidCollapse:(id)arg1;
- (void)outlineViewItemDidExpand:(id)arg1;
- (void)deleteResults:(id)arg1;
- (void)applyFilter:(id)arg1 isRestoringState:(BOOL)arg2;
- (void)selectFindResult:(id)arg1 openResultsInEditor:(BOOL)arg2;
- (void)expandItemAndAncestors:(id)arg1;
- (id)contextMenuFocusedResults;
- (id)selectedResults;
- (id)allVisibleResults;
- (id)visibleResultsInOutlineOrder;
- (void)primitiveInvalidate;
- (void)didCompleteFirstLayout;
- (id)regenerateLineWrappingParameters;
- (void)pushExpansionStates;
- (void)recusrivelyPushExpansionStateForChildrenOfItem:(id)arg1;
- (void)initiate;
- (id)initWithQuerySpecification:(id)arg1 initialLineWrappingParameters:(id)arg2 workspaceDocument:(id)arg3 delegate:(id)arg4 error:(id *)arg5;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

