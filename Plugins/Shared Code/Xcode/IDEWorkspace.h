//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEXMLPackageContainer.h"

#import "IDEBuildNoticeWorkspace-Protocol.h"
#import "IDEClientTracking-Protocol.h"
#import "IDEIssueLogDataSource-Protocol.h"
#import "IDEProvisionableProvider-Protocol.h"
#import "IDETestableDataSource_IndexProvider-Protocol.h"
#import "_TtP13IDEFoundation32IDESchemeFileReference_Workspace_-Protocol.h"

@class DVTFilePath, DVTNotificationToken, DVTObservingToken, DVTStackBacktrace, IDEActivityLogMessage, IDEActivityLogSection, IDEBreakpointManager, IDEConcreteClientTracker, IDEContainer, IDEContainerQuery, IDEDeviceInstallWorkspaceMonitor, IDEDynamicContentRootGroup, IDEExecutionEnvironment, IDEIndex, IDEIssueManager, IDELocalizationManager, IDELocalizationWorkspaceMonitor, IDELogManager, IDEProvisioningManager, IDEProvisioningWorkspaceMonitor, IDERefactoring, IDERunContextManager, IDESourceControlWorkspaceMonitor, IDETestManager, IDETextFragmentIndex, IDEWorkspaceArena, IDEWorkspaceNoticeSubsystem, IDEWorkspaceSharedSettings, IDEWorkspaceUpgradeTasksController, IDEWorkspaceUserSettings, NSArray, NSDate, NSDictionary, NSHashTable, NSMapTable, NSMutableArray, NSMutableDictionary, NSMutableOrderedSet, NSMutableSet, NSNumber, NSSet, NSString, _TtC13IDEFoundation30IDEStructureEditingCoordinator, _TtC16DVTDocumentation23DVTDocumentationManager;
@protocol IDEActiveRunContextStoring, IDEBlueprintProvider, IDEBuildNoticeLogSection, IDEBuildSystemService, IDECustomDataStoring, IDEPackageManagerWorkspace, IDEWorkspaceDelegate;

@interface IDEWorkspace : IDEXMLPackageContainer <IDETestableDataSource_IndexProvider, IDEBuildNoticeWorkspace, _TtP13IDEFoundation32IDESchemeFileReference_Workspace_, IDEClientTracking, IDEProvisionableProvider, IDEIssueLogDataSource>
{
    NSString *_untitledName;
    IDEWorkspaceArena *_workspaceArena;
    DVTFilePath *_headerMapFilePath;
    IDEExecutionEnvironment *_executionEnvironment;
    IDEContainerQuery *_containerQuery;
    DVTObservingToken *_containerQueryObservingToken;
    NSMutableSet *_referencedContainers;
    NSHashTable *_fileRefsWithContainerLoadingIssues;
    IDEActivityLogSection *_containerLoadingIntegrityLog;
    NSMutableSet *_customDataStores;
    IDEWorkspaceUserSettings *_userSettings;
    IDEWorkspaceSharedSettings *_sharedSettings;
    NSMapTable *_blueprintProviderObserverMap;
    NSMapTable *_blueprintProviderEditedObserverMap;
    NSMutableSet *_referencedBlueprints;
    NSDictionary *_uniqueIdentifiersToReferencedBlueprints;
    BOOL _initialContainerScanComplete;
    NSMutableArray *_referencedRunnableBuildableProducts;
    IDERunContextManager *_runContextManager;
    IDELogManager *_logManager;
    IDEIssueManager *_issueManager;
    IDEBreakpointManager *_breakpointManager;
    IDETestManager *_testManager;
    _TtC16DVTDocumentation23DVTDocumentationManager *_documentationManager;
    IDEContainerQuery *_indexableSourceQuery;
    DVTObservingToken *_indexableSourceQueryObservingToken;
    NSMapTable *_observedIndexableSourcesToObservingTokensTable;
    IDEIndex *_index;
    NSMutableDictionary *_identifiersToIndexablesPendingRegistration;
    IDEDeviceInstallWorkspaceMonitor *_deviceInstallWorkspaceMonitor;
    IDEProvisioningWorkspaceMonitor *_provisioningWorkspaceMonitor;
    IDESourceControlWorkspaceMonitor *_sourceControlWorkspaceMonitor;
    IDELocalizationWorkspaceMonitor *_localizationWorkspaceMonitor;
    IDEProvisioningManager *_provisioningManager;
    IDELocalizationManager *_localizationManager;
    _TtC13IDEFoundation30IDEStructureEditingCoordinator *_structureEditingMoveCoordinator;
    NSNumber *_shouldUseLegacyBuildSystem;
    id <IDEBuildSystemService> _buildSystemService;
    DVTNotificationToken *_buildSystemSettingsNotificationToken;
    DVTFilePath *_wrappedContainerPath;
    IDEContainer<IDECustomDataStoring> *_wrappedContainer;
    DVTObservingToken *_wrappedContainerValidObservingToken;
    DVTObservingToken *_newWrappedContainerObservingToken;
    NSHashTable *_pendingReferencedFileReferences;
    NSHashTable *_pendingReferencedContainers;
    DVTNotificationToken *_holdFilesOnAppActivationNotificationToken;
    IDEConcreteClientTracker *_clientTracker;
    NSHashTable *_fileReferencesForProblem8727051;
    DVTObservingToken *_finishedLoadingObservingToken;
    NSDictionary *_Problem9887530_preferredStructurePaths;
    BOOL _simpleFilesFocused;
    id _openingPerformanceMetricIdentifier;
    DVTStackBacktrace *_finishedLoadingBacktrace;
    NSMutableOrderedSet *_initialOrderedReferencedBlueprintProviders;
    BOOL _hasPostedIndexingRegistrationBatchNotification;
    BOOL _didFinishLoadingFirstStage;
    BOOL _finishedLoading;
    BOOL _postLoadingPerformanceMetricsAllowed;
    BOOL _willInvalidate;
    BOOL _pendingFileReferencesAndContainers;
    BOOL _didProcessFileReferencesForProblem8727051;
    BOOL _isCleaningBuildFolder;
    BOOL _indexingAndRefactoringRestartScheduled;
    BOOL _indexCreationInFlight;
    BOOL _didFinishBuildingInitialBlueprintProviderOrderedSet;
    NSMapTable *_pendingExecutionNotificationTokens;
    BOOL _isWaitingForSourcePackages;
    BOOL _wasLoadedForUIContext;
    BOOL _hostsOnlyWrappedContainer;
    BOOL _hostsOnlyXcode3Project;
    BOOL _hostsOnlyPackages;
    BOOL _hostsOnlyPlaygroundProject;
    BOOL _hostsOnlyPlayground;
    BOOL _isPotentiallyClosing;
    IDEDynamicContentRootGroup *_dynamicContentRootGroup;
    NSArray *_sourcePackageLoadingErrors;
    IDEActivityLogSection *_sourcePackageResolutionIssueLog;
    id <IDEPackageManagerWorkspace> _packageManager;
    IDEWorkspaceNoticeSubsystem *_noticeSubsystem;
    IDETextFragmentIndex *_textFragmentIndex;
    IDERefactoring *_refactoring;
    NSString *_xcbuildSandboxProfile;
    IDEWorkspaceUpgradeTasksController *_deferredUpgradeTasksController;
    NSDate *_icloudDriveLastHeldDate;
    id <IDEActiveRunContextStoring> _activeRunContextStore;
}

+ (id)keyPathsForValuesAffectingProvisionableDevices;
+ (id)keyPathsForValuesAffectingProvisionables;
+ (BOOL)_shouldTrackReadOnlyStatus;
+ (id)keyPathsForValuesAffectingRepresentingCustomDataStore;
+ (id)keyPathsForValuesAffectingHostsOnlyPlayground;
+ (id)keyPathsForValuesAffectingHostsOnlyXcode3Project;
+ (id)keyPathsForValuesAffectingRepresentingTitle;
+ (id)keyPathsForValuesAffectingRepresentingFilePath;
+ (id)keyPathsForValuesAffectingName;
+ (id)keyPathsForValuesAffectingReferencedRemoteSourcePackages;
+ (id)keyPathsForValuesAffectingReferencedSourcePackages;
+ (id)keyPathsForValuesAffectingContainsPackageReferences;
+ (id)_workspaceFileExtension;
+ (id)containerTypeDisplayName;
+ (id)containerFileDataType;
+ (id)xmlArchiveFileName;
+ (id)rootElementName;
+ (BOOL)automaticallyNotifiesObserversOfFileRefsWithContainerLoadingIssues;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (void)initialize;
+ (id)globalScopeStore;
+ (id)createGlobalScopeStore;
// - (void).cxx_destruct;
@property(retain) id <IDEActiveRunContextStoring> activeRunContextStore; // @synthesize activeRunContextStore=_activeRunContextStore;
@property(nonatomic) BOOL isPotentiallyClosing; // @synthesize isPotentiallyClosing=_isPotentiallyClosing;
@property(copy) NSDate *icloudDriveLastHeldDate; // @synthesize icloudDriveLastHeldDate=_icloudDriveLastHeldDate;
@property(retain) IDEWorkspaceUpgradeTasksController *deferredUpgradeTasksController; // @synthesize deferredUpgradeTasksController=_deferredUpgradeTasksController;
@property(retain, nonatomic) IDEWorkspaceSharedSettings *sharedSettings; // @synthesize sharedSettings=_sharedSettings;
@property(retain, nonatomic) IDEWorkspaceUserSettings *userSettings; // @synthesize userSettings=_userSettings;
@property(nonatomic) BOOL pendingFileReferencesAndContainers; // @synthesize pendingFileReferencesAndContainers=_pendingFileReferencesAndContainers;
@property(retain, nonatomic) IDEWorkspaceArena *workspaceArena; // @synthesize workspaceArena=_workspaceArena;
@property BOOL isCleaningBuildFolder; // @synthesize isCleaningBuildFolder=_isCleaningBuildFolder;
@property BOOL hostsOnlyPlayground; // @synthesize hostsOnlyPlayground=_hostsOnlyPlayground;
@property BOOL hostsOnlyPlaygroundProject; // @synthesize hostsOnlyPlaygroundProject=_hostsOnlyPlaygroundProject;
@property BOOL hostsOnlyPackages; // @synthesize hostsOnlyPackages=_hostsOnlyPackages;
@property BOOL hostsOnlyXcode3Project; // @synthesize hostsOnlyXcode3Project=_hostsOnlyXcode3Project;
@property BOOL hostsOnlyWrappedContainer; // @synthesize hostsOnlyWrappedContainer=_hostsOnlyWrappedContainer;
@property(readonly) DVTFilePath *wrappedContainerPath; // @synthesize wrappedContainerPath=_wrappedContainerPath;
@property(readonly, nonatomic) BOOL postLoadingPerformanceMetricsAllowed; // @synthesize postLoadingPerformanceMetricsAllowed=_postLoadingPerformanceMetricsAllowed;
@property(nonatomic) BOOL finishedLoading; // @synthesize finishedLoading=_finishedLoading;
@property(retain, nonatomic) NSString *xcbuildSandboxProfile; // @synthesize xcbuildSandboxProfile=_xcbuildSandboxProfile;
@property(nonatomic) BOOL wasLoadedForUIContext; // @synthesize wasLoadedForUIContext=_wasLoadedForUIContext;
@property(retain, nonatomic) IDEProvisioningManager *provisioningManager; // @synthesize provisioningManager=_provisioningManager;
@property(retain) IDELocalizationWorkspaceMonitor *localizationWorkspaceMonitor; // @synthesize localizationWorkspaceMonitor=_localizationWorkspaceMonitor;
@property(retain) IDESourceControlWorkspaceMonitor *sourceControlWorkspaceMonitor; // @synthesize sourceControlWorkspaceMonitor=_sourceControlWorkspaceMonitor;
@property(retain) IDEProvisioningWorkspaceMonitor *provisioningWorkspaceMonitor; // @synthesize provisioningWorkspaceMonitor=_provisioningWorkspaceMonitor;
@property(retain) IDEDeviceInstallWorkspaceMonitor *deviceInstallWorkspaceMonitor; // @synthesize deviceInstallWorkspaceMonitor=_deviceInstallWorkspaceMonitor;
@property(readonly) IDERefactoring *refactoring; // @synthesize refactoring=_refactoring;
@property(readonly) IDETextFragmentIndex *textFragmentIndex; // @synthesize textFragmentIndex=_textFragmentIndex;
@property(retain) IDEIndex *index; // @synthesize index=_index;
@property(readonly) IDEWorkspaceNoticeSubsystem *noticeSubsystem; // @synthesize noticeSubsystem=_noticeSubsystem;
@property(retain) IDERunContextManager *runContextManager; // @synthesize runContextManager=_runContextManager;
@property(retain) id <IDEPackageManagerWorkspace> packageManager; // @synthesize packageManager=_packageManager;
@property BOOL initialContainerScanComplete; // @synthesize initialContainerScanComplete=_initialContainerScanComplete;
@property(copy) IDEActivityLogSection *sourcePackageResolutionIssueLog; // @synthesize sourcePackageResolutionIssueLog=_sourcePackageResolutionIssueLog;
@property(copy, nonatomic) NSArray *sourcePackageLoadingErrors; // @synthesize sourcePackageLoadingErrors=_sourcePackageLoadingErrors;
@property BOOL isWaitingForSourcePackages; // @synthesize isWaitingForSourcePackages=_isWaitingForSourcePackages;
@property(retain) NSDictionary *uniqueIdentifiersToReferencedBlueprints; // @synthesize uniqueIdentifiersToReferencedBlueprints=_uniqueIdentifiersToReferencedBlueprints;
@property(retain) IDEDynamicContentRootGroup *dynamicContentRootGroup; // @synthesize dynamicContentRootGroup=_dynamicContentRootGroup;
@property(readonly) DVTFilePath *containingDirectory;
@property(readonly, nonatomic) NSSet *provisionableDestinations;
@property(readonly, nonatomic) NSSet *provisionables;
- (void)notifyBuildSystemServiceThatBlueprintProviderDidChange:(id)arg1;
- (id)buildableProductsForBaseName:(id)arg1;
- (void)_handleIndexablesChange:(id)arg1;
- (void)_enqueueRegistrationFromPendingIndexables;
- (void)didCreateIndex:(id)arg1;
- (void)initializeIndexAndRefactoring;
- (void)_scheduleWorkspaceUpgradeTasksController:(id)arg1;
- (void)_setupWorkspaceUpgradeTasksController;
- (void)_setupSourceControlWorkspaceMonitorIfNeeded;
- (void)_initializeSourceControlWorkspaceMonitor;
- (void)_setupLocalizationWorkspaceMonitor;
- (void)_setupProvisioningWorkspaceMonitor;
- (void)_setupDeviceInstallWorkspaceMonitor;
- (void)tearDownIndexAndRefactoring;
- (void)_restartIndexingAndRefactoring;
- (void)_scheduleIndexingAndRefactoringRestart;
- (void)_handleIndexableSourcesChange:(id)arg1;
- (void)primitiveInvalidate;
@property(readonly) IDEContainer<IDECustomDataStoring> *representingCustomDataStore;
- (void)_updateWrappedContainer;
- (void)_setWrappedContainer:(id)arg1;
@property(readonly, getter=isSimpleFilesFocused) BOOL simpleFilesFocused;
- (void)_setSimpleFilesFocused:(BOOL)arg1;
- (void)_primitiveSetSimpleFilesFocused:(BOOL)arg1;
- (void)_setHostsOnlyPlayground:(BOOL)arg1;
@property(readonly) NSString *representingTitle;
@property(readonly) DVTFilePath *representingFilePath;
@property(retain) IDEExecutionEnvironment *executionEnvironment;
- (void)_setupExecutionEnvironment;
- (id)_subitemsForUnarchivedSubitems:(id)arg1;
- (float)maxSupportedArchiveVersion;
- (float)archiveVersion;
- (id)displayName;
@property(readonly) NSString *name;
- (id)allLocalizations;
@property(readonly) BOOL supportsSourcePackages;
@property(readonly) id <IDEBuildSystemService> buildSystemService;
@property(readonly) id <IDEBuildSystemService> buildSystemServiceProvider;
@property(readonly) BOOL wantsModernBuildSystem;
@property(readonly) BOOL usesModernBuildSystem;
- (void)_invalidateBuildSystemService;
@property(retain, nonatomic) NSNumber *shouldUseLegacyBuildSystem; // @dynamic shouldUseLegacyBuildSystem;
@property(readonly) _TtC13IDEFoundation30IDEStructureEditingCoordinator *structureEditingMoveCoordinator;
@property(readonly) IDELocalizationManager *localizationManager;
@property(retain) _TtC16DVTDocumentation23DVTDocumentationManager *documentationManager; // @dynamic documentationManager;
@property(retain) IDETestManager *testManager; // @dynamic testManager;
@property(retain) IDEBreakpointManager *breakpointManager; // @dynamic breakpointManager;
@property(readonly) IDEIssueManager *issueManager;
- (void)_setupIssueManagerIfNeeded;
@property(readonly) IDELogManager *logManager;
- (void)_setupLogManagerIfNeeded;
- (id)blueprintsContainingFilePaths:(id)arg1;
@property(readonly) NSArray *notificationPayloadFileReferences;
@property(readonly) NSSet *customDataStores;
- (id)likelyAttachToTargetRunnableBuildableNames;
@property(readonly) NSSet *referencedRunnableBuildableProducts;
- (id)referencedSourcePackageForURL:(id)arg1;
- (BOOL)fileIsMemberOfRemoteSourcePackage:(id)arg1;
@property(readonly) NSSet *referencedRemoteSourcePackages;
@property(readonly) NSSet *referencedSourcePackages;
- (BOOL)containsSwiftPackages;
@property(readonly) NSSet *referencedBlueprints;
- (id)containerGraphOrderForBlueprintProviders:(id)arg1;
@property(readonly) NSSet *referencedBlueprintProviders;
@property(readonly) NSSet *referencedContainers;
- (void)_referencedContainersDidUpdate;
- (void)invokeChangingValueForKey:(id)arg1 fromSet:(id)arg2 toSet:(id)arg3 block:(CDUnknownBlockType)arg4;
- (void)_referencedBlueprintProviderDidEdit:(id)arg1;
- (void)_referencedBlueprintsDidUpdateForProvider:(id)arg1;
- (id)buildableProductsForProductWithModuleName:(id)arg1;
- (id)buildableProductsForProductName:(id)arg1;
- (void)_setupHeaderMapPath;
- (void)_setupContainerQueries;
- (void)_addBlueprintProviderToOrderedSet:(id)arg1;
- (id)_Problem9887530_preferredStructurePathForContainerAtPath:(id)arg1;
- (id)_Problem9887530_preferredStructurePaths;
- (id)_Problem9887530_preferredStructurePathsForContainerToContainerFileReferences:(id)arg1;
- (id)_Problem9887530_wrappedContainerFileReferences:(id)arg1 forPath:(id)arg2;
- (void)_processFileReferencesForProblem8727051;
- (void)_setFileRefsForProblem8727051:(id)arg1;
- (void)cancelTrackedClients;
@property(readonly) BOOL isCancelling;
- (id)clientsNotSupportingCancellation;
- (id)clientsRequiringCancellationPrompt;
- (id)registerUncancellableClientWithName:(id)arg1 terminationSignpost:(CDUnknownBlockType)arg2;
- (id)registerClientWithName:(id)arg1 promptForCancellation:(BOOL)arg2 terminationSignpost:(CDUnknownBlockType)arg3 cancellationBlock:(CDUnknownBlockType)arg4;
@property(readonly) IDEConcreteClientTracker *clientTracker;
- (BOOL)_cancelOngoingBuildWithCompletionBlockIfNeeded:(CDUnknownBlockType)arg1;
- (void)_setupBuildCompletedNotificationForExecutionEnvironment:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (BOOL)saveRecursivelyWithError:(id *)arg1;
- (BOOL)setContainerFilePath:(id)arg1 error:(id *)arg2;
- (BOOL)_setContainerFilePath:(id)arg1 upgradeToWorkspace:(BOOL)arg2 error:(id *)arg3;
- (void)_changeContainerFilePath:(id)arg1 inContext:(id)arg2 upgradeToWorkspace:(BOOL)arg3;
- (void)_changeContainerFilePath:(id)arg1 inContext:(id)arg2;
- (BOOL)_configureWrappedWorkspaceWithError:(id *)arg1;
- (id)_wrappingContainerPath;
- (id)_wrappedPlaygroundContainer;
- (id)_wrappedContainer;
- (void)_setWrappedContainerPath:(id)arg1;
- (id)initWithFilePath:(id)arg1 extension:(id)arg2 workspace:(id)arg3 options:(id)arg4 error:(id *)arg5;
- (void)_buildProductsLocationDidChange;
- (void)_containerDidLoad;
- (void)_checkIfHasFinishedLoading;
- (void)_finishLoadingAsynchronously:(BOOL)arg1 shouldUpgradeFromSimpleFilesFocused:(BOOL)arg2;
- (void)_setupWorkspaceArenaIfNeeded;
- (BOOL)_shouldLoadUISubsystems;
- (void)holdOnDiskFilesForICloudDriveIfNecessary;
@property(readonly) IDEActivityLogSection *issueLog;
- (void)_validateSchemeOptionReference:(id)arg1 scheme:(id)arg2 referenceDisplayType:(id)arg3;
- (void)analyzeModelForIssues;
@property(readonly) IDEActivityLogMessage *swiftDeprecationLogMessage;
@property(readonly) BOOL shouldShowSwiftDeprecationWarning;
- (void)_setFileRefsWithContainerLoadingIssues:(id)arg1;
- (void)_handleContainerResolutionFailureForFileReference:(id)arg1;
- (void)_clearPendingFileReferencesAndContainerLoadingTokens;
- (void)_removePendingReferencedContainerPath:(id)arg1;
- (void)_addPendingReferencedContainerPath:(id)arg1;
- (void)_removePendingReferencedFileReference:(id)arg1;
- (void)_addPendingReferencedFileReference:(id)arg1;
@property(retain) id <IDEWorkspaceDelegate> workspaceDelegate;
- (id)_openingPerformanceMetricIdentifier;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)arg1 version:(id)arg2;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)arg1 version:(id)arg2;
- (void)setSdefSupport_activeRunDestination:(id)arg1;
- (id)sdefSupport_activeRunDestinationForDocument:(id)arg1;
- (id)sdefSupport_runDestinationsForDocument:(id)arg1;
- (id)_disambiguatedRunDestinations;
- (void)setSdefSupport_activeScheme:(id)arg1;
- (id)sdefSupport_activeSchemeForDocument:(id)arg1;
- (id)sdefSupport_schemesForDocument:(id)arg1;
- (id)newScriptingObjectOfClass:(Class)arg1 forValueForKey:(id)arg2 withContentsValue:(id)arg3 properties:(id)arg4;
- (id)collectLinkedTargetIndexableIdsForIndexableIds:(id)arg1;
@property(retain) NSArray *namedBatchFindScopes;
- (id)localScopeStore;
- (id)observeCurrentBuildOperationDidChange:(CDUnknownBlockType)arg1;
- (id)observeActiveRunDestinationDidChange:(CDUnknownBlockType)arg1;
- (id)observeBuildImplicitDependenciesDidChange:(CDUnknownBlockType)arg1;
- (id)observeActiveSchemeDidChange:(CDUnknownBlockType)arg1;
- (id)observeActiveBlueprintLogSectionIDs:(CDUnknownBlockType)arg1;
- (id)makeLogStoreForNoticeLogs;
- (id)activeBlueprintLogSectionIDs;
@property(readonly) id <IDEBlueprintProvider> noticeWorkspaceWrappedContainer;
- (id)observeLatestBuildLogIdentityDidChange:(CDUnknownBlockType)arg1;
@property(readonly) id <IDEBuildNoticeLogSection> latestBuildLogForBuildNoticeProvider;
- (id)ideModelObjectTypeIdentifier;
- (id)ideIndex_configurationNameForIndexingBlueprint:(id)arg1 scheme:(id)arg2;
- (id)ideIndex_runDestinationForIndexingWithScheme:(id)arg1;
- (id)ideIndex_bestSchemeForBlueprint:(id)arg1;
- (id)ideIndex_buildParametersForIndexingBlueprint:(id)arg1 synthesizedMacroOverrides:(id)arg2;
- (void)_updateUniqueIdentifiersToReferencedBlueprints;
- (void)issueLogDataSourceDidChangeForUntypedDataSource:(id)arg1;
- (void)issueLogDataSourceDidChangeForBlueprintProvider:(id)arg1;
- (void)issueLogDataSourceDidChangeForBlueprint:(id)arg1;
- (void)issueLogDataSourceDidChangeForWorkspace:(id)arg1;
- (void)issueLogDataSourceDidChange;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;
@property(readonly) IDEWorkspace *workspace;

@end

