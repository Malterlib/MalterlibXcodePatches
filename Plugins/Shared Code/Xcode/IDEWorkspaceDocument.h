//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEWorkspaceDocument_h
#define IDEWorkspaceDocument_h
#import <Foundation/Foundation.h>


#include "DVTCancellable-Protocol.h"
#include "DVTInvalidation-Protocol.h"
#include "DVTStateRepositoryDelegate-Protocol.h"
#include "DVTStatefulObject-Protocol.h"
#include "IDEActiveRunContextStoring-Protocol.h"
#include "IDEActivityReportManager.h"
#include "IDEFindNavigatorQueryHistoryManager.h"
#include "IDELibraryWindowController.h"
#include "IDERunContextRecents.h"
#include "IDESourceControlWorkspaceDocumentUIHandlerProtocol-Protocol.h"
#include "IDEWorkspaceDelegate-Protocol.h"
#include "IDEWorkspaceWindowController.h"

@class DVTDelayedInvocation, DVTNotificationToken, DVTObservingToken, DVTPerformanceMetric, DVTStackBacktrace, DVTStateRepository, DVTStateToken, DVTSystemActivityToken, IDEOpenQuicklyWorkspaceContentContextProvider, IDEScriptingSchemeActionResult, IDEWorkspace, NSArray, NSDate, NSDictionary, NSHashTable, NSMapTable, NSMutableArray, NSMutableDictionary, NSMutableSet, NSString, NSURL, DVTInvalidation, IDEUIRecordingManager;
@protocol IDETrayManager, DVTInvalidation, IDEEditorContextDefaultStateStorage, IDEMustCloseOnQuitDocument, IDEPreBuildSavingDelegate, IDEActiveRunContextStoring;

@interface IDEWorkspaceDocument : NSDocument<IDEActiveRunContextStoring, IDEWorkspaceDelegate, DVTInvalidation, DVTStatefulObject, DVTStateRepositoryDelegate, IDEMustCloseOnQuitDocument, IDEPreBuildSavingDelegate, IDEEditorContextDefaultStateStorage> {
  /* instance variables */
  IDEWorkspaceWindowController *_lastActiveWorkspaceWindowController;
  NSHashTable *_allRecentEditorDocumentURLs;
  NSMutableDictionary *_defaultEditorStateTree;
  NSMutableDictionary *_defaultPrimaryEditorFrameSizes;
  NSMutableSet *_editedDocuments;
  NSMapTable *_controllerForDebugSessionTable;
  DVTDelayedInvocation *_stateSavingDelayedInvocation;
  DVTObservingToken *_isWorkspaceIdleToken;
  DVTObservingToken *_launchSessionsObservingToken;
  DVTObservingToken *_launchSessionsRunnablePIDObservingToken;
  DVTNotificationToken *_launchSessionErrorToken;
  DVTObservingToken *_currentDebugSessionObserverToken;
  DVTNotificationToken *_applicationIsQuittingNotificationToken;
  DVTObservingToken *_currentExecutionTrackerObservingToken;
  NSMapTable *_hasGUIValueForLaunchSessionMap;
  NSDictionary *_previousSessionActiveRunContextInfo;
  NSDictionary *_previousSessionActiveRunDestinationInfo;
  id /* block */ _upgradeCompletionBlock;
  NSMutableArray *_stateChangeObservingTokens;
  BOOL _lastWorkspaceWindowHasStartedClosing;
  BOOL _isInvalidated;
  BOOL _didSetupUISubsystemsForFullWorkspace;
  BOOL _didSetupUISubsystemsForFullWorkspaceOrSimpleFilesFocused;
  BOOL _isCheckingCanClose;
  id _openingPerformanceMetricIdentifier;
  BOOL _didRevertWindowState;
  NSString *_windowTabbingIdentifier;
  DVTSystemActivityToken *_systemActivityToken;
  DVTObservingToken *_executionTrackerIsFinishedObservingToken;
  DVTObservingToken *_executionTrackerWantsHoldObservingToken;
  DVTObservingToken *_executionEnvironmentCurrentBuildOperationObservingToken;
  DVTObservingToken *_simpleFilesFocusedObservingToken;
  DVTPerformanceMetric *_closingMetric;
  NSObject<DVTCancellable> *_delayedStatisticsCollectionToken;
  double _workspaceSessionStartTime;
  unsigned long long _rosettaRunDestinationVisibility;
  DVTNotificationToken *_editorDocumentWillSaveNotificationToken;
  DVTNotificationToken *_editorDocumentDidSaveNotificationToken;
  DVTNotificationToken *_holdFilesOnAppActivationNotificationToken;
}

@property (retain) DVTStateToken *stateToken;
@property (retain) IDERunContextRecents *runContextRecents;
@property (copy) NSArray *orderedWindowControllerNames;
@property (copy) NSDictionary *stateSavingDefaultEditorStatesForURLs;
@property (copy) NSArray *stateSavingRecentEditorDocumentURLs;
@property (retain) NSMutableDictionary *tabStateContextForTabNameMap;
@property BOOL applicationIsTerminating;
@property (retain) NSObject<IDESourceControlWorkspaceDocumentUIHandlerProtocol> *sourceControlWorkspaceUIHandler;
@property BOOL didReportCanClose;
@property (copy) NSDate *icloudDriveLastHeldDate;
@property (readonly) IDEWorkspace *workspace;
@property (readonly) DVTStateRepository *stateRepository;
@property BOOL userWantsBreakpointsActivated;
@property (readonly) IDEActivityReportManager *activityReportManager;
@property (retain, nonatomic) IDEUIRecordingManager<DVTInvalidation> *uiRecordingManager;
@property (readonly) BOOL dvt_closed;
@property (readonly, nonatomic) BOOL isClosing;
@property (readonly) BOOL closed;
@property (readonly) DVTStackBacktrace *invalidationBacktrace;
@property (readonly) NSArray *recentEditorDocumentURLs;
@property (readonly, nonatomic) NSURL *fileURLToReopenWorkspace;
@property (retain) IDEScriptingSchemeActionResult *lastScriptingSchemeActionResult;
@property (readonly) NSObject<IDETrayManager> *trayManager;
@property (nonatomic) BOOL createdAsUntitled;
@property (readonly) IDEFindNavigatorQueryHistoryManager *findNavigatorQueryHistoryManager;
@property (readonly) IDEOpenQuicklyWorkspaceContentContextProvider *openQuicklyContentContextProvider;
@property (readonly) IDELibraryWindowController *libraryWindowController;
@property unsigned long long rosettaVisibility;
@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;
@property (readonly, nonatomic) BOOL valid;
@property (retain) DVTStackBacktrace *creationBacktrace;
@property (readonly) BOOL canRevertWithEmptyStateDictionary;
@property (readonly) BOOL canRevertStateBeforeLayout;

/* class methods */
+ (void)initialize;
+ (BOOL)preservesVersions;
+ (BOOL)autosavesInPlace;
+ (BOOL)autosavesDrafts;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)selector;
+ (id)documentTypeName;
+ (id)debuggerUIExtensionForLaunchSession:(id)session;
+ (id)activeWorkspaceTabControllerForWorkspace:(id)workspace;
+ (id)documentForWorkspace:(id)workspace;
+ (BOOL)canRecentFilesUseDocumentURL:(id)url checkIsFileURLReachable:(BOOL)urlreachable;
+ (long long)_unlimitedMaximumRecentEditorDocumentCountMarker;
+ (long long)_maximumRecentEditorDocumentCount;
+ (void)_setMaximumRecentEditorDocumentCount:(long long)count;
+ (void)configureStateSavingObjectPersistenceByName:(id)name;
+ (long long)version;
+ (id)keyPathsForValuesAffectingUserWantsBreakpointsActivated;

/* instance methods */
- (id)librariesByExtensionID;
- (BOOL)sdefSupport_isLoaded;
- (BOOL)_checkForLoading;
- (id)sdefSupport_projects;
- (id)sdefSupport_schemes;
- (id)sdefSupport_activeScheme;
- (void)setSdefSupport_activeScheme:(id)scheme;
- (id)sdefSupport_runDestinations;
- (id)sdefSupport_activeRunDestination;
- (void)setSdefSupport_activeRunDestination:(id)destination;
- (id)sdefSupport_lastSchemeActionResult;
- (id)sdefSupport_schemeActionResults;
- (id)newScriptingObjectOfClass:(Class)class forValueForKey:(id)key withContentsValue:(id)value properties:(id)properties;
- (id)displayName;
- (id)objectSpecifier;
- (id)sdefSupport_fileURL;
- (id)sdefSupport_path;
- (id)sdefSupport_build:(id)support_build;
- (id)sdefSupport_clean:(id)support_clean;
- (id)sdefSupport_run:(id)support_run;
- (id)sdefSupport_test:(id)support_test;
- (id)sdefSupport_stop:(id)support_stop;
- (id)_performScriptingSchemeCommand:(unsigned long long)command forScriptCommand:(id)command;
- (id)sdefSupport_attach:(id)support_attach;
- (id)sdefSupport_debug:(id)support_debug;
- (id)_openWindowTerminationDisablingReason;
- (id)init;
- (id)initWithWorkspace:(id)workspace;
- (id)initWithType:(id)type error:(id *)error;
- (id)initForURL:(id)url withContentsOfURL:(id)url ofType:(id)type error:(id *)error;
- (void)_setUpSourceControlWorkspaceHandler;
- (id)windowForSheet;
- (BOOL)_isLocatedByURL:(id)url becauseOfAutosavedContentsFile:(BOOL *)file;
- (void)dvt_shouldDeallocate;
- (id)_openingPerformanceMetricIdentifier;
- (BOOL)isClosed;
- (BOOL)dvt_hasBeenEditedSinceLastUserInitiatedSave;
- (void)writeStateIfNeeded;
- (void)primitiveInvalidate;
- (void)close;
- (BOOL)_closeAfterSavingDirtyEditorDocumentsWithCancelButton:(BOOL)button;
- (BOOL)_canCloseWorkspaceDocument;
- (BOOL)canCloseDocumentAtQuit;
- (void)shouldCloseWindowController:(id)controller delegate:(id)delegate shouldCloseSelector:(SEL)selector contextInfo:(void *)info;
- (void)canCloseDocumentWithDelegate:(id)delegate shouldCloseSelector:(SEL)selector contextInfo:(void *)info;
- (void)revertDocumentToSaved:(id)saved;
- (void)saveDocument:(id)document;
- (void)saveDocumentAs:(id)as;
- (void)duplicateDocument:(id)document;
- (void)saveDocumentTo:(id)to;
- (void)printDocument:(id)document;
- (void)runPageLayout:(id)layout;
- (BOOL)validateUserInterfaceItem:(id)item;
- (BOOL)prepareSavePanel:(id)panel;
- (void)saveAsWorkspace:(id)workspace;
- (void)_workspaceDocument:(id)document didSave:(BOOL)save contextInfo:(void *)info;
- (void)_upgradeAlertDidEnd:(id)end returnCode:(long long)code;
- (void)saveAsWorkspace:(id)workspace showAlert:(BOOL)alert completionBlock:(id /* block */)block;
- (BOOL)saveToURL:(id)url ofType:(id)type forSaveOperation:(unsigned long long)operation error:(id *)error;
- (void)didReceiveEditorDocumentWillSaveNotification:(id)notification;
- (void)didReceiveEditorDocumentDidSaveNotification:(id)notification;
- (void)_reportWorkspaceMetricsForInternalUsersAtStage:(long long)stage;
- (id)_cppFileExtensions;
- (id)_objcppFileExtensions;
- (id)_allClangFileExtensions;
- (id)_headerFileExtensions;
- (id)_makeFileExtensions;
- (long long)_projectCountForWorkspace:(id)workspace;
- (id)_firstErrorForExecutionTracker:(id)tracker consideringOnlyOnHoldTrackers:(BOOL)trackers;
- (void)_presentErrorForLaunch:(id)launch;
- (void)_setupLaunchSessionsObservation;
- (void)_workspace:(id)_workspace failedToResolveContainerForProjectFile:(id)file;
- (void)setupUISubsystems;
- (void)setupUISubsystemsForFullWorkspaceOrSimpleFilesFocused;
- (void)setupUISubsystemsForFullWorkspace;
- (BOOL)checkAutosavingSafetyAndReturnError:(id *)error;
- (BOOL)_checkAutosavingPossibilityAndReturnError:(id *)error;
- (BOOL)_shouldShowAutosaveButtonForWindow:(id)window;
- (void)performBlockAfterPreBuildSave:(id /* block */)save;
- (id)dataOfType:(id)type error:(id *)error;
- (BOOL)readFromData:(id)data ofType:(id)type error:(id *)error;
- (id)printOperationWithSettings:(id)settings error:(id *)error;
- (void)_container:(id)_container didChangeFromFilePath:(id)path toFilePath:(id)path;
- (void)holdOnDiskFilesForICloudDriveIfNecessary;
- (void)_workspace:(id)_workspace didChangeFinishedLoadingTo:(BOOL)to;
- (void)_workspace:(id)_workspace didChangeSimpleFilesFocusedTo:(BOOL)to;
- (void)_setWorkspace:(id)workspace;
- (id)activeWorkspaceWindowController;
- (void)setLastActiveWorkspaceWindowController:(id)controller;
- (BOOL)isUIStateSavingEnabled;
- (BOOL)_readFromURL:(id)url ofType:(id)type simpleFilesFocused:(BOOL)focused error:(id *)error;
- (BOOL)readFromURL:(id)url ofType:(id)type error:(id *)error;
- (BOOL)revertToContentsOfURL:(id)url ofType:(id)type error:(id *)error;
- (void)_handleDocumentFileChanges:(id)changes;
- (BOOL)_isExpendableAsUnsavedDocument;
- (void)presentedItemDidMoveToURL:(id)url;
- (void)presentedItemDidChange;
- (void)_setLaunchSessionToIntensiveFileIODoneStateIfNecessary:(id)necessary;
- (void)_activateTargetProcess:(id)process tryCounter:(long long)counter;
- (void)_updateIconForLaunchSessionIfNecessary:(id)necessary pid:(int)pid;
- (id)_appIconForLaunchSession:(id)session pid:(int)pid;
- (BOOL)_isXcodeActiveAndTargetInActivatableState:(id)state;
- (void)_delayedActivateTargetProcess:(id)process;
- (void)activateTargetProcessForLaunchSession:(id)session;
- (id)debugSessionControllerForLaunchSession:(id)session;
- (id)defaultEditorStateDictionaryForEditorContext:(id)context documentURL:(id)url documentExtensionIdentifier:(id)identifier;
- (void)cacheDefaultEditorStateDictionary:(id)dictionary forEditorContext:(id)context documentURL:(id)url documentExtensionIdentifier:(id)identifier;
- (void)_cacheDefaultEditorStateDictionary:(id)dictionary forDocumentURL:(id)url documentExtensionIdentifier:(id)identifier;
- (struct CGSize)_defaultPrimaryEditorFrameSizeForDocumentURL:(id)url;
- (void)_setDefaultPrimaryEditorFrameSize:(struct CGSize)size forDocumentURL:(id)url;
- (id)_editedDocuments;
- (void)_didOpenDocument:(id)document;
- (void)_willEditDocument:(id)document;
- (void)_editorDocumentWillClose:(id)close;
- (void)windowControllerWindowWillClose:(id)close;
- (void)_clearRecentEditorDocumentURLs;
- (id)_allRecentEditorDocumentURLs;
- (void)_addRecentEditorDocumentURL:(id)url;
- (id)_makeWindowControllerWithUniqueID;
- (id)_makeWindowControllerWithStateSavingIdentifier:(id)identifier;
- (id)windowControllerWithStateSavingIdentifier:(id)identifier;
- (id)existingWindowWithUserDefinedTabLabel:(id)label;
- (id)createWindowWithUserDefinedTabLabel:(id)label inNewWindow:(BOOL)window restoringAfter:(double)after;
- (id)createWindowWithUserDefinedTabLabel:(id)label addToTabGroup:(BOOL)group activate:(BOOL)activate;
- (void)_setUpSimpleFilesFocusedObservingToken;
- (void)_setupStateSaving;
- (void)makeWindowControllers;
- (void)addWindowController:(id)controller;
- (void)removeWindowController:(id)controller;
- (id)_stateSavingCustomDataSpecifier;
- (void)writeStateData;
- (BOOL)readStateData;
- (id)_windowTabbingIdentifier;
- (void)_setWindowTabbingIdentifier:(id)identifier;
- (void)stateRepositoryDidChange:(id)change;
- (void)configureStateSavingObservers;
- (void)revertStateWithDictionary:(id)dictionary;
- (void)commitStateToDictionary:(id)dictionary;
- (void)showWindows;
- (void)_reallySetStatesForURLs:(id)urls;
- (id)_tabGroupIDsBySelectedWindowControllerIdentifierForStateSaving;
- (id)_selectedWindowControllerNamesForStateSaving;
- (void)_restoreSelectedTabsByIdentifierFromStateSaving:(id)saving;
- (id)activeRunContextInfo;
- (id)activeRunDestinationInfo;
- (id)storedRunContextName;
- (id)storedRunDestinationSelectable;
- (void)setCurrentScheme:(id)scheme;
- (id)orderedRecentSchemes;
- (void)schemeDidChangeNameFromOldName:(id)name toNewName:(id)name;
- (void)clearSchemeHistory:(id)history;
- (void)clearRecentSchemes;
- (id)orderedRecentRunDestinationsForScheme:(id)scheme;
- (id)lastUsedRunDestinationIfAvailableForScheme:(id)scheme;
- (void)setCurrentRunDestination:(id)destination activeScheme:(id)scheme;
- (void)clearRecentRunDestinations;
- (id)dvt_extraBindings;
- (BOOL)containsPlaygroundDocumentAtURL:(id)url;
- (void)initializeTrayManager;
- (BOOL)dvt_isClosed;
@end

#endif /* IDEWorkspaceDocument_h */
