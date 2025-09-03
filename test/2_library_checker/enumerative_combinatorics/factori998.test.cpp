#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/factorial998.hpp"

using mint = modint998;

void solve() {
  INT(N);
  print(factorial998(N));
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
