//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class IDEFindNavigatorPathControl, NSArray, NSString;

@protocol IDEFindNavigatorPathControlDelegate <NSObject>
- (void)pathControl:(IDEFindNavigatorPathControl *)arg1 userChoseValue:(id)arg2 forSegment:(id)arg3;
- (NSString *)pathControl:(IDEFindNavigatorPathControl *)arg1 titleForValue:(id)arg2 ofSegment:(id)arg3;
- (NSArray *)pathControl:(IDEFindNavigatorPathControl *)arg1 candidatesForSegment:(id)arg2;
- (id)pathControl:(IDEFindNavigatorPathControl *)arg1 valueForSegment:(id)arg2;
- (NSArray *)pathControlSegments:(IDEFindNavigatorPathControl *)arg1;
- (void)pathControlShouldRefresh:(IDEFindNavigatorPathControl *)arg1;
@end

