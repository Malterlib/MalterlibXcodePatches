#!/bin/bash

xcodebuild -workspace "XcodePlugins.xcworkspace" -scheme "Release All" clean || true
xcodebuild -workspace "XcodePlugins.xcworkspace" -scheme "Release All"
