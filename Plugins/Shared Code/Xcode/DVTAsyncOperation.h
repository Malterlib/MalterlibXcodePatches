//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTAsyncOperation_h
#define DVTAsyncOperation_h
#import <Foundation/Foundation.h>

#include "DVTOperation.h"

@interface DVTAsyncOperation : DVTOperation
/* class methods */
+ (id)operationWithBlock:(id /* block */)block;
+ (id)operationWithAsynchronousBlock:(id /* block */)block;

/* instance methods */
- (void)mainWithCompletionHandler:(id /* block */)handler;
- (id)operationWithSynchronousBlock:(id /* block */)block;
- (BOOL)isAsynchronous;
- (void)main;
- (void)start;
@end

#endif /* DVTAsyncOperation_h */
