#define PROBLEM "https://yukicoder.me/problems/no/2649"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  B x;
  read(x);
  x = x * x + x;
  x = x.divmod(2).fi;
  INT(mod);
  ll ANS = x.divmod(mod).se;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
