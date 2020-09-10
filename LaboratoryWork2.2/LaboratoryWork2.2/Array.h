#pragma once
#include <iostream>
#include "Functions.h"

using namespace std;

template <typename T>
class Array {
private:
	T *ArrayData;
	int Length;
private:
	Array<T>(int Length_) {
		ArrayData = new T[Length_ + 1];
		Length = Length_;
	}
public:
	Array<T>() {
		ArrayData = new T[1];
		Length = 0;
	}
	int GetLength() {
		return Length;
	}
	T Get(int Index) {
		if ((Index < 1) || (Index > Length)) {
			throw out_of_range("Out of range");
		}
		return ArrayData[Index];
	}
	void Change(int Index, T Item) {
		if ((Index < 1) || (Index > Length)) {
			throw out_of_range("Out of range");
		}
		ArrayData[Index] = Item;
	}
	void InsertAt(int Index, T Item) {
		if ((Index < 1) || (Index > Length + 1)) {
			throw out_of_range("Out of range");
		}
		T *NewArrayData = new T[Length + 2];
		for (int i = 1; i <= Index - 1; i++) {
			NewArrayData[i] = ArrayData[i];
		}
		NewArrayData[Index] = Item;
		for (int i = Index; i <= Length; i++) {
			NewArrayData[i + 1] = ArrayData[i];
		}
		delete[] ArrayData;
		ArrayData = NewArrayData;
		Length++;
	}
	void Remove(T Item) {
		int NewLength = Length;
		for (int i = 1; i <= Length; i++) {
			if (ArrayData[i] == Item) {
				NewLength--;
			}
		}
		T *NewArrayData = new T[NewLength + 1];
		for (int i = 1, j = 1; i <= Length; i++) {
			if (ArrayData[i] != Item) {
				NewArrayData[j] = ArrayData[i];
				j++;
			}
		}
		delete[] ArrayData;
		ArrayData = NewArrayData;
		Length = NewLength;
	}
	Array<T> *GetSubarray(int StartIndex, int EndIndex) {
		if ((StartIndex < 1) || (StartIndex > Length) || (EndIndex < 1) || (EndIndex > Length) || (StartIndex > EndIndex)) {
			throw out_of_range("Out of range");
		}
		Array<T> *Result = new Array<T>(EndIndex - StartIndex + 1);
		for (int i = StartIndex; i <= EndIndex; i++) {
			Result->ArrayData[i - StartIndex + 1] = ArrayData[i];
		}
		return Result;
	}
	string ArrayToString() {
		string Result;
		for (int i = 1; i <= Length; i++) {
			Result += ElementToString(ArrayData[i]) + " ";
		}
		return Result;
	}
	~Array<T>() {
		delete[] ArrayData;
		Length = 0;
	}
};