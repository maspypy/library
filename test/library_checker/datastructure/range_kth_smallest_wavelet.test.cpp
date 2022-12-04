#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  WaveletMatrix<int> WM(A);
  FOR(Q) {
    LL(l, r, k);
    print(WM.kth(l, r, k));
  }
}

signed main() {
  solve();

  return 0;
}
