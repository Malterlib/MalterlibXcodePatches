//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDENavigableItemCoordinator_h
#define IDENavigableItemCoordinator_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDENavigableItemCoordinatorDelegate-Protocol.h"

@class DVTDelayedInvocation, DVTModelGraphTransactionScope, DVTStackBacktrace, NSHashTable, NSMapTable, NSMutableOrderedSet, NSString;

@interface IDENavigableItemCoordinator : NSObject<DVTInvalidation> {
  /* instance variables */
  NSHashTable *_coordinatedItems;
  NSMapTable *_documentsByNavItem;
  NSMapTable *_domainIdentifiersByNavItem;
  NSMapTable *_rootItemsByRepresentedObject;
  DVTDelayedInvocation *_postPendingChangesInvocation;
  NSMutableOrderedSet *_pendingGraphChangedItems;
  NSMutableOrderedSet *_pendingArrangedGraphChangedItems;
  NSMutableOrderedSet *_pendingPropertyChangedItems;
  DVTModelGraphTransactionScope *_transactionScope;
  NSHashTable *_pendingForgettingItems;
  struct __nicFlags { unsigned int _delegateRespondsToDocumentForNavigableItem :1 ; unsigned int _delegateRespondsToNavigableItemChildRepresentedObjectsForArray :1 ; unsigned int _hasWarnedAboutRootItemsCount :1 ; unsigned int _isInvalidating :1 ; } _nicFlags;
}

@property (readonly, nonatomic) NSObject<IDENavigableItemCoordinatorDelegate> *_childItemsRearrangingDelegate;
@property (retain, nonatomic) NSObject<IDENavigableItemCoordinatorDelegate> *delegate;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (void)initialize;
+ (void)_invalidateTemporaryCoordinator;
+ (void)temporaryItemForRepresentedObject:(id)object inScope:(id /* block */)scope;
+ (void)temporaryItemsForRepresentedObjects:(id)objects inScope:(id /* block */)scope;
+ (void)temporaryItemInDomain:(id)domain forWorkspace:(id)workspace inScope:(id /* block */)scope;
+ (BOOL)temporaryItemForArchivableRepresentation:(id)representation forWorkspace:(id)workspace error:(id *)error inScope:(id /* block */)scope;
+ (BOOL)temporaryStructureItemForDocumentURL:(id)url forWorkspace:(id)workspace error:(id *)error inScope:(id /* block */)scope;
+ (id)structureNavigableItemArchivableRepresentationsForURLs:(id)urls inWorkspace:(id)workspace;

/* instance methods */
- (id)init;
- (void)primitiveInvalidate;
- (id)_rootNavigableItemsWithRepresentedObjects:(id)objects;
- (id)rootNavigableItemWithRepresentedObject:(id)object;
- (id)_structureNavigableItemForFileURL:(id)url inWorkspace:(id)workspace error:(id *)error;
- (id)_structureNavigableItemForNonFileURL:(id)url domainExtension:(id)extension inWorkspace:(id)workspace error:(id *)error;
- (id)_structureNavigableItemForNonFileURL:(id)url inWorkspace:(id)workspace error:(id *)error;
- (id)structureNavigableItemForDocumentURL:(id)url inWorkspace:(id)workspace error:(id *)error;
- (id)_navigableItemForFilePath:(id)path inWorkspace:(id)workspace withSeenFileReferences:(id)references computedNavItemsByContainerFilePath:(id)path allowLeaf:(BOOL)leaf;
- (id)_providersByDomain;
- (id)_domainIdentifiersByNavItem;
- (id)_rootItemsByRepresentedObject;
- (id)_coordinatedItems;
- (id)domainIdentifierForNavigableItem:(id)item;
- (Class)domainProviderWithIdentifier:(id)identifier;
- (id)rootNavigableItemInDomain:(id)domain forWorkspace:(id)workspace;
- (id)_childNavigableItemWithRepresentationIDs:(id)ids parentItem:(id)item acceptPartialMatch:(BOOL)match;
- (id)_documentContentNavigableItemFromArchivableRepresentation:(id)representation documentItem:(id)item;
- (id)_navigableItemFromArchivableRepresentation:(id)representation rootItem:(id)item error:(id *)error;
- (id)navigableItemFromArchivableRepresentation:(id)representation forWorkspace:(id)workspace error:(id *)error;
- (id)workspaceRootFilePathIfAvailable;
- (void)_postWillForgetNotification:(id)notification;
- (void)_postDidForgetNotificationAndPurgePendingForgottenItems;
- (void)_postNotificationNamed:(id)named forChangedItems:(id)items;
- (void)_hibernate;
- (void)_unhibernate;
- (void)_delayedPostGraphAndPropertyChangeNotifications;
- (void)_noteNavigableItemChangedChildItems:(id)items;
- (void)_noteNavigableItemChangedArrangedChildItems:(id)items;
- (void)_noteNavigableItem:(id)item valueWillChangeForProperty:(id)property;
- (void)processPendingChanges;
- (id)_arrangedChildItemsOfItem:(id)item;
- (int)_filterCurrentGeneration;
- (void)registerNavigableItem:(id)item;
- (void)_collectDescendants:(id)descendants toForgetForItem:(id)item;
- (void)closeDocumentsForItems:(id)items;
- (void)_forgetItems:(id)items;
- (void)forgetNavigableItems:(id)items;
- (void)forgetNavigableItem:(id)item;
- (void)_editorDocumentWillClose:(id)close;
- (id)editorDocumentForNavigableItem:(id)item;
- (void)forgetEditorDocument:(id)document;
@end

#endif /* IDENavigableItemCoordinator_h */
