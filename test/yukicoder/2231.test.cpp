#define PROBLEM "https://yukicoder.me/problems/no/2231"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/rollinghash.hpp"
#include "string/wildcard_pattern_matching.hpp"

void solve() {
  LL(N, M);
  STR(S1, S2);
  string A = S1;
  FOR(i, N) if (S1[i] == '?') A[i] = 'a';
  RollingHash RH;
  auto RS1 = RH.build(S1);
  auto RS2 = RH.build(S2);
  auto RA = RH.build(A);

  vc<bool> OK = wildcard_pattern_matching(S1, S2);
  vc<int> I;
  FOR(i, N - M + 1) if (OK[i]) I.eb(i);
  if (I.empty()) return print(-1);

  // for (auto&& i: I) print(S1.substr(i, M));

  auto check = [&](int i, int j) -> bool {
    assert(i < j);
    // 「i 選んだ方がよい」
    if (i + M <= j) return false;
    int n = RH.lcp(RS2, 0, j - i, RA, i, j);
    if (n < j - i) { return S2[n] < A[i + n]; };
    n = RH.lcp(RS2, j - i, M, RS2, 0, M + i - j);
    if (n < M + i - j) { return S2[j - i + n] < S2[n]; }
    n = RH.lcp(RA, i + M, j + M, RS2, M + i - j, M);
    if (n < j - i) { return A[i + M + n] < S2[M + i - j + n]; }
    return true;
  };
  int i = I[0];
  I.erase(I.begin());
  for (auto&& j: I) {
    if (!check(i, j)) i = j;
  }

  FOR(m, M) S1[i + m] = S2[m];
  FOR(i, N) if (S1[i] == '?') S1[i] = 'a';
  print(S1);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
