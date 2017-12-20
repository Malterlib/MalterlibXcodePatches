#!/bin/bash

xcodebuild -workspace "XcodePlugins.xcworkspace" -scheme "Release All" clean
xcodebuild -workspace "XcodePlugins.xcworkspace" -scheme "Release All"
