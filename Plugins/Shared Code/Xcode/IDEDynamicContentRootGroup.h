//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEDynamicContentRootGroup_h
#define IDEDynamicContentRootGroup_h
#import <Foundation/Foundation.h>

#include "IDEGroup.h"

@interface IDEDynamicContentRootGroup : IDEGroup
/* instance methods */
- (BOOL)canStructureEditName;
- (BOOL)canStructureEditInsertFileURLs:(id)urls atIndex:(unsigned long long)index;
- (BOOL)canStructureEditInsertSubitems:(id)subitems atIndex:(unsigned long long)index;
- (BOOL)canStructureEditRemoveSubitemsAtIndexes:(id)indexes;
- (BOOL)canStructureEditSortSubitemsAtIndexes:(id)indexes sortStyle:(unsigned long long)style;
@end

#endif /* IDEDynamicContentRootGroup_h */
