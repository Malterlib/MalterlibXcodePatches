//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef PBXBuildContext_h
#define PBXBuildContext_h
#import <Foundation/Foundation.h>

#include "XCMacroExpansionScope.h"

@class NSString;

@interface PBXBuildContext : NSObject {
  /* instance variables */
  NSString *_baseDirectoryPath;
  XCMacroExpansionScope *_macroExpansionScope;
}

/* instance methods */
- (id)valueForUndefinedKey:(id)key;
- (id)init;
- (id)baseDirectoryPath;
- (void)setBaseDirectoryPath:(id)path;
- (id)macroExpansionScope;
- (void)_setMacroExpansionScope:(id)scope;
- (id)absolutePathForPath:(id)path;
@end

#endif /* PBXBuildContext_h */