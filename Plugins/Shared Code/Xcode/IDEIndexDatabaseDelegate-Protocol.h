//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//

@class IDEBoltIndexDatabase, IDEBoltIndexImportSession;

@protocol IDEIndexDatabaseDelegate

@optional
- (void)database:(IDEBoltIndexDatabase *)arg1 didEndImportSession:(IDEBoltIndexImportSession *)arg2;
- (void)databaseDidChangeMainFiles:(IDEBoltIndexDatabase *)arg1;
- (void)databaseDidIndexHotFile:(IDEBoltIndexDatabase *)arg1;
- (void)databaseDidInitializeFromDatastore:(IDEBoltIndexDatabase *)arg1;
- (void)databaseDidOpen:(IDEBoltIndexDatabase *)arg1;
@end

