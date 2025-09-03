#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "ds/fenwicktree/dual_fenwicktree.hpp"

void test() {
  FOR(N, 1, 50) {
    FOR(Q, 1, 100) {
      vc<int> A(N);
      Dual_FenwickTree<Monoid_Add<int>> bit(N);
      FOR(Q) {
        int t = RNG(0, 3);
        if (t == 0) {
          // apply
          int L = RNG(0, N), R = RNG(0, N);
          if (L > R) swap(L, R);
          int x = RNG(0, 100);
          ++R;
          FOR(i, L, R) A[i] += x;
          bit.apply(L, R, x);
        }
        if (t == 1) {
          // get
          int i = RNG(0, N);
          assert(A[i] == bit.get(i));
        }
        if (t == 2) {
          // get_all
          assert(A == bit.get_all());
        }
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}

signed main() {
  test();
  solve();
  return 0;
}