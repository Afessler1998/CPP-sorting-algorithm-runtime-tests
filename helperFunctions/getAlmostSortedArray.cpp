#include <array>
#include <stdlib.h>
#include <time.h>
#include "../array_size.h"
#include "helperFunctions.h"

std::array<int, array_size> getAlmostSortedArray() {
  std::array<int, array_size> sortedArray = getSortedArray();

  srand(time(NULL));

  //if array size is >= 20, 10% of indices will be swapped randomly, otherwise only swap two
  for (int i = 0; i < (array_size >= 20 ? array_size * 0.05 : 1); i++) {
    int randomIndexOne = rand() % array_size + 1;
    int randomIndexTwo = rand() % array_size + 1;
    swap(sortedArray[randomIndexOne], sortedArray[randomIndexTwo]);
  }

  return sortedArray;
}