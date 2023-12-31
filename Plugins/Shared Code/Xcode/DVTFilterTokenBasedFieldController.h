//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22540.0.0.0.0
//
#ifndef DVTFilterTokenBasedFieldController_h
#define DVTFilterTokenBasedFieldController_h
#import <Foundation/Foundation.h>

#include "DVTFilterTokenField.h"
#include "DVTFilterTokenFieldCompletionDelegate-Protocol.h"
#include "DVTFilterTokenFieldDelegate-Protocol.h"
#include "_DVTFilterTokenFieldValue.h"

@class NSArray, NSData, NSFont, NSMutableArray, NSMutableDictionary, NSSet, NSString;
@protocol DVTFilterTokenFieldControllerDelegate;

@interface DVTFilterTokenBasedFieldController : NSObject<DVTFilterTokenFieldDelegate, DVTFilterTokenFieldCompletionDelegate> {
  /* instance variables */
  unsigned long long _lastChangeID;
  long long _requestedGlobalOperatorType;
  NSFont *_tokenKeyFont;
  NSArray *_newlyAddedTokens;
  NSArray *_lastCompletionTokens;
  NSMutableArray *_completionSections;
  NSMutableArray *_recentFilterItems;
  _DVTFilterTokenFieldValue *_itemToBeAddedToRecents;
  BOOL _accessingFieldObjectValueDuringTokenAddition;
}

@property (retain) NSMutableDictionary *completionData;
@property (retain, nonatomic) NSArray *currentTokens;
@property (retain, nonatomic) NSString *editingString;
@property (readonly, nonatomic) DVTFilterTokenField *tokenField;
@property (nonatomic) BOOL recentFiltersEnabled;
@property (retain, nonatomic) NSArray *additionalIconMenuItems;
@property (copy, nonatomic) NSArray *sampleFilterTokens;
@property (nonatomic) long long globalOperatorType;
@property (weak, nonatomic) NSObject<DVTFilterTokenFieldControllerDelegate> *delegate;
@property (copy, nonatomic) NSSet *allowedClassesForArchivingState;
@property (readonly, copy, nonatomic) NSData *encodedState;
@property (copy, nonatomic) NSObject<NSCopying, NSSecureCoding> *stateValue;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* instance methods */
- (BOOL)restoreFromEncodedState:(id)state error:(id *)error;
- (void)_setState:(id)state;
- (id)_state;
- (id)initWithFrame:(struct CGRect)frame;
- (void)_updateFilterIconMenu;
- (void)_recentFilterMenuItemSelected:(id)selected;
- (void)_clearRecentFilters:(id)filters;
- (void)clearRecents;
- (id)_menuItemForRecentFilterItem:(id)item;
- (id)_menuItemsForAdditionalFilteringOptions;
- (id)_menuItemsForRecents;
- (id)_menuItemsForSampleFilters;
- (id)tokenFieldIconMenuItemsFor:(id)forNot;
- (id)initWithTokenField:(id)field;
- (void)_updateValuesWithTextStorage:(id)storage;
- (Class)_tokenClass;
- (void)_updateValuesWithArray:(id)array;
- (void)_scrollToMakeTokensVisible:(id)visible tokens:(id)tokens;
- (struct _NSRange)editingStringRangeFromTextStorage:(id)storage;
- (void)_clearEditingStringFromTextStorage:(id)storage;
- (id)_editingStringFromTextStorage:(id)storage;
- (void)_handleCompletionFromStorage:(id)storage andLastChangeID:(unsigned long long)id;
- (void)triggerCompletions;
- (void)controlTextDidChange:(id)change;
- (void)tokenField:(id)field objectValueDidChange:(id)change;
- (BOOL)tokenField:(id)field hasMenuForRepresentedObject:(id)object;
- (id)tokenField:(id)field displayStringForRepresentedObject:(id)object;
- (id)tokenField:(id)field editingStringForRepresentedObject:(id)object;
- (id)attachmentCellForToken:(id)token;
- (id)tokenField:(id)field setUpTokenAttachmentCell:(id)cell forRepresentedObject:(id)object;
- (id)tokenField:(id)field shouldAddObjects:(id)objects atIndex:(unsigned long long)index;
- (unsigned long long)tokenField:(id)field styleForRepresentedObject:(id)object;
- (id)tokenField:(id)field menuForRepresentedObject:(id)object;
- (void)tokenField:(id)field globalOperatorDidChange:(long long)change;
- (void)_tokenFieldMenuItemDidClick:(id)click;
- (id)_mergeFirstTwoStringsFromArrayIfEligible:(id)eligible;
- (id)_currentFieldItems;
- (void)addCompletionToken:(id)token;
- (void)addFilterToken:(id)token;
- (void)addFilterTokens:(id)tokens;
- (void)removeFilterToken:(id)token;
- (void)removeFilterTokens:(id)tokens;
- (void)setTokensAndMoveInsertionPointToEnd:(id)end;
- (void)clearField;
- (void)_updateRecentFilters;
- (void)_somethingDidChangeInFilter;
- (void)_notifySomethingChanged;
- (void)_updateValuesWith:(id)with editingString:(id)string;
- (unsigned long long)tokenFieldCompletionNumOfSections:(id)sections;
- (id)tokenFieldCompletion:(id)completion sectionTitleForSection:(unsigned long long)section;
- (unsigned long long)tokenFieldCompletion:(id)completion numOfRowsForSection:(unsigned long long)section;
- (id)tokenFieldCompletion:(id)completion rowStringFor:(unsigned long long)forNot inSection:(unsigned long long)section;
- (void)tokenFieldCompletion:(id)completion didSelectRow:(unsigned long long)row inSection:(unsigned long long)section;
- (BOOL)isRecentFiltersEnabled;
@end

#endif /* DVTFilterTokenBasedFieldController_h */
