//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//

#include "Shared.h"

#import "IDEViewController.h"

#import "DVTEditor-Protocol.h"
#import "DVTReplacementViewDelegate-Protocol.h"
#import "DVTStatefulObject-Protocol.h"
#import "IDEAttachToProcessErrorHandler-Protocol.h"
#import "IDEEditorAreaContainer-Protocol.h"
#import "IDEProvisioningManagerDelegate-Protocol.h"
#import "IDEStructureEditingWorkspaceTabContext-Protocol.h"
#import "IDEWorkspaceDocumentProvider-Protocol.h"

@class DVTMutableOrderedSet, DVTObservingToken, DVTReplacementView, DVTSplitView, DVTSplitViewItem, DVTTextDocumentLocation, IDEARCConversionAssistantContext, IDEAppChooserWindowController, IDEBuildAlertMonitor, IDEEditorArea, IDEExecutionHoldAlertHelper, IDEFindNavigatorQueryResultsController, IDELaunchSession, IDENavigatorArea, IDEObjCModernizationAssistantContext, IDERunAlertMonitor, IDESwiftMigrationAssistantContext, IDEWorkspace, IDEWorkspaceDocument, IDEWorkspaceWindowController, NSAlert, NSMapTable, NSMutableArray, NSString;
@protocol DVTInvalidation;

@interface IDEWorkspaceTabController : IDEViewController <NSTextViewDelegate, DVTStatefulObject, DVTReplacementViewDelegate, IDEEditorAreaContainer, IDEStructureEditingWorkspaceTabContext, IDEWorkspaceDocumentProvider, DVTEditor, IDEProvisioningManagerDelegate, IDEAttachToProcessErrorHandler>
{
    DVTSplitView *_designAreaSplitView;
    DVTReplacementView *_navReplacementView;
    DVTReplacementView *_editorReplacementView;
    DVTReplacementView *_inspectorReplacementView;
    DVTSplitViewItem *_navigatorAreaSplitViewItem;
    DVTSplitViewItem *_inspectorsAreaSplitViewItem;
    DVTMutableOrderedSet *_cursorRectInterceptors;
    NSMapTable *_additionControllersForLaunchSessionTable;
    NSMutableArray *_debuggingUIControllerLifeCycleObservers;
    NSMapTable *_notificationTokenForLaunchSessionTable;
    NSMapTable *_observerTokenForLaunchSessionsDebuggingAdditionsTable;
    NSMutableArray *_uiControllerObserverEntries;
    DVTObservingToken *_mainCurrentLaunchSessionObserverToken;
    DVTObservingToken *_currentLaunchSessionStateObserverToken;
    DVTObservingToken *_launchSessionAlertErrorObservingToken;
    DVTObservingToken *_debugSessionObserverToken;
    DVTObservingToken *_debugSessionCoalescedStateObservingToken;
    DVTObservingToken *_currentStackFrameDisassemblyObservingToken;
    DVTObservingToken *_firstTimeSnapshotObserverToken;
    NSAlert *_stoppingExecutionAlert;
    id _pendingExecutionNotificationToken;
    CDUnknownBlockType _pendingEnqueuingCompletionBlock;
    IDERunAlertMonitor *_runAlertMonitor;
    IDEARCConversionAssistantContext *_conversionAssistantContext;
    IDEObjCModernizationAssistantContext *_objcModernizationAssistantContext;
    IDESwiftMigrationAssistantContext *_swiftMigrationAssistantContext;
    id <DVTInvalidation> _libraryInstallationToken;
    CDUnknownBlockType _openSimpleFileEditorOpenSpecifierCompletionBlock;
    BOOL _userWantsInspectorAreaVisible;
    BOOL _userWantsNavigatorVisible;
    BOOL _isAnimatingInspectorArea;
    BOOL _completedInitialStateRestore;
    BOOL _tabLoadingCompleted;
    IDEWorkspaceDocument *_workspaceDocument;
    NSString *_userDefinedTabLabel;
    IDELaunchSession *_currentLaunchSession;
    IDEFindNavigatorQueryResultsController *_findNavigatorQueryResultsController;
    DVTTextDocumentLocation *_issueInstructionPointerLocation;
    DVTTextDocumentLocation *_issueInstructionPointerLocationForDisassembly;
    DVTObservingToken *_documentLoadingObservationToken;
    DVTObservingToken *_firstIssueObservationToken;
    DVTObservingToken *_buildCompleteObservationToken;
    IDEAppChooserWindowController *_appChooserWindowController;
    IDEExecutionHoldAlertHelper *_executionHoldAlertHelper;
    IDEBuildAlertMonitor *_buildAlertMonitor;
    unsigned long long _assistantEditorsLayout;
    NSString *_tabLabel;
    NSString *_name;
    NSString *_stateSavingIdentifier;
}

+ (void)initialize;
+ (id)keyPathsForValuesAffectingEditorArea;
+ (id)keyPathsForValuesAffectingNavigatorArea;
+ (id)keyPathsForValuesAffectingWindowController;
+ (id)keyPathsForValuesAffectingShowNavigator;
+ (id)keyPathsForValuesAffectingShowInspectorArea;
+ (id)keyPathsForValuesAffectingLibraryAnchoringEditor;
+ (id)keyPathsForValuesAffectingWorkspace;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (long long)version;
+ (void)configureStateSavingObjectPersistenceByName:(id)arg1;
+ (unsigned long long)defaultAssistantEditorsLayout;
+ (void)setDefaultAssistantEditorsLayout:(unsigned long long)arg1;
@property(copy) NSString *stateSavingIdentifier; // @synthesize stateSavingIdentifier=_stateSavingIdentifier;
@property(copy) NSString *name; // @synthesize name=_name;
@property(copy) NSString *tabLabel; // @synthesize tabLabel=_tabLabel;
@property(nonatomic) BOOL tabLoadingCompleted; // @synthesize tabLoadingCompleted=_tabLoadingCompleted;
@property(nonatomic) unsigned long long assistantEditorsLayout; // @synthesize assistantEditorsLayout=_assistantEditorsLayout;
@property(retain) IDEBuildAlertMonitor *buildAlertMonitor; // @synthesize buildAlertMonitor=_buildAlertMonitor;
@property(retain) IDEExecutionHoldAlertHelper *executionHoldAlertHelper; // @synthesize executionHoldAlertHelper=_executionHoldAlertHelper;
@property(retain) IDEAppChooserWindowController *appChooserWindowController; // @synthesize appChooserWindowController=_appChooserWindowController;
@property(retain) DVTObservingToken *buildCompleteObservationToken; // @synthesize buildCompleteObservationToken=_buildCompleteObservationToken;
@property(retain) DVTObservingToken *firstIssueObservationToken; // @synthesize firstIssueObservationToken=_firstIssueObservationToken;
@property(retain) DVTObservingToken *documentLoadingObservationToken; // @synthesize documentLoadingObservationToken=_documentLoadingObservationToken;
@property BOOL completedInitialStateRestore; // @synthesize completedInitialStateRestore=_completedInitialStateRestore;
@property(retain) DVTReplacementView *editorReplacementView; // @synthesize editorReplacementView=_editorReplacementView;
@property(retain) DVTTextDocumentLocation *issueInstructionPointerLocationForDisassembly; // @synthesize issueInstructionPointerLocationForDisassembly=_issueInstructionPointerLocationForDisassembly;
@property(retain) DVTTextDocumentLocation *issueInstructionPointerLocation; // @synthesize issueInstructionPointerLocation=_issueInstructionPointerLocation;
@property(retain, nonatomic) IDEFindNavigatorQueryResultsController *findNavigatorQueryResultsController; // @synthesize findNavigatorQueryResultsController=_findNavigatorQueryResultsController;
@property(retain, nonatomic) IDELaunchSession *currentLaunchSession; // @synthesize currentLaunchSession=_currentLaunchSession;
@property(copy) NSString *userDefinedTabLabel; // @synthesize userDefinedTabLabel=_userDefinedTabLabel;
@property(nonatomic) BOOL isAnimatingInspectorArea; // @synthesize isAnimatingInspectorArea=_isAnimatingInspectorArea;
@property(nonatomic) BOOL userWantsNavigatorVisible; // @synthesize userWantsNavigatorVisible=_userWantsNavigatorVisible;
@property(nonatomic) BOOL userWantsInspectorAreaVisible; // @synthesize userWantsInspectorAreaVisible=_userWantsInspectorAreaVisible;
@property(retain) IDEWorkspaceDocument *workspaceDocument; // @synthesize workspaceDocument=_workspaceDocument;
@property(retain) DVTReplacementView *navigatorReplacementView; // @synthesize navigatorReplacementView=_navReplacementView;
// - (void).cxx_destruct;
- (void)discardEditing;
- (BOOL)commitEditingForAction:(int)arg1 errors:(id)arg2;
- (void)provisioningManager:(id)arg1 repairable:(id)arg2 shouldAuthorizeUserAction:(id)arg3 authorizationCallback:(CDUnknownBlockType)arg4;
- (void)moveKeyboardFocusToPreviousEditor:(id)arg1;
- (void)moveKeyboardFocusToNextEditor:(id)arg1;
- (void)moveKeyboardFocusToPreviousArea:(id)arg1;
- (void)moveKeyboardFocusToNextArea:(id)arg1;
- (void)_moveKeyboardFocusToNextAreaForward:(BOOL)arg1 editorOnly:(BOOL)arg2;
- (id)_keyboardFocusAreas:(BOOL)arg1;
- (id)_currentFirstResponderArea;
- (void)performCloseWorkspace:(id)arg1;
- (void)_swiftMigrationFoundErrorsAlertDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)showSwiftMigrationAssistant:(id)arg1;
- (void)_objCModernizationFoundErrorsAlertDidEnd:(id)arg1 returnCode:(long long)arg2 contextInfo:(void *)arg3;
- (void)showModernObjectiveCConversionAssistant:(id)arg1;
- (void)showARCConversionAssistant:(id)arg1;
- (void)showAlertForNonAttachableArchitecture:(id)arg1;
- (void)handleAttachToProcessError:(id)arg1;
- (void)_workspaceDocument:(id)arg1 shouldClose:(BOOL)arg2 contextInfo:(void *)arg3;
- (void)setShowDisassemblyWhenDebugging:(id)arg1;
- (void)reloadConsole:(id)arg1;
- (void)clearConsole:(id)arg1;
- (void)viewMemory:(id)arg1;
- (void)showSharedLibrariesPopUp:(id)arg1;
- (void)attachByPIDOrName:(id)arg1;
- (void)attachToProcess:(id)arg1;
- (void)uiSnapshotRefresh:(id)arg1;
- (void)backgroundFetchEvent:(id)arg1;
- (void)stepOut:(id)arg1;
- (void)stepOverInstruction:(id)arg1;
- (void)stepOverThread:(id)arg1;
- (void)stepOver:(id)arg1;
- (void)stepIntoInstruction:(id)arg1;
- (void)stepIntoThread:(id)arg1;
- (void)stepInto:(id)arg1;
- (void)detach:(id)arg1;
- (void)pauseOrContinue:(id)arg1;
- (void)toggleBreakpoints:(id)arg1;
- (void)createConstraintErrorBreakpoint:(id)arg1;
- (void)createTestFailureBreakpoint:(id)arg1;
- (void)createSymbolicBreakpoint:(id)arg1;
- (void)createExceptionBreakpoint:(id)arg1;
- (void)createSwiftErrorBreakpoint:(id)arg1;
- (void)_createBreakpointOfClass:(Class)arg1 sender:(id)arg2;
- (void)editWorkspaceUserSettings:(id)arg1;
- (void)newRunContext:(id)arg1;
- (void)takeScreenshot:(id)arg1;
- (void)createBot:(id)arg1;
- (void)manageRunContexts:(id)arg1;
- (void)selectPreviousDestination:(id)arg1;
- (void)selectNextDestination:(id)arg1;
- (void)chooseDestination:(id)arg1;
- (void)selectPreviousRunContext:(id)arg1;
- (void)selectNextRunContext:(id)arg1;
- (void)chooseScheme:(id)arg1;
- (CDUnknownBlockType)_prevIndex;
- (CDUnknownBlockType)_nextIndex;
- (void)_selectDestination:(CDUnknownBlockType)arg1;
- (void)_selectRunContext:(CDUnknownBlockType)arg1;
- (void)editActiveRunContext:(id)arg1;
- (void)editAndAnalyzeActiveRunContext:(id)arg1;
- (void)editBuildAndArchiveActiveRunContext:(id)arg1;
- (void)editAndBuildForTestingActiveRunContext:(id)arg1;
- (void)editAndTestActiveRunContext:(id)arg1;
- (void)editAndBuildForProfilingActiveScheme:(id)arg1;
- (void)editAndProfileActiveScheme:(id)arg1;
- (void)editAndBuildForRunningActiveRunContext:(id)arg1;
- (void)editAndRunActiveRunContext:(id)arg1;
- (void)_doCommandForEditAndSchemeCommand:(id)arg1;
- (void)_doCommandForEditAndSchemeCommand:(id)arg1 schemeTask:(long long)arg2;
- (void)showAppChooserIfNecessaryForScheme:(id)arg1 runDestination:(id)arg2 command:(id)arg3 onCompletion:(CDUnknownBlockType)arg4;
- (id)_extensionRunnableForBundleIdentifier:(id)arg1 BuildableProduct:(id)arg2 Scheme:(id)arg3 extensionRunMode:(int)arg4;
- (BOOL)_shouldShowAppChooserForScheme:(id)arg1 command:(id)arg2;
- (void)_showAppChooserForCurrentSchemeIfNecessaryForCommand:(id)arg1 launch:(CDUnknownBlockType)arg2;
- (id)_generateErrorForScheme:(id)arg1;
- (void)showModalAlertForScheme:(id)arg1;
- (void)runWithoutBuildingForSchemeIdentifier:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (void)compileFileAtPath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)analyzeFileAtPath:(id)arg1;
- (void)generateAssemblyCodeForFilePath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)generatePreprocessedFileForFilePath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)cleanBuildFolder:(id)arg1;
- (void)reallyCleanBuildFolder;
- (void)_cleanForRunActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)cleanActiveRunContext:(id)arg1;
- (void)installActiveRunContext:(id)arg1;
- (void)analyzeActiveRunContext:(id)arg1;
- (void)buildAndRunToGenerateOptimizationProfileActiveRunContext:(id)arg1;
- (void)buildForInstallActiveRunContext:(id)arg1;
- (void)buildAndArchiveActiveRunContext:(id)arg1;
- (void)buildActiveRunContextWithTimingSummary:(id)arg1;
- (void)buildActiveRunContext:(id)arg1;
- (void)testActiveRunContextWithoutBuilding:(id)arg1;
- (void)buildForTestActiveRunContext:(id)arg1;
- (void)profileUsingActiveRunContextWithOverridingTestingSpecifiers:(id)arg1;
- (void)testUsingActiveRunContextWithOverridingTestingSpecifiers:(id)arg1 contextString:(id)arg2;
- (void)_testActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 additionalCommandLineArgs:(id)arg3 overridingEnvironmentVars:(id)arg4 contextString:(id)arg5 completionBlock:(CDUnknownBlockType)arg6;
- (void)testActiveRunContextWithContextString:(id)arg1;
- (void)testActiveRunContext:(id)arg1;
- (void)profileActiveSchemeWithoutBuilding:(id)arg1;
- (void)buildForProfileActiveRunContext:(id)arg1;
- (void)profileActiveScheme:(id)arg1;
- (void)runActiveRunContextWithoutBuilding:(id)arg1;
- (void)_runWithoutBuildingForScheme:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (void)_buildForRunActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)buildForRunActiveRunContext:(id)arg1;
- (void)_alertNonExistentWorkingDirectoryBeforeRunOrProfileForContext:(id)arg1 workingDirectory:(id)arg2 title:(id)arg3 defaultButton:(id)arg4 usingBlock:(CDUnknownBlockType)arg5 errorBlock:(CDUnknownBlockType)arg6;
- (void)_alertNonExistentWorkingDirectoryBeforeProfileForContext:(id)arg1 usingBlock:(CDUnknownBlockType)arg2 errorBlock:(CDUnknownBlockType)arg3;
- (void)_alertNonExistentWorkingDirectoryBeforeRunForContext:(id)arg1 usingBlock:(CDUnknownBlockType)arg2 errorBlock:(CDUnknownBlockType)arg3;
- (void)_askShouldBuildBeforeRunOrProfileForContext:(id)arg1 title:(id)arg2 defaultButton:(id)arg3 usingBlock:(CDUnknownBlockType)arg4;
- (void)_runActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 additionalCommandLineArgs:(id)arg3 overridingEnvironmentVars:(id)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (void)runActiveRunContext:(id)arg1;
- (void)_runScheme:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (BOOL)_needToSwitchSchemeActionToLLDB:(id)arg1;
- (void)_silentlySwitchToLLDBIfNecessary:(id)arg1;
- (void)_performDebuggableTaskOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 invokedViaScripting:(BOOL)arg3 completionBlock:(CDUnknownBlockType)arg4;
- (BOOL)_validToolchainForSchemeAction:(id)arg1 schemeCommand:(id)arg2;
- (id)_runtimeLLDBFilePath;
- (void)_debugSessionCoalescedStateChanged:(id)arg1 forDebugSession:(id)arg2;
- (BOOL)isActiveWorkspaceTabController;
- (id)debuggingAdditionUIControllersForLaunchSession:(id)arg1;
- (id)currentDebuggingAdditionUIControllers;
- (id)debugSessionController;
- (BOOL)_contentSizeCanBeZeroSize;
- (void)_performContextTask:(long long)arg1 command:(id)arg2 commandName:(id)arg3 buildCommand:(long long)arg4 filePath:(id)arg5 invocationRecord:(id)arg6 useLegacyCompletionBehavior:(BOOL)arg7 completionBlock:(CDUnknownBlockType)arg8;
- (void)_checkNeedToStopExistingExecutionForScheme:(id)arg1 runDestination:(id)arg2 task:(long long)arg3 command:(id)arg4 trackersToStop:(id)arg5 needToStopCurrentBuild:(char *)arg6 needToStopCurrentTest:(char *)arg7 needToStopCurrentExecution:(char *)arg8;
- (void)_performBlock:(CDUnknownBlockType)arg1 unlessBuildIsActiveWithScheme:(id)arg2 forSchemeOperationParameters:(id)arg3 useLegacyCompletionBehavior:(BOOL)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (void)_performTaskOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 useLegacyCompletionBehavior:(BOOL)arg3 invokedViaScripting:(BOOL)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (id)_errorForNoRunDestinationForCommandName:(id)arg1;
- (id)_errorForNoActiveSchemeForCommandName:(id)arg1;
- (CDUnknownBlockType)_legacyEnqueuingErrorBlock;
- (BOOL)_launchingOrProfiling:(long long)arg1 withNonExistentWorkingDirectory:(id)arg2;
- (void)_showWarningForBuild:(BOOL)arg1 forTest:(BOOL)arg2 forOtherExecution:(BOOL)arg3 trackersToStop:(id)arg4 taskActionBlock:(CDUnknownBlockType)arg5;
- (void)_runAnotherInstance:(id)arg1;
- (void)_acceptStoppingExecutionAlert:(id)arg1;
- (void)_rejectStoppingExecutionAlert:(id)arg1;
- (void)_cleanupAfterStoppingExecutionAlert;
- (void)_actuallyPerformTaskOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 useLegacyCompletionBehavior:(BOOL)arg3 enqueuingErrorBlock:(CDUnknownBlockType)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (CDUnknownBlockType)_deviceAvailableCheckerOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 enqueuingErrorBlock:(CDUnknownBlockType)arg3;
- (void)invalidateAllBuildAlertMonitorsForWorkspace;
- (BOOL)_cleanBuildFolderWithError:(id *)arg1;
- (void)observeBuildOperationForRestoringState:(id)arg1;
- (void)switchNavigatorOnBuild;
- (void)hideInspectorArea:(id)arg1;
- (void)showInspectorArea:(id)arg1;
- (BOOL)isInspectorAreaVisible;
- (void)toggleInspectorAreaVisibility:(id)arg1;
- (void)hideNavigator:(id)arg1;
- (BOOL)isNavigatorVisible;
- (void)toggleNavigatorsVisibility:(id)arg1;
- (void)changeToBreakpointsNavigator:(id)arg1;
- (void)changeToDebuggerNavigator:(id)arg1;
- (void)changeToWorkingCopiesNavigator:(id)arg1;
- (void)changeToFindNavigator:(id)arg1;
- (void)changeToTestNavigator:(id)arg1;
- (void)_changeToIssuesNavigatorForBuildIssues;
- (void)changeToIssuesNavigator:(id)arg1 showRuntime:(BOOL)arg2 clearFilterType:(unsigned long long)arg3;
- (void)changeToIssuesNavigator:(id)arg1;
- (void)changeToLogsNavigator:(id)arg1;
- (void)changeToSymbolsNavigator:(id)arg1;
- (void)revealSelectionInProjectNavigator:(id)arg1;
- (void)changeToStructureNavigator:(id)arg1;
- (void)showNavigatorWithIdentifier:(id)arg1;
- (void)changeToNavigatorWithIdentifier:(id)arg1 sender:(id)arg2;
- (void)_splitViewDidToggleClosed;
- (void)showInspectorWithChoiceFromSender:(id)arg1;
- (void)showInspectorCategoryWithExtensionIdentifier:(id)arg1;
- (void)showInspectorWithChoice:(id)arg1;
- (id)inspectorArea;
- (void)filterInNavigator:(id)arg1;
- (void)changeToAssistantLayout_BH:(id)arg1;
- (void)changeToAssistantLayout_BV:(id)arg1;
- (void)changeToAssistantLayout_TH:(id)arg1;
- (void)changeToAssistantLayout_TV:(id)arg1;
- (void)changeToAssistantLayout_LH:(id)arg1;
- (void)changeToAssistantLayout_LV:(id)arg1;
- (void)changeToAssistantLayout_RH:(id)arg1;
- (void)changeToAssistantLayout_RV:(id)arg1;
- (void)_changeToAssistantLayoutForActionSelector:(SEL)arg1;
- (void)changeToVersionEditorLogView:(id)arg1;
- (void)changeToVersionEditorBlameView:(id)arg1;
- (void)changeToVersionEditorComparisonView:(id)arg1;
- (void)_changeToVersionEditorSubmode:(int)arg1;
- (void)changeToVersionEditor:(id)arg1;
- (void)changeToGeniusEditor:(id)arg1;
- (void)changeToStandardEditor:(id)arg1;
- (void)_changeToEditorMode:(int)arg1;
- (void)cancelCurrentExecution:(id)arg1;
- (void)resetEditor:(id)arg1;
- (void)removeAssistantEditor:(id)arg1;
- (void)addAssistantEditor:(id)arg1;
- (void)openMediaLibrary:(id)arg1;
- (void)showMediaLibrary:(id)arg1;
- (void)openPrimaryLibrary:(id)arg1;
- (void)showPrimaryLibrary:(id)arg1;
@property(readonly) IDEWorkspaceTabController *structureEditWorkspaceTabController;
@property(readonly) IDEWorkspace *structureEditWorkspace;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (BOOL)_validateEditorLayoutUserInterfaceItem:(id)arg1 forActionSelector:(SEL)arg2;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
@property(readonly) IDEEditorArea *editorArea;
@property(readonly) IDENavigatorArea *navigatorArea;
@property(readonly) IDEWorkspaceWindowController *windowController;
- (id)splitView:(id)arg1 needsRectanglesForViewsWithState:(id)arg2 forSize:(struct CGSize)arg3;
- (void)splitView:(id)arg1 resizeSubviewsWithOldSize:(struct CGSize)arg2;
- (void)_adjustDesignAreaSplitViewWithOldSize:(struct CGSize)arg1;
- (id)_framesForDesignAreaWithNavigatorState:(int)arg1 editorAreaState:(int)arg2 inspectorAreaState:(int)arg3 forSize:(struct CGSize)arg4;
- (id)splitView:(id)arg1 additionalEffectiveRectsOfDividerAtIndex:(long long)arg2;
- (double)splitView:(id)arg1 constrainSplitPosition:(double)arg2 ofSubviewAt:(long long)arg3;
- (BOOL)splitView:(id)arg1 canCollapseSubview:(id)arg2;
- (double)splitView:(id)arg1 constrainMaxCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (double)splitView:(id)arg1 constrainMinCoordinate:(double)arg2 ofSubviewAt:(long long)arg3;
- (struct CGSize)minimumSizeForView:(id)arg1;
- (void)updateMinimumWindowSize:(BOOL)arg1;
- (struct CGSize)minimumSizeForDesignArea;
- (struct CGSize)minimumSizeForDesignAreaIfNavigatorVisible:(BOOL)arg1 editorVisisble:(BOOL)arg2 inspectorAreaVisible:(BOOL)arg3;
- (void)_removeCursorRectInterceptor:(id)arg1;
- (void)_addCursorRectInterceptor:(id)arg1;
- (void)_interceptWillInvalidateCursorRectsForViewsWithNoTrackingAreas;
- (void)_interceptWillInvalidateCursorRectsForView:(id)arg1;
- (BOOL)_interceptAddCursorRect:(struct CGRect)arg1 cursor:(id)arg2 forView:(id)arg3 inWindow:(id)arg4;
- (BOOL)_interceptSetCursorForMouseLocation:(struct CGPoint)arg1 inWindow:(id)arg2;
- (void)_openSimpleFileEditorOpenSpecifier:(id)arg1 documentLocationToShowInEditor:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)_pushDefaultPrimaryEditorFrameSize;
@property BOOL showNavigator;
@property BOOL showInspectorArea;
- (id)libraryAnchoringEditor;
- (id)workspace;
- (void)_removePendingDebuggingAdditionUIControllerObserversForLaunchSession:(id)arg1;
- (void)_notifyAndRemoveObserversForCreatedUIController:(id)arg1 inLaunchSession:(id)arg2;
- (id)debuggingAdditionUIControllerMatchingClass:(id)arg1 forLaunchSession:(id)arg2 handler:(CDUnknownBlockType)arg3;
- (id)debuggingAdditionUIControllerMatchingID:(id)arg1 forLaunchSession:(id)arg2 handler:(CDUnknownBlockType)arg3;
- (id)_createDebuggingAdditionUIControllersForDebuggingAddition:(id)arg1;
- (void)_createDebuggingAdditionUIControllersForLaunchSession:(id)arg1;
- (void)_navigateToPossiblyNonExistentURL:(id)arg1 withStackFrame:(id)arg2 withEventType:(unsigned long long)arg3 inOptionalEditor:(BOOL)arg4;
- (void)_navigateEditorToDisassemblyForStackFrame:(id)arg1 inOptionalEditor:(BOOL)arg2;
- (void)_navigateToURL:(id)arg1 withStackFrame:(id)arg2 withEventType:(unsigned long long)arg3 inOptionalEditor:(BOOL)arg4;
- (void)_navigateEditorToStackFramesSourceFile:(id)arg1 inOptionalEditor:(BOOL)arg2;
- (void)_showEditorForStackFrame:(id)arg1 inOptionalEdtor:(BOOL)arg2;
- (void)showOptionalEditorForStackFrame:(id)arg1;
- (void)showEditorForStackFrame:(id)arg1;
- (BOOL)_showDisassemblyWhenDebugging;
- (void)dismissExecutionHoldAlert;
- (void)showExecutionHoldAlertWithError:(id)arg1;
- (void)showAlertModallyInWorkspaceForError:(id)arg1;
- (void)replacementView:(id)arg1 willInstallViewController:(id)arg2;
- (void)primitiveInvalidate;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (void)_performExtraViewDidInstallWork;
- (void)commitStateToDictionary:(id)arg1;
- (void)revertStateWithDictionary:(id)arg1;
- (void)_refreshInspectorAreaVisibility;
- (void)_primitiveSetAssistantEditorsLayout:(unsigned long long)arg1;
- (void)_updateTabLabel;
- (BOOL)setUserDefinedTabLabel:(id)arg1 error:(id *)arg2;
- (void)_setup32bitOnlyMacTargetWarning;
- (void)loadView;
- (void)setSplitGroupAccessibility;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (void)setLastPrimaryLibraryID:(id)arg1;
- (id)lastPrimaryLibraryID;
- (id)findNavigator_selectedText;
- (id)findNavigator_focusedIDESourceExpressionSource;
- (id)findNavigator_focusedDVTSourceExpressionSource;
- (id)findNavigator_switchToFindNavigator;

// Remaining properties
@property(readonly) BOOL canRevertWithEmptyStateDictionary;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

