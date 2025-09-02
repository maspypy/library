#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using bint = BigInteger;

void solve() {
  STR(A, B);
  bint a(A), b(B);
  print((a + b).to_string());
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
