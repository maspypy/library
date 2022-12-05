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
  Wavelet_Matrix<ll, 1> X(A);
  auto Ac = cumsum<ll>(A);
  auto Bc = cumsum<ll>(B);

  const ll INF = 1LL << 60;

  for (auto&& n: query) {
    ll x = X.kth(0, n, (n - 1) / 2);
    ll cnt_lo = X.freq(0, n, -INF, x);
    ll sum_lo = X.sum(0, n, cnt_lo);
    ll cnt_hi = n - cnt_lo;
    ll sum_hi = Ac[n] - sum_lo;
    ll ANS = Bc[n];
    ANS += (cnt_lo * x - sum_lo);
    ANS += (sum_hi - cnt_hi * x);
    print(x, ANS);
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
