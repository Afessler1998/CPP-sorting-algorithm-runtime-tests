#include <array>
#include "../array_size.h"
#include "sortingFunctions.h"

/*
radix sort uses getMaxValue to find the element which has the largest number of digits
to determine how many times to call countSort and for what digits. countSort sorts the array
by a single place value at a time
*/

//function which returns the largest value of the array
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

  //store the number that each digit occurs in the count array
  for (i = 0; i < arraySize; i++) {
    count[(array[i] / placeValue) % 10]++;
  }

  //modify count to contain the correct position of each digit in the output array
  for (i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  //create the output array
  for (i = arraySize - 1; i >= 0; i--) {
    output[count[(array[i] / placeValue) % 10] - 1] = array[i];
    count[(array[i] / placeValue) % 10]--;
  }

  //copy the values of output array into the main array
  for (i = 0; i < arraySize; i++) {
    array[i] = output[i];
  }

  delete[] output;
}

void radixSort(std::array<int, array_size> &array) {
  //find max value to know how many digits to sort
  int maxValue = getMaxValue(array);

  //call count sort for each digit
  for (int placeValue = 1; maxValue / placeValue > 0; placeValue *= 10) {
    countSort(array, placeValue);
  }
}