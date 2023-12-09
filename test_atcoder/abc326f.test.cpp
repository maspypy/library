#define PROBLEM "https://atcoder.jp/contests/abc326/tasks/abc326_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "knapsack/subset_sum.hpp"

void solve() {
  LL(N, XX, YY);
  VEC(ll, A, N);
  vi X, Y;
  FOR(i, N) {
    if (i % 2 == 1) X.eb(A[i]);
    if (i % 2 == 0) Y.eb(A[i]);
  }

  auto solve = [&](vi X, ll XX) -> pair<bool, vc<int>> {
    // 全部 + でとるとする
    ll SM = SUM<ll>(X);
    ll diff = (SM - XX);
    if (diff % 2 != 0) return {false, {}};
    diff /= 2;
    vc<int> ANS(len(X), +1);
    if (diff == 0) { return {true, ANS}; }

    auto I = subset_sum(X, diff);
    if (I.empty()) return {false, {}};
    for (auto& idx: I) ANS[idx] = -1;
    return {true, ANS};
  };

  auto [ok1, S1] = solve(X, XX);
  auto [ok2, S2] = solve(Y, YY);
  if (!ok1 || !ok2) return No();

  vc<int> DIR(N);
  FOR(i, len(S1)) { DIR[2 * i + 1] = (S1[i] == 1 ? 0 : 2); }
  FOR(i, len(S2)) { DIR[2 * i + 0] = (S2[i] == 1 ? 1 : 3); }

  DIR.insert(DIR.begin(), 0);
  string ANS;
  FOR(i, N) { ANS += ((DIR[i + 1] - DIR[i] - 1) % 4 == 0 ? "L" : "R"); }
  Yes();
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
