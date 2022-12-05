#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/min.hpp"
#include "ds/segtree/dynamic_segtree_sparse.hpp"
#include "random/base.hpp"

void test() {
  using Mono = Monoid_Min<int>;
  int unit = Mono::unit();

  FOR(100) {
    int N = RNG(1, 100);

    vc<int> A(N, unit);
    Dynamic_SegTree_Sparse<Mono, false, 2000> X(0, N);
    using np = typename decltype(X)::np;
    np root = nullptr;

    int Q = RNG(1, 1000);

    FOR(Q) {
      int t = RNG(0, 4);
      int L = RNG(0, N);
      int R = RNG(0, N);
      if (L > R) swap(L, R);
      ++R;
      if (t == 0) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.set(root, i, x);
        A[i] = x;
      }
      if (t == 1) {
        int i = RNG(0, N);
        int x = RNG(1, 100);
        root = X.multiply(root, i, x);
        chmin(A[i], x);
      }
      if (t == 2) {
        vc<int> B = {A.begin() + L, A.begin() + R};
        assert(X.prod(root, L, R) == MIN(B));
      }
      if (t == 3) {
        // max_right
        int LIM = RNG(1, 100);
        auto check = [&](auto e) -> bool { return e >= LIM; };
        int naive = [&]() -> int {
          ll mi = unit;
          FOR(i, L, N) {
            chmin(mi, A[i]);
            if (mi < LIM) return i;
          }
          return N;
        }();
        assert(naive == X.max_right(root, check, L));
      }
    }
  }
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
