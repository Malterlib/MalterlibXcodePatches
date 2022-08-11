#import <Cocoa/Cocoa.h>
#include <Carbon/Carbon.h>
#import <objc/runtime.h>
#include "../Shared Code/XcodePlugin.h"
#include "../Shared Code/Xcode/IDEContainer.h"

#import "Plugin_Malterlib.h"

#define LLDBFixesEnable false

typedef NSEvent* __nullable (^CNavigationHandler)(NSEvent*);

#if LLDBFixesEnable
static IMP original_LLDBLauncherStart = nil;
#endif

static IMP original_compositeEnvironmentVariables = nil;
static IMP original_suspendFilePathChangeNotifications = nil;
static IMP original_resumeFilePathChangeNotifications = nil;
static IMP original_filePathDidChangeWithPendingChangeDictionary = nil;
static IMP original_saveContainerForAction = nil;
static IMP original_updateOperationConcurrency = nil;
static IMP original_changeMaximumOperationConcurrencyUsingThrottleFactor = nil;
static IMP original_canSaveContainer = nil;
static IMP original_SMSourceModel_parse = nil;

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@protocol Plugin_Malterlib
- (CNavigationHandler) registerNavigationHandler;
@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface IDEContainer (MalterlibIDEContainer)

@property (nonatomic, retain) NSNumber *generatedContainer;
@property (nonatomic, retain) NSNumber *lastBuilding;

@end

static void * MalterlibIDEContainerKey_generatedContainer = &MalterlibIDEContainerKey_generatedContainer;
static void * MalterlibIDEContainerKey_lastBuilding = &MalterlibIDEContainerKey_lastBuilding;

@implementation NSObject (MalterlibIDEContainer)

- (NSNumber *)generatedContainer {
    return objc_getAssociatedObject(self, MalterlibIDEContainerKey_generatedContainer);
}

- (void)setGeneratedContainer:(NSNumber *)generated {
    objc_setAssociatedObject(self, MalterlibIDEContainerKey_generatedContainer, generated, OBJC_ASSOCIATION_RETAIN_NONATOMIC); 
}

- (NSNumber *)lastBuilding {
	return objc_getAssociatedObject(self, MalterlibIDEContainerKey_lastBuilding);
}

- (void)setLastBuilding:(NSNumber *)generated {
	objc_setAssociatedObject(self, MalterlibIDEContainerKey_lastBuilding, generated, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface NSView (FindUIViewController)
- (NSViewController *) firstAvailableResponderOfClass:(Class)ClassToFind;
- (id) traverseResponderChainForResponder:(Class)ClassToFind;
@end

@implementation NSView (FindUIViewController)
- (NSViewController *) firstAvailableResponderOfClass:(Class)ClassToFind {
    // convenience function for casting and to "mask" the recursive function
    return (NSViewController *)[self traverseResponderChainForResponder:ClassToFind];
}

- (id) traverseResponderChainForResponder:(Class)ClassToFind {
    id nextResponder = [self nextResponder];
    if ([nextResponder isKindOfClass:ClassToFind]) {
        return nextResponder;
    } else if ([nextResponder isKindOfClass:[NSView class]]) {
        return [nextResponder traverseResponderChainForResponder:ClassToFind];
    } else {
        return nil;
    }
}
@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


@interface Plugin_Malterlib : NSObject<IDEContainerReloadingDelegate>
{
	id eventMonitor;
}
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@implementation Plugin_Malterlib

static Plugin_Malterlib *singleton = nil;

#include "Plugin_Malterlib_Navigation.h"
#if LLDBFixesEnable
#	include "Plugin_Malterlib_LLDBFixes.h"
#endif
#include "Plugin_Malterlib_DebugOptions.h"
#include "Plugin_Malterlib_BuildSystem.h"
#include "Plugin_Malterlib_ProjectReload.h"
#include "Plugin_Malterlib_Options.h"
#include "Plugin_Malterlib_SyntaxFixes.h"

Class g_SourceEditorViewClass = nil;

- (void) applicationReady:(NSNotification*)notification {
	g_SourceEditorViewClass = NSClassFromString(@"SourceEditor.SourceEditorContentView");

	g_SourceModelParseLock = [[NSLock alloc] init];;

	original_SMSourceModel_parse = XcodePluginOverrideMethodString(@"SMSourceModel", @selector(parse), (IMP)&SMSourceModel_parse);

	[self loadSettings];
}

- (id) init {
	self = [super init];
	if (self)
	{
#if LLDBFixesEnable
		g_LLDBLaunchLock = [[NSLock alloc] init];
#endif

		NSNotificationCenter* notificationCenter = [NSNotificationCenter defaultCenter];

		if ([NSRunningApplication currentApplication].finishedLaunching) {
		  [self applicationReady:nil];
		}
		else {
		  [notificationCenter addObserver: self
								 selector: @selector( applicationReady: )
									 name: NSApplicationDidFinishLaunchingNotification
								   object: nil];

		}

		[notificationCenter addObserver: self
							   selector: @selector( frameChanged: )
								   name: NSViewFrameDidChangeNotification
								 object: nil];

		[notificationCenter addObserver: self
							   selector: @selector( DVTPlugInDidLoad: )
								   name: @"DVTPlugInDidLoad"
								 object: nil];

		eventMonitor = [NSEvent addLocalMonitorForEventsMatchingMask:NSEventMaskKeyDown handler: [self registerNavigationHandler]];
	}
	return self;
}

- (void) dealloc {
	[NSEvent removeMonitor:eventMonitor];
	[[NSNotificationCenter defaultCenter] removeObserver:self];
}

+ (id)capability
{
	return nil;
}

- (void) DVTPlugInDidLoad:(NSNotification *)notification
{
	if (![((DVTPlugIn *)notification.object).name isEqualToString:@"Plugin_Malterlib"])
		return;

	XcodePluginPreflight(true);

	singleton = self;

	original_changeMaximumOperationConcurrencyUsingThrottleFactor = XcodePluginOverrideMethodString(@"IDEBuildOperationQueueSet", @selector(changeMaximumOperationConcurrencyUsingThrottleFactor:), (IMP)&changeMaximumOperationConcurrencyUsingThrottleFactor);
	XcodePluginAssertOrPerform(original_changeMaximumOperationConcurrencyUsingThrottleFactor, goto failed);

	original_updateOperationConcurrency = XcodePluginOverrideMethodString(@"IDEBuildOperationQueueSet", @selector(updateOperationConcurrency), (IMP)&updateOperationConcurrency);
	XcodePluginAssertOrPerform(original_updateOperationConcurrency, goto failed);

	original_saveContainerForAction = XcodePluginOverrideMethodString(@"IDEContainer", @selector(_saveContainerForAction:error:), (IMP)&_saveContainerForAction);
	XcodePluginAssertOrPerform(original_saveContainerForAction, goto failed);

	original_canSaveContainer = XcodePluginOverrideMethodString(@"IDEContainer", @selector(canSaveContainer), (IMP)&canSaveContainer);
	XcodePluginAssertOrPerform(original_canSaveContainer, goto failed);

	original_filePathDidChangeWithPendingChangeDictionary = XcodePluginOverrideMethodString(@"IDEContainer", @selector(_filePathDidChangeWithPendingChangeDictionary), (IMP)&_filePathDidChangeWithPendingChangeDictionary);
	XcodePluginAssertOrPerform(original_filePathDidChangeWithPendingChangeDictionary, goto failed);

	original_resumeFilePathChangeNotifications = XcodePluginOverrideStaticMethodString(@"IDEContainer", @selector(resumeFilePathChangeNotifications), (IMP)&resumeFilePathChangeNotifications);
	XcodePluginAssertOrPerform(original_resumeFilePathChangeNotifications, goto failed);

	original_suspendFilePathChangeNotifications = XcodePluginOverrideStaticMethodString(@"IDEContainer", @selector(suspendFilePathChangeNotifications), (IMP)&suspendFilePathChangeNotifications);
	XcodePluginAssertOrPerform(original_suspendFilePathChangeNotifications, goto failed);

	original_compositeEnvironmentVariables = XcodePluginOverrideMethodString(@"IDERunOperationPathWorker", @selector(compositeEnvironmentVariables), (IMP)&compositeEnvironmentVariables);
	XcodePluginAssertOrPerform(original_compositeEnvironmentVariables, goto failed);

	#if LLDBFixesEnable
	{
		id pDebuggerExtension = [NSClassFromString(@"DBGLLDBDebugLocalService") _loadDebuggerExtension];

		if (pDebuggerExtension)
		{
			id pWorkerClass = [pDebuggerExtension valueForKey:@"workerClass"];
			(void)pWorkerClass;
		}
	}

	original_LLDBLauncherStart = XcodePluginOverrideMethodString(@"DBGLLDBLauncher", @selector(start), (IMP)&LLDBLauncherStart);
	XcodePluginAssertOrPerform(original_LLDBLauncherStart, goto failed);
	#endif

	XcodePluginPostflight();
}

@end
