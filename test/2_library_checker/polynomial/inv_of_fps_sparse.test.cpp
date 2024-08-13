#define PROBLEM \
  "https://judge.yosupo.jp/problem/inv_of_formal_power_series_sparse"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_inv.hpp"

void solve() {
  using mint = modint998;
  LL(N, K);
  vc<mint> f(N);
  FOR(K) {
    LL(i, a);
    f[i] = a;
  }
  print(fps_inv(f));
}

signed main() {
  solve();
  return 0;
}
