### Description

This plugin aims to emulate the editor behavior of the Visual Studio editor. The following features are implemented

+ `HOME` (`fn←` and `⌘←` on a Mac keyboard) jumps to first non-white space character and then cycles between start of line and first non-white space character
+ Text is not automatically indented when pasted
+ Insert tab indents selection instead of deleting it
+ Insert back tab unindents selection instead of deleting it
+ Move whole word left and right commands emulates the behavior in Visual Studio, where the location is the same when moving forward or backword
+ You can double-click on a <source>:<line>: formatted string in the the console to get to the location in the editor
+ `⌘-N` / `⌘-Shift-N` keyboard shortcuts moves to the next/previous location as in Visual Studio. This means:
 + Results in the batch find navigator
 + Issues in the issue navigator
 + Source locations in the console output
 + Files in the project navigator
 + It will use the same shortcut for all of these and use last active of them to go to the source location
+ `Option-N` keyboard shortcuts opens folder in navigator and moves to the next location. This means:
 + Issues in the issue navigator
 + Files in the project navigator
 + It will use the same shortcut for all of these and use last active of them to go to the source location
+ Emulate keyboard behaviour of find and replace:
 + `Tab` / `Shift+Tab` goes between find and replace fields instead of stopping at find button first
 + Down arrow centers on the last recent item instead of on the options menu item
 + `Ctrl-N` finds next search result
 + `Ctrl-Shift-N` finds previous search result
 + `Ctrl-R` Replaces one result
 + `Ctrl-A` Replaces all results
 + `Ctrl-O` Shows the options panel
 + `Ctrl-C` Toggels match case
 + `Ctrl-E` Toggels regular expression
 + `Ctrl-W` Toggles whole word only matching
 + `Esc` Returns to editor from batch find

Also fixes limitations bugs in Xcode

+ `Ctrl-H` Toggles breakpoints more reliably than the built in shortcut for toggling breakpoints (workaround for Xcode bug)

### TODO
+ Keyboard shortcuts should follow whatever is setup by user when possible

### Installation

[See](../README.md)
