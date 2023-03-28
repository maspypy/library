#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

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
  Wavelet_Matrix<ll, 1> X(A, A);
  auto Bc = cumsum<ll>(B);

  for (auto&& n: query) {
    ll cnt_lo = (n - 1) / 2;
    auto [med, sum_lo] = X.kth_value_and_sum(0, n, cnt_lo);
    auto total = X.sum(0, n, 0, n);
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
