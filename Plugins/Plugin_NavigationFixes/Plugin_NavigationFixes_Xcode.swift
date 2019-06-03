
public class SourceEditor {
	public class SourceEditorTextFindPanel: NSViewController {
	}

	public class SourceEditorLayoutManager {
	}

	struct SourceEditorLayoutManagerIdentifier: Hashable {
		var identifier: ObjectIdentifier;
	}

	struct LayoutContext<T> {
		init() {
		}
		var values: Dictionary<SourceEditor.SourceEditorLayoutManagerIdentifier, T>! = nil;
	}

	public class SourceEditorLineData {
		var lineContentRange: _NSRange = _NSRange();
		var lineTerminatorLength: Int = 0;
		var placeholders: Array<(_NSRange, Any)> = Array<(_NSRange, Any)>();
		var hidden: Bool = false;
		var layer: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		var auxViews: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		var accessoryView: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		var substitutionView: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
		var accessibilityElement: SourceEditor.LayoutContext<Any> = SourceEditor.LayoutContext<Any>();
	}

	public class SourceEditorDataSource {
		var lineData: Array<SourceEditor.SourceEditorLineData> = Array<SourceEditor.SourceEditorLineData>();
		var utf8RangeData: Array<_NSRange> = Array<_NSRange>();
		var contents: NSString = NSString();
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
		var line: Int = 0;
		var col: Int = 0;
	}

	public struct SourceEditorVerticalAnchor {
		var position: SourceEditor.SourceEditorPosition;
		var offset: Int = 0;
		var anchorPoint: CGPoint? = nil;
		var currentPosition: SourceEditor.SourceEditorPosition? = nil;
	}

	public struct SourceEditorSingleSelection {
		var range: Range<SourceEditor.SourceEditorPosition> = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (SourceEditor.SourceEditorPosition(), SourceEditor.SourceEditorPosition()));
		var markedRange: Range<SourceEditor.SourceEditorPosition>! = nil;
		var selectionAnchor: Range<SourceEditor.SourceEditorPosition>! = nil;
		var verticalAnchor: SourceEditor.SourceEditorVerticalAnchor! = nil;
	}

	public struct SourceEditorSelection {
		var primarySelection: SourceEditor.SourceEditorSingleSelection = SourceEditor.SourceEditorSingleSelection();
		var secondarySelections: [SourceEditor.SourceEditorSingleSelection] = [SourceEditor.SourceEditorSingleSelection]();
		var modifiers: SourceEditor.SourceEditorSelectionModifiers = SourceEditor.SourceEditorSelectionModifiers();
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

