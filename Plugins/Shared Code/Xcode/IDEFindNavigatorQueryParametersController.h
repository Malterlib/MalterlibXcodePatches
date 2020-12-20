//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEViewController.h"

#import "DVTFindPatternManager-Protocol.h"
#import "IDEFindNavigatorPathControlDelegate-Protocol.h"
#import "IDEFindNavigatorScopeChooserControllerDelegate-Protocol.h"

@class DVTDelayedInvocation, DVTInsetView, DVTScopeBarButton, IDEBatchFindNamedScope, IDEBatchFindQueryTerm, IDEFindNavigatorPathControl, IDEFindNavigatorScopeChooserController, IDEFindNavigatorTwoControlLeftPriorityLayout, IDEProgressSearchField, NSArray, NSButton, NSPopUpButton, NSString, NSView;
@protocol DVTInvalidation, IDEFindNavigatorQueryParametersControllerDelegate, IDEFindNavigatorQueryParametersPresentedController;

@interface IDEFindNavigatorQueryParametersController : IDEViewController <IDEFindNavigatorPathControlDelegate, IDEFindNavigatorScopeChooserControllerDelegate, DVTFindPatternManager, NSTextFieldDelegate>
{
    DVTInsetView *_modeRow;
    IDEFindNavigatorPathControl *_modePathControl;
    NSView *_queryTextSearchFieldRow;
    IDEProgressSearchField *_queryTextSearchField;
    NSView *_replaceFieldRow;
    IDEProgressSearchField *_replaceField;
    NSButton *_replaceButton;
    NSButton *_replaceAllButton;
    NSView *_textOptionsRow;
    IDEFindNavigatorTwoControlLeftPriorityLayout *_textOptionsAndScopeContainer;
    NSPopUpButton *_caseMatchingChooserPopUp;
    DVTScopeBarButton *_showScopesButton;
    IDEBatchFindQueryTerm *_selectedQueryTerm;
    long long _selectedQueryAction;
    Class _selectedQueryClass;
    Class _lastEasyToInitiateQueryClass;
    IDEBatchFindNamedScope *_selectedNamedScope;
    long long _selectedAnchoring;
    BOOL _selectedMatchCase;
    NSArray *_candidateQueryClasses;
    IDEFindNavigatorScopeChooserController *_scopeChooser;
    id <DVTInvalidation> _findStateObservationTokens;
    DVTDelayedInvocation *_userInterfaceValidator;
    id <IDEFindNavigatorQueryParametersControllerDelegate> _delegate;
    long long _progress;
    IDEViewController<IDEFindNavigatorQueryParametersPresentedController> *_presentedController;
}

+ (void)configureStateSavingObjectPersistenceByName:(id)arg1;
// - (void).cxx_destruct;
@property(retain, nonatomic) IDEViewController<IDEFindNavigatorQueryParametersPresentedController> *presentedController; // @synthesize presentedController=_presentedController;
@property(nonatomic) long long progress; // @synthesize progress=_progress;
@property __weak id <IDEFindNavigatorQueryParametersControllerDelegate> delegate; // @synthesize delegate=_delegate;
- (void)pathControl:(id)arg1 userChoseValue:(id)arg2 forSegment:(id)arg3;
- (BOOL)pathControl:(id)arg1 shouldHighlightSelectionForValue:(id)arg2 ofSegment:(id)arg3;
- (id)pathControl:(id)arg1 titleForValue:(id)arg2 ofSegment:(id)arg3;
- (id)pathControl:(id)arg1 candidatesForSegment:(id)arg2;
- (id)pathControl:(id)arg1 accessibilityIdentifierForSegment:(id)arg2;
- (id)pathControl:(id)arg1 valueForSegment:(id)arg2;
- (id)pathControlSegments:(id)arg1;
- (void)scoperChooserUserDidInitiateQuery:(id)arg1;
- (void)scoperChooserUserDidChooseScope:(id)arg1;
- (BOOL)supportsPatterns;
- (id)replaceFieldForField:(id)arg1;
- (id)findFieldForField:(id)arg1;
- (void)insertFindPattern:(id)arg1;
- (void)insertReplacePattern:(id)arg1;
- (void)insertFindPatternForField:(id)arg1;
- (void)userDidSelectHistoricQuery:(id)arg1;
- (void)selectQuerySpecification:(id)arg1 honorQueryTerm:(BOOL)arg2;
- (void)clearSearchHistory:(id)arg1;
- (id)replaceFieldMenu;
- (id)findFieldMenu;
- (id)insertPatternMenuItemWithAction:(SEL)arg1;
- (id)menuItemForHistoryQuery:(id)arg1 withFont:(id)arg2;
- (void)selectNamedScope:(id)arg1;
- (void)enterFindText:(id)arg1;
- (void)enterQueryTerm:(id)arg1;
- (BOOL)focusFindFieldAfterPreparingTheNavigatorForFocus;
- (void)prepareForExternallyInvokedTextualQuery;
- (Class)preferredEasilyManuallyInitiatableQueryClass;
- (void)selectMatchCase:(BOOL)arg1;
- (void)selectQueryAnchoring:(long long)arg1;
- (void)selectQueryAction:(long long)arg1;
- (void)selectQueryClass:(Class)arg1;
- (void)initiateQuery;
- (id)currentQuerySpecification;
- (void)controlTextDidChange:(id)arg1;
- (void)chooseScope:(id)arg1;
- (void)dismissPresentedController;
- (void)replaceAllItems:(id)arg1;
- (void)replaceSelectedItems:(id)arg1;
- (id)replacementText;
- (void)beginQuery:(id)arg1;
- (void)userChooseCaseMatching:(id)arg1;
- (void)scheduleUIRefreshConditionallyInvalidatingSavedState:(BOOL)arg1 notifyOfExportedStateChange:(BOOL)arg2;
- (void)viewDidLoad;
- (void)viewDidInstall;
- (void)pullReplaceTextFromSharedFindState;
- (void)pullFindTextFromSharedFindState;
- (id)view;
- (void)pathControlShouldRefresh:(id)arg1;
- (void)refreshUserInterface:(id)arg1;
- (id)attributedStringForTitle:(id)arg1 control:(id)arg2 accented:(BOOL)arg3;
- (void)revertStateWithDictionary:(id)arg1;
- (void)commitStateToDictionary:(id)arg1;
- (void)primitiveInvalidate;
- (BOOL)automaticallyInvalidatesChildViewControllers;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) Class superclass;

@end

