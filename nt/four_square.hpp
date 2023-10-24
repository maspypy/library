#include "nt/three_square.hpp"

tuple<ll, ll, ll, ll> four_square(ll N) {
  if (N == 0) return {0, 0, 0, 0};
  ll e = 0;
  while (N % 4 == 0) N /= 4, ++e;
  auto [a, b, c] = three_square(N);
  if (a != -1) return {a << e, b << e, c << e, 0};
  tie(a, b, c) = three_square(N - 1);
  return {a << e, b << e, c << e, 1LL << e};
}
