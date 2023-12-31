//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22028.0.0.0.0
//
#ifndef IDEBoltIndexDatabase_h
#define IDEBoltIndexDatabase_h
#import <Foundation/Foundation.h>

#include "IDEBoltIndexDatabaseProgressDelegate-Protocol.h"
#include "IDECoalescingInvocation.h"
#include "IDEIndexDatabaseDelegate-Protocol.h"
#include "IDEIndexGlobalQueryProvider-Protocol.h"
#include "IDEIndexingEngine.h"

@class DVTDispatchLock, DVTFilePath, NSArray, NSMutableArray, NSMutableDictionary, NSMutableSet;

@interface IDEBoltIndexDatabase : NSObject {
  /* instance variables */
  DVTFilePath *_storePath;
  IDEIndexingEngine *_engine;
  BOOL _enableOutOfDateFileWatching;
  BOOL _enableExplicitOutputUnits;
  BOOL _enableFullStoreVisibility;
  BOOL _isLoaded;
  BOOL _isDatabaseInitializedFromDatastore;
  BOOL _didProcessOutOfDateFilesAfterInitializedFromDatastore;
  DVTDispatchLock *_cacheLock;
  NSMutableDictionary *_targetsByMainFileURL;
  NSMutableDictionary *_indexablesByTarget;
  NSMutableDictionary *_pendingIndexedUnitOutputPathsBySession;
  NSMutableSet *_sessionsWaitingToEnd;
  IDECoalescingInvocation *_handleOutOfDateFiles;
  NSObject<OS_dispatch_queue> *_outOfDateFilesProcessQueue;
}

@property (readonly, nonatomic) DVTFilePath *path;
@property (readonly, nonatomic) NSObject<IDEIndexGlobalQueryProvider> *queryProvider;
@property (weak, nonatomic) NSObject<IDEIndexDatabaseDelegate> *delegate;
@property (weak, nonatomic) NSObject<IDEBoltIndexDatabaseProgressDelegate> *progressDelegate;
@property (readonly, nonatomic) NSArray *errors;

/* class methods */
+ (void)initialize;

/* instance methods */
- (id)initWithDatabasePath:(id)path storePath:(id)path engine:(id)engine enableOutOfDateFileWatching:(BOOL)watching enableExplicitOutputUnits:(BOOL)units enableFullStoreVisibility:(BOOL)visibility;
- (id)init;
- (void *)_getBoltDB;
- (void)didLoadWithIndex:(id)index;
- (void)didInitializeFromDatastore;
- (void)openReadOnly:(BOOL)only initialDBSize:(unsigned long long)dbsize index:(id)index;
- (void)close;
- (void)addUnitOutFilePaths:(id)paths waitForProcessing:(BOOL)processing;
- (void)removeUnitOutFilePaths:(id)paths waitForProcessing:(BOOL)processing;
- (void)_unitIsOutOfDate:(void *)hint;
- (void)_processOutOfDateFiles;
- (BOOL)isUnitOutOfDateWithOutputPath:(id)path dirtyFiles:(id)files;
- (BOOL)isUnitOutOfDateWithOutputPath:(id)path outOfDateModTime:(struct IndexModificationTime { unsigned long long x0; })time;
- (BOOL)hasUpToDateUnitForFile:(id)file outOfDateModTime:(struct IndexModificationTime { unsigned long long x0; })time;
- (void)addPendingIndexedUnitOutputPath:(id)path forSession:(id)session;
- (void)removePendingIndexedUnitOutputPath:(id)path forSession:(id)session;
- (void)_removePendingIndexedUnitOutputPathFromSessions:(id)sessions;
- (void)addPrefixMapping:(id)mapping mappingTo:(id)to;
- (void)_processedUnitOutputPath:(id)path;
- (void)purgeStaleData:(id)data;
- (id)filesForMainFile:(id)file target:(id)target;
- (id)filesForMainFile:(id)file target:(id)target followPCH:(BOOL)pch crossLanguage:(BOOL)language;
- (void)registerHotFile:(id)file;
- (void)setRootPaths:(id)paths;
- (void)registerIndexable:(id)indexable;
- (void)unregisterIndexable:(id)indexable;
- (void)addNewIndexableFile:(id)file indexable:(id)indexable;
- (void)removeIndexableFile:(id)file indexable:(id)indexable;
- (void)renameIndexableFile:(id)file newFile:(id)file indexable:(id)indexable;
- (void)editorDidSaveFile:(id)file;
- (id)_targetsForMainFileURL:(id)url;
- (id)_indexableForTarget:(id)target;
- (id)mainFilesForFile:(id)file crossLanguage:(BOOL)language;
- (BOOL)isKnownMainFile:(id)file target:(id)target;
- (BOOL)isKnownFile:(id)file;
- (void)sendDelegateDidEndImportSession:(id)session;
- (void)didEndSession:(id)session;
- (void)_forceEndSession:(id)session;
- (id)newImportSession;
@end

#endif /* IDEBoltIndexDatabase_h */
