// N 元 K 種類の多重集合の頻度列つまり
// a[0]+...+a[K-1]==N
template <typename F>
void enumerate_multiset(int N, int K, F query) {
  vc<int> A(K);
  auto dfs = [&](auto& dfs, int p, int s) -> void {
    if (p == K) {
      if (s == 0) query(A);
      return;
    }
    FOR(x, s + 1) {
      A[p] = x;
      dfs(dfs, p + 1, s - x);
    }
  };
  dfs(dfs, 0, N);
}
