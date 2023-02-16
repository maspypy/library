// 閉区間 [L, R] での凸関数の最小化
// L, R は long long、T は i128 可
template <typename T, bool MINIMIZE, typename F>
pair<ll, T> fibonacci_search(F f, ll L, ll R) {
  ll a = L, b = L + 1, c = L + 2, d = L + 3;
  int n = 0;
  while (d < R) { b = c, c = d, d = b + c - a, ++n; }
  auto get = [&](ll x) -> T {
    if (R < x) return infty<T>;
    return (MINIMIZE ? f(x) : -f(x));
  };
  T ya = get(a), yb = get(b), yc = get(c), yd = get(d);
  FOR(n) {
    if (yb < yc) {
      d = c, c = b, b = a + d - c;
      yd = yc, yc = yb, yb = get(b);
    } else {
      a = b, b = c, c = a + d - b;
      ya = yb, yb = yc, yc = get(c);
    }
  }
  ll x = a;
  T y = ya;
  if (chmin(y, yb)) x = b;
  if (chmin(y, yc)) x = c;
  if (chmin(y, yd)) x = d;
  if (MINIMIZE) return {x, y};
  return {x, -y};
}