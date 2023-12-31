//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22028.0.0.0.0
//
#ifndef SKUnitTestsIndex_h
#define SKUnitTestsIndex_h
#import <Foundation/Foundation.h>

#include "IDEIndex.h"
#include "SKIndexedUnitTestsDelegate-Protocol.h"
#include "SKIndexedUnitTestsRepo.h"
#include "SKScannedUnitTestsDelegate-Protocol.h"
#include "SKScannedUnitTestsRepo.h"

@class NSMutableDictionary, NSString;

@interface SKUnitTestsIndex : NSObject<SKScannedUnitTestsDelegate, SKIndexedUnitTestsDelegate> {
  /* instance variables */
  IDEIndex *_index;
  SKScannedUnitTestsRepo *_scannedTestsRepo;
  SKIndexedUnitTestsRepo *_indexedTestsRepo;
  void * _stateMtx;
  NSMutableDictionary *_testsByTestable;
  NSObject<OS_dispatch_queue> *_updateQueue;
}

@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (id)initWithIndex:(id)index toolchainResolver:(id)resolver;
- (void)setScanIndexDelegate:(id)delegate;
- (void)registerIndexable:(id)indexable;
- (void)unregisterIndexable:(id)indexable;
- (void)storeProcessedUnitOutputPath:(id)path hasTestSymbols:(BOOL)symbols;
- (void)storeCompletedProcessingUnits;
- (void)indexPausedStateChangedTo:(BOOL)to;
- (void)scannedSymbolsChanged:(id)changed repo:(id)repo;
- (void)indexedSymbolsChanged:(id)changed repo:(id)repo;
- (void)_updateTestInfoForTestablesAsync:(id)async;
- (void)_updateTestInfoForTestables:(id)testables;
- (BOOL)_updateTestInfoForTestable:(id)testable;
- (id)_mergeTestInfoForTestable:(id)testable;
- (id)unitTestsByIndexable;
- (void)invalidate;
- (void)_postUnitTestsDidChangeNotification;
@end

#endif /* SKUnitTestsIndex_h */
