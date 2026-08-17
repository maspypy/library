#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/run_enumerate.hpp"

void solve() {
  STR(S);
  auto ANS = run_enumerate(S);
  print(len(ANS));
  for (auto&& [p, l, r] : ANS) print(p, l, r);
}

signed main() {
  solve();

  return 0;
}
