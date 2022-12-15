//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTSearchFieldFlatCell.h"

@class NSTextFieldCell, NSTextView;

@interface DVTSearchFieldCell : DVTSearchFieldFlatCell
{
    NSTextFieldCell *_numberOfMatchesCell;
    BOOL _filterField;
    unsigned long long _additionalCancelButtonInset;
    BOOL _hasText;
    BOOL _showsProgress;
    NSTextView *_fieldEditor;
    long long _numberOfMatches;
}

+ (id)_placeholderTextColor:(id)arg1;
// - (void).cxx_destruct;
@property BOOL hasText; // @synthesize hasText=_hasText;
@property long long numberOfMatches; // @synthesize numberOfMatches=_numberOfMatches;
@property(retain) NSTextView *fieldEditor; // @synthesize fieldEditor=_fieldEditor;
@property BOOL showsProgress; // @synthesize showsProgress=_showsProgress;
- (struct CGRect)_accessibilitySearchFieldCellBounds;
- (id)accessibilityIdentifier;
- (id)accessibilityAttributeValue:(id)arg1;
- (id)accessibilityAttributeNames;
- (id)accessibilityHitTest:(struct CGPoint)arg1;
- (id)accessibilitySizeOfChild:(id)arg1;
- (id)accessibilityPositionOfChild:(id)arg1;
- (id)_numberOfMatchessCellAttribute;
- (id)accessibilityChildrenAttribute;
- (struct CGRect)_numberOfMatchesRectForBounds:(struct CGRect)arg1;
- (BOOL)_shouldShowNumberOfMatches;
- (void)drawInteriorWithFrame:(struct CGRect)arg1 inView:(id)arg2;
- (double)progressIndicatorWidth;
- (void)setAdditionalCancelButtonInset:(unsigned long long)arg1;
- (unsigned long long)additionalCancelButtonInset;
- (unsigned long long)standardCancelButtonInset;
- (struct CGRect)searchButtonRectForBounds:(struct CGRect)arg1;
- (struct CGRect)_cancelButtonRectForBoundsEvenIfHidden:(struct CGRect)arg1;
- (struct CGRect)cancelButtonRectForBounds:(struct CGRect)arg1;
- (BOOL)trackMouse:(id)arg1 inRect:(struct CGRect)arg2 ofView:(id)arg3 untilMouseUp:(BOOL)arg4;
- (void)showSearchMenu;
@property(getter=isFilterField) BOOL filterField;
- (void)setObjectValue:(id)arg1;
- (void)_updateSearchButtonImages;
- (struct CGRect)searchTextRectForBounds:(struct CGRect)arg1;
- (id)_placeholderAttributedString;
- (id)_placeholderString;
- (id)_attributedStringForEditing;
- (id)_searchMenuButtonLayerWithMenu;
- (id)_searchMenuButtonLayer;
- (id)_cancelButtonLayer;
- (id)setUpFieldEditorAttributes:(id)arg1;
- (void)_dvtFindBarSearchFieldCellCommonInit;
- (id)copy;
- (id)initWithCoder:(id)arg1;
- (id)initTextCell:(id)arg1;

@end

