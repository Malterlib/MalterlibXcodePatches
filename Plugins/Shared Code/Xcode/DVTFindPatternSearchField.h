//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTSearchField.h"

#import "DVTFindPatternField-Protocol.h"

@class DVTFindPatternComponents, NSString;
@protocol DVTFindPatternManager;

@interface DVTFindPatternSearchField : DVTSearchField <DVTFindPatternField>
{
    id <DVTFindPatternManager> findPatternManager;
    BOOL _doesNotSearchesImmediatelyAfterInsertingPattern;
}

@property id <DVTFindPatternManager> findPatternManager; // @synthesize findPatternManager;
- (void)_selectedFindPattern:(id)arg1;
- (id)menuForFindPatternAttachment:(id)arg1;
- (id)_uniquePatterns;
- (id)replacementExpression;
- (id)regularExpression;
- (id)findPatternTokenArray;
- (BOOL)hasFindPattern;
- (id)textView:(id)arg1 shouldChangeTypingAttributes:(id)arg2 toAttributes:(id)arg3;
- (void)textDidChange:(id)arg1;
- (BOOL)hasActiveFilter;
- (void)textView:(id)arg1 doubleClickedOnCell:(id)arg2 inRect:(struct CGRect)arg3 atIndex:(unsigned long long)arg4;
- (void)textView:(id)arg1 clickedOnCell:(id)arg2 inRect:(struct CGRect)arg3 atIndex:(unsigned long long)arg4;
- (void)removeFindPattern:(id)arg1;
- (id)_rangesOfFindPattern:(id)arg1 attachments:(id *)arg2;
- (id)_rangesOfFindPattern:(id)arg1;
- (void)setFindPatternPropertyList:(id)arg1;
- (id)findPatternPropertyList;
@property(copy) DVTFindPatternComponents *findPatternComponents;
- (id)plainTextValue;
- (void)setFindPatternArray:(id)arg1;
- (void)setAttributedStringValue:(id)arg1;
- (void)_uniqueFindPatternsInAttributedStringAttachments:(id)arg1;
- (void)setStringValue:(id)arg1;
- (void)_updateFindPatternsWithNewPatterns:(id)arg1;
- (void)_updateReplacePatternsWithNewPatternTokens:(id)arg1;
- (void)_invalidateLayout;
- (void)_insertFindPattern:(id)arg1;
- (void)insertNewFindPattern:(id)arg1;
- (void)_insertFindPatternAttachment:(id)arg1;
- (id)fieldEditorTargettingSelf;
- (id)_findPatternAttachmentForFindPattern:(id)arg1;
- (BOOL)performKeyEquivalent:(id)arg1;
- (BOOL)_eventIsInsertPatternKeyEquivalent:(id)arg1;
- (id)_fieldEditor;
- (BOOL)_isFindField;
- (id)replaceField;
- (id)findField;
@property BOOL searchesImmediatelyAfterInsertingPattern;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

