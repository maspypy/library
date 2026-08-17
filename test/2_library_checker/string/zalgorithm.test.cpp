#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/z_algorithm.hpp"

void solve() {
  STR(S);
  auto Z = z_algorithm(S);
  print(Z);
}

signed main() {
  solve();
  return 0;
}
