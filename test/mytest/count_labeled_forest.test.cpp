#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/count/count_labeled_forest.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  vc<mint> F = count_labeled_forest<mint>(10);
  vi ANS = {1, 1, 2, 7, 38, 291, 2932, 36961, 561948, 10026505, 205608536};
  FOR(n, 11) { assert(F[n] == mint(ANS[n])); }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}

signed main() {
  test();
  solve();
  return 0;
}
