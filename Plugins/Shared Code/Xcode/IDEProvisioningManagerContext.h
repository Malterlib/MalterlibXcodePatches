//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProvisioningManagerContext_h
#define IDEProvisioningManagerContext_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEProvisioningContext.h"
#include "IDEProvisioningErrorProvider-Protocol.h"
#include "IDEProvisioningMechanic.h"
#include "IDEProvisioningTeamAccountPairProvider-Protocol.h"
#include "IDEProvisioningTeamManager.h"

@class DVTStackBacktrace, NSString;
@protocol DVTProvisioningProfileManagerProtocol, DVTSigningCertificateManagerProtocol;

@interface IDEProvisioningManagerContext : NSObject<DVTInvalidation> {
  /* instance variables */
  IDEProvisioningContext *_provisioningContext;
}

@property (retain, nonatomic) IDEProvisioningMechanic *mechanic;
@property (readonly, nonatomic) IDEProvisioningTeamManager *teamManager;
@property (readonly, nonatomic) NSObject<DVTProvisioningProfileManagerProtocol> *profileManager;
@property (readonly, nonatomic) NSObject<DVTSigningCertificateManagerProtocol> *certificateManager;
@property (readonly, nonatomic) long long automaticLocationStyle;
@property (readonly, nonatomic) long long repairMode;
@property (readonly, nonatomic) long long evaluationMode;
@property (readonly, nonatomic) NSObject<IDEProvisioningErrorProvider> *errorProvider;
@property (readonly, nonatomic) NSObject<IDEProvisioningTeamAccountPairProvider> *teamAccountPairProvider;
@property (readonly, nonatomic) BOOL allowMutatingPortalAppIDs;
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
- (id)initWithProvisioningContext:(id)context mechanic:(id)mechanic;
- (void)primitiveInvalidate;
- (id)newProvisionableManagerForProvisionable:(id)provisionable provisioningManager:(id)manager;
@end

#endif /* IDEProvisioningManagerContext_h */
