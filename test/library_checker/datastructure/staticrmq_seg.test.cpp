#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree.hpp"
#include "alg/monoid_min.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  using Mono = Monoid_Min<int, 1 << 30>;
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
