#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/count/count_labeled_bridgeless.hpp"

using mint = modint998;

void test() {
  auto A = count_labeled_bridgeless<mint>(10);
  vi ANS = {
      0,
      1,
      0,
      1,
      10,
      253,
      11968,
      1047613,
      169181040,
      51017714393,
      29180467201536,
  };
  FOR(i, 11) assert(A[i] == mint(ANS[i]));

  FOR(i, 11) {
    mint a = count_labeled_bridgeless_single<mint>(i);
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