#pragma once
#include <iostream>
#include "Functions.h"

using namespace std;

template <typename T>
class List {
private:
	struct Element {
		T Data;
		Element *Previous;
		Element *Next;
	};
	Element *ListData;
	int Length;
private:
	Element *GetElement(int Index) {
		Element *Result = ListData;
		for (int i = 1; i <= Index; i++) {
			Result = Result->Next;
		}
		return Result;
	}
public:
	List<T>() {
		ListData = new Element;
		ListData->Previous = NULL;
		ListData->Next = NULL;
		Length = 0;
	};
	int GetLength() {
		return Length;
	}
	T Get(int Index) {
		if ((Index < 1) || (Index > Length)) {
			throw out_of_range("Out of range");
		}
		Element *Current = ListData;
		for (int i = 1; i <= Index; i++) {
			Current = Current->Next;
		}
		return Current->Data;
	}
	void Change(int Index, T Item) {
		if ((Index < 1) || (Index > Length)) {
			throw out_of_range("Out of range");
		}
		Element *Current = ListData;
		for (int i = 1; i <= Index; i++) {
			Current = Current->Next;
		}
		Current->Data = Item;
	}
	void InsertAt(int Index, T Item) {
		if ((Index < 1) || (Index > Length + 1)) {
			throw out_of_range("Out of range");
		}
		Element *Current = ListData;
		for (int i = 1; i <= Index - 1; i++) {
			Current = Current->Next;
		}
		Element *NewElement = new Element;
		NewElement->Data = Item;
		NewElement->Previous = Current;
		NewElement->Next = Current->Next;
		Current->Next = NewElement;
		if (NewElement->Next != NULL) {
			NewElement->Next->Previous = NewElement;
		}
		Length++;
	}
	void Remove(T Item) {
		Element *Current = ListData;
		Element *Copy;
		for (int i = 1; i <= Length; i++) {
			if (Current->Next->Data == Item) {
				Copy = Current->Next;
				Current->Next = Current->Next->Next;
				if (Current->Next != NULL) {
					Current->Next->Previous = Current;
				}
				delete Copy;
				Length--;
			}
			Current = Current->Next;
		}
	}
	List<T> *GetSublist(int StartIndex, int EndIndex) {
		if ((StartIndex < 1) || (StartIndex > Length) || (EndIndex < 1) || (EndIndex > Length) || (StartIndex > EndIndex)) {
			throw out_of_range("Out of range");
		}
		List<T> *Result = new List<T>();
		Element *Current = ListData;
		for (int i = 1; i <= StartIndex; i++) {
			Current = Current->Next;
		}
		for (int i = StartIndex; i <= EndIndex; i++) {
			Result->InsertAt(i - StartIndex + 1, Current->Data);
			Current = Current->Next;
		}
		return Result;
	}
	string ListToString() {
		string Result;
		Element *Current = ListData->Next;
		for (int i = 1; i <= Length; i++) {
			Result += ElementToString(Current->Data) + " ";
			Current = Current->Next;
		}
		return Result;
	}
	~List<T>() {
		Element *Current = ListData;
		Element *Copy;
		for (int i = 0; i <= Length; i++) {
			Copy = Current->Next;
			delete Current;
			Current = Copy;
		}
		Length = 0;
	}
};