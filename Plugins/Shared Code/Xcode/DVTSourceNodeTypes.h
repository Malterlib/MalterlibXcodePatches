//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@interface DVTSourceNodeTypes : NSObject
{
}

+ (BOOL)nodeType:(short)arg1 conformsToNodeTypesInList:(const long long *)arg2;
+ (long long *)nodeTypeListForTypeNames:(id)arg1;
+ (BOOL)nodeType:(short)arg1 conformsToNodeTypeNamed:(id)arg2;
+ (long long)nodeTypesCount;
+ (id)nodeTypeNameForId:(short)arg1;
+ (short)registerNodeTypeNamed:(id)arg1;
+ (void)initialize;

@end

