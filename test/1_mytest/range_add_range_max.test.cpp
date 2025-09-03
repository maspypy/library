#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "alg/acted_monoid/max_add.hpp"
#include "ds/segtree/lazy_segtree.hpp"
#include "ds/segtree/range_add_range_max.hpp"
#include "random/base.hpp"

vi sol_0(int N, int Q, vi A, vc<tuple<int, int, int, int>> query) {
  Lazy_SegTree<ActedMonoid_Max_Add<ll>> seg(A);
  vi ANS;
  for (auto [t, l, r, x] : query) {
    if (t == 0) {
      ANS.eb(seg.prod(l, r));
    }
    if (t == 1) {
      seg.apply(l, r, x);
    }
  }
  return ANS;
}

vi sol_1(int N, int Q, vi A, vc<tuple<int, int, int, int>> query) {
  Range_Add_Range_Max<ll> seg(A);
  vi ANS;
  for (auto [t, l, r, x] : query) {
    if (t == 0) {
      ANS.eb(seg.prod(l, r));
    }
    if (t == 1) {
      seg.apply(l, r, x);
    }
  }
  return ANS;
}

void test_1() {
  int N = 1'000'000;
  int Q = 1'000'000;
  int K = 1'000'000'000;
  vi A(N);
  vc<tuple<int, int, int, int>> query(Q);
  FOR(i, N) A[i] = RNG(-K, K + 1);
  FOR(q, Q) {
    int t = RNG(0, 2);
    int l = RNG(0, N);
    int r = RNG(0, N);
    if (l > r)
      swap(l, r);
    ++r;
    int x = RNG(-K, K + 1);
    query[q] = {t, l, r, x};
  }
  auto T0 = std::chrono::high_resolution_clock::now();
  auto ANS_0 = sol_0(N, Q, A, query);
  auto T1 = std::chrono::high_resolution_clock::now();
  auto ANS_1 = sol_1(N, Q, A, query);
  auto T2 = std::chrono::high_resolution_clock::now();
  double t0 = chrono::duration<double>(T1 - T0).count();
  double t1 = chrono::duration<double>(T2 - T1).count();
  assert(ANS_0 == ANS_1);
  // cout << t0 << " " << t1 << endl;
  // 10 回平均で 450ms, 270ms 程度.
}

void test_2() {
  FOR(N, 1, 10) {
    FOR(Q, 1, 10) {
      int K = 1'000'000'000;
      vi A(N);
      vc<tuple<int, int, int, int>> query(Q);
      FOR(i, N) A[i] = RNG(-K, K + 1);
      FOR(q, Q) {
        int t = RNG(0, 2);
        int l = RNG(0, N);
        int r = RNG(0, N);
        if (l > r)
          swap(l, r);
        ++r;
        int x = RNG(-K, K + 1);
        query[q] = {t, l, r, x};
      }
      auto ANS_0 = sol_0(N, Q, A, query);
      auto ANS_1 = sol_1(N, Q, A, query);
      assert(ANS_0 == ANS_1);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_1();
  test_2();
  solve();
}
