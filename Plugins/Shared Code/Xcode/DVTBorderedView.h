//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTBorderedView_h
#define DVTBorderedView_h
#import <Foundation/Foundation.h>

#include "DVTLayoutView_ML.h"
#include "DVTBorderView.h"
#include "DVTCancellable-Protocol.h"
#include "DVTWindowActivationStateObserver-Protocol.h"

@class NSColor, NSGradient, NSString, NSView;

@interface DVTBorderedView : DVTLayoutView_ML<DVTWindowActivationStateObserver> {
  /* instance variables */
  NSObject<DVTCancellable> *_windowActivationObservation;
  BOOL _needsVisibleBorderViewUpdate;
}

@property (retain, nonatomic) DVTBorderView *leftBorderView;
@property (retain, nonatomic) DVTBorderView *rightBorderView;
@property (retain, nonatomic) DVTBorderView *topBorderView;
@property (retain, nonatomic) DVTBorderView *bottomBorderView;
@property (nonatomic) unsigned long long borderSides;
@property (copy, nonatomic) NSColor *topBorderColor;
@property (copy, nonatomic) NSColor *bottomBorderColor;
@property (copy, nonatomic) NSColor *leftBorderColor;
@property (copy, nonatomic) NSColor *rightBorderColor;
@property (copy, nonatomic) NSColor *topInactiveBorderColor;
@property (copy, nonatomic) NSColor *bottomInactiveBorderColor;
@property (copy, nonatomic) NSColor *leftInactiveBorderColor;
@property (copy, nonatomic) NSColor *rightInactiveBorderColor;
@property (nonatomic) struct NSEdgeInsets borderSizeInsets;
@property (copy, nonatomic) NSColor *backgroundColor;
@property (copy, nonatomic) NSColor *inactiveBackgroundColor;
@property (copy, nonatomic) NSGradient *backgroundGradient;
@property (copy, nonatomic) NSGradient *inactiveBackgroundGradient;
@property (nonatomic) struct { double x0; double x1; double x2; double x3; } contentInset;
@property (readonly) struct CGRect contentRect;
@property (retain, nonatomic) NSView *contentView;
@property (nonatomic) unsigned long long horizontalContentViewResizingMode;
@property (nonatomic) unsigned long long verticalContentViewResizingMode;
@property BOOL allowsVibrancy;
@property (readonly) BOOL hasBackgroundMaterial;
@property (readonly) long long backgroundMaterial;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (double)dvt_heightWhenUsedAsBar;
- (void)_DVTBorderedViewDefaultInit;
- (id)initWithFrame:(struct CGRect)frame;
- (id)initWithCoder:(id)coder;
- (void)dealloc;
- (void)_setBorderSides:(unsigned long long)sides;
- (void)setAllBordersToColor:(id)color;
- (void)setAllInactiveBordersToColor:(id)color;
- (id)backgroundColorForWindowState;
- (id)backgroundGradientForWindowState;
- (struct { double x0; double x1; double x2; double x3; })_borderLayoutInset;
- (struct CGSize)boundSizeForContentSize:(struct CGSize)size;
- (struct CGSize)frameSizeForContentSize:(struct CGSize)size;
- (void)setNeedsVisibleBorderViewUpdate;
- (void)_insertBorderView:(id)view;
- (void)updateVisibleBorderViewsIfNeeded;
- (void)layoutTopDown;
- (void)validateContentViewAutoresizingMask;
- (void)layoutBottomUp;
- (struct CGRect)topBorderFrame;
- (struct CGRect)bottomBorderFrame;
- (struct CGRect)leftBorderFrame;
- (struct CGRect)rightBorderFrame;
- (BOOL)wantsUpdateLayer;
- (void)updateLayer;
- (void)setNeedsDisplay:(BOOL)display;
- (void)drawRect:(struct CGRect)rect;
- (BOOL)_isInactive;
- (void)viewWillMoveToWindow:(id)window;
- (void)window:(id)window didChangeActivationState:(long long)state;
@end

#endif /* DVTBorderedView_h */