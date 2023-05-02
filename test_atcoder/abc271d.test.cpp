#define PROBLEM "https://atcoder.jp/contests/abc271/tasks/abc271_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modular_subset_sum.hpp"

void solve() {
  LL(N, S);
  VEC(pi, AB, N);
  vi C;
  ll base = 0;
  for (auto&& [a, b]: AB) {
    ll x = min(a, b);
    base += min(a, b);
    C.eb(max(a, b) - x);
  }
  S -= base;
  if (S < 0) return No();

  ll mod = SUM<ll>(C) + 10;
  if (S >= mod) return No();
  Modular_Subset_Sum<ll> X(mod, C);
  if (!X[S]) return No();
  Yes();
  vc<int> usei = X.restore(S);
  vc<int> use(N);
  for (auto&& i: usei) use[i] = 1;
  string ANS;
  FOR(i, N) {
    auto [a, b] = AB[i];
    if (a < b) { ANS += (use[i] ? 'T' : 'H'); }
    if (a >= b) { ANS += (use[i] ? 'H' : 'T'); }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
