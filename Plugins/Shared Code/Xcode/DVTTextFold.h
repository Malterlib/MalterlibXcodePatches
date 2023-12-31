//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTTextFold_h
#define DVTTextFold_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "DVTTextFold.h"

@class DVTStackBacktrace, NSAttributedString, NSMutableArray, NSString, NSTextAttachmentCell;

@interface DVTTextFold : NSObject<DVTInvalidation> {
  /* instance variables */
  struct _NSRange _relativeLocation;
}

@property (retain) id representedObject;
@property (readonly) NSString *stringValue;
@property struct NSRange range;
@property (retain) DVTTextFold *parent;
@property (readonly) unsigned long long numberOfChildren;
@property (readonly) NSMutableArray *children;
@property (readonly) NSString *displayString;
@property (readonly) unsigned long long foldStyle;
@property (readonly) NSString *replacementString;
@property (readonly) struct NSRange replacementRange;
@property (readonly) NSTextAttachmentCell *attachmentCell;
@property (readonly) NSAttributedString *foldedIconString;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (Class)_inlineTokenAttachmentCellClass;
+ (Class)_markupViewAttachmentCellClass;
+ (id)decodeFold:(id)fold forParent:(id)parent;
+ (id)foldsFromString:(id)string;
+ (id)keyPathsForValuesAffectingDisplayString;
+ (id)keyPathsForValuesAffectingReplacementString;
+ (id)keyPathsForValuesAffectingReplacementRange;

/* instance methods */
- (id)initWithRepresentedObject:(id)object range:(struct NSRange)range style:(unsigned long long)style;
- (void)primitiveInvalidate;
- (id)_pList;
- (id)innerDescription:(id)description;
- (BOOL)validate;
- (void)offsetBy:(long long)by;
- (BOOL)rangeIsInsideAFold:(struct NSRange)afold;
- (BOOL)isCharacterFoldedAtIndex:(unsigned long long)index;
- (BOOL)deleteAsToken;
- (void)enumerateDescendantsWithOptions:(unsigned long long)options usingBlock:(id /* block */)block;
- (id)blockFoldsTouchingRange:(struct NSRange)range;
- (id)inlineFoldsTouchingRange:(struct NSRange)range;
- (id)allFoldsTouchingRange:(struct NSRange)range;
- (id)firstFoldTouchingCharacterIndex:(unsigned long long)index;
- (id)lastFoldTouchingCharacterIndex:(unsigned long long)index;
- (void)_addFoldsEnclosingRange:(struct NSRange)range toArray:(id)array;
- (id)foldsEnclosingRange:(struct NSRange)range;
- (id)adjustFoldsForRange:(struct NSRange)range changeInLength:(long long)length;
- (unsigned long long)addInFolds:(unsigned long long)folds;
- (unsigned long long)subtractOutFolds:(unsigned long long)folds;
- (id)findFoldWithRange:(struct NSRange)range;
- (id)findFoldContainingRange:(struct NSRange)range;
- (void)addChild:(id)child;
- (id)removeChildren:(id)children;
- (struct CGRect)foldingLayoutManager:(id)manager shouldUseBoundingRect:(struct CGRect)rect forGlyphRange:(struct NSRange)range inTextContainer:(id)container;
- (struct CGRect)foldingTypesetter:(id)typesetter shouldUseBoundingBox:(struct CGRect)box forControlGlyphAtIndex:(unsigned long long)index textContainer:(id)container proposedLineFragment:(struct CGRect)fragment glyphPosition:(struct CGPoint)position characterIndex:(unsigned long long)index;
- (unsigned long long)foldingTypesetter:(id)typesetter shouldUseControlCharacterAction:(unsigned long long)action remainingNominalParagraphRange:(struct NSRange *)range andParagraphSeparatorRange:(struct NSRange *)range charactarIndex:(unsigned long long)index layoutManager:(id)manager string:(id)string;
- (struct NSRange)fixedSelectionRangeForRange:(struct NSRange)range affinity:(unsigned long long)affinity inTextView:(id)view;
@end

#endif /* DVTTextFold_h */
