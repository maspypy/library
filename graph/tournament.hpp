// https://yukicoder.me/problems/no/2085
// https://codeforces.com/problemset/problem/412/D
template <typename F>
vc<int> hamiltonian_path_in_tournament(int n, F check) {
  auto dfs = [&](auto& dfs, int L, int R) -> vc<int> {
    if (R == L + 1) return {L};
    int M = (L + R) / 2;
    vc<int> X = dfs(dfs, L, M);
    vc<int> Y = dfs(dfs, M, R);
    vc<int> P;
    P.reserve(R - L);
    int i = 0, j = 0;
    while (len(P) < R - L) {
      if (i == len(X)) { P.eb(Y[j++]); }
      elif (j == len(Y)) { P.eb(X[i++]); }
      else {
        if (check(X[i], Y[j])) {
          P.eb(X[i++]);
        } else {
          P.eb(Y[j++]);
        }
      }
    }
    return P;
  };
  return dfs(dfs, 0, n);
}

// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_l
vc<string> from_outdegrees(vc<int> A) {
  int N = len(A);
  vc<int> F(N);
  for (auto& x: A) F[x]++;

  vc<string> ANS(N, string(N, '-'));
  FOR(i, N) {
    int lose = N - 1 - i - A[i];
    F[A[i]]--;
    FOR(j, i + 1, N) { ANS[i][j] = '1', ANS[j][i] = '0'; }
    int p = N;
    FOR_R(x, N) {
      int k = min(lose, F[x]);
      p -= F[x];
      FOR(j, p, p + k) { ANS[i][j] = '0', ANS[j][i] = '1'; }
      lose -= k;
    }
    FOR(j, i + 1, N) {
      if (ANS[i][j] == '0') {
        F[A[j]]--;
        A[j]--;
        F[A[j]]++;
      }
    }
  }
  return ANS;
}