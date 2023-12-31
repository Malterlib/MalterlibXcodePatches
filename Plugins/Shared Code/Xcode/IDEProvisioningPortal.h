//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProvisioningPortal_h
#define IDEProvisioningPortal_h
#import <Foundation/Foundation.h>

@class DVTSigningCertificateManager;
@protocol DVTProvisioningProfileManagerProtocol;

@interface IDEProvisioningPortal : NSObject

@property (retain) DVTSigningCertificateManager *signingCertificateManager;
@property (retain) NSObject<DVTProvisioningProfileManagerProtocol> *provisioningProfileManager;

/* class methods */
+ (id)defaultPortal;
+ (id)portalWithSigningCertificateManager:(id)manager provisioningProfileManager:(id)manager;
+ (id)concurrentQueue;
+ (id)_errorForNoMatchingTeam:(id)team;

/* instance methods */
- (id)init;
- (id)initWithSigningCertificateManager:(id)manager provisioningProfileManager:(id)manager;
- (id)createAndInstallCertificateWithSession:(id)session team:(id)team type:(id)type error:(id *)error;
- (BOOL)_installIdentity:(id)identity error:(id *)error;
- (id)portalCertificatesWithSession:(id)session team:(id)team type:(id)type memberSpecificCertificates:(id *)certificates error:(id *)error;
- (id)portalProfilesWithSession:(id)session team:(id)team platform:(id)platform sdkVariant:(id)variant nameOrUUID:(id)uuid error:(id *)error;
- (id)portalProfilesWithSession:(id)session team:(id)team nameOrUUID:(id)uuid error:(id *)error;
- (id)portalProfilesMatchingNameOrUUID:(id)uuid profiles:(id)profiles;
- (id)inMemoryProfileForPortalProfile:(id)profile session:(id)session error:(id *)error;
- (id)profilesWithSession:(id)session team:(id)team platform:(id)platform sdkVariant:(id)variant error:(id *)error;
- (id)profilesWithSession:(id)session team:(id)team error:(id *)error;
- (id)devicesWithSession:(id)session team:(id)team error:(id *)error;
- (id)portalTeamForTeam:(id)team session:(id)session error:(id *)error;
- (id)listTeamsAndRolesWithAccount:(id)account error:(id *)error;
- (id)errorForMissingProfileData;
@end

#endif /* IDEProvisioningPortal_h */
