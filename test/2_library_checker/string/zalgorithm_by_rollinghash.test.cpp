#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/rollinghash.hpp"

void solve() {
  STR(S);
  ll N = len(S);
  RollingHash RH;
  auto RS = RH.build(S);
  vi Z(N);
  FOR(i, N) { Z[i] = RH.lcp(RS, 0, N, RS, i, N); }
  print(Z);
}

signed main() {
  solve();
  return 0;
}
