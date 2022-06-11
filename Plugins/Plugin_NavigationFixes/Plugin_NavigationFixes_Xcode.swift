
public class SourceEditor {
	public class SourceEditorTextFindPanel: NSViewController {
	}

	public class SourceEditorLayoutManager {
	}

	struct SourceEditorLayoutManagerIdentifier: Hashable {
		let identifier: ObjectIdentifier;
	}

	struct LayoutContext<T> {
		init() {
		}
		let values: Dictionary<SourceEditor.SourceEditorLayoutManagerIdentifier, T>! = nil;
	}

	public class SourceEditorLineData {
		let lineContentRange: _NSRange = _NSRange();
		let lineTerminatorLength: Int = 0;
		let placeholders: Array<(_NSRange, Any)> = Array<(_NSRange, Any)>();
		let hidden: Bool = false;
		let layer: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		let auxViews: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		let accessoryView: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		let substitutionView: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		let accessibilityElement: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
	}

	public class SourceEditorDataSource {
		let lineData: ContiguousArray<SourceEditor.SourceEditorLineData> = ContiguousArray<SourceEditor.SourceEditorLineData>();
		let utf8RangeData: Array<_NSRange> = Array<_NSRange>();
		let contents: NSString = NSString();
 	}

	public enum ScrollPlacement {
		case Case_0

		init() {
			self = .Case_0
		}
	}

	public enum SourceEditorSelectionModifiers: Int
	{
		case Case_0 = 0
		case Case_1
		case Case_2
		case Case_3
		case Case_4
		case Case_5
		case Case_6
		case Case_7
		case Case_8
		case Case_9
		init()
		{
			self = .Case_0
		}
	}

	public struct SourceEditorPosition {
		init(line: Int, col: Int) {
			self.line = line;
			self.col = col;
		}
		init() {
			self.line = 0;
			self.col = 0;
		}
		var line: Int;
		var col: Int;
	}

	public struct SourceEditorVerticalAnchor {
		let position: SourceEditor.SourceEditorPosition;
		let offset: Int = 0;
		let anchorPoint: CGPoint? = nil;
		let currentPosition: SourceEditor.SourceEditorPosition? = nil;
	}

	public struct SourceEditorSingleSelection {
		var range: Range<SourceEditor.SourceEditorPosition> = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (SourceEditor.SourceEditorPosition(), SourceEditor.SourceEditorPosition()));
		let markedRange: Range<SourceEditor.SourceEditorPosition>! = nil;
		let selectionAnchor: Range<SourceEditor.SourceEditorPosition>! = nil;
		let verticalAnchor: SourceEditor.SourceEditorVerticalAnchor! = nil;
	}

	public struct SourceEditorSelection {
		var primarySelection: SourceEditor.SourceEditorSingleSelection = SourceEditor.SourceEditorSingleSelection();
		let secondarySelections: [SourceEditor.SourceEditorSingleSelection] = [SourceEditor.SourceEditorSingleSelection]();
		let modifiers: SourceEditor.SourceEditorSelectionModifiers = SourceEditor.SourceEditorSelectionModifiers();
	}

	public class SourceEditorView: NSView {
	}
}

extension SourceEditor.SourceEditorPosition: Comparable {
	public static func == (lhs: SourceEditor.SourceEditorPosition, rhs: SourceEditor.SourceEditorPosition) -> Bool {
		return
			lhs.line == rhs.line &&
				lhs.col == rhs.col
		;
	}

	public static func < (lhs: SourceEditor.SourceEditorPosition, rhs: SourceEditor.SourceEditorPosition) -> Bool {
		if (lhs.line < rhs.line) {
			return true
		}
		else if (lhs.line > rhs.line) {
			return false
		}
		return lhs.col < rhs.col
	}
}
