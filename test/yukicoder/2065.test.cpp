#define PROBLEM "https://yukicoder.me/problems/no/2065"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"
#include "ds/static_range_product_group.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Wavelet_Matrix<ll, false, Static_Range_Product_Group<Monoid_Add<ll>>> WM(
      N, [&](int i) -> pair<int, ll> {
        return {A[i], A[i]};
      });
  FOR(Q) {
    LL(l, r, x);
    --l;
    auto [cnt, sm] = WM.count_and_prod(l, r, 0, x);
    ll ANS = (r - l - cnt) * x + sm;
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}