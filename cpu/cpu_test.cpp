#include <cmath>
#include "cpu_test.h"

namespace test {
  int integer_basic_test(int n) {
    n = n + 3256;
    n = n - 3645;
    n = n * 34;
    n = n / 7;
    n = n + 8921;
    n = n % 1000000000;
    return n;
  }

  double floating_point_basic_test(double n) {
    n = n * 1.000001;
    n = n + 28575.678;
    n = n / 3.141592;
    n = n * (n + 0.457432);
    n = sqrt(fabs(n));
    n = n * 0.335886;
    return n;
  }

  uint32_t bitwise_basic_test(uint32_t a, uint32_t b) {
    uint32_t result = a;

    result = result & b;
    result = result | a;
    result = result ^ b;
    result = result << 4;
    result = result | b;
    result = result >> 3;
    result = result ^ a;

    return result;
  }
}