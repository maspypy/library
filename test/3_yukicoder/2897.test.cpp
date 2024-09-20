#define PROBLEM "https://yukicoder.me/problems/no/2897"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/manhattan_nns.hpp"

void solve() {
  LL(N);
  VEC(pi, FRM, N);
  LL(M);
  VEC(pi, TO, M);
  auto [D, J] = manhattan_nns(FRM, TO);
  print(MIN(D));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
