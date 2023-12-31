//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDELaunchSchemeAction_h
#define IDELaunchSchemeAction_h
#import <Foundation/Foundation.h>

#include "IDELaunchTestSchemeAction.h"
#include "_TtC13IDEFoundation24IDESchemeOptionReference.h"
#include "_TtC13IDEFoundation25IDEDeviceAppDataReference.h"
#include "_TtC13IDEFoundation28IDELocationScenarioReference.h"

@class DVTNotificationToken, DVTObservingToken, NSArray, NSDictionary, NSMutableDictionary, NSMutableOrderedSet, NSNumber, NSString;
@protocol IDEAnalysisToolService;

@interface IDELaunchSchemeAction : IDELaunchTestSchemeAction {
  /* instance variables */
  DVTObservingToken *_launchSessionObservingToken;
  NSDictionary *_cachedAppExtensionBuiltPaths;
  NSObject<IDEAnalysisToolService> *_analysisToolService;
  long long _internalStructuredConsoleMode;
  BOOL _hasArchivedInternalIOSLaunchStyle;
}

@property BOOL launchWithGlance;
@property BOOL launchWithComplication;
@property BOOL launchWithNotification;
@property BOOL staticNotificationSelected;
@property (retain) IDEFoundation_IDEDeviceAppDataReference *deviceAppDataReference;
@property BOOL allowDeviceSensorReplayData;
@property (retain) IDEFoundation_IDESchemeOptionReference *deviceSensorReplayFileReference;
@property BOOL debugXPCServices;
@property BOOL enableMallocStackLoggingLiteForXPCServices;
@property BOOL hiddenMallocStackLoggingLiteForXPCServices;
@property BOOL enableSanitizerCoverage;
@property (nonatomic) int launchStyle;
@property (nonatomic) unsigned long long launchAutomaticallySubstyle;
@property BOOL useCustomWorkingDirectory;
@property (copy, nonatomic) NSString *customWorkingDirectory;
@property (readonly) NSString *resolvedCustomWorkingDirectory;
@property BOOL allowLocationSimulation;
@property BOOL showNonLocalizedStrings;
@property BOOL enableTextLayoutIssuesDetection;
@property (retain) IDEFoundation_IDELocationScenarioReference *locationScenarioReference;
@property (retain) IDEFoundation_IDESchemeOptionReference *routingCoverageFileReference;
@property (retain) NSNumber *simulatorIPhoneDisplay;
@property (retain) NSNumber *simulatorIPadDisplay;
@property (retain) IDEFoundation_IDESchemeOptionReference *storeKitConfigurationFileReference;
@property BOOL ignoresPersistentStateOnLaunch;
@property BOOL debugDocumentVersioning;
@property (readonly) BOOL gpuDebuggerAvailable;
@property int enableGPUFrameCaptureMode;
@property int enableGPUValidationMode;
@property int enableGPUShaderValidationMode;
@property (nonatomic) BOOL showGraphicsOverview;
@property (nonatomic) BOOL logGraphicsOverview;
@property (retain) NSString *customLaunchCommand;
@property (copy) NSArray *additionalLaunchCommands;
@property BOOL customLaunchCommandPauseAfterCommands;
@property (retain) NSString *launchdServiceSpecifier;
@property (readonly) NSArray *customLaunchCommandMacroExpanded;
@property (retain) NSDictionary *additionalSchemeSettings;
@property (nonatomic) long long internalIOSInstallStyle;
@property (copy) NSString *internalIOSSubstitutionApp;
@property BOOL viewDebuggingEnabled;
@property BOOL queueDebuggingEnabled;
@property BOOL memoryGraphOnResourceException;
@property (nonatomic) long long structuredConsoleMode;
@property BOOL placeholderRenderingEnabled;
@property (copy) NSMutableOrderedSet *debugServiceExtensionContents;
@property (copy) NSString *debugServiceExtensionContentsString;
@property (copy) NSString *debugServiceExtension;

/* class methods */
+ (id)createAdditionalDiagnosticsDict;
+ (id)keyPathsForValuesAffectingDoesNonActionWork;
+ (id)keyPathsForValuesAffectingLaunchDueToFetchEvent;
+ (BOOL)shouldEnableMallocLoggingLiteByDefault:(id)defaultNot device:(id)device;

/* instance methods */
- (id)initFromXMLUnarchiver:(id)xmlunarchiver archiveVersion:(float)version;
- (void)dvt_commonInitIsFromUnarchiver:(BOOL)unarchiver;
- (id)schemeCommand;
- (void)_setupAnalysisToolService;
- (void)_setupQueueDebuggingState;
- (id)notificationPayloadFileReferences;
- (void)setRunContext:(id)context;
- (id)name;
- (BOOL)doesNonActionWork;
- (id)commandLineArgumentsForDevice:(id)device buildParameters:(id)parameters;
- (id)additionalOptions;
- (int)rawLaunchStyle;
- (BOOL)launchDueToFetchEvent;
- (void)setLaunchDueToFetchEvent:(BOOL)event;
- (long long)_internalIOSInstallStyle;
- (long long)internalIOSInstallStyleForBuildables:(id)buildables;
- (BOOL)performanceAntipatternCheckerAllowedForRunnable;
- (BOOL)enableMallocStackLoggingLiteByDefaultIfNecessary:(id)necessary;
- (void)modifyEnvironmentForMallocStackLogging:(id)logging;
- (void)_setupRecordedFramesInEnvironmentVariables:(id)variables runDestination:(id)destination;
- (BOOL)hasAppExtensionsInTargets;
- (BOOL)_isMetalRemoteDebuggingEnabledWithEnvironmentVariables:(id)variables;
- (void)_addMetalValidationVariablesToEnvironment:(id)environment;
- (id)_createErrorForCode:(int)code recoverySuggestion:(id)suggestion;
- (BOOL)_overrideParametersForMetalRemoteDebuggingWithEnvironmentVariables:(id)variables outError:(id *)error;
- (void)_restoreLaunchStyleForMetalRemoteDebuggingWithEnvironmentVariables:(id)variables;
- (id)_preferredBuildableForSchemeCommand:(id)command buildParameters:(id)parameters;
- (BOOL)isWatchProxyDeviceForRunDestination:(id)destination;
- (BOOL)_tweakEnvironmentVariables:(id)variables buildParameters:(id)parameters buildableProductDirectories:(id)directories schemeCommand:(id)command schemeActionRecord:(id)record shouldSetupExtraDebuggingSupport:(BOOL)support extensionInfos:(id)infos outError:(id *)error;
- (void)_tweakCommandLineArgumentsBasedOnAnalysisToolServiceProvidedExecutable:(id)executable;
- (void)_checkForAnalysisToolServiceProvidedExecutableToSet;
- (id)_checkRunnablePathFromBuildParameters:(id)parameters buildableProductDirectories:(id)directories schemeActionRecord:(id)record outError:(id *)error;
- (BOOL)_checkRunDestination:(id *)destination buildParameters:(id)parameters displayName:(id)name schemeActionRecord:(id)record outError:(id *)error;
- (id)_checkRunnableBundleIdentifierFromRunDestination:(id)destination buildParameters:(id)parameters buildableProduct:(id)product;
- (id)_runnableFromBuildParameters:(id)parameters;
- (id)runOperationForSchemeOperationParameters:(id)parameters buildOperation:(id)operation buildParameters:(id)parameters buildableProductDirectories:(id)directories schemeCommand:(id)command schemeActionRecord:(id)record outError:(id *)error actionCallbackBlock:(id /* block */)block;
- (BOOL)_launchOptionIsSet:(unsigned long long)set;
- (void)_setLaunchOption:(unsigned long long)option enabled:(BOOL)enabled;
- (unsigned long long)launchAutomaticallySubstyleForBuildableProduct:(id)product;
- (BOOL)askForAppToLaunch;
- (void)setAskForAppToLaunch:(BOOL)launch;
- (void)dvt_awakeFromXMLUnarchiver:(id)xmlunarchiver;
- (BOOL)_shouldArchiveIOSInternalLauchStyle;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)setIgnoresPersistentStateOnLaunchFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setDebugDocumentVersioningFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setDebugXPCServicesFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setEnableMallocStackLoggingLiteForXPCServicesFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setCustomLaunchCommandFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setCustomLaunchCommandPauseAfterCommandsFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setDebugServiceExtensionFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setDebugServiceExtensionContentsStringFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setEnableGPUFrameCaptureModeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setEnableGPUValidationModeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setEnableGPUShaderValidationModeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setShowGraphicsOverviewFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setLogGraphicsOverviewFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setAllowLocationSimulationFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setAllowDeviceSensorReplayDataFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setShowNonLocalizedStringsFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setEnableTextLayoutIssuesDetectionFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setSimulatorIPhoneDisplayFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setSimulatorIPadDisplayFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setInternalIOSSubstitutionAppFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setInternalIOSLaunchStyleFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setLaunchAutomaticallySubstyleFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setViewDebuggingEnabledFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setQueueDebuggingEnabledFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setMemoryGraphOnResourceExceptionFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setConsoleModeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setStructuredConsoleModeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setPlaceholderRenderingEnabledFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setUseCustomWorkingDirectoryFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setAskForAppToLaunchFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (BOOL)needsNewSchemeVersionForAppDataPackage;
- (BOOL)needsNewSchemeVersionForLocationSimulation;
- (BOOL)needsNewSchemeVersionForInternalIOSLaunchStyleAndOthers;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)addDeviceAppData:(id)data fromXMLUnarchiver:(id)xmlunarchiver;
- (void)addLocationScenarioReference:(id)reference fromXMLUnarchiver:(id)xmlunarchiver;
- (void)addRoutingCoverageFileReference:(id)reference fromXMLUnarchiver:(id)xmlunarchiver;
- (void)addStoreKitConfigurationFileReference:(id)reference fromXMLUnarchiver:(id)xmlunarchiver;
- (void)addDeviceSensorReplayFileReference:(id)reference fromXMLUnarchiver:(id)xmlunarchiver;
- (void)primitiveInvalidate;
@end

#endif /* IDELaunchSchemeAction_h */
