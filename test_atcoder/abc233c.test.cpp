#define PROBLEM "https://atcoder.jp/contests/abc233/tasks/abc233_c"
#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/product.hpp"

void solve() {
  LL(N, X);
  vc<int> S(N);
  vvc<int> dat(N);
  FOR(i, N) {
    read(S[i]);
    FOR(S[i]) {
      INT(x);
      dat[i].eb(x);
    }
  }
  ll ANS = 0;
  using I = i128;
  auto query = [&](vc<int>& p) -> void {
    I prod = 1;
    FOR(i, N) {
      prod *= dat[i][p[i]];
      if (prod > X) return;
    }
    if (prod == X) ++ANS;
  };

  enumerate_product(S, query);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}