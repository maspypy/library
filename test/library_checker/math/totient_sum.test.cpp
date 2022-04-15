#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_totient_function"
#include "my_template.hpp"
#include "other/io.hpp"

#include "nt/primesum.hpp"
#include "nt/multiplicative_sum.hpp"

void solve() {
  LL(N);
  auto [sum_lo_0, sum_hi_0] = primecnt<ll>(N);
  auto [sum_lo, sum_hi] = primesum<i128>(N);
  ll m = len(sum_lo_0);
  FOR(i, m) sum_lo[i] -= sum_lo_0[i];
  FOR(i, m) sum_hi[i] -= sum_hi_0[i];
  auto f = [&](ll p, ll e) -> i128 {
    ll x = p - 1;
    FOR_(e - 1) x *= p;
    return x;
  };
  int mod = 998244353;
  print(int(multiplicative_sum(N, f, sum_lo, sum_hi) % mod));
}

signed main() {
  solve();

  return 0;
}
