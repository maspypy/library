#include "poly/convolution.hpp"
#include "mod/primitive_root.hpp"

// C[k] = sum[k=ij mod p] A[i]B[j]
template <typename mint>
vc<mint> multiplicative_convolution_mod_p(int p, vc<mint>& A, vc<mint>& B) {
  assert(len(A) == p && len(B) == p);
  int r = primitive_root(p);
  vc<int> exp(p - 1), log(p);
  exp[0] = 1;
  FOR(i, p - 2) exp[i + 1] = exp[i] * ll(r) % p;
  FOR(i, p - 1) log[exp[i]] = i;

  vc<mint> FA(p - 1), FB(p - 1);
  FOR(i, p - 1) FA[i] = A[exp[i]], FB[i] = B[exp[i]];
  vc<mint> FC = convolution(FA, FB);
  FOR(i, p - 1, len(FC)) FC[i - (p - 1)] += FC[i];

  vc<mint> C(p);
  FOR(i, 1, p) C[i] = FC[log[i]];

  mint SA = SUM<mint>(A), SB = SUM<mint>(B);
  C[0] += SA * B[0] + SB * A[0] - A[0] * B[0];
  return C;
}