#include "bubbleSort.cpp"
#include "selectionSort.cpp"
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "radixSort.cpp"
#include "../array_size.h"

void bubbleSort(std::array<int, array_size>&);

void selectionSort(std::array<int, array_size>&);

void insertionSort(std::array<int, array_size>&);

void mergeSort(std::array<int, array_size>&, int, int);

void quickSort(std::array<int, array_size>&, int, int);

void radixSort(std::array<int, array_size>&);