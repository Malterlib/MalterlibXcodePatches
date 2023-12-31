//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDELogManager_h
#define IDELogManager_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, NSArray, NSDictionary, NSMapTable, NSMutableArray, NSMutableDictionary, NSString;

@interface IDELogManager : NSObject<DVTInvalidation> {
  /* instance variables */
  NSMapTable *_logProviderToRecordsIndex;
  NSDictionary *_cachedRecentLogRecordsByTypeIdentifier;
}

@property (readonly) NSArray *logProviders;
@property (readonly) NSMutableArray *mutableLogRecords;
@property (readonly) NSMutableDictionary *auxiliaryRecordsByIdentifier;
@property (retain) id domainItem;
@property (copy) NSString *domainName;
@property (readonly) NSArray *logRecords;
@property (readonly) NSMutableDictionary *navigatorRootItems;
@property (readonly, copy) NSArray *importedRecords;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (id)keyPathsForValuesAffectingImportedRecords;

/* instance methods */
- (id)initWithDomainItem:(id)item domain:(id)domain;
- (void)primitiveInvalidate;
- (id)importResultBundleRecord:(id)record disablesSourceIntegration:(BOOL)integration;
- (id)extensionsMatchingDomain;
- (void)_setupLogProviders;
- (id)_subRecordsFromCandidateRecords:(id)records;
- (void)_handleLogRecordChangesForProvider:(id)provider;
- (id)auxiliaryRecordWithIdentifier:(id)identifier;
- (id)cachedRecentLogRecordsByTypeIdentifier;
- (id)mostRecentLogRecordForType:(id)type;
- (id)logRecordForDVTDocumentLocation:(id)location;
@end

#endif /* IDELogManager_h */
