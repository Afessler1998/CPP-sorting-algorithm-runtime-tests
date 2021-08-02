#include "helperFunctions.h"

/*
this function swaps the location of two values in memory
*/

void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}