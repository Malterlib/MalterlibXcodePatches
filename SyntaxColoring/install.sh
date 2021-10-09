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

exit 0

xcode.syntax.markup.emphasis = Italic
xcode.syntax.markup.emphasis.strong = Bold
xcode.syntax.markup.strikethrough = Strikthrough

xcode.syntax.markup.aside.kind = xcode.syntax.markup.aside.kind
xcode.syntax.markup.code = DVTMarkupTextInlineCodeColor

################

# Used
xcode.syntax.markup.aside.kind				# Auto <------ Not critical
xcode.syntax.declaration.type 				# Local Functor (OK)
xcode.syntax.identifier.type.system 		# Variable (OK)
xcode.syntax.character						# Char
xcode.syntax.comment						# Comment
xcode.syntax.comment.doc					# Template constant <--------- Does not work in Xcode anyway
xcode.syntax.comment.doc.keyword 			# Built in type <------------- Not critical
xcode.syntax.declaration.other				# Member functor (OK)
xcode.syntax.identifier.class				# Type (OK)
xcode.syntax.identifier.class.system		# Functor param (OK)
xcode.syntax.identifier.constant			# Member (OK)
xcode.syntax.identifier.constant.system		# Member private (OK)
xcode.syntax.identifier.function			# Member function (OK)
xcode.syntax.identifier.function.system		# Global function (OK)
xcode.syntax.identifier.macro				# Macro Define (OK)
xcode.syntax.preprocessor					# Macro parameter <----------- Not critical
xcode.syntax.identifier.type				# Namespace (OK)
xcode.syntax.attribute						# Template function typename <------ Does not work in Xcode anyway
xcode.syntax.identifier.variable			# Function parameter (OK)
xcode.syntax.identifier.variable.system		# (private) static member, global static, global (OK)
xcode.syntax.keyword						# Keywords <--------- Not critical
xcode.syntax.mark							# Tempalte typename <--------- Does not work in Xcode anyway
xcode.syntax.markup.code					# Template function constant <----  Does not work in Xcode anyway
xcode.syntax.number							# Number
xcode.syntax.plain							# Language constructs
xcode.syntax.identifier.macro.system		# Member function private (OK)
xcode.syntax.string							# String
xcode.syntax.url							# Enumerator, member constant etc (OK)

