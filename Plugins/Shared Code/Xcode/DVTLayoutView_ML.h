//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTLayoutView_ML_h
#define DVTLayoutView_ML_h
#import <Foundation/Foundation.h>

#include "DVTStructuredLayoutView-Protocol.h"
#include "DVTStructuredLayoutViewState.h"

@interface DVTLayoutView_ML : NSView<DVTStructuredLayoutView> {
  /* instance variables */
  BOOL _implementsDrawRect;
}

@property (readonly) DVTStructuredLayoutViewState *dvt_layoutState;

/* class methods */
+ (void)initialize;

/* instance methods */
- (void)layoutTopDown;
- (void)layoutBottomUp;
- (void)didCompleteLayout;
- (void)willLayoutSubview:(id)subview;
- (void)didLayoutSubview:(id)subview;
- (void)layoutIfNeeded;
- (void)invalidateLayout;
- (void)setNeedsSecondLayoutPass:(BOOL)pass;
- (void)invalidateLayoutWithFrameChangesToView:(id)view;
- (void)invalidateLayoutWithFrameChangesToViews:(id)views;
- (void)stopInvalidatingLayoutWithFrameChangesToView:(id)view;
- (void)stopInvalidatingLayoutWithFrameChangesToViews:(id)views;
- (void)invalidateLayoutWithChangesToKeyPath:(id)path ofObject:(id)object;
- (void)stopInvalidatingLayoutWithChangesToKeyPath:(id)path ofObject:(id)object;
- (void)_DVTLayoutView_MLSharedInit;
- (id)initWithFrame:(struct CGRect)frame;
- (id)initWithCoder:(id)coder;
- (void)dvt_configureSubviewsBeforeSubviewLayout;
- (void)dvt_positionSubviewsAndSizeSelfAfterSubviewLayout;
- (void)dvt_willLayoutSubview:(id)subview atIndex:(long long)index;
- (void)dvt_didLayoutSubview:(id)subview atIndex:(long long)index;
- (void)dvt_didCompleteLayout;
- (BOOL)wantsDefaultClipping;
@end

#endif /* DVTLayoutView_ML_h */
