#include <array>
#include <stdlib.h>
#include <time.h>
#include "../array_size.h"
#include "helperFunctions.h"

std::array<int, array_size> getRandomArray() {
  srand(time(NULL));

  std::array<int, array_size> randomArray;
  for (int i = 0; i < array_size; i++) {
    randomArray[i] = rand() % 100 + 1;
  }

  return randomArray;
}