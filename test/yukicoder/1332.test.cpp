#define PROBLEM "https://yukicoder.me/problems/no/1332"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

void solve() {
  LL(N);
  VEC(ll, X, N);
  Wavelet_Matrix<ll, true> WM(X);
  LL(Q);
  FOR(Q) {
    LL(l, r, x);
    --l;
    ll ANS = infty<ll>;
    ll n = WM.count(l, r, 0, x);
    if (n > 0) chmin(ANS, abs(x - WM.kth(l, r, n - 1)));
    if (n < r - l) chmin(ANS, abs(x - WM.kth(l, r, n)));
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
