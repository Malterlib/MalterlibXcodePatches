//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEGeniusResultsGraphNode_h
#define IDEGeniusResultsGraphNode_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEKeyDrivenNavigableItemRepresentedObject-Protocol.h"

@class DVTDocumentLocation, DVTFileDataType, DVTIcon, DVTObservingToken, DVTStackBacktrace, DVTSymbol, IDEFileReference, NSArray, NSImage, NSNull, NSString, NSURL;

@interface IDEGeniusResultsGraphNode : NSObject<IDEKeyDrivenNavigableItemRepresentedObject, DVTInvalidation> {
  /* instance variables */
  DVTObservingToken *_manualDomainRootChildItemsObservingToken;
}

@property int type;
@property (copy) NSString *identifier;
@property (copy) NSImage *image;
@property (copy) NSString *name;
@property (copy, nonatomic) NSArray *subitems;
@property (readonly, nonatomic) BOOL hideSubItemCount;
@property (readonly, nonatomic) BOOL showHierarchyForSingleResultsCategory;
@property (readonly, nonatomic) BOOL enabled;
@property (readonly, nonatomic) BOOL singleResultsCategory;
@property (readonly, nonatomic) NSString *navigableItem_name;
@property (readonly, nonatomic) NSString *navigableItem_displayNameRespectingExtensionHidingPreference;
@property (readonly, nonatomic) NSString *navigableItem_subtitle;
@property (readonly, nonatomic) NSImage *navigableItem_image;
@property (readonly, nonatomic) DVTIcon *navigableItem_icon;
@property (readonly, nonatomic) NSString *navigableItem_accessibleImageDescription;
@property (readonly, nonatomic) NSString *navigableItem_accessibilityIdentifier;
@property (readonly, nonatomic) NSString *navigableItem_toolTip;
@property (readonly, nonatomic) NSArray *navigableItem_additionalFilterMatchingText;
@property (readonly, nonatomic) BOOL navigableItem_isLeaf;
@property (readonly, nonatomic) id navigableItem_parentRepresentedObject;
@property (readonly, nonatomic) NSArray *navigableItem_childRepresentedObjects;
@property (readonly, nonatomic) BOOL navigableItem_isMajorGroup;
@property (readonly, nonatomic) IDEFileReference *navigableItem_fileReference;
@property (readonly, nonatomic) DVTFileDataType *navigableItem_documentType;
@property (readonly, nonatomic) DVTDocumentLocation *navigableItem_contentDocumentLocation;
@property (readonly, nonatomic) NSURL *navigableItem_representedURL;
@property (readonly, nonatomic) DVTSymbol *navigableItem_representedSymbol;
@property (readonly, nonatomic) BOOL navigableItem_referencedContentExists;
@property (readonly, nonatomic) BOOL navigableItem_missingReferencedContentIsImportant;
@property (readonly, nonatomic) BOOL navigableItem_isEnabled;
@property (readonly, nonatomic) BOOL navigableItem_isVisible;
@property (readonly, nonatomic) NSString *navigableItem_groupIdentifier;
@property (readonly, nonatomic) NSNull *navigableItem_filtered;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;

/* class methods */
+ (void)initialize;
+ (id)_rootNodeForGeniusResults:(id)results editor:(id)editor includeJumpToCounterpartCategory:(BOOL)category emptyCategoriesNavigateToEmptyEditor:(BOOL)editor;
+ (id)keyPathsForValuesAffectingNavigableItem_isLeaf;
+ (id)keyPathsForValuesAffectingNavigableItem_childRepresentedObjects;

/* instance methods */
- (id)initWithType:(int)type identifier:(id)identifier image:(id)image name:(id)name subitems:(id)subitems singleResultsCategory:(BOOL)category showHierarchyForSingleResultsCategory:(BOOL)category hideSubItemCount:(BOOL)count;
- (void)primitiveInvalidate;
- (id)ideModelObjectTypeIdentifier;
- (id)nameWithSubitemCount;
- (id)navigableItem_identifierForRepresentedObjectAtIndex:(unsigned long long)index inRelationshipKeyPath:(id)path;
- (unsigned long long)navigableItem_indexOfRepresentedObjectForIdentifier:(id)identifier inRelationshipKeyPath:(id)path;
@end

#endif /* IDEGeniusResultsGraphNode_h */
