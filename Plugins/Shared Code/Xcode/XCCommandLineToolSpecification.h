//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22526.0.0.0.0
//
#ifndef XCCommandLineToolSpecification_h
#define XCCommandLineToolSpecification_h
#import <Foundation/Foundation.h>

#include "XCPropertyDomainSpecification.h"
#include "XCFnmatchPatternSet.h"

@class DVTMacroDefinitionTable, NSArray, NSDictionary, NSIndexSet, NSMutableDictionary;
@protocol DVTMacroExpansion, DVTMacroExpansion;

@interface XCCommandLineToolSpecification : XCPropertyDomainSpecification {
  /* instance variables */
  NSString<DVTMacroExpansion> *_commandIdentTemplate;
  NSArray<DVTMacroExpansion> *_commandLineTemplate;
  NSString<DVTMacroExpansion> *_execPath;
  NSArray<DVTMacroExpansion> *_ruleLineTemplate;
  Class _commandInvocationClass;
  NSMutableDictionary *_messageCategoryInfoDicts;
  NSMutableDictionary *_severityBasedMessageCategoryInfoDicts;
  NSArray *_outputParserClassesOrRules;
  Class _resultsPostprocessorClass;
  NSArray *_fallbackToolIdentifiers;
  NSMutableDictionary *_fallbackToolSpecifications;
  NSArray *_inputFileTypes;
  NSArray<DVTMacroExpansion> *_additionalInputFiles;
  BOOL _shouldDeeplyStatInputDirectories;
  NSString<DVTMacroExpansion> *_generatedInfoPlistContentFilePath;
  NSArray<DVTMacroExpansion> *_additionalPathsToClean;
  XCFnmatchPatternSet *_flagsNotAffectingOutputFile;
  BOOL _supportsDeploymentTarget;
  NSMutableDictionary *_defaultDeploymentTargetsByName;
  NSString<DVTMacroExpansion> *_outputDir;
  NSString<DVTMacroExpansion> *_outputPath;
  NSArray<DVTMacroExpansion> *_outputPaths;
  BOOL _outputsAreProducts;
  BOOL _dontProcessOutputs;
  BOOL _mightNotEmitAllOutputs;
  NSArray *_additionalDirectoriesToCreate;
  NSDictionary *_environmentVariables;
  BOOL _wantsBuildSettingsInEnvironment;
  DVTMacroDefinitionTable *_overridingMacros;
  NSArray *_requiredComponents;
  BOOL _shouldSynthesizeGlobalBuildRule;
  NSArray *_buildPhasesForWhichToSynthesizeBuildRules;
  NSArray *_inputFileGroupings;
  BOOL _serializeCommands;
  NSString<DVTMacroExpansion> *_executionDescription;
  NSString<DVTMacroExpansion> *_progressDescription;
}

@property (readonly) NSArray *relatedToolSpecificationIdentifiers;
@property (readonly) unsigned long long messageLimit;
@property (readonly) NSIndexSet *successExitCodes;
@property (readonly, nonatomic) NSString<DVTMacroExpansion> *dependencyInfoFile;
@property (readonly, nonatomic) BOOL isUnsafeToInterrupt;

/* class methods */
+ (void)initialize;
+ (Class)specificationTypeBaseClass;
+ (id)specificationType;
+ (id)localizedSpecificationTypeName;
+ (id)specificationTypePathExtensions;
+ (id)specificationRegistryName;
+ (void)createDefaultCommandLineToolSpecificationRegistry;
+ (unsigned long long)defaultMessageLimit;
+ (id)unionedDefaultMacrosForAllToolsInDomain:(id)domain;

/* instance methods */
- (id)initWithPropertyListDictionary:(id)dictionary inDomain:(id)domain;
- (id)name;
- (id)path;
- (id)fallbackToolSpecificationsForDomain:(id)domain;
- (id)fallbackToolSpecificationsForSDK:(id)sdk;
- (id)commandIdentifierTemplate;
- (id)ruleLineTemplate;
- (id)inputFileTypes;
- (id)additionalInputFiles;
- (BOOL)shouldDeeplyStatInputDirectories;
- (id)generatedInfoPlistContentFilePath;
- (id)supportedArchitecturesInDomain:(id)domain withMacroExpansionScope:(id)scope;
- (id)versionWithMacroExpansionScope:(id)scope;
- (BOOL)acceptsInputFileType:(id)type;
- (BOOL)shouldProcessInputFilePath:(id)path ofFileType:(id)type withMacroExpansionScope:(id)scope errorString:(id *)string;
- (BOOL)supportsArchitecture:(id)architecture inDomain:(id)domain withMacroExpansionScope:(id)scope;
- (BOOL)supportsArchitecture:(id)architecture inDomain:(id)domain allArchitectures:(id)architectures withMacroExpansionScope:(id)scope;
- (id)outputDir;
- (id)outputPaths;
- (BOOL)outputsAreProducts;
- (BOOL)dontProcessOutputs;
- (BOOL)mightNotEmitAllOutputs;
- (BOOL)shouldRemoveOutputsOnFailure;
- (id)additionalDirectoriesToCreate;
- (id)environmentVariables;
- (id)executionDescription;
- (id)progressDescription;
- (void)_addToDefaultMacros:(id)macros;
- (void)_addPerToolOverridingMacrosToMacroDefinitionTable:(id)table;
- (id)overridingMacros;
- (Class)commandInvocationClass;
- (id)commandOutputParserClassesOrParseRules;
- (id)defaultDeploymentTargetNamed:(id)named;
- (void)setDefaultDeploymentTarget:(id)target forName:(id)name;
- (id)requiredComponents;
- (id)inputFileGroupings;
- (id)hashStringForCommandLineComponents:(id)components inputFilePaths:(id)paths withMacroExpansionScope:(id)scope;
- (id)commandLineForAutogeneratedOptionsWithMacroExpansionScope:(id)scope;
- (BOOL)areOutputFilesAffectedByCommandLineArgument:(id)argument previousArgument:(id)argument;
- (BOOL)areOutputFilesAffectedByEnvironmentVariable:(id)variable;
- (id)arrayByRemovingArgumentsNotAffectingOutputFileFromArray:(id)array;
- (id)extraSignatureInfoForCommand:(id)command;
- (BOOL)commandsNeedToRecomputeSignatureOnEveryBuild;
- (id)messageCategoryInfoForExecutablePath:(id)path;
- (id)severityBasedMessageCategoryInfoForExecutablePath:(id)path;
- (id)instantiatedCommandOutputParserForCommand:(id)command withLogSectionRecorder:(id)recorder;
- (BOOL)shouldProcessDependencyInfoFileWithMacroExpansionScope:(id)scope;
- (BOOL)parseDependencyInfoFileAtPath:(id)path usingBlock:(id /* block */)block errorPtr:(id *)ptr;
- (id /* block */)processDependencyInfoFileIfNecessaryForCommand:(id)command commandInvocationSucceeded:(BOOL)succeeded;
- (id)messageFormatForFailingCommandWithNoErrors;
- (BOOL)shouldSynthesizeGlobalBuildRule;
- (id)identifiersOfBuildPhasesForWhichToSynthesizeBuildRules;
- (void)_addNameToDefaultValueMappingsToMacroDefinitionTable:(id)table;
- (BOOL)shouldIncludeInUnionedToolDefaults;
- (BOOL)isAppleProvidedSpecification;
- (void)checkDeploymentTargetAgainstSDKWithMacroExpansionScope:(id)scope;
- (id)executablePathWithMacroExpansionScope:(id)scope;
- (id)outputPathFromInputNodes:(id)nodes withMacroExpansionScope:(id)scope;
- (id)doSpecialDependencySetupForCommand:(id)command withInputNodes:(id)nodes withMacroExpansionScope:(id)scope;
- (id)findExecutable:(id)executable withMacroExpansionScope:(id)scope;
- (id)discoveredToolInfoWithMacroExpansionScope:(id)scope;
- (id)createCommandsforInputs:(id)inputs withMacroExpansionScope:(id)scope;
- (unsigned long long)concurrentExecutionCountWithMacroExpansionScope:(id)scope;
- (id)instantiatedCommandResultsPostprocessorForCommand:(id)command;
@end

#endif /* XCCommandLineToolSpecification_h */
