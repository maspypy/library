// Source: https://github.com/maspypy/library/blob/main/enumerate/product.hpp

// [0, A0) x [0, A1) x ...
template <typename F>
void enumerate_product(const vc<int>& A, F query) {
  int N = len(A);
  bool end = false;
  auto dfs = [&](auto& dfs, vc<int>& p) -> void {
    int n = len(p);
    if (n == N) return query(p, end);
    FOR(x, A[n]) {
      p.eb(x);
      dfs(dfs, p);
      p.pop_back();
      if (end) return;
    }
  };
  vc<int> p;
  dfs(dfs, p);
}
