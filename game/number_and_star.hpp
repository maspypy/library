#include "game/dyadic_rational.hpp"
#include "other/mex.hpp"

struct Number_And_Star {
  using A = Dyadic_Rational<ll>;
  // a + *b
  A a;
  int b;
  using T = Number_And_Star;

  Number_And_Star(A a = 0, ll b = 0) : a(a), b(b) {}
  T& operator+=(const T& p) {
    a += p.a, b ^= p.b;
    return *this;
  }
  T& operator-=(const T& p) {
    a -= p.a, b ^= p.b;
    return *this;
  }
  T operator-() const { return T(-a, b); }
  bool operator==(const T& p) const { return (a == p.a && b == p.b); }

  // {計算できたか, 値}
  static pair<bool, T> from_options(vc<T> left_ops, vc<T> right_ops) {
    A xl = -A::infinity(), xr = A::infinity();
    vc<int> Lb, Rb;
    for (auto&& t: left_ops) {
      if (chmax(xl, t.a)) Lb.clear();
      if (xl == t.a) Lb.eb(t.b);
    }
    for (auto&& t: right_ops) {
      if (chmin(xr, t.a)) Rb.clear();
      if (xr == t.a) Rb.eb(t.b);
    }
    int Lm = mex(Lb), Rm = mex(Rb);
    if (xl < xr) {
      A a = A::simplest(xl, xr, Lm == 0, Rm == 0);
      return {true, T(a, 0)};
    }
    if (xl == xr) {
      if (Lm == Rm) return {true, T(xl, Lm)};
    }
    return {false, T(0, 0)};
  }

  string to_string() {
    string x = a.to_string();
    x += " + *";
    x += ::to_string(b);
    return x;
  }

  // L, R はそれぞれ自分手番のときに勝てるか？
  pair<bool, bool> outcome() {
    if (a > 0) return {1, 0};
    if (a < 0) return {0, 1};
    if (b == 0) return {0, 0};
    return {1, 1};
  }
};
