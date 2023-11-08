#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "mod/q_analogue.hpp"

template <typename mint>
void test(i128 q) {
  vc<i128> fact(11);
  fact[0] = 1;
  i128 x = 1;
  FOR(i, 1, 11) {
    fact[i] = fact[i - 1] * x;
    x = x * q + 1;
  }

  q_Analogue<mint> X(mint(q), 10);
  vv(mint, binom, 11, 11);
  FOR(n, 11) FOR(k, n + 1) {
    i128 num = fact[n];
    i128 den = fact[k] * fact[n - k];
    assert(num % den == 0);
    i128 x = num / den;
    binom[n][k] = x % mint::get_mod();
    assert(binom[n][k] == X.binom(n, k));
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  FOR(q, 3) {
    test<modint<11>>(q);
    test<modint<13>>(q);
    test<modint<17>>(q);
    test<modint<19>>(q);
  }
  solve();
  return 0;
}
