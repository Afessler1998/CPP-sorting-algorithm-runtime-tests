#include <array>
#include <functional>
#include <iostream>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "../sortingFunctions/sortingFunctions.h"
#include "../helperFunctions/getRuntime.h"
#include "runtimeTestFunctions.h"

void sortedArrayTest() {
  std::array<int, array_size> sortedArray = getSortedArray();

  std::array<int, array_size> BubbleSortArray = sortedArray;
  std::array<int, array_size> SelectionSortArray = sortedArray;
  std::array<int, array_size> InsertionSortArray = sortedArray;
  std::array<int, array_size> MergeSortArray = sortedArray;
  std::array<int, array_size> QuickSortArray = sortedArray;
  std::array<int, array_size> RadixSortArray = sortedArray;

  auto bubbleSortBind = std::bind(bubbleSort, std::ref(BubbleSortArray));
  auto selectionSortBind = std::bind(selectionSort, std::ref(SelectionSortArray));
  auto insertionSortBind = std::bind(insertionSort, std::ref(InsertionSortArray));
  auto mergeSortBind = std::bind(mergeSort, std::ref(MergeSortArray), 0, array_size - 1);
  auto quickSortBind = std::bind(quickSort, std::ref(QuickSortArray), 0, array_size - 1);
  auto radixSortBind = std::bind(radixSort, std::ref(RadixSortArray));

  double bubbleSortRuntime = getRuntime(bubbleSortBind);
  double selectionSortRuntime = getRuntime(selectionSortBind);
  double insertionSortRuntime = getRuntime(insertionSortBind);
  double mergeSortRuntime = getRuntime(mergeSortBind);
  double quickSortRuntime = getRuntime(quickSortBind);
  double radixSortRuntime = getRuntime(radixSortBind);

  std::cout << "Sorted array test results:" << std::endl << std::endl;

  std::cout << "Bubble sort took " << bubbleSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Selection sort took " << selectionSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Insertion sort took " << insertionSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Merge sort took " << mergeSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Quick sort took " << quickSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Radix sort took " << radixSortRuntime << " microseconds to run." << std::endl;

  std::cout << std::endl;
}