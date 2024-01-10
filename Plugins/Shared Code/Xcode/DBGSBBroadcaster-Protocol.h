//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22522.0.0.0.0
//
#ifndef DBGSBBroadcaster_Protocol_h
#define DBGSBBroadcaster_Protocol_h
#import <Foundation/Foundation.h>

@protocol DBGSBBroadcaster <NSObject>
/* instance methods */
- (BOOL)IsValid;
- (id)initWithConnection:(id)connection name:(const char *)name;
- (void)BroadcastEventByType:(unsigned int)type unique:(BOOL)unique;
@end

#endif /* DBGSBBroadcaster_Protocol_h */