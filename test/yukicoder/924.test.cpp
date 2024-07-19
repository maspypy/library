#define PROBLEM "https://yukicoder.me/problems/no/924"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"
#include "ds/static_range_product_group.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix<int, false, Static_Range_Product_Group<Monoid_Add<ll>>> WM(
      N, [&](int i) -> pair<int, ll> {
        return {A[i], A[i]};
      });
  FOR(Q) {
    LL(L, R);
    --L;
    int n = (R - L);
    ll k = (n - 1) / 2;
    auto [med, sum_lo] = WM.kth_value_and_prod(L, R, k);
    auto sum_hi = WM.prod_all(L, R) - sum_lo;
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