#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/dynamic_modint.hpp"

#include "poly/fps_inv.hpp"

using mint = modint998;
// using mint = dmint;

void solve() {
  LL(N);
  VEC(mint, F, N);
  print(fps_inv(F));
}

signed main() {
  solve();

  return 0;
}
