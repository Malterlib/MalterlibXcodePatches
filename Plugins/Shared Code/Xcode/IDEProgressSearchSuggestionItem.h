//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEProgressSearchSuggestionItem_h
#define IDEProgressSearchSuggestionItem_h
#import <Foundation/Foundation.h>

@class NSAttributedString, NSString;

@interface IDEProgressSearchSuggestionItem : NSObject

@property BOOL isHeader;
@property BOOL isSeparatorItem;
@property (copy) NSString *titleFormat;
@property (copy) NSAttributedString *title;
@property (copy) NSString *subtitle;
@property long long tag;
@property (retain) id representedObject;
@property (copy) id /* block */ actionBlock;
@property BOOL isHidden;

/* class methods */
+ (id)separatorItem;
+ (id)headerWithTitle:(id)title;

/* instance methods */
- (id)initWithTitleFormat:(id)format;
- (id)initWithTitle:(id)title;
@end

#endif /* IDEProgressSearchSuggestionItem_h */