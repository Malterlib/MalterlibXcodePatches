//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTFileSystemRepresentationProviding-Protocol.h"

@class DVTFileDataType, DVTFileSystemVNode, NSArray, NSDate, NSDictionary, NSNumber, NSString, NSURL;

@interface DVTFilePath : NSObject <NSCopying, DVTFileSystemRepresentationProviding, NSSecureCoding>
{
    DVTFilePath *_parentPath;
    struct fastsimplearray *_childfsaPaths;
    DVTFileSystemVNode *_vnode;
    DVTFileDataType *_presumedType;
    unsigned int _numAssociates;
    unsigned int _numObservers;
    id _associates;
    NSString *_pathString;
    NSURL *_fileURL;
    struct DVTUnfairLock _childPathsLock;
    struct DVTUnfairLock _associatesLock;
    unsigned short _fsrepLength;
    _Atomic unsigned char _validationState;
    BOOL _hasResolvedVnode;
    BOOL _cleanRemoveFromParent;
    char _fsrep[0];
}

+ (void)_registerStandardCachedFileInfoDerivationFunctionsIfNeeded;
+ (CDUnknownFunctionPointerType)_cachedInfoDerivationFunctionForKey:(id)arg1 derivationLock:(id *)arg2;
+ (void)_registerCachedInfoDerivationFunction:(CDUnknownFunctionPointerType)arg1 forKey:(id)arg2 shouldUsePerVnodeLock:(BOOL)arg3;
+ (void)registerCachedInfoDerivationFunction:(CDUnknownFunctionPointerType)arg1 forKey:(id)arg2;
+ (id)filePathForFileURL:(id)arg1;
+ (id)filePathForPathString:(id)arg1;
+ (id)filePathForFileSystemRepresentation:(const char *)arg1;
+ (id)filePathForFileSystemRepresentation:(const char *)arg1 length:(unsigned long long)arg2;
+ (id)_filePathForParent:(id)arg1 pathString:(id)arg2;
+ (id)_filePathForParent:(id)arg1 fileSystemRepresentation:(const char *)arg2 length:(unsigned long long)arg3 allowCreation:(BOOL)arg4;
+ (BOOL)supportsSecureCoding;
+ (id)_lookupOrCreateFilePathWithParentPath:(id)arg1 fileSystemRepresentation:(const char *)arg2 length:(unsigned long long)arg3 allowCreation:(BOOL)arg4;
+ (id)rootFilePath;
+ (void)initialize;
// - (id).cxx_construct;
// - (void).cxx_destruct;
- (id)_descriptionOfAssociates;
- (id)description;
- (void)dvt_provideFileSystemRepresentationToBlock:(CDUnknownBlockType)arg1;
- (long long)comparePathString:(id)arg1;
- (void)simulateFileSystemNotificationAndNotifyAssociatesForUnitTests;
- (void)removeAllAssociates;
- (void)removeAssociate:(id)arg1;
- (void)removeAssociatesWithRole:(id)arg1;
- (void)removeAssociate:(id)arg1 withRole:(id)arg2;
- (void)addAssociate:(id)arg1 withRole:(id)arg2 observingDidChangeRecursively:(BOOL)arg3 onOperationQueue:(id)arg4 block:(CDUnknownBlockType)arg5;
- (void)addAssociate:(id)arg1 withRole:(id)arg2 observingDidChangeRecursively:(BOOL)arg3 onDispatchQueue:(id)arg4 block:(CDUnknownBlockType)arg5;
- (void)addAssociate:(id)arg1 withRole:(id)arg2;
- (id)associatesWithRole:(id)arg1;
- (id)associatesWithRole:(id)arg1 forAllPathsToSameFile:(BOOL)arg2;
- (void)_addAssociatesWithRole:(id)arg1 toArray:(id *)arg2;
- (void)_notifyAssociatesOfChange;
- (BOOL)_hasChangeObservers;
- (BOOL)_addInfoForObserversOfChangedFilePath:(id)arg1 toObjects:(id)arg2 roles:(id)arg3 blocks:(id)arg4 dispatchQueues:(id)arg5 operationQueues:(id)arg6;
- (id)cachedValueForKey:(id)arg1;
- (id)recursiveFileSizeWithError:(id *)arg1;
@property(readonly) NSNumber *recursiveFileSize;
- (id)machOArchitecturesWithError:(id *)arg1;
@property(readonly) DVTFileDataType *fileDataTypePresumed;
@property(readonly) DVTFileDataType *fileDataTypeFromFileContent;
@property(readonly) DVTFilePath *symbolicLinkDestinationFilePath;
@property(readonly) NSURL *fileReferenceURL;
@property(readonly) NSDictionary *fileSystemAttributes;
@property(readonly) NSDictionary *fileAttributes;
@property(readonly) NSString *fileTypeAttribute;
@property(readonly) BOOL isDirectory;
@property(readonly) NSArray *sortedDirectoryContents;
- (id)directoryContentsWithError:(id *)arg1;
@property(readonly) NSArray *directoryContents;
@property(readonly) NSDate *modificationDate;
@property(readonly) BOOL isExcludedFromBackup;
@property(readonly) BOOL isSymbolicLink;
@property(readonly) BOOL isExecutable;
@property(readonly) BOOL isDeletable;
@property(readonly) BOOL isWritable;
@property(readonly) BOOL isReadable;
@property(readonly) BOOL existsInFileSystem;
- (void)performCoordinatedReadRecursively:(BOOL)arg1;
- (void)excludeFromBackup;
- (BOOL)_hasResolvedVnode;
- (id)_locked_vnode;
- (id)_locked_vnodeKnownDoesNotExist:(BOOL)arg1;
- (void)_invalidateFilePathAndChildrenIncludingEquivalents;
- (void)_invalidateFilePathAndChildren;
- (void)invalidateFilePath;
- (void)_invalidateKnownDoesNotExist:(BOOL)arg1 explicitlyInvalidateChildren:(BOOL)arg2;
- (void)_invalidateChildrenRecursivelyKnownDoesNotExist:(BOOL)arg1;
- (void)_locked_validateTentativelyInvalidatedChildrenRecursively;
- (void)_locked_tentativelyInvalidateChildrenRecursivelyWithChildrenShouldBeTentativelyInvalid:(BOOL)arg1;
- (BOOL)isSameFileAsFilePath:(id)arg1;
- (BOOL)isEqual:(id)arg1;
- (id)relativePathStringFromFilePath:(id)arg1;
- (id)relativePathStringFromAncestorFilePath:(id)arg1;
- (void)invokeWithAccessToFileSystemRepresentation:(CDUnknownBlockType)arg1;
- (void)invokeWithAccessToFileSystemRepresentationAndLength:(CDUnknownBlockType)arg1;
- (void)invokeWithAccessToHeapAllocatedFileSystemRepresentationAndLength:(CDUnknownBlockType)arg1;
- (const char *)fileNameFSRepReturningLength:(long long *)arg1;
- (BOOL)_fileNameHasSuffix:(const char *)arg1 suffixLength:(long long)arg2;
- (BOOL)getFullFileSystemRepresentationIntoBuffer:(char **)arg1 ofLength:(unsigned long long)arg2 allowAllocation:(BOOL)arg3;
@property(readonly) NSString *pathExtension;
@property(readonly) NSString *fileName;
@property(readonly) NSURL *fileURL;
@property(readonly) NSArray *pathComponents;
@property(readonly) NSString *pathString;
- (id)filePathForUniqueRelativeDirectoryWithPrefix:(id)arg1 error:(id *)arg2;
- (id)filePathForUniqueRelativeFileWithPrefix:(id)arg1 error:(id *)arg2;
- (id)filePathForRelativePathString:(id)arg1;
- (id)filePathForRelativeFileSystemRepresentation:(const char *)arg1;
- (id)filePathForRelativeFileSystemRepresentation:(const char *)arg1 length:(unsigned long long)arg2;
- (id)firstAncestorPassingTest:(CDUnknownBlockType)arg1;
- (BOOL)isAncestorOfFilePath:(id)arg1;
@property(readonly) DVTFilePath *volumeFilePath;
@property(readonly) DVTFilePath *parentFilePath;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)init;
- (void)_invokeWithLockedAssociates:(CDUnknownBlockType)arg1;
- (void)_invokeWithLockedChildPaths:(CDUnknownBlockType)arg1;
- (void)dealloc;

@end

