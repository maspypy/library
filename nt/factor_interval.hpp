#include "nt/primetable.hpp"

// n が p を持つとき f(n, p) を呼ぶ
template <typename F>
void factor_interval(ll L, ll R, F f) {
  int n = R - L;
  auto primes = primetable(sqrt(R));
  vi A(n);
  iota(all(A), L);
  for (auto&& p: primes) {
    ll pp = 1;
    while (1) {
      if (pp > R / p) break;
      pp *= p;
      ll s = ceil(L, pp) * pp;
      while (s < R) {
        f(s, p);
        A[s - L] /= p;
        s += pp;
      }
    }
  }
  FOR(i, n) if (A[i] > 1) f(L + i, A[i]);
}
