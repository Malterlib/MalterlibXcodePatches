//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTTextCompletionItem_Protocol_h
#define DVTTextCompletionItem_Protocol_h
#import <Foundation/Foundation.h>

#include "DVTRangeArray.h"

@class DVTSourceCodeLanguage;

@protocol DVTTextCompletionItem <NSObject>

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *displayText;
@property (nonatomic, readonly) NSAttributedString *attributedDisplayType;
@property (nonatomic, readonly) NSString *displayType;
@property (nonatomic, readonly) NSString *briefDisplayText;
@property (nonatomic, readonly) DVTRangeArray *nameRanges;
@property (nonatomic, readonly) DVTRangeArray *displayTextRanges;
@property (nonatomic, readonly) DVTRangeArray *briefDisplayTextRanges;
@property (nonatomic, readonly) NSAttributedString *attributedDisplaySignature;
@property (nonatomic, readonly) NSString *displaySignature;
@property (nonatomic, readonly) long long debugTag;
@property (nonatomic, readonly) DVTTextCompletionIssue *issue;
@property (nonatomic, readonly) NSString *completionText;
@property (nonatomic, readonly) DVTSourceCodeLanguage *language;
@property (nonatomic, readonly) NSString *parentText;
@property (nonatomic, readonly) NSAttributedString *descriptionText;
@property (nonatomic, readonly) NSImage *icon;
@property (nonatomic, readonly) long long priorityBucket;
@property (nonatomic, readonly) unsigned long long priorityComparatorKind;
@property (nonatomic) double priority;
@property (nonatomic) double fuzzyMatchingScore;
@property (nonatomic, retain) DVTRangeArray *fuzzyMatchingRanges;
@property (nonatomic, readonly) BOOL notRecommended;
@property (nonatomic, readonly) NSString *accessibilityLabel;
@property (nonatomic, readonly) int completionItemStyle;
@property (nonatomic, readonly) NSArray *additionalCompletions;
@property (nonatomic, readonly) NSImage *statusIcon;
@property (nonatomic, readonly) NSImage *highlightedStatusIcon;
@property (nonatomic, readonly) NSString *action;
@property (nonatomic, readonly) NSString *usr;

@optional
/* instance methods */
- (void)attributedInfoWithContext:(id)context completionBlock:(id /* block */)block;
- (void)attributedInfoWithContext:(id)context completionBlock:(id /* block */)block;
- (unsigned long long)leadingCharactersToReplaceFromString:(id)string location:(unsigned long long)location;
- (unsigned long long)leadingCharactersToReplaceFromString:(id)string location:(unsigned long long)location;
@end

#endif /* DVTTextCompletionItem_Protocol_h */
