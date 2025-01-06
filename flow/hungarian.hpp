// returns: (ans, match, X, Y)
// N<=M を仮定, infty も valid として計算している, O(N^2M) time。
// ポテンシャルは次の双対問題の解である：
//   maximize \sum x_i + \sum y_j, subj to x_i + y_j\leq C_{ij}
// n ループで打ち切っても大きさ n のマッチングの最適解ではない
template <typename T, bool MINIMIZE>
tuple<T, vc<int>, vc<T>, vc<T>> hungarian(vvc<T>& C) {
  if (C.empty()) { return {0, {}, {}, {}}; }
  int N = len(C);
  int M = len(C[0]);
  assert(N <= M);
  vv(T, A, N + 1, M + 1);
  FOR(i, N) FOR(j, M) A[1 + i][1 + j] = (MINIMIZE ? 1 : -1) * C[i][j];
  ++N, ++M;

  vector<int> P(M), way(M);
  vector<T> X(N), Y(M);
  vc<T> minV;
  vc<bool> used;

  for (int i = 1; i < N; i++) {
    P[0] = i;
    minV.assign(M, infty<T>);
    used.assign(M, false);
    int j0 = 0;
    while (P[j0] != 0) {
      int i0 = P[j0], j1 = 0;
      used[j0] = true;
      T delta = infty<T>;
      for (int j = 1; j < M; j++) {
        if (used[j]) continue;
        T curr = A[i0][j] - X[i0] - Y[j];
        if (curr < minV[j]) minV[j] = curr, way[j] = j0;
        if (minV[j] < delta) delta = minV[j], j1 = j;
      }
      for (int j = 0; j < M; j++) {
        if (used[j])
          X[P[j]] += delta, Y[j] -= delta;
        else
          minV[j] -= delta;
      }
      j0 = j1;
    }
    do {
      P[j0] = P[way[j0]];
      j0 = way[j0];
    } while (j0 != 0);
  }
  T res = -Y[0];
  X.erase(X.begin());
  Y.erase(Y.begin());
  vc<int> match(N);
  FOR(i, N) match[P[i]] = i;
  match.erase(match.begin());
  for (auto&& i: match) --i;
  if (!MINIMIZE) res = -res;
  return {res, match, X, Y};
}
