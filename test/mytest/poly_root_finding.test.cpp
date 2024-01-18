#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "poly/finding_root_of_polynomial.hpp"
#include "poly/convolution_all.hpp"

// 相異なる 1 次式の積、重複度まあまああるかも
void test_1() {
  using mint = modint998;
  using poly = vc<mint>;
  int p = mint::get_mod();
  FOR(N, 50) {
    FOR(10) {
      vc<mint> S;
      FOR(10) S.eb(RNG(0, p));
      vc<poly> polys;
      vc<mint> roots;
      FOR(N) {
        mint a = S[RNG(0, 10)];
        roots.eb(a);
        polys.eb(poly({-mint(a), mint(1)}));
      }
      UNIQUE(roots);
      poly f = convolution_all(polys);
      auto ANS = finding_root_of_polynomial(f);
      sort(all(ANS));
      assert(roots == ANS);
    }
  }
}

// test_1 にもうひとつ N 次式をかける
void test_2() {
  using mint = modint998;
  using poly = vc<mint>;
  int p = mint::get_mod();
  FOR(N, 50) {
    FOR(10) {
      vc<mint> S;
      FOR(10) S.eb(RNG(0, p));
      vc<poly> polys;
      vc<mint> roots;
      FOR(N) {
        mint a = S[RNG(0, 10)];
        roots.eb(a);
        polys.eb(poly({-mint(a), mint(1)}));
      }
      UNIQUE(roots);
      poly f = convolution_all(polys);
      vc<mint> g(N + 1);
      FOR(i, N + 1) g[i] = RNG(0, p);
      f = convolution(f, g);
      auto ANS = finding_root_of_polynomial(f);
      for (auto& r: roots) { assert(binary_search(all(ANS), r)); }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test_1();
  test_2();
  solve();
  return 0;
}