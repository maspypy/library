#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/count/count_labeled_unicyclic.hpp"
#include "graph/count/count_labeled_tree.hpp"
#include "graph/count/count_labeled_forest.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  int N = 10;
  auto uni = count_labeled_unicyclic<mint>(N);
  assert(uni
         == vc<mint>(
             {0, 0, 0, 1, 15, 222, 3660, 68295, 1436568, 33779340, 880107840}));
  auto tree = count_labeled_tree<mint>(N);
  assert(tree
         == vc<mint>(
             {0, 1, 1, 3, 16, 125, 1296, 16807, 262144, 4782969, 100000000}));
  auto forest = count_labeled_forest<mint>(N);
  assert(forest
         == vc<mint>(
             {1, 1, 2, 7, 38, 291, 2932, 36961, 561948, 10026505, 205608536}));
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
