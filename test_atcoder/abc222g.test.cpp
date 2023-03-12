#define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/discrete_log.hpp"
#include "alg/acted_set/affine.hpp"
#include "mod/dynamic_modint.hpp"

using mint = dmint;
using AS = ActedSet_Affine<mint>;

void solve() {
  LL(mod);
  // repunit に帰着 → 10 が可逆元になるようにする
  if (mod % 4 == 0 || mod % 5 == 0) return print(-1);
  if (mod % 2 == 0) mod /= 2;
  mint::set_mod(mod);
  pair<mint, mint> a = {mint(10), mint(1)};
  auto H = [&](mint x) -> int { return x.val; };
  ll ANS = discrete_log_acted<AS>(a, 0, 0, H, 1, mod + 100);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
