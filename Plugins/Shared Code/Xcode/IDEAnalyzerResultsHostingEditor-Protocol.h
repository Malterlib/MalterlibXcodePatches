//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22502.0.0.0.0
//
#ifndef IDEAnalyzerResultsHostingEditor_Protocol_h
#define IDEAnalyzerResultsHostingEditor_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDEAnalyzerResultsHostingEditor <IDELocalAnnotationHostingEditor>

@property (nonatomic, readonly) NSView *textView;
@property (nonatomic, readonly) NSColor *backgroundColor;
@property (nonatomic, readonly) long long textIndentWidth;
@property (nonatomic, readonly) IDEAnalyzerResultsExplorer *analyzerResultsExplorer;

/* instance methods */
- (id)rectArrayForCharacterRange:(struct _NSRange)range;
- (id)rectArrayForCharacterRange:(struct _NSRange)range;
- (struct _NSRange)characterRangeFromDocumentLocation:(id)location;
- (struct _NSRange)characterRangeFromDocumentLocation:(id)location;
- (void)addAnalyzerVisualization:(id)visualization fadeIn:(BOOL)in completionBlock:(id /* block */)block;
- (void)removeAnalyzerVisualization:(id)visualization fadeOut:(BOOL)out completionBlock:(id /* block */)block;
- (void)refreshAnalyzerVisualization:(id)visualization;
- (void)showAllMessageBubbleAnnotationsIfNotExplicitlyHidden;
- (void)hideAllMessageBubbleAnnotations;
- (void)showAnalyzerExplorerForMessage:(id)message animate:(BOOL)animate;
- (void)showAnalyzerExplorerForMessage:(id)message animate:(BOOL)animate;
- (void)hideAnalyzerExplorerAnimate:(BOOL)animate;
@end

#endif /* IDEAnalyzerResultsHostingEditor_Protocol_h */
