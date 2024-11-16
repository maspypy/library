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
