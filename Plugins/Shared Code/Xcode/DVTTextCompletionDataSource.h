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

@class DVTSourceCodeLanguage, DVTStackBacktrace, DVTTextCompletionStrategy, NSArray, NSMutableArray, NSMutableSet, NSOperationQueue, NSString;
@protocol DVTTextCompletionDataSourceDelegate;

@interface DVTTextCompletionDataSource : NSObject <DVTInvalidation>
{
    NSMutableArray *_strategies;
    NSMutableSet *_strategyObservers;
    NSOperationQueue *_completionsGeneratorQueue;
    DVTSourceCodeLanguage *_language;
    id <DVTTextCompletionDataSourceDelegate> _delegate;
    DVTTextCompletionStrategy *_lastDefinitiveStrategy;
    NSObject *_lastCompletionsBackingStore;
}

+ (void)initialize;
// - (void).cxx_destruct;
@property(readonly) NSObject *lastCompletionsBackingStore; // @synthesize lastCompletionsBackingStore=_lastCompletionsBackingStore;
@property(readonly) __weak DVTTextCompletionStrategy *lastDefinitiveStrategy; // @synthesize lastDefinitiveStrategy=_lastDefinitiveStrategy;
@property __weak id <DVTTextCompletionDataSourceDelegate> delegate; // @synthesize delegate=_delegate;
@property(retain, nonatomic) DVTSourceCodeLanguage *language; // @synthesize language=_language;
@property(copy) NSArray *strategies;
- (void)cancelInProgressCompletions;
- (void)completionResultsForDocumentLocation:(id)arg1 filterText:(id)arg2 context:(id)arg3 priorityCoefficients:(id)arg4 completionBlock:(CDUnknownBlockType)arg5;
- (void)generateCompletionsForDocumentLocation:(id)arg1 context:(id)arg2 completionBlock:(CDUnknownBlockType)arg3;
- (void)primitiveInvalidate;
- (id)initWithLanguage:(id)arg1;
- (id)init;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

