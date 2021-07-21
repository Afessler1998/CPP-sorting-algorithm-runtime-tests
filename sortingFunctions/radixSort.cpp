#include <array>
#include "../array_size.h"
#include "sortingFunctions.h"

int getMaxValue(std::array<int, array_size> &array) {
  int maxValue = array[0];

  for (int i = 1; i < array.size(); i++) {
    if (array[i] > maxValue) maxValue = array[i];
  }

  return maxValue;
}

void countSort(std::array<int, array_size> &array, int placeValue) {
  int arraySize = array.size();  
  int *output = new int[arraySize];
  int  i, count[10] = { 0 };

  for (i = 0; i < arraySize; i++) {
    count[(array[i] / placeValue) % 10]++;
  }

  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (i = arraySize - 1; i >= 0; i--) {
    output[count[(array[i] / placeValue) % 10] - 1] = array[i];
    count[(array[i] / placeValue) % 10]--;
  }

  for (i = 0; i < arraySize; i++) {
    array[i] = output[i];
  }

  delete[] output;
}

void radixSort(std::array<int, array_size> &array) {
  int maxValue = getMaxValue(array);

  for (int placeValue = 1; maxValue / placeValue > 0; placeValue *= 10) {
    countSort(array, placeValue);
  }
}