#define PROBLEM \
  "https://judge.yosupo.jp/problem/pow_of_formal_power_series_sparse"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_pow.hpp"
#include "mod/dynamic_modint.hpp"

using mint = dmint;

void solve() {
  dmint::set_mod(998244353);
  LL(N, K, M);
  vc<mint> f(N);
  FOR(K) {
    LL(i, a);
    f[i] = a;
  }
  print(fps_pow(f, M));
}

signed main() {
  solve();

  return 0;
}
