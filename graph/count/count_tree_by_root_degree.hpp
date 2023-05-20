/*
ラベル付き木の数え上げ。頂点数と根の次数ごとに数え上げる。
*/
template <typename T>
T count_tree_by_root_degree(int n, int root_degree) {
  int d = root_degree;
  if (d <= 0 || d >= n) return T(0);
  d -= 1;
  return fact<T>(n - 2) * fact_inv<T>(d) * fact_inv<T>(n - 2 - d)
         * T(n - 1).pow(n - 2 - d);
}
