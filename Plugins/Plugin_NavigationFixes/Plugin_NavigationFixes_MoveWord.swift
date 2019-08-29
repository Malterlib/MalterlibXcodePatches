import Foundation

func binarySearchLine(_ lineData: [SourceEditor.SourceEditorLineData], characterPos: Int) -> Int {
	var lowerBound = 0
	var upperBound = lineData.count
	var iIter = 0;
	while lowerBound < upperBound {
		iIter += 1;
		let midIndex = lowerBound + (upperBound - lowerBound) / 2
		if lineData[midIndex].lineContentRange.location == characterPos {
			return midIndex
		} else if lineData[midIndex].lineContentRange.location < characterPos {
			lowerBound = midIndex + 1
		} else {
			upperBound = midIndex
		}
	}
	return upperBound
}

func getCodeCharSet() -> CharacterSet {
	let AlphaNumericSpace = CharacterSet.alphanumerics;
	var CodeCharSet = CharacterSet();
	CodeCharSet.formUnion(AlphaNumericSpace);
	CodeCharSet.insert(charactersIn: "_");
	return CodeCharSet;
}

let g_WhiteSpace = CharacterSet.whitespaces;
let g_NewLine = CharacterSet.newlines;
let g_CodeCharSet = getCodeCharSet();

@inline(never) func positionFromCharPos(_ dataSource: Unmanaged<SourceEditor.SourceEditorDataSource>, _ charPos: Int) -> SourceEditor.SourceEditorPosition {
	let iLine: Int = max(binarySearchLine(dataSource.takeUnretainedValue().lineData, characterPos: charPos) - 1, 0);

	for iSearch in iLine..<(iLine + 3) {
		let lineContentRange = dataSource.takeUnretainedValue().lineData[iSearch].lineContentRange;
		if (charPos >= lineContentRange.location) && (charPos <= (lineContentRange.location + lineContentRange.length)) {
			return SourceEditor.SourceEditorPosition(line: iSearch, col: charPos - lineContentRange.location);
		}
	}

	abort()
}

@inline(never) func charPosFromPosition(_ dataSource: Unmanaged<SourceEditor.SourceEditorDataSource>, _ pos: SourceEditor.SourceEditorPosition) -> Int {
	let lineData = dataSource.takeUnretainedValue().lineData[Int(pos.line)];
	return lineData.lineContentRange.location + Int(pos.col);
}

@inline(never) func getNextWordPosition(_ dataSource: Unmanaged<SourceEditor.SourceEditorDataSource>, fromPos: SourceEditor.SourceEditorPosition) -> SourceEditor.SourceEditorPosition {
	let contents = dataSource.takeUnretainedValue().contents;

	var iCharPos = charPosFromPosition(dataSource, fromPos);

	let nCharacters = contents.length;

	// Move to end of word
	if (iCharPos < nCharacters)
	{
		var StartChar = Unicode.Scalar(contents.character(at: iCharPos))!
		if (g_NewLine.contains(StartChar))
		{
			if (StartChar == "\r")
			{
				iCharPos += 1;
				StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;
				if (StartChar == "\n")
				{
					iCharPos += 1;
				}
			}
			else if (StartChar == "\n")
			{
				iCharPos += 1;
			}

			if (iCharPos > nCharacters) {
				iCharPos = nCharacters;
			}

			return positionFromCharPos(dataSource, iCharPos);
		}
		else if (g_CodeCharSet.contains(StartChar))
		{
			while (iCharPos < nCharacters)
			{
				if (!g_CodeCharSet.contains(Unicode.Scalar(contents.character(at: iCharPos))!)) {
					break
				}
				iCharPos += 1
			}
		}
		else if (!g_WhiteSpace.contains(StartChar))
		{
			if (iCharPos < nCharacters) {
				iCharPos += 1
			}
		}

		// Move over any white space
		while (iCharPos < nCharacters)
		{
			if (!g_WhiteSpace.contains(Unicode.Scalar(contents.character(at: iCharPos))!)) {
				break
			}
			iCharPos += 1
		}
	}

	if (iCharPos > nCharacters) {
		iCharPos = nCharacters;
	}

	return positionFromCharPos(dataSource, iCharPos);
}

@inline(never) func getPrevWordPosition(_ dataSource: Unmanaged<SourceEditor.SourceEditorDataSource>, fromPos: SourceEditor.SourceEditorPosition) -> SourceEditor.SourceEditorPosition {
	let contents = dataSource.takeUnretainedValue().contents;

	var iCharPos = charPosFromPosition(dataSource, fromPos);
	let nCharacters = contents.length;

	if (iCharPos > 0) {
		iCharPos -= 1;
	}

	var StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;

	var wasNewLine = false;
	if (g_NewLine.contains(StartChar))
	{
		wasNewLine = true;
		if (iCharPos > 0)
		{
			if (StartChar == "\n")
			{
				if (Unicode.Scalar(contents.character(at: iCharPos - 1))! == "\r")
				{
					iCharPos -= 1;
					StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;
				}
			}
		}
	}

	if (wasNewLine)
	{
		if (iCharPos < 0) {
			iCharPos = 0;
		}
		return positionFromCharPos(dataSource, iCharPos);
	}

	if (g_WhiteSpace.contains(StartChar))
	{
		while (iCharPos > 0)
		{
			StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;

			if (!g_WhiteSpace.contains(StartChar))
			{
				if (g_NewLine.contains(StartChar))
				{
					iCharPos += 1;
					return positionFromCharPos(dataSource, iCharPos);
				}
				break;
			}
			iCharPos -= 1;
		}
	}

	if (!g_NewLine.contains(StartChar))
	{
		// Move to beginning of word
		if (g_CodeCharSet.contains(StartChar))
		{
			while (iCharPos > 0)
			{
				StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;

				if (!g_CodeCharSet.contains(StartChar))
				{
					if (iCharPos < nCharacters) {
						iCharPos += 1;
					}
					break;
				}
				iCharPos -= 1;
			}
		}
	}

	if (iCharPos < 0) {
		iCharPos = 0;
	}

	return positionFromCharPos(dataSource, iCharPos);
}

extension SourceEditor.SourceEditorView {
	@_silgen_name("Call_SourceEditor_SourceEditorView_deleteSourceRange") public func deleteSourceRange(range: Swift.Range<SourceEditor.SourceEditorPosition>, forward: Swift.Bool, useKillRing: Swift.Bool) -> ();
	@_silgen_name("Call_SourceEditor_SourceEditorView_selectTextRange") public func selectTextRange(_: Range<SourceEditor.SourceEditorPosition>?, scrollPlacement: SourceEditor.ScrollPlacement?, alwaysScroll: Swift.Bool) -> ();
	@_silgen_name("Call_SourceEditor_SourceEditorView_clearSelectionAnchors") public func clearSelectionAnchors() -> ();

	@_silgen_name("SourceEditor_SourceEditorView_getDataSource") public func getDataSource() -> Unmanaged<SourceEditor.SourceEditorDataSource>;
	@_silgen_name("SourceEditor_SourceEditorView_getLayoutManager") public func getLayoutManager() -> Unmanaged<SourceEditor.SourceEditorLayoutManager>;
	@_silgen_name("SourceEditor_SourceEditorView_getSelectionPointer") public func getSelectionPointer() -> UnsafeMutableRawPointer;
}

extension SourceEditor.SourceEditorLayoutManager {
	@_silgen_name("Call_SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded") public func expandRangeIfNeeded(_: Range<SourceEditor.SourceEditorPosition>) -> Range<SourceEditor.SourceEditorPosition>;
}

@objc public class XcodePluginNavigationFixes_MoveWord : NSObject {

	class func moveWord(_ sourceView: SourceEditor.SourceEditorView, forward: Bool) -> Bool {
		//XcodePluginDumpClass(SourceEditor.SourceEditorView.self);
		//XcodePluginDumpClass(type(of: sourceView));
		//XcodePluginSwiftReflector.dumpObjectTypes(sourceView);
		/*let instance : SourceEditor.SourceEditorSelection? = SourceEditor.SourceEditorSelection();
		let size = MemoryLayout.size(ofValue: instance)
		print("size \(size)");
		let size2 = MemoryLayout.size(ofValue: instance!)
		print("size2 \(size2)");*/

		let dataSource = sourceView.getDataSource();

		let selectionAddress = sourceView.getSelectionPointer();
		let selection = selectionAddress.load(as: Optional<SourceEditor.SourceEditorSelection>.self);

		if (selection == nil || selection!.secondarySelections.count > 0) {
			return false;
		}

		var position: SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();

		if (selection!.primarySelection.selectionAnchor == nil) {
			position = selection!.primarySelection.range.lowerBound;
			if (selection!.secondarySelections.count > 0) {
				sourceView.clearSelectionAnchors();
			}
		} else {
			let anchor = selection!.primarySelection.selectionAnchor!.lowerBound;
			let startPosition = selection!.primarySelection.range.lowerBound;
			let endPosition = selection!.primarySelection.range.upperBound;

			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
			sourceView.clearSelectionAnchors();
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(dataSource, fromPos: position);
		}

		let range : Range<SourceEditor.SourceEditorPosition> = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (lower: newPosition, upper: newPosition));
		sourceView.selectTextRange(range, scrollPlacement: nil, alwaysScroll: false)

		return true;
	}

	class func deleteWord(_ sourceView: SourceEditor.SourceEditorView, forward: Bool) -> Bool {

		let dataSource = sourceView.getDataSource();

		let selectionAddress = sourceView.getSelectionPointer();
		let selection = selectionAddress.load(as: Optional<SourceEditor.SourceEditorSelection>.self);

		if (selection == nil || selection!.secondarySelections.count > 0) {
			return false;
		}

		var position = SourceEditor.SourceEditorPosition();

		if (selection!.primarySelection.selectionAnchor == nil) {
			position = selection!.primarySelection.range.lowerBound;
			if (selection!.secondarySelections.count > 0) {
				sourceView.clearSelectionAnchors();
			}
		} else {
			let anchor = selection!.primarySelection.selectionAnchor!.lowerBound;
			let startPosition = selection!.primarySelection.range.lowerBound;
			let endPosition = selection!.primarySelection.range.upperBound;

			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
			sourceView.clearSelectionAnchors();
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(dataSource, fromPos: position);
		}

		var range : Range<SourceEditor.SourceEditorPosition>;

		if (newPosition == position) {
			return true;
		}

		if (newPosition > position) {
			range = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (lower: position, upper: newPosition));
		} else {
			range = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (lower: newPosition, upper: position));
		}

		let layoutManager = sourceView.getLayoutManager();

		let fixedRange = layoutManager.takeUnretainedValue().expandRangeIfNeeded(range);
		sourceView.deleteSourceRange(range: fixedRange, forward: false, useKillRing: false);
		return true;
	}

	class func moveWordAndModifySelection(_ sourceView: SourceEditor.SourceEditorView, forward: Bool) -> Bool {
		let dataSource = sourceView.getDataSource();
		let selectionAddress = sourceView.getSelectionPointer();
		var selection = selectionAddress.load(as: Optional<SourceEditor.SourceEditorSelection>.self);

		if (selection == nil || selection!.secondarySelections.count > 0) {
			return false;
		}

		var position = SourceEditor.SourceEditorPosition();
		var bPositionSet = false;

		if (selection!.secondarySelections.count > 0) {
			sourceView.clearSelectionAnchors();
		}

		if (selection!.primarySelection.selectionAnchor == nil) {
			position = selection!.primarySelection.range.upperBound;
			bPositionSet = true
			Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(sourceView);
			selection = selectionAddress.load(as: Optional<SourceEditor.SourceEditorSelection>.self);
			if (selection!.primarySelection.selectionAnchor == nil) {
				print("STILL no selection anchor");
				return false;
			}
		}

		let anchor = selection!.primarySelection.selectionAnchor!.upperBound;
		let startPosition = selection!.primarySelection.range.upperBound;
		let endPosition = selection!.primarySelection.range.lowerBound;

		if (!bPositionSet) {
			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(dataSource, fromPos: position);
		}

		var range : Range<SourceEditor.SourceEditorPosition>;
		if (newPosition > anchor) {
			range = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (lower: anchor, upper: newPosition));
		} else {
			range = Range<SourceEditor.SourceEditorPosition>(uncheckedBounds: (lower: newPosition, upper: anchor));
		}

		selection!.primarySelection.range = range;

		sourceView.selectTextRange(range, scrollPlacement: nil, alwaysScroll: false);
		selectionAddress.bindMemory(to: Optional<SourceEditor.SourceEditorSelection>.self, capacity: 1).pointee = selection;
		return true;
	}
	@objc public class func moveWordForward(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return moveWord(sourceView, forward: true);
	}

	@objc public class func moveWordBackward(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return moveWord(sourceView, forward: false);
	}

	@objc public class func moveWordBackwardAndModifySelection(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return moveWordAndModifySelection(sourceView, forward: false)
	}

	@objc public class func moveWordForwardAndModifySelection(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return moveWordAndModifySelection(sourceView, forward: true)
	}

	@objc public class func deleteWordForward(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return deleteWord(sourceView, forward: true);
	}

	@objc public class func deleteWordBackward(_ sourceView: SourceEditor.SourceEditorView) -> Bool {
		return deleteWord(sourceView, forward: false);
	}
}
