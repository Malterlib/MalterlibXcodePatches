//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTInvalidation_NSObject_h
#define DVTInvalidation_NSObject_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "DVTStackBacktrace.h"

@class NSString;

@interface DVTInvalidation_NSObject : NSObject<DVTInvalidation>

@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;

/* instance methods */
- (void)primitiveInvalidate;
@end

#endif /* DVTInvalidation_NSObject_h */