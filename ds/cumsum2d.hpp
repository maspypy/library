template <typename T>
struct Cumsum2D {
  int H, W;
  vc<vc<T>> dat;

  Cumsum2D() {}
  Cumsum2D(vc<vc<T>>& A) { build(A); }

  void build(vc<vc<T>>& A) {
    int H = len(A);
    int W = (H == 0 ? 0 : len(A[0]));
    dat.assign(H + 1, vc<T>(W + 1));
    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];
    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] += dat[x][y];
    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] += dat[x][y];
  }

  T sum(int x1, int y1, int x2, int y2) {
    T val = T(0);
    val += dat[x1][y1];
    val -= dat[x1][y2];
    val -= dat[x2][y1];
    val += dat[x2][y2];
    return val;
  }
};