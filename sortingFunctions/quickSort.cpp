int partition(std::array<int, array_size> &array, int low, int high) {
  int pivot = array[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (array[j] < pivot) {
      i++;
      swap(array[i], array[j]);
    }
  }

  swap(array[i + 1], array[high]);

  return i + 1;
}

void quickSort(std::array<int, array_size> &array, int low, int high) {
  if (low < high) {
    //pIndex is partition index  
    int pIndex = partition(array, low, high);

    quickSort(array, low, pIndex - 1);
    quickSort(array, pIndex + 1, high);
  }
}