
// return: 2^M integers
// time: (N+M)^3+2^M
template <typename T>
vc<int> rank_for_all_column_subset(vvc<T> A, int N, int M) {
  assert(len(A) == N);
  FOR(i, N) assert(len(A[i]) == M);
  int rk = 0;
  FOR(j, M) {
    if (rk == N) break;
    FOR(i, rk, N) if (A[i][j] != 0) {
      swap(A[rk], A[i]);
      break;
    }
    if (A[rk][j] == 0) continue;
    T c = T(1) / A[rk][j];
    for (auto&& x: A[rk]) x *= c;
    FOR(i, N) if (i != rk) {
      T c = A[i][j];
      FOR(k, j, M) { A[i][k] -= A[rk][k] * c; }
    }
    ++rk;
  }
  A.resize(rk);

  /*
  ある行
  (M,M) matrix の対角に置く
  1**00*0*
  00000000
  00000000
  00010*0*
  00001*0*
  00000000
  0000001*
  00000000
  先頭列から順に処理する.
  */

  N = M;
  vv(T, work, N, N);
  vvv(T, memo, N, N, N);
  for (auto& X: A) {
    int p = 0;
    FOR_R(i, N) if (X[i] != 0) p = i;
    work[p] = X;
  }

  vc<int> ANS(1 << M);
  auto dfs = [&](auto& dfs, int s, int k, int r) -> void {
    if (k == N) {
      ANS[s] = r;
      return;
    }
    if (work[k][k] == T(0)) {
      // 使うにしても使わないにしても rank には影響しない
      dfs(dfs, s, k + 1, r);
      dfs(dfs, s | 1 << k, k + 1, r);
      return;
    }
    assert(work[k][k] == T(1));
    // 使う場合 : そのまま submatrix について解く
    dfs(dfs, s | 1 << k, k + 1, r + 1);
    // 使わない場合
    int p = -1;
    FOR(i, k + 1, N) {
      if (work[k][i] != T(0)) {
        p = i;
        break;
      }
    }
    if (p == -1) { return dfs(dfs, s, k + 1, r); }
    // snapshot
    FOR(i, k + 1, N) FOR(j, k + 1, N) memo[k][i][j] = work[i][j];
    T c = T(1) / work[k][p];
    FOR(j, p, N) work[p][j] = work[k][j] * c;
    FOR(i, k + 1, p) {
      T c = work[i][p];
      FOR(j, p, N) work[i][j] -= c * work[p][j];
    }
    dfs(dfs, s, k + 1, r);
    // rollback
    FOR(i, k + 1, N) FOR(j, k + 1, N) work[i][j] = memo[k][i][j];
  };
  dfs(dfs, 0, 0, 0);
  return ANS;
}