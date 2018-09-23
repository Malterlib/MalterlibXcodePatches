__===== DESCRIPTION =====__

This project includes plugins that extend Xcode
and fix some of its annoying behaviors.

__===== INSTALLATION =====__

To install the plugins:

Resign Xcode

1. Open the XcodePlugins workspace
2. Change the scheme to "Release All maintained"
3. Build the plugins
4. Unsign Xcode.app. You can use https://github.com/steakknife/unsign for this purpose
```./unsign "/Applications/Xcode.app/Contents/MacOS/Xcode" "/Applications/Xcode.app/Contents/MacOS/Xcode"
./unsign "/Applications/Xcode.app/Contents/Developer/usr/bin/xcodebuild" "/Applications/Xcode.app/Contents/Developer/usr/bin/xcodebuild"
``` 

The plugins will automatically be installed as a part of the build
process. Xcode must be relaunched for the plugins to take effect.

Plugins are installed into `~/Library/Application Support/Developer/<Xcode version>/Xcode/Plug-ins/.`

[Malterlib](Plugin_Malterlib/README.md)

[NavigationFixes](Plugin_NavigationFixes/README.md)

[Customize Annotation Colors](Plugin_CustomizeAnnotations/README.md)

[Hide Distractions](Plugin_HideDistractions/README.md)

[P4 Checkout](Plugin_P4Checkout/README.md)
