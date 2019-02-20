//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEXMLPackageContainer.h"

#import "IDEClientTracking-Protocol.h"
#import "IDEIssueLogDataSource-Protocol.h"
#import "IDEProvisionableProvider-Protocol.h"

@class DVTFilePath, DVTNotificationToken, DVTObservingToken, DVTStackBacktrace, DVTTimeSlicedMainThreadWorkQueue, IDEActivityLogMessage, IDEActivityLogSection, IDEBreakpointManager, IDEConcreteClientTracker, IDEContainer, IDEContainerQuery, IDEDeviceInstallWorkspaceMonitor, IDEDynamicContentRootGroup, IDEExecutionEnvironment, IDEIndex, IDEIssueManager, IDELocalizationManager, IDELogManager, IDEProvisioningManager, IDEProvisioningWorkspaceMonitor, IDERefactoring, IDERunContextManager, IDESourceControlWorkspaceMonitor, IDETestManager, IDETextFragmentIndex, IDEWorkspaceArena, IDEWorkspaceSharedSettings, IDEWorkspaceUpgradeTasksController, IDEWorkspaceUserSettings, NSArray, NSDate, NSDictionary, NSHashTable, NSMapTable, NSMutableArray, NSMutableOrderedSet, NSMutableSet, NSNumber, NSSet, NSString, _TtC13IDEFoundation30IDEStructureEditingCoordinator, _TtC16DVTDocumentation23DVTDocumentationManager;
@protocol IDEActiveRunContextStoring, IDEBuildSystemServiceProvider, IDECustomDataStoring, IDEWorkspaceDelegate;

@interface IDEWorkspace : IDEXMLPackageContainer <IDEClientTracking, IDEIssueLogDataSource, IDEProvisionableProvider>
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
    NSMapTable *_identifiersToIndexablesPendingRegistration;
    DVTTimeSlicedMainThreadWorkQueue *_indexRegistrationQueue;
    IDEDeviceInstallWorkspaceMonitor *_deviceInstallWorkspaceMonitor;
    IDEProvisioningWorkspaceMonitor *_provisioningWorkspaceMonitor;
    IDESourceControlWorkspaceMonitor *_sourceControlWorkspaceMonitor;
    IDEProvisioningManager *_provisioningManager;
    IDELocalizationManager *_localizationManager;
    _TtC13IDEFoundation30IDEStructureEditingCoordinator *_structureEditingMoveCoordinator;
    NSNumber *_shouldUseLegacyBuildSystem;
    id <IDEBuildSystemServiceProvider> _buildSystemServiceProvider;
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
    BOOL _hostsOnlyPlayground;
    BOOL _isPotentiallyClosing;
    IDEDynamicContentRootGroup *_dynamicContentRootGroup;
    NSArray *_sourcePackageLoadingErrors;
    IDEActivityLogSection *_sourcePackageResolutionIssueLog;
    IDETextFragmentIndex *_textFragmentIndex;
    IDERefactoring *_refactoring;
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
+ (id)keyPathsForValuesAffectingReferencedSourcePackages;
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
@property BOOL hostsOnlyPackages; // @synthesize hostsOnlyPackages=_hostsOnlyPackages;
@property BOOL hostsOnlyXcode3Project; // @synthesize hostsOnlyXcode3Project=_hostsOnlyXcode3Project;
@property BOOL hostsOnlyWrappedContainer; // @synthesize hostsOnlyWrappedContainer=_hostsOnlyWrappedContainer;
@property(readonly) DVTFilePath *wrappedContainerPath; // @synthesize wrappedContainerPath=_wrappedContainerPath;
@property(readonly, nonatomic) BOOL postLoadingPerformanceMetricsAllowed; // @synthesize postLoadingPerformanceMetricsAllowed=_postLoadingPerformanceMetricsAllowed;
@property(nonatomic) BOOL finishedLoading; // @synthesize finishedLoading=_finishedLoading;
@property(nonatomic) BOOL wasLoadedForUIContext; // @synthesize wasLoadedForUIContext=_wasLoadedForUIContext;
@property(retain, nonatomic) IDEProvisioningManager *provisioningManager; // @synthesize provisioningManager=_provisioningManager;
@property(retain) IDESourceControlWorkspaceMonitor *sourceControlWorkspaceMonitor; // @synthesize sourceControlWorkspaceMonitor=_sourceControlWorkspaceMonitor;
@property(retain) IDEProvisioningWorkspaceMonitor *provisioningWorkspaceMonitor; // @synthesize provisioningWorkspaceMonitor=_provisioningWorkspaceMonitor;
@property(retain) IDEDeviceInstallWorkspaceMonitor *deviceInstallWorkspaceMonitor; // @synthesize deviceInstallWorkspaceMonitor=_deviceInstallWorkspaceMonitor;
@property(readonly) IDERefactoring *refactoring; // @synthesize refactoring=_refactoring;
@property(readonly) IDETextFragmentIndex *textFragmentIndex; // @synthesize textFragmentIndex=_textFragmentIndex;
@property(retain) IDEIndex *index; // @synthesize index=_index;
@property(retain) IDERunContextManager *runContextManager; // @synthesize runContextManager=_runContextManager;
@property BOOL initialContainerScanComplete; // @synthesize initialContainerScanComplete=_initialContainerScanComplete;
@property(copy) IDEActivityLogSection *sourcePackageResolutionIssueLog; // @synthesize sourcePackageResolutionIssueLog=_sourcePackageResolutionIssueLog;
@property(copy) NSArray *sourcePackageLoadingErrors; // @synthesize sourcePackageLoadingErrors=_sourcePackageLoadingErrors;
@property BOOL isWaitingForSourcePackages; // @synthesize isWaitingForSourcePackages=_isWaitingForSourcePackages;
@property(retain) IDEDynamicContentRootGroup *dynamicContentRootGroup; // @synthesize dynamicContentRootGroup=_dynamicContentRootGroup;
// - (void).cxx_destruct;
@property(readonly, nonatomic) NSSet *provisionableDevices;
@property(readonly, nonatomic) NSSet *provisionables;
- (void)notifyBuildSystemServiceProviderThatBlueprintProviderDidChange:(id)arg1;
- (id)buildableProductsForBaseName:(id)arg1;
- (void)_handleIndexablesChange:(id)arg1;
- (void)didCreateIndex:(id)arg1;
- (void)initializeIndexAndRefactoring;
- (void)_scheduleWorkspaceUpgradeTasksController:(id)arg1;
- (void)_setupWorkspaceUpgradeTasksController;
- (void)_setupSourceControlWorkspaceMonitorIfNeeded;
- (void)_initializeSourceControlWorkspaceMonitor;
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
@property(readonly) NSString *representingTitle;
@property(readonly) DVTFilePath *representingFilePath;
@property(retain) IDEExecutionEnvironment *executionEnvironment;
- (void)_setupExecutionEnvironment;
- (id)_subitemsForUnarchivedSubitems:(id)arg1;
- (float)maxSupportedArchiveVersion;
- (float)archiveVersion;
- (id)displayName;
@property(readonly) NSString *name;
@property(readonly) BOOL supportsSourcePackages;
@property(readonly) id <IDEBuildSystemServiceProvider> buildSystemServiceProvider;
@property(readonly) BOOL wantsModernBuildSystem;
@property(readonly) BOOL usesModernBuildSystem;
- (void)_invalidateBuildSystemServiceProvider;
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
@property(readonly) NSSet *referencedSourcePackages;
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
- (BOOL)setContainerFilePath:(id)arg1 error:(id *)arg2;
- (BOOL)_setContainerFilePath:(id)arg1 upgradeToWorkspace:(BOOL)arg2 error:(id *)arg3;
- (void)_changeContainerFilePath:(id)arg1 inContext:(id)arg2 upgradeToWorkspace:(BOOL)arg3;
- (void)_changeContainerFilePath:(id)arg1 inContext:(id)arg2;
- (BOOL)_configureWrappedWorkspaceWithError:(id *)arg1;
- (id)_wrappingContainerPath;
- (BOOL)wrappedContainerConformsToProtocol:(id)arg1;
- (BOOL)isWrappedContainerKindOfClass:(Class)arg1;
- (id)_wrappedPlaygroundContainer;
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
@property(retain) NSArray *namedBatchFindScopes;
- (id)localScopeStore;
- (void)endSourcePackagePreflightResolution:(id)arg1;
- (id)beginSourcePackagePreflightResolutionWithReference:(id)arg1 delegate:(id)arg2 error:(out id *)arg3;
- (id)latestSourcePackageVersionFromTags:(id)arg1;
- (id)ideModelObjectTypeIdentifier;
- (id)ideIndex_configurationNameForIndexingBlueprint:(id)arg1 scheme:(id)arg2;
- (id)ideIndex_runDestinationForIndexingWithScheme:(id)arg1;
- (id)ideIndex_bestSchemeForBlueprint:(id)arg1;
- (id)ideIndex_buildParametersForIndexingBlueprint:(id)arg1 synthesizedMacroOverrides:(id)arg2;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

