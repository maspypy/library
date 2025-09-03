#define PROBLEM "https://yukicoder.me/problems/no/1939"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  ++N;

  vc<mint> P(N);
  P[0] = 1;
  FOR(M) {
    LL(a);
    if (a < N) P[a] += mint(1);
  }
  P = fps_pow_1_sparse<mint>(P, N);
  mint ANS = P[N - 1] / mint(N);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
