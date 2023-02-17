#define PROBLEM "https://atcoder.jp/contests/agc013/tasks/agc013_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/slice_rational_fps.hpp"

using mint = modint107;

void solve() {
  LL(N, M);
  using poly = vc<mint>;
  poly f = {0, 1, 1};
  poly Q = {1, -4, 2, -1};
  int now = 0;
  FOR(M) {
    INT(x);
    f = slice_rational_fps(f, Q, x - now);
    now = x;
    mint a = f[0];
    f = convolution(f, Q);
    f.resize(3);
    f[1] -= a;
    f[2] -= a;
  }
  f = slice_rational_fps(f, Q, N - now);
  print(f[0]);
}

signed main() {
  solve();
  return 0;
}