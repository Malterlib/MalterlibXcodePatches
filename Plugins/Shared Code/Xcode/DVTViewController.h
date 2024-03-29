//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTEditor-Protocol.h"
#import "DVTInvalidation-Protocol.h"

@class DVTExtension, DVTStackBacktrace, NSString, NSView, NSWindow, NSWindowController;

@interface DVTViewController : NSViewController <DVTEditor, DVTInvalidation>
{
    NSWindow *_kvoWindow;
    BOOL _isInstalled;
    BOOL _didInstall;
    BOOL _isViewLoaded;
    DVTExtension *_representedExtension;
}

+ (id)keyPathsForValuesAffectingParentWindowController;
+ (id)keyPathsForValuesAffectingMainViewControllerInParentWindow;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (BOOL)requiresUninstallAfterLoadView;
+ (id)viewControllerUsingDefaultNib;
+ (id)defaultNibBundle;
+ (id)defaultNibName;
+ (id)defaultViewNibBundle;
+ (id)defaultViewNibName;
+ (void)initialize;
// - (void).cxx_destruct;
@property BOOL isViewLoaded; // @synthesize isViewLoaded=_isViewLoaded;
@property(retain, nonatomic) DVTExtension *representedExtension; // @synthesize representedExtension=_representedExtension;
- (void)_interposeViewControllerNotifyingLifecycleMethodsIfNecessaryForView:(id)arg1;
- (void)_checkKvoWindow;
- (id)_kvoWindow;
@property(readonly) NSWindowController *parentWindowController;
@property(readonly) DVTViewController *mainViewControllerInParentWindow;
- (BOOL)commitEditingForAction:(int)arg1 errors:(id)arg2;
- (void)_windowWillClose:(id)arg1;
- (void)_viewDidMoveToSuperView;
- (void)_viewDidMoveToWindow;
- (void)_viewWillChangeSuperview;
- (void)_viewWillChangeWindow;
- (void)_viewWillUninstall;
- (void)_viewDidInstall;
- (void)viewWillUninstall;
- (void)viewDidInstall;
@property(readonly) NSView *viewIfLoaded;
- (void)loadView;
@property(retain) NSView *view;
- (void)separateKeyViewLoops;
- (BOOL)delegateFirstResponder;
- (id)supplementalMainViewController;
@property(readonly, copy) NSString *description;
- (void)primitiveInvalidate;
- (void)invalidate;
- (id)initWithCoder:(id)arg1;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initUsingDefaultNib;
- (void)dvtViewController_commonInit;
@property(readonly) BOOL canBecomeMainViewController;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

