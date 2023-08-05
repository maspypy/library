#include "nt/primetable.hpp"

/*
N と完全乗法的関数 f の prefix sum 関数 F を与える。
n = floor(N/d) となる n に対する sum_{p <= n} f(p) を計算する。
特に、素数の k 乗和や、mod m ごとでの素数の k 乗和が計算できる。
Complexity: O(N^{3/4}/logN) time, O(N^{1/2}) space.
*/
template <typename T>
struct PrimeSum {
  ll N;
  ll sqN;
  vc<T> sum_lo, sum_hi;
  bool calculated;

  PrimeSum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}

  // [1, x] ただし、x = floor(N, i) の形
  T operator[](ll x) {
    assert(calculated);
    return (x <= sqN ? sum_lo[x] : sum_hi[double(N) / x]);
  }

  template <typename F>
  void calc(const F f) {
    auto primes = primetable<int>(sqN);
    sum_lo.resize(sqN + 1);
    sum_hi.resize(sqN + 1);
    FOR3(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;
    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N) / i) - 1;
    for (int p: primes) {
      ll pp = ll(p) * p;
      if (pp > N) break;
      ll R = min(sqN, N / pp);
      ll M = sqN / p;
      T x = sum_lo[p - 1];
      T fp = sum_lo[p] - sum_lo[p - 1];
      FOR(i, 1, M + 1) sum_hi[i] -= fp * (sum_hi[i * p] - x);
      FOR(i, M + 1, R + 1) sum_hi[i] -= fp * (sum_lo[N / (double(i) * p)] - x);
      FOR_R(n, pp, sqN + 1) sum_lo[n] -= fp * (sum_lo[double(n) / p] - x);
    }
    calculated = 1;
  }

  void calc_count() {
    calc([](ll x) -> T { return x; });
  }

  void calc_sum() {
    calc([](ll x) -> T {
      ll a = x, b = x + 1;
      if (!(x & 1)) a /= 2;
      if (x & 1) b /= 2;
      return T(a) * T(b);
    });
  }
};
