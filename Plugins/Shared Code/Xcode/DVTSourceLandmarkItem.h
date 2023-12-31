//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTSourceLandmarkItem_h
#define DVTSourceLandmarkItem_h
#import <Foundation/Foundation.h>

#include "DVTSourceLandmarkItem.h"
#include "DVTSourceLandmarkItemDelegate-Protocol.h"
#include "DVTSourceLandmarkItemProtocol-Protocol.h"

@class DVTStackBacktrace, NSArray, NSMutableArray, NSString;

@interface DVTSourceLandmarkItem : NSObject<DVTSourceLandmarkItemProtocol> {
  /* instance variables */
  DVTStackBacktrace *_pendingUpdateBacktrace;
  NSObject<DVTSourceLandmarkItemDelegate> *_delegate;
  void * _itemRef;
}

@property DVTSourceLandmarkItem *parent;
@property (readonly) NSMutableArray *_children;
@property (readonly) BOOL needsUpdate;
@property (readonly) NSArray *children;
@property (readonly) long long numberOfChildren;
@property (copy, nonatomic) NSString *name;
@property (readonly) unsigned long long type;
@property (readonly, copy, nonatomic) NSString *typeName;
@property unsigned long long markStyle;
@property (nonatomic) struct _NSRange range;
@property (nonatomic) struct _NSRange nameRange;
@property (readonly) double timestamp;
@property long long nestingLevel;
@property long long indentLevel;

/* class methods */
+ (unsigned long long)sourceLandmarkItemTypeForNodeType:(long long)type;

/* instance methods */
- (id)initWithName:(id)name type:(unsigned long long)type;
- (id)initWithItemReference:(void *)reference type:(unsigned long long)type delegate:(id)delegate;
- (id)initWithItem:(id)item type:(unsigned long long)type delegate:(id)delegate;
- (void)dealloc;
- (void)_evaluateNameAndRange;
- (void)_evaluateTypeName;
- (id)description;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)equal;
- (void)insertObject:(id)object inChildrenAtIndex:(unsigned long long)index;
- (void)removeObjectFromChildrenAtIndex:(unsigned long long)index;
- (void)insertChild:(id)child atIndex:(long long)index;
- (void)removeChildAtIndex:(long long)index;
- (BOOL)isDeclaration;
- (long long)compareWithLandmarkItem:(id)item;
- (void)markForUpdate;
- (id)parentLandmarkItem;
- (long long)numberOfChildLandmarkItems;
- (id)childLandmarkItems;
- (id)landmarkItemName;
- (struct _NSRange)landmarkItemRange;
- (struct _NSRange)landmarkItemNameRange;
- (unsigned long long)landmarkItemType;
- (id)landmarkItemTypeName;
@end

#endif /* DVTSourceLandmarkItem_h */
