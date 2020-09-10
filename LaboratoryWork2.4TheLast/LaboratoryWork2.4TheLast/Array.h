#pragma once

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
			TItem *Data0 = new TItem[MaxLength];
			for (int i = 0; i <= Length - 1; i++) {
				Data0[i] = Data[i];
			}
			delete[] Data;
			Data = Data0;
		}
		for (int i = Length - 1; i >= Index; i--) {
			Data[i + 1] = Data[i];
		}
		Data[Index] = Item;
		Length++;
	}
	void Remove(TItem Item) {
		int Index = -1;
		for (int i = 0; i <= Length - 1; i++) {
			if (Data[i] == Item) {
				Index = i;
				break;
			}
		}
		if (Index == -1) {
			throw std::out_of_range("Out of range");
		}
		for (int i = Index + 1; i <= Length - 1; i++) {
			Data[i - 1] = Data[i];
		}
		Length--;
		if (Length <= MaxLength / 2 && Length != 0) {
			MaxLength /= 2;
			TItem *Data0 = new TItem[MaxLength];
			for (int i = 0; i <= Length - 1; i++) {
				Data0[i] = Data[i];
			}
			delete[] Data;
			Data = Data0;
		}
	}
	~Array0() {
		delete[] Data;
	}
};