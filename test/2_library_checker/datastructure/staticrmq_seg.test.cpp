#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/min.hpp"

void solve() {
  LL(N, Q);
  using Mono = Monoid_Min<int>;
  SegTree<Mono> seg(N, [&](int i) -> int {
    INT(x);
    return x;
  });
  FOR(Q) {
    LL(L, R);
    print(seg.prod(L, R));
  }
}

signed main() {
  solve();

  return 0;
}
