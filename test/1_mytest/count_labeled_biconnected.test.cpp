#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_labeled_biconnected.hpp"

using mint = modint998;

void test() {
  vc<mint> F = count_labeled_biconnected<mint>(10);
  vi ANS = {
      0,
      0,
      1,
      1,
      10,
      238,
      11368,
      1014888,
      166537616,
      50680432112,
      29107809374336,
  };
  FOR(i, 11) assert(F[i] == mint(ANS[i]));
  FOR(i, 11) {
    mint a = count_labeled_biconnected_single<mint>(i);
    assert(a == mint(ANS[i]));
  }
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
