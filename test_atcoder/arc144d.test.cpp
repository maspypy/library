#define PROBLEM "https://atcoder.jp/contests/arc144/tasks/arc144_d"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/sum_of_C_negative.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vc<mint> f(N + 1);
  FOR(i, N + 1) f[i] = C<mint>(N, i);
  mint ANS = sum_of_C_negative<mint>(K, N + 2, f);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}