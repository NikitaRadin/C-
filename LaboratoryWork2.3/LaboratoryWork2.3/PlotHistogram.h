#pragma once
#include "SortedSequence.h"
#include "Dictionary.h"
#include "AdditionalDataTypes.h"

double UniformPartitionCoefficient(int NumberOfRange, int NumberOfRanges) {
	return (double)NumberOfRange / (double)NumberOfRanges;
}

template <typename TItem>
BinaryTreeDictionary<Range<TItem>, int> *PlotHistogram(SortedSequence<TItem> *Sequence, TItem Left, TItem Right, int NumberOfRanges, double(*Coefficient)(int, int), double LeftShare, double RightShare) {
	BinaryTreeDictionary<Range<TItem>, int> *Result = new BinaryTreeDictionary<Range<TItem>, int>();
	BinarySearch<TItem> *BinarySearchObject = new BinarySearch<TItem>();
	for (int i = 1; i <= NumberOfRanges; i++) {
		Range<TItem> SubItem = { (TItem)(Left + Coefficient(i - 1, NumberOfRanges) * (Right - Left)), (TItem)(Left + Coefficient(i, NumberOfRanges) * (Right - Left)) };
		Result->Add(SubItem, BinarySearchObject->Implementation(Sequence, SubItem.Left, SubItem.Right, LeftShare, RightShare));
	}
	return Result;
}