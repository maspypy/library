#define PROBLEM "https://yukicoder.me/problems/no/2065"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix<ll, true, true> X(A, A);
  FOR(Q) {
    LL(l, r, x);
    --l;
    auto [k, sm] = X.range_cnt_sum(l, r, 0, x);
    ll ANS = (r - l - k) * x + sm;
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}
