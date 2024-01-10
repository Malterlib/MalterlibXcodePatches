//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTFilterControlBar_h
#define DVTFilterControlBar_h
#import <Foundation/Foundation.h>

#include "DVTBorderedView.h"
#include "DVTFilterControlBarTarget-Protocol.h"
#include "DVTInvalidation-Protocol.h"

@class DVTStackBacktrace, NSMutableArray, NSString;
@protocol DVTFilterControlField;

@interface DVTFilterControlBar : DVTBorderedView<DVTInvalidation> {
  /* instance variables */
  id _filterLeftButton;
  NSMutableArray *_toggleButtons;
}

@property (readonly) NSTextField<DVTFilterControlField> *filterControlField;
@property (retain, nonatomic) NSObject<DVTFilterControlBarTarget> *filterTarget;
@property (copy, nonatomic) NSString *filterDefinitionIdentifier;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;

/* instance methods */
- (id)_filterControlFieldWithFrame:(struct CGRect)frame;
- (void)_commonInit;
- (id)initWithFrame:(struct CGRect)frame;
- (id)initWithCoder:(id)coder;
- (id)filterDefinitionExtension;
- (id)imageNamed:(id)named fromExtension:(id)extension;
- (void)setUpFilterControls;
- (void)_willSetFilterTarget;
- (void)_didSetFilterTarget;
- (void)configureLeftFilterButtonWithMenu:(id)menu;
- (id)toggleButtons;
- (void)primitiveInvalidate;
@end

#endif /* DVTFilterControlBar_h */