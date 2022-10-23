#include "mod/fast_div.hpp"

int det_mod(vvc<int> A, int m) {
  fast_div mod(m);
  const int n = len(A);
  ll det = 1;
  FOR(i, n) {
    FOR(j, i, n) {
      if (A[j][i] == 0) continue;
      if (i != j) { swap(A[i], A[j]), det = m - det; }
      break;
    }
    FOR(j, i + 1, n) {
      while (A[i][i] != 0) {
        ll c = m - A[j][i] / A[i][i];
        FOR_R(k, i, n) { A[j][k] = (A[j][k] + A[i][k] * c) % mod; }
        swap(A[i], A[j]), det = m - det;
      }
      swap(A[i], A[j]), det = m - det;
    }
  }
  FOR(i, n) det = det * A[i][i] % mod;
  return det;
}