#include <iostream>
#include "menu.h"
#include "../version.h"
#include "../cpu/cpu_benchmark.h"

using std::cin;
using std::cout;
using std::endl;
using std::chrono::steady_clock;
using std::chrono::milliseconds;

using namespace global;

namespace menu {
  int get_input() {
    std::string input;
    cin >> input;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    try {
      return stoi(input);
    }
    catch (...) {
      return -1;
    }
  }

  void name() {
    cout << color::clear_screen;
    cout << "\nSystem Benchmark " << VERSION;
    #ifdef DEVELOPMENT_BUILD
    cout << color::yellow << " [Development Build]" << color::reset;
    #endif
    cout << "\n\n";
  }

  void start() {
    while (true) {
      name();
      cout << "0) Exit" << endl;
      cout << "1) CPU Benchmark" << endl;
      cout << "Select an option (0-1): ";

      switch (get_input()) {
        case 0: {
          exit(0);
          break;
        }

        case 1: {
          cpu_main();
          break;
        }

        default: {
          break;
        }
      }
    }
  }

  void cpu_main() {
    while (true) {
      name();
      cout << "0) Back" << endl;
      cout << "1) Single-Thread" << endl;
      cout << "2) Multi-Thread" << endl;
      cout << "Select an option (0-2): ";

      switch (get_input()) {
        case 0: {
          return;
        }

        case 1: {
          cpu_single();
          break;
        }

        case 2: {
          cpu_multi();
          break;
        }

        default: {
          break;
        }
      }
    }
  }

  void cpu_single() {
    while (true) {
      name();
      cout << "0) Back" << endl;
      cout << "1) Integer Benchmark" << endl;
      cout << "2) Floating Point Benchmark" << endl;
      cout << "3) Bitwise Benchmark" << endl;
      cout << "4) Basic Benchmark (Integer + Floating Point + Bitwise)" << endl;
      cout << "Select an option (0-4): ";

      const int input = get_input();
      benchmark::warm_up();
      switch (input) {
        case 0: {
          return;
        }

        case 1: {
          BenchmarkResult result = benchmark::integer_benchmark(iterations_int);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Duration: " << result.duration << " ms" << endl;
          cout << "Score: " << result.score << endl;
          break;
        }

        case 2: {
          BenchmarkResult result = benchmark::floating_point_benchmark(iterations_float);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Duration: " << result.duration << " ms" << endl;
          cout << "Score: " << result.score << endl;
          break;
        }

        case 3: {
          BenchmarkResult result = benchmark::bitwise_benchmark(iterations_bitwise);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Duration: " << result.duration << " ms" << endl;
          cout << "Score: " << result.score << endl;
          break;
        }

        case 4: {
          BenchmarkResult result_i = benchmark::integer_benchmark(iterations_int);
          BenchmarkResult result_f = benchmark::floating_point_benchmark(iterations_float);
          BenchmarkResult result_b = benchmark::bitwise_benchmark(iterations_bitwise);

          cout << color::clear_screen;

          cout << "Integer Checksum (debug): " << result_i.checksum << endl;
          cout << "Integer Duration: " << result_i.duration << " ms" << endl;
          cout << "Integer Score: " << result_i.score << endl;
          cout << endl;

          cout << "Floating Point Checksum (debug): " << result_f.checksum << endl;
          cout << "Floating Point Duration: " << result_f.duration << " ms" << endl;
          cout << "Floating Point Score: " << result_f.score << endl;
          cout << endl;

          cout << "Bitwise Checksum (debug): " << result_b.checksum << endl;
          cout << "Bitwise Duration: " << result_b.duration << " ms" << endl;
          cout << "Bitwise Score: " << result_b.score << endl;
          cout << endl;

          cout << "Total Duration: " << result_i.duration + result_f.duration + result_b.duration << " ms" << endl;
          cout << "Total Score: " << (result_i.score + result_f.score + result_b.score) / 3 << endl;
          break;
        }

        default: {
          break;
        }
      }
      cout << "\nPress Enter to continue...";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }


  void cpu_multi() {
    while (true) {
      name();
      cout << "0) Back" << endl;
      cout << "1) Integer Benchmark" << endl;
      cout << "2) Floating Point Benchmark" << endl;
      cout << "3) Bitwise Benchmark" << endl;
      cout << "4) Basic Benchmark (Integer + Floating Point + Bitwise)" << endl;
      cout << "Select an option (0-4): ";

      const int input = get_input();
      benchmark::warm_up();
      switch (input) {
        case 0: {
          return;
        }

        case 1: {
          BenchmarkResult result = benchmark::multithread_benchmark(BenchmarkType::INTEGER);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Average Duration (per thread): " << result.duration << " ms" << endl;
          cout << "Score (total): " << result.score << endl;
          cout << "Score (per thread): " << result.score / std::thread::hardware_concurrency() << endl;
          break;
        }

        case 2: {
          BenchmarkResult result = benchmark::multithread_benchmark(BenchmarkType::FLOATING_POINT);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Average Duration (per thread): " << result.duration << " ms" << endl;
          cout << "Score (total): " << result.score << endl;
          cout << "Score (per thread): " << result.score / std::thread::hardware_concurrency() << endl;

          break;
        }

        case 3: {
          BenchmarkResult result = benchmark::multithread_benchmark(BenchmarkType::BITWISE);

          cout << color::clear_screen;

          cout << "Checksum (debug): " << result.checksum << endl;
          cout << "Average Duration (per thread): " << result.duration << " ms" << endl;
          cout << "Score (total): " << result.score << endl;
          cout << "Score (per thread): " << result.score / std::thread::hardware_concurrency() << endl;
          break;
        }

        case 4: {
          BenchmarkResult result_i = benchmark::multithread_benchmark(BenchmarkType::INTEGER);
          BenchmarkResult result_f = benchmark::multithread_benchmark(BenchmarkType::FLOATING_POINT);
          BenchmarkResult result_b = benchmark::multithread_benchmark(BenchmarkType::BITWISE);

          cout << color::clear_screen;

          cout << "Integer Checksum (debug): " << result_i.checksum << endl;
          cout << "Integer Average Duration (per thread): " << result_i.duration << " ms" << endl;
          cout << "Integer Score (total): " << result_i.score << endl;
          cout << "Integer Score (per thread): " << result_i.score / std::thread::hardware_concurrency() << endl;
          cout << endl;

          cout << "Floating Point Checksum (debug): " << result_f.checksum << endl;
          cout << "Floating Point Average Duration (per thread): " << result_f.duration << " ms" << endl;
          cout << "Floating Point Score (total): " << result_f.score << endl;
          cout << "Floating Point Score (per thread): " << result_f.score / std::thread::hardware_concurrency() << endl;
          cout << endl;

          cout << "Bitwise Checksum (debug): " << result_b.checksum << endl;
          cout << "Bitwise Average Duration (per thread): " << result_b.duration << " ms" << endl;
          cout << "Bitwise Score (total): " << result_b.score << endl;
          cout << "Bitwise Score (per thread): " << result_b.score / std::thread::hardware_concurrency() << endl;
          cout << endl;

          cout << "Total Average Duration (per thread): " << result_i.duration + result_f.duration + result_b.duration << " ms" << endl;
          cout << "Total Score (total): " << (result_i.score + result_f.score + result_b.score) / 3 << endl;
          cout << "Total Score (per thread): " << ((result_i.score + result_f.score + result_b.score) / 3) / std::thread::hardware_concurrency() << endl;
          break;
        }

        default: {
          break;
        }
      }
      cout << "\nPress Enter to continue...";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
}
