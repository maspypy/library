#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/discrete_log.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/modint.hpp"
#include "alg/Xset/affine.hpp"

using mint = amint;

void solve() {
  LL(P, A, B, S, G);
  mint::set_mod(P);
  if (A == 0) {
    if (S == G) return print(0);
    if (B == G) return print(1);
    return print(-1);
  }

  pair<mint, mint> g = {A, B};

  auto h = [&](mint x) -> ll { return x.val; };

  ll ANS = discrete_log_gset<XSet_Affine<mint>>(g, S, G, h, 0, P);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}
