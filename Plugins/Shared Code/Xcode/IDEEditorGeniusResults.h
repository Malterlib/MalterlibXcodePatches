//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEEditorGeniusResults_h
#define IDEEditorGeniusResults_h
#import <Foundation/Foundation.h>

#include "DVTInvalidation-Protocol.h"
#include "IDEEditorDocument.h"
#include "IDEWorkspaceTabController.h"

@class DVTExtension, DVTFileDataType, DVTStackBacktrace, NSArray, NSDictionary, NSString;

@interface IDEEditorGeniusResults : NSObject<DVTInvalidation> {
  /* instance variables */
  IDEWorkspaceTabController *_workspaceTabController;
  IDEEditorDocument *_editorDocument;
  NSArray *_documentLocations;
  BOOL _shouldResetGeniusFinders;
  DVTExtension *_editorDocumentExtension;
  DVTFileDataType *_fileDataType;
  NSArray *_finders;
  NSArray *_geniusCategories;
  BOOL _ignoreGeniusResultsUpdates;
}

@property BOOL idle;
@property (readonly, copy) NSDictionary *geniusResults;
@property (readonly) unsigned long long numberOfGeniusResults;
@property (readonly, copy) NSString *editorDocumentIdentifier;
@property (readonly, nonatomic) BOOL valid;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (void)initialize;
+ (id)indexRequestsQueue;
+ (id)_finderExtensionsForEditorDocumentIdentifier:(id)identifier fileDataType:(id)type;
+ (id)_geniusCategoriesForFinderExtensions:(id)extensions;
+ (BOOL)validGeniusCategory:(id)category forEditorDocumentIdentifier:(id)identifier;
+ (id)_geniusCategoryExtensions;
+ (id)nameForGeniusCategory:(id)category;
+ (id)groupForGeniusCategory:(id)category;
+ (BOOL)singleResultsCategoryForGeniusCategory:(id)category;
+ (BOOL)showHierarchyForSingleResultsCategoryForGeniusCategory:(id)category;
+ (BOOL)hideSubitemCountForGeniusCategory:(id)category;
+ (BOOL)automaticallyNotifiesObserversOfGeniusResults;

/* instance methods */
- (id)initWithWorkspaceTabController:(id)controller;
- (BOOL)_allGeniusFindersAreIdle;
- (BOOL)_allGeniusReultsFindersAllowInstantUpdateGeniusResultsWhenIdle;
- (void)_doUpdateGeniusResultsAfterOneSecond;
- (void)_clearForcedUpdateTimer;
- (void)_setForcedUpdateTimer;
- (void)_clearFindResultsTimer;
- (void)_setFindResultsTimer;
- (void)findGeniusResultsForEditorDocument:(id)document editorDocumentExtension:(id)extension selectedDocumentLocations:(id)locations;
- (void)_doFindGeniusResults;
- (id)geniusCategories;
- (void)_doUpdateGeniusResults;
- (void)_breakIdleCoalescingOfGeniusResultsUpdates;
- (void)_setGeniusResults:(id)results;
- (BOOL)_updateGeniusResults;
- (void)primitiveInvalidate;
@end

#endif /* IDEEditorGeniusResults_h */
