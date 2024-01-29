#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_labeled_biconnected.hpp"

using mint = modint998;

void test() {
  vc<mint> A = count_labeled_biconnected<mint>(10);
  vi OEIS013922 = {};
  FOR(i, 11) { assert(A[i] == mint(OEIS013922[i])); }
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
