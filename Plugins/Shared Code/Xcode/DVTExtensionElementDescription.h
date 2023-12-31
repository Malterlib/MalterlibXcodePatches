//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTExtensionElementDescription_h
#define DVTExtensionElementDescription_h
#import <Foundation/Foundation.h>

#include "DVTExtensionPropertyDescription.h"

@class NSDictionary, NSSet, NSString;

@interface DVTExtensionElementDescription : DVTExtensionPropertyDescription

@property (copy) NSString *plural;
@property unsigned long long minOccurs;
@property unsigned long long maxOccurs;
@property (copy) NSDictionary *attributes;
@property (copy) NSDictionary *elements;
@property (copy) NSDictionary *properties;
@property (copy) NSSet *propertyKeys;

/* instance methods */
- (void)validateRequiredTypesArePresentForKeyPathPrefix:(id)prefix failureHandler:(id /* block */)handler;
- (id)initWithName:(id)name plural:(id)plural minOccurs:(unsigned long long)occurs maxOccurs:(unsigned long long)occurs optional:(BOOL)optional attributes:(id)attributes elements:(id)elements;
- (id)initWithPropertyList:(id)list owner:(id)owner;
- (void)awakeFromPropertyList;
- (void)encodeIntoPropertyList:(id)list;
- (void)_inheritAttributesAndElementsFromElementDescription:(id)description;
- (BOOL)populateSymbolNamesForSwiftProtocolDescriptorsWithModuleName:(id)name error:(id *)error;
@end

#endif /* DVTExtensionElementDescription_h */
