#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_2_A"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  STR(X, Y);
  B x(X), y(Y);
  x += y;
  print(x.to_string());
}

signed main() {
  solve();
  return 0;
}
