// [L, R) での極小値をひとつ求める、単峰は不要
template <typename T, bool MINIMIZE, typename F>
pair<ll, T> fibonacci_search(F f, ll L, ll R) {
  assert(L < R);
  --R;
  ll a = L, b = L + 1, c = L + 2, d = L + 3;
  int n = 0;
  while (d < R) { b = c, c = d, d = b + c - a, ++n; }
  auto get = [&](ll x) -> T {
    if (R < x) return infty<T>;
    return (MINIMIZE ? f(x) : -f(x));
  };
  T ya = get(a), yb = get(b), yc = get(c), yd = get(d);
  // この中で極小ならば全体でも極小、を維持する
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