#define PROBLEM "https://judge.yosupo.jp/problem/multivariate_convolution"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/multivar_convolution.hpp"

using mint = modint998;

void solve() {
  LL(K);
  VEC(ll, ns, K);
  ll N = 1;
  FOR(k, K) N *= ns[k];
  VEC(mint, f, N);
  VEC(mint, g, N);

  auto h = multivar_convolution(ns, f, g);
  print(h);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
