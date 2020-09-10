#pragma once
#include <iostream>
#include "BinaryTree.h"
#include "Array.h"
#include "AdditionalDataTypes.h"

template <typename TKey, typename TValue>
class Dictionary {
protected:
	int Count;
public:
	Dictionary() {
		Count = 0;
	}
	int GetCount() {
		return Count;
	}
	virtual TValue Get(TKey Key) = 0;
	virtual bool ContainsKey(TKey Key) = 0;
	virtual void Add(TKey Key, TValue Value) = 0;
	//virtual void Remove(TKey Key) = 0;
	~Dictionary() {
		Count = 0;
	}
};

template <typename TKey, typename TValue>
class BinaryTreeDictionary : public Dictionary<TKey, TValue> {
private:
	BinaryTree<Pair<TKey, TValue>> *Data;
	Array0<TKey> *KeyArray;//А теперь нужно изменить построение гистограммы
public:
	BinaryTreeDictionary() : Dictionary<TKey, TValue>() {
		Data = new BinaryTree<Pair<TKey, TValue>>();
		KeyArray = new Array0<TKey>();
	}
	int GetCount() {
		return Data->GetCount();
	}
	TKey GetKey(int Index) {
		return KeyArray->Get(Index);
	}
	TValue Get(TKey Key) {
		TValue *Auxiliary = NULL;
		Pair<TKey, TValue> Reference = { Key, Null(Auxiliary) };
		Pair<TKey, TValue> Received = Data->Get(Reference);
		return Received.Value;
	}
	bool ContainsKey(TKey Key) {
		TValue *Auxiliary = NULL;
		Pair<TKey, TValue> Reference = { Key, Null(Auxiliary) };
		try {
			Pair<TKey, TValue> Found = Data->Get(Reference);
			return true;
		}
		catch (std::out_of_range Exception) {
			return false;
		}
	}
	void Add(TKey Key, TValue Value) {
		Pair<TKey, TValue> Item = { Key, Value };
		Data->Add(Item);
		KeyArray->InsertAt(KeyArray->GetLength(), Key);
		Dictionary<TKey, TValue>::Count++;
	};
	std::string BinaryDictionaryToString() {
		return Data->BinaryTreeToString();
	}
	~BinaryTreeDictionary() {
		delete Data;
		delete KeyArray;
	}
};