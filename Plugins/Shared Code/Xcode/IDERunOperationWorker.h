//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"

@class DVTDispatchLock, DVTStackBacktrace, IDEExecutionRunnableTracker, IDELaunchSession, IDERunOperationWorkerGroup, NSString;

@interface IDERunOperationWorker : NSObject <DVTInvalidation>
{
    NSString *_extensionIdentifier;
    IDELaunchSession *_launchSession;
    IDERunOperationWorkerGroup *_workerGroup;
    double _preflightAttemptInterval;
    BOOL _hasPerformedWorkerAction;
    DVTDispatchLock *_hasPerformedWorkerActionLock;
    BOOL _isLongTerm;
    unsigned long long _preflightRetryAttempts;
    IDEExecutionRunnableTracker *_runnableTracker;
}

+ (void)initialize;
@property BOOL isLongTerm; // @synthesize isLongTerm=_isLongTerm;
@property(retain, nonatomic) IDEExecutionRunnableTracker *runnableTracker; // @synthesize runnableTracker=_runnableTracker;
@property(readonly) IDELaunchSession *launchSession; // @synthesize launchSession=_launchSession;
@property(readonly) NSString *extensionIdentifier; // @synthesize extensionIdentifier=_extensionIdentifier;
// - (void).cxx_destruct;
- (void)primitiveInvalidate;
@property(readonly, copy) NSString *description;
- (void)terminate;
- (id)notFinishedReasonWithDepth:(unsigned long long)arg1;
- (void)finishedWithError:(id)arg1;
- (void)recoveredFromPreflightError;
- (void)start;
- (void)_startWithRetrying:(char *)arg1;
@property(nonatomic) unsigned long long preflightRetryAttempts; // @synthesize preflightRetryAttempts=_preflightRetryAttempts;
- (void)performWorkerAction;
- (BOOL)preflightWithError:(id *)arg1 recoverable:(char *)arg2 shouldRetry:(char *)arg3;
- (void)startNextWorkerFromCompletedWorker:(id)arg1 error:(id)arg2;
- (void)setWorkerGroup:(id)arg1;
- (id)initWithExtensionIdentifier:(id)arg1 launchSession:(id)arg2;
- (id)init;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

