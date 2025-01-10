#define PROBLEM "https://yukicoder.me/problems/no/705"
#include "my_template.hpp"
#include "other/io.hpp"
#include "convex/lichao.hpp"

int N;
vi dp;
vc<int> A, X, Y;

struct F {
  using value_type = ll; // operator() の戻り値
  int i;
  ll operator()(int j) {
    if (i == -1) return infty<ll>;
    assert(1 <= j && j <= N);
    ll dx = abs(A[j - 1] - X[i]);
    ll dy = abs(Y[i]);
    return dp[i] + dx * dx * dx + dy * dy * dy;
  }
};

void solve() {
  read(N);
  A.resize(N), X.resize(N), Y.resize(N);
  FOR(i, N) read(A[i]);
  FOR(i, N) read(X[i]);
  FOR(i, N) read(Y[i]);

  dp.resize(N + 1);

  LiChao_Tree<F, false, true> LCT(1, N + 1, F{-1});

  FOR(i, N + 1) {
    if (i > 0) { dp[i] = LCT.query(i).fi; }
    if (i < N) LCT.chmin_line(F{int(i)});
  }
  print(dp[N]);
}

signed main() {
  solve();
  return 0;
}