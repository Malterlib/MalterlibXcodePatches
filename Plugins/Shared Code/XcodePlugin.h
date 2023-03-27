#pragma once

#import <Foundation/Foundation.h>
#include <os/lock.h>
#import "Xcode/DVTPlugIn.h"


#ifdef _DEBUG
#define XcodePluginLog(...) NSLog(__VA_ARGS__)
#else
#define XcodePluginLog(...) ((void)0)
#endif

#define XcodePluginPreflight(_LoadInXcodeBuild)                         \
    if (!XcodePluginShouldLoad(_LoadInXcodeBuild))                      \
        return;                                    \
                                                   \
    static NSUInteger loadAttempt = 0;             \
    loadAttempt++;                                 \
    XcodePluginLog(@"%@ initialization attempt %ju/%ju...", \
      NSStringFromClass([self class]),         \
      (uintmax_t)loadAttempt,                  \
      (uintmax_t)XcodePluginMaxLoadAttempts);

#define XcodePluginPostflight()                                                                                 \
    XcodePluginLog(@"%@ initialization successful!", NSStringFromClass([self class]));                               \
    return;                                                                                                 \
    failed:                                                                                                 \
    {                                                                                                       \
        XcodePluginLog(@"%@ initialization failed.", NSStringFromClass([self class]));                               \
                                                                                                            \
        if (loadAttempt < XcodePluginMaxLoadAttempts)                                                           \
        {                                                                                                   \
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 10.0 * NSEC_PER_SEC), dispatch_get_main_queue(), \
                ^(void)                                                                                     \
                {                                                                                           \
                    [self onLoad];                                                           \
                });                                                                                         \
        }                                                                                                   \
                                                                                                            \
        else XcodePluginLog(@"%@ failing permanently. :(", NSStringFromClass([self class]));                         \
    }

#define XcodePluginAssertMessageFormat @"Assertion failed (file: %s, function: %s, line: %u): %s\n"
#define XcodePluginNoOp (void)0

#define XcodePluginAssertOrPerform(condition, action)                                                      \
({                                                                                                     \
    bool __evaluated_condition = false;                                                                \
                                                                                                       \
    __evaluated_condition = (condition);                                                               \
                                                                                                       \
    if (!__evaluated_condition)                                                                        \
    {                                                                                                  \
        XcodePluginLog(XcodePluginAssertMessageFormat, __FILE__, __PRETTY_FUNCTION__, __LINE__, (#condition));      \
        action;                                                                                        \
    }                                                                                                  \
})

#define XcodePluginAssertOrRaise(condition) XcodePluginAssertOrPerform((condition), [NSException raise: NSGenericException format: @"An XcodePlugin exception occurred"])

#define XcodePluginConfirmOrPerform(condition, action)      \
({                                                      \
    if (!(condition))                                   \
    {                                                   \
        action;                                         \
    }                                                   \
})

@class NSView;

void XcodePluginTraceViewHierarchy(NSView *_pView, int _Depth);
void XcodePluginDumpClass(Class theClass);
BOOL XcodePluginShouldLoad(BOOL _LoadInXcodeBuild);
extern const NSUInteger XcodePluginMaxLoadAttempts;

/* This function overrides a method at the given class level, and returns the old implementation. If no method existed at
   the given class' level, a new method is created at that level, and the superclass' (or super-superclass', and so on)
   implementation is returned.
   
   This function returns nil on failure. */
IMP XcodePluginOverrideMethod(Class class0, SEL selector, IMP newImplementation);
#define XcodePluginOverrideMethodString(className, selector, newImplementation) XcodePluginOverrideMethod(NSClassFromString(className), selector, newImplementation)

IMP XcodePluginOverrideStaticMethod(Class class0, SEL selector, IMP newImplementation);
#define XcodePluginOverrideStaticMethodString(className, selector, newImplementation) XcodePluginOverrideStaticMethod(NSClassFromString(className), selector, newImplementation)

NSString *fg_ExtractInType(NSString *_inType);
BOOL fg_IsBuiltinType(NSString *_inType);
NSString *fg_FixVariableName(NSString *_inType);
NSArray<NSString *> *fg_SplitString(NSString *_pString, NSString *_pSeparator);

