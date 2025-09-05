#define PROBLEM "https://yukicoder.me/problems/no/2525"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

void solve() {
  STR(AA, BB);
  BigInteger A(AA), B(BB);
  bool ok = A.divmod(2).se == B.divmod(2).se;
  print(ok ? "Possible" : "Impossible");
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
