//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTPropertyListEncoding_Protocol_h
#define DVTPropertyListEncoding_Protocol_h
#import <Foundation/Foundation.h>

@protocol DVTPropertyListEncoding <NSObject>
/* instance methods */
- (id)initWithPropertyList:(id)list owner:(id)owner;
- (void)awakeFromPropertyList;
- (void)encodeIntoPropertyList:(id)list;
@end

#endif /* DVTPropertyListEncoding_Protocol_h */
