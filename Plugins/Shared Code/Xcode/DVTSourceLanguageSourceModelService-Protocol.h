//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTSourceModel, DVTSourceModelItem, NSString;

@protocol DVTSourceLanguageSourceModelService <NSObject>
- (long long)languageIdentifierAtLocation:(unsigned long long)arg1;
- (NSString *)stringForItem:(DVTSourceModelItem *)arg1;
- (DVTSourceModelItem *)commonSourceModelItemAtRange:(struct _NSRange)arg1;
- (DVTSourceModelItem *)sourceModelItemAtCharacterIndex:(unsigned long long)arg1;
- (DVTSourceModelItem *)sourceModelItemAtCharacterIndex:(unsigned long long)arg1 affinity:(unsigned long long)arg2;
- (DVTSourceModel *)sourceModelWithoutParsing;
- (DVTSourceModel *)sourceModel;
@end

