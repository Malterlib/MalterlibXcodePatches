//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTFoldingManagerDelegate-Protocol.h"

@class DVTFoldingManager, DVTNotificationToken, DVTObservingToken, DVTTextStorage, NSString;
@protocol DVTFoldingLayoutManagerDelegate;

@interface DVTFoldingLayoutManager : NSLayoutManager <DVTFoldingManagerDelegate>
{
    DVTObservingToken *_usesColorLiteralObservingToken;
    DVTObservingToken *_usesFileLiteralObservingToken;
    DVTObservingToken *_usesImageLiteralObservingToken;
    DVTNotificationToken *_textStorageDidEndEditingNotificationToken;
    BOOL _foldsMultiPathTokens;
    BOOL _generatingInlineFolds;
    DVTFoldingManager *_foldingManager;
}

+ (id)layoutLogAspect;
// - (void).cxx_destruct;
@property(getter=isGeneratingInlineFolds) BOOL generatingInlineFolds; // @synthesize generatingInlineFolds=_generatingInlineFolds;
@property BOOL foldsMultiPathTokens; // @synthesize foldsMultiPathTokens=_foldsMultiPathTokens;
@property(readonly) DVTFoldingManager *foldingManager; // @synthesize foldingManager=_foldingManager;
- (unsigned long long)characterIndexForPoint:(struct CGPoint)arg1 inTextContainer:(id)arg2 fractionOfDistanceBetweenInsertionPoints:(double *)arg3;
- (struct CGSize)attachmentSizeForGlyphAtIndex:(unsigned long long)arg1;
- (void)drawGlyphsForGlyphRange:(struct _NSRange)arg1 atPoint:(struct CGPoint)arg2;
- (id)mediaResourceProviderForLiteralInFoldingManager:(id)arg1;
- (id)directoriesForLiteralInFoldingManager:(id)arg1;
- (void)foldingManager:(id)arg1 didUnfoldRange:(struct _NSRange)arg2;
- (void)foldingManager:(id)arg1 didFoldRange:(struct _NSRange)arg2;
- (struct CGRect)boundingRectForGlyphRange:(struct _NSRange)arg1 inTextContainer:(id)arg2;
- (void)_invalidateGlyphsInCharacterRange:(struct _NSRange)arg1;
- (struct _NSRange)_paragraphExtendedCharacterRange:(struct _NSRange)arg1;
- (void)textStorage:(id)arg1 edited:(unsigned long long)arg2 range:(struct _NSRange)arg3 changeInLength:(long long)arg4 invalidatedRange:(struct _NSRange)arg5;
- (void)_validateSelectedRange;
- (void)_invalidateGlyphsForExtendedCharacterRange:(struct _NSRange)arg1 changeInLength:(long long)arg2 includeBlocks:(BOOL)arg3;
- (struct _NSRange)_extendedCharRangeForInvalidation:(struct _NSRange)arg1 editedCharRange:(struct _NSRange)arg2;
- (void)generateInlineFoldsForCharacterRange:(struct _NSRange)arg1;
- (void)_sourceCodeTreeNodeMenuItemAction:(id)arg1;
- (void)_generateSourceCodeTreeNodeFoldWithRange:(struct _NSRange)arg1;
- (void)_addMenuItemsForChildrenOfNode:(id)arg1 toMenu:(id)arg2 withRange:(id)arg3;
- (void)setFolsMultiPathTokens:(BOOL)arg1;
- (struct _NSRange)paragraphRangeForLineRange:(struct _NSRange)arg1;
- (BOOL)foldsAreValid:(id)arg1;
@property DVTTextStorage *textStorage;
- (void)enableTextFolding:(BOOL)arg1;
- (void)_unfoldObjectLiteralFolds;
- (id)initWithCoder:(id)arg1;
- (void)dealloc;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property id <DVTFoldingLayoutManagerDelegate> delegate; // @dynamic delegate;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

