#define PROBLEM "https://atcoder.jp/contests/arc160/tasks/arc160_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/sum_of_C_negative.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N, M, K);
  if (M % K != 0) return print(0);
  M /= K;

  ll e = (N - K + 1);
  poly f(e * K + 1);
  FOR(i, e + 1) { f[K * i] = (i & 1 ? -C<mint>(e, i) : C<mint>(e, i)); }

  mint ANS = sum_of_C_negative<mint>(M, N + e, f);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
