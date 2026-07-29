#pragma once
#include <iostream>

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

  constexpr const char* clear_screen = "\033[2J\033[H";
}

namespace menu {
  int get_input();
  void name();
  void start();
  void cpu_main();
  void cpu_single();

}