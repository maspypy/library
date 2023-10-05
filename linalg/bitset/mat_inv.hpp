#include "ds/my_bitset.hpp"

// det = 0 の場合には empty をかえす
template <typename BS>
vc<BS> mat_inv(vc<BS> A) {
  int N = len(A);
  vc<BS> B(N);
  if constexpr (is_same_v<BS, My_Bitset>) { FOR(i, N) B[i] = BS(N); }
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
        A[k] ^= A[i];
        B[k] ^= B[i];
      }
    }
  }
  return B;
}
