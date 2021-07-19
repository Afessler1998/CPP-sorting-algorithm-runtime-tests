#include <chrono>
using namespace std::chrono;

template <typename Function>
double getRuntime(Function function) {
  auto startTime = high_resolution_clock::now();
  function();
  auto stopTime = high_resolution_clock::now();
  double duration = duration_cast<microseconds>(stopTime - startTime).count();
  return duration;
}


