#define PROBLEM "https://yukicoder.me/problems/no/1270"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fenwick.hpp"
#include "ds/query/mo.hpp"

#include "ds/lazysegtree.hpp"
#include "alg/lazy/min_add.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  for (auto&& x: A) --x;

  vi ANS(Q);
  FenwickTree<Monoid_Add<int>> bit_l(N), bit_r(N);
  LazySegTree<Lazy_Min_Add<int>> seg(N, [&](int i) -> int { return 0; });
  int ans = 0;
  for (auto&& x: A) {
    ans += bit_r.sum(x + 1, N);
    bit_r.add(x, 1);
    seg.apply(x + 1, N, 1);
  }
  int sz = 0;

  Mo mo;
  FOR(q, Q) {
    LL(l, r);
    mo.add(--l, r);
  }

  auto ADD_L = [&](int i) -> void {
    int x = A[i];
    ans -= bit_l.sum(x + 1, N);
    ans -= bit_r.sum(x);
    bit_l.add(x, -1);
    seg.apply(0, x, -1);
    ++sz;
  };
  auto ADD_R = [&](int i) -> void {
    int x = A[i];
    ans -= bit_r.sum(x);
    ans -= bit_l.sum(x + 1, N);
    bit_r.add(x, -1);
    seg.apply(x + 1, N, -1);
    ++sz;
  };
  auto RM_L = [&](int i) -> void {
    int x = A[i];
    ans += bit_l.sum(x + 1, N);
    ans += bit_r.sum(x);
    bit_l.add(x, 1);
    seg.apply(0, x, 1);
    --sz;
  };
  auto RM_R = [&](int i) -> void {
    int x = A[i];
    ans += bit_r.sum(x);
    ans += bit_l.sum(x + 1, N);
    bit_r.add(x, 1);
    seg.apply(x + 1, N, 1);
    --sz;
  };
  auto CALC = [&](int q) -> void { ANS[q] = ans + seg.prod_all() * sz; };
  mo.calc(ADD_L, ADD_R, RM_L, RM_R, CALC);
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
