#include <array>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "sortingFunctions.h"

/*
bubble sort repeatedly swaps adjacent elements if they are not in sorted order.
*/

void bubbleSort(std::array<int, array_size> &array) {
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array.size(); j++) {
      if (array[j] > array[j+1]) swap(array[j], array[j+1]);
    }
  }
}