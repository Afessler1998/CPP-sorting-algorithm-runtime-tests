#include <array>
#include <stdlib.h>
#include <time.h>
#include "../array_size.h"
#include "helperFunctions.h"

/*
this function creates an array then assigns each index with a random value between 1-100
*/

std::array<int, array_size> getRandomArray() {
  srand(time(NULL));

  std::array<int, array_size> randomArray;
  for (int i = 0; i < array_size; i++) {
    randomArray[i] = rand() % 100 + 1;
  }

  return randomArray;
}