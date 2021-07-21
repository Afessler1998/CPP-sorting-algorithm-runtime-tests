#include <array>
#include "../array_size.h"
#include "sortingFunctions.h"

void insertionSort(std::array<int, array_size> &array) {
  int i, j, key;
  int size = array.size();

  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = key;
  }
}