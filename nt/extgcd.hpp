// {g,x,y}, ax+by=g
template <typename T>
tuple<T, T, T> extgcd(T a, T b) {
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

tuple<ll, ll, ll, ll> Farey_lr(ll a, ll b) {
  assert(a > 0 && b > 0);
  /*
  Farey 数列で、a/b が最初に現れるときの、左右を求める。
  a/b = 19/12 → (x1/y1, x2/y2) = (11/7, 8/5) → (11,7,8,5) を返す。
  */
  if (a == b) return {0, 1, 1, 0};
  ll q = (a - 1) / b;
  auto [x1, y1, x2, y2] = Farey_lr(b, a - q * b);
  return {q * x2 + y2, x2, q * x1 + y1, x1};
}

tuple<ll, ll, ll> extgcd2(ll a, ll b) {
  // ax + by = d の最小解 (x, y, d) を返す。
  // (|x|+|y|, x) に関する辞書順最小とする。
  auto [x1, y1, x2, y2] = Farey_lr(a, b);
  tie(x1, y1) = mp(y1, -x1);
  tie(x2, y2) = mp(-y2, x2);
  ll g = a * x1 + b * y1;
  pi key1 = mp(abs(x1) + abs(y1), x1);
  pi key2 = mp(abs(x2) + abs(y2), x2);
  return (key1 < key2 ? mt(x1, y1, g) : mt(x2, y2, g));
}
