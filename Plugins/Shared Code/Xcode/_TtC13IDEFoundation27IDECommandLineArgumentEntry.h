//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef _TtC13IDEFoundation27IDECommandLineArgumentEntry_h
#define _TtC13IDEFoundation27IDECommandLineArgumentEntry_h
#import <Foundation/Foundation.h>

@class NSString;

@interface IDEFoundation_IDECommandLineArgumentEntry : NSObject<NSCopying> // (Swift)

@property (nonatomic, copy) NSString *argument;
@property (nonatomic) BOOL enabled;
@property (nonatomic, readonly) NSString *description;
@property (nonatomic, readonly) long long hash;

/* instance methods */
- (void)dvt_encodeAttributesWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)setArgumentFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)setIsEnabledFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (BOOL)isEnabled;
- (id)initWithArgument:(id)argument enabled:(BOOL)enabled;
- (id)init;
- (BOOL)isEqual:(id)equal;
- (id)copyWithZone:(void *)zone;
@end

#endif /* _TtC13IDEFoundation27IDECommandLineArgumentEntry_h */
