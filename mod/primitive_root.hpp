#include "nt/factor.hpp"
#include "mod/mod_pow.hpp"
int primitive_root(int p) {
  auto pf = factor(p - 1);
  auto is_ok = [&](int g) -> bool {
    for (auto&& [q, e]: pf)
      if (mod_pow(g, (p - 1) / q, p) == 1) return false;
    return true;
  };
  FOR3(x, 1, p) {
    if (is_ok(x)) return x;
  }
  return -1;
}
