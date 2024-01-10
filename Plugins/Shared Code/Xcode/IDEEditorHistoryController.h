//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEditorHistoryController_h
#define IDEEditorHistoryController_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"

@protocol IDEEditorHistoryControllerDelegate;
@class DVTDelayedMenuGradientImageButton, DVTStackBacktrace, NSArray, NSImage, NSMutableArray, NSString;

@interface IDEEditorHistoryController : NSObject<DVTInvalidation> {
  /* instance variables */
  NSImage *_defaultBackButtonImage;
  NSImage *_defaultForwardButtonImage;
}

@property (readonly, nonatomic) NSObject<IDEEditorHistoryControllerDelegate> *delegate;
@property (readonly) NSMutableArray *mutableNextHistoryItems;
@property (readonly) NSMutableArray *mutablePreviousHistoryItems;
@property (readonly) BOOL canGoForwardByCommand;
@property (readonly) BOOL canGoBackByCommand;
@property (readonly) BOOL canSelectForwardButton;
@property (readonly) BOOL canSelectBackButton;
@property (readonly) DVTDelayedMenuGradientImageButton *forwardButton;
@property (readonly) DVTDelayedMenuGradientImageButton *backButton;
@property (copy) NSArray *nextHistoryItems;
@property (copy) NSArray *previousHistoryItems;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (long long)historySizeLimit;
+ (id)_historyButtonWithImage:(id)image width:(double)width height:(double)height;
+ (BOOL)canEditorHistoryUseDocumentURL:(id)url checkIsFileURLReachable:(BOOL)urlreachable;
+ (id)keyPathsForValuesAffectingCanSelectBackButton;
+ (id)keyPathsForValuesAffectingCanSelectForwardButton;
+ (id)keyPathsForValuesAffectingCanGoBackByCommand;
+ (id)keyPathsForValuesAffectingCanGoForwardByCommand;

/* instance methods */
- (id)initWithDelegate:(id)delegate navBarHeight:(double)height;
- (void)addHistoryEditorHistoryItem:(id)item filterAdjacentEntriesWithIdenticalNavigableItems:(BOOL)items;
- (BOOL)selectEditorHistoryItem:(id)item;
- (BOOL)selectHistoryItemInThisEditorContext:(id)context forward:(BOOL)forward captureHistory:(BOOL)history;
- (void)_goToEditorHistoryItem:(id)item;
- (BOOL)goBackInHistoryToNowhere;
- (void)_removeHistoryItemsForDocumentURL:(id)url goingForward:(BOOL)forward;
- (id)_lastHistoryItemNotMatchingDocumentURL:(id)url goingForward:(BOOL)forward;
- (void)forgetHistoryWithCurrentDocumentWithURL:(id)url;
- (BOOL)selectHistoryItemWithDifferentDocumentURL:(id)url navigationBlock:(id /* block */)block;
- (id)backControl;
- (id)forwardControl;
- (void)primitiveInvalidate;
- (BOOL)canSelectButtonGoingForward:(BOOL)forward;
- (void)_goByButtonClickGoingForward:(BOOL)forward;
- (void)goForwardInHistoryByButtonClick:(id)click;
- (void)goBackInHistoryEntryByButtonClick:(id)click;
- (void)goForwardInHistoryToThisEntry:(id)entry;
- (void)goBackInHistoryToThisEntry:(id)entry;
- (void)_removeUnreachableHistoryItemsGoingForward:(BOOL)forward;
- (id)_historyButtonMenuWithDirectionForward:(BOOL)forward;
- (id)goForwardMenu;
- (id)goBackMenu;
- (void)_goByMenuCommandGoingForward:(BOOL)forward;
- (void)goForwardInHistoryByCommand:(id)command;
- (void)goBackInHistoryByCommand:(id)command;
- (void)goForwardInHistoryByCommandWithAlternate:(id)alternate;
- (void)goForwardInHistoryByCommandWithShiftPlusAlternate:(id)alternate;
- (void)goBackInHistoryByCommandWithAlternate:(id)alternate;
- (void)goBackInHistoryByCommandWithShiftPlusAlternate:(id)alternate;
@end

#endif /* IDEEditorHistoryController_h */