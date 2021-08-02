#include <array>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "sortingFunctions.h"

/*
selection sort repeatedly find the smallest element in the unsorted part of the array
and moves it to the beginning of the array
*/

void selectionSort(std::array<int, array_size> &array) {
  int i, j, minIndex;
  int size = array.size();

  for (i = 0; i < size - 1; i++) {
    //find the minimum element in the unsorted array
    int minIndex = i;

    for (j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) minIndex = j;
    }
    
    //swap the found minimum with the first element in the unsorted part of the array
    swap(array[minIndex], array[i]);
  }
}