#define PROBLEM \
  "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/compositional_inverse.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(mint, F, N);
  vc<mint> G = compositional_inverse(F);
  print(G);
}

signed main() {
  solve();
  return 0;
}