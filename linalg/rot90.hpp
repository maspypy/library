template <typename VC>
vc<VC> rot90(const int n, const int m, const vc<VC>& A,
             bool counter_clockwise = true) {
  vc<VC> B(m, VC(n, A[0][0]));
  if (counter_clockwise) {
    FOR(x, n) FOR(y, m) B[m - 1 - y][x] = A[x][y];
  } else {
    FOR(x, n) FOR(y, m) B[y][n - 1 - x] = A[x][y];
  }
  return B;
}
