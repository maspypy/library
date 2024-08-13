#define PROBLEM "https://atcoder.jp/contests/abc326/tasks/abc326_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "flow/maxflow.hpp"

void solve() {
  LL(N, M);
  VEC(ll, C, N);
  VEC(ll, A, M);

  int s = 0;
  int t = 1;
  auto idx = [&](int i, int j) -> int {
    if (j == 0) return s;
    if (j == 5) return t;
    return 2 + 4 * i + (j - 1);
  };
  auto idx_a = [&](int i) -> int { return idx(N, 1) + i; };

  MaxFlow<ll> G(idx_a(M), s, t);

  FOR(i, N) {
    FOR(j, 5) G.add(idx(i, j + 1), idx(i, j), infty<ll>);
    FOR(j, 1, 5) G.add(idx(i, j), idx(i, j + 1), C[i] * j);
  }

  FOR(j, M) { G.add(s, idx_a(j), A[j]); }

  FOR(j, M) FOR(i, N) {
    INT(x);
    if (x == 1) continue;
    G.add(idx_a(j), idx(i, x - 1), infty<ll>);
  }

  // G.debug();

  ll ANS = SUM<ll>(A);
  ANS -= G.flow();
  // print(G.flow_ans);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
