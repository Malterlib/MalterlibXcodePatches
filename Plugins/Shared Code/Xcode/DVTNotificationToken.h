//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTCancellable-Protocol.h"

@class DVTStackBacktrace, NSNotificationCenter, NSString, _DVTNotificationReceiver;

@interface DVTNotificationToken : NSObject <DVTCancellable>
{
    NSNotificationCenter *_notificationCenter;
    id _observedObject;
    NSString *_name;
    _DVTNotificationReceiver *_receiver;
    DVTStackBacktrace *_creationBacktrace;
}

+ (void)initialize;
// - (void).cxx_destruct;
- (void)dealloc;
- (void)cancel;
@property(readonly, getter=isCancelled) BOOL cancelled;
- (id)initWithDistributedNotificationCenter:(id)arg1 receiver:(id)arg2 name:(id)arg3 observedObject:(id)arg4 suspensionBehavior:(unsigned long long)arg5;
- (id)initWithNotificationCenter:(id)arg1 receiver:(id)arg2 name:(id)arg3 observedObject:(id)arg4;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

