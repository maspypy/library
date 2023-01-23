#define PROBLEM "https://atcoder.jp/contests/abc212/tasks/abc212_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "setfunc/hadamard.hpp"

void solve() {
  LL(N, K);
  using mint = modint998;
  ll LIM = 1 << 16;
  vc<mint> f(LIM);
  FOR(K) {
    LL(a);
    f[a] += mint(1);
  }
  hadamard(f);
  for (auto&& x: f) {
    if (x == mint(1)) {
      x = mint(N);
    } else {
      mint a = x.pow(N) - mint(1);
      a /= x - mint(1);
      x *= a;
    }
  }
  hadamard(f);
  mint ANS = 0;
  FOR(i, 1, LIM) ANS += f[i];
  ANS *= mint(LIM).inverse();
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
