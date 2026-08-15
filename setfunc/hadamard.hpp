
#include "setfunc/bitwise_transform.hpp"

// B[j] = sum_i (-1)^{popcnt(i&j)} A[i]
// len(A) は 2^25 以下の 2 冪を仮定。2^k で割ることはしていない。
template <typename T>
void hadamard(vc<T>& A) {
  bitwise::bitwise_transform<bitwise::trans_type::hadamard>(A);
}
