#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/min.hpp"
#include "ds/offline_query/static_monoid_products.hpp"

void solve() {
  INT(N, Q);
  VEC(int, A, N);
  vc<pair<int, int>> LR(Q);
  FOR(q, Q) read(LR[q]);
  vc<int> ANS(Q);
  static_monoid_products<Monoid_Min<int>>(A, LR, [&](int q, int lx, int rx) -> void { ANS[q] = min(lx, rx); });
  for (auto& x: ANS) print(x);
}

signed main() {
  solve();

  return 0;
}