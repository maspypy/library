#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  Dynamic_SegTree<Monoid_Add<ll>, false, 4000000> seg(0, 1LL << 30);
  auto root = seg.new_node();
  LL(Q);
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { seg.multiply(root, a, b); }
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
