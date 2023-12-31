//
//   Generated by https://github.com/blacktop/ipsw (Version: 3.1.442, BuildTime: 2023-12-27T19:00:48Z)
//
//    - LC_BUILD_VERSION:  Platform: macOS, MinOS: 13.0, SDK: 14.0, Tool: ld (1022.1)
//    - LC_SOURCE_VERSION: 22551.0.0.0.0
//
#ifndef IDEConsoleItemLogData_h
#define IDEConsoleItemLogData_h
#import <Foundation/Foundation.h>

#include "DVTSimpleSerialization-Protocol.h"

@class NSString, NSTimeZone;

@interface IDEConsoleItemLogData : NSObject<DVTSimpleSerialization, NSSecureCoding>

@property (readonly) NSString *message;
@property (readonly) NSString *subsystem;
@property (readonly) NSString *category;
@property (readonly) NSString *library;
@property (readonly) NSString *format;
@property (readonly) NSString *backtrace;
@property (readonly) int pid;
@property (readonly) NSString *processName;
@property (readonly) NSString *sessionUUID;
@property (readonly) unsigned long long tid;
@property (readonly) unsigned char messageType;
@property (readonly) NSString *senderImagePath;
@property (readonly) NSString *senderImageUUID;
@property (readonly) unsigned long long senderImageOffset;
@property (readonly) NSString *localSenderImagePath;
@property (readonly) double unixTimeInterval;
@property (readonly) NSTimeZone *timeZone;
@property (retain) NSString *senderFunctionName;
@property (retain) NSString *senderSourcePath;
@property long long senderSourceLine;
@property long long senderSourceColumn;

/* class methods */
+ (id)localizeSenderImagePath:(id)path withLaunchParameters:(id)parameters andDeviceSupportPath:(id)path;
+ (unsigned char)logTypeFromString:(id)string;
+ (BOOL)supportsSecureCoding;

/* instance methods */
- (id)initWithMessage:(id)message subsystem:(id)subsystem category:(id)category library:(id)library format:(id)format backtrace:(id)backtrace pid:(int)pid processName:(id)name sessionUUID:(id)uuid tid:(unsigned long long)tid messageType:(unsigned char)type senderImagePath:(id)path senderImageUUID:(id)uuid senderImageOffset:(unsigned long long)offset unixTimeInterval:(double)interval timeZone:(id)zone;
- (id)initWithMessage:(id)message subsystem:(id)subsystem category:(id)category library:(id)library format:(id)format backtrace:(id)backtrace pid:(int)pid processName:(id)name sessionUUID:(id)uuid tid:(unsigned long long)tid messageType:(unsigned char)type senderImagePath:(id)path senderImageUUID:(id)uuid senderImageOffset:(unsigned long long)offset localSenderImagePath:(id)path unixTimeInterval:(double)interval timeZone:(id)zone;
- (id)initWithMessage:(id)message subsystem:(id)subsystem category:(id)category library:(id)library format:(id)format backtrace:(id)backtrace pid:(int)pid processName:(id)name sessionUUID:(id)uuid tid:(unsigned long long)tid messageType:(unsigned char)type senderImagePath:(id)path senderImageUUID:(id)uuid senderImageOffset:(unsigned long long)offset unixTimeInterval:(double)interval timeZone:(id)zone launchParameters:(id)parameters deviceSupportPath:(id)path;
- (id)initWithMessage:(id)message dictionary:(id)dictionary launchParameters:(id)parameters deviceSupportPath:(id)path;
- (id)dvt_initFromDeserializer:(id)deserializer;
- (void)dvt_writeToSerializer:(id)serializer;
- (id)initWithCoder:(id)coder;
- (void)encodeWithCoder:(id)coder;
@end

#endif /* IDEConsoleItemLogData_h */
