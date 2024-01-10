//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTStructuredLayoutViewState_h
#define DVTStructuredLayoutViewState_h
#import <Foundation/Foundation.h>

@class NSMapTable, NSMutableDictionary, NSPointerArray;
@protocol DVTStructuredLayoutView;

@interface DVTStructuredLayoutViewState : NSObject {
  /* instance variables */
  NSView<DVTStructuredLayoutView> *_hostView;
  NSPointerArray *_frameObservers;
  NSMapTable *_observedViewsToObservationRecords;
  NSMutableDictionary *_keyPathInvalidationTokens;
  BOOL _isLayoutValid;
  BOOL _isSubtreeLayoutValid;
  double _lastKnownScaleFactor;
}

@property BOOL implicatedInLayoutCycle;
@property (nonatomic) BOOL needsSecondLayoutPass;

/* instance methods */
- (id)initWithHostView:(id)view;
- (void)dealloc;
- (id)description;
- (id)window;
- (void)hostViewDidChangeBackingProperties;
- (void)hostViewDidMoveToWindow;
- (void)hostViewDidMoveToSuperview;
- (void)hostViewWillDrawContinuingViewWillDrawRecursionWith:(id /* block */)with;
- (BOOL)isLayoutValid;
- (void)markLayoutAsValid;
- (BOOL)isSubtreeLayoutValid;
- (void)markSubtreeLayoutAsValid;
- (void)markSubTreeNeedsLayout;
- (void)invalidateLayout;
- (id)firstAncestorLayoutView;
- (void)markSubtreeNeedsLayoutForAncestors;
- (void)layoutIfNeeded;
- (void)registerFrameObserver:(id)observer;
- (void)removeFrameObsever:(id)obsever;
- (void)notifyObserversOfFrameChange;
- (void)hostViewWillChangeFrameSize:(struct CGSize)size;
- (void)hostViewWillChangeFrameOrigin:(struct CGPoint)origin;
- (void)hostViewWillChangeBoundsSize:(struct CGSize)size;
- (void)hostViewWillChangeBoundsOrigin:(struct CGPoint)origin;
- (void)unregisterForObservationsOf:(id)of;
- (void)invalidateLayoutWithFrameChangesToView:(id)view;
- (void)invalidateLayoutWithFrameChangesToViews:(id)views;
- (void)stopInvalidatingLayoutWithFrameChangesToView:(id)view;
- (void)stopInvalidatingLayoutWithFrameChangesToViews:(id)views;
- (void)observedViewDidChangeFrame:(id)frame;
- (void)_observedViewFrameChangeNotificationHandler:(id)handler;
- (void)invalidateLayoutWithChangesToKeyPath:(id)path ofObject:(id)object changeHandler:(id /* block */)handler;
- (void)invalidateLayoutWithChangesToKeyPath:(id)path ofObject:(id)object;
- (void)stopInvalidatingLayoutWithChangesToKeyPath:(id)path ofObject:(id)object;
@end

#endif /* DVTStructuredLayoutViewState_h */