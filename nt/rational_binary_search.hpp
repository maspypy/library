
// 0/1 OK, 1/0 NG. 3N がオーバーフローしない. unsigned OK.
// return : (a,b,c,d) such that a/b OK, c/d NG.
template <typename T, typename F>
tuple<T, T, T, T> rational_binary_search(F check, T N) {
  assert(check(0, 1) && !check(1, 0));
  auto dfs = [&](auto& dfs, bool side, T& a, T& b, T c, T d) -> void {
    if (a + c > N || b + d > N) return;
    if (check(a + c, b + d) == side) {
      a += c, b += d;
      dfs(dfs, side, a, b, c + c, d + d);
    }
    if (a + c <= N && b + d <= N && check(a + c, b + d) == side) a += c, b += d;
  };

  T a = 0, b = 1, c = 1, d = 0;
  while (a + c <= N && b + d <= N) { dfs(dfs, true, a, b, c, d), dfs(dfs, false, c, d, a, b); }
  return {a, b, c, d};
}
