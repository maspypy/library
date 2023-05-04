#define PROBLEM "https://atcoder.jp/contests/abc236/tasks/abc236_h"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_exp.hpp"

using mint = modint998;
void solve() {
  LL(N, M);
  VEC(ll, A, N);
  vi LCM(1 << N, 1);
  auto f = [&](ll a, ll b) -> ll {
    ll g = gcd(a, b);
    a /= g;
    if (b > M / a) return M + 1;
    return a * b;
  };
  FOR(i, N) FOR(s, 1 << i) LCM[s | 1 << i] = f(LCM[s], A[i]);

  vc<mint> F(1 << N);
  FOR(i, 1, 1 << N) {
    F[i] = M / LCM[i];
    int n = popcnt(i);
    if (!(n & 1)) F[i] = -F[i];
    F[i] *= fact<mint>(n - 1);
  }
  F = sps_exp<mint, 16>(N, F);
  print(F.back());
}

signed main() {
  solve();
  return 0;
}
