#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/lazy_segtree.hpp"
#include "alg/acted_monoid/sum_add.hpp"
#include "ds/fenwicktree/fenwicktree_range_add.hpp"
#include "random/base.hpp"

vc<int> solve_seg(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {
  Lazy_SegTree<ActedMonoid_Sum_Add<int>> seg(A);
  vc<int> ANS;
  for (auto& [L, R, x]: query) {
    if (x == 0)
      ANS.eb(seg.prod(L, R));
    else
      seg.apply(L, R, x);
  }
  return ANS;
}

vc<int> solve_bit(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {
  FenwickTree_Range_Add<Monoid_Add<int>> seg(A);
  vc<int> ANS;
  for (auto& [L, R, x]: query) {
    if (x == 0)
      ANS.eb(seg.prod(L, R));
    else
      seg.add(L, R, x);
  }
  return ANS;
}

void test() {
  ll N = 1 << 18, Q = 1 << 18;
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(0, 100);
  vc<tuple<int, int, int>> query;
  FOR(Q) {
    int L = RNG(0, N), R = RNG(0, N);
    if (L > R) swap(L, R);
    ++R;
    int t = RNG(0, 2);
    int x = RNG(0, 100);
    if (t == 1) x = 0;
    query.eb(L, R, x);
  }
  vc<int> ANS_1 = solve_seg(N, Q, A, query);
  vc<int> ANS_2 = solve_bit(N, Q, A, query);
  assert(ANS_1 == ANS_2);

  /*
  int a = clock();
  FOR(100) solve_seg(N, Q, A, query);
  int b = clock();
  FOR(100) solve_bit(N, Q, A, query);
  int c = clock();
  print(b - a, c - b);
  print(double(b - a) / double(c - b));
  4.4 倍くらい高速ということに
  */
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}