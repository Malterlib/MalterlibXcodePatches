//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class IDEBatchFindAbstractQuery, IDEBatchFindAbstractResult, NSArray, NSSet;

@protocol IDEBatchFindQueryDelegate <NSObject>
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 didFinishGeneratingLazyChildrenOfResult:(IDEBatchFindAbstractResult *)arg2;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 didGenerateResults:(NSArray *)arg2;
- (void)findNavigatorQueryDidComplete:(IDEBatchFindAbstractQuery *)arg1 totalWork:(CDStruct_912cb5d2)arg2 duration:(double)arg3;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 isStalledOnFilePaths:(NSSet *)arg2;
- (void)findNavigatorQuery:(IDEBatchFindAbstractQuery *)arg1 progressUpdate:(long long)arg2;
@end

