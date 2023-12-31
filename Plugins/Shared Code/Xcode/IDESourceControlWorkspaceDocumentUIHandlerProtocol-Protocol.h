//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22522.0.0.0.0
//
#ifndef IDESourceControlWorkspaceDocumentUIHandlerProtocol_Protocol_h
#define IDESourceControlWorkspaceDocumentUIHandlerProtocol_Protocol_h
#import <Foundation/Foundation.h>

@protocol IDESourceControlWorkspaceUIHandlerProtocol;

@protocol IDESourceControlWorkspaceDocumentUIHandlerProtocol <IDESourceControlWorkspaceUIHandlerProtocol, DVTInvalidation>

@property (copy) id /* block */ sourceControlCommandContinuationBlock;

/* instance methods */
- (void)initialWorkspaceScanIsFinished:(id)finished;
- (void)addWindowController:(id)controller;
- (void)setWorkspaceDocument:(id)document;
- (void)displayWaitingOnInitialWorkspaceScanAlertInWindow:(id)window withContinuationBlock:(id /* block */)block;
- (void)shouldCreateLocalRepository:(BOOL)repository atFilePath:(id)path;
@end

#endif /* IDESourceControlWorkspaceDocumentUIHandlerProtocol_Protocol_h */
