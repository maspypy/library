#define PROBLEM "https://yukicoder.me/problems/no/2859"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/wavelet_matrix/wavelet_matrix_2d_range.hpp"
#include "alg/monoid/max.hpp"
#include "ds/segtree/segtree.hpp"

void solve() {
  LL(N, K);
  VEC(ll, T, N);
  VEC(ll, X, N);
  VEC(ll, C, N);

  auto I = argsort(T);
  T = rearrange(T, I);
  X = rearrange(X, I);
  C = rearrange(C, I);

  vi A(N), B(N);
  FOR(i, N) A[i] = X[i] + K * T[i];
  FOR(i, N) B[i] = K * T[i] - X[i];

  Wavelet_Matrix_2D_Range<ll, 0, 0, SegTree<Monoid_Max<ll>>> seg(N, [&](int i) -> tuple<ll, ll, ll> { return {A[i], B[i], -infty<ll>}; });

  ll ANS = 0;
  FOR(i, N) {
    if (abs(X[i]) > K * T[i]) continue;
    ll ans = 0;
    chmax(ans, seg.prefix_prod(-infty<ll>, A[i] + 1, B[i] + 1));
    ans += C[i];
    seg.set(i, ans);
    chmax(ANS, ans);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
