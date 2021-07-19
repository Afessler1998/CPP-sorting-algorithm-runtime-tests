#include <iostream>
#include <array>
#include <functional>
#include "helperFunctions/helperFunctions.h"
#include "sortingFunctions/sortingFunctions.h"
#include "array_size.h"

int main() {
  std::array<int, array_size> randomArray = getRandomIntArray();

  std::array<int, array_size> bubbleSortedArray = randomArray;
  std::array<int, array_size> selectionSortedArray = randomArray;
  std::array<int, array_size> insertionSortedArray = randomArray;
  std::array<int, array_size> mergeSortedArray = randomArray;
  std::array<int, array_size> quickSortedArray = randomArray;
  std::array<int, array_size> radixSortedArray = randomArray;

  auto bubbleSortBind = std::bind(bubbleSort, std::ref(bubbleSortedArray));
  auto selectionSortBind = std::bind(selectionSort, std::ref(selectionSortedArray));
  auto insertionSortBind = std::bind(insertionSort, std::ref(insertionSortedArray));
  auto mergeSortBind = std::bind(mergeSort, std::ref(mergeSortedArray), 0, mergeSortedArray.size() - 1);
  auto quickSortBind = std::bind(quickSort, std::ref(quickSortedArray), 0, quickSortedArray.size() - 1);
  auto radixSortBind = std::bind(radixSort, std::ref(radixSortedArray));

  double bubbleSortRuntime = getRuntime(bubbleSortBind);
  double selectionSortRuntime = getRuntime(selectionSortBind);
  double insertionSortRuntime = getRuntime(insertionSortBind);
  double mergeSortRuntime = getRuntime(mergeSortBind);
  double quickSortRuntime = getRuntime(quickSortBind);
  double radixSortRuntime = getRuntime(radixSortBind);

  std::cout << "Bubble sort took " << bubbleSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Selection sort took " << selectionSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Insertion sort took " << insertionSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Merge sort took " << mergeSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Quick sort took " << quickSortRuntime << " microseconds to run." << std::endl;
  std::cout << "Radix sort took " << radixSortRuntime << " microseconds to run." << std::endl;

  return 0;
}