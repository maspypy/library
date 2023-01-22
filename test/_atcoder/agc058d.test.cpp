#define PROBLEM "https://atcoder.jp/contests/agc058/tasks/agc058_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "poly/coef_of_rational_fps_2d.hpp"

using mint = modint998;

void solve() {
  LL(A, B, C);
  ll N = A + B + C;

  using poly = vc<mint>;
  vc<poly> F(2), G(4);
  F[0] = {mint(3)};
  F[1] = {mint(-1)};
  G[0] = {mint(1)};
  G[1] = {mint(-1)};
  G[3] = {mint(0), mint(2)};

  auto g = coef_of_rational_fps_2d(F, G, N);
  FOR(i, len(g)) g[i] *= inv<mint>(2);
  g[0] = 1;

  mint ANS = 0;

  FOR(t, len(g)) {
    ll a = A - t, b = B - t, c = C - t;
    if (min({a, b, c}) < 0) break;
    mint cf = fact<mint>(a + b + c) * fact_inv<mint>(a) * fact_inv<mint>(b)
              * fact_inv<mint>(c);
    ANS += g[t] * cf;
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
