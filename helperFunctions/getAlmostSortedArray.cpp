#include <stdlib.h>
#include <time.h>
#include <array>
#include "../array_size.h"
#include "helperFunctions.h"

std::array<int, array_size> getAlmostSortedArray() {
  std::array<int, array_size> sortedArray = getSortedArray();

  srand(time(NULL));

  for (int i = 0; i < array_size / 5; i++) {
    int randomIndexOne = rand() % array_size + 1;
    int randomIndexTwo = rand() % array_size + 1;
    swap(sortedArray[randomIndexOne], sortedArray[randomIndexTwo]);
  }

  return sortedArray;
}