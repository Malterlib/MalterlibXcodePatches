#!/bin/bash


IFS=$'\n'
set -f
set -e

pushd Xcode
FilesToUpdate="$XcodeExecutables
$(find . -type f)"
popd

CurrentPath=$PWD

Search0='struct { unsigned int x :62 _reserved; unsigned int x :1 _isSecondaryScan; unsigned int x :1 _hasScannedForPlugIns; }'
Replace0='struct { uint64_t _reserved :62 ; uint64_t _isSecondaryScan :1 ; uint64_t _hasScannedForPlugIns :1 ; }'

Search1='struct { unsigned int x :1 observingForBuildProductsRelative; unsigned int x :1 observingForCurrentSDKRelative; unsigned int x :1 observingForSourceTreeRelative; }'
Replace1='struct { unsigned int observingForBuildProductsRelative :1 ; unsigned int observingForCurrentSDKRelative :1 ; unsigned int observingForSourceTreeRelative :1 ; }'

Search2='#include "NSCopying-Protocol.h"'
Replace2=''

Search3='struct _NSRange { unsigned long long x0; unsigned long long x1; }'
Replace3='struct NSRange'




for File in $FilesToUpdate; do
	File=${File#"./"}

	if [[ "$File" == ".DS_Store" ]] || [[ "$File" == "NSCarbonMenuImpl.h" ]] || [[ "$File" == "NSConcreteTextStorage.h" ]] ; then
		continue
	else

		FindFile=`find "XcodeDump" -name "$File" | head -n 1`

		if [ -e "$FindFile" ]; then
			echo "$FindFile" to "Xcode/$File" 1>&2
			sed 's/@import Foundation;/#import <Foundation\/Foundation.h>/g' "$FindFile" | sed 's/@dynamic//g' \
			| sed "s/$Search0/$Replace0/g" \
			| sed "s/$Search1/$Replace1/g" \
			| sed "s/$Search2/$Replace2/g" \
			| sed "s/$Search3/$Replace3/g" \
			> "Xcode/$File"
		else
			if [[ "$File" == "./Shared.h" ]]; then
				continue
			fi
			rm "Xcode/$File"
			echo -e "\033[31mMISSING:\033[0m $File"
		fi
	fi
done
