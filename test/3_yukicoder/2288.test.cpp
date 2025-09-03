#define PROBLEM "https://yukicoder.me/problems/no/2288"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/stable_matching.hpp"

void solve() {
  LL(N, X, Y);
  N += 2;
  vc<pi> col1(N, {-1, -1});
  vc<pi> col2(N, {-1, -1});
  vvc<int> P, Q;
  FOR(i, X) {
    INT(n);
    ++n;
    VEC(int, A, n);
    FOR(j, 1, n - 1) col1[A[j]] = {i, j};
    P.eb(A);
  }
  FOR(i, Y) {
    INT(n);
    ++n;
    VEC(int, A, n);
    FOR(j, 1, n - 1) col2[A[j]] = {i, j};
    Q.eb(A);
  }
  Stable_Matching S(Y, X);
  FOR(v, 1, N - 1) {
    auto [i, ni] = col1[v];
    auto [j, nj] = col2[v];
    if (i == -1 || j == -1) continue;
    S.add(j, i, nj, -ni);
  }

  S.calc();

  ll ANS = 0;
  FOR(i, X) {
    ll x = -S.val_2[i];
    ANS += min(x, len(P[i]) - 1);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
