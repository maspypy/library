#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/min.hpp"
#include "ds/disjoint_sparse/disjointsparse.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using Mono = Monoid_Min<int>;
  DisjointSparse<Mono> DS(A);

  FOR(_, Q) {
    LL(L, R);
    print(DS.prod(L, R));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
