//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class NSArray, NSImage, NSString, NSURL;
@protocol NSObject, DVTPathCellItem;

@protocol DVTPathCellItem <NSObject>
@property(readonly, nonatomic) NSString *accessibilityIdentifier;
@property(readonly, nonatomic) NSURL *representedURLForExternalDrag;
@property(readonly, nonatomic) NSURL *representedURL;
@property(readonly, nonatomic) NSString *groupIdentifier;
@property(readonly, nonatomic, getter=isEnabled) BOOL enabled;
@property(readonly, nonatomic, getter=isVisible) BOOL visible;
@property(readonly, nonatomic, getter=isValid) BOOL valid;
@property(readonly, nonatomic, getter=isLeaf) BOOL leaf;
@property(readonly, nonatomic) NSArray *childItems;
@property(readonly, nonatomic) id <NSObject, DVTPathCellItem> parentItem;
@property(readonly, nonatomic) id representedObject;
@property(readonly, nonatomic) NSString *toolTip;
@property(readonly, nonatomic) NSImage *image;
@property(readonly, nonatomic) NSString *name;
- (BOOL)representsDocumentRoot;

@optional
@property(readonly, nonatomic) BOOL mergeDecendants;
@end

