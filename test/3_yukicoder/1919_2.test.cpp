#define PROBLEM "https://yukicoder.me/problems/no/1919"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/wavelet_matrix/wavelet_matrix_2d_range.hpp"
#include "alg/monoid/add_pair.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(int, A, N);
  VEC(int, B, N);

  pair<mint, mint> ANS;
  FOR(2) {
    swap(ANS.fi, ANS.se);
    swap(A, B);
    auto I = argsort(A);
    A = rearrange(A, I);
    B = rearrange(B, I);
    vc<int> X(N), Y(N);
    FOR(i, N) X[i] = A[i] - B[i];
    FOR(i, N) Y[i] = A[i] + B[i];

    using Grp = Monoid_Add_Pair<mint>;
    Wavelet_Matrix_2D_Range<int, false, false, FenwickTree<Grp>> WM(
        N, [&](int i) -> tuple<int, int, pair<mint, mint>> {
          return {X[i], Y[i], Grp::unit()};
        });
    FOR(i, N) {
      WM.multiply(i, {mint(1), mint(A[i])});
      auto [c, s] = WM.prod(-infty<int>, X[i], -infty<int>, Y[i]);
      ANS.fi += mint(A[i]) * c - s;
    }
  }
  ANS.fi *= mint(2);
  ANS.se *= mint(2);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
