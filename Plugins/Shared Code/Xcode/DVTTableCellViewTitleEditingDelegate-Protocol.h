//
//     Generated by class-dump 3.5 (64 bit).
//
//  Copyright (C) 1997-2019 Steve Nygard.
//

//
// SDK Root: /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk
//


@class DVTTableCellView;

@protocol DVTTableCellViewTitleEditingDelegate <NSObject>
- (void)titleDidChangeForTableCellView:(DVTTableCellView *)arg1;
- (struct _NSRange)initialSelectionRangeForTableCellView:(DVTTableCellView *)arg1 usingProposedRange:(struct _NSRange)arg2;

@optional
- (void)titleEditingDidAbortForTableCellView:(DVTTableCellView *)arg1;
- (BOOL)titleIsEditableForTableCellView:(DVTTableCellView *)arg1;
@end

