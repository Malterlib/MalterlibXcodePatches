//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEDebugArea_h
#define IDEDebugArea_h
#import <Foundation/Foundation.h>

#include "IDEViewController.h"
#include "IDEConsoleAreaProtocol-Protocol.h"
#include "IDEVariablesView.h"

@class NSString;

@interface IDEDebugArea : IDEViewController

@property (readonly) NSString *stateSavingIdentifier;
@property (readonly) NSObject<IDEConsoleAreaProtocol> *consoleArea;
@property (readonly) IDEVariablesView *variablesView;

/* class methods */
+ (id)createShowLeftViewButton;
+ (id)createShowRightViewButton;

/* instance methods */
- (void)loadView;
- (BOOL)canClearConsole;
- (void)clearConsole;
- (BOOL)canReloadConsole;
- (void)reloadConsole;
- (BOOL)canActivateConsole;
- (void)activateConsole;
- (BOOL)canSelectLastOutput;
- (void)selectLastOutput;
- (BOOL)validateUserInterfaceItem:(id)item;
- (void)copyGroupWithVisibleMetadata:(id)metadata;
- (void)copyGroupWithAllMetadata:(id)metadata;
- (void)copyGroupWithoutMetadata:(id)metadata;
- (void)jumpToSource:(id)source;
- (void)showHideSimilarItems:(id)items;
@end

#endif /* IDEDebugArea_h */
