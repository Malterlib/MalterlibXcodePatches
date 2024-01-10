//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTActiveStateAwareToken_h
#define DVTActiveStateAwareToken_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, NSString;
@protocol DVTActiveStateAware;

@interface DVTActiveStateAwareToken : NSObject<DVTInvalidation>

@property (readonly) NSView<DVTActiveStateAware> *observer;
@property (readonly) NSView<DVTActiveStateAware> *ancestor;
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
- (id)initWithObserver:(id)observer ancestor:(id)ancestor;
- (void)primitiveInvalidate;
@end

#endif /* DVTActiveStateAwareToken_h */