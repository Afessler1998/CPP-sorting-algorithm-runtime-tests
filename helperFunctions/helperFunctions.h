#include <array>
#include "../array_size.h"

#ifndef helperFunctions
#define helperFunctions

void swap(int&, int&);

std::array<int, array_size> getRandomArray();

std::array<int, array_size> getSortedArray();

std::array<int, array_size> getAlmostSortedArray();

#endif