template <typename T>
vc<vc<T>> mat_inv(vc<vc<T>> A) {
  int N = len(A);
  vv(T, B, N, N);
  FOR(n, N) B[n][n] = 1;
  FOR(i, N) {
    FOR3(k, i, N) if (A[k][i] != 0) {
      if (k != i) swap(A[i], A[k]), swap(B[i], B[k]);
      break;
    }
    if (A[i][i] == 0) return {};
    T c = T(1) / A[i][i];
    FOR(j, N) {
      A[i][j] *= c;
      B[i][j] *= c;
    }
    FOR(k, N) if (i != k) {
      T c = A[k][i];
      FOR(j, N) A[k][j] -= A[i][j] * c;
      FOR(j, N) B[k][j] -= B[i][j] * c;
    }
  }
  return B;
}
