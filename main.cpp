/*
Alec Fessler
afessler1998@gmail.com
8/2/2021
this program tests the time various sorting algorithms take to run on a random array, sorted array, and almost sorted array
*/
#include <thread>
#include "runtimeTestFunctions/runtimeTestFunctions.h"

int main() {

  //create a thread for each test so that they can run in unison since each one is somewhat slow
  std::thread t1(randomArrayTest);
  std::thread t2(sortedArrayTest);
  std::thread t3(almostSortedArrayTest);

  //wait for each thread to be done before stopping the program
  t1.join();
  t2.join();
  t3.join();

  return 0;
}