#define PROBLEM "https://yukicoder.me/problems/no/866"
#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/or.hpp"
#include "ds/sparse_table/sparse_table_on_segtree.hpp"
#include "ds/sparse_table/sparse_table.hpp"

void solve() {
  INT(H, W, K);
  VEC(string, G, H);
  vv(u32, tmp, H, W);
  FOR(x, H) FOR(y, W) tmp[x][y] = 1 << (G[x][y] - 'a');
  Sparse_Table_On_SegTree<Sparse_Table<Monoid_Or<u32>>> seg(tmp);
  ll ANS = 0;
  FOR(x, H) FOR(y, W) {
    ll n = min(H - x, W - y);
    ll n1 = binary_search([&](ll n) -> bool { return popcnt(seg.prod(x, x + n, y, y + n)) < K; }, 0, n + 1);
    ll n2 = binary_search([&](ll n) -> bool { return popcnt(seg.prod(x, x + n, y, y + n)) <= K; }, 0, n + 1);
    ANS += n2 - n1;
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
