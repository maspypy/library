#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/base.hpp"
#include "ds/fenwicktree/fenwicktree_01.hpp"

void test() {
  FOR(N, 1, 1000) {
    FOR(Q, 1, 100) {
      vc<int> A(N);
      FenwickTree_01 bit(N);
      FOR(Q) {
        int t = RNG(0, 2);
        if (t == 0) {
          int k = RNG(0, N);
          if (A[k] == 0)
            bit.add(k), A[k] = 1;
          else
            bit.remove(k), A[k] = 0;
        }
        if (t == 1) {
          vc<int> I;
          FOR(i, N) if (A[i]) I.eb(i);
          if (I.empty()) continue;
          int k = RNG(0, len(I));
          assert(bit.kth(k) == I[k]);
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