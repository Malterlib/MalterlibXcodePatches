//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEBatchFindFileResult_h
#define IDEBatchFindFileResult_h
#import <Foundation/Foundation.h>

#include "IDEBatchFindAbstractResult.h"

@class DVTFilePath, NSString;

@interface IDEBatchFindFileResult : IDEBatchFindAbstractResult {
  /* instance variables */
  NSString *_contextualSuffix;
}

@property (readonly) DVTFilePath *filePath;

/* class methods */
+ (BOOL)supportsSecureCoding;

/* instance methods */
- (id)initWithFilePath:(id)path contextualSuffix:(id)suffix parent:(id)parent suggestedOrder:(long long)order childOrderingSelector:(SEL)selector queryIdentifier:(id)identifier resultIdentifier:(long long)identifier;
- (void)encodeWithCoder:(id)coder;
- (id)initWithCoder:(id)coder;
- (BOOL)contributesToFileResultCount;
- (BOOL)contributesToResultCount;
- (BOOL)emphasizesTitle;
- (BOOL)allowsSummarization;
- (BOOL)canHaveChildren;
- (id)textRepresentationForPasteboard;
- (BOOL)textIsFileName;
- (id)contextualSuffix;
@end

#endif /* IDEBatchFindFileResult_h */
