//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTInvalidation-Protocol.h"

@class NSSet;

@protocol IDEProvisionableProvider <DVTInvalidation>
@property(readonly, nonatomic) NSSet *provisionableDestinations;
@property(readonly, nonatomic) NSSet *provisionables;
@property(readonly, nonatomic) BOOL finishedLoading;
@end

