#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/longest_common_subsequence.hpp"

void solve() {
  STR(S, T);
  ll LCS = longest_common_subsequence(S, T);
  vc<pair<int, int>> pairs = longest_common_subsequence_restore(S, T);
  assert(len(pairs) == LCS);
  for (auto&& [i, j]: pairs) assert(S[i] == T[j]);
  FOR(i, LCS - 1) {
    assert(pairs[i].fi < pairs[i + 1].fi);
    assert(pairs[i].se < pairs[i + 1].se);
  }
  print(LCS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(_, T) solve();

  return 0;
}
