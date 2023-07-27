#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint61.hpp"
#include "string/rollinghash_2d.hpp"

void solve() {
  LL(H, W);
  VEC(string, A, H);
  RollingHash_2D RH;
  auto AH = RH.build(A);
  LL(H2, W2);
  VEC(string, B, H2);
  auto BH = RH.build(B);
  auto b = RH.query(BH, 0, 0, H2, W2);

  FOR(x, H - H2 + 1) FOR(y, W - W2 + 1) {
    auto a = RH.query(AH, x, x + H2, y, y + W2);
    if (a == b) { print(x, y); }
  }
}

signed main() {
  solve();
  return 0;
}
