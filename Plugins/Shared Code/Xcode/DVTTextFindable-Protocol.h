//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTDocumentLocation, DVTFindDescriptor, DVTFindResult;

@protocol DVTTextFindable <NSObject>
- (DVTFindResult *)findStringMatchingDescriptor:(DVTFindDescriptor *)arg1 backwards:(BOOL)arg2 from:(DVTDocumentLocation *)arg3 to:(DVTDocumentLocation *)arg4;

@optional
@property unsigned long long supportedMatchingOptions;
- (long long)compareFindableLocation:(DVTDocumentLocation *)arg1 withLocation:(DVTDocumentLocation *)arg2;
@end

