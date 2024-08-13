#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/modint.hpp"
#include "random/base.hpp"
#include "poly/convolution_all.hpp"

using mint = modint998;

void test() {
  FOR(10000) {
    int N = RNG(0, 1000);
    vc<mint> A(N);
    FOR(i, N) A[i] = RNG(0, mint::get_mod());
    vvc<mint> polys;
    for (auto& a: A) polys.eb(vc<mint>({mint(1), -a}));
    vc<mint> F = convolution_all_1<mint>(A);
    vc<mint> G = convolution_all<mint>(polys);
    assert(F == G);
  }
}

void test_1() {
  int N = 100000;
  FOR(100) {
    vc<mint> A(N);
    FOR(i, N) A[i] = RNG(0, mint::get_mod());
    vvc<mint> polys;
    for (auto& a: A) polys.eb(vc<mint>({mint(1), -a}));
    int a = clock();
    vc<mint> F = convolution_all_1<mint>(A);
    int b = clock();
    vc<mint> G = convolution_all<mint>(polys);
    int c = clock();
    cout << b - a << " " << c - b << endl;
    assert(F == G);
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  // test_1();
  solve();
  return 0;
}