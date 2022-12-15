//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@class DVTDevice, DVTDeviceCapability, DVTExtension;

@interface DVTDeviceService : NSObject
{
    DVTDevice *_device;
    DVTExtension *_extension;
    DVTDeviceCapability *_currentCapability;
}

+ (id)capability;
// - (void).cxx_destruct;
@property(readonly) DVTDeviceCapability *currentCapability; // @synthesize currentCapability=_currentCapability;
@property(readonly) DVTDevice *device; // @synthesize device=_device;
- (id)initForDevice:(id)arg1 extension:(id)arg2 capability:(id)arg3;

@end

