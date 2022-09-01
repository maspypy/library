// a/2^b の形で持つ
// a は i128 にもできるが、実用上足りるかは、演習量が足りていなくて不明
template <typename INTEGER = ll>
struct DyRational {
  using X = DyRational;
  INTEGER a;
  int b;

  DyRational(INTEGER _a = 0, int _b = 0) : a(_a), b(_b) {
    while (b && a % 2 == 0) { a /= 2, b--; }
  }

  friend X operator+(const X& x, const X& y) {
    int b = max(x.b, y.b);
    INTEGER a = ((x.a) << (b - x.b)) + ((y.a) << (b - y.b));
    return X(a, b);
  }
  friend X operator-(const X& x, const X& y) {
    int b = max(x.b, y.b);
    INTEGER a = ((x.a) << (b - x.b)) - ((y.a) << (b - y.b));
    return X(a, b);
  }
  X& operator+=(const X& x) { return (*this) = (*this) + x; }
  X& operator-=(const X& x) { return (*this) = (*this) - x; }

  friend bool operator<(const X& x, const X& y) { return (x - y).a < 0; }
  friend bool operator<=(const X& x, const X& y) { return (x - y).a <= 0; }
  friend bool operator>(const X& x, const X& y) { return (x - y).a > 0; }
  friend bool operator>=(const X& x, const X& y) { return (x - y).a >= 0; }
  friend bool operator==(const X& x, const X& y) { return (x - y).a == 0; }
  friend bool operator!=(const X& x, const X& y) { return (x - y).a != 0; }

  // x, y の間の simplest dyrational number を見つける
  static X find(const X& x, const X& y) {
    assert(x < y);
    FOR(k, max(x.b, y.b) + 1) {
      // floor(x)
      INTEGER xx = (x.a) >> (x.b - k);
      // ceil(y)
      INTEGER yy = ((y.a - 1) >> (y.b - k)) + 1;
      if (xx + 2 <= yy) {
        if (k != 0) return X(xx + 1, k);
        // [xx+1, yy-1] のうちで、絶対値最小のものを選ぶ
        if (xx + 1 >= 0) return X(xx + 1, 0);
        if (yy - 1 <= 0) return X(yy - 1, 0);
        return X(0, 0);
      }
    }
    int k = max(x.b, y.b) + 1;
    INTEGER xx = (x.a) << (k - x.b);
    return X(xx + 1, k);
  }

  void debug() { print(a, "/", INTEGER(1) << b); }
};