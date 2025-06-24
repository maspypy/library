#include "poly/convolution.hpp"
#include "mod/crt3.hpp"

template <typename T = u64>
vector<T> convolution_u64(const vector<u64>& a, const vector<u64>& b) {
  static_assert(is_same_v<T, u64> || is_same_v<T, u128>);
  int n = len(a), m = len(b);
  if (!n || !m) return {};
  if (min(n, m) <= 12500) return convolution_karatsuba(a, b);
  constexpr int p0 = 880803841;
  constexpr int p1 = 943718401;
  constexpr int p2 = 998244353;
  constexpr int p3 = 1004535809;
  constexpr int p4 = 1012924417;
  using M0 = modint<p0>;
  using M1 = modint<p1>;
  using M2 = modint<p2>;
  using M3 = modint<p3>;
  using M4 = modint<p4>;
  vc<M0> a0(n), b0(m);
  vc<M1> a1(n), b1(m);
  vc<M2> a2(n), b2(m);
  vc<M3> a3(n), b3(m);
  vc<M4> a4(n), b4(m);
  FOR(i, n) { a0[i] = a[i], a1[i] = a[i], a2[i] = a[i], a3[i] = a[i], a4[i] = a[i]; }
  FOR(i, m) { b0[i] = b[i], b1[i] = b[i], b2[i] = b[i], b3[i] = b[i], b4[i] = b[i]; }
  a0 = convolution_ntt<M0>(a0, b0);
  a1 = convolution_ntt<M1>(a1, b1);
  a2 = convolution_ntt<M2>(a2, b2);
  a3 = convolution_ntt<M3>(a3, b3);
  a4 = convolution_ntt<M4>(a4, b4);
  vc<T> c(n + m - 1);
  FOR(i, n + m - 1)
  c[i] = CRT5<T, p0, p1, p2, p3, p4>(a0[i].val, a1[i].val, a2[i].val, a3[i].val, a4[i].val);
  return c;
}
