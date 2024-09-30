#include "nt/nimber/base.hpp"
#include "linalg/xor/basis.hpp"

namespace NIMBER_QUADRATIC {
// x^2+x==a を解く. Trace(a)==0 が必要.
// Nimber では Trace は topbit.
// topbit==0 である空間から偶数全体への全単射がある.
// これを前計算したい. 線形写像なので連立方程式を解いて埋め込むだけでよい.

u64 Q[4][65536];

void __attribute__((constructor)) precalc() {
  Basis<63> B;
  FOR(i, 63) {
    Nimber64 x(u64(1) << (i + 1));
    x = x.square() + x;
    assert(!B.solve_or_add(x.val).fi);
  }
  FOR(k, 63) {
    int t = k / 16, i = k % 16;
    u64 X = B.way[k] * 2;
    FOR(s, 1 << i) Q[t][s | 1 << i] = Q[t][s] ^ X;
  }
}

u16 f(u16 a) { return Q[0][a]; }
u32 f(u32 a) { return Q[0][a & 65535] ^ Q[1][a >> 16]; }
u64 f(u64 a) { return Q[0][a & 65535] ^ Q[1][a >> 16 & 65535] ^ Q[2][a >> 32 & 65535] ^ Q[3][a >> 48 & 65535]; }

template <typename U>
vc<U> solve_quadratic_1(U a) {
  constexpr int k = numeric_limits<U>::digits - 1;
  if (a >> k & 1) return {};
  return {f(a), U(f(a) | 1)};
}
} // namespace NIMBER_QUADRATIC

template <typename F>
vc<F> solve_quadratic(F a, F b) {
  if (a == F(0)) return {b.sqrt()};
  b /= a.square();
  vc<F> ANS;
  for (auto& x: NIMBER_QUADRATIC::solve_quadratic_1(b.val)) { ANS.eb(a * F(x)); }
  return ANS;
}
