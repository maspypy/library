#define PROBLEM "https://atcoder.jp/contests/abc259/tasks/abc259_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/binary_optimization.hpp"

void solve() {
  LL(H, W);
  VV(ll, dat, H, W);
  const ll INF = 1LL << 60;
  Binary_Optimization<ll, 1> X(H + W, INF);
  vi A(H), B(W);
  FOR(i, H) FOR(j, W) {
    A[i] += dat[i][j];
    B[j] += dat[i][j];
  }
  ll S = 1LL << 45;

  auto row = [&](ll i) -> ll { return i; };
  auto col = [&](ll i) -> ll { return H + i; };

  FOR(i, H) FOR(j, W) {
    ll x = dat[i][j];
    if (x > 0) { X.add_2(row(i), col(j), -x, 0, -x, -x); }
    if (x < 0) { X.add_2(row(i), col(j), -x, 0, S, -x); }
  }
  auto [val, v] = X.calc();
  print(-val);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}