#define PROBLEM \
  "https://judge.yosupo.jp/problem/log_of_formal_power_series_sparse"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_log.hpp"
#include "mod/dynamic_modint.hpp"

void solve() {
  using mint = dmint;
  mint::set_mod(998244353);
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
