#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"

#include "graph/count/count_labeled_undirected.hpp"

using mint = modint998;

void test() {
  vc<mint> F = count_labeled_undirected<mint>(10);
  vi ANS = {1,
            1,
            2,
            8,
            64,
            1024,
            32768,
            2097152,
            268435456,
            68719476736,
            35184372088832};
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
