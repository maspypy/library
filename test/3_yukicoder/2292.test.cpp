#define PROBLEM "https://yukicoder.me/problems/no/2292"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/dynamic_lazy_segtree.hpp"
#include "alg/acted_monoid/sum_assign.hpp"

void solve() {
  /*
  x と x+1 が接続：dat[x] = 0
  */

  LL(N, Q);
  using AM = ActedMonoid_Sum_Assign<int, -1>;
  Dynamic_Lazy_SegTree<AM, false, 10'000'000> seg(
      0, N + 10, [&](ll l, ll r) -> int { return r - l; });

  auto root = seg.new_root();
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(L, R);
      if (L == R) continue;
      root = seg.apply(root, L, R, 0);
    }
    if (t == 2) {
      LL(L, R);
      if (L == R) continue;
      root = seg.apply(root, L, R, 1);
    }
    if (t == 3) {
      LL(L, R);
      if (L > R) swap(L, R);
      ll x = (L == R ? 0 : seg.prod(root, L, R));
      if (x == 0)
        print(1);
      else
        print(0);
    }
    if (t == 4) {
      LL(v);
      ll r = seg.max_right(
          root, [&](auto e) -> bool { return e == 0; }, v);
      ll l = seg.min_left(
          root, [&](auto e) -> bool { return e == 0; }, v);
      print(r - l + 1);
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
