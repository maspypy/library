template <typename VC>
vc<VC> rot90(const vc<VC>& A, bool counter_clockwise = true, int H = -1,
             int W = -1) {
  if (H == -1) { H = len(A), W = len(A[0]); }
  vc<VC> B(W, VC(H, A[0][0]));
  if (counter_clockwise) {
    FOR(x, H) FOR(y, W) B[W - 1 - y][x] = A[x][y];
  } else {
    FOR(x, H) FOR(y, W) B[y][H - 1 - x] = A[x][y];
  }
  return B;
}
