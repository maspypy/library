
/*
https://codeforces.com/contest/1375/problem/I
Hurwitz integers
q=a+bi+cj+dk, a,b,c,d は全部整数または全部半整数
実装内部では q=(a+bi+cj+dk)/2 という a,b,c,d を持つ

立方体格子の特徴づけ
q: Hurwitz を用いて q (Zi+Zj+Zk) conjugate(q) と書ける
*/
template <typename T>
struct Hurwitz {
  static_assert(is_same_v<T, ll> || is_same_v<T, i128>);
  T a, b, c, d;
  Hurwitz(T a, T b, T c, T d) : a(a), b(b), c(c), d(d) { validate(); }
  Hurwitz(T x = 0) : a(2 * x), b(0), c(0), d(0) {}

  inline void validate() {
    assert((a + b) % 2 == 0 && (a + c) % 2 == 0 && (a + d) % 2 == 0);
  }

  Hurwitz conjugate() { return Hurwitz(a, -b, -c, -d); }
  bool is_real() { return (b == 0 && c == 0 && d == 0); }
  bool is_pure_imaginary() { return (a == 0); }
  bool is_zero() { return (a == 0 && b == 0 && c == 0 && d == 0); }

  Hurwitz &operator+=(const Hurwitz &p) {
    a += p.a, b += p.b, c += p.c, d += p.d;
    return *this;
  }
  Hurwitz &operator-=(const Hurwitz &p) {
    a -= p.a, b -= p.b, c -= p.c, d -= p.d;
    return *this;
  }
  Hurwitz &operator*=(const Hurwitz &p) {
    T a1 = (a * p.a - b * p.b - c * p.c - d * p.d) / 2;
    T b1 = (a * p.b + b * p.a + c * p.d - d * p.c) / 2;
    T c1 = (a * p.c - b * p.d + c * p.a + d * p.b) / 2;
    T d1 = (a * p.d + b * p.c - c * p.b + d * p.a) / 2;
    a = a1, b = b1, c = c1, d = d1;
    return *this;
  }
  Hurwitz operator-() const { return Hurwitz(-a, -b, -c, -d); }
  Hurwitz operator+(const Hurwitz &p) const { return Hurwitz(*this) += p; }
  Hurwitz operator-(const Hurwitz &p) const { return Hurwitz(*this) -= p; }
  Hurwitz operator*(const Hurwitz &p) const { return Hurwitz(*this) *= p; }
  bool operator==(const Hurwitz &p) const {
    return (a == p.a && b == p.b && c == p.c && d == p.d);
  }
  bool operator!=(const Hurwitz &p) const { return !(*(this) == p); }
  T norm() { return (a * a + b * b + c * c + d * d) / 4; }

  static Hurwitz next_even(Hurwitz x) {
    auto f = [&](T a) -> T { return a + (a & 1); };
    return Hurwitz(f(x.a), f(x.b), f(x.c), f(x.d));
  }
  static Hurwitz next_odd(Hurwitz x) {
    auto f = [&](T a) -> T { return a + 1 - (a & 1); };
    return Hurwitz(f(x.a), f(x.b), f(x.c), f(x.d));
  }

  // x/y=(q,r): x=yq+r. 割り切れるときに y が left divisor になる向き
  static pair<Hurwitz, Hurwitz> left_division(Hurwitz x, Hurwitz y) {
    Hurwitz z = y.conjugate() * x;
    T k = y.norm();
    Hurwitz q;
    q.a = floor<T>(z.a, k);
    q.b = floor<T>(z.b, k);
    q.c = floor<T>(z.c, k);
    q.d = floor<T>(z.d, k);
    Hurwitz q0 = next_even(q), q1 = next_odd(q);
    Hurwitz r0 = x - y * q0, r1 = x - y * q1;
    if (r0.norm() < r1.norm()) return {q0, r0};
    return {q1, r1};
  }

  // x/y=(q,r): x=qy+r. 割り切れるときに y が right divisor になる向き
  static pair<Hurwitz, Hurwitz> right_division(Hurwitz x, Hurwitz y) {
    Hurwitz z = x * y.conjugate();
    T k = y.norm();
    Hurwitz q;
    q.a = floor<T>(z.a, k);
    q.b = floor<T>(z.b, k);
    q.c = floor<T>(z.c, k);
    q.d = floor<T>(z.d, k);
    Hurwitz q0 = next_even(q), q1 = next_odd(q);
    Hurwitz r0 = x - q0 * y, r1 = x - q1 * y;
    if (r0.norm() < r1.norm()) return {q0, r0};
    return {q1, r1};
  }

  // x=gs, y=gt, g=xu+yv と書ける g
  static Hurwitz left_gcd(Hurwitz x, Hurwitz y) {
    while (!y.is_zero()) {
      x = left_division(x, y).se;
      swap(x, y);
    }
    return x;
  }

  // x=sg, y=tg, g=ux+vy と書ける g
  static Hurwitz right_gcd(Hurwitz x, Hurwitz y) {
    while (!y.is_zero()) {
      x = right_division(x, y).se;
      swap(x, y);
    }
    return x;
  }
};
