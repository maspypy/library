#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "seq/famous/bernoulli.hpp"
#include "mod/modint.hpp"

// sum_[1,n]i^p=f(n)
template <typename mint>
vc<mint> faulhaber_formula(int p) {
  vc<mint> F = bernoulli_number<mint>(p + 1);
  if (1 <= p) F[1] = inv<mint>(2);
  reverse(all(F));
  F[0] = 0;
  FOR(r, p + 1) { F[p - r + 1] *= fact<mint>(p) * fact_inv<mint>(r) * fact_inv<mint>(p + 1 - r); }
  return F;
}

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