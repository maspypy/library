// [0, N) ^ K
template <typename F>
void enumerate_products(int N, int K, F query, int LIM_len = -1, int LIM_val = -1) {
  assert(N >= 0);
  auto dfs = [&](auto& dfs, vc<int>& p) -> void {
    if (len(p) == K) {
      query(p);
      return;
    }
    FOR(x, N){
      p.eb(x);
      dfs(dfs, p);
      p.pop_back();
    }
  };
  vc<int> p;
  dfs(dfs, p);
}