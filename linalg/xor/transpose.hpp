// n x m 行列の transpose。O((n+m)log(n+m)) 時間。
// https://github.com/dsnet/matrix-transpose
template <typename UINT>
vc<UINT> transpose(int n, int m, vc<UINT> mat) {
  assert(max(n, m) <= numeric_limits<UINT>::digits);
  assert(len(mat) == n);
  int LOG = 0;
  while ((1 << LOG) < max(n, m)) ++LOG;
  mat.resize(1 << LOG);
  int width = 1 << LOG;
  UINT mask = 1;
  FOR(i, LOG) mask = mask | (mask << (1 << i));
  FOR(t, LOG) {
    width >>= 1;
    mask = mask ^ (mask >> width);
    FOR(i, 1 << t) {
      FOR(j, width) {
        UINT* x = &mat[width * (2 * i + 0) + j];
        UINT* y = &mat[width * (2 * i + 1) + j];
        *x = ((*y << width) & mask) ^ *x;
        *y = ((*x & mask) >> width) ^ *y;
        *x = ((*y << width) & mask) ^ *x;
      }
    }
  }
  mat.resize(m);
  return mat;
}