//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEFileReference_h
#define IDEFileReference_h
#import <Foundation/Foundation.h>

#include "IDEContainerItem.h"
#include "IDEContainer.h"
#include "IDEStructureEditing-Protocol.h"

@class DVTExtension, DVTFileDataType, DVTFilePath, DVTObservingToken, NSString;

@interface IDEFileReference : IDEContainerItem<IDEStructureEditing> {
  /* instance variables */
  DVTFilePath *_watchedFilePath;
  DVTFilePath *_oldWatchedFilePath;
  DVTFileDataType *_lastDiscoveredFileDataType;
  DVTObservingToken *_referencedContainerIsValidObservingToken;
  DVTObservingToken *_workspaceIsValidObservingToken;
  BOOL _workaroundForProblem8727051;
  BOOL _stopResolvingReferencedContainers;
  unsigned long long _aggregateSourceControlLocalStatus;
  unsigned long long _aggregateSourceControlServerStatus;
  unsigned long long _aggregateSourceControlConflictStatus;
  BOOL _sourceControlLocalStatusNeedsUpdate;
  BOOL _sourceControlServerStatusNeedsUpdate;
  BOOL _sourceControlConflictStatusNeedsUpdate;
  BOOL _waitingForChangeNotificationsToResume;
  NSObject<NSObject> *_modelObjectGraphDidCoalesceNotificationToken;
}

@property (readonly) DVTFileDataType *presumedFileDataType;
@property unsigned long long sourceControlLocalStatus;
@property (readonly) unsigned long long sourceControlLocalStatusLastUpdatedTimestamp;
@property unsigned long long sourceControlServerStatus;
@property unsigned long long conflictStateForUpdateOrMerge;
@property (readonly) BOOL _filePathExists;
@property (readonly, copy, nonatomic) NSString *name;
@property (readonly) DVTFilePath *resolvedFilePath;
@property (copy, nonatomic) DVTFileDataType *assignedFileDataType;
@property (readonly) DVTFileDataType *discoveredFileDataType;
@property (readonly) DVTFileDataType *lastKnownFileDataType;
@property (readonly) DVTExtension *referencedContainerExtension;
@property (readonly) IDEContainer *referencedContainer;
@property (readonly) DVTFilePath *expectedFilePath;

/* class methods */
+ (id)keyPathsForValuesAffectingIdeModelObjectTypeIdentifier;
+ (void)initialize;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)selector;
+ (id)_fileReferenceAssociatesForPath:(id)path forAllPathsToSameFile:(BOOL)file workspace:(id)workspace;
+ (id)fileReferenceAssociatesForPath:(id)path forAllPathsToSameFile:(BOOL)file workspace:(id)workspace;
+ (id)fileReferenceAssociatesForPath:(id)path forAllPathsToSameFile:(BOOL)file;
+ (id)keyPathsForValuesAffectingName;
+ (id)keyPathsForValuesAffectingExpectedFilePath;
+ (BOOL)automaticallyNotifiesObserversOfSourceControlLocalStatus;
+ (BOOL)automaticallyNotifiesObserversOfSourceControlServerStatus;
+ (BOOL)automaticallyNotifiesObserversOfConflictStateForUpdateOrMerge;
+ (BOOL)automaticallyNotifiesObserversOfAggregateSourceControlLocalStatus;
+ (BOOL)automaticallyNotifiesObserversOfAggregateSourceControlServerStatus;
+ (BOOL)automaticallyNotifiesObserversOfAggregateSourceControlConflictStatus;
+ (id)keyPathsForValuesAffectingCanStructureEditName;
+ (id)Xcode3VariantFileReference_LocaleIdentifierForPath:(id)path;

/* instance methods */
- (void)evaluateAndSetExpectedSignatureIfNecessaryWithCompletionBlock:(id /* block */)block;
- (void)dvt_awakeFromXMLUnarchiver:(id)xmlunarchiver;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)dvt_encodeRelationshipsWithXMLArchiver:(id)xmlarchiver version:(id)version;
- (void)setAssignedFileDataTypeFromUTF8String:(char *)string fromXMLUnarchiver:(id)xmlunarchiver;
- (void)ide_populateFilePaths:(id)paths parentSuffixIndex:(long long)index visitedContainers:(id)containers;
- (id)ideModelObjectTypeIdentifier;
- (void)ideFindScope_accumulateFilePaths:(id)paths andVisitedContainers:(id)containers;
- (id)ideFindScope_predicateRoot;
- (id)ideFindScope_componentForGroupPath;
- (id)ideFindScope_itemAtPath:(id)path position:(long long)position preferContainerFileReferenceToRootGroup:(BOOL)group;
- (id)init;
- (void)primitiveInvalidate;
- (void)_setContainer:(id)container;
- (void)changePath:(id)path resolutionStrategies:(id)strategies;
- (void)_invalidateStartingWith:(id)with;
- (void)_invalidateStartingWith:(id)with changeBlock:(id /* block */)block;
- (id)_resolvedFilePathIfAvailable;
- (id)_absolutePath;
- (void)_resolvedFilePathWasInvalidated;
- (void)_invalidateResolvedFilePath;
- (void)_invalidateResolvedFilePathUsingPath:(id)path resolutionStrategies:(id)strategies;
- (void)_resolvedFilePathDidChange:(id)change;
- (BOOL)_resolvedFilePathIsValid;
- (void)_assignedFileDataTypeDidChange;
- (void)_invalidateFileDataType;
- (BOOL)_isBuildProductReference;
- (id)_resolveReferencedContainerExtension;
- (BOOL)_workaroundForProblem8727051;
- (void)_recalculateReferencedContainer;
- (void)_referencedContainerWasRecalculated;
- (void)_resolvedFilePathWasRecalculated;
- (id)_referencedContainer;
- (void)_addObserversForReferencedContainer;
- (void)_invalidateReferencedContainer;
- (BOOL)isReferencedContainerLoaded;
- (unsigned long long)aggregateSourceControlLocalStatus;
- (unsigned long long)aggregateSourceControlServerStatus;
- (unsigned long long)aggregateSourceControlConflictStatus;
- (void)_enqueueScmStatusUpdate;
- (void)_updateSourceControlStatus;
- (void)_updateSourceControlServerStatus;
- (void)_updateConflictStateForUpdateOrMerge;
- (void)_setAggregateSourceControlLocalStatus:(unsigned long long)status;
- (void)_setAggregateSourceControlServerStatus:(unsigned long long)status;
- (void)_setAggregateSourceControlConflictStatus:(unsigned long long)status;
- (void)_updateAggregateSourceControlLocalStatus;
- (void)_updateAggregateSourceControlServerStatus;
- (void)_updateAggregateSourceControlConflictStatus;
- (void)_updateSourceControlStatusIfNeeded;
- (void)debugPrintInnerStructure;
- (void)_takeConfigurationFromFileReference:(id)reference;
- (void)fileReferenceWasConfigured;
- (BOOL)allowRemovingContainerGroup;
- (BOOL)allowUserModificationOfSubitems;
- (BOOL)canStructureEditInsertSubitems:(id)subitems atIndex:(unsigned long long)index;
- (id)structureEditInsertSubitems:(id)subitems atIndex:(unsigned long long)index;
- (BOOL)canStructureEditInsertFileURLs:(id)urls atIndex:(unsigned long long)index;
- (id)structureEditInsertFileURLs:(id)urls atIndex:(unsigned long long)index createGroupsForFolders:(BOOL)folders;
- (BOOL)canStructureEditSortSubitemsAtIndexes:(id)indexes sortStyle:(unsigned long long)style;
- (BOOL)structureEditSortSubitemsAtIndexes:(id)indexes sortStyle:(unsigned long long)style;
- (BOOL)canStructureEditRemoveSubitemsAtIndexes:(id)indexes;
- (BOOL)structureEditRemoveSubitemsAtIndexes:(id)indexes error:(id *)error;
- (BOOL)canStructureEditName;
- (id)_structureEditNameForSuggestedName:(id)name;
- (BOOL)structureEditSetName:(id)name inContext:(id)context;
- (BOOL)structureEditName:(id)name inContext:(id)context completionBlock:(id /* block */)block;
@end

#endif /* IDEFileReference_h */
