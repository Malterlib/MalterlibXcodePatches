//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@class NSArray, NSDictionary, NSFont, NSMutableArray, NSMutableDictionary, NSMutableIndexSet, NSTrackingArea;

@interface DVTMessageBubbleView : NSView
{
    NSMutableArray *_annotations;
    NSMutableArray *_visibleAnnotations;
    NSDictionary *_cachedMessageTextAttributes;
    NSDictionary *_cachedExpandButtonTextAttributes;
    NSMutableDictionary *_messageWidths;
    NSFont *_messageFont;
    NSTrackingArea *_trackingArea;
    double _arrowheadWidth;
    NSMutableIndexSet *_annotsNeedTooltip;
    double _collapsedHeight;
    struct CGSize _preferredSize;
    int _position;
    unsigned long long _mouseOverHelpButtonAnnotationIndex;
    unsigned long long _mouseDownHelpButtonAnnotationIndex;
    struct {
        unsigned int expanded:1;
        unsigned int needsParagraphSpacing:1;
        unsigned int wantsFlatStyle:1;
        unsigned int mouseOverExpandButton:1;
        unsigned int mouseDownExpandButton:1;
    } _mbvFlags;
    struct CGSize _cachedAvailableSize;
}

+ (struct CGRect)adjustedExpandButtonRect:(struct CGRect)arg1 withFont:(id)arg2 padding:(double)arg3;
+ (struct CGRect)adjustedIconRect:(struct CGRect)arg1 withFont:(id)arg2 padding:(double)arg3;
+ (double)_defaultMessageFontSize;
+ (id)defaultAnimationForKey:(id)arg1;
// - (void).cxx_destruct;
@property(nonatomic) double collapsedHeight; // @synthesize collapsedHeight=_collapsedHeight;
@property int position; // @synthesize position=_position;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityAttributeNames;
- (BOOL)accessibilityIsIgnored;
- (id)_collapseButtonTrianglePathInRect:(struct CGRect)arg1;
- (id)_backgroundBezierPathInRect:(struct CGRect)arg1;
- (void)noticeFontAndColorsChanged;
- (void)drawRect:(struct CGRect)arg1;
- (void)_drawHelpButtonInRect:(struct CGRect)arg1;
- (void)_drawExpandButton;
- (void)_drawAnnotationMessages;
- (void)_drawBackground;
- (void)mouseDown:(id)arg1;
- (void)mouseExited:(id)arg1;
- (void)mouseEntered:(id)arg1;
- (void)mouseMoved:(id)arg1;
- (void)_updateMouseOverFlagsWithEvent:(id)arg1;
- (void)updateTrackingAreas;
- (id)view:(id)arg1 stringForToolTip:(long long)arg2 point:(struct CGPoint)arg3 userData:(void *)arg4;
- (void)resetCursorRects;
- (id)_cachedExpandButtonTextAttributes;
- (id)_cachedMessageTextAttributes;
- (struct CGRect)_helpButtonRect;
- (struct CGRect)_helpButtonRectForAnnotationAtIndex:(unsigned long long)arg1;
- (double)_helpButtonWidth;
- (double)_helpButtonWidthForAnnotationAtIndex:(unsigned long long)arg1;
- (struct CGRect)_expandButtonRect;
- (double)_expandButtonWidth;
- (double)_messageWidthForString:(id)arg1;
- (struct CGRect)_annotationIconRectAtIndex:(unsigned long long)arg1;
- (double)_iconMaxWidth;
- (id)_themeForMainAnnotation;
- (struct CGRect)_rectForAnnotationAtIndex:(unsigned long long)arg1;
- (double)_preferredHeight;
- (struct CGSize)preferredSizeForAvailableSize:(struct CGSize)arg1;
@property BOOL wantsFlatStyle;
@property BOOL needsParagraphSpacing;
@property(readonly) BOOL wantsPreferredBubbleSizeAndPosition;
- (unsigned long long)annotationIndexAtPoint:(struct CGPoint)arg1;
- (void)_resetVisibleAnnotations;
- (void)removeAnnotation:(id)arg1;
- (void)addAnnotation:(id)arg1;
@property(getter=isExpanded) BOOL expanded;
@property(readonly) NSArray *annotations;
- (id)initWithFrame:(struct CGRect)arg1;

@end

