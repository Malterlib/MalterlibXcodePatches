//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class IDEContainerItem, NSSet;
@protocol IDEStructureEditingItem;

@protocol IDEStructureEditingItem <NSObject>
- (BOOL)hasAncestorInSet:(NSSet *)arg1;
- (id)actualRepresentedObject;
- (id <IDEStructureEditingItem>)parentStructureEditingItem;
- (long long)indexUnderParent;
- (IDEContainerItem *)representedContainerItem;
@end

