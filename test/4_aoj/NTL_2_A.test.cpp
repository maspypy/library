#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  B x, y;
  read(x);
  read(y);
  x += y;
  print(x);
}

signed main() {
  solve();
  return 0;
}
