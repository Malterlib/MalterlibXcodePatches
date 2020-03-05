//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEViewController.h"

#import "IDEDebuggerBarEditorInfoProvider-Protocol.h"
#import "IDEEditorMultipleSplitDelegate-Protocol.h"

@class DVTBorderedView, DVTLayoutView_ML, DVTObservingToken, DVTReplacementView, DVTSplitView, DVTSplitViewItem, DVTStateToken, IDEDebugArea, IDEDebugBar, IDEEditorAreaSplit, IDEEditorContext, IDEEditorDocument, IDEEditorModeViewController, IDEEditorMultipleSplit, IDENavigableItemArchivableRepresentation, NSArray, NSDictionary, NSIndexPath, NSMutableArray, NSMutableDictionary, NSNumber, NSString, NSTouchBar, NSView;
@protocol DVTCancellable;

@interface IDEEditorArea : IDEViewController <NSTouchBarProvider, NSTouchBarDelegate, IDEDebuggerBarEditorInfoProvider, IDEEditorMultipleSplitDelegate>
{
    NSView *_editorAreaSplitHostView;
    int _editorMode;
    DVTObservingToken *_workspaceActivityObserver;
    DVTObservingToken *_navigationTargetedEditorContextIsValidObservingToken;
    DVTObservingToken *_finishedLoadingObservingToken;
    IDEEditorContext *_lastActiveEditorContext;
    IDEDebugBar *_activeDebuggerBar;
    IDEDebugArea *_activeDebuggerArea;
    NSMutableDictionary *_defaultPersistentRepresentations;
    NSString *_currentDefaultDebugAreaExtensionID;
    NSMutableArray *_editorAreaSplits_propertyObservingTokens;
    DVTLayoutView_ML *_editorAreaAutoLayoutView;
    DVTLayoutView_ML *_debuggerAreaAutoLayoutView;
    DVTBorderedView *_debuggerBarBorderedView;
    DVTBorderedView *_debuggerAreaBorderedView;
    DVTReplacementView *_debuggerBarReplacementView;
    DVTReplacementView *_debuggerAreaReplacementView;
    DVTSplitView *_debuggerSplitView;
    DVTSplitViewItem *_debugAreaSplitViewItem;
    double _heightToReturnToDebuggerArea;
    id _launchSessionObserver;
    BOOL _needsToRefreshContexts;
    BOOL _didRestoreState;
    BOOL _userWantsEditorVisible;
    BOOL _restoringStateSelfInitiated;
    BOOL _showDebuggerArea;
    id <DVTCancellable> _setEditorModeAfterDelayToken;
    id <DVTCancellable> _invokeCompletionBlockAfterDelayToken;
    DVTObservingToken *_lastActiveEditorContextIsValidToken;
    DVTObservingToken *_primaryEditorDocumentToken;
    DVTObservingToken *_workspaceFinishedLoadingToken;
    NSArray *_beforeMaximizeEditorAreaSplitStates;
    NSIndexPath *_indexPathOfMaximizedEditorAreaSplit;
    BOOL _beforeMaximizeComparisonMode_isMaximized;
    int _beforeMaximizeComparisonMode_UserVisibleEditorMode;
    NSDictionary *_unrestoredStateDictionary;
    NSNumber *_setShowDebuggerAreaReentrancyCheck;
    BOOL _isRestoringState;
    IDEEditorAreaSplit *_primaryEditorAreaSplit;
    NSArray *_editorAreaSplits;
    IDEEditorMultipleSplit *_editorMultipleSplit;
    IDEEditorDocument *_primaryEditorDocument;
    IDEEditorAreaSplit *_selectedEditorAreaSplit;
    IDEEditorContext *_navigationTargetedEditorContext;
    long long _maximizedState;
}

+ (id)_copyEditorAreaSplitToParentEditorMultipleSplit:(id)arg1 client:(unsigned long long)arg2;
+ (int)defaultEditorMode;
+ (void)_performConfigurationTransaction:(CDUnknownBlockType)arg1;
+ (BOOL)_isRunningConfigurationTransaction;
+ (id)_configurationTransactionScope;
+ (long long)version;
+ (void)configureStateSavingObjectPersistenceByName:(id)arg1;
+ (id)keyPathsForValuesAffectingShowEditor;
+ (id)keyPathsForValuesAffectingSelectedNavigableItemArchivedRepresentation;
+ (id)keyPathsForValuesAffectingNavigationTargetedEditorDocument;
+ (id)keyPathsForValuesAffectingPrimaryEditorContext;
+ (BOOL)automaticallyNotifiesObserversOfLastActiveEditorContext;
+ (id)keyPathsForValuesAffectingLastActiveEditorAreaSplit;
+ (BOOL)_newEditorsHaveEmptyContent;
// - (void).cxx_destruct;
@property BOOL isRestoringState; // @synthesize isRestoringState=_isRestoringState;
@property long long maximizedState; // @synthesize maximizedState=_maximizedState;
@property(retain) IDEEditorContext *navigationTargetedEditorContext; // @synthesize navigationTargetedEditorContext=_navigationTargetedEditorContext;
@property(retain, nonatomic) IDEEditorAreaSplit *selectedEditorAreaSplit; // @synthesize selectedEditorAreaSplit=_selectedEditorAreaSplit;
@property(retain) IDEEditorDocument *primaryEditorDocument; // @synthesize primaryEditorDocument=_primaryEditorDocument;
@property(retain) IDEEditorMultipleSplit *editorMultipleSplit; // @synthesize editorMultipleSplit=_editorMultipleSplit;
@property(retain) NSArray *editorAreaSplits; // @synthesize editorAreaSplits=_editorAreaSplits;
@property(retain) IDEEditorAreaSplit *primaryEditorAreaSplit; // @synthesize primaryEditorAreaSplit=_primaryEditorAreaSplit;
@property(retain) IDEDebugArea *activeDebuggerArea; // @synthesize activeDebuggerArea=_activeDebuggerArea;
@property(retain) IDEDebugBar *activeDebuggerBar; // @synthesize activeDebuggerBar=_activeDebuggerBar;
@property(retain, nonatomic) IDEEditorContext *lastActiveEditorContext; // @synthesize lastActiveEditorContext=_lastActiveEditorContext;
@property(readonly) DVTReplacementView *debuggerAreaReplacementView; // @synthesize debuggerAreaReplacementView=_debuggerAreaReplacementView;
@property(nonatomic) BOOL userWantsEditorVisible; // @synthesize userWantsEditorVisible=_userWantsEditorVisible;
- (void)editorMultipleSplit:(id)arg1 didRemoveSplitItem:(id)arg2 fromIndex:(unsigned long long)arg3;
- (void)editorMultipleSplit:(id)arg1 willRemoveSplitItem:(id)arg2 fromIndex:(unsigned long long)arg3;
- (id)editorArea;
- (void)didResizeEditorMultipleSplit:(id)arg1;
- (void)editorMultipleSplit:(id)arg1 didCreateSplitItem:(id)arg2;
- (void)_updateEditorAreaSplitsWithoutSplitItem:(id)arg1;
- (void)_updateEditorAreaSplits;
- (id)_maximizeComparisonMode:(BOOL)arg1 withEditorAreaSplit:(id)arg2 client:(unsigned long long)arg3;
- (void)_primitiveRestoreEditorSplitsWithStateDictionaries:(id)arg1 maximizedState:(long long)arg2 selectedEditorSplitIndexPath:(id)arg3 primaryHistoryStackForSelectedEditor:(id)arg4 secondaryHistoryStackForSelectedEditor:(id)arg5 client:(unsigned long long)arg6;
- (void)_restoreEditorSplitsWithStateDictionaries:(id)arg1 maximizedState:(long long)arg2 selectedEditorSplitIndexPath:(id)arg3 primaryHistoryStackForSelectedEditor:(id)arg4 secondaryHistoryStackForSelectedEditor:(id)arg5 client:(unsigned long long)arg6;
- (id)_indexPathForEditorAreaSplit:(id)arg1;
- (void)_unmaximizeAndSelectedEditorAreaSplitWithClient:(unsigned long long)arg1;
- (void)toggleMaximizeWithEditorAreaSplit:(id)arg1 client:(unsigned long long)arg2;
- (BOOL)canToggleMaximizeEditor;
- (void)toggleMaximizedComparisonModeWithEditorAreaSplit:(id)arg1 client:(unsigned long long)arg2;
- (void)_cancelPendingStateRestoration;
@property(readonly) unsigned long long editorAreaSplitsLayout;
@property(readonly) IDEEditorModeViewController *editorModeViewController;
@property(nonatomic) int editorMode; // @synthesize editorMode=_editorMode;
- (void)_resetEditorSizes;
- (BOOL)_canResetEditorSizes;
- (void)_closeEditorContext:(id)arg1 client:(unsigned long long)arg2;
- (BOOL)_canCloseEditorContext:(id)arg1;
- (void)_closeOtherEditorsUsingClient:(unsigned long long)arg1;
- (id)_closeAllEditorAreaSplitsKeeping:(id)arg1 client:(unsigned long long)arg2;
- (BOOL)_canCloseOtherEditors;
- (void)_resetAssistantEditorSelection;
- (BOOL)_canResetAssistantEditorSelection;
- (void)_removeEditorAreaSplit:(id)arg1 client:(unsigned long long)arg2;
- (BOOL)_canRemoveEditorAreaSplit:(id)arg1;
- (id)_addNewEditorAreaSplitAtIndex:(unsigned long long)arg1 layout:(unsigned long long)arg2 client:(unsigned long long)arg3;
- (BOOL)_canAddNewEditorAreaSplitAtIndex:(unsigned long long)arg1 layout:(unsigned long long)arg2;
- (id)_addEditorAreaSplitAfterEditorAreaSplit:(id)arg1 copyContent:(BOOL)arg2 layout:(unsigned long long)arg3 client:(unsigned long long)arg4;
- (BOOL)_canAddEditorAreaSplitAfterEditorAreaSplit:(id)arg1 layout:(unsigned long long)arg2;
- (BOOL)_canChangeEditorAreaSplitsLayout;
- (void)openMaximizedComparisonModeWithDocumentLocation:(id)arg1 client:(unsigned long long)arg2;
- (void)openMaximizedComparisonModeWithRevision:(id)arg1 client:(unsigned long long)arg2;
- (void)compareRevisionChange:(id)arg1;
- (void)showBlame;
- (void)discardEditing;
- (BOOL)commitEditingForAction:(int)arg1 errors:(id)arg2;
- (void)commitStateToDictionary:(id)arg1;
- (void)_restoreEditorSplitsWhenWorkspaceFinishesLoading:(CDUnknownBlockType)arg1;
- (void)_primitiveRevertStateWithDictionary:(id)arg1;
- (void)revertStateWithDictionary:(id)arg1;
- (unsigned long long)_layoutForString:(id)arg1 defaultValue:(unsigned long long)arg2;
- (id)_stringForLayout:(unsigned long long)arg1;
- (void)revertState;
@property(retain) DVTStateToken *stateToken; // @dynamic stateToken;
- (void)_updateStateSavingRegistrations;
- (void)splitView:(id)arg1 resizeSubviewsWithOldSize:(struct CGSize)arg2;
- (void)_resizeSubviewsForHeightIncrease:(double)arg1;
- (void)_resizeSubviewsForHeightDecrease:(double)arg1;
- (id)splitView:(id)arg1 additionalEffectiveRectsOfDividerAtIndex:(long long)arg2;
- (double)splitView:(id)arg1 constrainSplitPosition:(double)arg2 ofSubviewAt:(long long)arg3;
- (BOOL)splitView:(id)arg1 canCollapseSubview:(id)arg2;
- (double)splitView:(id)arg1 constrainMaxCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (double)splitView:(id)arg1 constrainMinCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (void)toggleEditorOrientation:(id)arg1;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (void)toggleDebuggerVisibility:(id)arg1;
- (void)activateConsole:(id)arg1;
@property BOOL showDebuggerArea;
- (void)_setShowDebuggerArea:(BOOL)arg1 animate:(BOOL)arg2;
- (void)showDebuggerArea:(id)arg1;
@property BOOL showEditor;
- (void)_updateDebuggerBarVisibility;
- (void)_addDebuggerBarToDebuggerArea;
- (void)_addDebuggerBarToEditorArea;
- (void)_moveDebuggerBarToDebuggerArea;
- (void)_moveDebuggerBarToEditorArea;
- (void)_hideDebuggerBarAndResetSplitViewFrames;
- (void)_resetSplitViewFrames;
@property(readonly) BOOL showDebuggerBar;
- (id)_defaultPersistentRepresentationForDocumentExtensionIdentifier:(id)arg1 documentURL:(id)arg2;
- (void)_clearDefaultPersistentRepresentationForDocumentExtensionIdentifier:(id)arg1 documentURL:(id)arg2;
- (void)_cacheDefaultPersistentRepresentation:(id)arg1 forDocumentExtensionIdentifier:(id)arg2 documentURL:(id)arg3;
- (void)setStateSavingDefaultPersistentRepresentations:(id)arg1;
- (id)stateSavingDefaultPersistentRepresentations;
- (id)_editorContexts;
- (BOOL)_openEditorOpenSpecifier:(id)arg1 editorContext:(id)arg2 takeFocus:(BOOL)arg3;
- (BOOL)_openEditorHistoryItem:(id)arg1 editorContext:(id)arg2 takeFocus:(BOOL)arg3;
@property(readonly) IDENavigableItemArchivableRepresentation *selectedNavigableItemArchivedRepresentation;
@property(readonly) IDEEditorDocument *navigationTargetedEditorDocument;
@property(readonly) IDEEditorContext *primaryEditorContext;
- (void)_installDebugAreaWithExtensionID:(id)arg1 revertDebugAreaState:(BOOL)arg2;
- (void)installDebugAreaWithExtensionID:(id)arg1;
- (void)installNewDefaultDebugAreaWithExtensionID:(id)arg1;
- (void)_installDefaultDebugAreaAndRevertDebugAreaState:(BOOL)arg1;
- (void)installDefaultDebugArea;
- (void)editorContextWasRemoved:(id)arg1;
- (void)_updateNavigationTargetedEditorContextIsValidObservingToken;
- (void)editorContextDidBecomeLastActiveEditor:(id)arg1 focused:(BOOL)arg2;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (void)_refreshEditorContextsAndPreserveCurrentEditorHistoryStack:(BOOL)arg1;
- (void)__staticAnalyzer_InstanceVariablePartialInvalidator;
- (void)primitiveInvalidate;
- (void)_updateDebugAreaAfterDocumentOpened;
- (void)_updateDebugBarAfterDocumentOpened;
- (void)_updateJumpBarConfigurations;
- (void)_didRefreshEditorContextsForEditorAreaSplit:(id)arg1;
- (void)_primitiveLoadView;
- (void)loadView;
@property(readonly) IDEEditorAreaSplit *lastActiveEditorAreaSplit;
- (id)editorAreaDFRController;
- (id)_fileHistoryNavigationMode;
- (void)validateHistoryNavigation;
- (void)navigateHistoryWithSegmentedControl:(id)arg1;
- (id)_segmentedControlForHistoryNavigation;
- (id)_editorAreaItem;
- (id)touchBar:(id)arg1 makeItemForIdentifier:(id)arg2;
- (id)_touchBarForNavigatorWidget;
- (id)makeTouchBar;
- (void)updateTouchBar;
- (BOOL)wantsToSuppressFunctionBar;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;
@property(readonly) NSTouchBar *touchBar;

@end

