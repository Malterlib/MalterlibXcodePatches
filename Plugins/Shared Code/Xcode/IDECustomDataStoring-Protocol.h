//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef IDECustomDataStoring_Protocol_h
#define IDECustomDataStoring_Protocol_h
#import <Foundation/Foundation.h>

@protocol DVTCustomDataStoring;

@protocol IDECustomDataStoring <DVTCustomDataStoring>
/* instance methods */
- (void)scmStatusForSpecifier:(id)specifier completionBlock:(id /* block */)block;
- (void)addSpecifier:(id)specifier inWorkspace:(id)workspace toSCMWithCompletionBlock:(id /* block */)block;
@end

#endif /* IDECustomDataStoring_Protocol_h */
