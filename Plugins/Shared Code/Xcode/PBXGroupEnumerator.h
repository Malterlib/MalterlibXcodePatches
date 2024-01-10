//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef PBXGroupEnumerator_h
#define PBXGroupEnumerator_h
#import <Foundation/Foundation.h>

@class NSMutableArray;

@interface PBXGroupEnumerator : NSEnumerator<NSCopying, NSFastEnumeration> {
  /* instance variables */
  NSMutableArray *_enumeratedObjects;
  unsigned long long _nextIndex;
  unsigned long long _count;
}

/* class methods */
+ (SEL)traversalSelector;
+ (id)enumeratorForGroup:(id)group;
+ (id)enumeratorForGroup:(id)group startingAtItem:(id)item;

/* instance methods */
- (id)initWithRootArray:(id)array nextObject:(id)object;
- (void)rewind;
- (id)copyWithZone:(struct _NSZone *)zone;
- (id)nextObject;
- (id)allObjects;
- (unsigned long long)numberOfObjects;
- (void)setNextObject:(id)object;
- (id)previousObject;
- (id)firstObject;
- (id)lastObject;
- (unsigned long long)countByEnumeratingWithState:(void *)state objects:(id *)objects count:(unsigned long long)count;
@end

#endif /* PBXGroupEnumerator_h */