#define PROBLEM "https://yukicoder.me/problems/no/1533"
#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_pow.hpp"
#include "poly/fps_div.hpp"
using mint = modint998;

void solve() {
  LL(N, M, K);
  if (M == 1 && K == 1) return print(0);

  if (M == K) { --M; }
  mint R = 0;
  FOR(x, -M, M + 1) if (abs(x) != K) R += mint(1);

  vc<mint> g(M + M + 1, 1);
  if (K <= M) g[M + K] = g[M - K] = 0;

  ll LIM = N * M;
  g.resize(LIM);
  vc<mint> F = fps_pow_1_sparse<mint>(g, N + 2);
  g[M] -= R;
  g.resize(M + M + 1);
  F = fps_div<mint, 1>(F, g);
  F = fps_div<mint, 1>(F, g);
  mint ANS = SUM<mint>(F);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
