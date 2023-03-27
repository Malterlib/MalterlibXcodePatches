#import <Cocoa/Cocoa.h>
#include <Carbon/Carbon.h>
#import <objc/runtime.h>
#include "../Shared Code/XcodePlugin.h"

#import "Plugin_NavigationFixes-Swift.h"

#import "Plugin_NavigationFixes.h"

#include <dlfcn.h>

enum EPreferredNextLocation
{
	EPreferredNextLocation_Undefined
	, EPreferredNextLocation_Search
	, EPreferredNextLocation_Issue
	, EPreferredNextLocation_Workspace
	, EPreferredNextLocation_Console
};

typedef NSEvent* __nullable (^CNavigationHandler)(NSEvent*);

static IMP original_IDEFindNavigatorScopeChooserController_viewDidInstall = nil;
static IMP original_SourceEditor_SourceEditorView_pasteAndPreserveFormatting = nil;
static IMP original_SourceEditor_SourceEditorView_paste = nil;
static IMP original_SourceEditor_SourceEditorView_doCommandBySelector = nil;


static IMP original_didSelectTabViewItem = nil;
static IMP original_pushSelectionToChooserViews = nil;
//static IMP original_openLocation = nil;
static IMP original_mouseDownInConsole = nil;
static IMP original_becomeFirstResponder_Console = nil;
static IMP original_becomeFirstResponder_Search = nil;
static IMP original_becomeFirstResponder_NavigatorOutlineView = nil;
static IMP original_becomeFirstResponder_DVTOutlineView = nil;
static IMP original_becomeFirstResponder_DVTFindPatternFieldEditor = nil;
static IMP original_becomeFirstResponder_SourceEditor_SourceEditorView = nil;
static IMP original_resignFirstResponder_DVTFindPatternFieldEditor = nil;
static IMP original_menuItemWithKeyEquivalentMatchingEventRef = nil;
static IMP original_menuItemWithKeyEquivalentMatchingEventRef_macOS1012 = nil;

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface Plugin_NavigationFixesWindowProperties : NSObject
{
}

@property BOOL initializedPotentialViews;

@property IDEFindNavigatorOutlineView *activeFindNavigatorOutlineView;
@property IDENavigatorOutlineView *activeNavigatorOutlineView;
@property DVTOutlineView *activeDVTExplorerOutlineView;

@property IDEFindNavigator *activeFindNavigator;
@property IDENavigator *activeIssueNavigator;

@property DVTFindPatternFieldEditor *respondingPatternFieldEditor;
@property DVTFindBarOptionsCtrl *findBarOptionsCtrl;

@property NSString *consoleLastText;
@property NSRange consoleLastSelectedRange;

@end

@implementation Plugin_NavigationFixesWindowProperties
	@synthesize initializedPotentialViews;
	@synthesize activeFindNavigatorOutlineView;
	@synthesize activeNavigatorOutlineView;
	@synthesize activeDVTExplorerOutlineView;

	@synthesize activeFindNavigator;
	@synthesize activeIssueNavigator;

	@synthesize respondingPatternFieldEditor;
	@synthesize findBarOptionsCtrl;

	@synthesize consoleLastText;
	@synthesize consoleLastSelectedRange;
@end


@interface NSWindow (NavigationFixesNSWindow)

@property (nonatomic, retain) Plugin_NavigationFixesWindowProperties *navigationFixesProperties;


@end

static void * NavigationFixesNSWindow_navigationFixesProperties = &NavigationFixesNSWindow_navigationFixesProperties;

@implementation NSWindow (NavigationFixesNSWindow)

- (Plugin_NavigationFixesWindowProperties *)navigationFixesProperties {
	Plugin_NavigationFixesWindowProperties *pProperties = objc_getAssociatedObject(self, NavigationFixesNSWindow_navigationFixesProperties);
	if (!pProperties)
	{
		pProperties = [[Plugin_NavigationFixesWindowProperties alloc] init];
		objc_setAssociatedObject(self, NavigationFixesNSWindow_navigationFixesProperties, pProperties, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
	}
    return pProperties;
}
- (void)setNavigationFixesProperties:(Plugin_NavigationFixesWindowProperties *)value {
	objc_setAssociatedObject(self, NavigationFixesNSWindow_navigationFixesProperties, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


@interface NSWindowTabGroup (NavigationFixesNSWindowTabGroup)

@property (nonatomic, retain) IDEWorkspaceWindow *lastValidEditorWindow;

@property (nonatomic, assign) enum EPreferredNextLocation preferredNextLocation;

@end

static void * NavigationFixesNSWindowTabGroup_lastValidEditorWindow = &NavigationFixesNSWindowTabGroup_lastValidEditorWindow;
static void * NavigationFixesNSWindowTabGroup_preferredNextLocation = &NavigationFixesNSWindowTabGroup_preferredNextLocation;

@implementation NSWindowTabGroup (NavigationFixesNSWindowTabGroup)

- (IDEWorkspaceWindow *)lastValidEditorWindow {
    return objc_getAssociatedObject(self, NavigationFixesNSWindowTabGroup_lastValidEditorWindow);
}

- (void)setLastValidEditorWindow:(IDEWorkspaceWindow *)value {
    objc_setAssociatedObject(self, NavigationFixesNSWindowTabGroup_lastValidEditorWindow, value, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (enum EPreferredNextLocation)preferredNextLocation {
    NSNumber *pNumber = objc_getAssociatedObject(self, NavigationFixesNSWindowTabGroup_preferredNextLocation);
	if (!pNumber)
		return EPreferredNextLocation_Undefined;

	return [pNumber intValue];
}

- (void)setPreferredNextLocation:(enum EPreferredNextLocation )value {
    objc_setAssociatedObject(self, NavigationFixesNSWindowTabGroup_preferredNextLocation, [NSNumber numberWithInt:value], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


@interface NSObject (NavigationFixesNSObject)

@property (nonatomic, retain) NSNumber *displayCycleObserver_alreadyScheduled;
@property (nonatomic, retain) NSNumber *displayCycleObserver_lastDraw;
@property (nonatomic, retain) NSNumber *displayCycleObserver_sequence;

@end


static void * NavigationFixesNSObjectKey_displayCycleObserver_alreadyScheduled = &NavigationFixesNSObjectKey_displayCycleObserver_alreadyScheduled;
static void * NavigationFixesNSObjectKey_displayCycleObserver_lastDraw = &NavigationFixesNSObjectKey_displayCycleObserver_lastDraw;
static void * NavigationFixesNSObjectKey_displayCycleObserver_sequence = &NavigationFixesNSObjectKey_displayCycleObserver_sequence;

@implementation NSObject (NavigationFixesNSObject)

- (NSNumber *)displayCycleObserver_alreadyScheduled {
    return objc_getAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_alreadyScheduled);
}

- (void)setDisplayCycleObserver_alreadyScheduled:(NSNumber *)generated {
    objc_setAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_alreadyScheduled, generated, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSNumber *)displayCycleObserver_lastDraw {
    return objc_getAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_lastDraw);
}

- (void)setDisplayCycleObserver_lastDraw:(NSNumber *)generated {
    objc_setAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_lastDraw, generated, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (NSNumber *)displayCycleObserver_sequence {
    return objc_getAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_sequence);
}

- (void)setDisplayCycleObserver_sequence:(NSNumber *)generated {
    objc_setAssociatedObject(self, NavigationFixesNSObjectKey_displayCycleObserver_sequence, generated, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


@interface NSView (SubtreeDescription)

- (NSString *)_subtreeDescription;

@end

/*@interface SwiftReflector
- (void)reflect: (id) object;
@end*/

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

@protocol Plugin_NavigationFixes
- (CNavigationHandler) registerNavigationHandler;
@end


////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////


@interface Plugin_NavigationFixes : NSObject
{
	id eventMonitor;
}
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface NSObject (Private)
- (NSString*)_methodDescription;
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface SourceEditor_SourceEditorView : NSView
- (void) replaceAndFindNext:(id) arg1;
- (void) replaceAndFindPrevious:(id) arg1;
- (void) replaceAll:(id) arg1;
- (void) useSelectionForFind:(id) arg1;
- (void) useSelectionForReplace:(id) arg1;
- (void) findAndReplace:(id) arg1;
- (void) hideFindBar:(id) arg1;
- (void) replace:(id) arg1;
- (void) find:(id) arg1;
- (void) findNext:(id) arg1;
- (void) findPrevious:(id) arg1;
- (void) deleteToBeginningOfText:(id) arg1;
- (void) moveCurrentLineUp:(id) arg1;
- (void) moveCurrentLineDown:(id) arg1;
- (void) indentSelection:(id) arg1;
- (void) moveToBeginningOfText:(id) arg1;
- (void) moveToBeginningOfTextAndModifySelection:(id) arg1;
- (void) moveToEndOfText:(id) arg1;
- (void) moveToEndOfTextAndModifySelection:(id) arg1;
- (void) deleteToEndOfText:(id) arg1;
- (void) pasteAndPreserveFormatting:(id) arg1;
- (void) paste:(id) arg1;
- (void) unfold:(id) arg1;
- (void) fold:(id) arg1;
- (void) moveForward: (id)arg;
- (void) moveBackward: (id)arg;
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface IDESourceEditor_SourceCodeEditorView: SourceEditor_SourceEditorView
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface IDESourceEditor_SourceCodeEditor : IDEEditor
- (NSRange)selectedLineRange;
- (NSArray *)currentSelectedDocumentLocations;
- (void)selectDocumentLocations: (NSArray *)array;
- (NSString *)selectedText;
- (IDESourceEditor_SourceCodeEditorView *)sourceEditorView;
- (void) toggleBreakpointAtCurrentLine:(id) arg1;
@end

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////

@interface SourceEditor_SourceEditorTextFindPanel : NSViewController

- (id) caseSensitiveButton;
- (void) setCaseSensitiveButton:(id) arg1;
- (void) caseSensitiveButtonAction:(id) arg1;

- (id) searchPatternPopUp;
- (void) setSearchPatternPopUp:(id) arg1;
- (void) searchPatternPopUpAction:(id) arg1;

- (id) replaceField;
- (id) findField;

@end

@interface DVTSourceEditor_DVTSourceEditorTextFindPanel : SourceEditor_SourceEditorTextFindPanel
- (id) addPatternSeparator;
- (void) setAddPatternSeparator:(id) arg1;
- (id) addPatternSeparatorHeightConstraint;
- (void) setAddPatternSeparatorHeightConstraint:(id) arg1;
- (id) addPatternButton;
- (void) setAddPatternButton:(id) arg1;
- (void) addPatternButtonAction:(id) arg1;
- (id) findPatternField;
- (id) replacePatternField;
- (id) initWithCoder: (id) arg1;
- (void) controlTextDidChange:(id) arg1;
@end

@implementation Plugin_NavigationFixes
static Plugin_NavigationFixes *singleton = nil;

static IDESourceEditor_SourceCodeEditor *getEditor(NSWindow* _pWindow)
{
	IDEWorkspaceTabController *pTabController = getWorkspaceTabController(_pWindow);
	if (!pTabController)
		return NULL;

	IDEEditorArea *editorArea = pTabController.editorArea;
	if (!editorArea)
		return NULL;

	IDEEditorContext *lastActiveEditorContext = editorArea.lastActiveEditorContext;
	if (!lastActiveEditorContext)
		return NULL;

	if ([lastActiveEditorContext.editor isKindOfClass:NSClassFromString(@"IDESourceEditor.SourceCodeEditor")])
		return (IDESourceEditor_SourceCodeEditor *)lastActiveEditorContext.editor;
	return NULL;
}

static void setEditorFocus(NSWindow* _pWindow)
{
	IDEEditor *editor = getEditor(_pWindow);
	if (!editor)
		return;

	[_pWindow makeKeyWindow];
	[editor takeFocus];
}

#include "Plugin_NavigationFixes_SwiftCall.h"
#include "Plugin_NavigationFixes_Navigation.h"
#include "Plugin_NavigationFixes_InterceptShortcuts.h"
#include "Plugin_NavigationFixes_ConsoleGoto.h"
#include "Plugin_NavigationFixes_PasteNoFormat.h"
#include "Plugin_NavigationFixes_MoveWord.h"

- (void) applicationReady:(NSNotification*)notification {

	original_SourceEditor_SourceEditorView_pasteAndPreserveFormatting = XcodePluginOverrideMethodString(@"SourceEditor.SourceEditorView", @selector(pasteAndPreserveFormatting:), (IMP)&SourceEditor_SourceEditorView_pasteAndPreserveFormatting);
	original_SourceEditor_SourceEditorView_paste = XcodePluginOverrideMethodString(@"SourceEditor.SourceEditorView", @selector(paste:), (IMP)&SourceEditor_SourceEditorView_paste);
	original_SourceEditor_SourceEditorView_doCommandBySelector = XcodePluginOverrideMethodString(@"SourceEditor.SourceEditorView", @selector(doCommandBySelector:), (IMP)&SourceEditor_SourceEditorView_doCommandBySelector);

	original_becomeFirstResponder_SourceEditor_SourceEditorView = XcodePluginOverrideMethodString(@"SourceEditor.SourceEditorView", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_SourceEditor_SourceEditorView);

	Call_InitFunctionPointers();
}

- (id) init {
	self = [super init];
	if (self)
	{
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
							   selector: @selector( windowDidBecomeKey: )
								   name: NSWindowDidBecomeKeyNotification
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

- (void) onLoad
{
	XcodePluginPreflight(false);

	NSError *error = NULL;
	g_pSourceLocationColumnRegex = [NSRegularExpression regularExpressionWithPattern:@"^(.*?):([0-9]*):([0-9]*):?"
                                                                       options:NSRegularExpressionCaseInsensitive
                                                                         error:&error];

	original_IDEFindNavigatorScopeChooserController_viewDidInstall = XcodePluginOverrideMethodString(@"IDEFindNavigatorScopeChooserController", @selector(viewDidInstall), (IMP)&IDEFindNavigatorScopeChooserController_viewDidInstall);
	XcodePluginAssertOrPerform(original_IDEFindNavigatorScopeChooserController_viewDidInstall, goto failed);

	original_didSelectTabViewItem = XcodePluginOverrideMethodString(@"IDELocationCategoryPrefsPaneController", @selector(tabView:didSelectTabViewItem:), (IMP)&didSelectTabViewItem);
	XcodePluginAssertOrPerform(original_didSelectTabViewItem, goto failed);

	original_pushSelectionToChooserViews = XcodePluginOverrideMethodString(@"IDENavigatorArea", @selector(pushSelectionToChooserViews), (IMP)&pushSelectionToChooserViews);
	XcodePluginAssertOrPerform(original_pushSelectionToChooserViews, goto failed);

/*	original_openLocation = XcodePluginOverrideStaticMethodString(@"IDEOpenQuicklyResultOpener", @selector(openLocation:inWorkspaceTabController:targetOriginatingEditor:completionHandler:), (IMP)&openLocation);
	XcodePluginAssertOrPerform(original_openLocation, goto failed);*/

	original_mouseDownInConsole = XcodePluginOverrideMethodString(@"IDEConsoleTextView", @selector(mouseDown:), (IMP)&mouseDownInConsole);
	XcodePluginAssertOrPerform(original_mouseDownInConsole, goto failed);

	original_becomeFirstResponder_Console = XcodePluginOverrideMethodString(@"IDEConsoleTextView", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_Console);
	XcodePluginAssertOrPerform(original_becomeFirstResponder_Console, goto failed);

	original_becomeFirstResponder_Search = XcodePluginOverrideMethodString(@"IDEProgressSearchField", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_Search);
	XcodePluginAssertOrPerform(original_becomeFirstResponder_Search, goto failed);

	original_becomeFirstResponder_NavigatorOutlineView = XcodePluginOverrideMethodString(@"IDENavigatorOutlineView", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_NavigatorOutlineView);
	XcodePluginAssertOrPerform(original_becomeFirstResponder_NavigatorOutlineView, goto failed);

	original_becomeFirstResponder_DVTOutlineView = XcodePluginOverrideMethodString(@"DVTOutlineView", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_DVTOutlineView);
	XcodePluginAssertOrPerform(original_becomeFirstResponder_DVTOutlineView, goto failed);

	original_becomeFirstResponder_DVTFindPatternFieldEditor = XcodePluginOverrideMethodString(@"DVTFindPatternFieldEditor", @selector(becomeFirstResponder), (IMP)&becomeFirstResponder_DVTFindPatternFieldEditor);
	XcodePluginAssertOrPerform(original_becomeFirstResponder_DVTFindPatternFieldEditor, goto failed);

	original_resignFirstResponder_DVTFindPatternFieldEditor = XcodePluginOverrideMethodString(@"DVTFindPatternFieldEditor", @selector(resignFirstResponder), (IMP)&resignFirstResponder_DVTFindPatternFieldEditor);
	XcodePluginAssertOrPerform(original_resignFirstResponder_DVTFindPatternFieldEditor, goto failed);

	original_menuItemWithKeyEquivalentMatchingEventRef = XcodePluginOverrideStaticMethodString(@"NSCarbonMenuImpl", @selector(_menuItemWithKeyEquivalentMatchingEventRef:inMenu:), (IMP)&menuItemWithKeyEquivalentMatchingEventRef);
	original_menuItemWithKeyEquivalentMatchingEventRef_macOS1012 = XcodePluginOverrideStaticMethodString(@"NSCarbonMenuImpl", @selector(_menuItemWithKeyEquivalentMatchingEventRef:inMenu:includingDisabledItems:), (IMP)&menuItemWithKeyEquivalentMatchingEventRef_macOS1012);

	XcodePluginAssertOrPerform(original_menuItemWithKeyEquivalentMatchingEventRef || original_menuItemWithKeyEquivalentMatchingEventRef_macOS1012, goto failed);

	XcodePluginPostflight();
}

void InitPlugin(void)
{
	singleton = [[Plugin_NavigationFixes alloc] init];
	[singleton onLoad];
}

@end
