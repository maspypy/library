#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix/wavelet_matrix.hpp"
#include "ds/static_range_product_group.hpp"

void solve() {
  LL(Q);
  vi A, B, query;
  FOR(Q) {
    LL(t);
    if (t == 1) {
      LL(a, b);
      A.eb(a);
      B.eb(b);
    }
    if (t == 2) { query.eb(len(A)); }
  }
  Wavelet_Matrix<int, 0, Prefix_Sum<ll>> X(len(A), [&](int i) -> pair<int, ll> {
    return {A[i], A[i]};
  });
  auto Bc = cumsum<ll>(B);

  for (auto&& n: query) {
    ll cnt_lo = (n - 1) / 2;
    auto [med, sum_lo] = X.kth_value_and_prod(0, n, cnt_lo);
    auto total = X.prod_all(0, n);
    ll cnt_hi = n - cnt_lo;
    ll sum_hi = total - sum_lo;
    ll ANS = Bc[n];
    ANS += (cnt_lo * med - sum_lo);
    ANS += (sum_hi - cnt_hi * med);
    print(med, ANS);
  }
}

signed main() {
  solve();
  return 0;
}