#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/find_runs.hpp"

void solve() {
  STR(S);
  auto ANS = find_runs(S);
  print(len(ANS));
  for (auto&& [p, l, r] : ANS) print(p, l, r);
}

signed main() {
  solve();

  return 0;
}
