---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':x:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dyadic_rational.test.cpp
    title: test/1_mytest/dyadic_rational.test.cpp
  - icon: ':x:'
    path: test/1_mytest/partizan.test.cpp
    title: test/1_mytest/partizan.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"game/dyadic_rational.hpp\"\n// a+b/2^M \u306E\u5F62\u3067\
    \u6301\u3064\ntemplate <typename INTEGER>\nstruct Dyadic_Rational {\n  using X\
    \ = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr int M = std::numeric_limits<INTEGER>::digits\
    \ - 2;\n\n  Dyadic_Rational(INTEGER a = 0) : a(a), b(0) {}\n\n  // x + y / z\n\
    \  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER z) : a(x), b(y) {\n    auto [q,\
    \ r] = divmod(b, z);\n    a += q;\n    b = r;\n    b *= (INTEGER(1) << M) / z;\n\
    \  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x, INTEGER y) : Dyadic_Rational(0,\
    \ x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER b) {\n    X x(a);\n    x.b\
    \ = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n  bool operator==(X const& rhs)\
    \ const { return (a == rhs.a && b == rhs.b); }\n  bool operator!=(X const& rhs)\
    \ const { return !(*this == rhs); }\n  bool operator<(X const& rhs) const { return\
    \ (a < rhs.a) || (a == rhs.a && b < rhs.b); }\n  bool operator<=(X const& rhs)\
    \ const { return (a < rhs.a) || (a == rhs.a && b <= rhs.b); }\n  bool operator>(X\
    \ const& rhs) const { return (a > rhs.a) || (a == rhs.a && b > rhs.b); }\n  bool\
    \ operator>=(X const& rhs) const { return (a > rhs.a) || (a == rhs.a && b >= rhs.b);\
    \ }\n\n  // \u52A0\u6CD5\n  friend X operator+(const X& x, const X& y) {\n   \
    \ INTEGER a = x.a + y.a, b = x.b + y.b;\n    while (b >= INTEGER(1) << M) {\n\
    \      ++a;\n      b -= INTEGER(1) << M;\n    }\n    return from_ab(a, b);\n \
    \ }\n  friend X operator-(const X& x, const X& y) {\n    INTEGER a = x.a - y.a,\
    \ b = x.b - y.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n\
    \    }\n    return from_ab(a, b);\n  }\n  friend X operator-(const X& x) {\n \
    \   INTEGER a = -x.a, b = -x.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  X& operator+=(const X& x) {\
    \ return (*this) = (*this) + x; }\n  X& operator-=(const X& x) { return (*this)\
    \ = (*this) - x; }\n\n  static X simplest(X x, X y, bool include_x = false, bool\
    \ include_y = false) {\n    if (include_x && x != -infinity()) {\n      // eps\
    \ \u3092\u5F15\u304F, \u3042\u3068\u3067\u3082\u3063\u3068\u5C0F\u3055\u3044 eps\
    \ \u3092\u4F7F\u3063\u3066\u3044\u308B !\n      x = x - from_ab(0, 2);\n    }\n\
    \    if (include_y && y != infinity()) {\n      // eps \u3092\u8DB3\u3059\n  \
    \    y = y + from_ab(0, 2);\n    }\n    assert(x < y);\n    if (y.a < 0) return\
    \ -simplest(-y, -x);\n    {\n      INTEGER l = x.a + 1;\n      INTEGER r = (y.b\
    \ == 0 ? y.a - 1 : y.a);\n      if (l <= 0 && 0 <= r) return X(0);\n      if (l\
    \ <= r && 0 <= l) return X(l);\n      if (l <= r && r <= 0) return X(r);\n   \
    \ }\n\n    INTEGER l = x.b + 1;\n    INTEGER r = (y.b == 0 ? (INTEGER(1) << M)\
    \ - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a, l);\n    int k = topbit(l\
    \ ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return from_ab(x.a, r);\n  }\n\
    \n  static constexpr X infinity() { return from_ab(INTEGER(1) << M, 0); }\n\n\
    \  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) << M;\n    while\
    \ (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }\n    y += x * z;\n    return\
    \ std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n"
  code: "// a+b/2^M \u306E\u5F62\u3067\u6301\u3064\ntemplate <typename INTEGER>\n\
    struct Dyadic_Rational {\n  using X = Dyadic_Rational;\n  INTEGER a, b;\n  static\
    \ constexpr int M = std::numeric_limits<INTEGER>::digits - 2;\n\n  Dyadic_Rational(INTEGER\
    \ a = 0) : a(a), b(0) {}\n\n  // x + y / z\n  Dyadic_Rational(INTEGER x, INTEGER\
    \ y, INTEGER z) : a(x), b(y) {\n    auto [q, r] = divmod(b, z);\n    a += q;\n\
    \    b = r;\n    b *= (INTEGER(1) << M) / z;\n  }\n\n  // x/y\n  Dyadic_Rational(INTEGER\
    \ x, INTEGER y) : Dyadic_Rational(0, x, y) {}\n\n  static X from_ab(INTEGER a,\
    \ INTEGER b) {\n    X x(a);\n    x.b = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\
    \n  bool operator==(X const& rhs) const { return (a == rhs.a && b == rhs.b); }\n\
    \  bool operator!=(X const& rhs) const { return !(*this == rhs); }\n  bool operator<(X\
    \ const& rhs) const { return (a < rhs.a) || (a == rhs.a && b < rhs.b); }\n  bool\
    \ operator<=(X const& rhs) const { return (a < rhs.a) || (a == rhs.a && b <= rhs.b);\
    \ }\n  bool operator>(X const& rhs) const { return (a > rhs.a) || (a == rhs.a\
    \ && b > rhs.b); }\n  bool operator>=(X const& rhs) const { return (a > rhs.a)\
    \ || (a == rhs.a && b >= rhs.b); }\n\n  // \u52A0\u6CD5\n  friend X operator+(const\
    \ X& x, const X& y) {\n    INTEGER a = x.a + y.a, b = x.b + y.b;\n    while (b\
    \ >= INTEGER(1) << M) {\n      ++a;\n      b -= INTEGER(1) << M;\n    }\n    return\
    \ from_ab(a, b);\n  }\n  friend X operator-(const X& x, const X& y) {\n    INTEGER\
    \ a = x.a - y.a, b = x.b - y.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  friend X operator-(const X&\
    \ x) {\n    INTEGER a = -x.a, b = -x.b;\n    while (b < 0) {\n      --a;\n   \
    \   b += INTEGER(1) << M;\n    }\n    return from_ab(a, b);\n  }\n  X& operator+=(const\
    \ X& x) { return (*this) = (*this) + x; }\n  X& operator-=(const X& x) { return\
    \ (*this) = (*this) - x; }\n\n  static X simplest(X x, X y, bool include_x = false,\
    \ bool include_y = false) {\n    if (include_x && x != -infinity()) {\n      //\
    \ eps \u3092\u5F15\u304F, \u3042\u3068\u3067\u3082\u3063\u3068\u5C0F\u3055\u3044\
    \ eps \u3092\u4F7F\u3063\u3066\u3044\u308B !\n      x = x - from_ab(0, 2);\n \
    \   }\n    if (include_y && y != infinity()) {\n      // eps \u3092\u8DB3\u3059\
    \n      y = y + from_ab(0, 2);\n    }\n    assert(x < y);\n    if (y.a < 0) return\
    \ -simplest(-y, -x);\n    {\n      INTEGER l = x.a + 1;\n      INTEGER r = (y.b\
    \ == 0 ? y.a - 1 : y.a);\n      if (l <= 0 && 0 <= r) return X(0);\n      if (l\
    \ <= r && 0 <= l) return X(l);\n      if (l <= r && r <= 0) return X(r);\n   \
    \ }\n\n    INTEGER l = x.b + 1;\n    INTEGER r = (y.b == 0 ? (INTEGER(1) << M)\
    \ - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a, l);\n    int k = topbit(l\
    \ ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return from_ab(x.a, r);\n  }\n\
    \n  static constexpr X infinity() { return from_ab(INTEGER(1) << M, 0); }\n\n\
    \  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) << M;\n    while\
    \ (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }\n    y += x * z;\n    return\
    \ std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: game/dyadic_rational.hpp
  requiredBy:
  - game/number_and_star.hpp
  - game/solve_partizan_game.hpp
  timestamp: '2024-11-11 22:49:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/dyadic_rational.test.cpp
  - test/1_mytest/partizan.test.cpp
documentation_of: game/dyadic_rational.hpp
layout: document
redirect_from:
- /library/game/dyadic_rational.hpp
- /library/game/dyadic_rational.hpp.html
title: game/dyadic_rational.hpp
---
