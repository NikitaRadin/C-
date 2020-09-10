#pragma once
#include "List.h"
#include "Sequence.h"

template <typename T>
class ListSequence : public Sequence<T> {
private:
	List<T> *SequenceData;
public:
	ListSequence() : Sequence<T>() {
		SequenceData = new List<T>();
		Sequence<T>::Length = 0;
		Sequence<T>::IsEmpty = true;
	}
	ListSequence(List<T> *Source) : Sequence<T>() {
		SequenceData = Source;
		Sequence<T>::Length = Source->GetLength();
		Sequence<T>::IsEmpty = (Source->GetLength() == 0);
	}
	T GetFirst() {
		return SequenceData->Get(1);
	}
	T GetLast() {
		return SequenceData->Get(Sequence<T>::Length);
	}
	T Get(int Index) {
		return SequenceData->Get(Index);
	}
	void Change(int Index, T Item) {
		SequenceData->Change(Index, Item);
	}
	void Append(T Item) {
		SequenceData->InsertAt(Sequence<T>::Length + 1, Item);
		Sequence<T>::Length++;
		Sequence<T>::IsEmpty = false;
	}
	void Prepend(T Item) {
		SequenceData->InsertAt(1, Item);
		Sequence<T>::Length++;
		Sequence<T>::IsEmpty = false;
	}
	void InsertAt(int Index, T Item) {
		SequenceData->InsertAt(Index, Item);
		Sequence<T>::Length++;
		Sequence<T>::IsEmpty = false;
	}
	void Remove(T Item) {
		SequenceData->Remove(Item);
		Sequence<T>::Length = SequenceData->GetLength();
		if (Sequence<T>::Length == 0) {
			Sequence<T>::IsEmpty = true;
		}
	}
	ListSequence<T> *GetSubsequence(int StartIndex, int EndIndex) {
		ListSequence<T> *Result = new ListSequence<T>(SequenceData->GetSublist(StartIndex, EndIndex));
		return Result;
	}
	string SequenceToString() {
		string Result = SequenceData->ListToString();
		return Result;
	}
	~ListSequence() {
		delete SequenceData;
		Sequence<T>::Length = 0;
		Sequence<T>::IsEmpty = true;
	}
};