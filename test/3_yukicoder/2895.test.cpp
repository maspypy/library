#define PROBLEM "https://yukicoder.me/problems/no/2895"
#include "my_template.hpp"
#include "other/io.hpp"

#include "linalg/xor/basis.hpp"

void solve() {
  LL(N);
  Basis<60> B;
  FOR(i, N) {
    U64(x);
    auto [ok, way] = B.solve_or_add(x);
    if (!ok) continue;
    vc<int> ANS;
    FOR(j, 60) if (way >> j & 1) ANS.eb(j + 1);
    ANS.eb(i + 1);
    print(len(ANS));
    print(ANS);
    return;
  }
  print(-1);
}

signed main() {
  solve();
  return 0;
}