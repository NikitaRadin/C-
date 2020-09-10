#pragma once
#include "Sequence.h"
#include "Sort.h"
//#include <ctime>

template <typename T>
class ShellSort : public Sort<T> {
public:
	Sequence<T> *Implementation(Sequence<T> *Source) {
		Sequence<T> *Result = Source->GetSubsequence(1, Source->GetLength());
		T Copy;
		int n = Result->GetLength();
		for (int Step = n / 2; Step > 0; Step /= 2) {
			//A = clock();
			for (int i = Step + 1; i <= n; i++) {
				for (int j = i; j >= Step + 1; j -= Step) {
					if (Result->Get(j) < Result->Get(j - Step)) {
						Copy = Result->Get(j - Step);
						Result->Change(j - Step, Result->Get(j));
						Result->Change(j, Copy);
					}
				}
			}
			//B = clock();
		}
		//cout << "Test " << B - A << endl;
		return Result;
	}
};