// 下三角行列を仮定。とりあえず正則も仮定。
template <typename T>
vc<T> solve_linear_lower(vc<vc<T>> a, vc<T> b) {
  auto n = len(a);
  FOR(i, n) assert(a[i][i] != T(0));
  FOR(i, n) FOR(j, i + 1, n) assert(a[i][j] == T(0));
  FOR(i, n) {
    {
      T c = T(1) / a[i][i];
      a[i][i] *= c;
      b[i] *= c;
    }
    FOR(j, i + 1, n) {
      b[j] -= b[i] * a[j][i];
      a[j][i] = T(0);
    }
  }
  return b;
}
