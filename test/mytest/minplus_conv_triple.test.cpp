#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "random/base.hpp"
#include "convex/minplus_convolution_of_triples.hpp"

void test() {
  FOR(N, 0, 300) {
    vi A(N), B(N), C(N);
    FOR(i, N) A[i] = RNG(1, 1 << 30);
    FOR(i, N) B[i] = RNG(1, 1 << 30);
    FOR(i, N) C[i] = RNG(1, 1 << 30);
    // 愚直
    vi dp(2 * N + 1, infty<ll>);
    dp[0] = 0;
    FOR(i, N) {
      ll a = A[i], b = B[i], c = C[i];
      vi newdp(2 * N + 1, infty<ll>);
      FOR(i, len(dp)) {
        if (i + 0 <= 2 * N) chmin(newdp[i + 0], dp[i] + a);
        if (i + 1 <= 2 * N) chmin(newdp[i + 1], dp[i] + b);
        if (i + 2 <= 2 * N) chmin(newdp[i + 2], dp[i] + c);
      }
      swap(dp, newdp);
    }

    MinPlus_Convolution_of_Triples<ll> X;
    FOR(i, N) X.add(A[i], B[i], C[i]);
    X.solve();
    FOR(K, 2 * N + 1) {
      ll val = X[K];
      vc<int> x = X.restore(K);
      assert(SUM<int>(x) == K);
      ll sm = 0;
      FOR(i, N) {
        assert(0 <= x[i] && x[i] <= 2);
        if (x[i] == 0) sm += A[i];
        if (x[i] == 1) sm += B[i];
        if (x[i] == 2) sm += C[i];
      }
      assert(sm == val && val == dp[K]);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}