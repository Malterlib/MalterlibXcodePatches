//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, NSString;

@interface DVTGeneratedContentProvider : NSObject <DVTInvalidation>
{
}

+ (void)initialize;
+ (id)sourceFilePathForGeneratedContentURL:(id)arg1;
- (void)primitiveInvalidate;
- (void)generateContentForURL:(id)arg1 waitingBlock:(CDUnknownBlockType)arg2 completionBlock:(CDUnknownBlockType)arg3;
@property(readonly) NSString *displayName;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

