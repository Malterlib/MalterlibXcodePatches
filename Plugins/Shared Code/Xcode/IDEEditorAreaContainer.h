//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEditorAreaContainer_h
#define IDEEditorAreaContainer_h
#import <Foundation/Foundation.h>

#include "DVTLayoutView_ML.h"
#include "IDEEditorMultipleSplit.h"
#include "IDESafeAreaAwareContainer-Protocol.h"

@class DVTBorderView, DVTBorderedView, NSString, NSView, NSVisualEffectView;

@interface IDEEditorAreaContainer : DVTLayoutView_ML<IDESafeAreaAwareContainer>

@property (retain, nonatomic) NSVisualEffectView *underTitlebarBorderBackgroundView;
@property (retain, nonatomic) DVTBorderView *underTitlebarBorderView;
@property (retain, nonatomic) DVTBorderedView *debuggerBarViewWhichMayOrMayNotBeASubview;
@property (retain, nonatomic) NSView *editorAreaSplitHostView;
@property (retain, nonatomic) IDEEditorMultipleSplit *editorMultipleSplit;
@property (nonatomic) double safeAreaTopInset;
@property (nonatomic) double safeAreaBottomInset;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (void)awakeFromNib;
- (void)didInheritNewSafeAreaInsetsFromParent;
- (id)safeAreaAwareChildren;
- (BOOL)shouldSafeAreaAwareChildInheritTopInset:(id)inset;
- (BOOL)shouldSafeAreaAwareChildInheritBottomInset:(id)inset;
- (id)installedDebuggerBar;
- (BOOL)isFlipped;
- (void)dvt_configureSubviewsBeforeSubviewLayout;
- (void)dvt_positionSubviewsAndSizeSelfAfterSubviewLayout;
@end

#endif /* IDEEditorAreaContainer_h */
