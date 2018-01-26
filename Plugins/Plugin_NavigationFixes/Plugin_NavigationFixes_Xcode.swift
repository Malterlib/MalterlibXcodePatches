
public class SourceEditor {
	public class SourceEditorTextFindPanel: NSViewController {
	}

	class SourceEditorLayoutManager {
	}

	class SourceEditorLineData {
		var lineContentRange: _NSRange = _NSRange();
		var lineTerminatorLength: Int = 0;
		var placeholders: Array<(_NSRange, Any)> = Array<(_NSRange, Any)>();
		var hidden: Bool = false;
	}

	class SourceEditorDataSource {
		var lineData: Array<SourceEditor.SourceEditorLineData> = Array<SourceEditor.SourceEditorLineData>();
		var utf8RangeData: Array<_NSRange> = Array<_NSRange>();
		var contents: NSString = NSString();
	}

	class SourceEditorMouseSelectionSession {
		var startSelection: Optional<SourceEditor.SourceEditorSelection> = nil;
		var currentSelection: Optional<SourceEditor.SourceEditorSelection> = nil;
		var startPoint: CGPoint = CGPoint();
		var currentPoint: CGPoint = CGPoint();
	}

	public class SourceEditorSelectionController {
		var sourceEditorView: Optional<SourceEditor.SourceEditorView> = nil;
		var mouseSelectionSession: Optional<SourceEditor.SourceEditorMouseSelectionSession> = nil;
		var selectionAnchor: Optional<SourceEditor.SourceEditorRange> = nil;
	}

	public enum ScrollPlacement {
		case Case_0

		init() {
			self = .Case_0
		}
	}

	public enum SourceEditorSelectionModifiers: UInt64
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
			self = .Case_9
		}
	}
	struct SourceEditorPosition {
		var line: Int = 0;
		var col: Int = 0;

		static func == (lhs: SourceEditorPosition, rhs: SourceEditorPosition) -> Bool {
			return
				lhs.line == rhs.line &&
					lhs.col == rhs.col
			;
		}

		static func < (lhs: SourceEditor.SourceEditorPosition, rhs: SourceEditor.SourceEditorPosition) -> Bool {
			if (lhs.line < rhs.line) {
				return true
			}
			else if (lhs.line > rhs.line) {
				return false
			}
			return lhs.col < rhs.col
		}

		static func > (lhs: SourceEditor.SourceEditorPosition, rhs: SourceEditor.SourceEditorPosition) -> Bool {
			if (lhs.line > rhs.line) {
				return true
			}
			else if (lhs.line < rhs.line) {
				return false
			}
			return lhs.col > rhs.col
		}
	}
	public struct SourceEditorRange {
		var start: SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		var end: SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();

		static func == (lhs: SourceEditorRange, rhs: SourceEditorRange) -> Bool {
			return
				lhs.start == rhs.start &&
					lhs.end == rhs.end
			;
		}
	}

	public struct SourceEditorSelection {
		var range: SourceEditor.SourceEditorRange = SourceEditor.SourceEditorRange();
		var modifiers: SourceEditor.SourceEditorSelectionModifiers = SourceEditor.SourceEditorSelectionModifiers();
	}

	public class SourceEditorView: NSView {
		var dummy0_0 : UInt64 = 0;
		var dummy0_1 : UInt64 = 0;
		var dummy0_2 : UInt64 = 0;

		var layoutManager: SourceEditor.SourceEditorLayoutManager = SourceEditor.SourceEditorLayoutManager();

		var dummy1_0 : UInt64 = 0;
		var dummy1_1 : UInt64 = 0;
		var dummy1_2 : UInt64 = 0;

		var dataSource: SourceEditor.SourceEditorDataSource = SourceEditor.SourceEditorDataSource();

		var dummy2_00 : UInt64 = 0;
		var dummy2_01 : UInt64 = 0;
		var dummy2_02 : UInt64 = 0;
		var dummy2_03 : UInt64 = 0;
		var dummy2_04 : UInt64 = 0;
		var dummy2_05 : UInt64 = 0;
		var dummy2_06 : UInt64 = 0;
		var dummy2_07 : UInt64 = 0;
		var dummy2_08 : UInt64 = 0;
		var dummy2_09 : UInt64 = 0;

		var dummy2_10 : UInt64 = 0;
		var dummy2_11 : UInt64 = 0;
		var dummy2_12 : UInt64 = 0;
		var dummy2_13 : UInt64 = 0;
		var dummy2_14 : UInt64 = 0;
		var dummy2_15 : UInt64 = 0;
		var dummy2_16 : UInt64 = 0;
		var dummy2_17 : UInt64 = 0;
		var dummy2_18 : UInt64 = 0;
		var dummy2_19 : UInt64 = 0;

		var dummy2_20 : UInt64 = 0;
		var dummy2_21 : UInt64 = 0;
		var dummy2_22 : UInt64 = 0;
		var dummy2_23 : UInt64 = 0;
		var dummy2_24 : UInt64 = 0;
		var dummy2_25 : UInt64 = 0;
		var dummy2_26 : UInt64 = 0;
		var dummy2_27 : UInt64 = 0;
		var dummy2_28 : UInt64 = 0;
		var dummy2_29 : UInt64 = 0;

		var dummy2_30 : UInt64 = 0;
		var dummy2_31 : UInt64 = 0;
		var dummy2_32 : UInt64 = 0;
		var dummy2_33 : UInt64 = 0;
		var dummy2_34 : UInt64 = 0;
		var dummy2_35 : UInt64 = 0;
		var dummy2_36 : UInt64 = 0;
		var dummy2_37 : UInt64 = 0;
		var dummy2_38 : UInt64 = 0;
		var dummy2_39 : UInt64 = 0;

		var dummy2_40 : UInt64 = 0;
		var dummy2_41 : UInt64 = 0;
		var dummy2_42 : UInt64 = 0;
		var dummy2_43 : UInt64 = 0;
		var dummy2_44 : UInt64 = 0;
		var dummy2_45 : UInt64 = 0;
		var dummy2_46 : UInt64 = 0;
		var dummy2_47 : UInt64 = 0;
		var dummy2_48 : UInt64 = 0;
		var dummy2_49 : UInt64 = 0;

		var dummy2_50 : UInt64 = 0;
		var dummy2_51 : UInt64 = 0;
		var dummy2_52 : UInt64 = 0;
		var dummy2_53 : UInt64 = 0;
		var dummy2_54 : UInt64 = 0;
		var dummy2_55 : UInt64 = 0;
		var dummy2_56 : UInt64 = 0;
		var dummy2_57 : UInt64 = 0;
		var dummy2_58 : UInt64 = 0;
		var dummy2_59 : UInt64 = 0;

		var dummy2_60 : UInt64 = 0;
		var dummy2_61 : UInt64 = 0;
		var dummy2_62 : UInt64 = 0;
		var dummy2_63 : UInt64 = 0;
		var dummy2_64 : UInt64 = 0;
		var dummy2_65 : UInt64 = 0;
		var dummy2_66 : UInt64 = 0;
		var dummy2_67 : UInt64 = 0;

		var selectionController: SourceEditor.SourceEditorSelectionController? = nil;

		var dummy3_0 : UInt64 = 0;

		var selection: Optional<SourceEditor.SourceEditorSelection> = nil;
	}
}
