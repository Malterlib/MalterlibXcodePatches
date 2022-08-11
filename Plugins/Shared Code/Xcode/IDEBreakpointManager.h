//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTInvalidation-Protocol.h"
#import "IDEBreakpointDelegate-Protocol.h"

@class DVTDispatchLock, DVTObservingToken, DVTStackBacktrace, DVTTimeSlicedMainThreadWorkQueue, IDEBreakpointBucket, IDEWorkspace, NSArray, NSMapTable, NSMutableArray, NSMutableSet, NSString;

@interface IDEBreakpointManager : NSObject <IDEBreakpointDelegate, DVTInvalidation>
{
    DVTObservingToken *_workspaceReferencedContainersToken;
    DVTObservingToken *_currentDebugSessionObserverToken;
    DVTObservingToken *_currentDebugSessionStateObserverToken;
    NSMapTable *_bucketsToObserverTokens;
    NSMutableArray *_userProjectBuckets;
    IDEBreakpointBucket *_watchpointBucket;
    NSMutableArray *_sharedProjectBuckets;
    NSMapTable *_userToSharedBuckets;
    NSMapTable *_sharedToUserBuckets;
    NSMutableArray *_allBucketsWithBreakpoints;
    NSMutableArray *_breakpoints;
    DVTTimeSlicedMainThreadWorkQueue *_breakpointIdentifierChangedQueue;
    DVTDispatchLock *_registrationLock;
    unsigned long long _registrationNumber;
    NSMutableArray *_breakpointsToBeInvalidated;
    NSMutableSet *_breakpointObservers;
    BOOL _breakpointsActivated;
    IDEBreakpointBucket *_defaultBucket;
    IDEBreakpointBucket *_userWorkspaceBucket;
    IDEBreakpointBucket *_userGlobalBucket;
    IDEBreakpointBucket *_sharedWorkspaceBucket;
    IDEWorkspace *_workspace;
}

+ (void)initialize;
// - (void).cxx_destruct;
@property(readonly) IDEWorkspace *workspace; // @synthesize workspace=_workspace;
@property(nonatomic) BOOL breakpointsActivated; // @synthesize breakpointsActivated=_breakpointsActivated;
@property(readonly) NSArray *allBucketsWithBreakpoints; // @synthesize allBucketsWithBreakpoints=_allBucketsWithBreakpoints;
@property(readonly) IDEBreakpointBucket *sharedWorkspaceBucket; // @synthesize sharedWorkspaceBucket=_sharedWorkspaceBucket;
@property(readonly) IDEBreakpointBucket *userGlobalBucket; // @synthesize userGlobalBucket=_userGlobalBucket;
@property(readonly) IDEBreakpointBucket *userWorkspaceBucket; // @synthesize userWorkspaceBucket=_userWorkspaceBucket;
@property(retain, nonatomic) IDEBreakpointBucket *defaultBucket; // @synthesize defaultBucket=_defaultBucket;
- (void)primitiveInvalidate;
- (void)breakpointLocationsAdded:(id)arg1 removed:(id)arg2;
- (BOOL)breakpointShouldBeActivated:(id)arg1;
- (void)breakpointTextFilterablePropertyChanged:(id)arg1;
- (void)breakpointNameChanged:(id)arg1;
- (void)breakpointModificationChanged:(id)arg1;
- (void)breakpointResolutionChanged:(id)arg1;
- (void)breakpointEnablementChanged:(id)arg1;
- (void)_notifyObserversOfActivationStateChange;
- (void)removeBreakpointObserver:(id)arg1;
- (void)addBreakpointObserver:(id)arg1;
- (id)createSanitizerBreakpointIfNecessary:(unsigned long long)arg1 categories:(id)arg2 ignoreExisting:(BOOL)arg3;
- (void)_handleBreakpointsForBucket:(id)arg1 change:(id)arg2;
- (void)_addListenerToBucketsBreakpointList:(id)arg1;
- (void)_removeListenerFromBucketsBreakpointList:(id)arg1;
- (BOOL)_canSetBreakpointAtURL:(id)arg1;
- (BOOL)_anyFileReferenceForPath:(id)arg1 matchesDataTypeIdentifier:(id)arg2;
- (void)setBreakpointShared:(id)arg1 shared:(BOOL)arg2;
- (BOOL)_isBreakpointAtLocation:(id)arg1 location:(id)arg2 columnOnly:(BOOL)arg3;
- (id)columnBreakpointsAtDocumentLocation:(id)arg1;
- (id)lineBreakpointAtDocumentLocation:(id)arg1;
- (id)fileBreakpointAtDocumentLocation:(id)arg1;
- (void)registerDoingWorkOnBreakpoint:(id)arg1 block:(CDUnknownBlockType)arg2;
- (void)removeWatchpoint:(id)arg1;
- (void)removeBreakpoints:(id)arg1;
- (void)removeBreakpoint:(id)arg1;
- (BOOL)_managesBucket:(id)arg1;
- (void)_addBreakpoint:(id)arg1 toBucket:(id)arg2;
- (void)addWatchpoint:(id)arg1;
- (void)addBreakpoint:(id)arg1;
- (id)createWatchpoint:(id)arg1 variableName:(id)arg2;
- (id)_createAddressBreakpointFrom:(id)arg1 usingLineOfDisassembly:(id)arg2;
- (id)createAddressBreakpoint:(id)arg1;
- (id)createFileBreakpointAtDocumentLocation:(id)arg1;
- (id)createBreakpointAtDocumentLocation:(id)arg1 usingStringAtLine:(id)arg2;
- (void)_handleWorkspaceContainerRemoved:(id)arg1;
- (void)_handleWorkspaceContainerInserted:(id)arg1;
- (void)_handleWorkspaceContainersChanges:(id)arg1;
- (void)_handleCurrentDebugSessionStateChanged:(id)arg1;
- (id)initWithWorkspace:(id)arg1 error:(id *)arg2;

// Remaining properties
@property(copy) NSArray *breakpoints; // @dynamic breakpoints;
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) NSMutableArray *mutableBreakpoints; // @dynamic mutableBreakpoints;
@property(readonly) NSMutableArray *mutableSharedProjectBuckets; // @dynamic mutableSharedProjectBuckets;
@property(readonly) NSMutableArray *mutableUserProjectBuckets; // @dynamic mutableUserProjectBuckets;
@property(retain) NSArray *sharedProjectBuckets; // @dynamic sharedProjectBuckets;
@property(readonly) Class superclass;
@property(retain) NSArray *userProjectBuckets; // @dynamic userProjectBuckets;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

