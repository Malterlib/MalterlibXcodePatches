//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEAnalyzeSchemeAction_h
#define IDEAnalyzeSchemeAction_h
#import <Foundation/Foundation.h>

#include "IDESchemeAction.h"
#include "DVTXMLUnarchiving-Protocol.h"

@class NSString;

@interface IDEAnalyzeSchemeAction : IDESchemeAction<DVTXMLUnarchiving>

@property (readonly) unsigned long long hash;
@property (readonly) Class superclass;
@property (readonly, copy) NSString *description;
@property (readonly, copy) NSString *debugDescription;

/* class methods */
+ (BOOL)shouldAllowCustomPhaseActions;
+ (id)keyPathsForValuesAffectingSubtitle;
+ (void)insertsynthesizedMacrosIntoOverridingProperties:(id)properties;

/* instance methods */
- (id)init;
- (id)initFromXMLUnarchiver:(id)xmlunarchiver archiveVersion:(float)version;
- (void)_commonInit;
- (id)prePhaseExecutionActions;
- (id)mutablePrePhaseExecutionActions;
- (id)postPhaseExecutionActions;
- (id)mutablePostPhaseExecutionActions;
- (id)name;
- (id)subtitle;
- (BOOL)doesNonActionWork;
- (void)dvt_awakeFromXMLUnarchiver:(id)xmlunarchiver;
- (void)dvt_encodeAttributesWithXMLArchiver:(id)xmlarchiver version:(id)version;
@end

#endif /* IDEAnalyzeSchemeAction_h */