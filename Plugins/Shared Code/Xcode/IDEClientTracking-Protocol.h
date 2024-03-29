//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class NSArray, NSString;
@protocol IDEClientTrackingToken;

@protocol IDEClientTracking <NSObject>
@property(readonly) BOOL isCancelling;
- (void)cancelTrackedClients;
- (NSArray *)clientsNotSupportingCancellation;
- (NSArray *)clientsRequiringCancellationPrompt;
- (id <IDEClientTrackingToken>)registerUncancellableClientWithName:(NSString *)arg1 terminationSignpost:(void (^)(void (^)(void)))arg2;
- (id <IDEClientTrackingToken>)registerClientWithName:(NSString *)arg1 promptForCancellation:(BOOL)arg2 terminationSignpost:(void (^)(void (^)(void)))arg3 cancellationBlock:(void (^)(void))arg4;
@end

