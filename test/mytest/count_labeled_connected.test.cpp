#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "my_template.hpp"

#include "mod/modint.hpp"
#include "poly/fps_log.hpp"
#include "graph/count/count_labeled_connected.hpp"

using mint = modint998;

void test() {
  auto F = count_labeled_connected<mint>(10);
  vi OEIS_A001187 = {1,
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
  FOR(i, 1, 11) { assert(F[i] == mint(OEIS_A001187[i])); }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
