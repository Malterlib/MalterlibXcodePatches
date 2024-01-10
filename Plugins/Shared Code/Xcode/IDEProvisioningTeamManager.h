//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProvisioningTeamManager_h
#define IDEProvisioningTeamManager_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEProvisioningBasicTeamProtocol-Protocol.h"
#include "IDEProvisioningTeamAccountPairManager.h"

@class DVTDelayedInvocation, DVTDeveloperAccountManager, DVTDispatchLock, DVTLogAspect, DVTProvisioningProfileManager, DVTSigningCertificateManager, DVTStackBacktrace, NSOrderedSet, NSSet, NSString;

@interface IDEProvisioningTeamManager : NSObject<DVTInvalidation>

@property (retain) DVTDeveloperAccountManager *accountManager;
@property (retain) DVTProvisioningProfileManager *profileManager;
@property (retain) DVTSigningCertificateManager *certificateManager;
@property (retain) IDEProvisioningTeamAccountPairManager *teamAccountPairManager;
@property (retain) NSString *teamCacheKey;
@property (retain) DVTDispatchLock *teamsLock;
@property (retain) DVTDelayedInvocation *delayedUpdateInvocation;
@property (retain) DVTDelayedInvocation *delayedLocalUpdateInvocation;
@property (retain) NSSet *developerAccountCredentialObservers;
@property BOOL areTeamsLoaded;
@property BOOL busy;
@property (retain, nonatomic) NSOrderedSet *disambiguatedTeams;
@property (retain, nonatomic) NSOrderedSet *disambiguatedTeamsIncludingLocallyDerived;
@property (readonly) DVTLogAspect *logAspect;
@property (retain) NSObject<DVTInvalidation> *accountsToken;
@property (retain) NSObject<DVTInvalidation> *profilesToken;
@property (retain) NSObject<DVTInvalidation> *certificatesToken;
@property (readonly, nonatomic) NSOrderedSet *teams;
@property (readonly, nonatomic) NSOrderedSet *teamsIncludingLocallyDerivedTeams;
@property (retain) NSObject<IDEProvisioningBasicTeamProtocol> *lastSelectedTeam;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (id)defaultTeamManager;
+ (id)keyPathsForValuesAffectingTeams;
+ (id)keyPathsForValuesAffectingTeamsIncludingLocallyDerivedTeams;
+ (BOOL)supportsInvalidationPrevention;

/* instance methods */
- (id)initWithDeveloperAccountManager:(id)manager provisioningProfileManager:(id)manager signingCertificateManager:(id)manager teamAccountPairManager:(id)manager teamCacheUserDefaultsKey:(id)key wantsFullFunctionality:(BOOL)functionality;
- (id)init;
- (void)primitiveInvalidate;
- (void)_forceReloadInternalWithCacheLoadedCallback:(id /* block */)callback;
- (void)forceReloadTeams;
- (void)_commonInitWithFullFunctionality:(BOOL)functionality;
- (void)_setUpObservations;
- (void)_updateTeamsWithCacheLoadedCallback:(id /* block */)callback completionCallback:(id /* block */)callback;
- (void)_updateTeamsImpl:(id /* block */)impl completionCallback:(id /* block */)callback;
- (void)_updateLocallyDerivedTeams;
- (id)_teamsForAccount:(id)account error:(id *)error;
- (id)_cachedTeamsByUsername;
- (void)_cacheTeams:(id)teams forUsername:(id)username;
- (void)_purgeErstwhileUsernamesFromCache:(id)cache;
- (id)teamWithID:(id)id;
- (id)sessionProviderForTeam:(id)team error:(id *)error;
- (BOOL)isBusy;
@end

#endif /* IDEProvisioningTeamManager_h */