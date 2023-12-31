//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDESingleFileProcessingToolbarController_h
#define IDESingleFileProcessingToolbarController_h
#import <Foundation/Foundation.h>

#include "IDEViewController.h"
#include "IDEProcessedFileAttributes.h"

@class DVTBorderedView, DVTObservingToken, NSButton, NSPopUpButton, NSString, NSTextField;
@protocol IDESingleFileCommandSupportingEditor;

@interface IDESingleFileProcessingToolbarController : IDEViewController {
  /* instance variables */
  DVTBorderedView *_borderedView;
  NSPopUpButton *_actionPopUpButton;
  NSButton *_refreshButton;
  DVTObservingToken *_currentBuildOperationObservingToken;
}

@property BOOL canRefresh;
@property (readonly) NSString *actionLabel;
@property (retain) IDEEditor<IDESingleFileCommandSupportingEditor> *editor;
@property (retain, nonatomic) IDEProcessedFileAttributes *attributes;

/* class methods */
+ (id)defaultNibName;
+ (id)keyPathsForValuesAffectingActionLabel;

/* instance methods */
- (id)initWithEditor:(id)editor processedFileAttributes:(id)attributes;
- (void)primitiveInvalidate;
- (void)loadView;
- (void)viewDidInstall;
- (void)viewWillUninstall;
- (void)refresh:(id)refresh;
- (void)selectedSchemeAction:(id)action;
- (BOOL)_showingAssembly;
- (void)_updateActionPopUp;
@end

#endif /* IDESingleFileProcessingToolbarController_h */
