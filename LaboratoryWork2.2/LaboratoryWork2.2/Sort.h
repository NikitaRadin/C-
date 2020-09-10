#pragma once
#include "Sequence.h"

template <typename T>
class Sort {
public:
	virtual Sequence<T> *Implementation(Sequence<T> *Source) = 0;
};