//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTInvalidation-Protocol.h"

@class IDEActivityLogSection;

@protocol IDEIssueLogDataSource <NSObject, DVTInvalidation>
@property(readonly) IDEActivityLogSection *issueLog;
- (void)analyzeModelForIssues;
@end

