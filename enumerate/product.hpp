// [0, A0) x [0, A1) x ...
template <typename F>
void enumerate_product(vc<int> A, F query) {
  int N = len(A);
  auto dfs = [&](auto& dfs, vc<int>& p) -> void {
    int n = len(p);
    if (n == N) return query(p);
    FOR(x, A[n]) {
      p.eb(x);
      dfs(dfs, p);
      p.pop_back();
    }
  };
  vc<int> p;
  dfs(dfs, p);
}
