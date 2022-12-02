#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/min.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using Mono = Monoid_Min<int>;
  SegTree<Mono> seg(A);
  FOR(_, Q) {
    LL(L, R);
    print(seg.prod(L, R));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
