//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTMacroDefinitionTable_h
#define DVTMacroDefinitionTable_h
#import <Foundation/Foundation.h>

#include "DVTMacroDefinitionTable.h"
#include "DVTStackBacktrace.h"

@class NSDictionary, NSSet, NSString;

@interface DVTMacroDefinitionTable : NSObject<NSCopying, NSMutableCopying> {
  /* instance variables */
  struct DVTMacroValueAssignmentMapTable { unsigned int x0; unsigned int x1; unsigned int x2; unsigned int x3; void * x4; void * x5; } * _mapTable;
  DVTStackBacktrace *_creationBacktrace;
  DVTMacroDefinitionTable *_originalTable;
  NSDictionary *_cachedDictRep;
  NSSet *_cachedMacroNameSet;
  unsigned long long _cachedHash;
  void * _cacheLock;
  BOOL _isImmutable;
  BOOL _declaredMutable;
}

@property (copy) NSString *label;
@property BOOL postsChangeNotifications;
@property (copy) id /* block */ willSetValueBlock;
@property (copy) id /* block */ didSetValueBlock;

/* class methods */
+ (id)newWithLabel:(id)label;
+ (id)empty;
+ (id)macroNameRegistry;

/* instance methods */
- (id)initWithLabel:(id)label creationBacktrace:(id)backtrace;
- (id)initWithLabel:(id)label;
- (id)init;
- (void)dealloc;
- (unsigned long long)numberOfMacros;
- (unsigned long long)numberOfDefinitions;
- (unsigned long long)count;
- (unsigned long long)hash;
- (BOOL)isEqual:(id)equal;
- (void)discardCaches;
- (void)setValue:(id)value forMacroName:(id)name conditionSet:(id)set;
- (void)setStringValue:(id)value forMacroName:(id)name conditionSet:(id)set;
- (void)setLiteralValue:(id)value forMacroName:(id)name conditionSet:(id)set;
- (void)_setLiteralValue:(id)value forMacroName:(id)name conditionSet:(id)set wantsCheckForDVTMacroExpansionConformance:(BOOL)conformance;
- (void)parseAndSetValue:(id)value forMacroName:(id)name conditionSet:(id)set;
- (id)valueForMacroName:(id)name conditionSet:(id)set;
- (void)removeAllConditionSetsForMacroName:(id)name;
- (void)enumerateValuesForMacroName:(id)name usingBlock:(id /* block */)block;
- (void)enumerateMacroNamesAndValuesUsingBlock:(id /* block */)block;
- (id)dictionaryRepresentation;
- (id)allMacroNames;
- (void)setMacroNamesAndValuesFromDictionary:(id)dictionary;
- (void)setMacroNamesAndValuesFromMacroDefinitionTable:(id)table;
- (void)removeMacroName:(id)name;
- (void)removeMacroNames:(id)names arguments:(char *)arguments;
- (void)removeMacroNames:(id)names;
- (void)removeAllMacros;
- (id)copyWithZone:(struct _NSZone *)zone;
- (id)copyWithLabel:(id)label;
- (id)mutableCopyWithZone:(struct _NSZone *)zone;
- (BOOL)isImmutable;
- (void)makeImmutable;
- (void)declareMutable;
- (id)valueForKey:(id)key;
- (id)objectForKeyedSubscript:(id)subscript;
- (void)setObject:(id)object forKeyedSubscript:(id)subscript;
- (void)assertInternalConsistency;
- (id)descriptionWithLocale:(id)locale indent:(unsigned long long)indent;
- (id)description;
@end

#endif /* DVTMacroDefinitionTable_h */
