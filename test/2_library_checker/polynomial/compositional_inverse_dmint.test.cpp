#define PROBLEM \
  "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series_large"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "poly/power_projection.hpp"
#include "poly/compositional_inverse.hpp"

using mint = dmint;

void solve() {
  mint::set_mod(998244353);
  LL(N);
  VEC(mint, f, N);
  f = compositional_inverse(f);
  print(f);
}

signed main() { solve(); }
