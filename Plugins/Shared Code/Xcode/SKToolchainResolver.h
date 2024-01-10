//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22028.0.0.0.0
//
#ifndef SKToolchainResolver_h
#define SKToolchainResolver_h
#import <Foundation/Foundation.h>

@interface SKToolchainResolver : NSObject {
  /* instance variables */
  void * _registry;
}

/* instance methods */
- (id)initWithToolchainRegistry:(void *)registry;
- (id)toolchainForSettings:(id)settings tool:(int)tool;
- (id)defaultToolchainForTool:(int)tool;
@end

#endif /* SKToolchainResolver_h */