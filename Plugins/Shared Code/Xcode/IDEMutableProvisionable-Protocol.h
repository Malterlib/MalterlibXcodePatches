//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef IDEMutableProvisionable_Protocol_h
#define IDEMutableProvisionable_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDEMutableProvisionable <IDEProvisionable>
/* instance methods */
- (void)setProvisioningStyle:(long long)style forConfigurationNamed:(id)named;
- (void)setBundleIdentifier:(id)identifier forConfigurationNamed:(id)named sdk:(id)sdk;
- (void)setTeam:(id)team forConfigurationNamed:(id)named sdk:(id)sdk;
- (void)setProvisioningProfile:(id)profile forConfigurationNamed:(id)named sdk:(id)sdk;
- (void)setSigningCertificateIdentifier:(id)identifier forConfigurationNamed:(id)named sdk:(id)sdk;
@end

#endif /* IDEMutableProvisionable_Protocol_h */
