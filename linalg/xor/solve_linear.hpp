// 行ベクトル
// Ax==0
ARR solve_linear_xor(ARR& mat) {
  int n = 0, m = 64;
  for (auto&& x: mat)
    if (x) ++n;
  int rk = 0;
  FOR(j, m) {
    if (rk == n) break;
    if (!(mat[rk] >> j & 1)) {
      FOR(i, rk + 1, n) if (mat[i] >> j & 1) {
        swap(mat[rk], mat[i]);
        break;
      }
    }
    if (!(mat[rk] >> j & 1)) continue;
    FOR(i, n) if (i != rk) {
      if (mat[i] >> j & 1) { mat[i] ^= mat[rk]; }
    }
    ++rk;
  }
  ARR res{};
  vc<int> pivot(m, -1);
  int p = 0;
  FOR(i, rk) {
    while (!(mat[i] >> p & 1)) ++p;
    pivot[p] = i;
  }
  int nxt = 0;
  FOR(j, m) if (pivot[j] == -1) {
    u64 x = 0;
    x |= u64(1) << j;
    FOR(k, j) if (pivot[k] != -1 && (mat[pivot[k]] >> j & 1)) {
      x |= u64(1) << k;
    }
    res[nxt++] = x;
  }
  return res;
}