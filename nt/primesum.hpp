#include "nt/primetable.hpp"

template <typename T>
pair<vc<T>, vc<T>> primesum_F(ll N, function<T(ll)> F) {
  /*
  N と完全乗法的関数 f の prefix sum 関数 F を与える。
  n = floor(N/d) となる n に対する sum_{p <= n} f(p) を計算する。

  特に、p^k の和や、mod m ごとでの p^k の和が計算できる。

  Complexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.
  */
  ll sqN = sqrtl(N);
  auto primes = primetable(sqN);
  vc<T> sum_lo(sqN + 1), sum_hi(sqN + 1);
  FOR3(i, 1, sqN + 1) sum_lo[i] = F(i) - 1;
  FOR3(i, 1, sqN + 1) sum_hi[i] = F(double(N) / i) - 1;
  for (auto&& p: primes) {
    ll pp = p * p;
    if (pp > N) break;
    ll R = min(sqN, N / pp);
    ll M = sqN / p;
    T x = sum_lo[p - 1];
    T fp = sum_lo[p] - sum_lo[p - 1];
    FOR3(i, 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] - x);
    FOR3(i, M + 1, R + 1) sum_hi[i] -= fp * (sum_lo[double(N) / (i * p)] - x);
    FOR3_R(n, pp, sqN + 1) sum_lo[n] -= fp * (sum_lo[double(n) / p] - x);
  }
  return {sum_lo, sum_hi};
}

template <typename T>
pair<vc<T>, vc<T>> primecnt(ll N) {
  auto F = [&](ll N) -> T { return N; };
  return primesum_F<T>(N, F);
}

template <typename T>
pair<vc<T>, vc<T>> primesum(ll N) {
  auto F = [&](ll N) -> T {
    return (N & 1 ? T((N + 1) / 2) * T(N) : T(N / 2) * T(N + 1));
  };
  return primesum_F<T>(N, F);
}
