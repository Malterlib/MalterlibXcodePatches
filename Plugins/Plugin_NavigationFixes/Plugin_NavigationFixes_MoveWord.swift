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
	CodeCharSet.formUnion(AlphaNumericSpace)
	CodeCharSet.insert(charactersIn: "_")
	return CodeCharSet;
}

let g_WhiteSpace = CharacterSet.whitespaces;
let g_NewLine = CharacterSet.newlines;
let g_CodeCharSet = getCodeCharSet();

func positionFromCharPos(_ dataSource: SourceEditor.SourceEditorDataSource, _ charPos: Int) -> SourceEditor.SourceEditorPosition {
	let iLine: Int = max(binarySearchLine(dataSource.lineData, characterPos: charPos) - 1, 0);

	for iSearch in iLine..<(iLine + 3) {
		let lineContentRange = dataSource.lineData[iSearch].lineContentRange;
		if (charPos >= lineContentRange.location) && (charPos <= (lineContentRange.location + lineContentRange.length)) {
			return SourceEditor.SourceEditorPosition(line: iSearch, col: charPos - lineContentRange.location);
		}
	}

	abort()
}

func charPosFromPosition(_ dataSource: SourceEditor.SourceEditorDataSource, _ pos: SourceEditor.SourceEditorPosition) -> Int {
	let lineData = dataSource.lineData[Int(pos.line)];
	return lineData.lineContentRange.location + Int(pos.col);
}

func getNextWordPosition(_ dataSource: SourceEditor.SourceEditorDataSource, fromPos: SourceEditor.SourceEditorPosition) -> SourceEditor.SourceEditorPosition {
	let contents = dataSource.contents;

	var iCharPos = charPosFromPosition(dataSource, fromPos);

	let nCharacters = contents.length;

	// Move to end of word
	if (iCharPos < nCharacters)
	{
		let StartChar = Unicode.Scalar(contents.character(at: iCharPos))!
		if (g_CodeCharSet.contains(StartChar))
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

func getPrevWordPosition(_ dataSource: SourceEditor.SourceEditorDataSource, fromPos: SourceEditor.SourceEditorPosition) -> SourceEditor.SourceEditorPosition {
	let contents = dataSource.contents;

	var iCharPos = charPosFromPosition(dataSource, fromPos);

	let nCharacters = contents.length;

	if (iCharPos > 0) {
		iCharPos -= 1;
	}

	var StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;

	if (g_NewLine.contains(StartChar))
	{
		if (iCharPos > 0)
		{
			if (StartChar == "\n")
			{
				iCharPos -= 1;
				StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;
				if (StartChar == "\r")
				{
					iCharPos -= 1;
					StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;
				}
			}
			else if (StartChar == "\r")
			{
				iCharPos -= 1;
				StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;
			}
		}
	}

	while (iCharPos > 0)
	{
		StartChar = Unicode.Scalar(contents.character(at: iCharPos))!;

		if (!g_WhiteSpace.contains(StartChar)) {
			break;
		}
		iCharPos -= 1;
	}

	if (g_NewLine.contains(StartChar))
	{
		if (iCharPos < nCharacters) {
			iCharPos += 1;
		}
	}
	else
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
	@_silgen_name("Call_SourceEditor_SourceEditorView_deleteSourceRange") public func deleteSourceRange(range: SourceEditor.SourceEditorRange, forward: Swift.Bool, useKillRing: Swift.Bool) -> ();
	@_silgen_name("Call_SourceEditor_SourceEditorView_selectTextRange") public func selectTextRange(_: SourceEditor.SourceEditorRange?, scrollPlacement: SourceEditor.ScrollPlacement?, alwaysScroll: Swift.Bool) -> ();
	@_silgen_name("Call_SourceEditor_SourceEditorView_clearSelectionAnchors") public func clearSelectionAnchors() -> ();
}

extension SourceEditor.SourceEditorLayoutManager {
	@_silgen_name("Call_SourceEditor_SourceEditorLayoutManager_expandRangeIfNeeded") public func expandRangeIfNeeded(_: SourceEditor.SourceEditorRange) -> SourceEditor.SourceEditorRange;
}

@objc public class XcodePluginNavigationFixes_MoveWord : NSObject {

	class func moveWord(_ sourceView: SourceEditor.SourceEditorView, forward: Bool) {
//		XcodePluginDumpClass(SourceEditor.SourceEditorView.self);
//		XcodePluginDumpClass(type(of: sourceView));
//		XcodePluginSwiftReflector.dumpObjectTypes(sourceView);

		if (sourceView.selection == nil) {
			return;
		}

		let selection = sourceView.selection!;

		var position: SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();

		if (sourceView.selectionController == nil || sourceView.selectionController!.selectionAnchor == nil) {
			position = selection.range.start;
		} else {
			let anchor = sourceView.selectionController!.selectionAnchor!.start;
			let startPosition = selection.range.start;
			let endPosition = selection.range.end;

			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
			sourceView.clearSelectionAnchors();
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(sourceView.dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(sourceView.dataSource, fromPos: position);
		}

		let range : SourceEditor.SourceEditorRange = SourceEditor.SourceEditorRange(start: newPosition, end: newPosition);
		sourceView.selectTextRange(range, scrollPlacement: nil, alwaysScroll: false)
	}

	class func deleteWord(_ sourceView: SourceEditor.SourceEditorView, forward: Bool) {
		if (sourceView.selection == nil) {
			return;
		}
		let selection = sourceView.selection!;

		var position = SourceEditor.SourceEditorPosition();

		if (sourceView.selectionController == nil || sourceView.selectionController!.selectionAnchor == nil) {
			position = sourceView.selection!.range.start;
		} else {
			let anchor = sourceView.selectionController!.selectionAnchor!.start;
			let startPosition = selection.range.start;
			let endPosition = selection.range.end;

			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
			sourceView.clearSelectionAnchors();
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(sourceView.dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(sourceView.dataSource, fromPos: position);
		}

		var range : SourceEditor.SourceEditorRange = SourceEditor.SourceEditorRange();

		if (newPosition == position) {
			return;
		}

		if (newPosition > position) {
			range.start = position
			range.end = newPosition
		} else {
			range.start = newPosition
			range.end = position
		}

		let fixedRange = sourceView.layoutManager.expandRangeIfNeeded(range);
		sourceView.deleteSourceRange(range: fixedRange, forward: false, useKillRing: false);
	}

	class func moveWordAndModifySelection(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!, arg2: Selector, forward: Bool) {
		if (sourceView.selection == nil) {
			return;
		}

		var position = SourceEditor.SourceEditorPosition();
		var bPositionSet = false;

		if (sourceView.selectionController == nil) {
			position = sourceView.selection!.range.start;
			bPositionSet = true
			Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(sourceView, arg1, arg2);
			if (sourceView.selectionController == nil) {
				return;
			}
		}
		if (sourceView.selectionController!.selectionAnchor == nil) {
			position = sourceView.selection!.range.start;
			bPositionSet = true
			Call_SourceEditor_SourceEditorView_moveWordForwardAndModifySelection(sourceView, arg1, arg2);
			if (sourceView.selectionController!.selectionAnchor == nil) {
				return
			}
		}

		let anchor = sourceView.selectionController!.selectionAnchor!.start;
		let startPosition = sourceView.selection!.range.start;
		let endPosition = sourceView.selection!.range.end;

		if (!bPositionSet) {
			if (startPosition == anchor) {
				position = endPosition
			} else {
				position = startPosition
			}
		}

		var newPosition : SourceEditor.SourceEditorPosition = SourceEditor.SourceEditorPosition();
		if (forward) {
			newPosition = getNextWordPosition(sourceView.dataSource, fromPos: position);
		} else {
			newPosition = getPrevWordPosition(sourceView.dataSource, fromPos: position);
		}

		var range : SourceEditor.SourceEditorRange = SourceEditor.SourceEditorRange();
		if (newPosition > anchor) {
			range.start = anchor
			range.end = newPosition
		} else {
			range.start = newPosition
			range.end = anchor
		}

		sourceView.selectTextRange(range, scrollPlacement: nil, alwaysScroll: false)
	}
	@objc public class func moveWordForward(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!) {
		return moveWord(sourceView, forward: true);
	}

	@objc public class func moveWordBackward(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!) {
		return moveWord(sourceView, forward: false);
	}

	@objc public class func moveWordBackwardAndModifySelection(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!, arg2: Selector) {
		return moveWordAndModifySelection(sourceView, arg1: arg1, arg2: arg2, forward: false)
	}

	@objc public class func moveWordForwardAndModifySelection(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!, arg2: Selector) {
		return moveWordAndModifySelection(sourceView, arg1: arg1, arg2: arg2, forward: true)
	}

	@objc public class func deleteWordForward(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!) {
		return deleteWord(sourceView, forward: true);
	}

	@objc public class func deleteWordBackward(_ sourceView: SourceEditor.SourceEditorView, arg1 : Any!) {
		return deleteWord(sourceView, forward: false);
	}
}
