#include "mod/barrett.hpp"

int det_mod(vvc<int> A, int mod) {
  Barrett bt(mod);
  const int n = len(A);
  ll det = 1;
  FOR(i, n) {
    FOR(j, i, n) {
      if (A[j][i] == 0) continue;
      if (i != j) { swap(A[i], A[j]), det = mod - det; }
      break;
    }
    FOR(j, i + 1, n) {
      while (A[i][i] != 0) {
        ll c = mod - A[j][i] / A[i][i];
        FOR_R(k, i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }
        swap(A[i], A[j]), det = mod - det;
      }
      swap(A[i], A[j]), det = mod - det;
    }
  }
  FOR(i, n) det = bt.mul(det, A[i][i]);
  return det % mod;
}

template <typename mint>
mint det(vvc<mint>& A) {
  const int n = len(A);
  vv(int, B, n, n);
  FOR(i, n) FOR(j, n) B[i][j] = A[i][j].val;
  return det_mod(B, mint::get_mod());
}
