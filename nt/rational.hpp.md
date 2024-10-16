---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/0350.test.cpp
    title: test/4_aoj/0350.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc301g.test.cpp
    title: test/5_atcoder/abc301g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/agc060c.test.cpp
    title: test/5_atcoder/agc060c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/rational.hpp\"\ntemplate <typename T = long long, bool\
    \ REDUCE = true>\nstruct Rational {\n  T num, den;\n\n  Rational() : num(0), den(1)\
    \ {}\n  Rational(T x) : num(x), den(1) {}\n  Rational(T a, T b, bool coprime =\
    \ false) : num(a), den(b) {\n    if (den < 0) num = -num, den = -den;\n    if\
    \ (!coprime && REDUCE) reduce();\n  }\n\n  static T gcd(T a, T b) {\n    a = max(a,\
    \ -a), b = max(b, -b);\n    while (b) {\n      a %= b;\n      swap(a, b);\n  \
    \  }\n    return a;\n  }\n\n  void reduce() {\n    if constexpr (!REDUCE) {\n\
    \      return;\n    } else {\n      T g = gcd(num, den);\n      num /= g, den\
    \ /= g;\n    }\n  }\n\n  Rational &operator+=(const Rational &p) {\n    if constexpr\
    \ (!REDUCE) {\n      num = num * p.den + p.num * den;\n      den *= p.den;\n \
    \     return *this;\n    } else {\n      T g = (REDUCE ? gcd(den, p.den) : 1);\n\
    \      num = num * (p.den / g) + p.num * (den / g);\n      den *= p.den / g;\n\
    \      reduce();\n      return *this;\n    }\n  }\n  Rational &operator-=(const\
    \ Rational &p) {\n    if constexpr (!REDUCE) {\n      num = num * p.den - p.num\
    \ * den;\n      den *= p.den;\n      return *this;\n    } else {\n      T g =\
    \ (REDUCE ? gcd(den, p.den) : 1);\n      num = num * (p.den / g) - p.num * (den\
    \ / g);\n      den *= p.den / g;\n      reduce();\n      return *this;\n    }\n\
    \  }\n  Rational &operator*=(const Rational &p) {\n    if constexpr (!REDUCE)\
    \ {\n      num = num * p.num;\n      den = den * p.den;\n      return *this;\n\
    \    } else {\n      T g1 = gcd(num, p.den);\n      T g2 = gcd(den, p.num);\n\
    \      num = (num / g1) * (p.num / g2);\n      den = (den / g2) * (p.den / g1);\n\
    \      return *this;\n    }\n  }\n  Rational &operator/=(const Rational &p) {\n\
    \    T g1 = (REDUCE ? gcd(num, p.num) : 1);\n    T g2 = (REDUCE ? gcd(den, p.den)\
    \ : 1);\n    num = (num / g1) * (p.den / g2);\n    den = (den / g2) * (p.num /\
    \ g1);\n    if (den < 0) num = -num, den = -den;\n    return *this;\n  }\n\n \
    \ Rational operator-() const { return Rational(-num, den); }\n  Rational operator+(const\
    \ Rational &p) const { return Rational(*this) += p; }\n  Rational operator-(const\
    \ Rational &p) const { return Rational(*this) -= p; }\n  Rational operator*(const\
    \ Rational &p) const { return Rational(*this) *= p; }\n  Rational operator/(const\
    \ Rational &p) const { return Rational(*this) /= p; }\n  bool operator==(const\
    \ Rational &p) const { return num * p.den == p.num * den; }\n  bool operator!=(const\
    \ Rational &p) const { return num * p.den != p.num * den; }\n  bool operator<(const\
    \ Rational &p) const { return num * p.den < p.num * den; }\n  bool operator>(const\
    \ Rational &p) const { return num * p.den > p.num * den; }\n  bool operator<=(const\
    \ Rational &p) const { return num * p.den <= p.num * den; }\n  bool operator>=(const\
    \ Rational &p) const { return num * p.den >= p.num * den; }\n\n  string to_string()\
    \ { return std::to_string(num) + \"/\" + std::to_string(den); }\n  double to_double()\
    \ { return double(num) / double(den); }\n};\n"
  code: "template <typename T = long long, bool REDUCE = true>\nstruct Rational {\n\
    \  T num, den;\n\n  Rational() : num(0), den(1) {}\n  Rational(T x) : num(x),\
    \ den(1) {}\n  Rational(T a, T b, bool coprime = false) : num(a), den(b) {\n \
    \   if (den < 0) num = -num, den = -den;\n    if (!coprime && REDUCE) reduce();\n\
    \  }\n\n  static T gcd(T a, T b) {\n    a = max(a, -a), b = max(b, -b);\n    while\
    \ (b) {\n      a %= b;\n      swap(a, b);\n    }\n    return a;\n  }\n\n  void\
    \ reduce() {\n    if constexpr (!REDUCE) {\n      return;\n    } else {\n    \
    \  T g = gcd(num, den);\n      num /= g, den /= g;\n    }\n  }\n\n  Rational &operator+=(const\
    \ Rational &p) {\n    if constexpr (!REDUCE) {\n      num = num * p.den + p.num\
    \ * den;\n      den *= p.den;\n      return *this;\n    } else {\n      T g =\
    \ (REDUCE ? gcd(den, p.den) : 1);\n      num = num * (p.den / g) + p.num * (den\
    \ / g);\n      den *= p.den / g;\n      reduce();\n      return *this;\n    }\n\
    \  }\n  Rational &operator-=(const Rational &p) {\n    if constexpr (!REDUCE)\
    \ {\n      num = num * p.den - p.num * den;\n      den *= p.den;\n      return\
    \ *this;\n    } else {\n      T g = (REDUCE ? gcd(den, p.den) : 1);\n      num\
    \ = num * (p.den / g) - p.num * (den / g);\n      den *= p.den / g;\n      reduce();\n\
    \      return *this;\n    }\n  }\n  Rational &operator*=(const Rational &p) {\n\
    \    if constexpr (!REDUCE) {\n      num = num * p.num;\n      den = den * p.den;\n\
    \      return *this;\n    } else {\n      T g1 = gcd(num, p.den);\n      T g2\
    \ = gcd(den, p.num);\n      num = (num / g1) * (p.num / g2);\n      den = (den\
    \ / g2) * (p.den / g1);\n      return *this;\n    }\n  }\n  Rational &operator/=(const\
    \ Rational &p) {\n    T g1 = (REDUCE ? gcd(num, p.num) : 1);\n    T g2 = (REDUCE\
    \ ? gcd(den, p.den) : 1);\n    num = (num / g1) * (p.den / g2);\n    den = (den\
    \ / g2) * (p.num / g1);\n    if (den < 0) num = -num, den = -den;\n    return\
    \ *this;\n  }\n\n  Rational operator-() const { return Rational(-num, den); }\n\
    \  Rational operator+(const Rational &p) const { return Rational(*this) += p;\
    \ }\n  Rational operator-(const Rational &p) const { return Rational(*this) -=\
    \ p; }\n  Rational operator*(const Rational &p) const { return Rational(*this)\
    \ *= p; }\n  Rational operator/(const Rational &p) const { return Rational(*this)\
    \ /= p; }\n  bool operator==(const Rational &p) const { return num * p.den ==\
    \ p.num * den; }\n  bool operator!=(const Rational &p) const { return num * p.den\
    \ != p.num * den; }\n  bool operator<(const Rational &p) const { return num *\
    \ p.den < p.num * den; }\n  bool operator>(const Rational &p) const { return num\
    \ * p.den > p.num * den; }\n  bool operator<=(const Rational &p) const { return\
    \ num * p.den <= p.num * den; }\n  bool operator>=(const Rational &p) const {\
    \ return num * p.den >= p.num * den; }\n\n  string to_string() { return std::to_string(num)\
    \ + \"/\" + std::to_string(den); }\n  double to_double() { return double(num)\
    \ / double(den); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/rational.hpp
  requiredBy: []
  timestamp: '2024-09-24 18:06:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/4_aoj/0350.test.cpp
  - test/5_atcoder/abc301g.test.cpp
  - test/5_atcoder/agc060c.test.cpp
documentation_of: nt/rational.hpp
layout: document
redirect_from:
- /library/nt/rational.hpp
- /library/nt/rational.hpp.html
title: nt/rational.hpp
---
