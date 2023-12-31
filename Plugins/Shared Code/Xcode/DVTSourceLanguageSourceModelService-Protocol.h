//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTSourceLanguageSourceModelService_Protocol_h
#define DVTSourceLanguageSourceModelService_Protocol_h
#import <Foundation/Foundation.h>

@protocol DVTSourceLanguageSourceModelService <NSObject>
/* instance methods */
- (id)sourceModel;
- (id)sourceModelWithoutParsing;
- (id)sourceModelItemAtCharacterIndex:(unsigned long long)index affinity:(unsigned long long)affinity;
- (id)sourceModelItemAtCharacterIndex:(unsigned long long)index;
- (id)commonSourceModelItemAtRange:(struct _NSRange)range;
- (id)stringForItem:(id)item;
- (long long)languageIdentifierAtLocation:(unsigned long long)location;
@end

#endif /* DVTSourceLanguageSourceModelService_Protocol_h */
