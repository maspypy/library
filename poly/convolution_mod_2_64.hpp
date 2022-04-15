#include "poly/convolution.hpp"
vector<u64> convolution_mod_2_64(const vector<u64>& a, const vector<u64>& b) {
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 60) return convolution_naive(a, b);
  constexpr int P0 = 998244353;
  constexpr int P1 = 754974721;
  constexpr int P2 = 167772161;
  constexpr int P3 = 469762049;
  constexpr int P4 = 880803841;
  using M0 = modint<P0>;
  using M1 = modint<P1>;
  using M2 = modint<P2>;
  using M3 = modint<P3>;
  using M4 = modint<P4>;
  vc<M0> a0(n), b0(m);
  vc<M1> a1(n), b1(m);
  vc<M2> a2(n), b2(m);
  vc<M3> a3(n), b3(m);
  vc<M4> a4(n), b4(m);
  FOR(i, n) a0[i] = a[i] % P0;
  FOR(i, m) b0[i] = b[i] % P0;
  FOR(i, n) a1[i] = a[i] % P1;
  FOR(i, m) b1[i] = b[i] % P1;
  FOR(i, n) a2[i] = a[i] % P2;
  FOR(i, m) b2[i] = b[i] % P2;
  FOR(i, n) a3[i] = a[i] % P3;
  FOR(i, m) b3[i] = b[i] % P3;
  FOR(i, n) a4[i] = a[i] % P4;
  FOR(i, m) b4[i] = b[i] % P4;
  a0 = convolution_ntt<M0>(a0, b0);
  a1 = convolution_ntt<M1>(a1, b1);
  a2 = convolution_ntt<M2>(a2, b2);
  a3 = convolution_ntt<M3>(a3, b3);
  a4 = convolution_ntt<M4>(a4, b4);
  static const M1 inv10 = M1(1) / M1(P0);
  static const M2 inv21 = M2(1) / M2(P1), inv20 = inv21 / M2(P0);
  static const M3 inv32 = M3(1) / M3(P2), inv31 = inv32 / M3(P1),
                  inv30 = inv31 / M3(P0);
  static const M4 inv43 = M4(1) / M4(P3), inv42 = inv43 / M4(P2),
                  inv41 = inv42 / M4(P1), inv40 = inv41 / M4(P0);
  vc<u64> c(len(a0));
  FOR(i, len(c)) {
    ll x0 = a0[i].val;
    ll x1 = (M1(a1[i] - x0) * inv10).val;
    ll x2 = (M2(a2[i] - x0) * inv20 - M2(x1) * inv21).val;
    ll x3 = (M3(a3[i] - x0) * inv30 - M3(x1) * inv31 - M3(x2) * inv32).val;
    ll x4 = (M4(a4[i] - x0) * inv40 - M4(x1) * inv41 - M4(x2) * inv42
             - M4(x3) * inv43)
                .val;
    c[i] = x0 + P0 * (x1 + P1 * (x2 + P2 * (x3 + P3 * u64(x4))));
  }
  return c;
}
