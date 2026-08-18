#include "ds/my_bitset.hpp"
#include "linalg/bitset/matrix_mul_mod_2.hpp"

vc<Bit_Array> matrix_pow(vc<Bit_Array> A, ll n) {
  int N = len(A);
  vc<Bit_Array> ret(N, Bit_Array(N));
  FOR(i, N) ret[i][i] = 1;
  while (n) {
    if (n & 1) ret = matrix_mul_mod_2(ret, A, N, N, N);
    n /= 2;
    if (n) A = matrix_mul_mod_2(A, A, N, N, N);
  }
  return ret;
}
