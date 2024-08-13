#define PROBLEM \
  "https://judge.yosupo.jp/problem/composition_of_formal_power_series_large"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"
#include "poly/composition.hpp"

using mint = dmint;

void solve() {
  mint::set_mod(998244353);
  LL(N);
  VEC(mint, f, N);
  VEC(mint, g, N);
  f = composition(f, g);
  print(f);
}

signed main() { solve(); }
