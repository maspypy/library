#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "random/base.hpp"
#include "ds/segtree/segtree.hpp"

void test() {
  FOR(100) {
    int n = RNG(0, 5);
    int N = 1 << n;
    using Mono = Monoid_Add<int>;
    vc<int> A(N);
    FOR(i, N) A[i] = RNG(0, 10);
    SegTree<Mono> seg(A);
    FOR(100) {
      int t = RNG(0, 2);
      if (t == 0) {
        int i = RNG(0, N);
        int x = RNG(0, 10);
        seg.set(i, x);
        A[i] = x;
      }
      if (t == 1) {
        int L = RNG(0, N);
        int R = RNG(0, N);
        if (L > R) swap(L, R);
        ++R;
        int xor_val = RNG(0, N);
        int sm = 0;
        FOR(i, L, R) sm += A[i ^ xor_val];
        assert(sm == seg.xor_prod(L, R, xor_val));
      }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  solve();
  return 0;
}
