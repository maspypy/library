#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"
#include "alg/acted_monoid/sum_add.hpp"

void solve() {
  LL(Q);
  using AM = ActedMonoid_Sum_Add<ll>;
  Dynamic_Lazy_SegTree<AM, false> seg(60 * Q, 0, infty<int>);
  auto root = seg.new_node();
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { seg.apply(root, a, a + 1, b); }
    if (t == 1) { ANS += seg.prod(root, a, b + 1); }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}