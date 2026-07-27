#pragma once
#include "test.h"
#include <cstdint>

using std::chrono::steady_clock;
using std::chrono::milliseconds;

struct BenchmarkResult {
  double checksum = 0;
  int iterations = 0;
  long duration = 0;
  long score = 0;
};

namespace benchmark {
  inline BenchmarkResult integer_benchmark(const int iterations) {
    int result = 27574;
    auto start = steady_clock::now().time_since_epoch();

    for (int i = 0; i < iterations; i++) {
      result = test::integer_basic_test(result);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {static_cast<double>(result), iterations, duration_test.count(), score};
  }


  inline BenchmarkResult floating_point_benchmark(const int iterations) {
    double result = 7545.342;
    auto start = steady_clock::now().time_since_epoch();

    for (int i = 0; i < iterations; i++) {
      result = test::floating_point_basic_test(result);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {result, iterations, duration_test.count(), score};
  }


  inline BenchmarkResult bitwise_benchmark(const int iterations) {
    uint32_t result = 0xA53F91C7;
    uint32_t b = 0x6D82E4B9;
    auto start = steady_clock::now().time_since_epoch();

    for (int i = 0; i < iterations; i++) {
      result = test::bitwise_basic_test(result, b);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {static_cast<double>(result), iterations, duration_test.count(), score};
  }

}