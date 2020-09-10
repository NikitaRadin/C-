#include <iostream>
#include <string>
#include "conio.h"
#include "Interface.h"
#include "Tests.h"

using namespace std;

int main() {
	string Action;
	L6:
	cout << "Select the action:" << endl;
	cout << "	RunTest" << endl;
	cout << "	RunSort" << endl;
	cout << "	CompareAlgorithms" << endl;
	cout << endl;
	cin >> Action;
	cout << endl;
	if (Action == "RunTest") {
		string Test;
		L7:
		cout << "Choose the test:" << endl;
		cout << "	ArraySequenceTest" << endl;
		cout << "	ListSequenceTest" << endl;
		cout << "	QuickSortArraySequenceTest" << endl;
		cout << "	QuickSortListSequenceTest" << endl;
		cout << "	ShellSortArraySequenceTest" << endl;
		cout << "	ShellSortListSequenceTest" << endl;
		cout << endl;
		cin >> Test;
		if (Test == "ArraySequenceTest") {
			ArraySequenceTest();
			goto L6;
		}
		else if (Test == "ListSequenceTest") {
			ListSequenceTest();
			goto L6;
		}
		else if (Test == "QuickSortArraySequenceTest") {
			QuickSortArraySequenceTest();
			goto L6;
		}
		else if (Test == "QuickSortListSequenceTest") {
			QuickSortListSequenceTest();
			goto L6;
		}
		else if (Test == "ShellSortArraySequenceTest") {
			ShellSortArraySequenceTest();
			goto L6;
		}
		else if (Test == "ShellSortListSequenceTest") {
			ShellSortListSequenceTest();
			goto L6;
		}
		else if (Test == "Stop") {
			exit(0);
		}
		else {
			cout << "Invalid test" << endl;
			goto L7;
		}
	}
	else if (Action == "RunSort") {
		string Type;
	L5:
		cout << "Select type:" << endl;
		cout << "	int" << endl;
		cout << endl;
		cin >> Type;
		cout << endl;
		if (Type == "int") {
			Interface<int>();
			goto L6;
		}
		else if (Type == "Stop") {
			exit(0);
		}
		else {
			cout << "Invalid type" << endl;
			goto L5;
		}
	}
	else if (Action == "CompareAlgorithms") {
		int Length;
		cout << "Enter the length of the sequence:" << endl;
		cin >> Length;
		int Range;
		cout << "Enter the range of values:" << endl;
		cin >> Range;
		CompareAlgorithms(Length, Range);
		goto L6;
	}
	else if (Action == "Stop") {
		exit(0);
	}
	else {
		cout << "Invalid action" << endl;
		goto L6;
	}
	_getche();
	return 0;
}