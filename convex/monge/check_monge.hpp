// 定義域 [0, N] の範囲で f の monge 性を確認
template <typename T, typename F>
bool check_monge(int N, F f) {
  FOR(l, N + 1) FOR(k, l) FOR(j, k) FOR(i, j) {
    T lhs = f(i, l) + f(j, k);
    T rhs = f(i, k) + f(j, l);
    if (lhs < rhs) {
      print("monge ng");
      print(i, j, k, l, f(i, k), f(i, l), f(j, k), f(j, l), lhs, rhs);
      return false;
    }
  }
  print("monge ok");
  return true;
}
