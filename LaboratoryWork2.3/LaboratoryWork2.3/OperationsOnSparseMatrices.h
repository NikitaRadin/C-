#pragma once
#include "AdditionalDataTypes.h"
#include "Dictionary.h"

#include <ctime>

BinaryTreeDictionary<IndexCouple, int> *LinearCombination(int *Time, BinaryTreeDictionary<IndexCouple, int> *Source1, int A, BinaryTreeDictionary<IndexCouple, int> *Source2, int B) {
	BinaryTreeDictionary<IndexCouple, int> *Result = new BinaryTreeDictionary<IndexCouple, int>();
	IndexCouple Key;
	int Value;
	int StartTime;
	int EndTime;
	StartTime = clock();
	for (int i = 0; i <= Source1->GetCount() - 1; i++) {
		Key = Source1->GetKey(i);
		try {
			Source2->Get(Key);
			Value = A * Source1->Get(Key) + B * Source2->Get(Key);
			Result->Add(Key, Value);
		}
		catch (std::out_of_range Exception) {
			Value = A * Source1->Get(Key);
			Result->Add(Key, Value);
		}
	}
	EndTime = clock();
	*Time = EndTime - StartTime;
	for (int i = 0; i <= Source2->GetCount() - 1; i++) {
		Key = Source2->GetKey(i);
		try {
			Source1->Get(Key);
		}
		catch (std::out_of_range Exception) {
			Value = B * Source2->Get(Key);
			Result->Add(Key, Value);
		}
	}
	return Result;
}