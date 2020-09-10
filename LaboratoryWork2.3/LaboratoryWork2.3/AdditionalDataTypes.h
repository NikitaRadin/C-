#pragma once
#include <string>

template <typename TKey, typename TValue>
struct Pair {
	TKey Key;
	TValue Value;
	bool operator < (Pair Second) {
		if (Key < Second.Key) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator > (Pair Second) {
		if (Key > Second.Key) {
			return true;
		}
		else {
			return false;
		}
	}
};

template <typename TItem>
struct Range {
	TItem Left;
	TItem Right;
	bool operator < (Range Second) {
		if (!((Left == Second.Left) && (Right == Second.Right))) {
			if (Right <= Second.Left) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	bool operator > (Range Second) {
		if (!((Left == Second.Left) && (Right == Second.Right))) {
			if (Left >= Second.Right) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

struct IndexCouple {
	int i;
	int j;
	bool operator < (IndexCouple Second) {
		/*if ((i + j < Second.i + Second.j) || ((i + j == Second.i + Second.j) && (i < Second.i))) {
			return true;
		}
		else {
			return false;
		}*/
		return ((i + j < Second.i + Second.j) || ((i + j == Second.i + Second.j) && (i < Second.i)));
	}
	bool operator > (IndexCouple Second) {
		/*if ((i + j > Second.i + Second.j) || ((i + j == Second.i + Second.j) && (i > Second.i))) {
			return true;
		}
		else {
			return false;
		}*/
		return ((i + j > Second.i + Second.j) || ((i + j == Second.i + Second.j) && (i > Second.i)));
	}
};

int Null(int *) {
	return 0;
};

Pair<Range<int>, int> Null(Pair<Range<int>, int> *) {
	Range<int> Auxiliary = { 0, 0 };
	Pair<Range<int>, int> Result = { Auxiliary, 0 };
	return Result;
}

Pair<IndexCouple, int> Null(Pair<IndexCouple, int> *) {
	IndexCouple Auxiliary = { -1, -1 };
	Pair<IndexCouple, int> Result = { Auxiliary, 0 };
	return Result;
}

std::string ItemToString(Pair<IndexCouple, int> Source) {
	std::string Result = "(" + std::to_string(Source.Key.i) + ", " + std::to_string(Source.Key.j) + " -> " + std::to_string(Source.Value) + ")\n";
	return Result;
}

int Random0(int Range, int *Auxiliary) {//Дописать
	return (1 + (rand() * rand()) % Range);
}

int FibonacciNumber(int FibonacciNumberIndex) {
	if (FibonacciNumberIndex < 1) {
		throw std::out_of_range("Out of range");
	}
	int Previous = 1;
	int Result = 1;
	for (int i = 3; i <= FibonacciNumberIndex; i++) {
		Result = Previous + Result;
		Previous = Result - Previous;
	}
	return Result;
}