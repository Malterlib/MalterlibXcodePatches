//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTReplacementView, NSViewController;

@protocol DVTReplacementViewDelegate <NSObject>

@optional
- (void)replacementView:(DVTReplacementView *)arg1 willDisplayInRect:(struct CGRect)arg2;
- (void)replacementView:(DVTReplacementView *)arg1 willCloseViewController:(NSViewController *)arg2;
- (void)replacementView:(DVTReplacementView *)arg1 didInstallViewController:(NSViewController *)arg2;
- (void)replacementView:(DVTReplacementView *)arg1 willInstallViewController:(NSViewController *)arg2;
@end

