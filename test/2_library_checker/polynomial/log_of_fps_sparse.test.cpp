#define PROBLEM \
  "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_log.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vc<mint> f(N);
  FOR(K) {
    LL(i, a);
    f[i] = a;
  }
  print(fps_log(f));
}

signed main() {
  solve();

  return 0;
}
