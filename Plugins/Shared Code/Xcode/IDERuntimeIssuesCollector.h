//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDERuntimeIssuesCollector_h
#define IDERuntimeIssuesCollector_h
#import <Foundation/Foundation.h>

#include "DVTOSLogTapDelegate-Protocol.h"
#include "IDEDebugSession.h"
#include "IDELaunchSession.h"
#include "IDERecordedThreadCollection.h"

@class DVTDispatchLock, DVTFuture, DVTObservingToken, NSArray, NSMutableArray, NSString, XREngineeringValueFormatter;
@protocol XREngineeringValue;

@interface IDERuntimeIssuesCollector : NSObject<DVTOSLogTapDelegate> {
  /* instance variables */
  IDEDebugSession *_debugSession;
  IDERecordedThreadCollection *_collectionForBreakpoint;
  DVTDispatchLock *_collectionForBreakpointLock;
  DVTFuture *_tokenFuture;
  NSString *_token;
  BOOL _useThirdPartyPredicate;
  DVTObservingToken *_debugSessionToken;
  DVTObservingToken *_coalescedStateToken;
  BOOL _stillReceivingIssues;
  DVTDispatchLock *_stillReceivingIssuesLock;
  NSObject<XREngineeringValue> *_alternateBacktrace;
  XREngineeringValueFormatter *_formatter;
  IDELaunchSession *_launchSession;
}

@property (readonly, copy) NSMutableArray *mutableIssueRecords;
@property (readonly, copy) NSArray *issueRecords;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (void)registerDelegate:(id)delegate forIdentifier:(id)identifier;
+ (void)unregisterDelegate:(id)delegate forIdentifier:(id)identifier;
+ (id)_allowListImages;

/* instance methods */
- (id)init;
- (id)helpURLForOnlyRPAC:(id)rpac launchSession:(id)session;
- (id)initWithLaunchSession:(id)session andLogSection:(id)section;
- (void)handleDVTOSLogMessages:(id)messages;
- (BOOL)shouldIncludeDVTOSLogMessage:(id)message;
- (id)_getBacktraceFromDelegate:(id)delegate orLog:(id)log;
- (id)_backtraceThreadsForLog:(id)log;
- (id)_locationFromThreads:(id)threads;
- (void)_parseLog:(id)log identifier:(id *)identifier message:(id *)message displayMessage:(id *)message delegate:(id *)delegate;
- (void)cancel;
- (BOOL)shouldDisplayRuntimeIssueWithSubsystem:(id)subsystem category:(id)category imagePath:(id)path environmentVariables:(id)variables;
@end

#endif /* IDERuntimeIssuesCollector_h */