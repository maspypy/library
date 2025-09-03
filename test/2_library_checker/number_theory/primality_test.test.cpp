#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primetest.hpp"

void solve() {
  LL(p);
  Yes(primetest(p));
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}