#define PROBLEM "https://judge.yosupo.jp/problem/addition_of_hex_big_integers"

#include "my_template.hpp"
#include "other/io.hpp"

#include "bigint/binary.hpp"

using B = BigInteger_Binary;

void solve() { STR(a, b); }

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
