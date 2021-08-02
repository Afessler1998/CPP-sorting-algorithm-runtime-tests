#include <array>
#include "../array_size.h"
#include "sortingFunctions.h"

/*
insertion sort repeatedly moves unsorted elements backward in the array until the previous element is not smaller
*/

void insertionSort(std::array<int, array_size> &array) {
  int i, j, key;
  int size = array.size();

  for (i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    //move elements which are larger than key one index ahead of their current position
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = key;
  }
}