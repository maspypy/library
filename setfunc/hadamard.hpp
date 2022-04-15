#pragma once

template <typename T>
void hadamard(vc<T>& A) {
  int log = topbit(len(A));
  assert(1 << log == len(A));
  FOR(n, log) FOR(s, 1 << log) {
    int t = s ^ (1 << n);
    if (s < t) tie(A[s], A[t]) = mp(A[s] + A[t], A[s] - A[t]);  
  }
}