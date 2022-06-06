//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@class DVTStackBacktrace, NSArray, NSError, NSMutableArray;

@interface DVTOperation : NSOperation
{
    struct DVTUnfairLock _lock;
    CDUnknownBlockType _block;
    NSMutableArray *_cancellationBlockTokens;
    NSMutableArray *_finishingTokens;
    unsigned int _state:2;
    unsigned int _isFinishingAllowed:1;
    unsigned int _isCancelled:1;
    NSError *_error;
    NSArray *_warnings;
    DVTStackBacktrace *_creationBacktrace;
}

+ (id)unfinishedOperations;
+ (BOOL)callsMainIfCancelled;
+ (BOOL)removesDependenciesWhenFinished;
+ (BOOL)_removesDependenciesAfterFinish;
+ (id)operationWithAsynchronousBlock:(CDUnknownBlockType)arg1;
+ (id)operationWithSynchronousBlock:(CDUnknownBlockType)arg1;
+ (id)operationWithBlock:(CDUnknownBlockType)arg1;
// - (void).cxx_destruct;
@property(readonly) DVTStackBacktrace *creationBacktrace; // @synthesize creationBacktrace=_creationBacktrace;
@property(copy) NSArray *warnings; // @synthesize warnings=_warnings;
@property(copy) NSError *error; // @synthesize error=_error;
- (id)notFinishedReasonWithDepth:(unsigned long long)arg1;
- (id)stateString;
- (void)enumerateUsingBlock:(CDUnknownBlockType)arg1;
- (void)_enumerateWithStop:(char *)arg1 usingBlock:(CDUnknownBlockType)arg2;
- (void)allowFinishForToken:(id)arg1;
- (id)disallowFinishWithReason:(id)arg1;
- (void)start;
- (void)_postflightMain;
- (void)main;
- (BOOL)_preflightMain;
- (BOOL)isFinished;
- (BOOL)isExecuting;
- (BOOL)isReady;
- (void)cancel;
- (BOOL)isCancelled;
- (BOOL)unregisterCancellationBlockForToken:(id)arg1;
- (id)registerCancellationBlock:(CDUnknownBlockType)arg1;
- (id)debugDescription;
- (id)description;
- (void)dealloc;
- (id)init;
- (void)trackFuture:(id)arg1;
- (void)trackFuture:(id)arg1 cancel:(BOOL)arg2 error:(BOOL)arg3;

@end

