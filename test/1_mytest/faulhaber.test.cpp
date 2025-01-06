#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "seq/famous/faulhaber.hpp"
#include "mod/modint.hpp"

void test() {
  using mint = modint107;
  FOR(p, 0, 100) {
    vc<mint> F = faulhaber_formula<mint>(p);
    FOR(n, 0, 100) {
      mint LHS = 0, RHS = 0;
      FOR(i, 1, n + 1) LHS += mint(i).pow(p);
      FOR(i, len(F)) RHS += F[i] * mint(n).pow(i);
      assert(LHS == RHS);
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
}