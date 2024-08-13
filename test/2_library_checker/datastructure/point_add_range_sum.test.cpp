#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree.hpp"

void solve() {
  LL(N, Q);
  FenwickTree<Monoid_Add<ll>> bit(N, [&](int i) -> ll {
    LL(x);
    return x;
  });

  FOR(Q) {
    LL(t, a, b);
    if (t == 0) {
      bit.add(a, b);
    } else {
      print(bit.prod(a, b));
    }
  }
}

signed main() {
  solve();
  return 0;
}
