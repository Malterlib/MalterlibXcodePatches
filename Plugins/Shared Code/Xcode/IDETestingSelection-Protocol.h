//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "IDESelectionSource-Protocol.h"

@class IDETest, NSSet, NSString;
@protocol IDETestCollection;

@protocol IDETestingSelection <IDESelectionSource>

@optional
@property(readonly) NSString *selectionUIContext;
@property(readonly) id <IDETestCollection> selectedTests;
- (NSSet *)selectedTestsAndTestables;
- (IDETest *)selectedTest;
@end

