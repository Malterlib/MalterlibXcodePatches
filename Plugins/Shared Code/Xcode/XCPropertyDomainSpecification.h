//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "XCSpecification.h"

@class DVTMacroDefinitionTable, NSArray, NSDictionary, NSSet;

@interface XCPropertyDomainSpecification : XCSpecification
{
    NSSet *_deletedOptionNames;
    NSDictionary *_buildOptions;
    NSArray *_orderedBuildOptions;
    NSArray *_optionNamesForCommandLine;
    NSArray *_buildOptionCategories;
    NSSet *_buildOptionConditionFlavors;
    XCPropertyDomainSpecification *_specForUserInterface;
    NSDictionary *_flattenedBuildOptions;
    NSArray *_flattenedOrderedBuildOptions;
    NSArray *_flattenedCommonBuildOptions;
    NSArray *_flattenedOptionNamesForCommandLine;
    NSArray *_flattenedOptionCategories;
    DVTMacroDefinitionTable *_flattenedDefaultValues;
    DVTMacroDefinitionTable *_flattenedDefaultValuesTable;
    DVTMacroDefinitionTable *_defaultOptionValues;
}

+ (id)allRegisteredPropertiesForName:(id)arg1;
+ (id)propertyDomainForIdentifier:(id)arg1 inSpecificationDomain:(id)arg2;
+ (id)allRegisteredPropertyDomainsInSpecificationDomain:(id)arg1;
+ (id)allRegisteredSpecificationDomains;
+ (id)dictionaryOfallRegisteredPropertyDomainsInSpecificationDomain:(id)arg1;
+ (void)registerSpecificationOrProxy:(id)arg1;
+ (id)specificationRegistryName;
+ (id)specificationTypePathExtensions;
+ (id)localizedSpecificationTypeName;
+ (id)specificationType;
+ (Class)specificationTypeBaseClass;
// - (void).cxx_destruct;
- (id)defaultMacrosForAllOptions;
- (void)_addToDefaultMacros:(id)arg1;
- (id)specificationToShowInUserInterface;
- (id)buildOptionConditionFlavors;
- (id)namesOfFlattenedOptionsForCommandLine;
- (id)namesOfBuildOptionsForCommandLine;
- (id)flattenedOptionCategories;
- (id)buildOptionCategories;
- (id)orderedSelfDefinedBuildOptions;
- (id)orderedBuildOptions;
- (id)buildOptionNamed:(id)arg1;
- (id)buildOptions;
- (id)directlyDeclaredBuildOptions;
- (id)initWithPropertyListDictionary:(id)arg1 inDomain:(id)arg2;

@end

