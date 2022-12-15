//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"

@class DVTObservingToken, DVTStackBacktrace, DVTTimeSlicedMainThreadWorkQueue, IDEBuildParameters, IDEIssueCounter, IDEIssueLogRecordsGroup, IDEIssueProviderSession, IDEWorkspace, NSArray, NSHashTable, NSMapTable, NSMutableArray, NSMutableDictionary, NSMutableSet, NSSet, NSString;

@interface IDEIssueManager : NSObject <DVTInvalidation>
{
    NSMutableArray *_issueProviders;
    NSMapTable *_providerContextToProvisionInfoMap;
    NSMapTable *_issueToProviderContextMap;
    NSMutableArray *_issueGroups;
    NSMapTable *_identifierToGroupIndex;
    NSMapTable *_issueToGroupsIndex;
    NSMapTable *_issueToBlueprintsIndex;
    NSMapTable *_issueToContainersIndex;
    NSMutableSet *_issuesThatWillBeRemoved;
    NSMutableArray *_vendedIssuesWithNoDocument;
    IDEIssueCounter *_allIssuesCounter;
    NSMutableDictionary *_issuesWithNoDocumentGroupedByCoalescingBucketID;
    NSMutableSet *_issuesWithNoDocument;
    NSMutableArray *_documentURLsWithVendedIssues;
    NSMutableDictionary *_documentURLToIssueSummaryDict;
    NSHashTable *_allDocumentURLObservers;
    unsigned long long _nextIssueSequenceNumber;
    NSMapTable *_providerToSessionObservationToken;
    unsigned long long _nextGroupSequenceNumber;
    NSMapTable *_identifierToGroupSequenceNumberIndex;
    IDEIssueProviderSession *_lastSchemeActionSession;
    NSMutableSet *_lastSchemeActionIssues;
    id _issueFixedObserver;
    id _liveIssuesEnabledObserver;
    DVTTimeSlicedMainThreadWorkQueue *_buildableDependencyFinderQueue;
    IDEBuildParameters *_cachedBuildParamsForFindingBuildDependencies;
    NSMutableSet *_buildablesAlreadyCheckedForDependencies;
    NSHashTable *_cachedBlueprintsForShowingIssuesForActiveScheme;
    NSHashTable *_cachedBlueprintsForActiveScheme;
    NSHashTable *_cachedContainersForActiveScheme;
    long long _currentIssueFilterStyle;
    id _issueFilterStyleObserver;
    id _schemeBuildablesObserver;
    DVTObservingToken *_activeSchemeObserver;
    DVTObservingToken *_runDestinationObserver;
    DVTObservingToken *_implicitDependenciesObserver;
    DVTObservingToken *_referencedBlueprintsOberver;
    DVTObservingToken *_referencedContainersObserver;
    DVTObservingToken *_workspaceFinishedLoadingObserver;
    BOOL _liveIssuesEnabled;
    IDEWorkspace *_workspace;
    unsigned long long _numberOfBuildtimeIssues;
    unsigned long long _numberOfRuntimeIssues;
    IDEIssueLogRecordsGroup *_issueLogRecordsGroup;
}

+ (id)issueManagerLogAspect;
+ (id)_issueProviderInfo;
+ (void)_useDebugProviderExtensionPointWithIdentifier:(id)arg1;
+ (void)initialize;
// - (void).cxx_destruct;
@property(readonly) IDEIssueLogRecordsGroup *issueLogRecordsGroup; // @synthesize issueLogRecordsGroup=_issueLogRecordsGroup;
@property(readonly, getter=areLiveIssuesEnabled) BOOL liveIssuesEnabled; // @synthesize liveIssuesEnabled=_liveIssuesEnabled;
@property unsigned long long numberOfRuntimeIssues; // @synthesize numberOfRuntimeIssues=_numberOfRuntimeIssues;
@property unsigned long long numberOfBuildtimeIssues; // @synthesize numberOfBuildtimeIssues=_numberOfBuildtimeIssues;
@property(readonly) IDEWorkspace *workspace; // @synthesize workspace=_workspace;
- (void)removeIssueFromIssuesWithNoDocument:(id)arg1;
- (void)addIssueToIssuesWithNoDocument:(id)arg1;
- (id)_coalescingBucketIDForIssueWithNoDocument:(id)arg1;
- (void)_containersOrBlueprintsUpdated;
- (id)_issuesForProviderContext:(id)arg1;
- (id)_providerContextToProvisionInfoMapForIssues:(id)arg1;
- (id)_unitTestIssueProvidersAccessor;
- (void)_validateGroupIdentifiers;
- (void)_updateVendedIssues;
- (void)_updateContainersAndBlueprintsForActiveScheme;
- (void)_findDependencyForBuildable:(id)arg1;
- (void)_updateIssueFilterStyle;
- (void)_needsUpdateInResponseToFilterChanges;
- (void)_coalescedUpdateInResponseToFilterChanges;
- (void)_hideIssues:(id)arg1;
- (void)_setIssues:(id)arg1 forProviderContext:(id)arg2 container:(id)arg3 blueprint:(id)arg4 runtimeGroupingObject:(id)arg5 session:(id)arg6;
- (void)_removeIssues:(id)arg1 forProviderContext:(id)arg2 session:(id)arg3;
- (void)_recordIssue:(id)arg1;
- (void)_addIssues:(id)arg1 forProviderContext:(id)arg2 container:(id)arg3 blueprint:(id)arg4 runtimeGroupingObject:(id)arg5 session:(id)arg6 tryToCoalesce:(BOOL)arg7;
- (BOOL)isIssueInRemotePackage:(id)arg1;
- (BOOL)_vendOnlyActiveSchemeIssues;
- (void)_retractIssues:(id)arg1;
- (void)_vendIssues:(id)arg1 container:(id)arg2 blueprint:(id)arg3 runtimeGroupingObject:(id)arg4 issueToGroupingObjectMap:(id)arg5 session:(id)arg6;
- (void)_issueKVOForIssueCountsIfNecessary;
- (id)similarExistingIssueForIssue:(id)arg1;
- (id)_similarExistingIssueForIssue:(id)arg1 container:(id)arg2 blueprint:(id)arg3;
- (id)__similarExistingIssueWithNoDocument:(id)arg1 container:(id)arg2 blueprint:(id)arg3;
- (id)__similarExistingIssueWithDocument:(id)arg1 container:(id)arg2 blueprint:(id)arg3;
- (id)__firstSimilarExistingIssueFromIssuesToMatch:(id)arg1 coalesceingWithIssue:(id)arg2 container:(id)arg3 blueprint:(id)arg4;
- (_Bool)_doesIssue:(id)arg1 fromContainer:(id)arg2 andBlueprint:(id)arg3 coalesceWithIssue:(id)arg4;
- (_Bool)_doesIssue:(id)arg1 coalesceWithIssue:(id)arg2;
- (id)_groupingObjectsForIssue:(id)arg1;
- (void)_rescindObserverToken:(id)arg1;
- (id)newIssueObserverForDocumentURL:(id)arg1 options:(unsigned long long)arg2 withHandlerBlock:(CDUnknownBlockType)arg3;
- (void)_notifyAllObserversOfDocumentURL:(id)arg1 isPrior:(BOOL)arg2;
- (void)_notifyObserver:(id)arg1 forURL:(id)arg2 isPrior:(BOOL)arg3;
- (id)issuesWithNoDocument;
- (id)issuesIncludingOnesWithSecondaryLocationInDocumentURL:(id)arg1;
- (id)issuesForDocumentURL:(id)arg1;
- (id)buildtimeIssuesWithNoDocument;
- (id)buildtimeIssuesForDocumentURL:(id)arg1;
- (id)_buildtimeIssuesFromIssues:(id)arg1;
- (unsigned long long)maxSeverityOfDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfFixableDiagnosticItemsInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfAnalyzerResultsInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfNoticesInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfOptimizationOpportunitiesInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfRuntimeIssuesInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfBuildtimeIssuesInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfRemarksInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfWarningsInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfErrorsInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfTestFailuresInDocumentAtURL:(id)arg1;
- (unsigned long long)numberOfTotalIssuesInDocumentAtURL:(id)arg1;
- (id)_documentIssueSummaryForURL:(id)arg1;
- (unsigned long long)maxSeverity;
- (unsigned long long)numberOfFixableDiagnosticItems;
- (unsigned long long)numberOfAnalyzerResults;
- (unsigned long long)numberOfRemarks;
- (unsigned long long)numberOfNotices;
- (unsigned long long)numberOfOptimizationOpportunities;
- (unsigned long long)aggregatedRuntimeIssueCount;
- (unsigned long long)aggregatedBuildtimeIssueCount;
- (unsigned long long)numberOfWarnings;
- (unsigned long long)numberOfErrors;
- (unsigned long long)numberOfTestFailures;
- (unsigned long long)numberOfTotalIssues;
- (id)_issueCounterForURL:(id)arg1;
@property(readonly) NSArray *documentURLsWithIssues;
- (void)removeIndexesForIssue:(id)arg1;
- (BOOL)disassociateIssue:(id)arg1 withGroup:(id)arg2;
- (void)associateIssue:(id)arg1 withGroup:(id)arg2;
@property(readonly) NSArray *issueGroups;
- (void)_updateIssueProviders;
- (void)primitiveInvalidate;
- (id)initWithWorkspace:(id)arg1;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) NSSet *lastSchemeActionIssues; // @dynamic lastSchemeActionIssues;
@property(readonly) NSMutableSet *mutableLastSchemeActionIssues; // @dynamic mutableLastSchemeActionIssues;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

