
template <typename T>
vvc<T> comb_table(int H, int W) {
  vv(T, C, H + 1, W + 1);
  C[0][0] = 1;
  FOR(x, H) {
    C[x + 1] = C[x];
    FOR(y, W) C[x + 1][y + 1] += C[x][y];
  }
  return C;
}