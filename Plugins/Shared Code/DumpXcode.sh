#!/bin/bash


IFS=$'\n'
set -f
set -e
#set -x

XcodeVersion=Xcode.app

#XcodeExecutables="$XcodeExecutables
#$(find /System/Library/Frameworks -type f -perm +111)"
#XcodeExecutables="$XcodeExecutables
#$(find /System/Library/PrivateFrameworks -type f -perm +111)"
XcodeExecutables="$XcodeExecutables
$(find /Applications/$XcodeVersion/Contents/Plugins -type f -perm +111)"
XcodeExecutables="$XcodeExecutables
$(find /Applications/$XcodeVersion/Contents/OtherFrameworks -type f -perm +111)"
XcodeExecutables="$XcodeExecutables
$(find /Applications/$XcodeVersion/Contents/SharedFrameworks -type f -perm +111)"
XcodeExecutables="$XcodeExecutables
$(find /Applications/$XcodeVersion/Contents/Frameworks -type f -perm +111)"
XcodeExecutables="$XcodeExecutables
$(find /Applications/$XcodeVersion/Contents/MacOS -type f -perm +111)"

CurrentPath=$PWD
mkdir -p "$CurrentPath/XcodeDump"
if [ -e "$CurrentPath/XcodeDump/CDStructures.h" ]; then
	rm "$CurrentPath/XcodeDump/CDStructures.h"
fi

for Executable in $XcodeExecutables; do
	[[ "$Executable" == "/Applications/$XcodeVersion/Contents/Plugins/IDEInterfaceBuilderKit.framework/Versions/A/Resources/nibextractor" ]] && continue
	[[ $Executable =~ ^/Applications/Xcode\.app/Contents/OtherFrameworks/DevToolsInterface\.framework/Versions/A/Resources/UtilityScripts/.*$ ]] && continue
	[[ $Executable =~ ^.*\.pl$ ]] && continue
	[[ $Executable =~ ^.*\.py$ ]] && continue
	[[ $Executable =~ ^.*\.cube$ ]] && continue
	[[ $Executable =~ ^.*\.msgpack$ ]] && continue

#	echo $Executable 1>&2
	#class-dump --sdk-mac /Applications/$XcodeVersion/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk "$Executable"
	#echo -e "\033[32m/opt/Source/class-dump/build/Release/class-dump --arch x86_64 -H -F --sdk-mac "" -o $CurrentPath/XcodeDump $Executable \033[0m" 1>&2
	#/opt/Source/class-dump/build/Release/class-dump --arch x86_64 -H -F --sdk-mac "" -o $CurrentPath/XcodeDump "$Executable" || true
	#class-dump -H -I --sdk-mac /Applications/$XcodeVersion/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -o $CurrentPath/XcodeDump "$Executable"
	#class-dump -H -I -r --sdk-mac /Applications/$XcodeVersion/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk -o $CurrentPath/XcodeDump "$Executable"

	#echo -e "\033[32mktool -v -1 dump --headers --fdec --out \"$CurrentPath/XcodeDump\" \"$Executable\" \033[0m" 1>&2
	#ktool -v -1 dump --headers --fdec --out "$CurrentPath/XcodeDump" "$Executable"

	echo -e "\033[32mipsw class-dump --arch arm64 --headers --output \"$CurrentPath/XcodeDump\" \"$Executable\" \033[0m" 1>&2
	ipsw class-dump --arch arm64 --headers --refs --output "$CurrentPath/XcodeDump" "$Executable" || true
done



