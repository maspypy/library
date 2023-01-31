/*
0 行目に解のひとつ。
1～行目に解空間の基底が行ベクトルとして入る。
解なし = empty
*/
template <typename T>
vc<vc<T>> solve_linear(const int n, const int m, vc<vc<T>> a, vc<T> b) {
  int rk = 0;
  FOR(j, m) {
    if (rk == n) break;
    if (a[rk][j] == 0) {
      FOR3(i, rk + 1, n) if (a[i][j] != 0) {
        swap(a[rk], a[i]);
        swap(b[rk], b[i]);
        break;
      }
    }
    if (a[rk][j] == 0) continue;
    T c = T(1) / a[rk][j];
    for (auto&& x: a[rk]) x *= c;
    b[rk] *= c;
    FOR(i, n) if (i != rk) {
      T c = a[i][j];
      b[i] -= b[rk] * c;
      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }
    }
    ++rk;
  }
  FOR3(i, rk, n) if (b[i] != 0) return {};
  vc<vc<T>> res(1, vc<T>(m));
  vc<int> pivot(m, -1);
  int p = 0;
  FOR(i, rk) {
    while (a[i][p] == 0) ++p;
    res[0][p] = b[i];
    pivot[p] = i;
  }
  FOR(j, m) if (pivot[j] == -1) {
    vc<T> x(m);
    x[j] = -1;
    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];
    res.eb(x);
  }
  return res;
}
