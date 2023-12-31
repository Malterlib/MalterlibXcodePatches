//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEAbstractFindNavigatorOutlineView_h
#define IDEAbstractFindNavigatorOutlineView_h
#import <Foundation/Foundation.h>

@class NSEvent;

@interface IDEAbstractFindNavigatorOutlineView : NSOutlineView {
  /* instance variables */
  NSEvent *_currentKeyDownEvent;
}

/* instance methods */
- (id)makeViewWithIdentifier:(id)identifier owner:(id)owner;
- (void)keyDown:(id)down;
- (id)delegate;
- (void)dvt_expandRowAndPossiblySiblings:(id)siblings;
- (void)doCommandBySelector:(SEL)selector;
- (struct CGRect)frameOfCellAtColumn:(long long)column row:(long long)row;
@end

#endif /* IDEAbstractFindNavigatorOutlineView_h */
