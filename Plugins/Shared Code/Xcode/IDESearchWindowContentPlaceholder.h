//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDESearchWindowContentPlaceholder_h
#define IDESearchWindowContentPlaceholder_h
#import <Foundation/Foundation.h>

#include "DVTEmptyContentPlaceholderContainer-Protocol.h"

@class NSFont, NSString;

@interface IDESearchWindowContentPlaceholder : NSView<DVTEmptyContentPlaceholderContainer> {
  /* instance variables */
  BOOL _hasRunEmptyContentPlaceholderLayout;
}

@property (copy, nonatomic) NSString *emptyContentString;
@property (copy, nonatomic) NSString *emptyContentSubtitle;
@property (nonatomic) long long emptyContentStringStyle;
@property (copy, nonatomic) NSFont *emptyContentFont;
@property (nonatomic) BOOL hasContent;
@property (nonatomic) BOOL isLoadingContent;
@property (copy, nonatomic) NSString *emptyContentButtonTitle;
@property (nonatomic) BOOL followsFontAndColorTheme;

/* instance methods */
- (id)initWithFrame:(struct CGRect)frame;
- (void)layout;
@end

#endif /* IDESearchWindowContentPlaceholder_h */