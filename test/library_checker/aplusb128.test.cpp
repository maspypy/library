#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using bint = BigInteger;

void solve() {
  bint a, b;
  read(a), read(b);
  print(a + b);
}

signed main() {
  solve();
  return 0;
}