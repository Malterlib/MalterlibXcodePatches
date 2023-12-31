//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef IDEBlueprintProvider_Protocol_h
#define IDEBlueprintProvider_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDETestableProvider, IDEIssueLogDataSource;
@class IDEWorkspace;

@protocol IDEBlueprintProvider <DVTInvalidation, NSObject, IDEIssueLogDataSource>

@property (readonly, copy) NSArray *blueprints;
@property (readonly, copy) NSString *name;
@property (readonly, copy) NSString *organizationName;
@property (readonly, copy) NSString *classPrefix;
@property (readonly) NSObject<IDETestableProvider> *testableProvider;
@property (readonly) DVTFilePath *filePath;
@property (readonly) IDEWorkspace *workspace;
@property (readonly) NSString *uniqueIdentifier;
@property int buildSystemType;
@property (readonly) NSArray *sourcePackageReferences;
@property (readonly) BOOL supportsSourceFolders;

/* class methods */
+ (id)availableSwiftVersions;
/* instance methods */
- (id)blueprintForIdentifier:(id)identifier;
- (id)blueprintForName:(id)name;
@optional
/* instance methods */
- (void)addSourcePackageReference:(id)reference;
@end

#endif /* IDEBlueprintProvider_Protocol_h */
