// [0, K) ^ N
template <typename F>
void enumerate_products(int K, int N, F query) {
  assert(N >= 0);
  auto dfs = [&](auto& dfs, vc<int>& p) -> void {
    if (len(p) == N) {
      query(p);
      return;
    }
    FOR(x, K) {
      p.eb(x);
      dfs(dfs, p);
      p.pop_back();
    }
  };
  vc<int> p;
  dfs(dfs, p);
}