//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEditorContainerViewControllerView_h
#define IDEEditorContainerViewControllerView_h
#import <Foundation/Foundation.h>

#include "DVTStructuredLayoutView.h"
#include "IDEEditorContainerViewController.h"
#include "IDESafeAreaAwareContainer-Protocol.h"

@class NSString, IDEEditorContainerViewController;

@interface IDEEditorContainerViewControllerView : DVTStructuredLayoutView<IDESafeAreaAwareContainer>

@property (weak) IDEEditorContainerViewController *viewController;
@property (nonatomic) struct CGSize minimumEditorSize;
@property (nonatomic) double safeAreaTopInset;
@property (nonatomic) double safeAreaBottomInset;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (void)didInheritNewSafeAreaInsetsFromParent;
- (id)safeAreaAwareChildren;
- (BOOL)shouldSafeAreaAwareChildInheritTopInset:(id)inset;
- (BOOL)shouldSafeAreaAwareChildInheritBottomInset:(id)inset;
- (void)didAddSubview:(id)subview;
- (void)willRemoveSubview:(id)subview;
- (void)dvt_configureSubviewsBeforeSubviewLayout;
- (void)dvt_positionSubviewsAndSizeSelfAfterSubviewLayout;
@end

#endif /* IDEEditorContainerViewControllerView_h */