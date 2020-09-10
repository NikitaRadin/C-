#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "Sequence.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "Interface.h"

using namespace std;

template <typename T>
ArraySequence<T> *GenerateArraySequence(int Length, int Range) {
	ArraySequence<T> *Result = new ArraySequence<T>();
	for (int i = 1; i <= Length; i++) {
		Result->Append(Random(Range));
	}
	return Result;
}

template <typename T>
ListSequence<T> *GenerateListSequence(int Length, int Range) {
	ListSequence<T> *Result = new ListSequence<T>();
	for (int i = 1; i <= Length; i++) {
		Result->Append(Random(Range));
	}
	return Result;
}

bool IsInt(string Source) {
	int n = Source.size();
	for (int i = 0; i < n; i++) {
		if (Source[i] < 48 || Source[i] > 57) {
			return false;
		}
	}
	return true;
}

void CompareAlgorithms(int Length, int Range) {
	ArraySequence<int> *S1 = new ArraySequence<int>();
	ArraySequence<int> *S2 = new ArraySequence<int>();
	ArraySequence<int> *S3 = new ArraySequence<int>();
	ListSequence<int> *S4 = new ListSequence<int>();
	ListSequence<int> *S5 = new ListSequence<int>();
	ListSequence<int> *S6 = new ListSequence<int>();
	for (int i = 1; i <= Length; i++) {
		S1->Append(i);
		S2->Prepend(i);
		S3->Append(Random(Range));
		S4->Append(i);
		S5->Prepend(i);
		S6->Append(Random(Range));
	}
	QuickSort<int> *QuickSorter = new QuickSort<int>();
	ShellSort<int> *ShellSorter = new ShellSort<int>();
	int ST, ET;
	cout << "The sequence is sorted in direct order:" << endl;

	ST = clock();
	QuickSorter->Implementation(S1);
	ET = clock();
	cout << "	ArraySequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S1);
	ET = clock();
	cout << "	ArraySequence, Shell sort:" << ET - ST << " ms" << endl;

	ST = clock();
	QuickSorter->Implementation(S4);
	ET = clock();
	cout << "	ListSequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S4);
	ET = clock();
	cout << "	ListSequence, Shell sort:" << ET - ST << " ms" << endl;

	cout << endl;

	cout << "The sequence is sorted in reverse order:" << endl;

	ST = clock();
	QuickSorter->Implementation(S2);
	ET = clock();
	cout << "	ArraySequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S2);
	ET = clock();
	cout << "	ArraySequence, Shell sort:" << ET - ST << " ms" << endl;

	ST = clock();
	QuickSorter->Implementation(S5);
	ET = clock();
	cout << "	ListSequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S5);
	ET = clock();
	cout << "	ListSequence, Shell sort:" << ET - ST << " ms" << endl;

	cout << endl;

	cout << "The sequence is not sorted:" << endl;

	ST = clock();
	QuickSorter->Implementation(S3);
	ET = clock();
	cout << "	ArraySequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S3);
	ET = clock();
	cout << "	ArraySequence, Shell sort:" << ET - ST << " ms" << endl;

	ST = clock();
	QuickSorter->Implementation(S6);
	ET = clock();
	cout << "	ListSequence, Quick sort:" << ET - ST << " ms" << endl;

	ST = clock();
	ShellSorter->Implementation(S6);
	ET = clock();
	cout << "	ListSequence, Shell sort:" << ET - ST << " ms" << endl;

	cout << endl;
}

template <typename T>
void Interface() {

	string Length;
L1:
	cout << "Enter the length of the sequence:" << endl;
	cin >> Length;
	cout << endl;
	if (!IsInt(Length)) {
		if (Length == "Stop") {
			exit(0);
		}
		cout << "Invalid length value" << endl;
		cout << endl;
		goto L1;
	}

	string Range;
L2:
	cout << "Enter the range of values:" << endl;
	cin >> Range;
	cout << endl;
	if (!IsInt(Range)) {
		if (Length == "Stop") {
			exit(0);
		}
		cout << "Invalid range value" << endl;
		cout << endl;
		goto L2;
	}

	string a;
L3:
	cout << "Select the sequence type:" << endl;
	cout << "	ArraySequence" << endl;
	cout << "	ListSequence" << endl;
	cout << endl;
	cin >> a;
	cout << endl;
	Sequence<T> *S;
	if (a == "ArraySequence") {
		S = GenerateArraySequence<T>(atoi(Length.c_str()), atoi(Range.c_str()));
	}
	else if (a == "ListSequence") {
		S = GenerateListSequence<T>(atoi(Length.c_str()), atoi(Range.c_str()));
	}
	else if (a == "Stop") {
		exit(0);
	}
	else {
		cout << "Invalid sequence type" << endl;
		cout << endl;
		goto L3;
	}

	string b;
L4:
	cout << "Select the sorting algorithm:" << endl;
	cout << "	QuickSort" << endl;
	cout << "	ShellSort" << endl;
	cout << endl;
	cin >> b;
	cout << endl;
	Sequence<T> *S1;
	if (b == "QuickSort") {
		QuickSort<T> *Sorter = new QuickSort<T>();
		int StartTime = clock();
		S1 = Sorter->Implementation(S);
		int EndTime = clock();
		cout << EndTime - StartTime << " ms" << endl << endl;
		delete S;
		delete S1;
	}
	else if (b == "ShellSort") {
		ShellSort<T> *Sorter = new ShellSort<T>();
		int StartTime = clock();
		S1 = Sorter->Implementation(S);
		int EndTime = clock();
		cout << EndTime - StartTime << " ms" << endl << endl;
		delete S;
		delete S1;
	}
	else if (b == "Stop") {
		exit(0);
	}
	else {
		cout << "Invalid sorting algorithm" << endl;
		cout << endl;
		goto L4;
	}

}