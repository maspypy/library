#define PROBLEM "https://atcoder.jp/contests/abc335/tasks/abc335_g"

#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/factor.hpp"
#include "mod/mod_pow.hpp"

#include "nt/array_on_divisors.hpp"

void solve() {
  LL(N, P);
  auto pfs = factor(P - 1);

  auto F = [&](ll a) -> ll {
    ll exp = P - 1;
    for (auto& [p, e]: pfs) {
      while (exp % p == 0 && mod_pow_64(a, exp / p, P) == 1) exp /= p;
    }
    return exp;
  };

  Array_On_Divisors<ll> A(P - 1);

  FOR(N) {
    LL(a);
    a = F(a);
    A[a]++;
  }
  Array_On_Divisors<ll> B = A;
  B.divisor_zeta();

  ll ANS = 0;

  A.enumerate([&](ll d, ll fd) -> void { ANS += fd * B[d]; });

  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
