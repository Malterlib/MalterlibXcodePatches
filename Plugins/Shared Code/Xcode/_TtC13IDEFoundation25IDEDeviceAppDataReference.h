//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef _TtC13IDEFoundation25IDEDeviceAppDataReference_h
#define _TtC13IDEFoundation25IDEDeviceAppDataReference_h
#import <Foundation/Foundation.h>

#include "DVTXMLUnarchiving-Protocol.h"

@class NSString;

@interface IDEFoundation_IDEDeviceAppDataReference : NSObject<DVTXMLUnarchiving> // (Swift)

@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (nonatomic, copy) NSString *resolvedPath;
@property (nonatomic, copy) NSString *appDataBundleId;
@property (nonatomic, copy) NSString *appDataDownloadDate;

/* instance methods */
- (id)initFromXMLUnarchiver:(id)xmlunarchiver archiveVersion:(float)version;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)setResolvedPathFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setAppDataBundleIdFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setAppDataDownloadDateFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (id)init;
@end

#endif /* _TtC13IDEFoundation25IDEDeviceAppDataReference_h */
