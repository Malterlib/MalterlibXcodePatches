//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTDealloc2Main_View.h"

#import "DVTStructuredLayoutView-Protocol.h"

@class DVTStructuredLayoutViewState;

@interface DVTLayoutView_ML : DVTDealloc2Main_View <DVTStructuredLayoutView>
{
    BOOL _implementsDrawRect;
    DVTStructuredLayoutViewState *_dvt_layoutState;
}

+ (void)initialize;
+ (BOOL)isLayingoutWindow:(id)arg1;
@property(readonly) DVTStructuredLayoutViewState *dvt_layoutState; // @synthesize dvt_layoutState=_dvt_layoutState;
// - (void).cxx_destruct;
- (BOOL)wantsDefaultClipping;
- (void)dvt_didCompleteLayout;
- (void)dvt_didLayoutSubview:(id)arg1;
- (void)dvt_willLayoutSubview:(id)arg1;
- (void)dvt_positionSubviewsAndSizeSelfAfterSubviewLayout;
- (void)dvt_configureSubviewsBeforeSubviewLayout;
- (id)initWithCoder:(id)arg1;
- (id)initWithFrame:(struct CGRect)arg1;
- (void)_DVTLayoutView_MLSharedInit;
- (void)stopInvalidatingLayoutWithChangesToKeyPath:(id)arg1 ofObject:(id)arg2;
- (void)invalidateLayoutWithChangesToKeyPath:(id)arg1 ofObject:(id)arg2;
- (void)stopInvalidatingLayoutWithFrameChangesToViews:(id)arg1;
- (void)stopInvalidatingLayoutWithFrameChangesToView:(id)arg1;
- (void)invalidateLayoutWithFrameChangesToViews:(id)arg1;
- (void)invalidateLayoutWithFrameChangesToView:(id)arg1;
- (void)setNeedsSecondLayoutPass:(BOOL)arg1;
- (void)invalidateLayout;
- (void)layoutIfNeeded;
- (void)didLayoutSubview:(id)arg1;
- (void)willLayoutSubview:(id)arg1;
- (void)didCompleteLayout;
- (void)layoutBottomUp;
- (void)layoutTopDown;

@end

