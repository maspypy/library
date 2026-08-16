#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/is_prime.hpp"

void solve() {
  LL(p);
  Yes(is_prime(p));
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}