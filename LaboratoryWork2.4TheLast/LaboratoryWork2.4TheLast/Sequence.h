#pragma once
#include "Array.h"

template <typename TItem>
class Sequence {
protected:
	int Length;
public:
	int GetLength() {
		return Length;
	}
	bool GetIsEmpty() {
		return Length == 0;
	}
	virtual TItem GetFirst() = 0;
	virtual TItem GetLast() = 0;
	virtual TItem Get(int Index) = 0;
	virtual int IndexOf(TItem Item) = 0;
	virtual void Append(TItem Item) = 0;
	virtual void Prepend(TItem Item) = 0;
	virtual void InsertAt(int Index, TItem Item) = 0;
	virtual void Remove(TItem Item) = 0;
	virtual Sequence<TItem> *GetSubsequence(int StartIndex, int EndIndex) = 0;
};

template <typename TItem>
class ArraySequence : public Sequence<TItem> {
private:
	Array0<TItem> *Data;
public:
	ArraySequence() : Sequence<TItem>() {
		Data = new Array0<TItem>();
		Sequence<TItem>::Length = 0;
	}
	TItem GetFirst() {
		return Data->Get(0);
	}
	TItem GetLast() {
		return Data->Get(Sequence<TItem>::Length - 1);
	}
	TItem Get(int Index) {
		return Data->Get(Index);
	}
	int IndexOf(TItem Item) {
		for (int i = 0; i <= Sequence<TItem>::Length - 1; i++) {
			if (Data->Get(i) == Item) {
				return i;
			}
		}
		return -1;
	}
	void Append(TItem Item) {
		Data->InsertAt(Sequence<TItem>::Length, Item);
		Sequence<TItem>::Length++;
	}
	void Prepend(TItem Item) {
		Data->InsertAt(0, Item);
		Sequence<TItem>::Length++;
	}
	void InsertAt(int Index, TItem Item) {
		Data->InsertAt(Index, Item);
		Sequence<TItem>::Length++;
	}
	void Remove(TItem Item) {
		Data->Remove(Item);
		Sequence<TItem>::Length--;
	}
	ArraySequence<TItem> *GetSubsequence(int StartIndex, int EndIndex) {
		ArraySequence<TItem> *Result = new ArraySequence<TItem>();
		for (int i = StartIndex; i <= EndIndex; i++) {
			Result->Append(Data->Get(i));
		}
		return Result;
	}
	~ArraySequence() {
		delete Data;
	}
};

template <typename TItem, typename TPriority>
class ArrayPriorityQueuePair {
private:
	TItem Item;
	TPriority Priority;
public:
	ArrayPriorityQueuePair() {
	}
	ArrayPriorityQueuePair(TItem Item0, TPriority Priority0) {
		Item = Item0;
		Priority = Priority0;
	}
	TItem GetItem() {
		return Item;
	}
	TPriority GetPriority() {
		return Priority;
	}
	bool operator ==(ArrayPriorityQueuePair Second) {
		return Item == Second.Item && Priority == Second.Priority;
	}
	~ArrayPriorityQueuePair() {
	}
};

template <typename TItem, typename TPriority>
class ArrayPriorityQueue : private ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>> {
public:
	ArrayPriorityQueue() : ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>() {
	}
	int PeekLength() {
		return Sequence<ArrayPriorityQueuePair<TItem, TPriority>>::GetLength();
	}
	bool PeekIsEmpty() {
		return Sequence<ArrayPriorityQueuePair<TItem, TPriority>>::GetIsEmpty();
	}
	TItem PeekFirst() {
		return ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::GetFirst().GetItem();
	}
	TItem PeekLast() {
		return ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::GetLast().GetItem();
	}
	TItem Peek(int Index) {
		return ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Get(Index).GetItem();
	}
	TPriority PeekPriority(int Index) {
		return ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Get(Index).GetPriority();
	}
	void Enqueue(TItem Item, TPriority Priority) {
		//cout << "Test" << endl;
		int Index = 0;
		for (int i = 0; i <= Sequence<ArrayPriorityQueuePair<TItem, TPriority>>::Length - 1; i++) {
			if (Priority < ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Get(i).GetPriority()) {
				break;
			}
			Index++;
		}
		ArrayPriorityQueuePair<TItem, TPriority> *Item0 = new ArrayPriorityQueuePair<TItem, TPriority>(Item, Priority);
		ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::InsertAt(Index, *Item0);
	}
	TItem Dequeue() {
		TItem Result = ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Get(0).GetItem();
		ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Remove(ArraySequence<ArrayPriorityQueuePair<TItem, TPriority>>::Get(0));
		return Result;
	}
	~ArrayPriorityQueue() {
	}
};