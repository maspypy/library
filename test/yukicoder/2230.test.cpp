#define PROBLEM "https://yukicoder.me/problems/no/2230"
#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/longest_increasing_subsequence.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(H, W, N, P);
  VEC(pi, XY, N);
  sort(all(XY));
  vi Y;
  for (auto&& [a, b]: XY) Y.eb(b);
  ll a = longest_increasing_subsequence<ll, 0>(Y).fi;
  ll b = H + W - 3 - a;
  mint p = mint(1) / mint(P);
  mint ANS = mint(1) - (mint(1) - p - p).pow(a) * (mint(1) - p).pow(b);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
