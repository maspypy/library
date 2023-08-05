#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "ds/my_bitset.hpp"

void test() {
  FOR(N, 2000) {
    int Q = 10 * N;
    vc<int> A(N);
    My_Bitset B(N);
    FOR(Q) {
      int t = RNG(0, 4);
      int i = RNG(0, N);
      if (t == 0) {
        A[i] = 0;
        B[i] = 0;
      }
      if (t == 1) {
        A[i] = 1;
        B[i] = 1;
      }
      if (t == 2) {
        int p = i;
        while (p < N && A[p] == 0) ++p;
        assert(B.next(i) == p);
      }
      if (t == 3) {
        int p = i;
        while (p >= 0 && A[p] == 0) --p;
        assert(B.prev(i) == p);
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