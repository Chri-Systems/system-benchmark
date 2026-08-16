#pragma once

namespace color {
  constexpr auto reset = "\033[0m";
  constexpr auto red = "\033[31m";
  constexpr auto green = "\033[32m";
  constexpr auto yellow = "\033[33m";
  constexpr auto blue = "\033[34m";
  constexpr auto cyan = "\033[36m";
}

namespace menu {
  int get_input();
  void name();
  void start();
  void cpu_main();
  void cpu_single();
  void cpu_multi();
}