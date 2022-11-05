// vvc<T> と vc<string> を想定
template <typename VC>
vc<VC> transpose(const int n, const int m, const vc<VC>& A) {
  vc<VC> B(m, VC(n, A[0][0]));
  FOR(x, n) FOR(y, m) B[y][x] = A[x][y];
  return B;
}
