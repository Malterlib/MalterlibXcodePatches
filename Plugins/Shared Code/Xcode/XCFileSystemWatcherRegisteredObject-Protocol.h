//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef XCFileSystemWatcherRegisteredObject_Protocol_h
#define XCFileSystemWatcherRegisteredObject_Protocol_h
#import <Foundation/Foundation.h>

@protocol XCFileSystemWatcherRegisteredObject <NSObject>
/* instance methods */
- (void)fileSystemWatcherWillClose:(id)close;
- (void)fileSystemWatcher:(id)watcher notedChangeAtPath:(id)path scanRecursively:(BOOL)recursively;
@end

#endif /* XCFileSystemWatcherRegisteredObject_Protocol_h */
