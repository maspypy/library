#pragma once

template <typename T>
void superset_zeta(vc<T>& A) {
  int log = topbit(len(A));
  assert(1 << log == len(A));
  FOR(n, log) FOR(s, 1 << log) {
    int t = s ^ (1 << n);
    if (s < t) A[s] += A[t];
  }
}

template <typename T>
void superset_mobius(vc<T>& A) {
  int log = topbit(len(A));
  assert(1 << log == len(A));
  FOR(n, log) FOR(s, 1 << log) {
    int t = s ^ (1 << n);
    if (s < t) A[s] -= A[t];
  }
}

template <typename T>
void subset_zeta(vc<T>& A) {
  int log = topbit(len(A));
  assert(1 << log == len(A));
  FOR(n, log) FOR(s, 1 << log) {
    int t = s ^ (1 << n);
    if (s > t) A[s] += A[t];
  }
}

template <typename T>
void subset_mobius(vc<T>& A) {
  int log = topbit(len(A));
  assert(1 << log == len(A));
  FOR(n, log) FOR(s, 1 << log) {
    int t = s ^ (1 << n);
    if (s > t) A[s] -= A[t];
  }
}