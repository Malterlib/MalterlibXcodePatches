//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEntityIdentifier_h
#define IDEEntityIdentifier_h
#import <Foundation/Foundation.h>

@class NSDictionary, NSString;

@interface IDEEntityIdentifier : NSObject<NSCopying> {
  /* instance variables */
  unsigned long long _hashValue;
}

@property (readonly, copy) NSString *containerNameWithoutProjectOrWorkspaceSuffix;
@property (readonly, copy) NSString *entityName;
@property (readonly, copy) NSString *containerName;
@property (readonly) long long entityType;
@property (readonly, copy) NSString *entityGUID;
@property (readonly) long long sharedState;
@property (readonly, copy) NSDictionary *dictionaryRepresentation;

/* class methods */
+ (id)entityIdentifierFromGUID:(id)guid entityName:(id)name entityType:(long long)type containerName:(id)name isShared:(BOOL)shared;
+ (id)entityIdentifierFromGUID:(id)guid entityName:(id)name entityType:(long long)type containerName:(id)name;
+ (id)entityIdentifierFromEntityName:(id)name entityType:(long long)type containerName:(id)name isShared:(BOOL)shared;
+ (id)entityIdentifierFromEntityName:(id)name entityType:(long long)type containerName:(id)name;

/* instance methods */
- (id)initWithGUID:(id)guid entityName:(id)name entityType:(long long)type containerName:(id)name shared:(long long)shared;
- (id)initWithDictionaryRepresentation:(id)representation error:(id *)error;
- (BOOL)isEqual:(id)equal;
- (id)description;
- (unsigned long long)hash;
- (BOOL)isSimilarToEntityIdentifier:(id)identifier;
- (id)copyWithZone:(struct _NSZone *)zone;
@end

#endif /* IDEEntityIdentifier_h */
