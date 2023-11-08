#define PROBLEM "https://judge.yosupo.jp/problem/multiplication_of_big_integers"
#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/base.hpp"

using B = BigInteger;

void solve() {
  B a, b;
  read(a, b);
  print(a * b);
}

signed main() {
  INT(T);
  FOR(T) solve();

  return 0;
}
