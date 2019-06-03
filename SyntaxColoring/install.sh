#!/bin/bash

set -e

if [[ "$1" != "" ]]; then
	XcodeLocation="$1"
else
	XcodeLocation="/Applications/Xcode.app"
fi

echo Patching Xcode definitions

if ! cp -f Definitions/* "$XcodeLocation/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/" 2> /dev/null ; then
	sudo cp -f Definitions/* "$XcodeLocation/Contents/SharedFrameworks/DVTFoundation.framework/Versions/A/Resources/"
fi


if ! cp -f Definitions/* "$XcodeLocation/Contents/SharedFrameworks/SourceModel.framework/Versions/A/Resources/LanguageSpecifications/" 2> /dev/null ; then
	sudo cp -f Definitions/* "$XcodeLocation/Contents/SharedFrameworks/SourceModel.framework/Versions/A/Resources/LanguageSpecifications/"
fi
defaults write com.apple.dt.Xcode DVTTextEnableNativeParser -bool NO

mkdir -p "$HOME/Library/Developer/Xcode/UserData/FontAndColorThemes/"

cp -f Malterlib.xccolortheme "$HOME/Library/Developer/Xcode/UserData/FontAndColorThemes/"
defaults write com.apple.dt.xcode XCFontAndColorCurrentTheme Malterlib.xccolortheme

cp -f UnbrokenFont/* "$HOME/Library/Fonts"
