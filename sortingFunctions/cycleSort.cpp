#include <array>
#include <iostream>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "sortingFunctions.h"

/*
cycle sort repeatedly finds the correct index for each element and then moves there,
thus each element is moved zero times, if it's already in the correct index, or once to put it there
*/

void cycleSort(std::array<int, array_size> &array) {

  for (int cycleStart = 0; cycleStart < array_size - 1; cycleStart++) {
    int key = array[cycleStart];
    int position = cycleStart;

    //find correct position for element by counting the number of smaller elements
    for (int i = cycleStart + 1; i < array_size; i++)
      if (array[i] < key) position++;

    //continue if position is correct
    if (position == cycleStart) continue;

    //ignore duplicate elements
    while (key == array[position]) position++;

    //swap to correct position
    if (position != cycleStart) swap(key, array[position]);

    //complete the rest of the cycle
    while (position != cycleStart) {
      position = cycleStart;
      
      //find correct position
      for (int i = cycleStart + 1; i < array_size; i++)
        if (array[i] < key) position++;
        
      //ignore duplicate elements  
      while (key == array[position]) position++; 

      //swap to correct position
      if (key != array[position]) swap(key, array[position]);
    }
  }
}