#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp"

void solve() {
  LL(N, Q);
  vc<u32> X(N), Y(N);
  vc<u64> W(N);
  FOR(i, N) read(X[i], Y[i], W[i]);
  using QQ = tuple<u32, u32, u32, u32>;
  vc<QQ> query(Q);
  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      U32(x, y, w);
      X.eb(x);
      Y.eb(y);
      W.eb(0);
      query[q] = mt(-1, x, y, w);
    } else {
      U32(a, b, c, d);
      query[q] = mt(a, c, b, d);
    }
  }

  Wavelet_Matrix_2D_Range_Dynamic_AbelGroup<Monoid_Add<ll>, int, false, false>
      WM(len(X), [&](int i) -> tuple<int, int, ll> {
        return {X[i], Y[i], W[i]};
      });
  int idx = N;
  FOR(q, Q) {
    auto [a, b, c, d] = query[q];
    if (a == u32(-1)) {
      WM.add(idx++, d);
    } else {
      print(WM.sum(a, b, c, d));
    }
  }
}

signed main() {
  solve();

  return 0;
}
