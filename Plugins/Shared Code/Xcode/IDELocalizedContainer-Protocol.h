//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTModelObject-Protocol.h"

@class DVTLocale, NSArray, NSString;

@protocol IDELocalizedContainer <DVTModelObject>
@property(readonly) BOOL isLocalizable;
@property(readonly, copy) NSString *name;
- (DVTLocale *)developmentRegion;
- (NSArray *)localizations;
@end

