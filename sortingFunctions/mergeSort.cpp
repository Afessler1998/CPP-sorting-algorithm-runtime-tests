#include <array>
#include "../array_size.h"
#include "sortingFunctions.h"

/*
merge sort repeatedly divides the array in half until each sub array contains a single element, then merge
recombines them in sorted order
*/

void merge(std::array<int, array_size> &array, int start, int middle, int end) { 
    int const subArrayOne = middle - start + 1;
    int const subArrayTwo = end - middle;

    //create temporary subarrays
    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];
    
    //copy elements into their respective subarrays
    for (int i = 0; i < subArrayOne; i++) leftArray[i] = array[start + i];
    for (int i = 0; i < subArrayTwo; i++) rightArray[i] = array[middle + 1 + i];

    int subArrayOneIndex = 0;
    int subArrayTwoIndex = 0;
    int mergedArrayIndex = start;

    //merge temporary arrays back into the main array
    while (subArrayOneIndex < subArrayOne && subArrayTwoIndex < subArrayTwo) {
      if (leftArray[subArrayOneIndex] <= rightArray[subArrayTwoIndex]) {
        array[mergedArrayIndex] = leftArray[subArrayOneIndex];
        subArrayOneIndex++;
      } else {
        array[mergedArrayIndex] = rightArray[subArrayTwoIndex];
        subArrayTwoIndex++;
      }
      mergedArrayIndex++;
    }

    //copy any remaining elements of the left subarray
    while (subArrayOneIndex < subArrayOne) {
      array[mergedArrayIndex] = leftArray[subArrayOneIndex];
      subArrayOneIndex++;
      mergedArrayIndex++;
    }

    //copy any remaining elements of the right subarray
    while (subArrayTwoIndex < subArrayTwo) {
      array[mergedArrayIndex] = rightArray[subArrayTwoIndex];
      subArrayTwoIndex++;
      mergedArrayIndex++;
    }

    delete[] leftArray, rightArray;
}

void mergeSort(std::array<int, array_size> &array, int start, int end) {
  if (start < end) {
    int middle = (start + end) / 2;

    mergeSort(array, start, middle);
    mergeSort(array, middle + 1, end);

    merge(array, start, middle, end);
  }
}