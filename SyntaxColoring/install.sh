#!/bin/bash

set -e

if [[ "$1" != "" ]]; then
	XcodeLocation="$1"
else
	XcodeLocation="/Applications/Xcode.app"
fi

echo Patching Xcode definitions
if ! cp Definitions/* "$XcodeLocation/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/" ; then
	sudo cp Definitions/* "$XcodeLocation/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/"
fi
defaults write com.apple.dt.Xcode DVTTextEnableNativeParser -bool NO

mkdir -p "$HOME/Library/Developer/Xcode/UserData/FontAndColorThemes/"

cp Malterlib.xccolortheme "$HOME/Library/Developer/Xcode/UserData/FontAndColorThemes/"

cp UnbrokenFont/* "$HOME/Library/Fonts"
