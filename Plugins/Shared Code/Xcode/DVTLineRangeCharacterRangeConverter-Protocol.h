//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTLineRangeCharacterRangeConverter_Protocol_h
#define DVTLineRangeCharacterRangeConverter_Protocol_h
#import <Foundation/Foundation.h>

@protocol DVTLineRangeCharacterRangeConverter 
/* instance methods */
- (struct NSRange)characterRangeForLineRange:(struct NSRange)range;
- (struct NSRange)lineRangeForCharacterRange:(struct NSRange)range;
@end

#endif /* DVTLineRangeCharacterRangeConverter_Protocol_h */
