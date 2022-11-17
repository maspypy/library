#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "seq/famous/indecomposable_permutations.hpp"
#include "seq/famous/simple_permutations.hpp"

using mint = modint998;

void test() {
  vc<mint> I = indecomposable_permutations<mint>(10);
  assert(I == vc<mint>({0, 1, 1, 3, 13, 71, 461, 3447, 29093, 273343}));
  vc<mint> S = indecomposable_permutations<mint>(10);
  assert(S == vc<mint>({0, 0, 0, 0, 2, 6, 46, 338, 2926, 28146}));
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();

  return 0;
}
