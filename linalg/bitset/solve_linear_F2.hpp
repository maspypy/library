// bitset で高速化している
// (2000, 8000) で 300ms 程度（ABC276H）
template <int MAX_M, typename T = bool>
vvc<T> solve_linear_F2(const int n, const int m, vvc<T> a, vc<T> b) {
  using BS = bitset<MAX_M>;
  vc<BS> mat(n);
  FOR(i, n) FOR(j, m) mat[i][j] = a[i][j];
  int rk = 0;
  FOR(j, m) {
    if (rk == n) break;
    if (mat[rk][j] == 0) {
      FOR(i, rk + 1, n) if (mat[i][j] != 0) {
        swap(mat[rk], mat[i]);
        swap(b[rk], b[i]);
        break;
      }
    }
    if (mat[rk][j] == 0) continue;
    FOR(i, n) if (i != rk) {
      bool c = mat[i][j];
      if (c) {
        b[i] = b[i] ^ b[rk];
        mat[i] ^= mat[rk];
      }
    }
    ++rk;
  }
  FOR3(i, rk, n) if (b[i] != 0) return {};
  vv(T, res, 1, m);
  vc<int> pivot(m, -1);
  int p = 0;
  FOR(i, rk) {
    while (mat[i][p] == 0) ++p;
    res[0][p] = b[i];
    pivot[p] = i;
  }
  FOR(j, m) if (pivot[j] == -1) {
    vc<T> x(m);
    x[j] = 1;
    FOR(k, j) if (pivot[k] != -1) x[k] = mat[pivot[k]][j];
    res.eb(x);
  }
  return res;
}
