#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/famous/stirling_number_2.hpp"

void solve() {
  LL(N, K);

  FOR(Q) {
    INT(l, r, x);
    print(X.query(l, r, x));
  }
}

signed main() {
  solve();
  return 0;
}