#include <array>
#include "../array_size.h"
#include "helperFunctions.h"

/*
this function creates an array of integers between 1-100 which is already in ascending sorted order.
if the array size is greater than 100, there will have to be some duplicate elements,
the number of which is determined by incrementing j if the expression within the nested if statement is true
*/

std::array<int, array_size> getSortedArray() {
  std::array<int, array_size> sortedArray;

  int j = 1;

  for (int i = 0; i < array_size; i++) {
    if (array_size > 100) {
      sortedArray[i] = j;
      if ((i + 1) % (array_size / 100) == 0) j++;
    } else sortedArray[i] = i + 1;
  }

  return sortedArray;
}