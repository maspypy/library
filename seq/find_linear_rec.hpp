
#include "poly/poly_gcd.hpp"

// template <typename mint>
// vector<mint> find_linear_rec(vector<mint>& A) {
//   int N = len(A);
//   vc<mint> B = {1}, C = {1};
//   int l = 0, m = 1;
//   mint p = 1;
//   FOR(i, N) {
//     mint d = A[i];
//     FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }
//     if (d == 0) {
//       ++m;
//       continue;
//     }
//     auto tmp = C;
//     mint q = d / p;
//     if (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);
//     FOR(j, len(B)) C[j + m] -= q * B[j];
//     if (l + l <= i) {
//       B = tmp;
//       l = i + 1 - l, m = 1;
//       p = d;
//     } else {
//       ++m;
//     }
//   }
//   return C;
// }

namespace half_gcd {
template <typename T>
vector<T> find_linear_rec(vc<T>& F) {
  vc<T> f = F;
  int d = len(f);
  reverse(all(f));
  while (len(f) && f.back() == T(0)) POP(f);
  if (f.empty()) return vc<T>{T(1)};
  vc<T> g(d + 1);
  g.back() = T(1);
  auto m = hgcd(arr<T>{g, f});
  auto a = m * arr<T>{g, f};
  if (len(a[1]) > d - len(a[0]) + 1) m = step(poly_divmod(a[0], a[1]).fi) * m;
  vc<T> Q = m[3];
  T v = Q.back().inverse();
  for (auto& x : Q) x *= v;
  reverse(all(Q));
  return Q;
}
};  // namespace half_gcd
using half_gcd::find_linear_rec;