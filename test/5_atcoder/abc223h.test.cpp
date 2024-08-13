#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/range_xor_basis_query.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Range_Xor_Basis_Query<ll, 60> S(A);
  vi X(Q);
  FOR(q, Q) {
    LL(L, R);
    read(X[q]);
    S.query(--L, R);
  }

  vc<bool> ANS(Q);

  S.calc([&](int q, vi basis) -> void {
    ll x = X[q];
    for (auto&& b: basis) x = min(x, x ^ b);
    ANS[q] = x == 0;
  });
  for (auto&& a: ANS) Yes(a);
}

signed main() {
  solve();
  return 0;
}
