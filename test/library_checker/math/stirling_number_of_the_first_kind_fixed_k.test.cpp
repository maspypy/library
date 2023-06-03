#define PROBLEM \
  "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind_fixed_k"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/famous/stirling_number_1.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  auto S = stirling_number_1_k<mint>(K, N, true);
  S = {S.begin() + K, S.end()};
  print(S);
}

signed main() {
  solve();
  return 0;
}
