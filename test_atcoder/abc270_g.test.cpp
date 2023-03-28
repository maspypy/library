#define PROBLEM "https://atcoder.jp/contests/abc270/tasks/abc270_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/affine.hpp"
#include "mod/dynamic_modint.hpp"
#include "alg/acted_set/affine.hpp"
#include "nt/discrete_log.hpp"

using mint = dmint;

void solve() {
  LL(P, A, B, S, G);
  mint::set_mod(P);
  using AS = ActedSet_Affine<mint>;
  auto h = [&](mint x) -> ll { return x.val; };

  ll ANS = discrete_log_acted<AS, decltype(h), 18>({A, B}, S, G, h, 0, P);
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}