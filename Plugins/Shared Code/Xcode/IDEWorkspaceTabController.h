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

#import "DVTEditor-Protocol.h"
#import "DVTStatefulObject-Protocol.h"
#import "IDEAttachToProcessErrorHandler-Protocol.h"
#import "IDEEditorAreaContainer-Protocol.h"
#import "IDEProvisioningManagerDelegate-Protocol.h"
#import "IDEStructureEditingWorkspaceTabContext-Protocol.h"
#import "IDEWorkspaceDocumentProvider-Protocol.h"
#import "_IDEEditorModeActions-Protocol.h"

@class DVTMutableOrderedSet, DVTObservingToken, DVTTextDocumentLocation, IDEARCConversionAssistantContext, IDEAppChooserWindowController, IDEBuildAlertMonitor, IDEEditor, IDEEditorArea, IDEExecutionHoldAlertHelper, IDEFindNavigatorQueryResultsController, IDEInspectorArea, IDELaunchSession, IDENavigatorArea, IDENoticeBuildAlertMonitor, IDEObjCModernizationAssistantContext, IDERunAlertMonitor, IDESwiftMigrationAssistantContext, IDEWorkspace, IDEWorkspaceDesignAreaSplitViewController, IDEWorkspaceDocument, IDEWorkspaceWindowController, NSAlert, NSArray, NSMapTable, NSMutableArray, NSSplitViewItem, NSString, _TtC6IDEKit29IDEFindResultExplorableSource;
@protocol DVTInvalidation;

@interface IDEWorkspaceTabController : IDEViewController <NSTextViewDelegate, _IDEEditorModeActions, DVTStatefulObject, IDEEditorAreaContainer, IDEStructureEditingWorkspaceTabContext, IDEWorkspaceDocumentProvider, DVTEditor, IDEProvisioningManagerDelegate, IDEAttachToProcessErrorHandler>
{
    DVTMutableOrderedSet *_cursorRectInterceptors;
    NSMapTable *_additionControllersForLaunchSessionTable;
    NSMapTable *_notificationTokenForLaunchSessionTable;
    NSMapTable *_observerTokenForLaunchSessionsDebuggingAdditionsTable;
    NSMutableArray *_uiControllerObserverEntries;
    DVTObservingToken *_mainCurrentLaunchSessionObserverToken;
    DVTObservingToken *_currentLaunchSessionStateObserverToken;
    DVTObservingToken *_launchSessionAlertErrorObservingToken;
    DVTObservingToken *_debugSessionObserverToken;
    DVTObservingToken *_debugSessionCoalescedStateObservingToken;
    DVTObservingToken *_currentStackFrameDisassemblyObservingToken;
    NSAlert *_stoppingExecutionAlert;
    id _pendingExecutionNotificationToken;
    CDUnknownBlockType _pendingEnqueuingCompletionBlock;
    IDERunAlertMonitor *_runAlertMonitor;
    IDEARCConversionAssistantContext *_conversionAssistantContext;
    IDEObjCModernizationAssistantContext *_objcModernizationAssistantContext;
    IDESwiftMigrationAssistantContext *_swiftMigrationAssistantContext;
    id <DVTInvalidation> _libraryInstallationToken;
    BOOL _isOpeningSimpleFileEditorOpenSpecifier;
    BOOL _isNavigatorVisible;
    BOOL _isIssuesNavigatorVisible;
    BOOL _isNoticeNavigatorVisible;
    BOOL _isInspectorAreaVisible;
    BOOL _completedInitialStateRestore;
    BOOL _tabLoadingCompleted;
    IDEWorkspaceDocument *_workspaceDocument;
    NSString *_userDefinedTabLabel;
    IDELaunchSession *_currentLaunchSession;
    IDEWorkspaceDesignAreaSplitViewController *_designAreaSplitViewController;
    IDENavigatorArea *_navigatorArea;
    IDEEditorArea *_editorArea;
    IDEInspectorArea *_inspectorArea;
    IDEFindNavigatorQueryResultsController *_findNavigatorQueryResultsController;
    _TtC6IDEKit29IDEFindResultExplorableSource *_findResultExplorableSource;
    DVTTextDocumentLocation *_issueInstructionPointerLocation;
    DVTTextDocumentLocation *_issueInstructionPointerLocationForDisassembly;
    NSSplitViewItem *_navigatorAreaSplitViewItem;
    NSSplitViewItem *_editorAreaSplitViewItem;
    NSSplitViewItem *_inspectorAreaSplitViewItem;
    DVTObservingToken *_documentLoadingObservationToken;
    DVTObservingToken *_firstIssueObservationToken;
    DVTObservingToken *_buildCompleteObservationToken;
    IDEAppChooserWindowController *_appChooserWindowController;
    IDEExecutionHoldAlertHelper *_executionHoldAlertHelper;
    IDEBuildAlertMonitor *_buildAlertMonitor;
    IDENoticeBuildAlertMonitor *_noticeBuildAlertMonitor;
    unsigned long long _assistantEditorsLayout;
    NSString *_tabLabel;
    NSString *_name;
    NSString *_stateSavingIdentifier;
}

+ (void)initialize;
+ (void)_recordMetricsForBuildPlatformsFromOperationParameters:(id)arg1;
+ (id)keyPathsForValuesAffectingIsInspectorAreaVisible;
+ (id)keyPathsForValuesAffectingIsNavigatorVisible;
+ (id)keyPathsForValuesAffectingWindowController;
+ (id)keyPathsForValuesAffectingLibraryAnchoringEditor;
+ (id)keyPathsForValuesAffectingWorkspace;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (long long)version;
+ (void)configureStateSavingObjectPersistenceByName:(id)arg1;
// - (void).cxx_destruct;
@property(copy) NSString *stateSavingIdentifier; // @synthesize stateSavingIdentifier=_stateSavingIdentifier;
@property(copy) NSString *name; // @synthesize name=_name;
@property(copy) NSString *tabLabel; // @synthesize tabLabel=_tabLabel;
@property(nonatomic) BOOL tabLoadingCompleted; // @synthesize tabLoadingCompleted=_tabLoadingCompleted;
@property(nonatomic) unsigned long long assistantEditorsLayout; // @synthesize assistantEditorsLayout=_assistantEditorsLayout;
@property(retain) IDENoticeBuildAlertMonitor *noticeBuildAlertMonitor; // @synthesize noticeBuildAlertMonitor=_noticeBuildAlertMonitor;
@property(retain) IDEBuildAlertMonitor *buildAlertMonitor; // @synthesize buildAlertMonitor=_buildAlertMonitor;
@property(retain) IDEExecutionHoldAlertHelper *executionHoldAlertHelper; // @synthesize executionHoldAlertHelper=_executionHoldAlertHelper;
@property(retain) IDEAppChooserWindowController *appChooserWindowController; // @synthesize appChooserWindowController=_appChooserWindowController;
@property(retain) DVTObservingToken *buildCompleteObservationToken; // @synthesize buildCompleteObservationToken=_buildCompleteObservationToken;
@property(retain) DVTObservingToken *firstIssueObservationToken; // @synthesize firstIssueObservationToken=_firstIssueObservationToken;
@property(retain) DVTObservingToken *documentLoadingObservationToken; // @synthesize documentLoadingObservationToken=_documentLoadingObservationToken;
@property BOOL completedInitialStateRestore; // @synthesize completedInitialStateRestore=_completedInitialStateRestore;
@property(retain) NSSplitViewItem *inspectorAreaSplitViewItem; // @synthesize inspectorAreaSplitViewItem=_inspectorAreaSplitViewItem;
@property(retain) NSSplitViewItem *editorAreaSplitViewItem; // @synthesize editorAreaSplitViewItem=_editorAreaSplitViewItem;
@property(retain) NSSplitViewItem *navigatorAreaSplitViewItem; // @synthesize navigatorAreaSplitViewItem=_navigatorAreaSplitViewItem;
@property(nonatomic) BOOL isInspectorAreaVisible; // @synthesize isInspectorAreaVisible=_isInspectorAreaVisible;
@property(nonatomic) BOOL isNoticeNavigatorVisible; // @synthesize isNoticeNavigatorVisible=_isNoticeNavigatorVisible;
@property(nonatomic) BOOL isIssuesNavigatorVisible; // @synthesize isIssuesNavigatorVisible=_isIssuesNavigatorVisible;
@property(nonatomic) BOOL isNavigatorVisible; // @synthesize isNavigatorVisible=_isNavigatorVisible;
@property(retain) DVTTextDocumentLocation *issueInstructionPointerLocationForDisassembly; // @synthesize issueInstructionPointerLocationForDisassembly=_issueInstructionPointerLocationForDisassembly;
@property(retain) DVTTextDocumentLocation *issueInstructionPointerLocation; // @synthesize issueInstructionPointerLocation=_issueInstructionPointerLocation;
@property(retain, nonatomic) _TtC6IDEKit29IDEFindResultExplorableSource *findResultExplorableSource; // @synthesize findResultExplorableSource=_findResultExplorableSource;
@property(retain, nonatomic) IDEFindNavigatorQueryResultsController *findNavigatorQueryResultsController; // @synthesize findNavigatorQueryResultsController=_findNavigatorQueryResultsController;
@property(retain) IDEInspectorArea *inspectorArea; // @synthesize inspectorArea=_inspectorArea;
@property(retain) IDEEditorArea *editorArea; // @synthesize editorArea=_editorArea;
@property(retain) IDENavigatorArea *navigatorArea; // @synthesize navigatorArea=_navigatorArea;
@property(retain) IDEWorkspaceDesignAreaSplitViewController *designAreaSplitViewController; // @synthesize designAreaSplitViewController=_designAreaSplitViewController;
@property(retain, nonatomic) IDELaunchSession *currentLaunchSession; // @synthesize currentLaunchSession=_currentLaunchSession;
@property(copy) NSString *userDefinedTabLabel; // @synthesize userDefinedTabLabel=_userDefinedTabLabel;
@property(retain) IDEWorkspaceDocument *workspaceDocument; // @synthesize workspaceDocument=_workspaceDocument;
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
- (void)showTestPlanConversionSheet:(id)arg1;
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
- (void)simulateVehicularCrash:(id)arg1;
- (void)uiSnapshotRefresh:(id)arg1;
- (void)simulateMetricPayloads:(id)arg1;
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
- (void)deleteAllBreakpoints:(id)arg1;
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
- (void)editBuildAndArchiveActiveRunContext:(id)arg1;
- (void)_doCommandForEditAndSchemeCommand:(id)arg1;
- (void)_doCommandForEditAndSchemeCommand:(id)arg1 schemeTask:(long long)arg2;
- (void)showAppChooserIfNecessaryForScheme:(id)arg1 runDestination:(id)arg2 command:(id)arg3 onCompletion:(CDUnknownBlockType)arg4;
- (id)_extensionPathRunnableForBundleIdentifier:(id)arg1 BuildableProduct:(id)arg2 Scheme:(id)arg3 extensionRunMode:(int)arg4;
- (id)_extensionRunnableForBundleIdentifier:(id)arg1 BuildableProduct:(id)arg2 Scheme:(id)arg3 extensionRunMode:(int)arg4;
- (BOOL)_shouldShowAppChooserForScheme:(id)arg1 command:(id)arg2;
- (void)_showAppChooserForCurrentSchemeIfNecessaryForCommand:(id)arg1 launch:(CDUnknownBlockType)arg2;
- (id)_generateErrorForScheme:(id)arg1;
- (void)showModalAlertForScheme:(id)arg1;
- (void)showPackagePluginActivationAlertForPluginNamed:(id)arg1 isUnknown:(BOOL)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)showBuildToolPluginFingerprintsAlertForScheme:(id)arg1 schemeTask:(long long)arg2 schemeCommand:(id)arg3 runDestination:(id)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (void)runWithoutBuildingForSchemeIdentifier:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (void)generateRemarksForFileAtPath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)compileFileAtPath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)analyzeFileAtPath:(id)arg1;
- (void)generateAssemblyCodeForFilePath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)generatePreprocessedFileForFilePath:(id)arg1 forSchemeCommand:(id)arg2;
- (void)clearAllIssues:(id)arg1;
- (void)cleanTestResults:(id)arg1;
- (void)cleanBuildFolder:(id)arg1;
- (void)reallyCleanBuildFolder;
- (void)_reallyCleanWithInvocationRecord:(id)arg1 invokedViaScripting:(BOOL)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)cleanActiveRunContext:(id)arg1;
- (id)_buildFolderToRevealReturningRevealCommandDisplayTitle:(out id *)arg1;
- (void)revealBuildFolder:(id)arg1;
- (void)buildAndRunToGenerateOptimizationProfileActiveRunContext:(id)arg1;
- (void)buildForInstallActiveRunContext:(id)arg1;
- (void)buildAndArchiveActiveRunContext:(id)arg1;
- (void)buildActiveRunContextWithTimingSummary:(id)arg1;
- (void)buildActiveRunContext:(id)arg1;
- (void)installActiveRunContext:(id)arg1;
- (void)editAndAnalyzeActiveRunContext:(id)arg1;
- (void)analyzeActiveRunContext:(id)arg1;
- (void)profileUsingActiveRunContextWithOverridingTestingSpecifierGroups:(id)arg1;
- (void)buildForProfileActiveScheme:(id)arg1;
- (void)editAndBuildForProfilingActiveScheme:(id)arg1;
- (void)editAndProfileActiveScheme:(id)arg1;
- (void)profileActiveSchemeWithoutBuilding:(id)arg1;
- (void)profileActiveScheme:(id)arg1;
- (void)testUsingActiveRunContextWithOverridingTestingSpecifierGroups:(id)arg1 testRepetitionPolicy:(id)arg2 schemeTask:(long long)arg3 contextString:(id)arg4 testingCompleteBlock:(CDUnknownBlockType)arg5;
- (void)_testActiveRunContextFromScripting:(BOOL)arg1 schemeTask:(long long)arg2 withInvocationRecord:(id)arg3 additionalCommandLineArgs:(id)arg4 overridingEnvironmentVars:(id)arg5 contextString:(id)arg6 completionBlock:(CDUnknownBlockType)arg7;
- (void)_testActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 additionalCommandLineArgs:(id)arg3 overridingEnvironmentVars:(id)arg4 contextString:(id)arg5 completionBlock:(CDUnknownBlockType)arg6;
- (void)testActiveRunContextWithContextString:(id)arg1 schemeTask:(long long)arg2;
- (void)testActiveRunContextWithContextString:(id)arg1;
- (void)buildForTestActiveRunContext:(id)arg1 testProductsPath:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)buildForTestActiveRunContext:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)buildForTestActiveRunContext:(id)arg1;
- (void)editAndBuildForTestingActiveRunContext:(id)arg1;
- (void)editAndTestActiveRunContext:(id)arg1;
- (void)testActiveRunContextWithoutBuilding:(id)arg1;
- (void)testActiveRunContext:(id)arg1;
- (void)_runWithoutBuildingForScheme:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (void)_buildForRunActiveRunContextFromScripting:(BOOL)arg1 withInvocationRecord:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)buildForRunActiveRunContext:(id)arg1;
- (void)editAndBuildForRunningActiveRunContext:(id)arg1;
- (void)editAndRunActiveRunContext:(id)arg1;
- (void)runActiveRunContextWithoutBuilding:(id)arg1;
- (void)_alertNonExistentWorkingDirectoryBeforeRunOrProfileForContext:(id)arg1 workingDirectory:(id)arg2 title:(id)arg3 defaultButton:(id)arg4 usingBlock:(CDUnknownBlockType)arg5 errorBlock:(CDUnknownBlockType)arg6;
- (void)_alertNonExistentWorkingDirectoryBeforeProfileForContext:(id)arg1 usingBlock:(CDUnknownBlockType)arg2 errorBlock:(CDUnknownBlockType)arg3;
- (void)_alertNonExistentWorkingDirectoryBeforeRunForContext:(id)arg1 usingBlock:(CDUnknownBlockType)arg2 errorBlock:(CDUnknownBlockType)arg3;
- (void)_askShouldBuildBeforeRunProfileForContext:(id)arg1 title:(id)arg2 defaultButton:(id)arg3 usingBlock:(CDUnknownBlockType)arg4;
- (void)_runSchemeName:(id)arg1 fromScripting:(BOOL)arg2 skipBuilding:(BOOL)arg3 invocationRecord:(id)arg4 runDestinationSpecifier:(id)arg5 additionalCommandLineArgs:(id)arg6 overridingEnvironmentVars:(id)arg7 completionBlock:(CDUnknownBlockType)arg8;
- (void)buildDocumentationForActiveRunContext:(id)arg1;
- (void)localizationImport:(id)arg1;
- (void)localizationExport:(id)arg1;
- (void)performLocalizationAction:(id)arg1;
- (void)runActiveRunContext:(id)arg1;
- (void)_runScheme:(id)arg1 runDestination:(id)arg2 invocationRecord:(id)arg3;
- (BOOL)_needToSwitchSchemeActionToLLDB:(id)arg1;
- (void)_silentlySwitchToLLDBIfNecessary:(id)arg1;
- (void)_performDebuggableTaskOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 invokedViaScripting:(BOOL)arg3 completionBlock:(CDUnknownBlockType)arg4;
- (BOOL)_validateDeviceForDaemonDebuggingOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2;
- (BOOL)_validToolchainForSchemeAction:(id)arg1 schemeCommand:(id)arg2;
- (id)_runtimeLLDBFilePath;
- (void)_debugSessionCoalescedStateChanged:(id)arg1 forDebugSession:(id)arg2;
@property(readonly) BOOL isActiveWorkspaceTabController;
- (id)debuggingAdditionUIControllersForLaunchSession:(id)arg1;
@property(readonly) NSArray *currentDebuggingAdditionUIControllers;
- (id)debugSessionController;
- (BOOL)_contentSizeCanBeZeroSize;
- (void)_performContextTask:(long long)arg1 command:(id)arg2 commandName:(id)arg3 buildCommand:(long long)arg4 runDestination:(id)arg5 filePath:(id)arg6 invocationRecord:(id)arg7 useLegacyCompletionBehavior:(BOOL)arg8 completionBlock:(CDUnknownBlockType)arg9;
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
- (id)_errorForEmbeddedWatchContentMissingPlatformWithScheme:(id)arg1 operationParameters:(id)arg2 underlyingError:(id)arg3;
- (id)_errorForMissingInstallablePlatformWithScheme:(id)arg1 operationParameters:(id)arg2 underlyingError:(id)arg3;
- (id)_missingPlatformAlertMesageForPlatformNameAndVersion:(id)arg1 shouldPresentDownloadOption:(BOOL)arg2;
- (id)_errorForInvalidActionForScheme:(id)arg1 operationParameters:(id)arg2;
- (CDUnknownBlockType)_deviceAvailableCheckerOnScheme:(id)arg1 forSchemeOperationParameters:(id)arg2 enqueuingErrorBlock:(CDUnknownBlockType)arg3;
- (void)invalidateAllBuildAlertMonitorsForWorkspace;
- (BOOL)_cleanBuildFolderWithError:(id *)arg1;
- (void)observeBuildOperationForRestoringState:(id)arg1;
- (void)switchNavigatorOnBuild;
- (void)hideInspectorAreaAnimated:(BOOL)arg1;
- (void)showInspectorAreaAnimated:(BOOL)arg1;
- (void)toggleInspectorArea:(id)arg1;
- (void)setInspectorAreaVisible:(BOOL)arg1 animated:(BOOL)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)hideNavigatorAnimated:(BOOL)arg1;
- (void)showNavigatorAnimated:(BOOL)arg1;
- (void)toggleNavigator:(id)arg1;
- (void)_setNavigatorVisible:(BOOL)arg1 animated:(BOOL)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)_setVisible:(BOOL)arg1 ofSplitViewItem:(id)arg2 animated:(BOOL)arg3 completionBlock:(CDUnknownBlockType)arg4;
- (void)setShowNavigator:(BOOL)arg1;
- (void)showNavigatorWithIdentifier:(id)arg1;
- (void)changeToBreakpointsNavigator:(id)arg1;
- (void)changeToDebuggerNavigator:(id)arg1;
- (void)changeToRepositoriesNavigator:(id)arg1;
- (void)changeToChangesNavigator:(id)arg1;
- (void)changeToWorkingCopiesNavigator:(id)arg1;
- (void)changeToFindNavigator:(id)arg1;
- (void)changeToTestNavigator:(id)arg1;
- (void)changeToNoticeNavigatorAndFilterNoticesWithNoticeSeverities:(id)arg1 noticeKinds:(id)arg2;
- (void)changeToNoticeNavigatorAndSelectWrappedNotice:(id)arg1;
- (void)changeToNoticeNavigator;
- (void)_changeToIssuesNavigatorForBuildIssues;
- (void)changeToIssuesNavigatorAndShowRuntime:(BOOL)arg1 clearFilterType:(unsigned long long)arg2 openNavigatorArea:(BOOL)arg3;
- (void)changeToIssuesNavigator:(id)arg1 showRuntime:(BOOL)arg2 clearFilterType:(unsigned long long)arg3;
- (void)changeToIssuesNavigator:(id)arg1;
- (void)changeToLogsNavigator:(id)arg1;
- (void)changeToSymbolsNavigator:(id)arg1;
- (void)revealInBreakpointNavigator:(id)arg1 showEditor:(BOOL)arg2;
- (void)revealSelectionInProjectNavigator:(id)arg1;
- (void)changeToStructureNavigator:(id)arg1;
- (void)chooseNewFirstResponderIfNecessary;
- (void)showInspectorWithChoiceFromSender:(id)arg1;
- (void)showInspectorCategoryWithExtensionIdentifier:(id)arg1;
- (void)showInspectorWithChoice:(id)arg1;
- (void)filterInNavigator:(id)arg1;
- (void)_toggleIndexBuildLog:(id)arg1;
- (void)_toggleShowCodeReviewForEditor:(id)arg1;
- (void)_setSubEditorPositionToBelow:(id)arg1;
- (void)_setSubEditorPositionToOnRight:(id)arg1;
- (void)_setSubEditorPositionToAutomatic:(id)arg1;
- (void)_toggleMaximizeEditor:(id)arg1;
- (void)_toggleShowAssistantMode:(id)arg1;
- (void)_toggleShowPreviewMode:(id)arg1;
- (void)_showPreviewMode:(id)arg1;
- (void)_showAssistantMode:(id)arg1;
- (void)_showEditorOnly:(id)arg1;
- (void)changeToGeniusEditor:(id)arg1;
- (void)changeToAuxiliaryEditor:(id)arg1;
- (void)changeToStandardEditor:(id)arg1;
- (void)cancelCurrentExecution:(id)arg1;
- (void)closeOtherEditors:(id)arg1;
- (void)resetEditorSizes:(id)arg1;
- (void)resetAssistantEditorSelection:(id)arg1;
- (void)_closeOtherEditorTabs:(id)arg1;
- (void)dvt_closeActiveEditorTab:(id)arg1;
- (void)_closeActiveEditor:(id)arg1;
- (void)tabController_newEditorAreaSplitAlternate:(id)arg1;
- (void)tabController_newEditorAreaSplit:(id)arg1;
- (void)openLibrary:(id)arg1;
- (void)showLibrary:(id)arg1;
- (void)toggleLibraryFromButton:(id)arg1;
- (void)toggleComparisonModeFromToolbar:(id)arg1;
@property(readonly) IDEWorkspaceTabController *structureEditWorkspaceTabController;
@property(readonly) IDEWorkspace *structureEditWorkspace;
- (BOOL)shouldEnableLocalizationActions;
- (BOOL)validateUserInterfaceItem:(id)arg1;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
@property(readonly) IDEWorkspaceWindowController *windowController;
- (struct CGSize)minimumSizeForView:(id)arg1;
- (void)updateMinimumWindowSize:(BOOL)arg1;
@property(readonly) struct CGSize minimumSizeForDesignArea;
- (struct CGSize)minimumSizeForDesignAreaIfNavigatorVisible:(BOOL)arg1 editorVisisble:(BOOL)arg2 inspectorAreaVisible:(BOOL)arg3;
- (void)_removeCursorRectInterceptor:(id)arg1;
- (void)_addCursorRectInterceptor:(id)arg1;
- (void)_interceptWillInvalidateCursorRectsForViewsWithNoTrackingAreas;
- (void)_interceptWillInvalidateCursorRectsForView:(id)arg1;
- (BOOL)_interceptAddCursorRect:(struct CGRect)arg1 cursor:(id)arg2 forView:(id)arg3 inWindow:(id)arg4;
- (BOOL)_interceptSetCursorForMouseLocation:(struct CGPoint)arg1 inWindow:(id)arg2;
- (void)_openSimpleFileEditorOpenSpecifier:(id)arg1 documentLocationToShowInEditor:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)_pushDefaultPrimaryEditorFrameSize;
@property(readonly) IDEEditor *libraryAnchoringEditor;
- (id)workspace;
- (id)observeDebugSessionStateWithInitialCallback:(BOOL)arg1 handler:(CDUnknownBlockType)arg2;
- (void)_removePendingDebuggingAdditionUIControllerObserversForLaunchSession:(id)arg1;
- (void)_notifyAndRemoveObserversForCreatedUIController:(id)arg1 inLaunchSession:(id)arg2;
- (id)debuggingAdditionUIControllerMatchingClass:(id)arg1 forLaunchSession:(id)arg2 handler:(CDUnknownBlockType)arg3;
- (id)debuggingAdditionUIControllerMatchingID:(id)arg1 forLaunchSession:(id)arg2 handler:(CDUnknownBlockType)arg3;
- (id)_createDebuggingAdditionUIControllersForDebuggingAddition:(id)arg1;
- (void)_createDebuggingAdditionUIControllersForLaunchSession:(id)arg1;
- (void)_navigateToPossiblyNonExistentURL:(id)arg1 withStackFrame:(id)arg2 withEventType:(unsigned long long)arg3;
- (void)_navigateEditorToDisassemblyForStackFrame:(id)arg1;
- (void)_navigateToURL:(id)arg1 withStackFrame:(id)arg2 withEventType:(unsigned long long)arg3;
- (void)_navigateEditorToStackFramesSourceFile:(id)arg1;
- (void)_showEditorForStackFrame:(id)arg1;
- (void)showOptionalEditorForStackFrame:(id)arg1;
- (void)showEditorForStackFrame:(id)arg1;
- (BOOL)_showDisassemblyWhenDebugging;
- (void)dismissExecutionHoldAlert;
- (void)showExecutionHoldAlertWithError:(id)arg1;
- (void)showAlertModallyInWorkspaceForError:(id)arg1;
- (void)primitiveInvalidate;
- (void)viewWillUninstall;
- (void)viewDidInstall;
- (void)_performExtraViewDidInstallWork;
- (void)commitStateToDictionary:(id)arg1;
- (void)revertStateWithDictionary:(id)arg1;
- (void)_updateTabLabel;
- (BOOL)setUserDefinedTabLabel:(id)arg1 error:(id *)arg2;
- (void)showStandardArchitecturesAlertForScheme:(id)arg1 schemeTask:(long long)arg2 schemeCommand:(id)arg3 runDestination:(id)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (void)_setup32bitOnlyMacTargetWarning;
- (void)loadView;
- (void)_setDefaultSplitViewItemWidths;
- (void)_setSplitGroupAccessibility;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (void)setLastApplicableLibraryExtensionIDs:(id)arg1;
- (id)lastApplicableLibraryExtensionIDs;
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

