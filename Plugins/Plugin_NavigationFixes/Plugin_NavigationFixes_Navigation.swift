
import Foundation

extension SourceEditor.SourceEditorTextFindPanel {
	@_silgen_name("Call_SourceEditor_SourceEditorTextFindPanel_recentsMenuItems") public func recentsMenuItems() -> Swift.Array<NSMenuItem>;
}

@objc public class XcodePluginNavigationFixes_Navigation : NSObject {

	@objc public class func recentMenuItems(_ sourceEditorTextFindPanel: SourceEditor.SourceEditorTextFindPanel) -> NSArray {
		let rawItems = sourceEditorTextFindPanel.recentsMenuItems();
		return rawItems as NSArray;
	}
}
