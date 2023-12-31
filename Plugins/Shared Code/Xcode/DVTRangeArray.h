//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTRangeArray_h
#define DVTRangeArray_h
#import <Foundation/Foundation.h>

@interface DVTRangeArray : NSArray {
  /* instance variables */
  unsigned long long _count;
  NSRange * _ranges;
}

/* class methods */
+ (void)initialize;

/* instance methods */
- (id)initWithObjects:(const id *)objects count:(unsigned long long)count;
- (id)initWithRanges:(const struct _NSRange *)ranges count:(unsigned long long)count;
- (id)initWithRange:(struct _NSRange)range;
- (id)init;
- (void)dealloc;
- (unsigned long long)hash;
- (BOOL)isEqualToArray:(id)array;
- (id)copyWithZone:(struct _NSZone *)zone;
- (id)mutableCopyWithZone:(struct _NSZone *)zone;
- (id)descriptionWithLocale:(id)locale;
- (unsigned long long)count;
- (id)objectAtIndex:(unsigned long long)index;
- (struct NSRange)rangeAtIndex:(unsigned long long)index;
- (unsigned long long)indexOfRange:(struct _NSRange)range;
- (struct NSRange)firstRange;
- (struct NSRange)lastRange;
- (unsigned long long)indexOfRangePreceding:(unsigned long long)preceding;
- (unsigned long long)indexOfRangeFollowing:(unsigned long long)following;
- (unsigned long long)indexOfRangeContainingOrPreceding:(unsigned long long)preceding;
- (unsigned long long)indexOfRangeContainingOrFollowing:(unsigned long long)following;
- (void)getRanges:(struct NSRange *)ranges count:(unsigned long long)count;
- (id)normalizedRangeArray;
- (id)sortedRangeArray;
@end

#endif /* DVTRangeArray_h */
