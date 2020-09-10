#pragma once
#include <iostream>

template <typename TItem>
class Array0 {
private:
	TItem *Data;
	int Length;
	int MaxLength;
public:
	Array0() {
		MaxLength = 1;
		Data = new TItem[MaxLength];
		Length = 0;
	}
	int GetLength() {
		return Length;
	}
	TItem Get(int Index) {
		if ((Index < 0) || (Index > Length - 1)) {
			throw std::out_of_range("Out of range");
		}
		return Data[Index];
	}
	void InsertAt(int Index, TItem Item) {
		if ((Index < 0) || (Index > Length)) {
			throw std::out_of_range("Out of range");
		}
		if (Length + 1 > MaxLength) {
			MaxLength *= 2;
			TItem *NewArrayData = new TItem[MaxLength];
			for (int i = 0; i <= Length - 1; i++) {
				NewArrayData[i] = Data[i];
			}
			delete[] Data;
			Data = NewArrayData;
		}
		for (int i = Length - 1; i >= Index; i--) {
			Data[i + 1] = Data[i];
		}
		Data[Index] = Item;
		Length++;
	}
	~Array0() {
		delete[] Data;
		Length = 0;
		MaxLength = 1;
	}
};