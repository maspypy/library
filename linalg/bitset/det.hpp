#include "ds/my_bitset.hpp"

template <typename BS>
bool det(vc<BS> A) {
  int N = len(A);
  FOR(i, N) {
    FOR(k, i + 1, N) if (A[k][i]) {
      swap(A[k], A[i]);
      break;
    }
    if (!A[i][i]) return 0;
    FOR(k, i + 1, N) {
      if (A[k][i]) { A[k] ^= A[i]; }
    }
  }
  return 1;
}