// Eulerian number
// sum n^dx^n = A_d(x) / (1-x)^{d+1} となる d 次多項式の係数列
template <typename mint>
vvc<mint> eulerian_number_2d(int N, int K) {
  vv(mint, A, N + 1, K + 1);
  A[0][0] = mint(1);
  FOR(d, N) FOR(k, 1, K + 1) {
    A[d + 1][k] = mint(k) * A[d][k] + mint(d - k + 2) * A[d][k - 1];
  }
  return A;
}
