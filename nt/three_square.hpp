#include "nt/primetest.hpp"
#include "nt/gaussian_integers.hpp"

// https://math.stackexchange.com/questions/483101/rabin-and-shallit-algorithm
// ERH のもと O(log^2N) ？
tuple<ll, ll, ll> three_square(ll N) {
  if (N == 0) return {0, 0, 0};
  auto F = [&](ll n) -> tuple<ll, ll, ll> {
    if (N == 2) return {1, 1, 0};
    if (N == 3) return {1, 1, 1};
    if (N == 10) return {3, 1, 0};
    if (N == 34) return {5, 3, 0};
    if (N == 58) return {7, 3, 0};
    if (N == 85) return {9, 2, 0};
    if (N == 130) return {11, 3, 0};
    if (N == 214) return {14, 3, 3};
    if (N == 226) return {15, 1, 0};
    if (N == 370) return {19, 3, 0};
    if (N == 526) return {21, 9, 2};
    if (N == 706) return {25, 9, 0};
    if (N == 730) return {27, 1, 0};
    if (N == 1414) return {33, 18, 1};
    if (N == 1906) return {41, 15, 0};
    if (N == 2986) return {45, 31, 0};
    if (N == 9634) return {97, 15, 0};
    ll x = sqrtl(N);
    if (N == x * x) return {x, 0, 0};
    if (N % 4 != 1 && x % 2 == 0) --x;
    if (N % 4 == 1 && x % 2 == 1) --x;
    x += 2;
    while (1) {
      x -= 2;
      ll k = N - x * x;
      if (k < 0) break;
      if (k % 2 == 1 && primetest(k)) {
        auto [a, b] = solve_norm_equation_prime(k);
        a = abs(a), b = abs(b);
        return {a, b, x};
      }
      if (k % 2 == 0 && primetest(k / 2)) {
        auto [a, b] = solve_norm_equation_prime(k / 2);
        tie(a, b) = mp(a + b, a - b);
        a = abs(a), b = abs(b);
        return {a, b, x};
      }
    }
    return {-1, -1, -1};
    assert(0);
  };
  ll e = 0;
  while (N % 4 == 0) N /= 4, ++e;
  if (N % 8 == 7) return {-1, -1, -1};
  auto [a, b, c] = F(N);
  return {a << e, b << e, c << e};
}
