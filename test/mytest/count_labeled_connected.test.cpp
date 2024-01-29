#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_labeled_connected.hpp"

using mint = modint998;

void test() {
  vc<mint> F = count_labeled_connected<mint>(10);
  vi ANS = {0,
            1,
            1,
            4,
            38,
            728,
            26704,
            1866256,
            251548592,
            66296291072,
            34496488594816};
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
