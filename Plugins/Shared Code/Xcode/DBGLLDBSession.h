//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22522.0.0.0.0
//
#ifndef DBGLLDBSession_h
#define DBGLLDBSession_h
#import <Foundation/Foundation.h>

#include "IDEDebugSession.h"
#include "DBGDebugSessionBreakpointLifeCycleDelegate-Protocol.h"
#include "DBGLLDBLauncher.h"
#include "DBGLLDBRuntimeIssuesHelper.h"
#include "DBGSBBroadcaster-Protocol.h"
#include "DBGSBTarget-Protocol.h"
#include "IDEConsoleAdaptorDelegateProtocol-Protocol.h"

@class DVTDispatchLock, NSMutableArray, NSMutableString, NSString, DBGLLDBLauncher;
@protocol OS_dispatch_queue;

@interface DBGLLDBSession : IDEDebugSession<IDEConsoleAdaptorDelegateProtocol, DBGDebugSessionBreakpointLifeCycleDelegate> {
  /* instance variables */
  NSObject<DBGSBTarget> *_lldbTarget;
  NSObject<DBGSBBroadcaster> *_lldbBroadcaster;
  NSString *_prompt;
  DVTDispatchLock *_eventCallbackLock;
  NSMutableArray *_resumeActions;
  NSMutableArray *_actionsOnSessionThread;
  DVTDispatchLock *_actionsLock;
  double _lastPendingRunStartTime;
  BOOL _shouldSetIsLongRunningCommand;
  BOOL _isLongRunningCommand;
  NSObject<OS_dispatch_queue> *_isLongRunningCommandQueue;
  unsigned long long _previousHostUserTicks;
  unsigned long long _previousHostSystemTicks;
  unsigned long long _previousHostIdleTicks;
  unsigned long long _totalElapsedMicroSec;
  unsigned long long _previousElapsedMicroSec;
  unsigned long long _previousUsedMicroSec;
  struct __CFDictionary * _previousUsedMicroSecForThreadTable;
  unsigned long long _previousEnergy;
  double _CPUCapAverage;
  unsigned long long _CPUCapIntervalCounter;
  BOOL _profilingCPUCapForWatch;
  NSMutableString *_previousProfileDataString;
  DBGLLDBRuntimeIssuesHelper *_runtimeIssuesHelper;
  NSString *_memoryProfilingDisabledMessage;
}

@property BOOL hitFirstStop;
@property (nonatomic) BOOL profilingEnabled;
@property int profileScanType;
@property BOOL pauseRequested;
@property BOOL continueRequestedAfterExpression;
@property BOOL fetchEventRequested;
@property BOOL killCalled;
@property (retain) NSMutableArray *actionsWhenPaused;
@property BOOL continueAfterActions;
@property BOOL readyForActionsWhenPaused;
@property BOOL pendingRun;
@property BOOL shouldIssueKillAfterPause;
@property (retain) NSMutableArray *expressionsWhenPaused;
@property (readonly) DBGLLDBLauncher *launcher;
@property (copy) NSString *RPCServerCrashedOrExitedMessage;
@property BOOL isTracingOnDeviceAndTargetGotJetsam;
@property BOOL stopRequested;
@property void * sessionThreadIdentifier;

/* class methods */
+ (BOOL)supportsInvalidationPrevention;
+ (BOOL)breakpointHit:(void *)hit thread:(id)thread location:(id)location;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)selector;

/* instance methods */
- (BOOL)shouldStopForRuntimeIssuesBreakpointAtLocation:(id)location frame:(id)frame;
- (id)initWithDebugLauncher:(id)launcher;
- (void)_setupProfileEnergyCPUCap;
- (void)_setupProfileMemoryCap;
- (void)_setupProfileScanType:(id)type;
- (void)setTarget:(id)target;
- (id)lldbTarget;
- (id)lldbBroadcaster;
- (BOOL)_shouldRecordStatistics;
- (void)trackProcess;
- (id)prompt;
- (void)_setAndAppendPrompt:(id)prompt;
- (void)_setFlagsForTestingLongRunningCommand:(BOOL)command activityString:(id)string;
- (void)debuggerHasStandardOutput;
- (BOOL)currentThreadIsSessionThread;
- (void)_setSessionThreadIdentifier:(struct _opaque_pthread_t { long long x0; struct __darwin_pthread_handler_rec * x1; char x2[8176] } *)identifier;
- (void)_appendProcessControlAction:(int)action scope:(int)scope arg:(unsigned long long)arg;
- (void)_appendProcessControlAction:(int)action scope:(int)scope arg:(unsigned long long)arg location:(id)location;
- (void)requestStepIn;
- (void)requestStepInSuspendOtherThreads;
- (void)requestStepIntoInstruction;
- (void)requestStepOverLine;
- (void)requestStepOverInstruction;
- (void)requestStepOverSuspendOtherThreads;
- (void)requestStepOut;
- (void)requestPause;
- (void)requestContinue;
- (void)requestDetach;
- (void)writeOutProfileDataWhenPaused;
- (void)requestStop;
- (void)requestStepIntoCallSymbol:(id)symbol atLocation:(id)location;
- (void)requestContinueToLocation:(id)location;
- (void)_runActionOnSessionThreadWhenPaused:(id /* block */)paused;
- (id)bundleIDOfLaunchParameters;
- (void)requestFetchEvent;
- (void)simulateMetricPayloads;
- (void)requestUISnapshotRefresh;
- (void)simulateVehicularCrash;
- (void)_requestFetchEventOnSessionThread;
- (void)_putLLDBInThreadID:(unsigned long long)id stackFrameID:(unsigned long long)id restoreThreadFrameAfterWork:(BOOL)work toDoWork:(id /* block */)work;
- (void)executeConsoleCommand:(id)command threadID:(unsigned long long)id stackFrameID:(unsigned long long)id;
- (void)executeDebuggerCommand:(id)command threadID:(unsigned long long)id stackFrameID:(unsigned long long)id;
- (void)requestMovePCInStackFrame:(id)frame toLineNumber:(unsigned long long)number;
- (void)requestLoadSymbolsForStackFrameUUID:(id)uuid;
- (void)loadSymbolAtPath:(id)path;
- (void)requestLoadDylibAtPath:(id)path completionBlock:(id /* block */)block;
- (void)_addBreakpointHitCallback:(id)callback;
- (void)_removeBreakpointHitCallback:(int)callback;
- (void)_performBreakpointActions:(id)actions frame:(id)frame;
- (id)_logicalValueForBreakpointActionExpression:(id)expression;
- (id)_createNSStringForCString:(const char *)cstring;
- (void)printDescriptionOfDataValueToConsole:(id)console runAllThreads:(BOOL)threads completionHandler:(id /* block */)handler;
- (void)completeString:(id)string resultHandler:(id /* block */)handler;
- (void)addSessionThreadAction:(id /* block */)action;
- (void)_warnAndLogNoCurrentThreadForStep:(id)step;
- (BOOL)_logProcessControlStep:(id)step controlState:(int)state;
- (void)_recordPendingRun;
- (BOOL)_handleNextActionWithState:(int *)state;
- (void)_drainAllSessionThreadActionsWithActionsLockAlreadyTaken;
- (void)_drainAllSessionThreadActionsByFirstTakingActionsLock;
- (void)_quitWatchdogOnProcessState:(int *)state;
- (void)_killWatchdog;
- (void)_delayedSetRunningState;
- (id)commandsExpectingExpressions;
- (void)_setProfilingEnabled:(BOOL)enabled;
- (void)evaluateExpression:(id)expression threadID:(unsigned long long)id stackFrameID:(unsigned long long)id queue:(id)queue completionHandler:(id /* block */)handler;
- (void)evaluateExpression:(id)expression threadID:(unsigned long long)id stackFrameID:(unsigned long long)id queue:(id)queue resultBlock:(id /* block */)block;
- (void)evaluateExpression:(id)expression threadID:(unsigned long long)id stackFrameID:(unsigned long long)id queue:(id)queue options:(id)options completionHandler:(id /* block */)handler;
- (void)evaluateExpression:(id)expression threadID:(unsigned long long)id stackFrameID:(unsigned long long)id queue:(id)queue options:(id)options resultBlock:(id /* block */)block;
- (void)_evaluateExpressionFromSessionThread:(id)thread threadID:(unsigned long long)id stackFrameID:(unsigned long long)id queue:(id)queue options:(id)options resultBlock:(id /* block */)block completionHandler:(id /* block */)handler;
- (void)_handleSanitizerBreakpoint:(id)breakpoint stop:(long long)stop multiplier:(long long)multiplier;
- (void)_changeNameForBreakpoint:(id)breakpoint initial:(BOOL)initial;
- (void)createBreakpointIfNecessary:(id)necessary;
- (id)_createBreakpointFromFileBreakpoint:(id)breakpoint;
- (id)_createBreakpointFromSymbolicBreakpoint:(id)breakpoint;
- (id)_sbBreakpointForSymbolsNames:(id)names;
- (id)_createBreakpointFromTestFailureBreakpoint:(id)breakpoint;
- (id)_createBreakpointFromConstraintErrorBreakpoint:(id)breakpoint;
- (id)_createBreakpointFromSwiftErrorBreakpoint:(id)breakpoint;
- (id)_createBreakpointFromExceptionBreakpoint:(id)breakpoint;
- (id)_createBreakpointFromAddressBreakpoint:(id)breakpoint;
- (void)deleteWatchpoint:(id)watchpoint;
- (void)_deleteWatchpointFromLLDBSessionThread:(id)thread;
- (void)_handleBreakpointAddedEvent:(id)event;
- (id)_breakpointLocationFromSBBreakpointLocation:(id)location parentBreakpoint:(id)breakpoint;
- (void)_handleBreakpointRemovedEvent:(id)event;
- (void)_handleBreakpointLocationsResolvedEvent:(id)event;
- (void)_handleBreakpointEnabled:(BOOL)enabled event:(id)event;
- (void)_handleBreakpointEnabledEvent:(id)event;
- (void)_handleBreakpointDisabledEvent:(id)event;
- (void)_handleBreakpointLocationsRemovedEvent:(id)event;
- (void)deleteBreakpoint:(id)breakpoint;
- (void)_deleteBreakpointFromLLDBSessionThread:(id)thread breakpointLocations:(id)locations;
- (void)activationStateChanged:(BOOL)changed forBreakpoints:(id)breakpoints;
- (void)watchpointEnablementChanged:(id)changed;
- (void)_logBreakpointState:(id)state usingPrefix:(id)prefix;
- (void)_logBreakpointLocationState:(id)state usingPrefix:(id)prefix;
- (void)breakpointNameChanged:(id)changed;
- (void)breakpointConditionChanged:(id)changed;
- (void)breakpointIgnoreCountChanged:(id)changed;
- (BOOL)_allSanitizerBreakpointsInSameEnabledStateAsBreakpoint:(id)breakpoint;
- (void)breakpointEnablementChanged:(id)changed;
- (void)breakpointLocationConditionChanged:(id)changed;
- (void)breakpointLocationIgnoreCount:(id)count;
- (void)breakpointLocationEnablementChanged:(id)changed;
- (id)_sbBreakpointLocationForIDEBreakpointLocationID:(unsigned long long)id parentBreakpointID:(unsigned long long)id;
- (BOOL)consoleShouldTrackInputHistory;
- (id)supportedDataValueFormatsForDataValue:(id)value;
- (void)terminateCurrentDebuggerCommandIfNeeded;
- (const char *)_getProfileEnableString;
- (id)_stringFromHexString:(id)string;
- (void)processProfileDataString:(id)string;
- (void)appendProfileDataString:(id)string;
- (void)forceRefreshPausedStates;
- (id)symbolicatedFramesFromUUIDsAndOffsets:(id)offsets markRecorded:(BOOL)recorded;
- (id)dbgLLDBProcess;
- (void)_handleThreadEvent:(id)event;
- (void)assertIsLLDBSessionThread;
- (void)_refreshThreadListAndUpdateCurrentThread:(int *)thread;
- (void)_runPendingExpressionsAndPurgeList;
- (BOOL)_shouldIgnoreSigTermKill;
- (BOOL)_stopDueToMSLDuringAttach;
- (void)startMemoryDebuggingIfNeeded;
- (void)stopMemoryDebugging;
- (void)primitiveInvalidate;
- (id)_lldbProcessPlugnPacketSend:(const char *)send;
- (void)_setUpRecordingStackFramesForAttach;
- (int)errorCodeForExitDescription:(id)description;
- (void)_handleSessionThreadEndOfLifeWithExitCode:(long long)code exitDescription:(id)description;
- (void)_delayedTurnOnMemoryDebugging;
- (void)setValue:(id)value forGlobalVariable:(id)variable ofType:(id)type completionHandler:(id /* block */)handler queue:(id)queue;
- (id)memoryProfilingDisabledMessage;
- (BOOL)isProfilingEnabled;
@end

#endif /* DBGLLDBSession_h */
