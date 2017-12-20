### Description

This plugin adds a "Hide Distractions" menu item
to the View menu, which focuses the current editor by hiding auxiliary
views and maximizing the active window. This plugin works best when the
Plugin_DisableAnimations plugin is also installed.

The default key combination for the 'Hide Distractions' menu item is
command-shift-D, which interferes with Xcode's default key combination
for 'Jump to Instruction Pointer' (under the Navigate menu), so you
may want remove that key binding to free up command-shift-D.
Alternatively, you can modify the 'Hide Distractions' key combination
by editing Plugin_HideDistractions.m and changing the
kHideDistractionsKey and kHideDistractionsKeyModifiers constants at
the top of the file.

### Installation

[See](../README.md)
