#pragma once
#include <chrono>

using std::chrono::steady_clock;
using std::chrono::milliseconds;

struct BenchmarkResult {
  double checksum = 0;
  int64_t iterations = 0;
  long duration = 0;
  long score = 0;
};

namespace global {
  constexpr int64_t million = 1'000'000;
  constexpr int64_t billion = 1'000'000'000;

  constexpr int64_t iterations_int = 1 * billion;
  constexpr int64_t iterations_float = 251 * million;
  constexpr int64_t iterations_bitwise = 2.6 * billion;
}

namespace benchmark {
  // Misura la velocità dell'ALU
  BenchmarkResult integer_benchmark(int64_t iterations);

  // Misura la velocità della FPU
  BenchmarkResult floating_point_benchmark(int64_t iterations);

  // Misura la velocità delle unità logiche
  BenchmarkResult bitwise_benchmark(int64_t iterations);

  // Viene eseguito prima dei benchmark per "stabilizzare" la cpu
  long warm_up();
}