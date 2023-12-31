//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEDeviceInstallWorkspaceMonitor_h
#define IDEDeviceInstallWorkspaceMonitor_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEActivityLogSectionRecorder.h"
#include "IDELogStore.h"

@class DVTStackBacktrace, NSArray, NSString;

@interface IDEDeviceInstallWorkspaceMonitor : NSObject<DVTInvalidation>

@property (retain) NSString *appName;
@property (retain) IDELogStore *logStore;
@property (retain) IDEActivityLogSectionRecorder *logRecorder;
@property (retain) IDEActivityLogSectionRecorder *logSectionRecorder;
@property (retain) NSString *resultError;
@property (readonly) NSArray *logRecords;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (id)keyPathsForValuesAffectingLogRecords;

/* instance methods */
- (void)primitiveInvalidate;
- (void)loadDeviceInstallLogsForWorkspace:(id)workspace;
- (void)startActivityLogForAppNamed:(id)named deviceNamed:(id)named;
- (void)stopActivityLog;
- (void)addOperationToActivityLog:(id)log details:(id)details;
- (void)setResultErrorString:(id)string;
@end

#endif /* IDEDeviceInstallWorkspaceMonitor_h */
