#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "enumerate/product.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void test() {
  {
    vvc<int> res;
    auto f = [&](vc<int> A) -> void { res.eb(A); };
    enumerate_product(vc<int>(2, 3), f);
    assert(len(res) == 9);
    assert(res[0] == vc<int>({0, 0}));
    assert(res[1] == vc<int>({0, 1}));
    assert(res[2] == vc<int>({0, 2}));
    assert(res[3] == vc<int>({1, 0}));
    assert(res[4] == vc<int>({1, 1}));
    assert(res[5] == vc<int>({1, 2}));
    assert(res[6] == vc<int>({2, 0}));
    assert(res[7] == vc<int>({2, 1}));
    assert(res[8] == vc<int>({2, 2}));
  }
  {
    int cnt = 0;
    auto f = [&](vc<int> A) -> void { ++cnt; };
    enumerate_product(vc<int>(4, 3), f);
    assert(cnt == 81);
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  cout << fixed << setprecision(15);

  test();
  solve();

  return 0;
}
