#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Functions.h"
#include "ArraySequence.h"
#include "ListSequence.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "Tests.h"

void ArraySequenceTest() {
	bool Success = true;
	ArraySequence<int> *TestArraySequence = new ArraySequence<int>();
	Success &= (TestArraySequence->GetLength() == 0);//0
	TestArraySequence->Append(23);
	Success &= (TestArraySequence->GetLength() == 1);//1
	Success &= (TestArraySequence->GetFirst() == 23);//23
	Success &= (TestArraySequence->GetLast() == 23);//23
	Success &= (TestArraySequence->Get(1) == 23);//23
	try {
		TestArraySequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestArraySequence->Get(2);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	TestArraySequence->Append(43);
	Success &= (TestArraySequence->GetLength() == 2);//2
	Success &= (TestArraySequence->GetFirst() == 23);//23
	Success &= (TestArraySequence->GetLast() == 43);//43
	Success &= (TestArraySequence->Get(1) == 23);//23
	Success &= (TestArraySequence->Get(2) == 43);//43
	try {
		TestArraySequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestArraySequence->Get(3);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	TestArraySequence->Prepend(53);
	Success &= (TestArraySequence->GetLength() == 3);//3
	Success &= (TestArraySequence->GetFirst() == 53);//53
	Success &= (TestArraySequence->GetLast() == 43);//43
	Success &= (TestArraySequence->Get(1) == 53);//53
	Success &= (TestArraySequence->Get(2) == 23);//23
	try {
		TestArraySequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestArraySequence->Get(4);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	ArraySequence<int> *TestArraySubsequence = TestArraySequence->GetSubsequence(2, 2);
	Success &= (TestArraySubsequence->GetLength() == 1);//1
	Success &= (TestArraySubsequence->GetFirst() == 23);//23
	Success &= (TestArraySubsequence->GetLast() == 23);//23
	if (Success) {
		cout << "ArraySequenceTest has been successfully completed" << endl << endl;
	}
	else {
		cout << "ArraySequenceTest has been unsuccessfully completed" << endl << endl;
	}
	delete TestArraySequence;
	delete TestArraySubsequence;
}

void ListSequenceTest() {
	bool Success = true;
	ListSequence<int> *TestListSequence = new ListSequence<int>();
	Success &= (TestListSequence->GetLength() == 0);//0
	TestListSequence->Append(23);
	Success &= (TestListSequence->GetLength() == 1);//1
	Success &= (TestListSequence->GetFirst() == 23);//23
	Success &= (TestListSequence->GetLast() == 23);//23
	Success &= (TestListSequence->Get(1) == 23);//23
	try {
		TestListSequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestListSequence->Get(2);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	TestListSequence->Append(43);
	Success &= (TestListSequence->GetLength() == 2);//2
	Success &= (TestListSequence->GetFirst() == 23);//23
	Success &= (TestListSequence->GetLast() == 43);//43
	Success &= (TestListSequence->Get(1) == 23);//23
	Success &= (TestListSequence->Get(2) == 43);//43
	try {
		TestListSequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestListSequence->Get(3);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	TestListSequence->Prepend(53);
	Success &= (TestListSequence->GetLength() == 3);//3
	Success &= (TestListSequence->GetFirst() == 53);//53
	Success &= (TestListSequence->GetLast() == 43);//43
	Success &= (TestListSequence->Get(1) == 53);//53
	Success &= (TestListSequence->Get(2) == 23);//23
	try {
		TestListSequence->Get(0);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	try {
		TestListSequence->Get(4);
		Success = false;
	}
	catch (out_of_range Error) {
	}
	ListSequence<int> *TestListSubsequence = TestListSequence->GetSubsequence(2, 2);
	Success &= (TestListSubsequence->GetLength() == 1);//1
	Success &= (TestListSubsequence->GetFirst() == 23);//23
	Success &= (TestListSubsequence->GetLast() == 23);//23
	if (Success) {
		cout << "ListSequenceTest has been successfully completed" << endl << endl;
	}
	else {
		cout << "ListSequenceTest has been unsuccessfully completed" << endl << endl;
	}
	delete TestListSequence;
	delete TestListSubsequence;
}

void QuickSortArraySequenceTest() {
	bool Success = true;
	ArraySequence<int> *TestArraySequence = new ArraySequence<int>();
	for (int i = 1; i <= 1000; i++) {
		TestArraySequence->Append(rand() % 10000 + 1);
	}
	//cout << "The initial sequence has the form:" << endl;
	//cout << TestArraySequence->SequenceToString() << endl << endl;
	QuickSort<int> *Sort = new QuickSort<int>;
	unsigned int StartTime = clock();
	ArraySequence<int> *SortedTestArraySequence = (ArraySequence<int> *)Sort->Implementation(TestArraySequence);
	unsigned int EndTime = clock();
	ofstream f;
	f.open("File.txt");
	f << TestArraySequence->SequenceToString() << endl;
	f << SortedTestArraySequence->SequenceToString() << endl;
	f.close();
	//cout << "The sorted sequence has the form:" << endl;
	//cout << SortedTestArraySequence->SequenceToString() << endl << endl;
	for (int i = 1; i <= SortedTestArraySequence->GetLength() - 1; i++) {
		if (SortedTestArraySequence->Get(i) > SortedTestArraySequence->Get(i + 1)) {
			Success = false;
			break;
		}
	}
	if (Success) {
		cout << "QuickSortArraySequenceTest has been successfully completed" << endl;
		cout << "The execution time of the algorithm was: " << EndTime - StartTime << " ms" << endl << endl;
	}
	else {
		cout << "QuickSortArraySequenceTest has been unsuccessfully completed" << endl << endl;
	}
	//cout << "________________________________________________________________" << endl << endl;
	delete TestArraySequence;
	delete Sort;
	delete SortedTestArraySequence;
}

void QuickSortListSequenceTest() {
	bool Success = true;
	ListSequence<int> *TestListSequence = new ListSequence<int>();
	for (int i = 1; i <= 1000; i++) {
		TestListSequence->Append(rand() % 10000 + 1);
	}
	//cout << "The initial sequence has the form:" << endl;
	//cout << TestListSequence->SequenceToString() << endl << endl;
	QuickSort<int> *Sort = new QuickSort<int>;
	unsigned int StartTime = clock();
	ListSequence<int> *SortedTestListSequence = (ListSequence<int> *)Sort->Implementation(TestListSequence);
	unsigned int EndTime = clock();
	ofstream f;
	f.open("File.txt");
	f << TestListSequence->SequenceToString() << endl;
	f << SortedTestListSequence->SequenceToString() << endl;
	f.close();
	//cout << "The sorted sequence has the form:" << endl;
	//cout << SortedTestListSequence->SequenceToString() << endl << endl;
	for (int i = 1; i <= SortedTestListSequence->GetLength() - 1; i++) {
		if (SortedTestListSequence->Get(i) > SortedTestListSequence->Get(i + 1)) {
			Success = false;
			break;
		}
	}
	if (Success) {
		cout << "QuickSortListSequenceTest has been successfully completed" << endl;
		cout << "The execution time of the algorithm was: " << EndTime - StartTime << " ms" << endl << endl;
	}
	else {
		cout << "QuickSortListSequenceTest has been unsuccessfully completed" << endl << endl;
	}
	//cout << "________________________________________________________________" << endl << endl;
	delete TestListSequence;
	delete Sort;
	delete SortedTestListSequence;
}

void ShellSortArraySequenceTest() {
	bool Success = true;
	ArraySequence<int> *TestArraySequence = new ArraySequence<int>();
	for (int i = 1; i <= 1000; i++) {
		TestArraySequence->Append(rand() % 10000 + 1);
	}
	//cout << "The initial sequence has the form:" << endl;
	//cout << TestArraySequence->SequenceToString() << endl << endl;
	ShellSort<int> *Sort = new ShellSort<int>;
	unsigned int StartTime = clock();
	ArraySequence<int> *SortedTestArraySequence = (ArraySequence<int> *)Sort->Implementation(TestArraySequence);
	unsigned int EndTime = clock();
	ofstream f;
	f.open("File.txt");
	f << TestArraySequence->SequenceToString() << endl;
	f << SortedTestArraySequence->SequenceToString() << endl;
	f.close();
	//cout << "The sorted sequence has the form:" << endl;
	//cout << SortedTestArraySequence->SequenceToString() << endl << endl;
	for (int i = 1; i <= SortedTestArraySequence->GetLength() - 1; i++) {
		if (SortedTestArraySequence->Get(i) > SortedTestArraySequence->Get(i + 1)) {
			Success = false;
			break;
		}
	}
	if (Success) {
		cout << "ShellSortArraySequenceTest has been successfully completed" << endl;
		cout << "The execution time of the algorithm was: " << EndTime - StartTime << " ms" << endl << endl;
	}
	else {
		cout << "ShellSortArraySequenceTest has been unsuccessfully completed" << endl << endl;
	}
	//cout << "________________________________________________________________" << endl << endl;
	delete TestArraySequence;
	delete Sort;
	delete SortedTestArraySequence;
}

void ShellSortListSequenceTest() {
	bool Success = true;
	ListSequence<int> *TestListSequence = new ListSequence<int>();
	for (int i = 1; i <= 1000; i++) {
		TestListSequence->Append(rand() % 10000 + 1);
	}
	//cout << "The initial sequence has the form:" << endl;
	//cout << TestListSequence->SequenceToString() << endl << endl;
	ShellSort<int> *Sort = new ShellSort<int>;
	unsigned int StartTime = clock();
	ArraySequence<int> *SortedTestListSequence = (ArraySequence<int> *)Sort->Implementation(TestListSequence);
	unsigned int EndTime = clock();
	ofstream f;
	f.open("File.txt");
	f << TestListSequence->SequenceToString() << endl;
	f << SortedTestListSequence->SequenceToString() << endl;
	f.close();
	//cout << "The sorted sequence has the form:" << endl;
	//cout << SortedTestListSequence->SequenceToString() << endl << endl;
	for (int i = 1; i <= SortedTestListSequence->GetLength() - 1; i++) {
		if (SortedTestListSequence->Get(i) > SortedTestListSequence->Get(i + 1)) {
			Success = false;
			break;
		}
	}
	if (Success) {
		cout << "ShellSortListSequenceTest has been successfully completed" << endl;
		cout << "The execution time of the algorithm was: " << EndTime - StartTime << " ms" << endl << endl;
	}
	else {
		cout << "ShellSortListSequenceTest has been unsuccessfully completed" << endl << endl;
	}
	//cout << "________________________________________________________________" << endl << endl;
	delete TestListSequence;
	delete Sort;
	delete SortedTestListSequence;
}