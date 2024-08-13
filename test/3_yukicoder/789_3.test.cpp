#define PROBLEM "https://yukicoder.me/problems/no/789"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  using MX = Monoid_Add<ll>;
  Dynamic_SegTree_Sparse<MX, false, 100000> seg(0, 1LL << 30);
  using np = typename decltype(seg)::np;
  np root = nullptr;
  LL(Q);
  ll ANS = 0;
  FOR(Q) {
    LL(t, a, b);
    if (t == 0) { root = seg.multiply(root, a, b); }
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
