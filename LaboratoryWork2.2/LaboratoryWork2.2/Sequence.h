#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Sequence {
protected:
	int Length;
	bool IsEmpty;
public:
	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return IsEmpty;
	}
	virtual T GetFirst() = 0;
	virtual T GetLast() = 0;
	virtual T Get(int Index) = 0;
	virtual void Change(int Index, T Item) = 0;
	virtual void Append(T Item) = 0;
	virtual void Prepend(T Item) = 0;
	virtual void InsertAt(int Index, T Item) = 0;
	virtual void Remove(T Item) = 0;
	virtual Sequence<T> *GetSubsequence(int StartIndex, int EndIndex) = 0;
	virtual string SequenceToString() = 0;
};