template <typename T = long long, bool REDUCE = true>
struct Rational {
  T num, den;

  Rational() : num(0), den(1) {}
  Rational(T x) : num(x), den(1) {}
  Rational(T a, T b, bool coprime = false) : num(a), den(b) {
    if (den < 0) num = -num, den = -den;
    if (!coprime && REDUCE) reduce();
  }

  static T gcd(T a, T b) {
    a = max(a, -a), b = max(b, -b);
    while (b) {
      a %= b;
      swap(a, b);
    }
    return a;
  }

  void reduce() {
    if constexpr (!REDUCE) {
      return;
    } else {
      T g = gcd(num, den);
      num /= g, den /= g;
    }
  }

  Rational &operator+=(const Rational &p) {
    if constexpr (!REDUCE) {
      num = num * p.den + p.num * den;
      den *= p.den;
      return *this;
    } else {
      T g = (REDUCE ? gcd(den, p.den) : 1);
      num = num * (p.den / g) + p.num * (den / g);
      den *= p.den / g;
      reduce();
      return *this;
    }
  }
  Rational &operator-=(const Rational &p) {
    if constexpr (!REDUCE) {
      num = num * p.den - p.num * den;
      den *= p.den;
      return *this;
    } else {
      T g = (REDUCE ? gcd(den, p.den) : 1);
      num = num * (p.den / g) - p.num * (den / g);
      den *= p.den / g;
      reduce();
      return *this;
    }
  }
  Rational &operator*=(const Rational &p) {
    if constexpr (!REDUCE) {
      num = num * p.num;
      den = den * p.den;
      return *this;
    } else {
      T g1 = gcd(num, p.den);
      T g2 = gcd(den, p.num);
      num = (num / g1) * (p.num / g2);
      den = (den / g2) * (p.den / g1);
      return *this;
    }
  }
  Rational &operator/=(const Rational &p) {
    T g1 = (REDUCE ? gcd(num, p.num) : 1);
    T g2 = (REDUCE ? gcd(den, p.den) : 1);
    num = (num / g1) * (p.den / g2);
    den = (den / g2) * (p.num / g1);
    if (den < 0) num = -num, den = -den;
    return *this;
  }

  Rational operator-() const { return Rational(-num, den); }
  Rational operator+(const Rational &p) const { return Rational(*this) += p; }
  Rational operator-(const Rational &p) const { return Rational(*this) -= p; }
  Rational operator*(const Rational &p) const { return Rational(*this) *= p; }
  Rational operator/(const Rational &p) const { return Rational(*this) /= p; }
  bool operator==(const Rational &p) const {
    return num * p.den == p.num * den;
  }
  bool operator!=(const Rational &p) const {
    return num * p.den != p.num * den;
  }
  bool operator<(const Rational &p) const { return num * p.den < p.num * den; }
  bool operator>(const Rational &p) const { return num * p.den > p.num * den; }
  bool operator<=(const Rational &p) const {
    return num * p.den <= p.num * den;
  }
  bool operator>=(const Rational &p) const {
    return num * p.den >= p.num * den;
  }

  string to_string() {
    auto f = [&](T x) -> string {
      // i128
      bool neg = 0;
      string ans;
      if (x < 0) neg = 1, x = -x;
      while (x) ans += '0' + (x % 10), x /= 10;
      reverse(all(ans));
      if (ans.empty()) ans = "0";
      return (neg ? "-" + ans : ans);
    };
    return f(num) + "/" + f(den);
  }
  double to_double() { return double(num) / double(den); }
};
