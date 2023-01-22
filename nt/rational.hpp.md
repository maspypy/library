---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0350.test.cpp
    title: test/aoj/0350.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/rational.hpp\"\ntemplate <typename T = long long, bool\
    \ REDUCE = true>\nstruct Rational {\n  T num, den;\n\n  Rational() : num(0), den(1)\
    \ {}\n  Rational(T x) : num(x), den(1) {}\n  Rational(T a, T b, bool coprime =\
    \ false) : num(a), den(b) {\n    if (!coprime && REDUCE) reduce();\n  }\n\n  static\
    \ T gcd(T a, T b) {\n    while (b) {\n      a %= b;\n      swap(a, b);\n    }\n\
    \    return a;\n  }\n\n  void reduce() {\n    if (!REDUCE) return;\n    T g =\
    \ gcd(abs(num), abs(den));\n    num /= g, den /= g;\n  }\n\n  Rational &operator+=(const\
    \ Rational &p) {\n    T g = (REDUCE ? gcd(den, p.den) : 1);\n    num = num * (p.den\
    \ / g) + p.num * (den / g);\n    den *= p.den / g;\n    reduce();\n    return\
    \ *this;\n  }\n  Rational &operator-=(const Rational &p) {\n    T g = (REDUCE\
    \ ? gcd(den, p.den) : 1);\n    num = num * (p.den / g) - p.num * (den / g);\n\
    \    den *= p.den / g;\n    reduce();\n    return *this;\n  }\n  Rational &operator*=(const\
    \ Rational &p) {\n    T g1 = (REDUCE ? gcd(num, p.den) : 1);\n    T g2 = (REDUCE\
    \ ? gcd(den, p.num) : 1);\n    num = (num / g1) * (p.num / g2);\n    den = (den\
    \ / g2) * (p.den / g1);\n    return *this;\n  }\n  Rational &operator/=(const\
    \ Rational &p) {\n    T g1 = (REDUCE ? gcd(num, p.num) : 1);\n    T g2 = (REDUCE\
    \ ? gcd(den, p.den) : 1);\n    num = (num / g1) * (p.den / g2);\n    den = (den\
    \ / g2) * (p.num / g1);\n    if (den < 0) num = -num, den = -den;\n    return\
    \ *this;\n  }\n\n  Rational operator-() const { return Rational(-num, den); }\n\
    \  Rational operator+(const Rational &p) const { return Rational(*this) += p;\
    \ }\n  Rational operator-(const Rational &p) const { return Rational(*this) -=\
    \ p; }\n  Rational operator*(const Rational &p) const { return Rational(*this)\
    \ *= p; }\n  Rational operator/(const Rational &p) const { return Rational(*this)\
    \ /= p; }\n  bool operator==(const Rational &p) const {\n    return num * p.den\
    \ == p.num * den;\n  }\n  bool operator!=(const Rational &p) const {\n    return\
    \ num * p.den != p.num * den;\n  }\n  bool operator<(const Rational &p) const\
    \ { return num * p.den < p.num * den; }\n  bool operator>(const Rational &p) const\
    \ { return num * p.den > p.num * den; }\n  bool operator<=(const Rational &p)\
    \ const {\n    return num * p.den <= p.num * den;\n  }\n  bool operator>=(const\
    \ Rational &p) const {\n    return num * p.den >= p.num * den;\n  }\n\n  string\
    \ to_string() { return std::to_string(num) + \"/\" + std::to_string(den); }\n\
    };\n"
  code: "template <typename T = long long, bool REDUCE = true>\nstruct Rational {\n\
    \  T num, den;\n\n  Rational() : num(0), den(1) {}\n  Rational(T x) : num(x),\
    \ den(1) {}\n  Rational(T a, T b, bool coprime = false) : num(a), den(b) {\n \
    \   if (!coprime && REDUCE) reduce();\n  }\n\n  static T gcd(T a, T b) {\n   \
    \ while (b) {\n      a %= b;\n      swap(a, b);\n    }\n    return a;\n  }\n\n\
    \  void reduce() {\n    if (!REDUCE) return;\n    T g = gcd(abs(num), abs(den));\n\
    \    num /= g, den /= g;\n  }\n\n  Rational &operator+=(const Rational &p) {\n\
    \    T g = (REDUCE ? gcd(den, p.den) : 1);\n    num = num * (p.den / g) + p.num\
    \ * (den / g);\n    den *= p.den / g;\n    reduce();\n    return *this;\n  }\n\
    \  Rational &operator-=(const Rational &p) {\n    T g = (REDUCE ? gcd(den, p.den)\
    \ : 1);\n    num = num * (p.den / g) - p.num * (den / g);\n    den *= p.den /\
    \ g;\n    reduce();\n    return *this;\n  }\n  Rational &operator*=(const Rational\
    \ &p) {\n    T g1 = (REDUCE ? gcd(num, p.den) : 1);\n    T g2 = (REDUCE ? gcd(den,\
    \ p.num) : 1);\n    num = (num / g1) * (p.num / g2);\n    den = (den / g2) * (p.den\
    \ / g1);\n    return *this;\n  }\n  Rational &operator/=(const Rational &p) {\n\
    \    T g1 = (REDUCE ? gcd(num, p.num) : 1);\n    T g2 = (REDUCE ? gcd(den, p.den)\
    \ : 1);\n    num = (num / g1) * (p.den / g2);\n    den = (den / g2) * (p.num /\
    \ g1);\n    if (den < 0) num = -num, den = -den;\n    return *this;\n  }\n\n \
    \ Rational operator-() const { return Rational(-num, den); }\n  Rational operator+(const\
    \ Rational &p) const { return Rational(*this) += p; }\n  Rational operator-(const\
    \ Rational &p) const { return Rational(*this) -= p; }\n  Rational operator*(const\
    \ Rational &p) const { return Rational(*this) *= p; }\n  Rational operator/(const\
    \ Rational &p) const { return Rational(*this) /= p; }\n  bool operator==(const\
    \ Rational &p) const {\n    return num * p.den == p.num * den;\n  }\n  bool operator!=(const\
    \ Rational &p) const {\n    return num * p.den != p.num * den;\n  }\n  bool operator<(const\
    \ Rational &p) const { return num * p.den < p.num * den; }\n  bool operator>(const\
    \ Rational &p) const { return num * p.den > p.num * den; }\n  bool operator<=(const\
    \ Rational &p) const {\n    return num * p.den <= p.num * den;\n  }\n  bool operator>=(const\
    \ Rational &p) const {\n    return num * p.den >= p.num * den;\n  }\n\n  string\
    \ to_string() { return std::to_string(num) + \"/\" + std::to_string(den); }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/rational.hpp
  requiredBy: []
  timestamp: '2023-01-22 14:28:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/0350.test.cpp
documentation_of: nt/rational.hpp
layout: document
redirect_from:
- /library/nt/rational.hpp
- /library/nt/rational.hpp.html
title: nt/rational.hpp
---
