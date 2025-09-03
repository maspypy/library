#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "ds/segtree/range_assignment_segtree.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "alg/monoid/add.hpp"
#include "alg/acted_monoid/sum_assign.hpp"
#include "random/base.hpp"

struct PROB {
  int N, Q;
  vc<ll> INIT;
  vc<tuple<int, int, int>> QUERY;
};

PROB gen(int N, int Q) {
  PROB p;
  p.N = N, p.Q = Q;
  FOR(N) { p.INIT.eb(RNG(0, 1 << 30)); }
  FOR(Q) {
    int t = RNG(0, 2);
    int l = RNG(0, N), r = RNG(0, N);
    int x = RNG(0, 1 << 30);
    if (l > r) swap(l, r);
    ++r;
    if (t == 0) p.QUERY.eb(l, r, x);
    if (t == 1) p.QUERY.eb(l, r, -1);
  }
  return p;
}

vi sol_1(PROB p) {
  vi ANS;
  Lazy_SegTree<ActedMonoid_Sum_Assign<ll, -1>> seg(p.INIT);
  for (auto& [l, r, x]: p.QUERY) {
    if (x == -1) {
      ANS.eb(seg.prod(l, r));
    } else {
      seg.apply(l, r, x);
    }
  }
  return ANS;
}

vi sol_2(PROB p) {
  vi ANS;
  Range_Assignment_SegTree<Monoid_Add<ll>> seg(p.INIT);
  for (auto& [l, r, x]: p.QUERY) {
    if (x == -1) {
      ANS.eb(seg.prod(l, r));
    } else {
      seg.assign(l, r, x);
    }
  }
  return ANS;
}

void test() {
  int N = 1 << 22, Q = 1 << 22;
  PROB p = gen(N, Q);
  double a = clock();
  vi A = sol_1(p);
  double b = clock();
  vi B = sol_2(p);
  double c = clock();
  a = (b - a) / CLOCKS_PER_SEC;
  b = (c - b) / CLOCKS_PER_SEC;
  assert(A == B);
  // cout << a << "\n"; 1.563 sec
  // cout << b << "\n"; 1.376 sec
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}