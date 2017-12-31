#import <Cocoa/Cocoa.h>
#import <objc/runtime.h>
#import "XcodePlugin.h"

static NSMenu 	 * 								 viewMenu = nil;
static NSString * const kDisableAnimationsClassName = @"Plugin_DisableAnimations",
					 * const        kHideDistractionsKey = @"D";

static NSUInteger kHideDistractionsKeyModifiers 	= (NSEventModifierFlagCommand | NSEventModifierFlagShift);


@interface 		 Plugin_HideDistractions : NSObject
@property (strong, nonatomic) NSMenuItem * hideDistractionsMenuItem;
@property 									BOOL   isShowingDistractions;
@end

@implementation Plugin_HideDistractions
@synthesize  	 hideDistractionsMenuItem,
					 isShowingDistractions;

+ (void)pluginDidLoad:(NSBundle *)plugin	{

	XcodePluginPreflight(false);
	if ([NSRunningApplication currentApplication].finishedLaunching) {
		[self applicationFinishedLaunching:nil];
	}
	else {
		[NSNotificationCenter.defaultCenter addObserver:self selector:@selector(applicationFinishedLaunching:)
																 name:NSApplicationDidFinishLaunchingNotification object: nil];
	}
	XcodePluginPostflight();
}
+ (instancetype) sharedPlugin {	static Plugin_HideDistractions * sharedPlugin = nil;
											static 			 dispatch_once_t   onceToken;

	dispatch_once(&onceToken, ^{ sharedPlugin = self.new;
										  sharedPlugin.isShowingDistractions = YES;
	});	return sharedPlugin;
}
+ (void)applicationFinishedLaunching: (NSNotification *)notification
{
	[self sharedPlugin];

	NSMenu *mainMenu 				= [NSApp mainMenu];
	NSMenuItem *viewMenuItem  	= [mainMenu itemWithTitle: @"Edit"];
	XcodePluginAssertOrPerform(mainMenu, return);
	XcodePluginAssertOrPerform(viewMenuItem, return);

	viewMenu 						= viewMenuItem.submenu;
	XcodePluginAssertOrPerform(viewMenuItem, return);

	/* The 'Hide Distractions' menu item key combination can be set below. */
	NSMenuItem *hideMenu;
	[[self sharedPlugin] setHideDistractionsMenuItem: hideMenu = [NSMenuItem.alloc initWithTitle:@"Hide Distractions"
																													  action:@selector(hideDistractions:)
																											 keyEquivalent:kHideDistractionsKey]];
	XcodePluginAssertOrPerform(hideMenu,return);
	[hideMenu setKeyEquivalentModifierMask: kHideDistractionsKeyModifiers];
	[hideMenu setTarget: self];
	[viewMenu addItem:hideMenu];
}

+ (void)clickMenuItem: (NSMenuItem *)menuItem	{

	if (menuItem && menuItem.isEnabled) [NSApp sendAction:menuItem.action to:menuItem.target from:menuItem];
}

+ (NSMenuItem *)menuItemWithPath: (NSString *)menuItemPath
{
	NSArray *pathComponents 			= nil;
	NSString *currentPathComponent 	= nil;
	NSMenu *currentMenu 					= nil;
	NSMenuItem *currentMenuItem 		= nil;

	NSParameterAssert(menuItemPath);
	NSParameterAssert([menuItemPath length]);

	currentMenu = [NSApp mainMenu];
	XcodePluginAssertOrPerform(currentMenu, return nil);

	pathComponents = [menuItemPath componentsSeparatedByString: @" > "];

	for (currentPathComponent in pathComponents)
	{
		XcodePluginAssertOrRaise(currentPathComponent);
		XcodePluginAssertOrRaise([currentPathComponent length]);

		[currentMenu update];
		currentMenuItem = [currentMenu itemWithTitle: currentPathComponent];
		XcodePluginConfirmOrPerform(currentMenuItem && currentMenuItem.isEnabled, return nil);

		currentMenu = currentMenuItem.hasSubmenu ? currentMenuItem.submenu : nil;
	}

	return currentMenuItem;
}

+ (void)toggleMenu	{ BOOL newVal = ![[self sharedPlugin]isShowingDistractions];

	[[self sharedPlugin]setIsShowingDistractions:newVal];
	[[[self sharedPlugin]hideDistractionsMenuItem]setTitle: newVal ? @"Hide Distractions" :@"Un-hide Distractions"];
}

+ (void)hideDistractions: (id)sender
{
	if (! [[self sharedPlugin]isShowingDistractions])  { [self showDistractions:self];  return; }

	NSWindow *activeWindow = nil;				/* Get the front window */

	activeWindow = [NSApp keyWindow];
	XcodePluginConfirmOrPerform(activeWindow, return);

	/* If we get here, everything checks out; that is, we have an active window and we have
	 references to the required menus items. */

	if (NSClassFromString(kDisableAnimationsClassName))	[activeWindow disableFlushWindow];

//	[self clickMenuItem: [self menuItemWithPath: @"View > Hide Toolbar"]];
	[self clickMenuItem: [self menuItemWithPath: @"View > Hide Tab Bar"]];

	/* Zoom our window after hiding the toolbar. */

//	if (!NSEqualRects([activeWindow frame], [[activeWindow screen] visibleFrame]))
//		[activeWindow setFrame: [[activeWindow screen] visibleFrame] display: YES];

	/* Perform the rest of our menu items now that the toolbar's taken care of. */

	[self clickMenuItem: [self menuItemWithPath: @"View > Debug Area > Hide Debug Area"]];
	[self clickMenuItem: [self menuItemWithPath: @"View > Navigators > Hide Navigator"]];
	[self clickMenuItem: [self menuItemWithPath: @"View > Utilities > Hide Utilities"]];
	[self clickMenuItem: [self menuItemWithPath: @"View > Standard Editor > Show Standard Editor"]];
	[self clickMenuItem: [self menuItemWithPath: @"Find > Find > Hide Find Bar"]];
	[self clickMenuItem: [self menuItemWithPath: @"Editor > Issues > Hide All Issues"]];

	if (NSClassFromString(kDisableAnimationsClassName))		[activeWindow enableFlushWindow];

	/* Replace the menu item */
	[self toggleMenu];
}

+ (void)showDistractions: (id)sender
{
	NSWindow *activeWindow = [NSApp keyWindow];
	XcodePluginConfirmOrPerform(activeWindow, return);

	/* If we get here, everything checks out; that is, we have an active window and we have
	 references to the required menus items. */

	if (NSClassFromString(kDisableAnimationsClassName)) [activeWindow disableFlushWindow];

//	[self clickMenuItem: [self menuItemWithPath: @"View > Show Toolbar"]];
	[self clickMenuItem: [self menuItemWithPath: @"View > Show Tab Bar"]];

	/* Perform the rest of our menu items now that the toolbar's taken care of. */

	[self clickMenuItem: [self menuItemWithPath: @"View > Navigators > Show Navigator"]];
//	[self clickMenuItem: [self menuItemWithPath: @"View > Utilities > Show Utilities"]];
	[self clickMenuItem: [self menuItemWithPath: @"Editor > Issues > Show All Issues"]];

	if (NSClassFromString(kDisableAnimationsClassName))
		[activeWindow enableFlushWindow];

	[self toggleMenu]; 	/* Replace the menu item */
}
@end
