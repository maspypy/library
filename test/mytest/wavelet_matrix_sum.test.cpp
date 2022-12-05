#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "ds/wavelet_matrix.hpp"

void test() {
  FOR(N, 1, 50) {
    vi A(N);
    FOR(i, N) A[i] = RNG(0, 10);
    Wavelet_Matrix<ll, true, Monoid_Add<ll>> X(A);
    FOR(L, N) FOR(R, L, N + 1) {
      vi B = {A.begin() + L, A.begin() + R};
      sort(all(B));
      auto Bc = cumsum<ll>(B);

      FOR(k, R - L + 1) { assert(Bc[k] == X.sum(L, R, k)); }
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
