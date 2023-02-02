// solve Ax = b を解く。[0] に特殊解、[1]～ に Ker A の基底が入る。解なしは
// empty。 A の行ベクトルを UINT で持たせる。
template <typename UINT>
vc<UINT> solve_linear(int n, int m, vc<UINT>& A, UINT b) {
  assert(max(n, m) <= numeric_limits<UINT>::digits);
  assert(len(A) == n);
  int rk = 0;
  FOR(j, m) {
    if (rk == n) break;
    FOR(i, rk, n) if (A[i] >> j & 1) {
      if (i == rk) break;
      swap(A[rk], A[i]);
      if ((b >> rk & 1) != (b >> i & 1)) b ^= (UINT(1) << rk) | (UINT(1) << i);
      break;
    }
    if (!(A[rk] >> j & 1)) continue;
    FOR(i, n) if (i != rk) {
      if (A[i] >> j & 1) {
        A[i] ^= A[rk];
        b ^= (b >> rk & 1) << i;
      }
    }
    ++rk;
  }
  if (b >> rk) { return {}; }
  vc<UINT> res(1);
  vc<int> pivot(m, -1);
  int p = 0;
  FOR(i, rk) {
    while (!(A[i] >> p & 1)) ++p;
    res[0] |= (b >> i & 1) << p;
    pivot[p] = i;
  }
  FOR(j, m) if (pivot[j] == -1) {
    UINT x = 0;
    x |= UINT(1) << j;
    FOR(k, j) if (pivot[k] != -1 && (A[pivot[k]] >> j & 1)) {
      x |= UINT(1) << k;
    }
    res.eb(x);
  }
  return res;
}