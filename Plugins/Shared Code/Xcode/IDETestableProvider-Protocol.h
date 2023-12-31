//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef IDETestableProvider_Protocol_h
#define IDETestableProvider_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDETestableProvider <DVTInvalidation, IDETestStateChangeEmitter, NSObject>

@property (readonly, copy) NSArray *testables;
@property (readonly, copy) NSString *name;

/* instance methods */
- (id)testableForBlueprint:(id)blueprint;
@end

#endif /* IDETestableProvider_Protocol_h */
