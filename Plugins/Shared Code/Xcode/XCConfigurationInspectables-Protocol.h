//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef XCConfigurationInspectables_Protocol_h
#define XCConfigurationInspectables_Protocol_h
#import <Foundation/Foundation.h>

@protocol XCConfigurationInspectables <NSObject>
/* instance methods */
- (id)name;
- (id)configurationInspectionContextForConfigurationNamed:(id)named;
- (id)createPropertyInfoContextWithBuildAction:(id)action configurationName:(id)name;
@end

#endif /* XCConfigurationInspectables_Protocol_h */