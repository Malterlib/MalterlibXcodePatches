#!/bin/bash

set -e

CurrentDir="$PWD"

pushd /Applications/Xcode.app/Contents/SharedFrameworks/SourceModel.framework/Versions/A/Resources/LanguageSpecifications
cp BaseSupport.xclangspec "$CurrentDir/Definitions/"
cp C++.xclangspec "$CurrentDir/Definitions/"
cp C.xclangspec "$CurrentDir/Definitions/"
cp ObjectiveC++.xclangspec "$CurrentDir/Definitions/"
cp ObjectiveC.xclangspec "$CurrentDir/Definitions/"
cp OpenCL.xclangspec "$CurrentDir/Definitions/"

