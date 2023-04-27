#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/binomial.hpp"

void solve() {
  INT(T, mod);
  Binomial X(mod);
  FOR(T) {
    LL(n, k);
    print(X.C(n, k));
  }
}

signed main() {
  solve();

  return 0;
}