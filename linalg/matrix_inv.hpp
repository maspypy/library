// (det, invA) をかえす
template <typename T>
pair<T, vc<vc<T>>> matrix_inv(vc<vc<T>> A) {
  T det = 1;
  int N = len(A);
  vv(T, B, N, N);
  FOR(n, N) B[n][n] = 1;
  FOR(i, N) {
    FOR(k, i, N) if (A[k][i] != 0) {
      if (k != i) {
        swap(A[i], A[k]), swap(B[i], B[k]);
        det = -det;
      }
      break;
    }
    if (A[i][i] == 0) return {T(0), {}};
    T c = T(1) / A[i][i];
    det *= A[i][i];
    FOR(j, i, N) A[i][j] *= c;
    FOR(j, N) B[i][j] *= c;
    FOR(k, N) if (i != k) {
      T c = A[k][i];
      FOR(j, i, N) A[k][j] -= A[i][j] * c;
      FOR(j, N) B[k][j] -= B[i][j] * c;
    }
  }
  return {det, B};
}
