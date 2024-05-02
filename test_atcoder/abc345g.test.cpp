#define PROBLEM "https://atcoder.jp/contests/abc345/tasks/abc345_g"

#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/coef_of_fps_pows.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  mint p = mint(1) / mint(K);
  vc<mint> f(N);
  FOR(i, N) if (1 <= i && i <= K) f[i] = p;
  vc<mint> g(N, 1);
  vc<mint> A = coef_of_fps_pows<mint>(f, N - 1, N, g);
  FOR(n, 1, N + 1) { print(A[n - 1] - A[n]); }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
