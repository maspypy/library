#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/count/count_unlabeled_tree.hpp"

using mint = modint998;

void test() {
  auto A = count_unlabeled_tree<mint>(10, false);
  vc<mint> B = {mint(0), mint(1),  mint(1),  mint(1),  mint(2),  mint(3),
                mint(6), mint(11), mint(23), mint(47), mint(106)};
  assert(A == B);
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