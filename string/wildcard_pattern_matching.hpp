#include "mod/modint.hpp"
#include "poly/ntt.hpp"
#include "poly/middle_product.hpp"

vc<bool> wildcard_pattern_matching(string S, string T, char WILD = '?') {
  using mint = modint998;
  int N = len(S), M = len(T);
  int mi = 1024;
  for (auto&& x: S)
    if (x != '?') chmin(mi, x);
  for (auto&& x: T)
    if (x != '?') chmin(mi, x);
  vc<mint> f1(N), g1(M);
  FOR(i, N) f1[i] = (S[i] == '?' ? 0 : S[i] - mi + 1);
  FOR(i, M) g1[i] = (T[i] == '?' ? 0 : T[i] - mi + 1);
  vc<mint> f2(N), f3(N), g2(M), g3(M);
  FOR(i, N) f2[i] = f1[i] * f1[i], f3[i] = f2[i] * f1[i];
  FOR(i, M) g2[i] = g1[i] * g1[i], g3[i] = g2[i] * g1[i];
  vc<mint> A = middle_product(f1, g3);
  vc<mint> B = middle_product(f2, g2);
  vc<mint> C = middle_product(f3, g1);
  FOR(i, len(A)) A[i] = A[i] - B[i] - B[i] + C[i];
  vc<bool> res(len(A));
  FOR(i, len(res)) res[i] = A[i] == mint(0);
  return res;
}