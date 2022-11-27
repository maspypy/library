#define PROBLEM "https://yukicoder.me/problems/no/1919"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "ds/fenwick2d.hpp"
#include "alg/monoid/add_pair.hpp"

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
    Fenwick2D<Grp, int, false> bit(X, Y);
    FOR(i, N) {
      bit.add(X[i], Y[i], {mint(1), mint(A[i])});
      auto [c, s] = bit.prefix_sum(X[i], Y[i]);
      ANS.fi += mint(A[i]) * c - s;
    }
  }
  ANS.fi *= mint(2);
  ANS.se *= mint(2);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
