//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class SKScanIndex;

@protocol SKScanIndexDelegate <NSObject>
- (void)scanIndexDidFinishScanning:(SKScanIndex *)arg1;
- (void)scanIndexIsScanning:(SKScanIndex *)arg1 completed:(long long)arg2 remaining:(long long)arg3;
- (void)scanIndexStartedScanning:(SKScanIndex *)arg1;
@end

