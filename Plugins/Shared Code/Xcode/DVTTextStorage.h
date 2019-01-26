//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "NSConcreteTextStorage.h"

#import "DVTDiffSessionTextEditBuffer-Protocol.h"
#import "DVTLineRangeCharacterRangeConverter-Protocol.h"
#import "DVTSourceBufferProvider-Protocol.h"
#import "DVTSourceLanguageServiceDelegate-Protocol.h"
#import "DVTTextDocumentLocationEncodingConverter-Protocol.h"

@class DVTFontAndColorTheme, DVTObservingToken, DVTSourceCodeLanguage, DVTSourceLandmarkItem, DVTSourceLanguageService, DVTSourceModel, NSDictionary, NSString, NSTimer, _LazyInvalidationHelper;
@protocol DVTSourceLanguageSourceModelService, DVTSourceLanguageSyntaxTypeService, DVTTextStorageDelegate;

@interface DVTTextStorage : NSConcreteTextStorage <DVTDiffSessionTextEditBuffer, DVTSourceBufferProvider, DVTSourceLanguageServiceDelegate, DVTTextDocumentLocationEncodingConverter, DVTLineRangeCharacterRangeConverter>
{
    struct _DVTTextLineOffsetTable _lineOffsets;
    unsigned long long _changeCapacity;
    unsigned long long _numChanges;
    struct _DVTTextChangeEntry *_changes;
    DVTSourceCodeLanguage *_language;
    NSTimer *_sourceModelUpdater;
    DVTSourceLandmarkItem *_topSourceLandmark;
    DVTSourceLandmarkItem *_rootImportLandmark;
    NSTimer *_landmarksCacheTimer;
    double _lastEditTimestamp;
    unsigned long long _tabWidth;
    unsigned long long _indentWidth;
    unsigned long long _wrappedLineIndentWidth;
    DVTObservingToken *_wrappedLinesIndentObserver;
    double _advancementForSpace;
    DVTFontAndColorTheme *_fontAndColorTheme;
    struct _NSRange _rangeNeedingInvalidation;
    struct {
        unsigned int lineEndings:2;
        unsigned int usesTabs:1;
        unsigned int syntaxColoringEnabled:1;
        unsigned int processingLazyInvalidation:1;
        unsigned int breakChangeCoalescing:1;
        unsigned int doingBatchEdit:1;
        unsigned int doingSubwordMovement:1;
        unsigned int doingExpressionMovement:1;
        unsigned int delegateRespondsToShouldAllowEditing:1;
        unsigned int delegateRespondsToDidUpdateSourceLandmarks:1;
        unsigned int delegateRespondsToNodeTypeForItem:1;
        unsigned int delegateRespondsToSourceLanguageServiceContext:1;
        unsigned int languageServiceSupportsSourceModel:1;
        unsigned int disabled:16;
    } _tsflags;
    _LazyInvalidationHelper *_lazyInvalidationHelper;
    DVTSourceLanguageService<DVTSourceLanguageSyntaxTypeService> *_sourceLanguageService;
    DVTObservingToken *_sourceLanguageServiceContextObservingToken;
}

+ (id)keyPathsForValuesAffectingSourceLanguageServiceContext;
+ (void)initialize;
+ (id)_changeTrackingLogAspect;
+ (id)_sourceLandmarksLogAspect;
@property(nonatomic) unsigned long long wrappedLineIndentWidth; // @synthesize wrappedLineIndentWidth=_wrappedLineIndentWidth;
@property unsigned long long indentWidth; // @synthesize indentWidth=_indentWidth;
@property double lastEditTimestamp; // @synthesize lastEditTimestamp=_lastEditTimestamp;
// - (void).cxx_destruct;
- (id)updatedLocationFromLocation:(id)arg1 toTimestamp:(double)arg2;
- (id)compatibleLocationFromLocation:(id)arg1;
- (id)convertLocationToNativeNSStringEncodedLocation:(id)arg1;
- (id)convertLocationToUTF8EncodedLocation:(id)arg1;
- (void)_restoreRecomputableState;
- (void)_dropRecomputableState;
- (unsigned long long)lineBreakBeforeIndex:(unsigned long long)arg1 withinRange:(struct _NSRange)arg2;
- (id)_ancestorItemForTokenizableItem:(id)arg1;
- (long long)nodeTypeForTokenizableItem:(id)arg1;
- (double)indentationForWrappedLineAtIndex:(unsigned long long)arg1;
- (unsigned long long)leadingWhitespacePositionsForLine:(unsigned long long)arg1;
- (long long)syntaxTypeForItem:(id)arg1 context:(id)arg2;
- (id)colorAtCharacterIndex:(unsigned long long)arg1 effectiveRange:(struct _NSRange *)arg2 context:(id)arg3;
- (long long)nodeTypeAtCharacterIndex:(unsigned long long)arg1 effectiveRange:(struct _NSRange *)arg2 context:(id)arg3;
- (void)_themeColorsChanged:(id)arg1;
@property(retain) DVTFontAndColorTheme *fontAndColorTheme;
@property(getter=isSyntaxColoringEnabled) BOOL syntaxColoringEnabled;
- (id)stringBySwappingRange:(struct _NSRange)arg1 withAdjacentRange:(struct _NSRange)arg2;
- (struct _NSRange)functionOrMethodBodyRangeAtIndex:(unsigned long long)arg1;
- (struct _NSRange)functionRangeAtIndex:(unsigned long long)arg1 isDefinitionOrCall:(char *)arg2;
- (struct _NSRange)methodDefinitionRangeAtIndex:(unsigned long long)arg1;
- (struct _NSRange)methodCallRangeAtIndex:(unsigned long long)arg1;
- (id)importStatementStringAtCharacterIndex:(unsigned long long)arg1;
- (id)importStatementStringAtCharacterIndex:(unsigned long long)arg1 effectiveRange:(struct _NSRange *)arg2 isModule:(char *)arg3;
- (id)symbolNameAtCharacterIndex:(unsigned long long)arg1 nameRanges:(id *)arg2;
- (unsigned long long)nextExpressionFromIndex:(unsigned long long)arg1 forward:(BOOL)arg2;
@property(getter=isExpressionMovement) BOOL expressionMovement;
- (unsigned long long)dvt_nextWordFromIndex:(unsigned long long)arg1 forward:(BOOL)arg2;
- (unsigned long long)nextWordFromIndex:(unsigned long long)arg1 forward:(BOOL)arg2;
@property(getter=isSubwordMovement) BOOL subwordMovement;
- (struct _NSRange)doubleClickAtIndex:(unsigned long long)arg1 inRange:(struct _NSRange)arg2;
- (struct _NSRange)rangeOfWordAtIndex:(unsigned long long)arg1;
- (struct _NSRange)rangeOfWordAtIndex:(unsigned long long)arg1 allowNonWords:(BOOL)arg2;
- (id)sourceLandmarkAtCharacterIndex:(unsigned long long)arg1;
- (id)_sourceLandmarkAtCharacterIndex:(unsigned long long)arg1 inLandmarkItems:(id)arg2;
- (id)importLandmarkItems;
@property(readonly) DVTSourceLandmarkItem *topSourceLandmark;
@property(readonly) BOOL hasPendingSourceLandmarkInvalidation;
- (void)_invalidateSourceLandmarks:(id)arg1;
- (void)invalidateAllLandmarks;
- (id)stringForItem:(id)arg1;
@property(readonly) DVTSourceModel *sourceModelWithoutParsing;
@property(readonly) DVTSourceModel *sourceModel;
@property(readonly) DVTSourceLanguageService<DVTSourceLanguageSourceModelService> *sourceModelService;
@property(readonly, nonatomic) NSDictionary *sourceLanguageServiceContext;
@property(readonly) DVTSourceLanguageService<DVTSourceLanguageSyntaxTypeService> *languageService;
@property(copy) DVTSourceCodeLanguage *language;
- (void)didReplaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2 changeInLength:(long long)arg3 replacedString:(id)arg4;
- (void)willReplaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2 changeInLength:(long long)arg3;
- (void)_dumpChangeHistory;
- (struct _NSRange)lineRangeForLineRange:(struct _NSRange)arg1 fromTimestamp:(double)arg2 toTimestamp:(double)arg3;
- (struct _NSRange)characterRangeForCharacterRange:(struct _NSRange)arg1 fromTimestamp:(double)arg2 toTimestamp:(double)arg3;
- (id)_debugInfoForChangeIndex:(unsigned long long)arg1 toChangeIndex:(unsigned long long)arg2;
- (unsigned long long)changeIndexForTimestamp:(double)arg1;
- (struct _NSRange)lineRangeForLineRange:(struct _NSRange)arg1 fromChangeIndex:(unsigned long long)arg2 toChangeIndex:(unsigned long long)arg3;
- (struct _NSRange)characterRangeForCharacterRange:(struct _NSRange)arg1 fromChangeIndex:(unsigned long long)arg2 toChangeIndex:(unsigned long long)arg3;
- (void)breakChangeTrackingCoalescing;
- (void)clearChangeHistory;
@property(readonly) unsigned long long currentChangeIndex;
- (id)_debugInfoString;
@property(readonly) unsigned long long numberOfLines;
- (struct _NSRange)currentWordAtIndex:(unsigned long long)arg1;
- (struct _NSRange)lineRangeForCharacterRange:(struct _NSRange)arg1;
- (struct _NSRange)characterRangeForLineRange:(struct _NSRange)arg1;
- (struct _NSRange)characterRangeFromDocumentLocation:(id)arg1;
- (void)_dumpLineOffsetsTable;
- (id)_debugStringFromUnsignedIntegers:(const unsigned long long *)arg1 count:(unsigned long long)arg2;
- (void)scheduleLazyInvalidationForLineRange:(struct _NSRange)arg1;
- (void)scheduleLazyInvalidationForRange:(struct _NSRange)arg1;
- (void)_updateLazyInvalidationForEditedRange:(struct _NSRange)arg1 changeInLength:(long long)arg2;
- (void)_processLazyInvalidation;
- (void)_invalidateCallback:(id)arg1;
@property BOOL processingLazyInvalidation;
- (void)invalidateDisplayForLineRange:(struct _NSRange)arg1;
- (void)invalidateDisplayForRange:(struct _NSRange)arg1;
- (void)updateAttributesInRange:(struct _NSRange)arg1;
- (void)fixAttributesInRange:(struct _NSRange)arg1;
- (void)fixSyntaxColoringInRange:(struct _NSRange)arg1;
@property id <DVTTextStorageDelegate> delegate;
- (id)_associatedTextViews;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withAttributedString:(id)arg2 withUndoManager:(id)arg3;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2 withUndoManager:(id)arg3;
- (void)addLayoutManager:(id)arg1;
- (void)invalidateAttributesInRange:(struct _NSRange)arg1;
- (BOOL)fixesAttributesLazily;
- (void)processEditing;
- (void)endEditing;
- (void)beginEditing;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withAttributedString:(id)arg2;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2 evenIfNotEditable:(BOOL)arg3;
- (BOOL)isDoingBatchEdit;
- (void)doingBatchEdit:(BOOL)arg1;
- (void)doingBatchEdit:(BOOL)arg1 notifyModel:(BOOL)arg2;
- (void)resetAdvancementForSpace;
@property(readonly) double advancementForTab;
@property(readonly) double advancementForSpace;
@property BOOL usesTabs;
@property(nonatomic) unsigned long long tabWidth;
@property(readonly) BOOL isEditable;
@property unsigned long long lineEndings;
@property(readonly, copy) NSString *description;
- (void)dealloc;
- (id)init;
- (id)initWithString:(id)arg1;
- (id)initWithString:(id)arg1 attributes:(id)arg2;
- (id)initWithAttributedString:(id)arg1;
- (void)_dvtTextStorageCommonInit;
- (BOOL)_isExpressionItemLikeFunction:(id)arg1;
- (BOOL)_isExpressionItemLikelyTarget:(id)arg1;
- (BOOL)_isItemExpression:(id)arg1;
- (unsigned long long)_reverseParseExpressionFromIndex:(unsigned long long)arg1 ofParent:(id)arg2;
- (unsigned long long)_startLocationForObjCMethodCallAtLocation:(unsigned long long)arg1 withArgs:(char *)arg2;
- (unsigned long long)locationForOpeningBracketForClosingBracket:(unsigned long long)arg1 withArgs:(char *)arg2;
- (BOOL)isAtFirstArgumentInMethodCallAtLocation:(unsigned long long)arg1 inCall:(char *)arg2;
- (BOOL)_isTextEmptyInBetweenItem:(id)arg1 prevItem:(id)arg2;
- (id)_textInBetweenItem:(id)arg1 prevItem:(id)arg2;
- (id)_parenLikeItemAtLocation:(unsigned long long)arg1;
- (BOOL)_isItemParenExpression:(id)arg1;
- (BOOL)_isItemBlockExpression:(id)arg1;
- (BOOL)_isItemBracketLikeExpression:(id)arg1;
- (BOOL)_isItemBracketExpression:(id)arg1;
- (BOOL)indentAtBeginningOfLineForCharacterRange:(struct _NSRange)arg1 undoManager:(id)arg2;
- (BOOL)isAtBOL:(struct _NSRange)arg1;
- (void)indentCharacterRange:(struct _NSRange)arg1 undoManager:(id)arg2;
- (void)indentLineRange:(struct _NSRange)arg1 undoManager:(id)arg2;
- (BOOL)indentLine:(long long)arg1 options:(unsigned long long)arg2 undoManager:(id)arg3;
- (long long)firstNonblankForLine:(long long)arg1 convertTabs:(BOOL)arg2;
- (id)getTextForLineSansBlanks:(long long)arg1;
@property(readonly, getter=isIndentable) BOOL indentable;
- (long long)getIndentForLine:(long long)arg1;
- (long long)_getIndentForObjectLiteral:(id)arg1 atLocation:(unsigned long long)arg2;
- (BOOL)_isInvalidObjectLiteralItem:(id)arg1;
- (unsigned long long)firstColonAfterItem:(id)arg1 inRange:(struct _NSRange)arg2;
- (long long)columnForPositionConvertingTabs:(unsigned long long)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *string;
@property(readonly) Class superclass;

@end

