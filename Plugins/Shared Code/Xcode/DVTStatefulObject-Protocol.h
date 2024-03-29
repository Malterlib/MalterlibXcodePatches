//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTStateToken, NSDictionary, NSMutableDictionary;

@protocol DVTStatefulObject <NSObject>
+ (long long)version;
+ (void)configureStateSavingObjectPersistenceByName:(NSMutableDictionary *)arg1;
- (void)commitStateToDictionary:(NSMutableDictionary *)arg1;
- (void)revertStateWithDictionary:(NSDictionary *)arg1;
- (void)setStateToken:(DVTStateToken *)arg1;
- (DVTStateToken *)stateToken;

@optional
@property(readonly) BOOL canRevertWithEmptyStateDictionary;
@end

