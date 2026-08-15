#include "alg/monoid_pow.hpp"

// https://yukicoder.me/submissions/883884
// https://qoj.ac/contest/1411/problem/7620
// U は範囲内で ax+b がオーバーフローしない程度
// yyy x yyyy x ... yyy x yyy (x を N 個)
// k 個目の x までに floor(ak+b,m) 個の y がある
// my<=ax+b における lattice path における辺の列と見なせる
template <typename Monoid, typename X, typename U>
X floor_monoid_product(X x, X y, U N, U a, U b, U m) {
  U c = (a * N + b) / m;
  X pre = Monoid::unit(), suf = Monoid::unit();
  while (1) {
    const U p = a / m, q = b / m;
    a %= m, b %= m;
    x = Monoid::op(x, monoid_pow<Monoid>(y, p));
    pre = Monoid::op(pre, monoid_pow<Monoid>(y, q));
    c -= (p * N + q);
    if (c == 0) break;
    const U d = (m * c - b - 1) / a + 1;
    suf = Monoid::op(y, Monoid::op(monoid_pow<Monoid>(x, N - d), suf));
    b = m - b - 1 + a, N = c - 1, c = d;
    swap(m, a), swap(x, y);
  }
  x = monoid_pow<Monoid>(x, N);
  return Monoid::op(Monoid::op(pre, x), suf);
}