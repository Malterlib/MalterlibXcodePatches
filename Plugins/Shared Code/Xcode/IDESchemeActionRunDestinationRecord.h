//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDESchemeActionRunDestinationRecord_h
#define IDESchemeActionRunDestinationRecord_h
#import <Foundation/Foundation.h>

#include "IDESchemeActionDeviceRecord.h"
#include "IDESchemeActionSDKRecord.h"

@class NSDictionary, NSString;

@interface IDESchemeActionRunDestinationRecord : NSObject

@property (readonly, copy) NSDictionary *dictionaryRepresentation;
@property (retain, nonatomic) IDESchemeActionDeviceRecord *targetDeviceRecord;
@property (readonly, copy) NSString *displayName;
@property (readonly, copy) NSString *targetArchitecture;
@property (readonly, nonatomic) IDESchemeActionDeviceRecord *localComputerRecord;
@property (readonly, nonatomic) IDESchemeActionSDKRecord *targetSDKRecord;

/* class methods */
+ (id)recordForRunDestination:(id)destination;

/* instance methods */
- (id)initWithDisplayName:(id)name targetArchitecture:(id)architecture targetDevice:(id)device targetSDK:(id)sdk localComputer:(id)computer;
@end

#endif /* IDESchemeActionRunDestinationRecord_h */