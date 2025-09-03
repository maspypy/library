#define PROBLEM "https://yukicoder.me/problems/no/187"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/factor.hpp"
#include "nt/crt.hpp"
#include "mod/modint.hpp"

void solve() {
  LL(N);
  vc<int> vals, mods;
  FOR(i, N) {
    LL(a, b);
    vals.eb(a);
    mods.eb(b);
  }

  if (MAX(vals) == 0) {
    map<int, int> MP;
    for (auto&& m: mods) {
      for (auto&& [p, e]: factor(m)) { chmax(MP[p], e); }
    }
    using mint = modint107;
    mint ANS = 1;
    for (auto&& [p, e]: MP) ANS *= mint(p).pow(e);
    return print(ANS);
  }
  print(CRT(vals, mods, 1000000007, 0));
}

signed main() {
  solve();
  return 0;
}