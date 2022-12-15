//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"

@class DVTDispatchLock, DVTObservingToken, DVTStackBacktrace, IDEExecutionRunnableTracker, IDELaunchSession, IDELaunchSessionLogSection, IDERunOperationWorkerGroup, NSString;

@interface IDERunOperationWorker : NSObject <DVTInvalidation>
{
    NSString *_extensionIdentifier;
    IDELaunchSession *_launchSession;
    IDERunOperationWorkerGroup *_workerGroup;
    DVTObservingToken *_runnablePIDOberverToken;
    double _preflightAttemptInterval;
    BOOL _hasPerformedWorkerAction;
    DVTDispatchLock *_hasPerformedWorkerActionLock;
    unsigned long long _startTimeMonotonicNS;
    BOOL _isLongTerm;
    unsigned long long _preflightRetryAttempts;
    IDEExecutionRunnableTracker *_runnableTracker;
    IDELaunchSessionLogSection *_logSection;
}

+ (void)initialize;
// - (void).cxx_destruct;
@property(retain, nonatomic) IDELaunchSessionLogSection *logSection; // @synthesize logSection=_logSection;
@property BOOL isLongTerm; // @synthesize isLongTerm=_isLongTerm;
@property(retain, nonatomic) IDEExecutionRunnableTracker *runnableTracker; // @synthesize runnableTracker=_runnableTracker;
@property(readonly) IDELaunchSession *launchSession; // @synthesize launchSession=_launchSession;
@property(readonly) NSString *extensionIdentifier; // @synthesize extensionIdentifier=_extensionIdentifier;
- (void)primitiveInvalidate;
- (void)logInstallWatchApplicationFinishedWithError:(id)arg1;
- (void)logInstallingWatchApplication;
- (void)logInstallApplicationFinishedWithError:(id)arg1;
- (void)logInstallingApplication;
- (void)logLaunchApplicationFinishedWithError:(id)arg1;
- (void)logLaunchingApplication;
- (void)logUsingExistingApplicationInstance;
- (id)formattedLaunchParameters;
- (id)logSectionDetails;
- (id)logSectionTitle;
- (void)createLogSection;
@property(readonly, copy) NSString *description;
- (void)terminate;
- (id)notFinishedReasonWithDepth:(unsigned long long)arg1;
- (void)finishedWithError:(id)arg1;
- (void)finishRunnableTrackingWithAnalyticsAndError:(id)arg1;
- (id)reportCompletionToAnalyticsWithError:(id)arg1;
- (void)rerunPreflight;
- (void)recoveredFromPreflightError;
- (void)start;
- (void)_startWithRetrying:(char *)arg1;
@property(nonatomic) unsigned long long preflightRetryAttempts; // @synthesize preflightRetryAttempts=_preflightRetryAttempts;
- (void)performPostLaunchActions;
- (void)performWorkerAction;
- (BOOL)preflightWithError:(id *)arg1 recoverable:(char *)arg2 shouldRetry:(char *)arg3;
- (void)startNextWorkerFromCompletedWorker:(id)arg1 error:(id)arg2;
- (void)setWorkerGroup:(id)arg1;
- (id)workerGroup;
- (id)initWithExtensionIdentifier:(id)arg1 launchSession:(id)arg2;
- (id)init;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

