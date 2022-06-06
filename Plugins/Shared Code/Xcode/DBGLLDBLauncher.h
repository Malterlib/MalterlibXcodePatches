//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDERunOperationPathWorker.h"

#import "IDEConsoleAdaptorDelegateProtocol-Protocol.h"

@class DBGLLDBSession, DVTDispatchLock, NSObject, NSString;
@protocol DBGSBDebugger, OS_dispatch_queue;

@interface DBGLLDBLauncher : IDERunOperationPathWorker <IDEConsoleAdaptorDelegateProtocol>
{
    id <DBGSBDebugger> _lldbDebugger;
    NSString *_lastKnownDebuggerPrompt;
    BOOL _ignorePromptOnce;
    NSObject<OS_dispatch_queue> *_executeLLDBCommandQueue;
    BOOL _hasFinishedRunning;
    BOOL _shouldProceedToAttach;
    DVTDispatchLock *_lifeCycleLock;
    NSString *_remoteInstallPath;
    BOOL _lldbTargetFromLocalPath;
    BOOL _useOnlyStandardLLDBFramework;
    BOOL _hasQueriedLLDBRPCUserDefaults;
    BOOL _terminateCalled;
    BOOL _forceKillingLLDBRPCServer;
    int _lldbRPCServerPID;
    DBGLLDBSession *_debugSession;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (void)initialize;
// - (void).cxx_destruct;
@property BOOL forceKillingLLDBRPCServer; // @synthesize forceKillingLLDBRPCServer=_forceKillingLLDBRPCServer;
@property(retain) DBGLLDBSession *debugSession; // @synthesize debugSession=_debugSession;
@property(readonly) int lldbRPCServerPID; // @synthesize lldbRPCServerPID=_lldbRPCServerPID;
@property(readonly) BOOL terminateCalled; // @synthesize terminateCalled=_terminateCalled;
- (void)primitiveInvalidate;
- (id)_storeKitConfigurationFileSync;
- (id)logSectionDetails;
- (id)logSectionTitle;
- (void)_logDebugOptions;
- (void)terminate;
- (void)start;
- (void)removeTrackedName:(id)arg1 addTrackedPID:(unsigned long long)arg2 forDeviceIdentifier:(id)arg3;
- (void)removeTrackedPID:(unsigned long long)arg1 forDeviceIdentifier:(id)arg2;
- (void)_warnSlowLaunch;
- (void)_warnSlowLaunchReadFromMemory;
- (void)_warnSlowLaunchDSYMForUUIDEnabled;
- (void)_setupSearchPaths:(id)arg1;
- (void)_addExtraModules:(id)arg1;
- (void)_consumeEventAfterConnectToDebugServer:(id)arg1;
- (void)_setMiscHandleCommands:(id)arg1;
- (void)_setPlatformForStart:(id)arg1;
- (id)_devicePathSubstitutionPairsString;
- (id)_tryWithAnotherArchitectureOnBinaryPath:(id)arg1;
- (id)_doRegularDebugWithTarget:(id)arg1 usingDebugServer:(BOOL)arg2 errTargetString:(id)arg3 outError:(id *)arg4;
- (BOOL)_configureConsoleMode:(id)arg1 forLaunchInfo:(id)arg2;
- (const char *)UTF8StringFromPotentialString:(id)arg1;
- (void)_createTargetConsoleAdaptorForPTY:(id)arg1;
- (id)errorForLLDBLaunchError:(id)arg1 target:(id)arg2;
- (id)_doAttachWithTarget:(id)arg1 childPID:(unsigned long long *)arg2 outError:(id *)arg3;
- (BOOL)_shouldProceedAttachToPID:(unsigned long long)arg1;
- (BOOL)_shouldProceedAttachToName:(id)arg1;
- (void)_setErrorDueToDebugMoreThanOnce:(id)arg1 code:(int)arg2;
- (id)_errorMessageForAttachingToPID:(unsigned long long)arg1;
- (id)_errorMessageForAttachingToName:(id)arg1;
- (id)_errorStringFromLLDBError:(id)arg1;
- (void)_logSetUID:(unsigned int)arg1;
- (id)_modifyMessageForDisplay:(id)arg1 suggestedErrorCode:(int *)arg2;
- (id)_launchErrorForDescription:(id)arg1 message:(id)arg2 rawErrorMessage:(id)arg3;
- (id)parseConsoleOutputFromOriginalOutput:(id)arg1;
- (id)parseConsoleInputFromOriginalInput:(id)arg1;
- (void)_executeLLDBCommands:(id)arg1;
- (void)_createBasicDebuggerObjects:(id)arg1;
- (BOOL)_createDebuggerConsoleAdaptor:(id *)arg1 launchParameters:(id)arg2;
- (void)_sourceLLDBInitFile:(id)arg1;
- (id)lldbDebugger;
- (void)setFinishedRunning:(id)arg1;
- (void)_logToConsoleForUserActions:(id)arg1;
- (void)_logDebugStringFromLLDB:(const char *)arg1;
- (void)forceKillLLDBRPCServer;
- (BOOL)useOnyStandardLLDBFramework;
- (id)initWithExtensionIdentifier:(id)arg1 launchSession:(id)arg2;

@end

