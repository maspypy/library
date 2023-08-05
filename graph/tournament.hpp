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
