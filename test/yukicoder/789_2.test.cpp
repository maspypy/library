#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"
#include "alg/acted_monoid/sum_add.hpp"

void solve() {
  using AM = ActedMonoid_Sum_Add<ll>;
  Dynamic_Lazy_SegTree<AM, false, 2000000> seg(0, 1LL << 30);
  auto root = seg.new_node();
  LL(Q);
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { seg.apply(root, a, a + 1, b); }
    if (t == 1) { ANS += seg.prod(root, a, b + 1); }
  }
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
