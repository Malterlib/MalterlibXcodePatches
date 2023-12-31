//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDELaunchSession_h
#define IDELaunchSession_h
#import <Foundation/Foundation.h>

#include "IDEConsoleAdaptorObserverProtocol-Protocol.h"
#include "IDEDebugSession.h"
#include "IDEExecutionEnvironment.h"
#include "IDEExecutionTracker.h"
#include "IDELaunchParametersSnapshot.h"
#include "IDELaunchSession.h"
#include "IDELaunchSessionLogger.h"
#include "IDELocationSimulator.h"
#include "IDERunDestination.h"
#include "IDERuntimeIssueRecordProcessInfo.h"
#include "IDERuntimeIssuesCollector.h"
#include "IDESchemeActionAnalytics-Protocol.h"
#include "IDESchemeActionRecord.h"
#include "IDESchemeCommand.h"
#include "XCTHDebugSession-Protocol.h"
#include "XCTHLaunchSession-Protocol.h"
#include "XCTHRunDestination-Protocol.h"

@class DVTFileDataType, DVTFuture, DVTObservingToken, DVTPerformanceMetric, NSArray, NSDictionary, NSError, NSMapTable, NSMutableArray, NSMutableSet, NSNumber, NSSet, NSString, XCTestConfiguration, IDEExecutionEnvironment;
@protocol IDETraceInferiorSession;

@interface IDELaunchSession : NSObject<XCTHLaunchSession, IDESchemeActionAnalytics, IDEConsoleAdaptorObserverProtocol> {
  /* instance variables */
  NSMutableSet *_shellXPCLaunchSessions;
  DVTPerformanceMetric *_xpcDebuggingMetric;
  int _setupPIDForDiagnostics;
  BOOL _allConsoleAdaptorsTerminated;
  BOOL _hasAlreadyOutputExitString;
  DVTFuture *_appExtensionInstallFuture;
  DVTObservingToken *_appExtensionObserverToken;
  NSMutableSet *_debugserverFileHandles;
  unsigned long long _launchTimeInContinuousTime;
}

@property (retain) NSError *alertError;
@property long long state;
@property int runnablePID;
@property (readonly) NSSet *consoleAdaptors;
@property (retain) XCTestConfiguration *testConfiguration;
@property (retain) NSObject<XCTHDebugSession> *currentDebugSession;
@property (copy) NSString *runnableDisplayName;
@property BOOL hasExitCode;
@property long long exitCode;
@property BOOL hasCrashed;
@property (retain) NSNumber *terminatingSignal;
@property (readonly) NSObject<XCTHRunDestination> *runDestination;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (nonatomic, readonly) BOOL isForXCTestToolHostedTesting;
@property (readonly, copy) NSMutableSet *kvoConsoleAdaptors;
@property (retain, nonatomic) NSMapTable *targetConsoleAdaptorToTerminationToken;
@property (retain, nonatomic) DVTObservingToken *codeModulesObserver;
@property (retain, nonatomic) NSMutableArray *mutableDebuggingAdditions;
@property (retain, nonatomic) DVTObservingToken *storeKitModulesObserver;
@property (copy) NSArray *xpcServices;
@property (readonly) IDEExecutionEnvironment *executionEnvironment;
@property (retain) IDESchemeActionRecord *schemeActionRecord;
@property (retain) IDEExecutionTracker *executionTracker;
@property (copy) NSArray *debugSessions;
@property (readonly, copy) NSMutableArray *mutableDebugSessions;
@property (readonly, nonatomic) BOOL debuggerShouldAttachToTarget;
@property (nonatomic) BOOL wasDetached;
@property (retain) NSObject<IDETraceInferiorSession> *currentTraceInferiorSession;
@property (readonly) BOOL isCurrentlyTracing;
@property (readonly, copy) NSArray *debuggingAdditions;
@property (readonly) NSSet *gaugeLocations;
@property (readonly) NSMutableSet *mutableGaugeLocations;
@property (retain) IDELaunchParametersSnapshot *launchParameters;
@property (readonly, nonatomic) DVTFileDataType *runnableType;
@property BOOL shouldHidePID;
@property int simulatorPID;
@property (retain) IDESchemeCommand *schemeCommand;
@property (readonly) int CPUType;
@property (readonly, nonatomic) int launchSessionOutputState;
@property (readonly) IDELocationSimulator *locationSimulator;
@property (readonly) BOOL supportsDebugSession;
@property (copy) NSString *explicitActivityViewTitle;
@property BOOL representsAnXPCService;
@property int parentPID;
@property (readonly, nonatomic) IDELaunchSession *parentLaunchSession;
@property (readonly, nonatomic) NSSet *xpcLaunchSessions;
@property (readonly, nonatomic) NSArray *frameworkNamesIncludingExtensionsLinkedByExecutableForAllSlices;
@property (retain) IDERuntimeIssuesCollector *runtimeIssuesCollector;
@property (readonly) NSString *noticeSourceID;
@property (readonly, nonatomic) IDERuntimeIssueRecordProcessInfo *runtimeIssueRecordProcessInfo;
@property (readonly) IDELaunchSessionLogger *logger;
@property (readonly) NSDictionary *analyticsDictionary;

/* class methods */
+ (void)initialize;
+ (void)_setLaunchSession:(id)session forReference:(id)reference;
+ (id)launchSessionForReference:(id)reference;
+ (id)createLaunchSessionForDebuggingAddition:(id)addition inWorkspace:(id)workspace launchParameters:(id)parameters runnableDisplayName:(id)name runDestination:(id)destination;
+ (id)createLaunchSessionForFieldReportPoint:(id)point inWorkspace:(id)workspace;
+ (void)terminateLaunchSession:(id)session;
+ (void)terminateLaunchSession:(id)session inWorkspace:(id)workspace;
+ (BOOL)automaticallyNotifiesObserversOfLaunchSessionOutputState;
+ (id)keyPathsForValuesAffectingIsCurrentlyTracing;
+ (id)keyPathsForValuesAffectingIsAlive;
+ (BOOL)_registerLaunchSession:(id)session asSoleRecipientForAppExt:(id)ext error:(id *)error;
+ (BOOL)_unregisterLaunchSession:(id)session asSoleRecipientForAppExt:(id)ext;
+ (BOOL)_isLaunchSession:(id)session soleRecipientForAppExt:(id)ext;
+ (id)languageArguments;
+ (id)notificationPayloadForFilePath:(id)path;
+ (id)watchLaunchOptionsForLaunchParameters:(id)parameters;

/* instance methods */
- (void)processRuntimeIssueRecords:(id)records;
- (id)initWithExecutionEnvironment:(id)environment launchParameters:(id)parameters runnableDisplayName:(id)name runnableType:(id)type runDestination:(id)destination;
- (id)initWithExecutionEnvironment:(id)environment launchParameters:(id)parameters runnableDisplayName:(id)name runnableType:(id)type runDestination:(id)destination logger:(id)logger;
- (void)dealloc;
- (void)setRunnablePIDWithDiagnostics:(int)diagnostics logSection:(id)section andCompletionHandler:(id /* block */)handler;
- (void)setRunnablePIDWithoutDiagnostics:(int)diagnostics;
- (void)_emitLaunchSignpostIfNecessary;
- (void)addConsoleAdaptor:(id)adaptor;
- (void)removeConsoleAdaptor:(id)adaptor;
- (void)receiveConsoleItems:(id)items fromConsoleAdaptor:(id)adaptor;
- (void)_handleConsoleAdaptorOutputTerminated:(id)terminated;
- (void)_removeConsoleAdaptorObservations:(id)observations;
- (void)_didStart;
- (void)startDebugLaunchOfDaemonWithLaunchd;
- (BOOL)_extensionHasLinkedFrameworkNameMatchCriteria:(id)criteria;
- (id)_createDebuggingAdditionForExtension:(id)extension availableBinariesNames:(id)names anyMatchCriteriaFailuresDueToAvailableBinaries:(BOOL *)binaries;
- (id)_frameworkNamesIncludingExtensionsFromLoadedCodeModules;
- (void)_invalidateExecutionEnvironment;
- (void)_willExpire;
- (BOOL)isAlive;
- (id)referenceWhenAlive;
- (id)existingGaugeLocationForURL:(id)url;
- (void)addNewGaugeLocation:(id)location;
- (void)addNewGaugeLocation:(id)location withPriority:(unsigned long long)priority;
- (id)debuggingAdditionMatchingID:(id)id;
- (id)debuggingAdditionMatchingClass:(id)class;
- (id)_frameworkNamesIncludingExtensionsLinkedByExecutableForCpuType:(int)type;
- (void)cancelShellXPCServices:(id)xpcservices;
- (void)_cancelAllXPCRelatedWork;
- (id)_createLaunchSessionForXPCServiceName:(id)name withLaunchParameters:(id)parameters;
- (id)_environmentVariablesWithTestingFilteredOut:(id)out;
- (void)_startObservingXPCServicesAndAppExtensions;
- (id)_tweakEnvironmentVariablesForXPCDebugging;
- (void)_startObservingXPCServicesAndAppExtensionsStage2;
- (void)_performSiriQueryIfNeeded;
- (void)_startXPCPostLaunchActions;
- (void)_cancelXPCPostLaunchActions;
- (id)_findShellXPCLaunchSessionForServiceName:(id)name;
- (void)_fillUpXPCServiceWithPid:(int)pid forServiceName:(id)name;
- (void)createXPCLaunchSessionsShells:(id)shells launchParameter:(id)parameter;
- (void)_handleXPCServiceObservation:(id)observation;
- (void)handleDebugXPCService:(id)xpcservice logSection:(id)section useRegistration:(BOOL)registration;
- (void)performanceMetric_xpcDebuggingStarted;
- (void)performanceMetric_xpcDebuggingCompleted;
- (void)performanceMetric_xpcDebuggingCheckpointWithLabel:(id)label;
- (id)storeKitConfigurationSync;
- (void)_checkForLoadedStoreKitFramework;
- (id)_storeKitConfigurationSyncFuture;
- (id)setupAppStoreServices;
@end

#endif /* IDELaunchSession_h */
