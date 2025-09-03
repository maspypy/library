#define PROBLEM "https://yukicoder.me/problems/no/2490"
#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/my_bitset.hpp"

void solve() {
  INT(N);
  VEC(int, A, 2 * N);
  FOR(i, 2 * N) A.eb(A[i]);
  using BS = My_Bitset;
  BS ng(7 * N);
  BS other(4 * N);
  vvc<int> pos(2 * N + 1);
  FOR(i, len(A)) {
    if (A[i] == -1) continue;
    pos[A[i]].eb(i);
    other[i] = 1;
  }

  FOR(x, 1, 2 * N + 1) {
    auto& I = pos[x];
    for (auto& i: I) { other[i] = 0; }
    for (auto& i: I) {
      if (i >= 3 * N) break;
      BS x = other.range(i + 1, i + N + 1);
      ng.or_to_range(2 * i + 1, 2 * i + N + 1, x);
    }
    for (auto& i: I) { other[i] = 1; }
  }

  int s = N - 1, t = 5 * N - 1;
  FOR(i, s, t) if (!ng[i]) return Yes();
  No();
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
