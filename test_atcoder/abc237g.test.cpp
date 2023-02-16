#define PROBLEM "https://atcoder.jp/contests/abc237/tasks/abc237_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/sortable_segtree.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  INT(N, Q, X);
  VEC(int, A, N);
  for (auto&& x: A) --x;
  Sortable_SegTree<Monoid_Add<int>, 10'000'000> seg(N, A, A);
  FOR(Q) {
    INT(t, L, R);
    --L;
    if (t == 1) seg.sort_inc(L, R);
    if (t == 2) seg.sort_dec(L, R);
  }
  auto ANS = seg.get_all().fi;
  for (auto&& x: ANS) ++x;
  FOR(i, N) if (ANS[i] == X) return print(i + 1);
}

signed main() {
  solve();
  return 0;
}