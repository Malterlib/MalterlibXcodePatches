//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProvisioningTeamAccountPairProvider_Protocol_h
#define IDEProvisioningTeamAccountPairProvider_Protocol_h
#import <Foundation/Foundation.h>

@class DVTDeveloperAccountManager;

@protocol IDEProvisioningTeamAccountPairProvider <NSObject>

@property (nonatomic, readonly) NSOrderedSet *sessionProviders;
@property (nonatomic, readonly) DVTDeveloperAccountManager *accountManager;

/* instance methods */
- (id)pairForTeam:(id)team error:(id *)error;
- (id)pairForTeam:(id)team error:(id *)error;
@end

#endif /* IDEProvisioningTeamAccountPairProvider_Protocol_h */
