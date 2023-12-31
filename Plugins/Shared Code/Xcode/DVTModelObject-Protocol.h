//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTModelObject_Protocol_h
#define DVTModelObject_Protocol_h
#import <Foundation/Foundation.h>

#include "DVTModelObject-Protocol.h"
#include "DVTModelObjectGraph.h"

@class NSString;

@protocol DVTModelObject <NSObject>

@property (readonly, nonatomic) DVTModelObjectGraph *objectGraph;

@end

#endif /* DVTModelObject_Protocol_h */
