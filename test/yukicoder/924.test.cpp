#define PROBLEM "https://yukicoder.me/problems/no/924"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix_sum.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix_Sum<ll, true> WM(A);
  FOR(Q) {
    LL(L, R);
    --L;
    int n = (R - L);
    ll cnt_lo = (n - 1) / 2;
    auto [med, sum_lo] = WM.kth(L, R, cnt_lo);
    ll sum_hi = WM.kth(L, R, R - L).se - sum_lo;
    ll cnt_hi = (R - L) - cnt_lo;
    ll ANS = 0;
    ANS += med * cnt_lo - sum_lo;
    ANS += sum_hi - med * cnt_hi;
    print(ANS);
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
