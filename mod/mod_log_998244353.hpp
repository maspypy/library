#include "mod/discrete_log_998244353.hpp"
#include "mod/mod_inv.hpp"

int mod_log_998244353(int a, int b) {
  int x = discrete_log_mod_998244353_primitive_root(a);
  int y = discrete_log_mod_998244353_primitive_root(b);
  int m = 998244353 - 1;
  int g = gcd(x, m);
  if (y % g != 0) return -1;
  x /= g, y /= g, m /= g;
  return mod_inv(x, g) * y % m;
}
