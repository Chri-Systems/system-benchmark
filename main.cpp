#include <chrono>
#include <iostream>
#include "benchmark.h"

using std::cin;
using std::cout;
using std::endl;

namespace color {
  constexpr const char* reset = "\033[0m";
  constexpr const char* red = "\033[31m";
  constexpr const char* green = "\033[32m";
  constexpr const char* yellow = "\033[33m";
  constexpr const char* blue = "\033[34m";
  constexpr const char* cyan = "\033[36m";
}

int main() {
  constexpr int iterations = 500000000;

  cout << "\nSystem Benchmark v0.1.0-alpha";
#ifdef DEVELOPMENT_BUILD
  cout << color::yellow << " [Development Build]" << color::reset;
#endif
  cout << "\n\nselect an option (1-4)" << endl;
  cout << "1) Integer Benchmark" << endl;
  cout << "2) Floating Point Benchmark" << endl;
  cout << "3) Bitwise Benchmark" << endl;
  cout << "4) Basic Benchmark (Integer + Floating Point + Bitwise)" << endl;

  int selected = 0;
  cin >> selected;

  cout << "\nRunning benchmark, please wait...\n" << endl;

  benchmark::warm_up();

  switch (selected) {
    case 1: {
      BenchmarkResult result = benchmark::integer_benchmark(iterations);
      cout << "Checksum (debug): " << result.checksum << endl;
      cout << "Duration: " << result.duration << " ms" << endl;
      cout << "Score: " << result.score << endl;
      break;
    }
    case 2: {
      BenchmarkResult result = benchmark::floating_point_benchmark(iterations);
      cout << "Checksum (debug): " << result.checksum << endl;
      cout << "Duration: " << result.duration << " ms"  << endl;
      cout << "Score: " << result.score << endl;
      break;
    }
    case 3: {
      BenchmarkResult result = benchmark::bitwise_benchmark(iterations);
      cout << "Checksum (debug): " << result.checksum << endl;
      cout << "Duration: " << result.duration << " ms"  << endl;
      cout << "Score: " << result.score << endl;
      break;
    }
    case 4: {
      BenchmarkResult result_i = benchmark::integer_benchmark(iterations);
      BenchmarkResult result_f = benchmark::floating_point_benchmark(iterations);
      BenchmarkResult result_b = benchmark::bitwise_benchmark(iterations);

      cout << "Integer Checksum (debug): " << result_i.checksum << endl;
      cout << "Integer Duration: " << result_i.duration << " ms"  << endl;
      cout << "Integer Score: " << result_i.score << endl;
      cout << endl;

      cout << "Floating Checksum (debug): " << result_f.checksum << endl;
      cout << "Floating Point Duration: " << result_f.duration << " ms"  << endl;
      cout << "Floating Point Score: " << result_f.score << endl;
      cout << endl;

      cout << "Bitwise Checksum (debug): " << result_b.checksum << endl;
      cout << "Bitwise Duration: " << result_b.duration << " ms"  << endl;
      cout << "Bitwise Score: " << result_b.score << endl;
      cout << endl;

      cout << "Total Duration: " << result_i.duration + result_f.duration + result_b.duration << " ms"  << endl;
      cout << "Total Score: " << (result_i.score + result_f.score + result_b.score) / 3 << endl;
      break;
    }
    default: {
      cout << color::red << "Invalid input" << color::reset << endl;
      return 1;
    }
  }

  return 0;
}