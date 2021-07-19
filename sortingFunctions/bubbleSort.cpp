void bubbleSort(std::array<int, array_size> &array) {
  for (int i = 0; i < array.size(); i++) {
    for (int j = 0; j < array.size(); j++) {
      if (array[j] > array[j+1]) swap(array[j], array[j+1]);
    }
  }
}