// floor(n log_2n) 回以下の comp call
template <class T, class Comp>
void merge_sort(vc<T>& A, Comp comp) {
  int n = A.size();
  vc<T> B;
  B.reserve(n);
  auto dfs = [&](auto& dfs, int l, int r) -> void {
    if (r - l <= 1) return;
    int m = (l + r) / 2;
    dfs(dfs, l, m), dfs(dfs, m, r);
    B.clear();
    int i = l, j = m;
    while (i < m || j < r) {
      if (j == r || (i < m && comp(A[i], A[j]))) {
        B.emplace_back(A[i++]);
      } else {
        B.emplace_back(A[j++]);
      }
    }
    FOR(k, len(B)) A[l + k] = B[k];
  };
  dfs(dfs, 0, n);
}
