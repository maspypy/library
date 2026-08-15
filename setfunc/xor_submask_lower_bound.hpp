#include "other/bit.hpp"

// a <= b xor (submask S) となる中で右辺の最小
// なければ UINT(-1)
template <typename UINT>
UINT xor_submask_lower_bound(UINT a, UINT b, UINT S) {
  // a <= (b ^ submask(S)), minimize rhs
  b &= ~S;
  if (a <= b) return b;
  u32 c = b | S;
  if (a > c) return -1;
  u32 D = (a ^ b) & ~S;
  if (D == 0) return a;
  int k = topbit(D);
  if ((b >> k) & 1) {
    b |= (a & S) & ~full_mask(k + 1);
    return b;
  }
  u32 X = S & ~a;
  X &= ~full_mask(k + 1);
  k = lowbit(X);
  b |= (a & S) & ~full_mask(k + 1);
  b |= u32(1) << k;
  assert(a <= b);
  return b;
};