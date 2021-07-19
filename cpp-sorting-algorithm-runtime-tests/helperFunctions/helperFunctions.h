#include "getRandomIntArray.cpp"
#include "swap.cpp"
#include "getRuntime.cpp"
#include "../array_size.h"

void swap(int&, int&);

std::array<int, array_size> getRandomIntArray();

template <typename Function>
double getRuntime(Function);