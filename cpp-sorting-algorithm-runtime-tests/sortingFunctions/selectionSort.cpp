void selectionSort(std::array<int, array_size> &array) {
  int i, j, minIndex;
  int size = array.size();

  for (i = 0; i < size - 1; i++) {
    int minIndex = i;

    for (j = i + 1; j < size; j++) {
      if (array[j] < array[minIndex]) minIndex = j;
    }
    
    swap(array[minIndex], array[i]);
  }
}