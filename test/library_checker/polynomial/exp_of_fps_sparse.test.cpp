#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/fps_exp.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vc<mint> f(N);
  FOR(K){
    LL(i, a);
    f[i] = a;
  }
  print(fps_exp(f));
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
