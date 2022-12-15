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

@class DVTStackBacktrace, NSArray, NSMutableArray, NSString;
@protocol DVTAnnotationManagerDelegate;

@interface DVTAnnotationManager : NSObject <DVTInvalidation>
{
    id <DVTAnnotationManagerDelegate> _delegate;
    NSMutableArray *_annotationProviders;
}

+ (unsigned long long)assertionBehaviorForKeyValueObservationsAtEndOfEvent;
+ (unsigned long long)assertionBehaviorAfterEndOfEventForSelector:(SEL)arg1;
+ (void)initialize;
// - (void).cxx_destruct;
@property(retain) id <DVTAnnotationManagerDelegate> delegate; // @synthesize delegate=_delegate;
@property(readonly) NSArray *annotationProviders; // @synthesize annotationProviders=_annotationProviders;
- (void)_removeAllAnnotationProviders;
- (void)setupAnnotationProvidersWithContext:(id)arg1;
- (id)_installObservationBlockForAnnotationProvider:(id)arg1;
- (void)primitiveInvalidate;

// Remaining properties
@property(retain) DVTStackBacktrace *creationBacktrace;
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) DVTStackBacktrace *invalidationBacktrace;
@property(readonly) Class superclass;
@property(readonly, nonatomic, getter=isValid) BOOL valid;

@end

