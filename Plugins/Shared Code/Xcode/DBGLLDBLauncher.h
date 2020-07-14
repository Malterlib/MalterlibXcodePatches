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
    DVTDispatchLock *_lifeCycleLock;
    BOOL _useOnlyStandardLLDBFramework;
    BOOL _hasQueriedLLDBRPCUserDefaults;
    BOOL _terminateCalled;
    int _lldbRPCServerPID;
    DBGLLDBSession *_debugSession;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (void)initialize;
// - (void).cxx_destruct;
@property(retain) DBGLLDBSession *debugSession; // @synthesize debugSession=_debugSession;
@property(readonly) int lldbRPCServerPID; // @synthesize lldbRPCServerPID=_lldbRPCServerPID;
@property(readonly) BOOL terminateCalled; // @synthesize terminateCalled=_terminateCalled;
- (id)_storeKitConfigurationFileSync;
- (void)primitiveInvalidate;
- (void)terminate;
- (void)start;
- (void)_messageTrace:(id)arg1;
- (void)_setupSearchPaths:(id)arg1;
- (void)_addExtraModules:(id)arg1;
- (id)_consumeEventAfterConnectToDebugServer:(id)arg1 lldbTarget:(id)arg2 launchParameters:(id)arg3;
- (void)_setMiscHandleCommands:(id)arg1;
- (void)_setPlatformForStart:(id)arg1;
- (id)devicePathSubstitutionPairsString;
- (id)_tryWithAnotherArchitectureOnBinaryPath:(id)arg1;
- (void)_reportDiagnosticStatistics:(id)arg1;
- (id)_doRegularDebugWithTarget:(id)arg1 usingDebugServer:(BOOL)arg2 errTargetString:(id)arg3;
- (const char *)UTF8StringFromPotentialString:(id)arg1;
- (void)_createTargetConsoleAdaptorForPTY:(id)arg1;
- (void)_reportTarget:(id)arg1 failedToLaunchError:(id)arg2;
- (id)_doAttachWithTarget:(id)arg1 childPID:(unsigned long long *)arg2;
- (void)_logSetUID:(unsigned int)arg1;
- (id)_modifyMessageForDisplay:(id)arg1;
- (void)_showLaunchErrorForDescription:(id)arg1 message:(id)arg2 rawErrorMessage:(id)arg3;
- (id)parseConsoleOutputFromOriginalOutput:(id)arg1;
- (id)parseConsoleInputFromOriginalInput:(id)arg1;
- (void)_executeLLDBCommands:(id)arg1;
- (void)_createBasicDebuggerObjects:(id)arg1;
- (BOOL)_createDebuggerConsoleAdaptor:(id *)arg1 launchParameters:(id)arg2;
- (void)_sourceLLDBInitFile:(id)arg1;
- (id)lldbDebugger;
- (void)setFinishedRunning;
- (void)_logToConsoleForUserActions:(id)arg1;
- (void)_logDebugStringFromLLDB:(const char *)arg1;
- (BOOL)useOnyStandardLLDBFramework;
- (id)initWithExtensionIdentifier:(id)arg1 launchSession:(id)arg2;

@end

