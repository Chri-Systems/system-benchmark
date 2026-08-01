#include <iostream>
#include "cpu_benchmark.h"
#include "cpu_test.h"

namespace benchmark {
  BenchmarkResult integer_benchmark(const int64_t iterations) {
    int result = 27574;
    auto start = steady_clock::now().time_since_epoch();

    for (int64_t i = 0; i < iterations; i++) {
      result = test::integer_basic_test(result);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {static_cast<double>(result), iterations, duration_test.count(), score};
  }

  BenchmarkResult floating_point_benchmark(const int64_t iterations) {
    double result = 7545.342;
    auto start = steady_clock::now().time_since_epoch();

    for (int64_t i = 0; i < iterations; i++) {
      result = test::floating_point_basic_test(result);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {result, iterations, duration_test.count(), score};
  }

  BenchmarkResult bitwise_benchmark(const int64_t iterations) {
    uint32_t result = 0xA53F91C7;
    uint32_t b = 0x6D82E4B9;
    auto start = steady_clock::now().time_since_epoch();

    for (int64_t i = 0; i < iterations; i++) {
      result = test::bitwise_basic_test(result, b);
    }
    auto end = steady_clock::now().time_since_epoch();
    auto duration_test = duration_cast<milliseconds>(end - start);
    long score = iterations / duration_test.count() / 100;

    return {static_cast<double>(result), iterations, duration_test.count(), score};
  }

  long warm_up() {
    volatile int result_i = 35662;
    volatile double result_f = 54245.765;
    volatile uint32_t result_b = 0xA53F91C7;
    uint32_t b = 0x6D82E4B9;

    auto start = steady_clock::now().time_since_epoch();

    for (int i = 0; i < 3000000; i++) {
      result_i = test::integer_basic_test(result_i);
    }
    for (int i = 0; i < 1000000; i++) {
      result_f = test::floating_point_basic_test(result_f);
    }
    for (int i = 0; i < 2000000; i++) {
      result_b = test::bitwise_basic_test(result_b, b);
    }
    auto end = steady_clock::now().time_since_epoch();

    return duration_cast<milliseconds>(end - start).count();
  }

  void multithread_integer_benchmark(const int64_t iterations) {
    BenchmarkResult result = integer_benchmark(iterations);
    multithread_mutex.lock();
    multithread_results.push_back(result);
    multithread_mutex.unlock();
  }

  unsigned int multithread_benchmark_test() {
    const unsigned int total_threads = std::thread::hardware_concurrency();

    for (int i = 0; i < total_threads; i++) {
      multithread_threads.emplace_back(multithread_integer_benchmark, global::iterations_int);
    }

    for (auto& thread: multithread_threads) {
      thread.join();
    }

    for (auto& multithread_result: multithread_results) {
      multithread_result.iterations;
    }

    return 0;
  }
}