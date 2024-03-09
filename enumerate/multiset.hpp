// a[0]+...+a[N-1]==K
template <typename F>
void enumerate_multiset(int K, int N, F query) {
  vc<int> A(N);
  auto dfs = [&](auto& dfs, int p, int s) -> void {
    if (p == N) {
      if (s == 0) query(A);
      return;
    }
    FOR(x, s + 1) {
      A[p] = x;
      dfs(dfs, p + 1, s - x);
    }
  };
  dfs(dfs, 0, K);
}
