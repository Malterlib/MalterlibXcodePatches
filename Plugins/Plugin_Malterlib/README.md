### Description

Fixes limitations bugs in Xcode making life easer when you generate projects

+ Batches external updates and automatically reloads them. .xcworkspace and .xcproj folders needs to have a 'generatedContainer' file in them to enable. For use with external project generators.
+ Run multiple schemes with `⌘-G` from one scheme by setting Custom working directory to "[MulitLaunchSchemes]" and the scheme names as arguments
+ Ability to stop the debugger from setting DYLD_INSERT_LIBRARIES, DYLD_LIBRARY_PATH and DYLD_FRAMEWORK_PATH. Accessbile from Edit->Xcode fixes options... or `Ctrl+O`
+ Disable the build queue throttling in Xcode

### TODO
+ Build only current project

### Installation

[See](../README.md)
