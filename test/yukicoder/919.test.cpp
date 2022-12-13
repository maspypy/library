#define PROBLEM "https://yukicoder.me/problems/no/919"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/wavelet_matrix.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  Wavelet_Matrix<ll, true> WM(A);
  const ll INF = 1LL << 60;
  ll ANS = -INF;

  auto get = [&](ll L, ll R) -> ll {
    assert(L < R);
    ll n = R - L;
    return WM.kth(L, R, (n - 1) / 2);
  };

  FOR3(K, 1, N + 1) {
    // とる最大回数
    ll LIM = N / K;
    vi left(LIM);
    vi right(LIM);
    FOR(i, LIM) left[i] = get(K * i, K * i + K);
    FOR(i, LIM) right[i] = get(N - K * i - K, N - K * i);
    left = cumsum<ll>(left);
    right = cumsum<ll>(right);
    // x 回以下とるときの～
    FOR(i, LIM) chmax(left[i + 1], left[i]);
    FOR(i, LIM) chmax(right[i + 1], right[i]);
    FOR(i, LIM + 1) chmax(ANS, K * (left[i] + right[LIM - i]));
  }
  print(ANS);
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
