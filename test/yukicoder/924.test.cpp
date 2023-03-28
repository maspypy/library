#define PROBLEM "https://yukicoder.me/problems/no/924"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix<ll, true> WM(A, A);
  FOR(Q) {
    LL(L, R);
    --L;
    int n = (R - L);
    ll k = (n - 1) / 2;
    ll med = WM.kth(L, R, k);
    ll sum_lo = WM.sum(L, R, 0, k);
    ll sum_hi = WM.sum(L, R, k, R - L);
    ll ANS = 0;
    ANS += med * k - sum_lo;
    ANS += sum_hi - med * (R - L - k);
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
