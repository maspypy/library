// x^2 - Dy^2 == pm 1, 正の最小解 1<=x<=LIM_X, なければ (0,0), O(log(ANS))
// T で (LIM_X)^2 程度がオーバーフローしない
template <typename T>
pair<T, T> pell_equation(ll D, const bool RHS_EQUAL_ONE, T LIM_X = -1) {
  static_assert(!std::is_same<T, u32>::value);
  static_assert(!std::is_same<T, u64>::value);
  static_assert(!std::is_same<T, u128>::value);
  assert(D > 0);
  ll x0 = sqrtl(D);
  if (x0 * x0 == D) return {0, 0};
  T a = x0, b = 1, c = x0 + 1, d = 1;

  auto f = [&](T x, T y) -> T { return x * x - y * y * T(D); };

  auto dfs = [&](auto& dfs, auto check, T& a, T& b, T c, T d) -> void {
    if (LIM_X != -1 && a + c > LIM_X) return;
    if (check(a + c, b + d)) { dfs(dfs, check, a, b, c + c, d + d); }
    if (check(a + c, b + d)) a += c, b += d;
  };

  if (f(a, b) == T(-1)) return {a, b};
  if (f(c, d) == T(1)) return {c, d};
  while (1) {
    auto check_1 = [&](T x, T y) -> bool { return f(x, y) < 0; };
    dfs(dfs, check_1, a, b, c, d);
    if (!RHS_EQUAL_ONE && f(a, b) == T(-1)) { return {a, b}; }
    auto check_2 = [&](T x, T y) -> bool { return f(x, y) > 0; };
    dfs(dfs, check_2, c, d, a, b);
    if (f(c, d) == T(1)) return {c, d};
    if (LIM_X != -1 && a + c > LIM_X) break;
  }
  return {0, 0};
}