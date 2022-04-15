#include "poly/poly_divmod.hpp"

namespace half_gcd {
// https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf
template <typename T>
using arr = array<vc<T>, 2>;

template <typename T>
using mat = array<vc<T>, 4>;

template <typename T>
void shrink(vc<T>& a) {
  while (len(a) && a.back() == 0) a.pop_back();
}

template <typename T>
vc<T> operator+(const vc<T>& a, const vc<T>& b) {
  vc<T> c(max(len(a), len(b)));
  FOR(i, len(a)) c[i] += a[i];
  FOR(i, len(b)) c[i] += b[i];
  shrink(c);
  return c;
}

template <typename T>
vc<T> operator-(const vc<T>& a, const vc<T>& b) {
  vc<T> c(max(len(a), len(b)));
  FOR(i, len(a)) c[i] += a[i];
  FOR(i, len(b)) c[i] -= b[i];
  shrink(c);
  return c;
}

template <typename T>
vc<T> operator*(const vc<T>& a, const vc<T>& b) {
  return convolution(a, b);
}

template <typename T>
mat<T> operator*(const mat<T>& A, const mat<T>& B) {
  return {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],
          A[2] * B[0] + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};
}

template <typename T>
mat<T> step(const vc<T> q) {
  mat<T> Q;
  Q[1] = {1}, Q[2] = {1};
  Q[3] = Q[3] - q;
  return Q;
}

template <typename T>
arr<T> operator*(const mat<T>& A, const arr<T>& b) {
  return {A[0] * b[0] + A[1] * b[1], A[2] * b[0] + A[3] * b[1]};
}

template <typename T>
mat<T> hgcd(arr<T> a) {
  assert(len(a[0]) > len(a[1]) && len(a[1]) > 0);
  int m = len(a[0]) / 2;
  if (a[1].size() <= m) {
    mat<T> M;
    M[0] = {1}, M[3] = {1};
    return M;
  }
  auto R = hgcd(arr<T>({vc<T>(a[0].begin() + m, a[0].end()),
                        vc<T>(a[1].begin() + m, a[1].end())}));
  a = R * a;
  if (a[1].size() <= m) return R;
  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);
  R = Q * R, a = Q * a;
  if (a[1].size() <= m) return R;
  int k = 2 * m + 1 - len(a[0]);
  auto H = hgcd(arr<T>({vc<T>(a[0].begin() + k, a[0].end()),
                        vc<T>(a[1].begin() + k, a[1].end())}));
  return H * R;
}

template <typename T>
mat<T> cgcd(arr<T> a) {
  assert(a[0].size() > a[1].size() && !a[1].empty());
  auto m0 = hgcd(a);
  a = m0 * a;
  if (a[1].empty()) return m0;
  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);
  m0 = Q * m0, a = Q * a;
  if (a[1].empty()) return m0;
  return cgcd(a) * m0;
}

template <typename T>
tuple<vc<T>, vc<T>, vc<T>> poly_extgcd(const vc<T>& a, const vc<T>& b) {
  mat<T> Q = step(poly_divmod(a, b).fi);
  auto m = Q;
  auto ap = Q * arr<T>{a, b};
  if (!ap[1].empty()) m = cgcd(ap) * m;
  return {a * m[0] + b * m[1], m[0], m[1]};
}
} // namespace half_gcd
using half_gcd::poly_extgcd;