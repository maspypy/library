#define PROBLEM "https://yukicoder.me/problems/no/2065"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix_sum.hpp"

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  Wavelet_Matrix_Sum<int, true, Monoid_Add<ll>> X(A);
  FOR(Q) {
    LL(l, r, x);
    --l;
    auto [cnt, sm] = X.prefix_count(l, r, x);
    ll ANS = (r - l - cnt) * x + sm;
    print(ANS);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
