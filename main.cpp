#include <thread>
#include "runtimeTestFunctions/runtimeTestFunctions.h"

#include "sortingFunctions/sortingFunctions.h"
#include "helperFunctions/helperFunctions.h"
#include <iostream>
#include <array>
#include "array_size.h"

int main() {

  /*std::array<int, array_size> randomArray = getRandomArray();

  for (int i = 0; i < array_size; i++) {
    std::cout << randomArray[i] << std::endl;
  }

  std::cout << std::endl;

  cycleSort(randomArray);

  for (int i = 0; i < array_size; i++) {
    std::cout << randomArray[i] << std::endl;
  }*/

  std::thread t1(randomArrayTest);
  std::thread t2(sortedArrayTest);
  std::thread t3(almostSortedArrayTest);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}