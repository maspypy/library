#define PROBLEM "https://judge.yosupo.jp/problem/primitive_root"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/primitive_root.hpp"

void solve() {
  LL(p);
  ll ANS = primitive_root_64(p);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
