//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDESchemeActionSDKRecord_h
#define IDESchemeActionSDKRecord_h
#import <Foundation/Foundation.h>

#include "IDESchemeActionAnalytics-Protocol.h"

@class NSDictionary, NSString;

@interface IDESchemeActionSDKRecord : NSObject<IDESchemeActionAnalytics>

@property (readonly, copy) NSDictionary *dictionaryRepresentation;
@property (readonly, copy) NSString *displayName;
@property (readonly, copy) NSString *canonicalName;
@property (readonly, copy) NSString *operatingSystemVersion;
@property (readonly) BOOL internal;
@property (readonly) NSDictionary *analyticsDictionary;

/* instance methods */
- (id)initWithDisplayName:(id)name canonicalName:(id)name operatingSystemVersion:(id)version isInternal:(BOOL)internal;
- (id)initWithSDK:(id)sdk;
- (BOOL)isInternal;
@end

#endif /* IDESchemeActionSDKRecord_h */
