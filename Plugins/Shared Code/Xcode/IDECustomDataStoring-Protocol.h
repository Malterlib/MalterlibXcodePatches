//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTCustomDataStoring-Protocol.h"

@class DVTCustomDataSpecifier, IDEWorkspace;

@protocol IDECustomDataStoring <DVTCustomDataStoring>
- (void)addSpecifier:(DVTCustomDataSpecifier *)arg1 inWorkspace:(IDEWorkspace *)arg2 toSCMWithCompletionBlock:(void (^)(BOOL, NSError *))arg3;
- (void)scmStatusForSpecifier:(DVTCustomDataSpecifier *)arg1 completionBlock:(void (^)(unsigned long long, NSError *))arg2;
@end

