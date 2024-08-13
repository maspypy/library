#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix_2d_range.hpp"
#include "ds/static_range_product_group.hpp"

void solve() {
  LL(N, Q);
  vc<u32> X(N), Y(N), W(N);
  FOR(i, N) read(X[i], Y[i], W[i]);
  Wavelet_Matrix_2D_Range<int, false, false, Prefix_Sum<ll>> WM(
      N, [&](int i) -> tuple<int, int, ll> {
        return {X[i], Y[i], W[i]};
      });
  FOR(q, Q) {
    LL(a, c, b, d);
    print(WM.prod(a, b, c, d));
  }
}

signed main() {
  solve();

  return 0;
}
