#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp"

void solve() {
  LL(N, Q);
  vc<u32> X(N), Y(N), W(N);
  FOR(i, N) read(X[i], Y[i], W[i]);
  using DST = Disjoint_Sparse_Table<Monoid_Add<ll>>;
  Wavelet_Matrix_2D_Range_Static_Monoid<Monoid_Add<ll>, DST, int, false, false>
      WM(N, [&](int i) -> tuple<int, int, ll> {
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
