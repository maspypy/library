// a+b/2^M の形で持つ
template <typename INTEGER>
struct Dyadic_Rational {
  using X = Dyadic_Rational;
  INTEGER a, b;
  static constexpr int M = std::numeric_limits<INTEGER>::digits - 2;

  Dyadic_Rational(INTEGER a = 0) : a(a), b(0) {}

  // x + y / z
  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER z) : a(x), b(y) {
    auto [q, r] = divmod(b, z);
    a += q;
    b = r;
    b *= (INTEGER(1) << M) / z;
  }

  // x/y
  Dyadic_Rational(INTEGER x, INTEGER y) : Dyadic_Rational(0, x, y) {}

  static X from_ab(INTEGER a, INTEGER b) {
    X x(a);
    x.b = b;
    return x;
  }

  // 比較
  bool operator==(X const& rhs) const { return (a == rhs.a && b == rhs.b); }
  bool operator!=(X const& rhs) const { return !(*this == rhs); }
  bool operator<(X const& rhs) const {
    return (a < rhs.a) || (a == rhs.a && b < rhs.b);
  }
  bool operator<=(X const& rhs) const {
    return (a < rhs.a) || (a == rhs.a && b <= rhs.b);
  }
  bool operator>(X const& rhs) const {
    return (a > rhs.a) || (a == rhs.a && b > rhs.b);
  }
  bool operator>=(X const& rhs) const {
    return (a > rhs.a) || (a == rhs.a && b >= rhs.b);
  }

  // 加法
  friend X operator+(const X& x, const X& y) {
    INTEGER a = x.a + y.a, b = x.b + y.b;
    while (b >= INTEGER(1) << M) {
      ++a;
      b -= INTEGER(1) << M;
    }
    return from_ab(a, b);
  }
  friend X operator-(const X& x, const X& y) {
    INTEGER a = x.a - y.a, b = x.b - y.b;
    while (b < 0) {
      --a;
      b += INTEGER(1) << M;
    }
    return from_ab(a, b);
  }
  friend X operator-(const X& x) {
    INTEGER a = -x.a, b = -x.b;
    while (b < 0) {
      --a;
      b += INTEGER(1) << M;
    }
    return from_ab(a, b);
  }
  X& operator+=(const X& x) { return (*this) = (*this) + x; }
  X& operator-=(const X& x) { return (*this) = (*this) - x; }

  static X simplest(const X& x, const X& y) {
    assert(x < y);
    if (y.a < 0) return -simplest(-y, -x);
    {
      INTEGER l = x.a + 1;
      INTEGER r = (y.b == 0 ? y.a - 1 : y.a);
      if (l <= 0 && 0 <= r) return X(0);
      if (l <= r && 0 <= l) return X(l);
      if (l <= r && r <= 0) return X(r);
    }

    INTEGER l = x.b + 1;
    INTEGER r = (y.b == 0 ? (INTEGER(1) << M) - 1 : y.b - 1);
    if (l == r) return from_ab(x.a, l);
    int k = topbit(l ^ r);
    r &= ~((INTEGER(1) << k) - 1);
    return from_ab(x.a, r);
  }

  static constexpr X infinity() { return from_ab(INTEGER(1) << M, 0); }

  string to_string() {
    ll x = a, y = b, z = INTEGER(1) << M;
    while (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }
    y += x * z;
    return std::to_string(y) + "/" + std::to_string(z);
  }
};