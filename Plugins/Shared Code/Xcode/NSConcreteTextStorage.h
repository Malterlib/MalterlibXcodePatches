//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2014 by Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.10.sdk.sdk
//

@class NSConcreteNotifyingMutableAttributedString;

@interface NSConcreteTextStorage : NSTextStorage
{
    NSConcreteNotifyingMutableAttributedString *_contents;
    struct _opaque_pthread_rwlock_t _lock;
    struct {
        unsigned int _forceFixAttributes:1;
        unsigned int _needLock:1;
        unsigned int _lockInitialized:1;
        unsigned int _inFixingAttributes:1;
        unsigned int _reserved:28;
    } _pFlags;
}

+ (unsigned long long)_writerCountTSDKey;
- (void)addAttributes:(id)arg1 range:(struct _NSRange)arg2;
- (void)removeAttribute:(id)arg1 range:(struct _NSRange)arg2;
- (void)addAttribute:(id)arg1 value:(id)arg2 range:(struct _NSRange)arg3;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withAttributedString:(id)arg2;
- (void)setAttributes:(id)arg1 range:(struct _NSRange)arg2;
- (void)replaceCharactersInRange:(struct _NSRange)arg1 withString:(id)arg2;
- (id)attribute:(id)arg1 atIndex:(unsigned long long)arg2 longestEffectiveRange:(struct _NSRange *)arg3 inRange:(struct _NSRange)arg4;
- (id)attribute:(id)arg1 atIndex:(unsigned long long)arg2 effectiveRange:(struct _NSRange *)arg3;
- (id)attributesAtIndex:(unsigned long long)arg1 longestEffectiveRange:(struct _NSRange *)arg2 inRange:(struct _NSRange)arg3;
- (id)attributesAtIndex:(unsigned long long)arg1 effectiveRange:(struct _NSRange *)arg2;
- (void)_setAttributeFixingInProgress:(BOOL)arg1;
- (BOOL)_attributeFixingInProgress;
- (BOOL)_forceFixAttributes;
- (void)_setForceFixAttributes:(BOOL)arg1;
- (id)string;
- (unsigned long long)length;
- (BOOL)fixesAttributesLazily;
- (void)dealloc;
- (id)init;
- (id)initWithString:(id)arg1 attributes:(id)arg2;
- (id)initWithString:(id)arg1;
- (id)initWithAttributedString:(id)arg1;
- (void)_initLocks;
- (void)_unlock;
- (BOOL)_lockForWritingWithExceptionHandler:(BOOL)arg1;
- (BOOL)_lockForReading;
- (Class)classForCoder;

@end

