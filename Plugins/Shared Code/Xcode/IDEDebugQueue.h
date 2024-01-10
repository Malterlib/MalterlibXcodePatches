//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEDebugQueue_h
#define IDEDebugQueue_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEDebugNavigableModel-Protocol.h"
#include "IDEDebugProcess.h"
#include "IDELaunchSession.h"
#include "IDEThread.h"

@class DVTStackBacktrace, NSArray, NSMutableArray, NSString, IDEThread, IDEDebugProcess;

@interface IDEDebugQueue : NSObject<IDEDebugNavigableModel, DVTInvalidation> {
  /* instance variables */
  NSString *_type;
  BOOL _displayNameComputed;
  NSMutableArray *_delayedInvalidationChildren;
}

@property (retain, nonatomic) IDEThread *recordedThread;
@property (readonly, nonatomic) IDEDebugProcess *parentProcess;
@property (copy, nonatomic) NSString *name;
@property (readonly, nonatomic) NSString *displayName;
@property (readonly, nonatomic) unsigned long long numberOfPendingBlocks;
@property (copy, nonatomic) NSArray *threads;
@property (copy, nonatomic) NSArray *pendingBlocksThreads;
@property (readonly, nonatomic) BOOL recorded;
@property BOOL toBeInvalidated;
@property (readonly, copy) NSString *associatedProcessUUID;
@property (readonly) IDELaunchSession *launchSession;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;

/* class methods */
+ (void)initialize;
+ (BOOL)_queueNameBelongsToConcurrentQueues:(id)queues;
+ (id)keyPathsForValuesAffectingRecorded;
+ (id)keyPathsForValuesAffectingDisplayName;

/* instance methods */
- (id)initWithParentProcess:(id)process name:(id)name type:(id)type recordedThread:(id)thread;
- (BOOL)isEqual:(id)equal;
- (BOOL)isRecorded;
- (void)setPrimitiveThreads:(id)threads;
- (void)primitiveInvalidate;
@end

#endif /* IDEDebugQueue_h */