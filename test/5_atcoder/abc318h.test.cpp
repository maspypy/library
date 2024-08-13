#define PROBLEM "https://atcoder.jp/contests/abc318/tasks/abc318_Ex"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/fps_exp.hpp"

using mint = modint998;

void solve() {
  LL(N);
  mint ALL = fact<mint>(N) * fact<mint>(N);
  vc<mint> f(N + 1);
  FOR(n, 1, N + 1) { f[n] = inv<mint>(n) * inv<mint>(n); }
  f = fps_exp(f);
  mint A = f[N] * fact<mint>(N) * fact<mint>(N);
  mint ANS = ALL - A - A + fact<mint>(N);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
