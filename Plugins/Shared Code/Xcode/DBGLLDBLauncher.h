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
    DVTDispatchLock *_lifeCycleLock;
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
- (id)_storeKitConfigurationFileSync;
- (void)primitiveInvalidate;
- (void)terminate;
- (void)start;
- (void)_warnSlowLaunch;
- (void)_warnSlowLaunchReadFromMemory;
- (void)_warnSlowLaunchDSYMForUUIDEnabled;
- (void)_setupSearchPaths:(id)arg1;
- (void)_addExtraModules:(id)arg1;
- (id)_consumeEventAfterConnectToDebugServer:(id)arg1 lldbTarget:(id)arg2 launchParameters:(id)arg3;
- (void)_setMiscHandleCommands:(id)arg1;
- (void)_setPlatformForStart:(id)arg1;
- (id)devicePathSubstitutionPairsString;
- (id)_remoteInstallPath:(id)arg1;
- (id)_tryWithAnotherArchitectureOnBinaryPath:(id)arg1;
- (id)_doRegularDebugWithTarget:(id)arg1 usingDebugServer:(BOOL)arg2 errTargetString:(id)arg3 outError:(id *)arg4;
- (const char *)UTF8StringFromPotentialString:(id)arg1;
- (void)_createTargetConsoleAdaptorForPTY:(id)arg1;
- (id)errorForLLDBLaunchError:(id)arg1 target:(id)arg2;
- (id)_doAttachWithTarget:(id)arg1 childPID:(unsigned long long *)arg2 outError:(id *)arg3;
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

