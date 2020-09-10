#pragma once
#include "Sequence.h"
#include "Sort.h"

#include <ctime>

template <typename T>
class QuickSort : public Sort<T> {
private:
	void QuickSortRecursive(Sequence<T> *Source, int Left, int Right) {
		int Pivot = Left;
		T Copy;
		int LeftCopy = Left;
		int RightCopy = Right;
		while (Left != Right) {
			while ((Source->Get(Left) <= Source->Get(Pivot)) && (Left != Right)) {
				Left++;
			}
			while ((Source->Get(Right) >= Source->Get(Pivot)) && (Left != Right)) {
				Right--;
			}
			if (Left != Right) {
				Copy = Source->Get(Left);
				Source->Change(Left, Source->Get(Right));
				Source->Change(Right, Copy);
			}
			else if (Source->Get(Left) >= Source->Get(Pivot)) {
				Copy = Source->Get(Pivot);
				Source->Change(Pivot, Source->Get(Left - 1));
				Source->Change(Left - 1, Copy);
				Pivot = Left - 1;
			}
			else {
				Copy = Source->Get(Pivot);
				Source->Change(Pivot, Source->Get(Left));
				Source->Change(Left, Copy);
				Pivot = Left;
			}
		}
		Left = LeftCopy;
		Right = RightCopy;
		if ((Left != Pivot) && (Left != Pivot - 1)) {
			QuickSortRecursive(Source, Left, Pivot - 1);
		}
		if ((Right != Pivot) && (Right != Pivot + 1)) {
			QuickSortRecursive(Source, Pivot + 1, Right);
		}
	}
public:
	Sequence<T> *Implementation(Sequence<T> *Source) {
		Sequence<T> *Result = Source->GetSubsequence(1, Source->GetLength());
		QuickSortRecursive(Result, 1, Result->GetLength());
		return Result;
	}
};