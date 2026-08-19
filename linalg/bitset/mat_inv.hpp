#include "ds/bit_array.hpp"

// det = 0 の場合には empty をかえす
template <typename BS>
vc<BS> mat_inv(vc<BS> A) {
  int N = len(A);
  vc<BS> B(N);
  if constexpr (is_same_v<BS, Bit_Array>) { FOR(i, N) B[i] = BS(N); }
  FOR(i, N) B[i][i] = 1;
  FOR(i, N) {
    FOR(k, i + 1, N) if (A[k][i]) {
      swap(A[k], A[i]);
      swap(B[k], B[i]);
      break;
    }
    if (!A[i][i]) return {};
    FOR(k, N) {
      if (i == k) continue;
      if (A[k][i]) {
        if constexpr (is_same_v<BS, Bit_Array>) {
          A[k].xor_suffix(i, A[i]);
          B[k] ^= B[i];
        } else {
          A[k] ^= A[i];
          B[k] ^= B[i];
        }
      }
    }
  }
  return B;
}
