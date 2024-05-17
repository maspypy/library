#define PROBLEM "https://atcoder.jp/contests/abc348/tasks/abc348_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/maxplus_convolution.hpp"

void solve() {
  LL(N);
  vi A(N), B(N);
  FOR(i, N) read(A[i], B[i]);

  auto I = argsort(B);
  A = rearrange(A, I);
  B = rearrange(B, I);

  auto dfs = [&](auto &dfs, int L, int R) -> pair<vi, vi> {
    if (R == L + 1) {
      vi X = {0, A[L]};
      vi Y = {-infty<ll>, A[L] - B[L]};
      return {X, Y};
    }
    int M = (L + R) / 2;
    auto [X1, Y1] = dfs(dfs, L, M);
    auto [X2, Y2] = dfs(dfs, M, R);

    ll n = R - L;
    vi X(n + 1, -infty<ll>);
    vi Y(n + 1, -infty<ll>);
    // 右側が空
    FOR(i, len(X1)) chmax(X[i], X1[i]);
    FOR(i, len(Y1)) chmax(Y[i], Y1[i]);

    vi P = maxplus_convolution<ll, true, true>(X1, X2);
    vi Q = maxplus_convolution<ll, true, false>(X1, Y2);
    FOR(i, len(P)) chmax(X[i], P[i]);
    FOR(i, len(Q)) chmax(Y[i], Q[i]);
    // vi R = maxplus_convolution<ll, true, true>(Y1, X2);
    return {X, Y};
  };

  auto [X, Y] = dfs(dfs, 0, N);
  FOR(i, 1, N + 1) print(Y[i]);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
