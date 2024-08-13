#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_C"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  B x, y;
  read(x), read(y);
  print(x * y);
}

signed main() {
  solve();
  return 0;
}
