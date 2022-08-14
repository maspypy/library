#include "poly/convolution.hpp"

template <typename mint>
mint coef_of_rational_fps(vector<mint> A, vector<mint> B, ll N) {
  if (len(A) == 0) return 0;
  assert(len(A) < len(B));
  while (len(A) + 1 < len(B)) A.eb(0);
  assert(B[0] == mint(1));
  assert(len(B) == len(A) + 1);
  while (N) {
    vc<mint> B1 = B;
    FOR(i, len(B1)) if (i & 1) B1[i] = -B1[i];
    A = convolution(A, B1);
    B = convolution(B, B1);
    FOR(i, len(B1)) B[i] = B[2 * i];
    if (N & 1) {
      FOR(i, len(B1) - 1) A[i] = A[2 * i | 1];
    } else {
      FOR(i, len(B1) - 1) A[i] = A[2 * i];
    }
    A.resize(len(B1) - 1);
    B.resize(len(B1));
    N /= 2;
  }
  return A[0];
}