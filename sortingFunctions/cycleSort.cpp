#include <array>
#include <iostream>
#include "../array_size.h"
#include "../helperFunctions/helperFunctions.h"
#include "sortingFunctions.h"

void cycleSort(std::array<int, array_size> &array) {

  for (int cycleStart = 0; cycleStart < array_size - 1; cycleStart++) {
    int key = array[cycleStart];
    int position = cycleStart;

    for (int i = cycleStart + 1; i < array_size; i++)
      if (array[i] < key) position++;

    if (position == cycleStart) continue;

    while (key == array[position]) position++;

    if (position != cycleStart) swap(key, array[position]);

    while (position != cycleStart) {
      position = cycleStart;

      for (int i = cycleStart + 1; i < array_size; i++)
        if (array[i] < key) position++;
        
      while (key == array[position]) position++; 

      if (key != array[position]) swap(key, array[position]);
    }
  }
}