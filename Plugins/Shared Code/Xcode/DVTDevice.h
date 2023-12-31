//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTDevice_h
#define DVTDevice_h
#import <Foundation/Foundation.h>

#include "DTApplicationObserver-Protocol.h"
#include "DVTBasicDevice-Protocol.h"
#include "DVTConditionInducerSession.h"
#include "DVTDevice.h"
#include "DVTDeviceType.h"
#include "DVTDispatchLock.h"
#include "DVTExtension.h"
#include "DVTPlatform.h"
#include "DVTTestDevice-Protocol.h"

@class DTXChannel, DVTCPUCount, NSArray, NSData, NSDictionary, NSError, NSMutableArray, NSMutableSet, NSNumber, NSOrderedSet, NSSet, NSString, NSURL, NSUUID, UTType;
@protocol OS_dispatch_queue;

@interface DVTDevice : NSObject<DVTTestDevice, DTApplicationObserver, DVTBasicDevice> {
  /* instance variables */
  NSObject<OS_dispatch_queue> *_instrumentsServerMessageQueue;
  unsigned long long _nonBlockingOperationCount;
  DVTDispatchLock *_deviceOperationLock;
  DTXChannel *_appExtensionInstallObserverChannel;
  DTXChannel *_appExtensionInstallObserverChannel_proxy;
  NSObject<OS_dispatch_queue> *_appListingChannelQueue;
  NSObject<OS_dispatch_queue> *_stateControlQueue;
  DTXChannel *_odrAssetServerChannel;
  unsigned int _demandRetainCount;
}

@property (readonly, copy) NSString *identifier;
@property (readonly, copy) NSString *name;
@property (readonly) DVTDevice *dvtDevice;
@property (readonly) unsigned long long state;
@property (readonly) NSObject<DVTTestDevice> *activeProxiedDevice;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (nonatomic, readonly) DVTPlatform *platformNonnull;
@property (nonatomic, readonly) NSString *nativeArchitectureNonnull;
@property (readonly) DVTExtension *extension;
@property (copy, nonatomic) NSString *modelName;
@property (copy, nonatomic) NSString *modelCode;
@property (copy, nonatomic) NSString *modelUTI;
@property BOOL available;
@property (nonatomic) BOOL usedForDevelopment;
@property (retain) DVTPlatform *platform;
@property (copy) NSString *operatingSystemVersion;
@property (copy) NSString *iOSSupportVersion;
@property (copy) NSString *operatingSystemBuild;
@property (copy, nonatomic) NSString *operatingSystemVersionWithBuildNumber;
@property (retain) DVTDeviceType *deviceType;
@property (copy) NSString *nativeArchitecture;
@property (copy) NSSet *translatedArchitectures;
@property (retain) DVTCPUCount *cpuCountDescription;
@property (copy) NSString *cpuKind;
@property (copy) NSNumber *cpuSpeedMHz;
@property (copy) NSNumber *busSpeedMHz;
@property BOOL canSelectArchitectureToExecute;
@property (readonly, copy) NSMutableSet *mutableCapabilities;
@property (readonly) NSNumber *ecid;
@property (readonly) NSArray *deviceOperations;
@property (readonly, nonatomic) BOOL shouldPrepareDebugSymbols;
@property (retain) NSError *lastPairingError;
@property (readonly, copy) NSURL *deviceLocation;
@property (readonly) BOOL genericDevice;
@property (readonly) BOOL concreteDevice;
@property (readonly) BOOL isSuggestedDevice;
@property (readonly) NSUUID *identifierOfBackingDeviceSuggestion;
@property (readonly) BOOL isCoreDevice;
@property (readonly) NSArray *deviceSummaryPropertyDictionaries;
@property (readonly) NSArray *deviceSummaryInternalPropertyDictionaries;
@property (readonly) BOOL dvtDevicesWindow_canSSH;
@property (readonly) NSString *dvtDevicesWindow_isWirelessEnabled;
@property (readonly) BOOL canUserIgnore;
@property (readonly) BOOL ignored;
@property (readonly) BOOL automaticallyVisible;
@property unsigned long long visibilityPreference;
@property (readonly, nonatomic) BOOL allowsSecureServices;
@property (readonly, copy) NSOrderedSet *supportedArchitectures;
@property (readonly) BOOL isSupportedHardware;
@property (readonly) BOOL isRunningSupportedOS;
@property BOOL isCloudDevice;
@property BOOL isCloudDevicePlaceholder;
@property (readonly, copy) NSSet *capabilities;
@property (readonly) NSString *displayOrder;
@property (readonly) NSData *displayImageBitmapData;
@property (readonly) BOOL alwaysAttachesForDebugging;
@property (readonly) BOOL supportsRecordedFrames;
@property (readonly, copy) NSString *recordedFramesLibdispatchIntrospectionDylibPath;
@property (readonly, copy) NSString *extraDebuggingRuntimeDylibPath;
@property (readonly) BOOL supportsDebugOverrides;
@property (readonly) BOOL supportsDaemonDebugging;
@property (readonly) NSSet *eligibleForAdditionalPlatforms;
@property (readonly) NSString *executionDisplayName;
@property (readonly) NSDictionary *scriptingEnvironment;
@property (readonly) BOOL supportsLocationSimulation;
@property (readonly) BOOL supportsLocalizationOptions;
@property (readonly) BOOL supportsRoutingCoverageFile;
@property (readonly) BOOL supportsSensorReplayFile;
@property (readonly) BOOL supportsDisplayScaleOption;
@property (readonly) BOOL supportsCustomWorkingDirectory;
@property (readonly) BOOL supportsResumeAndTurningItOnOrOff;
@property (readonly) BOOL supportsDebuggingDocumentVersioning;
@property (readonly) BOOL supportsDebugAsDifferentUser;
@property (readonly) BOOL supportsAttachByPIDOrName;
@property (readonly) BOOL supportsApplicationDataUploading;
@property (readonly) BOOL runsRemoteFromHostLauncher;
@property (readonly) BOOL canRunMultipleInstancesPerApp;
@property (readonly) BOOL supportsXPCServiceDebugging;
@property (readonly) BOOL supportsUnhostedXPCServiceDebugging;
@property (readonly) BOOL supportsDebuggingForAskOnLaunch;
@property (readonly) BOOL supportsDTServiceHubLogging;
@property (readonly) BOOL supportsLibLogRedirectLogging;
@property (readonly) BOOL couldSupportLibLogRedirectLoggingBasedOnBuildNumber;
@property (readonly) NSString *pathOfLogRedirectDylib;
@property (readonly) BOOL disablesOnlyActiveArch;
@property (readonly) BOOL deferProfileGenerationSetupUntilAfterInstallation;
@property (readonly) unsigned long long supportsFetchEvents;
@property (readonly) BOOL supportsArchiving;
@property (readonly) NSSet *provisioningProfiles;
@property (readonly) BOOL canBeWatchCompanion;
@property (readonly) BOOL canSetActiveProxiedDevice;
@property (readonly) NSSet *companionDevices;
@property (readonly) BOOL canRename;
@property (readonly) BOOL supportsSimulateMetricPayloads;
@property (readonly, nonatomic) BOOL supportsLogFileRetrieval;
@property (readonly) BOOL supportsLANConnections;
@property (readonly) BOOL isWireless;
@property (readonly) BOOL hasWirelessConnection;
@property (readonly) BOOL hasWiredConnection;
@property (readonly) BOOL hasConnection;
@property (readonly, copy) NSString *hostname;
@property (readonly, copy) NSString *primaryAddress;
@property (readonly, copy) NSArray *addresses;
@property (copy) NSString *presumedRemoteAddress;
@property (readonly) BOOL isWirelessEnabled;
@property (readonly) BOOL userCanToggleLANConnections;
@property (readonly) BOOL autoPairEnabled;
@property (readonly) BOOL usesPairingRecord;
@property (readonly) BOOL isPaired;
@property (readonly) BOOL supportsUnpair;
@property (readonly) NSString *hostPairingToken;
@property (readonly) long long directSSHPort;
@property (readonly) long long remoteSSHPort;
@property (readonly) long long rsyncPort;
@property (readonly) BOOL canTakeScreenshot;
@property (readonly) BOOL canStartUpAndShutDown;
@property (readonly) BOOL allowsManagedStateControl;
@property (readonly) BOOL canRunExecutables;
@property (readonly) BOOL canInstallApplication;
@property (readonly) unsigned long long supportedLaunchOptions;
@property (readonly) unsigned long long supportedLaunchOptionsForProxiedDevice;
@property (readonly) BOOL canConnectOnDemand;
@property (readonly) NSString *disambiguousIdentifier;
@property (readonly, copy, nonatomic) NSString *modelCodename;
@property (readonly, copy, nonatomic) NSString *thinningProductType;
@property (readonly, copy, nonatomic) UTType *modelUTType;
@property (readonly) NSArray *supportedDeviceFamilies;
@property (readonly, copy) NSString *processorDescription;
@property (readonly) BOOL isInternalBuild;
@property (readonly) BOOL isProxiedDevice;
@property (readonly, weak) NSObject<DVTBasicDevice> *companionDevice;
@property (readonly) NSError *unavailabilityError;
@property (readonly) BOOL deviceIsBusy;
@property (readonly) BOOL supportsDeveloperMode;
@property (readonly) long long developerMode;
@property (readonly) BOOL supportsMainThreadChecker;
@property (readonly) BOOL supportsPerformanceAntipatternChecker;
@property (readonly, nonatomic) DVTConditionInducerSession *conditionInducerSession;
@property (readonly) BOOL supportsSimulateVehicularCrash;
@property (readonly, copy) NSString *nameForDeveloperPortal;
@property (readonly, copy) NSString *platformIdentifier;
@property (readonly) BOOL supportsProvisioning;
@property (readonly, copy) NSSet *proxiedDevices;

/* class methods */
+ (void)initialize;
+ (id)remotePairingVersionScan:(id)scan;
+ (id)_knownDeviceLocators;
+ (id)deviceFrameworkVersionAnalytics;
+ (id)keyPathsForValuesAffectingActiveProxiedDevice;
+ (id)keyPathsForValuesAffectingSupportedArchitectures;
+ (id)modelUTIFromModelCode:(id)code;
+ (id)modelNameFromModelUTI:(id)uti;
+ (id)keyPathsForValuesAffectingIgnored;
+ (id)keyPathsForValuesAffectingHasConnection;
+ (unsigned long long)watchLaunchStyleForWatch:(id)watch;
+ (unsigned long long)watchLaunchStyleForDevice:(id)device;

/* instance methods */
- (id)initWithDeviceLocation:(id)location extension:(id)extension;
- (void)dealloc;
- (BOOL)isEqual:(id)equal;
- (id)deviceServicesCategory;
- (id)servicesMatchingCapability:(id)capability;
- (void)setActiveProxiedDevice:(id)device completionQueue:(id)queue completionHandler:(id /* block */)handler;
- (id)deviceSupportSymbolsPathForTargetArch:(id)arch;
- (id)prepareSymbolCacheForTargetArch:(id)arch;
- (BOOL)isGenericDevice;
- (BOOL)isConcreteDevice;
- (BOOL)isUsedForDevelopment;
- (id)viewDebuggerDylibPathWithOptions:(id)options;
- (void)requestProcessInformationsOnPairedDevice:(BOOL)device handler:(id /* block */)handler;
- (void)remotePathForBundleIdentifier:(id)identifier onProxy:(BOOL)proxy handler:(id /* block */)handler;
- (id)coreDeviceIdentifier;
- (id)deviceIdentifierForGPUTracing;
- (BOOL)supportsBuildingThinnedResources;
- (BOOL)supportsUISnapshotOnProxy:(BOOL)proxy;
- (BOOL)supportsPGOReturningError:(id *)error;
- (BOOL)addressSanitizerRequiresDyldInsertLibrary;
- (BOOL)threadSanitizerRequiresDyldInsertLibrary;
- (unsigned long long)backgroundFetchSupportStyle;
- (void)performFetchEventForBundleIdentifier:(id)identifier orPid:(int)pid onProxy:(BOOL)proxy;
- (void)snapshotUIForBundleIdentifier:(id)identifier orPid:(int)pid onProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)performUbiquityFetchEvent;
- (BOOL)canPerformUbiquityFetchEvent;
- (void)installProvisioningProfile:(id)profile completion:(id /* block */)completion;
- (void)installProvisioningProfiles:(id)profiles completion:(id /* block */)completion;
- (void)installProvisioningProfileAtURL:(id)url completion:(id /* block */)completion;
- (void)uninstallProvisioningProfile:(id)profile completion:(id /* block */)completion;
- (BOOL)shouldIgnoreGivenVisibilityPreference:(unsigned long long)preference automaticallyVisible:(BOOL)visible;
- (BOOL)isIgnored;
- (BOOL)validateDeviceSpecifierOptions:(id)options error:(id *)error;
- (void)debugXPCServices:(id)xpcservices onPairedDevice:(BOOL)device completionSemaphore:(id)semaphore;
- (void)stopDebuggingXPCServices:(id)xpcservices forPairedDevice:(BOOL)device;
- (void)requestDebugLaunchOfDaemon:(id)daemon onPairedDevice:(BOOL)device;
- (id)installApplicationSync:(id)sync options:(id)options;
- (id)installApplicationsSync:(id)sync options:(id)options;
- (void)enableDeviceForDevelopment;
- (void)disableDeviceForDevelopment;
- (void)renameDevice:(id)device;
- (id)primaryInstrumentsServer;
- (id)proxiedPrimaryInstrumentsServer;
- (void)cancelPrimaryInstrumentsServer;
- (BOOL)isAvailableWithError:(id *)error;
- (void)applicationInstalled:(id)installed;
- (void)applicationUninstalled:(id)uninstalled;
- (id)_applicationListingChannelForPairedDevice:(BOOL)device;
- (id)listenForInstallOfAppExtensionIdentifiers:(id)identifiers onPairedDevice:(BOOL)device;
- (void)willInstallWatchAppForCompanionIdentifier:(id)identifier completionBlock:(id /* block */)block;
- (void)launchWatchAppWithIdentifier:(id)identifier options:(id)options completionblock:(id /* block */)completionblock;
- (id)_instrumentsServerForWatchLaunch;
- (void)_attemptToLaunchWatchAppWithIdentifier:(id)identifier options:(id)options completionblock:(id /* block */)completionblock attempt:(unsigned long long)attempt;
- (BOOL)_shouldAttemptToRetryWatchAppLaunchAttemptForLaunchError:(id)error;
- (void)terminateWatchAppWithIdentifier:(id)identifier options:(id)options completionSemaphore:(id)semaphore;
- (id)makeServiceHubProcessControlChannelForLauncher:(unsigned long long)launcher;
- (id)makeServiceHubProcessControlChannelForLauncher:(unsigned long long)launcher onProxy:(BOOL)proxy;
- (id)serviceHubProcessControlChannel;
- (id)serviceHubProcessControlChannelOnProxy:(BOOL)proxy;
- (void)showTodayViewForExtensions:(id)extensions pid:(int)pid;
- (void)showAppClipWithBundleIdentifer:(id)identifer pid:(int)pid context:(id)context completed:(id /* block */)completed;
- (id)_appendEnvSettings:(id)settings fromEnv:(id)env toProcessControl:(id)control;
- (void)showWidgetKit:(id)kit onProxy:(BOOL)proxy pid:(int)pid completed:(id /* block */)completed;
- (void)showQuicklookPreviewForExtension:(id)extension;
- (void)showSiriForExtensions:(id)extensions queryText:(id)text pid:(int)pid onProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)pressHomeButtonOnProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)simulateNotificationWithBundleID:(id)id payload:(id)payload onProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)showMessagesExtensionOnProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)simulateMetricPayloadsWithBundleID:(id)id payload:(id)payload onProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)_processControlForPid:(int)pid payload:(id)payload onProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)simulateVehicularCrashOnProxy:(BOOL)proxy completed:(id /* block */)completed;
- (void)_resourceControlChannel:(id)channel completionBlock:(id /* block */)block;
- (void)purgeAllResourcesForBundleIdentifier:(id)identifier completionBlock:(id /* block */)block;
- (void)purgeResourceWithTag:(id)tag bundleIdentifier:(id)identifier completionBlock:(id /* block */)block;
- (id)crashLogTransferSession;
- (id)enableLANConnections;
- (BOOL)disableLANConnectionsWithError:(id *)error;
- (id)_genericDeviceErrorWithMessage:(id)message;
- (void)extendedPairWithPromise:(id)promise extendedInformationHandler:(id /* block */)handler;
- (void)unpair;
- (void)attemptRecoveryFromUnavailabilityError;
- (void)unprepareIfPossible;
- (void)simulateLocationWithLatitude:(id)latitude longitude:(id)longitude completionBlock:(id /* block */)block;
- (void)stopLocationSimulationWithCompletionBlock:(id /* block */)block;
- (id)screenshotController;
- (void)takeScreenshotWithCompletionBlock:(id /* block */)block;
- (id)analyticsDictionaryWithName:(id)name proxiedDeviceUsed:(id)used;
- (id)endAnalyticsInOperation:(id)operation error:(id)error;
- (id)startDeviceOperation;
- (id)startDeviceOperationWithDescription:(id)description analyticsName:(id)name;
- (id)startDeviceOperationWithDescription:(id)description analyticsName:(id)name proxiedDeviceUsed:(id)used;
- (id)startUserInitiatedDeviceOperation;
- (id)startUserInitiatedDeviceOperationWithDescription:(id)description analyticsName:(id)name;
- (id)_startDeviceOperationUserInitiated:(BOOL)initiated description:(id)description shouldReportAnalyticsWithName:(id)name proxiedDeviceUsed:(id)used;
- (void)endDeviceOperation:(id)operation error:(id)error;
- (void)endDeviceOperation:(id)operation;
- (BOOL)wantsDeviceOperationActivityReporting;
- (id)startUpDevice;
- (id)shutDownDevice;
- (void)_transitionToState:(unsigned long long)state error:(id)error completionHandler:(id /* block */)handler;
- (void)discoverAvailableConnectionsWithCompletionHandler:(id /* block */)handler;
- (void)connectToDeviceWithCompletionHandler:(id /* block */)handler;
- (void)startDeviceWithCompletionHandler:(id /* block */)handler;
- (void)establishDevelopmentTrustWithCompletionHandler:(id /* block */)handler;
- (void)makeDeviceReadyForDevelopmentWithCompletionHandler:(id /* block */)handler;
- (unsigned long long)discoverAvailableConnectionsSyncWithError:(id *)error;
- (unsigned long long)connectToDeviceSyncWithError:(id *)error;
- (unsigned long long)startDeviceSyncWithError:(id *)error;
- (unsigned long long)establishDevelopmentTrustSyncWithError:(id *)error;
- (unsigned long long)makeDeviceReadyForDevelopmentSyncWithError:(id *)error;
- (id)runExecutableAtPath:(id)path withArguments:(id)arguments environment:(id)environment options:(id)options terminationHandler:(id /* block */)handler;
- (id)installApplicationAtPath:(id)path withOptions:(id)options;
- (id)uninstallApplicationWithBundleIdentifier:(id)identifier andOptions:(id)options;
- (id)applicationIsInstalledWithBundleIdentifier:(id)identifier;
- (BOOL)canInstallBuildablesError:(id *)error;
- (id)installDSTROOTAtPath:(id)path withOptions:(id)options;
- (id)installRsyncAtURL:(id)url withOptions:(id)options;
- (id)launchApplicationWithBundleIdentifier:(id)identifier withArguments:(id)arguments environment:(id)environment options:(id)options;
- (id)launchApplicationAtPath:(id)path withArguments:(id)arguments environment:(id)environment options:(id)options;
- (id)spawnExecutableAtURL:(id)url withArguments:(id)arguments environment:(id)environment options:(id)options;
- (id)fetchSpecificLaunchFailureReason;
- (id)loggingStream;
- (id)_mobileDevice;
- (BOOL)supportsDYLDPrintToStdErr;
- (BOOL)shouldLaunchSuspendedForWatchAppLaunchStyle:(unsigned long long)style;
- (void)takeWatchPowerAssertionName:(id)name details:(id)details;
- (void)cancelWatchPowerAssertion;
- (id)handleStoreKitConfigurationSyncForBundleID:(id)id configurationFilePath:(id)path runsOnProxy:(BOOL)proxy;
- (id)_bestServerConnectionForCapability:(id)capability minimumVersion:(int)version runsOnProxy:(BOOL)proxy;
- (id)supportsTPCCallstackAnalysis:(BOOL)analysis;
- (id)startODRAssetServiceForAppAtPath:(id)path runsOnProxy:(BOOL)proxy;
- (BOOL)supportsInstalledRoots;
- (id)fetchInstalledRoots;
- (id)installRootsAtLocalPaths:(id)paths;
- (id)uninstallRootsWithIdentifiers:(id)identifiers;
- (id)performBatchedRootOperationsWithBlock:(id /* block */)block;
- (id)reboot;
- (id)createFileHandleForDebugserver;
- (void)makeDeviceConcreteWithUserInfo:(id)info completionHandler:(id /* block */)handler;
- (void)retainDemand;
- (void)releaseDemandWithDelay:(unsigned long long)delay;
- (BOOL)hasRetainedDemand;
- (BOOL)isAvailable;
@end

#endif /* DVTDevice_h */
