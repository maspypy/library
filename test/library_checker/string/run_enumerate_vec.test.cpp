#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/run_enumerate.hpp"

void solve() {
  STR(S);
  auto A = s_to_vi(S); // vector の場合
  auto ANS = run_enumerate(A);
  print(len(ANS));
  for (auto&& [p, l, r]: ANS) print(p, l, r);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
