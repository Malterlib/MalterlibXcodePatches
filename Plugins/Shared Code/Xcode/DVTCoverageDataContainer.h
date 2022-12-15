//
//     Generated by class-dump 3.5-0.1.1 (64 bit) (forked by @manicmaniac).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"


@class NSNumber, NSString;

@interface DVTCoverageDataContainer : NSObject <NSSecureCoding>
{
    NSNumber *_lineCoverage;
    NSString *_identifier;
    unsigned int _executableLines;
    unsigned int _coveredLines;
    NSString *_name;
}

+ (BOOL)supportsSecureCoding;
// - (void).cxx_destruct;
@property(readonly, nonatomic) NSString *name; // @synthesize name=_name;
@property(nonatomic) unsigned int coveredLines; // @synthesize coveredLines=_coveredLines;
@property(nonatomic) unsigned int executableLines; // @synthesize executableLines=_executableLines;
@property(readonly, nonatomic) NSNumber *lineCoverage;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)initWithName:(id)arg1;

@end

