#define PROBLEM \
  "https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/limit_poly_exp_sum.hpp"
#include "mod/powertable.hpp"

using mint = modint998;
void solve() {
  mint r;
  read(r);
  LL(d);
  int L = d + 5;
  vc<mint> a = powertable_2<mint>(d, L - 1);
  mint p = 1;
  FOR(i, L) {
    a[i] *= p;
    p *= r;
  }
  a = cumsum<mint>(a, 0);
  print(limit_poly_exp_sum(a, r));
}

signed main() {
  solve();

  return 0;
}
