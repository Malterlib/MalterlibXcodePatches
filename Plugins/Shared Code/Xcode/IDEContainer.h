//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEContainer_h
#define IDEContainer_h
#import <Foundation/Foundation.h>

#include "DVTModelObject.h"

@protocol DVTInvalidation, IDEReadOnlyItem, DVTDirectoryBasedCustomDataStoreDelegate, IDEUpgradeableItem, IDEContainerDelegate, IDEContainerCore;
@class DVTExtension, DVTFilePath, DVTOperation, DVTStackBacktrace, DVTTimeSlicedMainThreadWorkQueue, NSDictionary, NSMapTable, NSMutableDictionary, NSString, NSTimer, NSURL, IDEWorkspace, IDEGroup;

@interface IDEContainer : DVTModelObject<DVTInvalidation, IDEReadOnlyItem, DVTDirectoryBasedCustomDataStoreDelegate, IDEUpgradeableItem> {
  /* instance variables */
  DVTOperation *_willReadOperation;
  DVTOperation *_readOperation;
  DVTOperation *_didReadOperation;
  DVTTimeSlicedMainThreadWorkQueue *_scmStatusUpdatingQueue;
  DVTTimeSlicedMainThreadWorkQueue *_pendingFileReferenceResolvingQueue;
  long long _transitionActivity;
  NSMutableDictionary *_sessionIdentifiersToFilePaths;
  NSMutableDictionary *_containerLoadingTokens;
  NSDictionary *_containerDataFilePaths;
  long long _autosaveBehavior;
  long long _saveIssue;
  NSTimer *_pendingSaveTimer;
  NSString *_sessionIdentifier;
  NSMutableDictionary *_filePathToReadOnlyItemMap;
  NSMapTable *_readOnlyItemToStatusObserverMap;
  NSMapTable *_pendingFilePathChangeDictionary;
  BOOL _hasTransitionedToIdle;
  BOOL _isMajorGroup;
  BOOL _isFolderLike;
}

@property (readonly) BOOL structureEditingTreatAsBlueFolder;
@property BOOL containerEdited;
@property int readOnlyStatus;
@property BOOL transitioningToNewFilePath;
@property (readonly, nonatomic) BOOL validForSchemeBuildableReferences;
@property long long activity;
@property (retain) NSObject<IDEContainerDelegate> *containerDelegate;
@property (readonly) NSObject<IDEContainerCore> *containerCore;
@property (readonly) IDEWorkspace *workspace;
@property (readonly) DVTExtension *extension;
@property (readonly) DVTFilePath *filePath;
@property (readonly) DVTFilePath *rootFilePath;
@property (readonly) NSString *displayName;
@property (readonly, copy) NSString *workspaceParentRelativePath;
@property (copy, nonatomic) DVTFilePath *itemBaseFilePath;
@property (readonly) IDEGroup *rootGroup;
@property (readonly) BOOL majorGroup;
@property (readonly) BOOL folderLike;
@property (readonly) BOOL editable;
@property (readonly) BOOL allowsRenaming;
@property (readonly) BOOL supportsOnDemandResources;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly) NSURL *readOnlyItemURL;

/* class methods */
+ (void)initialize;
+ (id)containerLoadingModelObjectGraph;
+ (id)containerExtensionForFileDataType:(id)type;
+ (id)containerFileDataType;
+ (id)containerTypeDisplayName;
+ (id)_noContainerClassForFileTypeError:(id)error;
+ (id)_containerOpenAsAnotherContainerTypeErrorForPath:(id)path newContainerTypeName:(id)name oldContainerTypeName:(id)name;
+ (id)_containerOpenInAnotherWorkspaceErrorForPath:(id)path;
+ (id)retainedContainerAtFilePath:(id)path fileDataType:(id)type workspace:(id)workspace error:(id *)error;
+ (id)_retainedContainerAtFilePath:(id)path fileDataType:(id)type workspace:(id)workspace options:(id)options error:(id *)error;
+ (id)retainedContainerForFilePath:(id)path workspace:(id)workspace;
+ (id)containersForFilePath:(id)path;
+ (id)retainedWrappedWorkspaceForContainerAtFilePath:(id)path fileDataType:(id)type error:(id *)error;
+ (BOOL)isContainerOpenForFilePath:(id)path;
+ (id)_openContainers;
+ (id)_containersPendingRelease;
+ (id)_refcountTableForContainer:(id)container;
+ (unsigned long long)_countForContainer:(id)container;
+ (void)_increaseCountForContainer:(id)container;
+ (void)_decreaseCountForContainer:(id)container;
+ (void)_removeOpenContainer:(id)container;
+ (BOOL)_closeContainerIfNeeded:(id)needed;
+ (void)_retainContainer:(id)container;
+ (void)_releaseContainer:(id)container;
+ (void)_invalidateContainer:(id)container;
+ (id)_containerForSessionIdentifier:(id)identifier;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)selector;
+ (BOOL)_observeContainerDataFilePathsForChanges;
+ (id)_containersWithPendingFilePathChanges;
+ (void)suspendFilePathChangeNotifications;
+ (void)resumeFilePathChangeNotifications;
+ (void)suspendFilePathChangeNotificationsForWorkspace:(id)workspace;
+ (void)resumeFilePathChangeNotificationsForWorkspace:(id)workspace;
+ (BOOL)filePathChangeNotificationsAreSuspendedForWorkspace:(id)workspace;
+ (void)_addContainerWithPendingChanges:(id)changes;
+ (BOOL)automaticallyNotifiesObserversOfContainerEdited;
+ (double)_defaltAutosaveDelay;
+ (double)_defaltSlowAutosaveDelay;
+ (id)_errorSavingContainer:(id)container code:(long long)code;
+ (BOOL)supportsFilePersistence;
+ (id)containerDataFilePathsForFilePath:(id)path;
+ (BOOL)automaticallyNotifiesObserversOfActivity;
+ (id)keyPathsForValuesAffectingWorkspaceParentRelativePath;
+ (BOOL)automaticallyNotifiesObserversOfFilePath;
+ (BOOL)supportsMultipleInstancesPerFilePath;
+ (BOOL)isOnlyUsedForUserInteraction;
+ (void)setErrorPresenter:(id)presenter;
+ (id)errorPresenter;
+ (void)setReloadingDelegate:(id)delegate;
+ (id)reloadingDelegate;
+ (void)setUnlockingDelegate:(id)delegate;
+ (id)unlockingDelegate;
+ (BOOL)_shouldTrackReadOnlyStatus;

/* instance methods */
- (id)_containerInstanceDescription;
- (void)_addPendingFileReference:(id)reference;
- (void)_removePendingFileReference:(id)reference;
- (void)_locateFileReferencesRecursivelyInGroup:(id)group;
- (void)_handleContainerResolutionFailureForFileReference:(id)reference;
- (void)_resolveFileReference:(id)reference;
- (void)_clearPendingFileReferencesAndContainerLoadingTokens;
- (void)_locateFileReferencesRecursively;
- (void)_removeContainerLoadingTokenForContainer:(id)container;
- (void)_setContainerLoadingTokenForContainer:(id)container;
- (void)_addSubcontainer:(id)subcontainer;
- (void)_removeSubcontainer:(id)subcontainer;
- (id)initWithFilePath:(id)path extension:(id)extension workspace:(id)workspace options:(id)options error:(id *)error;
- (id)init;
- (BOOL)canSaveContainer;
- (void)_saveContainerIfNeeded;
- (void)retainContainer;
- (void)releaseContainer;
- (void)_willInvalidateContainerToDiscardInMemoryRepresentation;
- (void)_invalidateContainerToDiscardInMemoryRepresentation:(BOOL)representation;
- (id)_sessionIdentifier;
- (void)invalidate;
- (void)primitiveInvalidate;
- (void)_filePathDidChangeWithPendingChangeDictionary;
- (void)_registerForChangesToContainerDataFilePath:(id)path;
- (void)_unregisterForChangesToContainerDataFilePath:(id)path;
- (void)_clearContainerDataFilePathsToModDateMap;
- (id)_modificationDateForFilePath:(id)path;
- (void)_createContainerDataFilePathsToModDateMap;
- (void)_updateContainerDataFilePathsToModDateMap;
- (id)_lastKnownModDateForContainerDataFile:(id)file;
- (id)_containerDataFilePaths;
- (void)_saveContainerPeriodically;
- (void)_scheduleAutosaveTimer;
- (BOOL)saveRecursivelyWithError:(id *)error;
- (BOOL)_saveContainerForAction:(long long)action error:(id *)error;
- (void)_containerEditedDidChange;
- (void)_setContainerEdited;
- (BOOL)ignoreLocalChanges;
- (BOOL)_canClosePreflightOrError:(id *)error;
- (BOOL)_canClosePreflightWithCheckedContainers:(id)containers error:(id *)error;
- (id)_readOperationWithFilePath:(id)path;
- (id)_willReadOperationWithFilePath:(id)path;
- (id)_didReadOperationWithFilePath:(id)path;
- (BOOL)_readAsyncIfPossibleFromFilePath:(id)path error:(id *)error;
- (BOOL)readFromFilePath:(id)path error:(id *)error;
- (BOOL)willReadFromFilePath:(id)path error:(id *)error;
- (BOOL)didReadFromFilePath:(id)path error:(id *)error;
- (BOOL)writeToFilePath:(id)path forceWrite:(BOOL)write error:(id *)error;
- (id)containerDataFilePathsForFilePath:(id)path;
- (void)_containerDidLoad;
- (void)_didTransitionToActivity:(long long)activity;
- (void)_willUpdateActivity;
- (void)_didUpdateActivity;
- (void)_setExtension:(id)extension;
- (void)_setTransitioningToNewFilePath:(BOOL)path;
- (void)_makeAbsoluteFileReferencesInGroup:(id)group relativeToFolderFilePath:(id)path withPathString:(id)string;
- (void)_respondToFileChangeOnDiskWithFilePath:(id)path;
- (BOOL)_shouldRespondToFileChangeOnDisk;
- (void)_setFilePath:(id)path strict:(BOOL)strict createContainerDataFilePathsToModDateMap:(BOOL)map;
- (void)_setFilePath:(id)path;
- (BOOL)_setContainerFilePath:(id)path strict:(BOOL)strict error:(id *)error;
- (BOOL)setContainerFilePath:(id)path error:(id *)error;
- (void)_changeContainerFilePath:(id)path inContext:(id)context;
- (void)_makeRelativeFileReferencesInGroup:(id)group relativeToNewBasePath:(id)path oldBaseFilePath:(id)path;
- (id)_itemBaseFilePathForFilePath:(id)path;
- (id)createRootGroup;
- (void)_initRootGroup;
- (BOOL)isEditable;
- (BOOL)isMajorGroup;
- (BOOL)isFolderLike;
- (void)enumerateUpgradeTasksWithBlock:(id /* block */)block;
- (void)holdOnDiskFilesForICloudDriveIfNecessary;
- (void)_enqueueSCMUpdateForItem:(id)item;
- (void)debugPrintInnerStructure;
- (void)debugPrintStructure;
- (BOOL)makeWritableWithError:(id *)error;
- (void)_updateSharedReadOnlyItemStatus;
- (void)_removeReadOnlyItemPath:(id)path;
- (void)_removeAllReadOnlyItemPaths;
- (void)_addReadOnlyItemPath:(id)path;
- (id)_readOnlyItemsToUnlock;
- (void)_unlockReadOnlyItems:(id)items completionQueue:(id)queue completionBlock:(id /* block */)block;
- (void)customDataStore:(id)store makeFilePathsWritable:(id)writable completionQueue:(id)queue completionBlock:(id /* block */)block;
- (void)customDataStore:(id)store moveItemAtFilePath:(id)path toFilePath:(id)path completionQueue:(id)queue completionBlock:(id /* block */)block;
- (void)customDataStore:(id)store removeItemAtFilePath:(id)path completionQueue:(id)queue completionBlock:(id /* block */)block;
- (BOOL)isValidForSchemeBuildableReferences;
- (BOOL)isTransitioningToNewFilePath;
@end

#include "DVTDirectoryBasedCustomDataStoreDelegate-Protocol.h"
#include "DVTInvalidation-Protocol.h"
#include "IDEContainerCore-Protocol.h"
#include "IDEContainerDelegate-Protocol.h"
#include "IDEGroup.h"
#include "IDEReadOnlyItem-Protocol.h"
#include "IDEUpgradeableItem-Protocol.h"
#include "IDEWorkspace.h"

#endif /* IDEContainer_h */
