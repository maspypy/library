#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/find_runs.hpp"

void solve() {
  STR(S);
  auto A = s_to_vi(S, 'a');  // vector の場合
  auto ANS = find_runs(A);
  print(len(ANS));
  for (auto&& [p, l, r] : ANS) print(p, l, r);
}

signed main() {
  solve();
  return 0;
}
