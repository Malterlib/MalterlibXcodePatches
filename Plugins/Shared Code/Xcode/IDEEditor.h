//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEViewController.h"

@class DVTFindBar, DVTNotificationToken, DVTObservingToken, DVTScopeBarsManager, IDEEditorContext, IDEEditorDocument, IDEFileTextSettings, NSAppearance, NSScrollView;
@protocol DVTTextFindable, IDEEditorDelegate;

@interface IDEEditor : IDEViewController
{
    DVTFindBar *_findBar;
    DVTNotificationToken *_documentDidChangeNotificationToken;
    DVTNotificationToken *_documentForNavBarStructureDidChangeNotificationToken;
    DVTObservingToken *_documentFileURLObservingToken;
    BOOL _discardsFindResultsWhenContentChanges;
    id <IDEEditorDelegate> _delegate;
    IDEEditorDocument *_document;
    IDEEditorDocument *_documentForNavBarStructure;
    id <DVTTextFindable> _findableObject;
    IDEFileTextSettings *_fileTextSettings;
    NSAppearance *_overridingLibraryAppearance;
    IDEEditorContext *_editorContext;
}

+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (BOOL)canProvideCurrentSelectedItems;
@property(retain) IDEEditorContext *editorContext; // @synthesize editorContext=_editorContext;
@property(readonly) NSAppearance *overridingLibraryAppearance; // @synthesize overridingLibraryAppearance=_overridingLibraryAppearance;
@property(retain, nonatomic) IDEFileTextSettings *fileTextSettings; // @synthesize fileTextSettings=_fileTextSettings;
@property(retain, nonatomic) id <DVTTextFindable> findableObject; // @synthesize findableObject=_findableObject;
@property BOOL discardsFindResultsWhenContentChanges; // @synthesize discardsFindResultsWhenContentChanges=_discardsFindResultsWhenContentChanges;
@property(retain, nonatomic) IDEEditorDocument *documentForNavBarStructure; // @synthesize documentForNavBarStructure=_documentForNavBarStructure;
@property(retain) IDEEditorDocument *document; // @synthesize document=_document;
@property(retain) id <IDEEditorDelegate> delegate; // @synthesize delegate=_delegate;
// - (void).cxx_destruct;
- (void)shouldNavigateAway:(CDUnknownBlockType)arg1;
- (BOOL)shouldCloseDocumentWhenClosingEditor;
- (BOOL)hideGeniusCategory:(id)arg1 results:(id)arg2;
- (id)relatedMenuItemsForNavItem:(id)arg1;
- (void)didSetupEditor;
- (void)navigateToAnnotationWithRepresentedObject:(id)arg1 wantsIndicatorAnimation:(BOOL)arg2 exploreAnnotationRepresentedObject:(id)arg3;
- (void)selectDocumentLocations:(id)arg1;
- (id)representedObjectForGeniusResultsPreviousDocumentLocation:(id)arg1;
- (id)navigableItemArchivableRepresentationForRepresentedObject:(id)arg1;
- (id)currentSelectedDocumentLocations;
- (id)currentSelectedItems;
- (void)primitiveInvalidate;
- (id)supplementalTargetForAction:(SEL)arg1 sender:(id)arg2;
@property(readonly) NSScrollView *mainScrollView;
@property(readonly) DVTScopeBarsManager *scopeBarsManager;
@property(readonly, getter=isPrimaryEditor) BOOL primaryEditor;
- (void)setupContextMenuWithMenu:(id)arg1 withContext:(id)arg2;
- (void)setupNavigateMenu:(id)arg1;
- (void)setupEditorMenu:(id)arg1;
- (void)takeFocus;
- (void)invalidateFindBarResults;
@property(readonly) DVTFindBar *findBar; // @synthesize findBar=_findBar;
- (void)editorContextDidHideFindBar;
- (id)createFindBar;
@property(readonly) BOOL providesOwnFindBar;
@property(readonly) BOOL findBarSupported;
- (id)_getUndoManager:(BOOL)arg1;
- (id)undoManager;
- (void)addObserver:(id)arg1 forKeyPath:(id)arg2 options:(unsigned long long)arg3 context:(void *)arg4;
- (int)editorMode;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2 document:(id)arg3;
- (id)_initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initWithNibName:(id)arg1 bundle:(id)arg2;
- (id)initUsingDefaultNib;
- (BOOL)wantsToSuppressEditorAreaFunctionBar;

@end

