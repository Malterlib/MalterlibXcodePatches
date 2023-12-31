//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDESchemeActionResult_h
#define IDESchemeActionResult_h
#import <Foundation/Foundation.h>

#include "IDEActivityLogSection.h"
#include "IDEConsoleLog.h"
#include "_TtC13IDEFoundation18IDEResultReference.h"

@class DVTFilePath, DVTObservingToken, IDESchemeActionCodeCoverage, NSArray, NSDictionary, NSError, NSHashTable, NSMutableArray, NSString, _TtC13DVTFoundation14DVTFilePromise;

@interface IDESchemeActionResult : NSObject {
  /* instance variables */
  DVTObservingToken *_logRecordingToken;
  BOOL _includeAllMessages;
  DVTFilePath *_filePathOfDiagnosticsToCopyIntoLocalResultDirectory;
}

@property (copy, nonatomic) NSString *resultName;
@property (copy, nonatomic) NSString *testSummaryPath;
@property BOOL hasReadIssueSummaries;
@property (copy, nonatomic) NSString *logPath;
@property (nonatomic) long long status;
@property (copy, nonatomic) NSError *error;
@property (retain, nonatomic) IDEActivityLogSection *log;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *logReference;
@property (nonatomic) BOOL localLogFileIsCurrent;
@property (nonatomic) unsigned long long warningCount;
@property (nonatomic) unsigned long long errorCount;
@property (nonatomic) unsigned long long analyzerWarningCount;
@property (nonatomic) unsigned long long testsCount;
@property (nonatomic) unsigned long long testsFailedCount;
@property (nonatomic) unsigned long long testsSkippedCount;
@property (retain, nonatomic) NSMutableArray *warningSummaries;
@property (retain, nonatomic) NSMutableArray *errorSummaries;
@property (retain, nonatomic) NSMutableArray *analyzerWarningSummaries;
@property (retain, nonatomic) NSMutableArray *testRunSummaries;
@property (retain, nonatomic) NSMutableArray *testFailureSummaries;
@property (copy, nonatomic) id remoteTestSummaryIdentifier;
@property (nonatomic) BOOL remoteTestSummaryNeedsFetch;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *testsReference;
@property (retain, nonatomic) IDESchemeActionCodeCoverage *coverageReport;
@property (retain, nonatomic) DVTFoundation_DVTFilePromise *coverageReportFilePromise;
@property (retain, nonatomic) DVTFoundation_DVTFilePromise *coverageArchiveFilePromise;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *coverageReportReference;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *coverageArchiveReference;
@property (retain, nonatomic) DVTFoundation_DVTFilePromise *diagnosticsFilePromise;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *diagnosticsReference;
@property (retain, nonatomic) IDEFoundation_IDEResultReference *consoleLogReference;
@property (retain, nonatomic) DVTFilePath *testSessionTemporaryDirectoryPath;
@property (retain, nonatomic) id _resultBundleWriter;
@property (retain, nonatomic) id _testSummariesStream;
@property (retain, nonatomic) id _resultStream;
@property (retain, nonatomic) id _issueStream;
@property (retain, nonatomic) id _issueProcessor;
@property (retain, nonatomic) id _logStream;
@property (readonly, nonatomic) long long actionIndex;
@property (readonly, nonatomic) long long resultIndex;
@property (retain, nonatomic) DVTFilePath *localResultDirectoryFilePath;
@property (retain, nonatomic) DVTFilePath *creatingWorkspaceFilePath;
@property (retain, nonatomic) NSHashTable *blueprintsForShowingIssues;
@property (readonly, copy) NSDictionary *dictionaryRepresentation;
@property (retain, nonatomic) IDEConsoleLog *consoleLog;
@property (readonly, nonatomic) BOOL isRecording;
@property (readonly, nonatomic) DVTFilePath *localLogFilePath;
@property (readonly, nonatomic) DVTFilePath *attachmentsFilePath;
@property (copy, nonatomic) id remoteLogIdentifier;
@property (nonatomic) BOOL remoteLogNeedsFetch;
@property (readonly, nonatomic) NSArray *testWarningSummaries;
@property (nonatomic) BOOL hasTests;
@property (readonly, nonatomic) DVTFilePath *localTestSummaryFilePath;
@property (readonly, nonatomic) DVTFilePath *localDiagnosticsFilePath;
@property (nonatomic) BOOL hasCoverageData;
@property (readonly, nonatomic) DVTFilePath *coverageReportFilePathForWriting;
@property (readonly, nonatomic) DVTFilePath *coverageArchiveFilePathForWriting;
@property (readonly, nonatomic) BOOL hasConsoleLog;

/* class methods */
+ (void)initialize;
+ (id)keyPathsForValuesAffectingIsRecording;
+ (void)saveSchemeActionResult:(id)result forSchemeActionRecord:(id)record container:(id)container completionBlock:(id /* block */)block;
+ (BOOL)automaticallyNotifiesObserversOfLog;
+ (id)stringForActionResultStatus:(long long)status;
+ (long long)actionResultStatusForString:(id)string;

/* instance methods */
- (void)didSetLog;
- (id)initWithResultName:(id)name localResultDirectoryFilePath:(id)path creatingWorkspaceFilePath:(id)path;
- (id)initWithResultName:(id)name status:(long long)status localResultDirectoryFilePath:(id)path creatingWorkspaceFilePath:(id)path;
- (id)initWithResultName:(id)name localResultDirectoryFilePath:(id)path creatingWorkspaceFilePath:(id)path resultBundleWriter:(id)writer testSummariesStream:(id)stream resultStream:(id)stream;
- (id)initWithResultName:(id)name status:(long long)status localResultDirectoryFilePath:(id)path creatingWorkspaceFilePath:(id)path warningCount:(unsigned long long)count errorCount:(unsigned long long)count analyzerWarningCount:(unsigned long long)count testsCount:(unsigned long long)count testsFailedCount:(unsigned long long)count testsSkippedCount:(unsigned long long)count warningSummaries:(id)summaries errorSummaries:(id)summaries analyzerWarningSummaries:(id)summaries testFailureSummaries:(id)summaries testWarningSummaries:(id)summaries testRunSummaries:(id)summaries hasCodeCoverage:(BOOL)coverage coverageReportFilePromise:(id)promise coverageArchiveFilePromise:(id)promise testsReference:(id)reference logReference:(id)reference diagnosticsFilePromise:(id)promise consoleLogReference:(id)reference;
- (id)initWithResultName:(id)name status:(long long)status localResultDirectoryFilePath:(id)path creatingWorkspaceFilePath:(id)path warningCount:(unsigned long long)count errorCount:(unsigned long long)count analyzerWarningCount:(unsigned long long)count testsCount:(unsigned long long)count testsFailedCount:(unsigned long long)count testsSkippedCount:(unsigned long long)count warningSummaries:(id)summaries errorSummaries:(id)summaries analyzerWarningSummaries:(id)summaries testFailureSummaries:(id)summaries testRunSummaries:(id)summaries hasCodeCoverage:(BOOL)coverage coverageReportFilePromise:(id)promise coverageArchiveFilePromise:(id)promise testsReference:(id)reference logReference:(id)reference diagnosticsFilePromise:(id)promise consoleLogReference:(id)reference;
- (id)sparseActionResultAtFilePath:(id)path testIdentifiersByBundleName:(id)name resultBundle:(id)bundle error:(id *)error;
- (id)init;
- (void)dealloc;
- (void)_saveForSchemeActionRecord:(id)record container:(id)container completionBlock:(id /* block */)block;
- (BOOL)_saveAdditionsForSchemeActionRecord:(id)record container:(id)container error:(id *)error;
- (id)description;
- (void)updateWithActionIndex:(long long)index resultIndex:(long long)index;
- (void)saveInMemorySealedLogToContainer:(id)container completionBlock:(id /* block */)block;
- (void)waitUntilBuildLogHasBeenClosed:(id)closed completionBlock:(id /* block */)block;
- (void)_waitUntilBuildLogHasBeenClosed:(id)closed deadlineForWaiting:(double)waiting completionBlock:(id /* block */)block;
- (void)filterWarningsToBuildables:(id)buildables;
- (id)_issueSummaryForMessage:(id)message producingTargetName:(id)name;
- (void)_readIssueSummaries;
- (BOOL)hasLog;
- (BOOL)loadLogIfNeededFromContainer:(id)container withError:(id *)error;
- (BOOL)loadTestSummariesIfNeededFromContainer:(id)container withError:(id *)error;
- (BOOL)loadCoverageReportIfNeededWithError:(id *)error;
- (BOOL)saveDiagnosticsToContainer:(id)container withError:(id *)error;
- (BOOL)saveAttachmentPayloadsToContainer:(id)container withError:(id *)error;
- (BOOL)saveCodeCoverageToContainer:(id)container withError:(id *)error;
- (BOOL)saveConsoleLogToContainer:(id)container returningError:(id *)error;
- (BOOL)loadConsoleLogIfNeededFromContainer:(id)container withError:(id *)error;
@end

#endif /* IDESchemeActionResult_h */
