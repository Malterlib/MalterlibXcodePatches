//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProvisioningRepairExecutionContext_h
#define IDEProvisioningRepairExecutionContext_h
#import <Foundation/Foundation.h>

#include "IDEProvisioningLedgerEntry.h"
#include "IDEProvisioningPortal.h"
#include "IDEProvisioningRepairContext.h"
#include "IDERepairable-Protocol.h"

@class DVTPortalTeam, DVTProvisioningContext;
@protocol DVTProvisioningProfileManagerProtocol, DVTSigningCertificateManagerProtocol;

@interface IDEProvisioningRepairExecutionContext : NSObject {
  /* instance variables */
  IDEProvisioningRepairContext *_repairContext;
}

@property (readonly, nonatomic) NSObject<IDERepairable> *repairable;
@property (readonly, nonatomic) DVTPortalTeam *team;
@property (readonly, nonatomic) NSObject<DVTSigningCertificateManagerProtocol> *signingCertificateManager;
@property (readonly, nonatomic) NSObject<DVTProvisioningProfileManagerProtocol> *provisioningProfileManager;
@property (readonly, nonatomic) IDEProvisioningPortal *portal;
@property (readonly, nonatomic) IDEProvisioningLedgerEntry *repairLedgerEntry;
@property (readonly, nonatomic) unsigned long long successiveRepairCount;
@property (readonly, nonatomic) DVTProvisioningContext *provisioningContext;
@property (readonly, nonatomic) BOOL allowMutatingPortalAppIDs;

/* instance methods */
- (id)initWithRepairContext:(id)context repairLedgerEntry:(id)entry;
- (id)sessionWithLedgerEntry:(id)entry error:(id *)error;
@end

#endif /* IDEProvisioningRepairExecutionContext_h */
