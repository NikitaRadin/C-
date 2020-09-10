#pragma once
#include <iostream>
#include <string>
#include "AdditionalDataTypes.h"

template <typename TItem>
class BinaryTree {
private:
	struct Node {
		TItem Item;
		Node *Left;
		Node *Right;
	};
	Node *Root;
	int Count;
private:
	Pair<bool, TItem> GetRecursive(Node *SubRoot, TItem Reference) {
		if (SubRoot != NULL) {
			if (Reference < SubRoot->Item) {
				return GetRecursive(SubRoot->Left, Reference);
			}
			else if (Reference > SubRoot->Item) {
				return GetRecursive(SubRoot->Right, Reference);
			}
			else {
				Pair<bool, TItem> Result = { true, SubRoot->Item };
				return Result;
			}
		}
		TItem *Auxiliary = NULL;
		Pair<bool, TItem> Result = { false, Null(Auxiliary) };
		return Result;
	}
	Node *AddRecursive(Node *SubRoot, TItem Item) {
		if (SubRoot == NULL) {
			SubRoot = new Node;
			SubRoot->Item = Item;
			SubRoot->Left = NULL;
			SubRoot->Right = NULL;
			if (Root == NULL) {
				Root = SubRoot;
			}
		}
		else if (Item < SubRoot->Item) {
			SubRoot->Left = AddRecursive(SubRoot->Left, Item);
		}
		else {
			SubRoot->Right = AddRecursive(SubRoot->Right, Item);
		}
		return SubRoot;
	}
	void BinaryTreeToStringRecursive(Node *pSource, std::string *pResult) {
		if (pSource != NULL) {
			BinaryTreeToStringRecursive(pSource->Left, pResult);
			*pResult += ItemToString(pSource->Item);
			BinaryTreeToStringRecursive(pSource->Right, pResult);
		}
	}
	void ClearRecursive(Node *SubRoot) {
		if (SubRoot != NULL) {
			ClearRecursive(SubRoot->Left);
			ClearRecursive(SubRoot->Right);
			delete SubRoot;
		}
	}
public:
	BinaryTree() {
		Root = NULL;
		Count = 0;
	}
	int GetCount() {
		return Count;
	}
	TItem Get(TItem Reference) {
		Pair<bool, TItem> Received = GetRecursive(Root, Reference);
		if (Received.Key == false) {
			throw std::out_of_range("Out of range");
		}
		return Received.Value;
	}
	void Add(TItem Item) {
		AddRecursive(Root, Item);
		Count++;
	}
	std::string BinaryTreeToString() {
		std::string Result = "";
		BinaryTreeToStringRecursive(Root, &Result);
		Result += "\n";
		return Result;
	}
	~BinaryTree() {
		ClearRecursive(Root);
		Count = 0;
	}
};