
// https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120915/1347668163.html
// Prop 1
// 上三角 monge A, B
// C[i][j] = min_k (A[i][k] + B[k][j])
template <typename T, typename F1, typename F2>
vvc<T> monge_matrix_product(int N, F1 A, F2 B) {
  vv(T, C, N + 1, N + 1, infty<T>);
  vc<int> K(N + 1);
  FOR(i, N + 1) C[i][i] = A(i, i) + B(i, i), K[i] = i;
  FOR(s, 1, N + 1) {
    vc<int> newK(N + 1 - s);
    FOR(i, N + 1 - s) {
      int j = i + s;
      int p = K[i], q = K[i + 1];
      FOR(k, p, q + 1) if (chmin(C[i][j], A(i, k) + B(k, j))) newK[i] = k;
    }
    swap(K, newK);
  }
  return C;
}
