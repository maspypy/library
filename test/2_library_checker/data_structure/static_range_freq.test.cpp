#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/to_small_key.hpp"

void solve() {
  U32(N, Q);
  VEC(u32, A, N);
  To_Small_Key X;
  for (auto& x: A) x = X.query(x, true);

  vvc<int> IDS(X.kind);
  FOR(i, N) IDS[A[i]].eb(i);
  FOR(Q) {
    U32(L, R, x);
    x = X.query(x, false);
    if (x == u32(-1)) {
      print(0);
    } else {
      auto& I = IDS[x];
      u32 ans = LB(I, R) - LB(I, L);
      print(ans);
    }
  }
}

signed main() {
  solve();

  return 0;
}
