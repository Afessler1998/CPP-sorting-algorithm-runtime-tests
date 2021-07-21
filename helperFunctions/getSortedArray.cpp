#include <array>
#include "../array_size.h"
#include "helperFunctions.h"

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