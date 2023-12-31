//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22504.0.0.0.0
//
#ifndef IDEConsoleAreaProtocol_Protocol_h
#define IDEConsoleAreaProtocol_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDEConsoleAreaProtocol <NSObject>

@property (nonatomic, readonly) DVTScopeBarView *scopeBarView;

/* instance methods */
- (void)activateConsole;
- (void)clearConsole:(id)console;
- (void)reloadConsole:(id)console;
@optional
/* instance methods */
- (BOOL)canSelectLastOutput;
- (void)selectLastOutput;
- (BOOL)validateUserInterfaceItem:(id)item;
- (BOOL)validateUserInterfaceItem:(id)item;
- (void)copyGroupWithVisibleMetadata:(id)metadata;
- (void)copyGroupWithAllMetadata:(id)metadata;
- (void)copyGroupWithoutMetadata:(id)metadata;
- (void)jumpToSource:(id)source;
- (void)showHideSimilarItems:(id)items;
@end

#endif /* IDEConsoleAreaProtocol_Protocol_h */
