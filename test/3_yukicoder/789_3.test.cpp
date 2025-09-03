#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(Q);
  using MX = Monoid_Add<ll>;
  Dynamic_SegTree_Sparse<MX, false> seg(Q, 0, 1LL << 30);
  using np = typename decltype(seg)::np;
  np root = nullptr;
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { root = seg.multiply(root, a, b); }
    if (t == 1) { ANS += seg.prod(root, a, b + 1); }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
