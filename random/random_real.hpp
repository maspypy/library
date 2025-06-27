
#include "random/base.hpp"

double random_real(double a, double b) {
  double x = RNG(0, 1 << 30);
  x /= (1 << 30);
  return a + (b - a) * x;
}
