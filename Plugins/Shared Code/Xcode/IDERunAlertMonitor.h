//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDERunAlertMonitor_h
#define IDERunAlertMonitor_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEWorkspaceTabController.h"

@class DVTStackBacktrace, NSString;

@interface IDERunAlertMonitor : NSObject<DVTInvalidation> {
  /* instance variables */
  IDEWorkspaceTabController *_workspaceTabController;
  id _currentLaunchSessionStateNotificationObserver;
  id _currentLaunchSessionTargetOutputNotificationObserver;
  id _pgoGenerationSucceededNotificationObserver;
  id _pgoGenerationFailedNotificationObserver;
}

@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;

/* instance methods */
- (id)initWithWorkspaceTabController:(id)controller;
- (id)_createInternalHideIfNoOutputAlertForRunCompleteEvent:(id)event;
- (BOOL)_launchSessionHasOutput:(id)output;
- (void)_launchSessionOutputStateChanged;
- (void)_runEvent:(id)event inWorkspace:(id)workspace modifyContext:(id)context;
- (BOOL)_hasDoneExecutionStarted;
- (void)_setHasDoneExecutionStarted;
- (BOOL)_hasDoneExecutionStopped;
- (void)_setHasDoneExecutionStopped;
- (BOOL)_hasDeterminedOutput;
- (void)_setHasDeterminedOutput:(id)output;
- (void)executionStart;
- (void)executionComplete;
- (void)primitiveInvalidate;
@end

#endif /* IDERunAlertMonitor_h */
