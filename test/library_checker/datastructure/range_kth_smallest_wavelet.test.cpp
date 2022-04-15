#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/waveletmatrix.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  WaveletMatrix WM(A);
  FOR_(Q) {
    LL(l, r, k);
    print(WM.kth(l, r, k));
  }
}

signed main() {
  solve();

  return 0;
}
