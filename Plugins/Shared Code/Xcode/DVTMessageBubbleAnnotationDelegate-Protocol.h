//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#import "DVTTextAnnotationDelegate-Protocol.h"

@class DVTAnnotation, DVTMessageBubbleAnnotation, NSImage, NSString, NSView;

@protocol DVTMessageBubbleAnnotationDelegate <DVTTextAnnotationDelegate>

@optional
- (NSString *)actionMessageForAnnotation:(DVTMessageBubbleAnnotation *)arg1;
- (NSString *)actionTitleForAnnotation:(DVTMessageBubbleAnnotation *)arg1;
- (NSImage *)actionStandaloneIconForAnnotation:(DVTAnnotation *)arg1;
- (void)didClickMessageBubbleControl:(NSView *)arg1 forAnnotation:(DVTMessageBubbleAnnotation *)arg2 inView:(NSView *)arg3;
@end

