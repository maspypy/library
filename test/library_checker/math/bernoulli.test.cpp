#define PROBLEM "https://judge.yosupo.jp/problem/bernoulli_number"
#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/famous/bernoulli.hpp"

using mint = modint998;

void solve() {
  INT(N);
  print(bernoulli_number<mint>(N));
}

signed main() {
  solve();
  return 0;
}
