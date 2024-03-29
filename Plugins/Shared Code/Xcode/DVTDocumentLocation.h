//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

#include "Shared.h"

#import "DVTSimpleSerialization-Protocol.h"
#import "DVTStringRepresentationPersistable-Protocol.h"

@class NSNumber, NSString, NSURL;

@interface DVTDocumentLocation : NSObject <NSSecureCoding, NSCopying, DVTStringRepresentationPersistable, DVTSimpleSerialization>
{
    NSURL *_documentURL;
    NSNumber *_timestamp;
}

+ (id)deserializedDocumentLocationForClassName:(id)arg1 stringRepresentation:(id)arg2 error:(id *)arg3;
+ (BOOL)supportsSecureCoding;
+ (id)dvt_documentLocationFromPersistableStringRepresentation:(id)arg1 error:(id *)arg2;
+ (id)documentLocationWithURLScheme:(id)arg1 path:(id)arg2 documentParameters:(id)arg3 locationParameters:(id)arg4;
// - (void).cxx_destruct;
@property(readonly) NSNumber *timestamp; // @synthesize timestamp=_timestamp;
@property(readonly) NSURL *documentURL; // @synthesize documentURL=_documentURL;
@property(readonly, nonatomic) NSString *pasteboardRepresentation;
- (id)locationParameters;
- (id)documentParameters;
- (id)documentPath;
- (id)documentScheme;
- (void)dvt_writeToSerializer:(id)arg1;
- (id)dvt_initFromDeserializer:(id)arg1;
- (void)encodeWithCoder:(id)arg1;
- (id)initWithCoder:(id)arg1;
- (id)dvt_persistableStringRepresentation;
- (id)dvt_initFromPersistableStringRepresentation:(id)arg1 error:(out id *)arg2;
- (long long)compare:(id)arg1;
@property(readonly, copy) NSString *description;
- (BOOL)isEqualDisregardingTimestamp:(id)arg1;
- (BOOL)isEqual:(id)arg1;
- (id)copyWithURL:(id)arg1;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (id)documentURLString;
- (id)initWithDocumentURL:(id)arg1 timestamp:(id)arg2;
- (id)init;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly) Class superclass;

@end

