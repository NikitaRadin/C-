#include <iostream>
#include <string>
#include "Functions.h"

using namespace std;

string ElementToString(int Source) {
	string Result = to_string(Source);
	return Result;
}

int Random(int Range) {
	int Result = rand() % Range + 1;
	return Result;
}