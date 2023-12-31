//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDETabbedWindow_h
#define IDETabbedWindow_h
#import <Foundation/Foundation.h>



@interface IDETabbedWindow : NSWindow

@property BOOL tabBarIsVisible;

/* instance methods */
- (BOOL)validateMenuItem:(id)item;
- (id)currentlySelectedTabbedWindow;
- (void)closeOtherWindowTabs:(id)tabs;
@end

#endif /* IDETabbedWindow_h */
