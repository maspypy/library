#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(Q);
  Dynamic_SegTree<Monoid_Add<ll>, false> seg(0, 1LL << 30);
  seg.reserve(1 + 30 * Q);
  int root = seg.new_root();
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) {
      seg.multiply(root, a, b);
    }
    if (t == 1) {
      ANS += seg.prod(root, a, b + 1);
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
