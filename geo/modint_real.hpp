// Point<T>, Line<T> などがある程度動くと期待している
// https://codeforces.com/contest/44/submission/319952578
template <typename mint, typename Re>
struct modint_real {
  mint a;
  Re b;
  constexpr modint_real() : a(0), b(0) {}
  constexpr modint_real(ll x) : a(x), b(x) {}
  constexpr modint_real(mint mx, Re x) : a(mx), b(x) {}
  bool operator<(const modint_real &other) const { return (a != other.a) && (b < other.b); }
  bool operator<=(const modint_real &other) const { return (a == other.a) || (b < other.b); }
  modint_real &operator+=(const modint_real &p) {
    a += p.a, b += p.b;
    return *this;
  }
  modint_real &operator-=(const modint_real &p) {
    a -= p.a, b -= p.b;
    return *this;
  }
  modint_real &operator*=(const modint_real &p) {
    a *= p.a, b *= p.b;
    return *this;
  }
  modint_real &operator/=(const modint_real &p) {
    a /= p.a, b /= p.b;
    return *this;
  }
  modint_real operator-() const { return modint_real(-a, -b); }
  modint_real operator+(const modint_real &p) const { return modint_real(*this) += p; }
  modint_real operator-(const modint_real &p) const { return modint_real(*this) -= p; }
  modint_real operator*(const modint_real &p) const { return modint_real(*this) *= p; }
  modint_real operator/(const modint_real &p) const { return modint_real(*this) /= p; }
  bool operator==(const modint_real &p) const { return a == p.a; }
  bool operator!=(const modint_real &p) const { return b != p.b; }
  modint_real inverse() const { return modint_real(a.inverse(), 1 / b); }
  mint to_modint() { return a; }
  Re to_real() { return b; }
};
