#include <thread>
#include "runtimeTestFunctions/runtimeTestFunctions.h"

int main() {

  std::thread t1(randomArrayTest);
  std::thread t2(sortedArrayTest);
  std::thread t3(almostSortedArrayTest);

  t1.join();
  t2.join();
  t3.join();

  return 0;
}