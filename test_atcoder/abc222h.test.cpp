#define PROBLEM "https://atcoder.jp/contests/abc222/tasks/abc222_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;
using poly = vc<mint>;
void solve() {
  LL(N);
  poly f = {1, 3, 1};
  f.resize(N);
  f = fps_pow(f, N + N);
  mint x = f[N - 1] * inv<mint>(N);
  print(x);
}

signed main() {
  solve();
  return 0;
}
