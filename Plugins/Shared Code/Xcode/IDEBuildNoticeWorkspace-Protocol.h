//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

@class IDEWorkspaceNoticeSubsystem, NSArray;
@protocol DVTCancellable, DVTInvalidation, IDEBlueprintProvider, IDEBuildNoticeLogRecord, IDEBuildNoticeLogStore;

@protocol IDEBuildNoticeWorkspace
- (id <IDEBuildNoticeLogStore>)makeLogStoreForNoticeLogs;
- (id <DVTInvalidation>)observeActiveNoticeDomains:(void (^)(void))arg1;
- (id <DVTCancellable>)observeLatestBuildLogIdentityDidChange:(void (^)(void))arg1;
- (NSArray *)activeNoticeDomains;
@property(nonatomic, readonly) id <IDEBuildNoticeLogRecord> latestBuildLogRecordForBuildNoticeProvider;
@property(nonatomic, readonly) id <IDEBlueprintProvider> noticeWorkspaceWrappedContainer;
@property(nonatomic, readonly) IDEWorkspaceNoticeSubsystem *noticeSubsystem;
@end

