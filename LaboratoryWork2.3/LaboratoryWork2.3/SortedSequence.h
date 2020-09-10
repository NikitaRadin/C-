#pragma once
#include <iostream>
#include "Array.h"

template <typename TItem>
class SortedSequence {
protected:
	int Length;
public:
	SortedSequence() {
		Length = 0;
	}
	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return (Length == 0);
	}
	virtual TItem GetFirst() = 0;
	virtual TItem GetLast() = 0;
	virtual TItem Get(int Index) = 0;
	virtual int IndexOf(TItem Item) = 0;
	virtual void Add(TItem Item) = 0;
	virtual SortedSequence<TItem> *GetSubsequence(int StartIndex, int EndIndex) = 0;
	~SortedSequence() {
		Length = 0;
	}
};

template <typename TItem>
class ArraySortedSequence : public SortedSequence<TItem> {
private:
	Array0<TItem> *Data;
public:
	ArraySortedSequence() : SortedSequence<TItem>() {
		Data = new Array0<TItem>();
	}
	TItem GetFirst() {
		return Data->Get(0);
	}
	TItem GetLast() {
		return Data->Get(SortedSequence<TItem>::Length - 1);
	}
	TItem Get(int Index) {
		return Data->Get(Index);
	}
	int IndexOf(TItem Item) {
		for (int i = 0; i <= SortedSequence<TItem>::Length - 1; i++) {
			if (Data->Get(i) == Item) {
				return i;
			}
		}
		return -1;
	}
	void Add(TItem Item) {
		int Index = 0;
		for (int i = 0; i <= SortedSequence<TItem>::Length - 1; i++) {
			if (Item <= Data->Get(i)) {
				break;
			}
			Index++;
		}
		Data->InsertAt(Index, Item);
		SortedSequence<TItem>::Length++;
	}
	ArraySortedSequence<TItem> *GetSubsequence(int StartIndex, int EndIndex) {
		ArraySortedSequence<TItem> *Result = new ArraySortedSequence<TItem>();
		for (int i = EndIndex; i >= StartIndex; i--) {
			Result->Add(Data->Get(i));
		}
		return Result;
	}
	~ArraySortedSequence() {
		delete Data;
	}
};

template<typename TItem>
class BinarySearch {
private:
	void BinarySearchRecursive(SortedSequence<TItem> *Sequence, int Left, int Right, TItem LeftReference, TItem RightReference, double LeftShare, double RightShare, int *Result) {
		if (Left <= Right) {
			int Middle = (int)((Left * RightShare + Right * LeftShare) / (LeftShare + RightShare));
			if (RightReference < Sequence->Get(Middle)) {
				BinarySearchRecursive(Sequence, Left, Middle - 1, LeftReference, RightReference, LeftShare, RightShare, Result);
			}
			else if (LeftReference >= Sequence->Get(Middle)) {
				BinarySearchRecursive(Sequence, Middle + 1, Right, LeftReference, RightReference, LeftShare, RightShare, Result);
			}
			else {
				(*Result)++;
				BinarySearchRecursive(Sequence, Left, Middle - 1, LeftReference, RightReference, LeftShare, RightShare, Result);
				BinarySearchRecursive(Sequence, Middle + 1, Right, LeftReference, RightReference, LeftShare, RightShare, Result);
			}
		}
	}
public:
	int Implementation(SortedSequence<TItem> *Sequence, TItem LeftReference, TItem RightReference, double LeftShare, double RightShare) {
		if ((LeftShare <= 0) || (RightShare <= 0)) {
			throw std::out_of_range("Out of range");
		}
		int Result = 0;
		BinarySearchRecursive(Sequence, 0, Sequence->GetLength() - 1, LeftReference, RightReference, LeftShare, RightShare, &Result);
		return Result;
	}
};