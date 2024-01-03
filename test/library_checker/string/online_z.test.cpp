#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/online_z_algorithm.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  Online_Z_Algorithm<char> X;
  vc<int> ANS(N, -1);

  FOR(i, N) {
    auto end = X.add(i, S[i]);
    for (auto& j: end) { ANS[j] = i - j; }
  }
  FOR(i, N) if (ANS[i] == -1) ANS[i] = N - i;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
