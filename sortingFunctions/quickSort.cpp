#include <array>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "sortingFunctions.h"

/*
quick sort calls partition to find a partition index and
swap any smaller elements to the left side and any
larger elements to the right side
*/

int partition(std::array<int, array_size> &array, int low, int high) {
  int pivot = array[high];
  int i = low - 1; //index for the next pivot point

  for (int j = low; j < high; j++) {
    //if current element is smaller than the pivot point
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[high]);

  return i + 1;
}

void quickSort(std::array<int, array_size> &array, int low, int high) {
  if (low < high) {
    //pIndex is partition index  
    int pIndex = partition(array, low, high);

    //recursively sort elements before and after the partition index seperately
    quickSort(array, low, pIndex - 1);
    quickSort(array, pIndex + 1, high);
  }
}