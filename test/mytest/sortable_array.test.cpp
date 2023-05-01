#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/sortable_array.hpp"
#include "random/base.hpp"

void test() {
  int N = RNG(1, 64);
  int MAX = RNG(2, 20);
  vc<int> A(N);
  FOR(i, N) A[i] = RNG(MAX);
  Sortable_Array<1000> X(MAX, A);

  int Q = 1000;
  FOR(Q) {
    int t = RNG(0, 5);
    if (t == 0) {
      vc<int> B = X.get_all();
      assert(A == B);
    }
    if (t == 0) {
      int idx = RNG(0, N);
      assert(A[idx] == X.get(idx));
    }
    if (t == 2) {
      int idx = RNG(0, N);
      int x = RNG(MAX);
      A[idx] = x;
      X.set(idx, x);
    }
    if (t == 3) {
      int L = RNG(0, N);
      int R = RNG(0, N);
      if (L > R) swap(L, R);
      ++R;
      X.sort_inc(L, R);
      sort(A.begin() + L, A.begin() + R);
    }
    if (t == 4) {
      int L = RNG(0, N);
      int R = RNG(0, N);
      if (L > R) swap(L, R);
      ++R;
      X.sort_dec(L, R);
      sort(A.begin() + L, A.begin() + R);
      reverse(A.begin() + L, A.begin() + R);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  FOR(100) test();
  solve();
  return 0;
}