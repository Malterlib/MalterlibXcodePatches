//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTIcon, NSArray, NSString, NSURL;
@protocol DVTPathCellItem;

@protocol DVTPathCellItem <NSObject>
@property(nonatomic, readonly) NSString *accessibilityIdentifier;
@property(nonatomic, readonly) NSURL *representedURLForExternalDrag;
@property(nonatomic, readonly) NSURL *representedURL;
@property(nonatomic, readonly) NSString *groupIdentifier;
- (BOOL)isEnabled;
- (BOOL)isVisible;
- (BOOL)isValid;
- (BOOL)representsDocumentRoot;
- (BOOL)isLeaf;
@property(nonatomic, readonly) NSArray *childItems;
@property(nonatomic, readonly) id <DVTPathCellItem> parentItem;
@property(nonatomic, readonly) id representedObject;
@property(nonatomic, readonly) NSString *pathComponentToolTip;
@property(nonatomic, readonly) DVTIcon *pathComponentIcon;
@property(nonatomic, readonly) NSString *pathComponentName;

@optional
@property(nonatomic, readonly) BOOL mergeDecendants;

// Remaining properties
@property(nonatomic, readonly) BOOL enabled;
@property(nonatomic, readonly) BOOL leaf;
@property(nonatomic, readonly) BOOL valid;
@property(nonatomic, readonly) BOOL visible;
@end

