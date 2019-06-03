//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTCoverageDataContainer.h"

@class NSArray, NSNumber, NSString;

@interface IDESchemeActionCodeCoverageFile : DVTCoverageDataContainer
{
    NSNumber *_functionCoverage;
    NSString *_documentLocation;
    NSArray *_functions;
}

+ (BOOL)supportsSecureCoding;
@property(readonly, nonatomic) NSArray *functions; // @synthesize functions=_functions;
@property(readonly, nonatomic) NSString *documentLocation; // @synthesize documentLocation=_documentLocation;
// - (void).cxx_destruct;
- (id)wrappedContainer;
- (id)description;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
@property(readonly, nonatomic) NSNumber *functionCoverage;
- (id)initWithDocumentLocation:(id)arg1 functions:(id)arg2;
- (id)makeCopyWithChildren:(id)arg1;
- (id)diffableChildren;
- (id)diffIdentifier;
- (unsigned long long)diffType;

@end

