void merge(std::array<int, array_size> &array, int start, int middle, int end) { 
    int const subArrayOne = middle - start + 1;
    int const subArrayTwo = end - middle;

    int *leftArray = new int[subArrayOne];
    int *rightArray = new int[subArrayTwo];

    for (int i = 0; i < subArrayOne; i++) leftArray[i] = array[start + i];
    for (int i = 0; i < subArrayTwo; i++) rightArray[i] = array[middle + 1 + i];

    int subArrayOneIndex = 0;
    int subArrayTwoIndex = 0;
    int mergedArrayIndex = start;

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

    while (subArrayOneIndex < subArrayOne) {
      array[mergedArrayIndex] = leftArray[subArrayOneIndex];
      subArrayOneIndex++;
      mergedArrayIndex++;
    }

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