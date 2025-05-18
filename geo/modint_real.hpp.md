---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/44/submission/319952578
  bundledCode: "#line 1 \"geo/modint_real.hpp\"\n// Point<T>, Line<T> \u306A\u3069\
    \u304C\u3042\u308B\u7A0B\u5EA6\u52D5\u304F\u3068\u671F\u5F85\u3057\u3066\u3044\
    \u308B\n// https://codeforces.com/contest/44/submission/319952578\ntemplate <typename\
    \ mint, typename Re>\nstruct modint_real {\n  mint a;\n  Re b;\n  constexpr modint_real()\
    \ : a(0), b(0) {}\n  constexpr modint_real(ll x) : a(x), b(x) {}\n  constexpr\
    \ modint_real(mint mx, Re x) : a(mx), b(x) {}\n  bool operator<(const modint_real\
    \ &other) const { return (a != other.a) && (b < other.b); }\n  bool operator<=(const\
    \ modint_real &other) const { return (a == other.a) || (b < other.b); }\n  modint_real\
    \ &operator+=(const modint_real &p) {\n    a += p.a, b += p.b;\n    return *this;\n\
    \  }\n  modint_real &operator-=(const modint_real &p) {\n    a -= p.a, b -= p.b;\n\
    \    return *this;\n  }\n  modint_real &operator*=(const modint_real &p) {\n \
    \   a *= p.a, b *= p.b;\n    return *this;\n  }\n  modint_real &operator/=(const\
    \ modint_real &p) {\n    a /= p.a, b /= p.b;\n    return *this;\n  }\n  modint_real\
    \ operator-() const { return modint_real(-a, -b); }\n  modint_real operator+(const\
    \ modint_real &p) const { return modint_real(*this) += p; }\n  modint_real operator-(const\
    \ modint_real &p) const { return modint_real(*this) -= p; }\n  modint_real operator*(const\
    \ modint_real &p) const { return modint_real(*this) *= p; }\n  modint_real operator/(const\
    \ modint_real &p) const { return modint_real(*this) /= p; }\n  bool operator==(const\
    \ modint_real &p) const { return a == p.a; }\n  bool operator!=(const modint_real\
    \ &p) const { return b != p.b; }\n  modint_real inverse() const { return modint_real(a.inverse(),\
    \ 1 / b); }\n  mint to_modint() { return a; }\n  Re to_real() { return b; }\n\
    };\n"
  code: "// Point<T>, Line<T> \u306A\u3069\u304C\u3042\u308B\u7A0B\u5EA6\u52D5\u304F\
    \u3068\u671F\u5F85\u3057\u3066\u3044\u308B\n// https://codeforces.com/contest/44/submission/319952578\n\
    template <typename mint, typename Re>\nstruct modint_real {\n  mint a;\n  Re b;\n\
    \  constexpr modint_real() : a(0), b(0) {}\n  constexpr modint_real(ll x) : a(x),\
    \ b(x) {}\n  constexpr modint_real(mint mx, Re x) : a(mx), b(x) {}\n  bool operator<(const\
    \ modint_real &other) const { return (a != other.a) && (b < other.b); }\n  bool\
    \ operator<=(const modint_real &other) const { return (a == other.a) || (b < other.b);\
    \ }\n  modint_real &operator+=(const modint_real &p) {\n    a += p.a, b += p.b;\n\
    \    return *this;\n  }\n  modint_real &operator-=(const modint_real &p) {\n \
    \   a -= p.a, b -= p.b;\n    return *this;\n  }\n  modint_real &operator*=(const\
    \ modint_real &p) {\n    a *= p.a, b *= p.b;\n    return *this;\n  }\n  modint_real\
    \ &operator/=(const modint_real &p) {\n    a /= p.a, b /= p.b;\n    return *this;\n\
    \  }\n  modint_real operator-() const { return modint_real(-a, -b); }\n  modint_real\
    \ operator+(const modint_real &p) const { return modint_real(*this) += p; }\n\
    \  modint_real operator-(const modint_real &p) const { return modint_real(*this)\
    \ -= p; }\n  modint_real operator*(const modint_real &p) const { return modint_real(*this)\
    \ *= p; }\n  modint_real operator/(const modint_real &p) const { return modint_real(*this)\
    \ /= p; }\n  bool operator==(const modint_real &p) const { return a == p.a; }\n\
    \  bool operator!=(const modint_real &p) const { return b != p.b; }\n  modint_real\
    \ inverse() const { return modint_real(a.inverse(), 1 / b); }\n  mint to_modint()\
    \ { return a; }\n  Re to_real() { return b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/modint_real.hpp
  requiredBy: []
  timestamp: '2025-05-18 18:12:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/modint_real.hpp
layout: document
redirect_from:
- /library/geo/modint_real.hpp
- /library/geo/modint_real.hpp.html
title: geo/modint_real.hpp
---
