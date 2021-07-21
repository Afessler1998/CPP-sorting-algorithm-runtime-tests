#include "chrono"

#ifndef get_Runtime
#define get_Runtime

template <typename Function>
double getRuntime(Function function) {
  auto startTime = std::chrono::high_resolution_clock::now();
  function();
  auto stopTime = std::chrono::high_resolution_clock::now();
  double duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
  return duration;
}

#endif