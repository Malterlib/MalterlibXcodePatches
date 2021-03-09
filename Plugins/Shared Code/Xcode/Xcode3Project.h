//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "IDEContainer.h"

#import "IDEBlueprintProvider-Protocol.h"
#import "IDECustomDataStoring-Protocol.h"
#import "IDEIndexableProvider-Protocol.h"
#import "IDELocalizedContainer-Protocol.h"
#import "IDETestableProvider-Protocol.h"
#import "IDEWorkspaceWrappingContainer-Protocol.h"
#import "Xcode3SourceListItemEditing-Protocol.h"

@class DVTLocale, DVTModelObjectGraph, DVTObservingToken, DVTStackBacktrace, IDEActivityLogSection, IDEDirectoryBasedCustomDataStore, NSArray, NSMapTable, NSMutableArray, NSMutableDictionary, NSSet, NSString, PBXProject, PBXReference;
@protocol IDETestableProvider;

@interface Xcode3Project : IDEContainer <IDEBlueprintProvider, IDEIndexableProvider, IDETestableProvider, Xcode3SourceListItemEditing, IDECustomDataStoring, IDEWorkspaceWrappingContainer, IDELocalizedContainer>
{
    PBXProject *_project;
    PBXReference *_projectReference;
    int _saveErrorCode;
    NSArray *_targets;
    NSMapTable *_pbxTargetsToXc3Targets;
    NSArray *_testables;
    NSMapTable *_xc3TargetsToTestables;
    NSMutableArray *_localizations;
    BOOL _isBaseLocalized;
    BOOL _integrityCheckingBlockQueued;
    BOOL _hasRunUpgradeCheck;
    DVTObservingToken *_projectObservation_targets;
    IDEDirectoryBasedCustomDataStore *_customDataStore;
    DVTObservingToken *_needsArchiveObservingToken;
    BOOL _pbxProjectEdited;
    BOOL _shouldLogUpgradeCheck;
    NSArray *_customUpgradeTasks;
    NSMutableDictionary *_deferredCustomUpgradeRegistrations;
    id _activeSchemeObservation;
    NSArray *_sortedLocalizationsIncludingBase;
    NSArray *_sortedLocalizationsWithoutBase;
}

+ (id)keyPathsForValuesAffectingTestables;
+ (id)deserializedSourceListItem:(id)arg1;
+ (id)pasteboardDataType;
+ (id)keyPathsForValuesAffectingIndexables;
+ (id)keyPathsForValuesAffectingBaseLocalized;
+ (id)keyPathsForValuesAffectingSourcePackageReferences;
+ (id)keyPathsForValuesAffectingBlueprints;
+ (id)containerDataFilePathsForFilePath:(id)arg1;
+ (BOOL)_shouldTrackReadOnlyStatus;
+ (BOOL)supportsFilePersistence;
+ (id)keyPathsForValuesAffectingName;
+ (id)swiftCompilerSpecification;
+ (id)availableSwiftVersions;
+ (id)xcode3ProjectCreationErrorHandler;
+ (void)setXcode3ProjectCreationErrorHandler:(Class)arg1;
+ (long long)obsoleteProjectVersion;
+ (id)allowedProjectArchiveVersions;
+ (id)currentProjectFileExtension;
+ (id)containerTypeDisplayName;
+ (id)containerFileDataType;
+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (void)initialize;
// - (void).cxx_destruct;
@property(nonatomic) BOOL pbxProjectEdited; // @synthesize pbxProjectEdited=_pbxProjectEdited;
@property BOOL hasRunUpgradeCheck; // @synthesize hasRunUpgradeCheck=_hasRunUpgradeCheck;
@property(retain) IDEActivityLogSection *issueLog; // @synthesize issueLog=_issueLog;
@property(retain) PBXProject *pbxProject; // @synthesize pbxProject=_project;
@property(retain) IDEDirectoryBasedCustomDataStore *customDataStore; // @synthesize customDataStore=_customDataStore;
@property int buildSystemType;
- (int)buildSystemTypeFromString:(id)arg1;
- (id)absolutePathByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
- (id)stringByEvaluatingBuildSettingExpressionString:(id)arg1 withBuildParameters:(id)arg2;
- (id)evaluatedStringListValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
- (id)evaluatedStringValueForBuildSetting:(id)arg1 withBuildParameters:(id)arg2;
- (id)allBuildSettingNamesWithBuildParameters:(id)arg1;
- (id)cachedMacroExpansionScopeForBuildParameters:(id)arg1;
@property(readonly) NSString *uniqueIdentifier;
- (void)clearTestablesCache;
- (void)_updateTestablesForTargetProxies:(id)arg1;
- (id)testableForBlueprint:(id)arg1;
@property(readonly, copy) NSArray *testables;
@property(readonly) id <IDETestableProvider> testableProvider;
- (void)addSpecifier:(id)arg1 inWorkspace:(id)arg2 toSCMWithCompletionBlock:(CDUnknownBlockType)arg3;
- (void)scmStatusForSpecifier:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)customDataStoreContainerClosing:(id)arg1;
- (BOOL)supportsCustomDataForOwnership:(id)arg1;
- (void)moveCustomDataWithSpecifier:(id)arg1 toSpecifier:(id)arg2 completionQueue:(id)arg3 completionBlock:(CDUnknownBlockType)arg4;
- (void)removeCustomDataWithSpecifier:(id)arg1 completionQueue:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)writeCustomData:(id)arg1 withSpecifier:(id)arg2 forceOverwrite:(BOOL)arg3 completionQueue:(id)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (id)readCustomDataWithSpecifier:(id)arg1 error:(id *)arg2;
- (id)customDataOwnershipsForGrouping:(id)arg1;
- (id)customDataSpecifiersForGrouping:(id)arg1 ownership:(id)arg2;
- (void)_updateCachedLastUpgradeVersionToCurrent;
@property(readonly) NSString *cachedLastUpgradeVersion;
- (void)updateLastUpgradeVersionToCurrent;
@property(readonly) NSString *lastUpgradeVersion;
- (id)serializedSourceListItem;
@property(readonly, copy) NSArray *indexables;
- (BOOL)installSourcesToPath:(id)arg1;
- (void)collectMessageTracerStatisticsIntoDictionary:(id)arg1;
- (void)analyzeModelForIssues;
- (void)_unregisterDeferredCustomUpgradeTask:(id)arg1 handler:(id)arg2;
- (id)_deferredCustomUpgradeHandlerForUUID:(id)arg1;
- (id)_deferredCustomUpgradeTaskForUUID:(id)arg1;
- (id)_registerDeferredCustomUpgradeTask:(id)arg1 handler:(id)arg2;
- (void)enumerateUpgradeTasksWithBlock:(CDUnknownBlockType)arg1;
- (void)updateLastSwiftMigrationToCurrent;
@property(readonly) BOOL lastSwiftMigrationIsCurrent;
- (void)updateLastSwiftUpdateVersionToCurrent;
@property(readonly) NSString *lastSwiftUpdateVersion;
@property(readonly) BOOL shouldLogUpgradeCheck;
- (void)_runUpgradeChecksIfNecessary;
- (BOOL)setBaseSDKPlatform:(id)arg1 forConfiguration:(id)arg2;
- (void)enableAnalyzerLocalizabilityCheckIfNeeded;
@property(copy) DVTLocale *developmentRegion;
- (void)removeLocalization:(id)arg1 deleteFiles:(BOOL)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)moveBaseLocalizationToLocalization:(id)arg1 completionBlock:(CDUnknownBlockType)arg2;
- (void)moveLocalizationVariantGroups:(id)arg1 toLocalization:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)copyLocalizationVariantGroups:(id)arg1 toLocalization:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)addLocalization:(id)arg1;
@property(readonly, getter=isBaseLocalized) BOOL baseLocalized;
@property(readonly, copy) NSArray *localizations;
- (void)_invalidateSortedLocalizations;
- (id)sortedLocalizationsIncludingBase:(BOOL)arg1;
@property(readonly, copy) NSSet *variantGroups;
- (BOOL)hasConfigurationNamed:(id)arg1;
- (id)blueprintForPBXTarget:(id)arg1;
- (id)blueprintForIdentifier:(id)arg1;
- (id)blueprintForName:(id)arg1;
@property(readonly) NSArray *sourcePackageReferences;
@property(readonly, copy) NSArray *blueprints;
- (void)_packageReferenceDidChange:(id)arg1;
- (void)_packageReferenceWillChange:(id)arg1;
- (void)_projectWillRemoveTarget:(id)arg1;
- (void)_projectDidAddTarget:(id)arg1;
- (void)_projectBuildSettingsDidChange:(id)arg1;
- (void)_projectDidChange:(id)arg1;
- (void)_projectWillChange:(id)arg1;
- (void)_projectDidSave:(id)arg1;
- (void)_projectNeedsRevert:(id)arg1;
- (BOOL)writeToFilePath:(id)arg1 forceWrite:(BOOL)arg2 error:(id *)arg3;
- (BOOL)supportsOnDemandResources;
- (void)holdOnDiskFilesForICloudDriveIfNecessary;
- (void)_containerDidLoad;
- (id)_itemBaseFilePathForFilePath:(id)arg1;
- (id)createRootGroup;
- (void)primitiveInvalidate;
- (void)_setContainerEdited;
- (void)setContainerEdited:(BOOL)arg1;
- (BOOL)containerEdited;
- (void)becomeWorkspaceWrappingContainer;
- (void)_willInvalidateContainerToDiscardInMemoryRepresentation;
- (id)initWithFilePath:(id)arg1 extension:(id)arg2 workspace:(id)arg3 options:(id)arg4 error:(id *)arg5;
@property(readonly) NSString *defaultConfigurationName;
@property(readonly) NSArray *configurationNames;
- (id)xcode3TargetForPBXTarget:(id)arg1;
- (void)syncTargetProxiesWithProjectTargets;
@property(readonly) NSArray *targetProxies;
- (BOOL)hasValueSetForBuildSetting:(id)arg1;
@property(copy) NSString *classPrefix;
@property(copy) NSString *organizationName;
- (id)localizedDescription;
- (id)ideModelObjectTypeIdentifier;
@property unsigned long long preferredProjectFormat;
@property(readonly) NSString *displayName;
@property(readonly, copy) NSString *name;
- (id)supportedSourceListItemEditorClasses;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly, nonatomic) DVTModelObjectGraph *objectGraph;
@property(readonly) Class superclass;
@property(readonly) BOOL supportsSourceFolders;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

