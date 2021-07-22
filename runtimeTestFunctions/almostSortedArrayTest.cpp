#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "../helperFunctions/getRuntime.h"
#include "../sortingFunctions/sortingFunctions.h"
#include "runtimeTestFunctions.h"

void almostSortedArrayTest() {

  const int numOfTests = 5;
  
  int bubbleSortAvgRuntime = 0;
  int selectionSortAvgRuntime = 0;
  int insertionSortAvgRuntime = 0;
  int mergeSortAvgRuntime = 0;
  int quickSortAvgRuntime = 0;
  int radixSortAvgRuntime = 0;

  for (int i = 0; i < numOfTests; i++) {

    std::array<int, array_size> almostSortedArray = getAlmostSortedArray();

    std::array<int, array_size> BubbleSortArray = almostSortedArray;
    std::array<int, array_size> SelectionSortArray = almostSortedArray;
    std::array<int, array_size> InsertionSortArray = almostSortedArray;
    std::array<int, array_size> MergeSortArray = almostSortedArray;
    std::array<int, array_size> QuickSortArray = almostSortedArray;
    std::array<int, array_size> RadixSortArray = almostSortedArray;

    auto bubbleSortBind = std::bind(bubbleSort, std::ref(BubbleSortArray));
    auto selectionSortBind = std::bind(selectionSort, std::ref(SelectionSortArray));
    auto insertionSortBind = std::bind(insertionSort, std::ref(InsertionSortArray));
    auto mergeSortBind = std::bind(mergeSort, std::ref(MergeSortArray), 0, array_size - 1);
    auto quickSortBind = std::bind(quickSort, std::ref(QuickSortArray), 0, array_size - 1);
    auto radixSortBind = std::bind(radixSort, std::ref(RadixSortArray));

    bubbleSortAvgRuntime += getRuntime(bubbleSortBind);
    selectionSortAvgRuntime += getRuntime(selectionSortBind);
    insertionSortAvgRuntime += getRuntime(insertionSortBind);
    mergeSortAvgRuntime += getRuntime(mergeSortBind);
    quickSortAvgRuntime += getRuntime(quickSortBind);
    radixSortAvgRuntime += getRuntime(radixSortBind);
  }

  bubbleSortAvgRuntime /= numOfTests;
  selectionSortAvgRuntime /= numOfTests;
  insertionSortAvgRuntime /= numOfTests;
  mergeSortAvgRuntime /= numOfTests;
  quickSortAvgRuntime /= numOfTests;
  radixSortAvgRuntime /= numOfTests;

  std::cout << "Almost sorted array results:" << std::endl << std::endl;

  std::cout << std::setw(16) << std::left << "Bubble sort: " << std::setw(8) << std::right << bubbleSortAvgRuntime << std::endl;
  std::cout << std::setw(16) << std::left << "Selection sort: " << std::setw(8) << std::right << selectionSortAvgRuntime << std::endl;
  std::cout << std::setw(16) << std::left << "Insertion sort: " << std::setw(8) << std::right << insertionSortAvgRuntime << std::endl;
  std::cout << std::setw(16) << std::left << "Merge sort: " << std::setw(8) << std::right << mergeSortAvgRuntime << std::endl;
  std::cout << std::setw(16) << std::left << "Quick sort: " << std::setw(8) << std::right << quickSortAvgRuntime << std::endl;
  std::cout << std::setw(16) << std::left << "Radix sort: " << std::setw(8) << std::right << radixSortAvgRuntime << std::endl;

  std::cout << std::endl;
}