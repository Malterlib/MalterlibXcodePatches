//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTInvalidation-Protocol.h"

@class DVTExtension, DVTFileDataType, DVTFilePath, NSArray;
@protocol IDEContainerGroupCore;

@protocol IDEContainerCore <NSObject, DVTInvalidation>
+ (NSArray *)containerDataFilePathsForFilePath:(DVTFilePath *)arg1;
+ (BOOL)supportsFilePersistence;
+ (DVTFileDataType *)containerFileType;
- (int)currentActivity;
- (DVTExtension *)containerExtension;
- (DVTFilePath *)filePath;
- (id <IDEContainerGroupCore>)rootGroup;
- (void)releaseContainerCore;
- (void)retainContainerCore;
- (id)initWithFilePath:(DVTFilePath *)arg1 extension:(DVTExtension *)arg2 error:(id *)arg3;
@end

