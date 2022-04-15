template <typename T>
T det(vc<vc<T>> A) {
  T det = T(1);
  while (len(A)) {
    int n = len(A);
    int k = n;
    FOR_R(i, n) if (A[i].back() != 0) {
      k = i;
      break;
    }
    if (k == n) return T(0);
    if (k != n - 1) {
      det *= (-1);
      swap(A[k], A[n - 1]);
    }
    det *= A[n - 1][n - 1];
    FOR(i, n - 1) {
      T c = A[i].back() / A[n - 1].back();
      A[i].pop_back();
      FOR(j, n - 1) A[i][j] -= A[n - 1][j] * c;
    }
    A.pop_back();
  }
  return det;
}
