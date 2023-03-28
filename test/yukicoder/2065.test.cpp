#define PROBLEM "https://yukicoder.me/problems/no/2065"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix<ll, true, Monoid_Add<ll>> X(A, A);
  FOR(Q) {
    LL(l, r, x);
    --l;
    int k = X.count(l, r, 0, x);
    ll sm = X.sum(l, r, 0, k);
    ll ANS = (r - l - k) * x + sm;
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
