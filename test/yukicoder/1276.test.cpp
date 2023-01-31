#define PROBLEM "https://yukicoder.me/problems/no/1276"

#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/multiplicative_sum.hpp"
#include "nt/primesum.hpp"
#include "enumerate/floor_range.hpp"

using mint = modint107;

void solve() {
  LL(N);
  // zeta^3
  // p^k -> k(k+1)/2
  PrimeSum<mint> X(N);
  X.calc_count();
  auto f_psum = [&](ll n) -> mint { return X[n] * mint(3); };
  auto f_pe = [&](ll p, ll e) -> mint { return (e + 1) * (e + 2) / 2; };

  mint ANS = 0;
  mint x = 0; // a|b

  auto f = [&](ll q, ll l, ll r) -> void {
    x += mint(r - l) * q;
    // b|c かつ distinct
    ANS += mint(N - 2) * mint(r - l) * mint(q - 1);
    // b|a,c かつ distinct
    ANS -= mint(r - l) * mint((q - 1) * (q - 2));
  };
  floor_range<int>(N, f);

  // a|b|c
  mint y = multiplicative_sum<mint>(N, f_pe, f_psum);
  // このうち distinct なものは？
  y -= x;
  y -= x;
  y += mint(N);
  print(ANS - y);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
