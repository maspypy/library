#define PROBLEM "https://judge.yosupo.jp/problem/factorial"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/mongomery_modint.hpp"

using mint = Mongomery_modint_32<0>;
constexpr int mod = 998244353;

void solve() {
  mint::set_mod(mod);
  INT(N);
  if (2 * N < mod) {
    mint x = 1;
    FOR(i, 1, N + 1) x *= mint(i);
    return print(x.val());
  }
  mint div = mod - 1;
  FOR_R(i, N + 1, mod) { div *= mint(i); }
  mint x = div.pow(mod - 2);
  print(x.val());
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}