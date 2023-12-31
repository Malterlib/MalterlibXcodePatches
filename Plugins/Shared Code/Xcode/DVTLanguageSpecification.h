//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTLanguageSpecification_h
#define DVTLanguageSpecification_h
#import <Foundation/Foundation.h>

#include "DVTSourceSpecification.h"
#include "DVTSourceModelParserProductionRule.h"
#include "DVTSourceScanner.h"

@class NSDictionary, NSString;

@interface DVTLanguageSpecification : DVTSourceSpecification

@property (readonly) long long uniqueId;
@property (readonly) BOOL includeInMenu;
@property (readonly) BOOL usesCLikeIndentation;
@property (readonly) Class scannerClass;
@property (readonly) BOOL preservesTrailingWhitespace;
@property (readonly) DVTSourceScanner *scanner;
@property (readonly) NSDictionary *syntaxRules;
@property (readonly) NSString *syntaxType;
@property (retain) DVTSourceModelParserProductionRule *productionRule;

/* class methods */
+ (Class)specificationTypeBaseClass;
+ (id)specificationType;
+ (id)localizedSpecificationTypeName;
+ (id)specificationTypePathExtensions;
+ (id)specificationRegistryName;
+ (long long)_uniqueIdForIdentifier:(id)identifier;
+ (id)identifierForUniqueId:(long long)id;

/* instance methods */
- (id)initWithPropertyListDictionary:(id)dictionary;
- (id)name;
- (id)lexerKeywords;
- (id)availableKeywords;
@end

#endif /* DVTLanguageSpecification_h */
