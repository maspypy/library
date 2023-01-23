// [0, K) 内の広義単調増加列
template <typename F>
void enumerate_multiset(int K, int N, F query) {
  vc<int> A(N);
  auto dfs = [&](auto& dfs, int p, int s) -> void {
    if (p == N) {
      query(A);
      return;
    }
    FOR(x, s, K) {
      A[p] = x;
      dfs(dfs, p + 1, x);
    }
  };
  dfs(dfs, 0, 0);
}
