#define PROBLEM "https://yukicoder.me/problems/no/2264"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "nt/function_on_divisors.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  ll lcm = 1;
  for (auto&& x: A) lcm = lcm / gcd(lcm, x) * x;

  Function_on_Divisors<int> X(lcm);
  X.set_euler_phi();

  mint ANS = 0;
  X.enumerate([&](int d, int phi) {
    ll exp = 0;
    ll k = lcm / d;
    for (auto&& a: A) {
      ll g = gcd(a, k);
      exp += g;
    }
    ANS += mint(M).pow(exp) * mint(phi);
  });
  ANS /= mint(lcm);
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
