#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/binomial.hpp"

void solve() {
  LL(Q, mod);
  Binomial Bi(mod);
  FOR_(Q) {
    LL(n, k);
    print(Bi.C(n, k));
  }
}

signed main() {
  solve();

  return 0;
}
