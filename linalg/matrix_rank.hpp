template <typename T>
int matrix_rank(vc<vc<T>> a, int n = -1, int m = -1) {
  if (n == 0) return 0;
  if (n == -1) { n = len(a), m = len(a[0]); }
  assert(n == len(a) && m == len(a[0]));
  int rk = 0;
  FOR(j, m) {
    if (rk == n) break;
    if (a[rk][j] == 0) {
      FOR(i, rk + 1, n) if (a[i][j] != T(0)) {
        swap(a[rk], a[i]);
        break;
      }
    }
    if (a[rk][j] == 0) continue;
    T c = T(1) / a[rk][j];
    FOR(k, j, m) a[rk][k] *= c;
    FOR(i, rk + 1, n) {
      T c = a[i][j];
      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }
    }
    ++rk;
  }
  return rk;
}
