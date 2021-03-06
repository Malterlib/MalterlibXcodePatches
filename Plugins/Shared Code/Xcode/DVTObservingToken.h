//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//

#include "Shared.h"

#import "DVTCancellable-Protocol.h"

@class DVTStackBacktrace, NSString;

@interface DVTObservingToken : NSObject <DVTCancellable>
{
    BOOL _isCancelled;
    DVTStackBacktrace *_creationBacktrace;
}

+ (void)initialize;
@property(retain) DVTStackBacktrace *creationBacktrace; // @synthesize creationBacktrace=_creationBacktrace;
// - (void).cxx_destruct;
- (void)dealloc;
@property(readonly, getter=isCancelled) BOOL cancelled;
- (void)cancel;
- (void)_primitiveCancelObservation;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

