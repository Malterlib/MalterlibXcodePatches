//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@class NSArray, NSDictionary, NSSet, NSString, PBXFileType, PBXObjectID, XCBuildInfo;
@protocol DVTMacroExpansion;

@interface XCBuildFileRefDGSnapshot : NSObject
{
    PBXObjectID *_referenceGlobalID;
    PBXObjectID *_groupGlobalID;
    NSString *_path;
    PBXFileType *_fileType;
    NSDictionary *_fileProperties;
    XCBuildInfo *_buildInfo;
    NSString *_buildFilePrimaryAttrString;
    NSArray<DVTMacroExpansion> *_addlCompilerArgs;
    BOOL _isInVariantGroup;
    BOOL _linkUsingSearchPath;
    NSString *_regionVariantName;
    NSSet *_attributes;
    NSSet *_assetTags;
    NSSet *_internalAssetTagSets;
    NSSet *_platformFilters;
    NSString *_fileTextEncodingName;
}

// - (void).cxx_destruct;
@property(readonly) NSString *fileTextEncodingName; // @synthesize fileTextEncodingName=_fileTextEncodingName;
- (id)platformFilters;
- (id)description;
- (BOOL)linkUsingSearchPath;
- (id)additionalCompilerArguments;
- (id)internalAssetTagSets;
- (id)assetTags;
- (BOOL)hasAssetTags;
- (id)attributes;
- (BOOL)boolValueOfAttributeNamed:(id)arg1;
- (id)pathForWrapperPart:(long long)arg1;
- (id)subpathForWrapperPart:(long long)arg1;
- (id)regionVariantName;
- (BOOL)isLocalizable;
- (BOOL)isInVariantGroup;
- (id)fileProperties;
- (id)fileType;
- (id)path;
- (id)groupGlobalID;
- (id)referenceGlobalID;
- (id)stringValueForPrimaryAttribute;
- (id)buildInfo;
- (void)printForDebugging;
- (id)init;
- (id)initWithPath:(id)arg1 fileType:(id)arg2 regionVariantName:(id)arg3;
- (id)initWithDependencyNode:(id)arg1 fileType:(id)arg2 buildSettings:(id)arg3;
- (id)initWithInformationFromBuildFile:(id)arg1 fileReference:(id)arg2 groupReference:(id)arg3 forTargetSnapshot:(id)arg4 withResolver:(id)arg5;
- (void)enumerateUsingBlock:(CDUnknownBlockType)arg1 macroExpansionScope:(id)arg2;

@end

