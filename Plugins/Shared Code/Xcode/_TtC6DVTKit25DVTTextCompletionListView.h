//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef _TtC6DVTKit25DVTTextCompletionListView_h
#define _TtC6DVTKit25DVTTextCompletionListView_h
#import <Foundation/Foundation.h>

#include "DVTTextCompletionFormatContext.h"
#include "DVTTextCompletionIssue.h"
#include "DVTTextCompletionItem-Protocol.h"

@class DVTStructuredLayoutTextField, NSAttributedString, NSNumber, NSObject, NSScreen, NSString, NSTableView;

@interface DVTKit_DVTTextCompletionListView : NSObject { // (Swift)
  /* instance variables */
   void * measurementCellView;
   void * placeholderField;
   void * completionArea;
   void * completionScrollView;
   void * signatureArea;
   void * _signatureField;
   void * signatureView;
   void * chinDivider;
   void * quickHelpArea;
   void * issueDivider;
   void * issueView;
   void * messageDivider;
   void * messageArea;
   void * messageField;
   void * debugTagLayer;
   void * _previousWidth;
   void * _pinnedWidth;
   void * _pinnedWindowX;
   void * _pinnedOrientation;
   void * previousQuickHelpFieldHeight;
   void * wasShowingPlaceholder;
}

@property (nonatomic, readonly) NSTableView *completionTableView;
@property (nonatomic, readonly) DVTStructuredLayoutTextField *quickHelpField;
@property (nonatomic, readonly) unsigned long long lineBreakModeForSignatureField;
@property (nonatomic, retain) NSObject<DVTTextCompletionItem> *longestInitialItem;
@property (nonatomic, retain) NSObject *longestInitialSignatureValue;
@property (nonatomic, retain) DVTTextCompletionFormatContext *formatContextForLongestInitialItem;
@property (nonatomic, retain) NSNumber *numberOfCompletionItems;
@property (nonatomic, retain) NSScreen *targetScreen;
@property (nonatomic) struct CGRect typingLocation;
@property (nonatomic, retain) NSObject *signatureValue;
@property (nonatomic, retain) NSAttributedString *quickHelpValue;
@property (nonatomic, copy) NSString *quickHelpPlaceholder;
@property (nonatomic) long long debugTag;
@property (nonatomic, retain) DVTTextCompletionIssue *issue;
@property (nonatomic, retain) NSAttributedString *message;
@property (nonatomic, readonly) BOOL showsPlaceholder;
@property (nonatomic, readonly) BOOL flipped;

/* instance methods */
- (id)initWithCoder:(id)coder;
- (id)init;
- (BOOL)isFlipped;
- (void)dvt_configureSubviewsBeforeSubviewLayout;
- (void)dvt_positionSubviewsAndSizeSelfAfterSubviewLayout;
- (void)showAccessoryWindow;
- (void)hideAccessoryWindow;
- (BOOL)accessoryWindowCanHandleMouseEvent:(id)event;
- (void)viewDidEndLiveResize;
- (void)prepareForNewSession;
- (id)initWithFrame:(struct CGRect)frame;
@end

#endif /* _TtC6DVTKit25DVTTextCompletionListView_h */