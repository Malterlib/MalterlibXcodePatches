//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

@class DVTDocumentLocation, NSNumber, NSString;

@interface IDEBatchFindAbstractResult : NSObject
{
    id _cachedIcon;
    DVTDocumentLocation *_location;
    SEL _childOrderingSelector;
    IDEBatchFindAbstractResult *_parent;
    long long _depth;
    long long _queryIdentifier;
    long long _resultIdentifier;
    NSString *_text;
    NSNumber *_initialSuggestedNumberOfLines;
    long long _suggestedOrder;
    struct _NSRange _highlightedTextRange;
}

// - (void).cxx_destruct;
@property(readonly) long long suggestedOrder; // @synthesize suggestedOrder=_suggestedOrder;
@property(readonly) NSNumber *initialSuggestedNumberOfLines; // @synthesize initialSuggestedNumberOfLines=_initialSuggestedNumberOfLines;
@property(readonly) struct _NSRange highlightedTextRange; // @synthesize highlightedTextRange=_highlightedTextRange;
@property(readonly) NSString *text; // @synthesize text=_text;
@property(readonly) long long resultIdentifier; // @synthesize resultIdentifier=_resultIdentifier;
@property(readonly) long long queryIdentifier; // @synthesize queryIdentifier=_queryIdentifier;
@property(readonly) long long depth; // @synthesize depth=_depth;
@property(readonly) IDEBatchFindAbstractResult *parent; // @synthesize parent=_parent;
@property(readonly) SEL childOrderingSelector; // @synthesize childOrderingSelector=_childOrderingSelector;
@property(readonly) DVTDocumentLocation *location; // @synthesize location=_location;
- (long long)compareSuggestedOrder:(id)arg1;
- (BOOL)textIsFileName;
@property(readonly) NSString *contextualSuffix;
- (id)textRepresentationForPasteboard;
- (id)generateFindResult;
- (BOOL)canHaveChildren;
- (BOOL)allowsSummarization;
- (BOOL)emphasizesTitle;
- (BOOL)contributesToResultCount;
- (BOOL)contributesToFileResultCount;
@property(readonly) BOOL isRoot;
- (long long)compareDocumentLocations:(id)arg1;
- (long long)compareText:(id)arg1;
- (long long)compareFilePaths:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)initWithDocumentLocation:(id)arg1 text:(id)arg2 highlightedTextRange:(struct _NSRange)arg3 initialNumberOfLinesCalculator:(CDUnknownBlockType)arg4 parent:(id)arg5 suggestedOrder:(long long)arg6 childOrderingSelector:(SEL)arg7 queryIdentifier:(long long)arg8 resultIdentifier:(long long)arg9;

@end

