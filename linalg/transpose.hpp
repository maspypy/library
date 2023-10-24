template <typename VC>
vc<VC> transpose(const vc<VC>& A, int H = -1, int W = -1) {
  if (H == -1) { H = len(A), W = len(A[0]); }
  vc<VC> B(W, VC(H, A[0][0]));
  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];
  return B;
}
