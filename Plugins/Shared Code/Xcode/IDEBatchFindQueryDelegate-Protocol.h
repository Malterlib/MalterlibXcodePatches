//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.13.sdk.sdk
//


@class IDEBatchFindAbstractQuery, IDEBatchFindAbstractResult, NSArray, NSSet;

@protocol IDEBatchFindQueryDelegate <NSObject>
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 didFinishGeneratingLazyChildrenOfResult:(IDEBatchFindAbstractResult *)arg2;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 didGenerateResults:(NSArray *)arg2;
- (void)findNavigatorQueryDidComplete:(IDEBatchFindAbstractQuery *)arg1;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 isStalledOnFilePaths:(NSSet *)arg2;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 progressUpdate:(long long)arg2;
@end

