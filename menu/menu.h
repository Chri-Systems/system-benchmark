#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace color {
  constexpr auto reset = "\033[0m";
  constexpr auto red = "\033[31m";
  constexpr auto green = "\033[32m";
  constexpr auto yellow = "\033[33m";
  constexpr auto blue = "\033[34m";
  constexpr auto cyan = "\033[36m";

  constexpr auto clear_screen = "\033[2J\033[H";
}

namespace menu {
  int get_input();
  void name();
  void start();
  void cpu_main();
  void cpu_single();
}