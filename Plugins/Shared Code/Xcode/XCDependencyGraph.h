//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef XCDependencyGraph_h
#define XCDependencyGraph_h
#import <Foundation/Foundation.h>

#include "PBXTargetBuildContext.h"
#include "XCDependencyNode.h"

@class NSMutableArray, NSMutableDictionary, NSSet, PBXTargetBuildContext, XCDependencyNode;

@interface XCDependencyGraph : NSObject {
  /* instance variables */
  PBXTargetBuildContext *_buildContext;
  NSMutableArray *_nodesByNumber;
  void * _nodesByNumberLock;
  XCDependencyNode *_rootNode;
  XCDependencyNode *_baseNode;
  NSMutableDictionary *_virtualNodesByIdent;
  void * _virtualNodesByIdentLock;
  NSMutableDictionary *_commandInvocRecordsByIdent;
  void * _commandInvocRecordsByIdentLock;
  NSMutableArray *_commandsByNumber;
  void * _commandsByNumberLock;
  void *_dependencyGraphFileInfo;
}

@property (copy) NSSet *buildActionProducedArtifactNodes;

/* class methods */
+ (id)dependencyGraphFilename;
+ (id)loadOrCreateInBuildDirectory:(id)directory withTargetBuildContext:(id)context withBasePath:(id)path;
+ (id)readFromBuildDirectory:(id)directory withTargetBuildContext:(id)context error:(id *)error;

/* instance methods */
- (id)initWithBasePath:(id)path targetBuildContext:(id)context;
- (id)init;
- (id)targetBuildContext;
- (id)basePath;
- (void)prepareForUpdatingDependencyGraph;
- (id)createNodeWithSupernode:(id)supernode nameCStr:(const char *)cstr length:(unsigned long long)length isVirtual:(BOOL)virtual;
- (id)nodeWithPath:(id)path relativeToNode:(id)node createIfNeeded:(BOOL)needed;
- (id)nodeWithPath:(id)path createIfNeeded:(BOOL)needed;
- (id)virtualNodeWithIdentifier:(id)identifier createIfNeeded:(BOOL)needed;
- (unsigned int)highestAssignedNodeNumber;
- (void)enumerateNodesUsingBlock:(id /* block */)block;
- (id)createCommandOfClass:(Class)class withIdentifier:(id)identifier macroExpansionScope:(id)scope;
- (id)createCommandWithIdentifier:(id)identifier macroExpansionScope:(id)scope;
- (id)createShadowCommandWithOriginalCommand:(id)command outputFilePath:(id)path subprocessCommandLineGenerationBlock:(id /* block */)block;
- (unsigned int)highestAssignedCommandNumber;
- (void)enumerateCommandsUsingBlock:(id /* block */)block;
- (id)createCommandInvocationRecordWithIdentifier:(id)identifier;
- (id)lookupCommandInvocationRecordWithIdentifier:(id)identifier;
- (id)initFromByteStream:(void *)stream withTargetBuildContext:(id)context error:(id *)error;
- (BOOL)writeToByteStream:(void *)stream error:(id *)error;
- (BOOL)_writeToByteStreamWhileLocked:(void *)locked error:(id *)error;
- (BOOL)isOutOfDateFromPersistedRepresentationInBuildDirectory:(id)directory;
- (BOOL)writeToBuildDirectory:(id)directory error:(id *)error;
- (BOOL)_writeToBuildDirectory:(id)directory forceWrite:(BOOL)write error:(id *)error;
- (void)invalidate;
- (BOOL)isValid;
- (void)printNodes;
- (id)description;
@end

#endif /* XCDependencyGraph_h */
