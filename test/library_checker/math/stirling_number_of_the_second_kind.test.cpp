#define PROBLEM \
  "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/stirling_number_2.hpp"

using mint = modint998;
void solve() {
  LL(N);
  auto ANS = stirling_number_2<mint>(N);
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
