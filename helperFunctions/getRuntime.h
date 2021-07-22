#include "chrono"

#ifndef get_Runtime
#define get_Runtime

//get runtime is declared and defined in header file to prevent "undefined reference" linker error due to template use in parameters
template <typename Function>
int getRuntime(Function function) {
  auto startTime = std::chrono::high_resolution_clock::now();
  function();
  auto stopTime = std::chrono::high_resolution_clock::now();
  int duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
  return duration;
}

#endif