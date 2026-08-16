// {g,x,y}, ax+by=g
template <typename T>
tuple<T, T, T> ext_gcd(T a, T b) {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  T x = 1, y = 0, x1 = 0, y1 = 1;
  while (b != 0) {
    T q = a / b;
    swap(a %= b, b);
    T X = x - q * x1, Y = y - q * y1;
    x = x1, y = y1, x1 = X, y1 = Y;
  }
  return {a, x, y};
}

tuple<ll, ll, ll, ll> farey_lr(ll a, ll b) {
  assert(a > 0 && b > 0);
  /*
  Farey 数列で、a/b が最初に現れるときの、左右を求める。
  a/b = 19/12 → (x1/y1, x2/y2) = (11/7, 8/5) → (11,7,8,5) を返す。
  */
  if (a == b) return {0, 1, 1, 0};
  ll q = (a - 1) / b;
  auto [x1, y1, x2, y2] = farey_lr(b, a - q * b);
  return {q * x2 + y2, x2, q * x1 + y1, x1};
}
