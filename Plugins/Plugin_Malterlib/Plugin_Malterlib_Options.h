
BOOL g_bDisableDyldLibraries = true;
BOOL g_bDisableDyldInsertLibraries = true;

- (void) loadSettings
{
	NSUserDefaults* userDefaults = [NSUserDefaults standardUserDefaults];

	NSDictionary *pAllSettings = [userDefaults dictionaryRepresentation];
	if ([[pAllSettings allKeys] containsObject:@"Malterlib_DisableDyldLibraries"])
		g_bDisableDyldLibraries = [userDefaults boolForKey:@"Malterlib_DisableDyldLibraries"];
	if ([[pAllSettings allKeys] containsObject:@"Malterlib_DisableDyldInsertLibraries"])
		g_bDisableDyldInsertLibraries = [userDefaults boolForKey:@"Malterlib_DisableDyldInsertLibraries"];
}
- (void) saveSettings
{
	NSUserDefaults* userDefaults = [NSUserDefaults standardUserDefaults];

	[userDefaults setBool:g_bDisableDyldLibraries forKey:@"Malterlib_DisableDyldLibraries"];
	[userDefaults setBool:g_bDisableDyldInsertLibraries forKey:@"Malterlib_DisableDyldInsertLibraries"];
}

NSPanel* m_OptionsWindow = nil;
NSWindow* m_MainWindow = nil;

- (void) closeOptions:(id)sender
{
	[m_MainWindow endSheet:m_OptionsWindow];
}

- (void) optionChanged:(id)sender
{
	if ([sender isKindOfClass:[NSButton class]])
	{
		NSButton* button = sender;
		if ([[button title] compare:@"Disable DYLD_LIBRARY_PATH and DYLD_FRAMEWORK_PATH in debugger"] == NSOrderedSame)
			g_bDisableDyldLibraries = [button state] == NSControlStateValueOn;
		else if ([[button title] compare:@"Disable DYLD_INSERT_LIBRARIES in debugger"] == NSOrderedSame)
			g_bDisableDyldInsertLibraries = [button state] == NSControlStateValueOn;
	}
}

- (void) changeOptions:(id)sender
{
	if (m_OptionsWindow)
		return;

	float Width = 600;

	NSRect frame = NSMakeRect(0, 0, Width, 110);

	NSPanel* window  = [[NSPanel alloc] initWithContentRect:frame
												  styleMask:NSWindowStyleMaskClosable | NSWindowStyleMaskTitled
													backing:NSBackingStoreBuffered
													  defer:NO];

	m_OptionsWindow = window;
	m_MainWindow = [NSApp keyWindow];

	window.title = @"Xcode fixes options";

	NSButton* disableLibrariesButton = [[NSButton alloc] initWithFrame:NSMakeRect(10, 70, Width-20, 25)];
	disableLibrariesButton.autoresizingMask = NSViewWidthSizable;
	disableLibrariesButton.title = @"Disable DYLD_LIBRARY_PATH and DYLD_FRAMEWORK_PATH in debugger";
	if (g_bDisableDyldLibraries)
		[disableLibrariesButton setState: NSControlStateValueOn];
	[disableLibrariesButton setTarget:self];
	[disableLibrariesButton setAction: @selector(optionChanged:)];
	[disableLibrariesButton setButtonType: NSButtonTypeSwitch];
	[[window contentView] addSubview:disableLibrariesButton];

	NSButton* disableInsertLibrariesButton = [[NSButton alloc] initWithFrame:NSMakeRect(10, 45, Width - 20, 25)];
	disableInsertLibrariesButton.autoresizingMask = NSViewWidthSizable;
	disableInsertLibrariesButton.title = @"Disable DYLD_INSERT_LIBRARIES in debugger";
	if (g_bDisableDyldInsertLibraries)
		[disableInsertLibrariesButton setState: NSControlStateValueOn];
	[disableInsertLibrariesButton setTarget:self];
	[disableInsertLibrariesButton setAction: @selector(optionChanged:)];
	[disableInsertLibrariesButton setButtonType: NSButtonTypeSwitch];
	[[window contentView] addSubview:disableInsertLibrariesButton];

	NSButton* closeButton = [[NSButton alloc] initWithFrame:NSMakeRect(10, 10, 80, 25)];
	closeButton.autoresizingMask = NSViewWidthSizable;
	closeButton.title = @"Close";
	[closeButton setTarget:self];
	[closeButton setAction: @selector(closeOptions:)];
	[closeButton setButtonType: NSButtonTypePushOnPushOff];
	[closeButton setBezelStyle: NSBezelStyleRounded];
	[[window contentView] addSubview:closeButton];

	[
		m_MainWindow beginSheet: window
		completionHandler: ^(NSModalResponse returnCode)
		{
			[self saveSettings];
			[window orderOut:self];
			[NSApp stopModal];
			m_MainWindow = nil;
			m_OptionsWindow = nil;
		}
	];
}

- (void) addItemToApplicationMenu
{
	NSMenu* mainMenu = [NSApp mainMenu];
	NSMenu* editorMenu = [[mainMenu itemAtIndex:[mainMenu indexOfItemWithTitle:@"Edit"]] submenu];

	if ( editorMenu != nil)
	{
		if ([editorMenu itemWithTitle:@"Xcode debug options..."] == nil)
		{
			XcodePluginLog(@"%s: editor menu added.\n",__FUNCTION__);

			NSMenuItem* newItem = [NSMenuItem new];

			[newItem setTitle:@"Xcode debug options..."];
			[newItem setTarget:self];
			[newItem setAction:@selector( changeOptions: )];
			[newItem setEnabled:YES];
			[newItem setKeyEquivalent:@"o"];
			[newItem setKeyEquivalentModifierMask:NSEventModifierFlagControl];

			[editorMenu insertItem:newItem atIndex:[editorMenu numberOfItems]];
		}
	}
	else
		XcodePluginLog(@"%s: failed to add editor menu.\n",__FUNCTION__);
}
