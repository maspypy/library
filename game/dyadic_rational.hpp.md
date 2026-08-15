---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':heavy_check_mark:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dyadic_rational.test.cpp
    title: test/1_mytest/dyadic_rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/partizan.test.cpp
    title: test/1_mytest/partizan.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"game/dyadic_rational.hpp\"\n\n// a+b/2^M \u306E\
    \u5F62\u3067\u6301\u3064\ntemplate <typename INTEGER>\nstruct Dyadic_Rational\
    \ {\n  using X = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr int M =\
    \ std::numeric_limits<INTEGER>::digits - 2;\n\n  Dyadic_Rational(INTEGER a = 0)\
    \ : a(a), b(0) {}\n\n  // x + y / z\n  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER\
    \ z) : a(x), b(y) {\n    auto [q, r] = divmod(b, z);\n    a += q;\n    b = r;\n\
    \    b *= (INTEGER(1) << M) / z;\n  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x,\
    \ INTEGER y) : Dyadic_Rational(0, x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER\
    \ b) {\n    X x(a);\n    x.b = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n \
    \ bool operator==(X const& rhs) const { return (a == rhs.a && b == rhs.b); }\n\
    \  bool operator!=(X const& rhs) const { return !(*this == rhs); }\n  bool operator<(X\
    \ const& rhs) const {\n    return (a < rhs.a) || (a == rhs.a && b < rhs.b);\n\
    \  }\n  bool operator<=(X const& rhs) const {\n    return (a < rhs.a) || (a ==\
    \ rhs.a && b <= rhs.b);\n  }\n  bool operator>(X const& rhs) const {\n    return\
    \ (a > rhs.a) || (a == rhs.a && b > rhs.b);\n  }\n  bool operator>=(X const& rhs)\
    \ const {\n    return (a > rhs.a) || (a == rhs.a && b >= rhs.b);\n  }\n\n  //\
    \ \u52A0\u6CD5\n  friend X operator+(const X& x, const X& y) {\n    INTEGER a\
    \ = x.a + y.a, b = x.b + y.b;\n    while (b >= INTEGER(1) << M) {\n      ++a;\n\
    \      b -= INTEGER(1) << M;\n    }\n    return from_ab(a, b);\n  }\n  friend\
    \ X operator-(const X& x, const X& y) {\n    INTEGER a = x.a - y.a, b = x.b -\
    \ y.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n\
    \    return from_ab(a, b);\n  }\n  friend X operator-(const X& x) {\n    INTEGER\
    \ a = -x.a, b = -x.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1)\
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
    \ (y % 2 == 0 && z % 2 == 0) {\n      y /= 2, z /= 2;\n    }\n    y += x * z;\n\
    \    return std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\n// a+b/2^M \u306E\u5F62\u3067\u6301\u3064\n\
    template <typename INTEGER>\nstruct Dyadic_Rational {\n  using X = Dyadic_Rational;\n\
    \  INTEGER a, b;\n  static constexpr int M = std::numeric_limits<INTEGER>::digits\
    \ - 2;\n\n  Dyadic_Rational(INTEGER a = 0) : a(a), b(0) {}\n\n  // x + y / z\n\
    \  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER z) : a(x), b(y) {\n    auto [q,\
    \ r] = divmod(b, z);\n    a += q;\n    b = r;\n    b *= (INTEGER(1) << M) / z;\n\
    \  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x, INTEGER y) : Dyadic_Rational(0,\
    \ x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER b) {\n    X x(a);\n    x.b\
    \ = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n  bool operator==(X const& rhs)\
    \ const { return (a == rhs.a && b == rhs.b); }\n  bool operator!=(X const& rhs)\
    \ const { return !(*this == rhs); }\n  bool operator<(X const& rhs) const {\n\
    \    return (a < rhs.a) || (a == rhs.a && b < rhs.b);\n  }\n  bool operator<=(X\
    \ const& rhs) const {\n    return (a < rhs.a) || (a == rhs.a && b <= rhs.b);\n\
    \  }\n  bool operator>(X const& rhs) const {\n    return (a > rhs.a) || (a ==\
    \ rhs.a && b > rhs.b);\n  }\n  bool operator>=(X const& rhs) const {\n    return\
    \ (a > rhs.a) || (a == rhs.a && b >= rhs.b);\n  }\n\n  // \u52A0\u6CD5\n  friend\
    \ X operator+(const X& x, const X& y) {\n    INTEGER a = x.a + y.a, b = x.b +\
    \ y.b;\n    while (b >= INTEGER(1) << M) {\n      ++a;\n      b -= INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  friend X operator-(const X&\
    \ x, const X& y) {\n    INTEGER a = x.a - y.a, b = x.b - y.b;\n    while (b <\
    \ 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n    return from_ab(a,\
    \ b);\n  }\n  friend X operator-(const X& x) {\n    INTEGER a = -x.a, b = -x.b;\n\
    \    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n    return\
    \ from_ab(a, b);\n  }\n  X& operator+=(const X& x) { return (*this) = (*this)\
    \ + x; }\n  X& operator-=(const X& x) { return (*this) = (*this) - x; }\n\n  static\
    \ X simplest(X x, X y, bool include_x = false, bool include_y = false) {\n   \
    \ if (include_x && x != -infinity()) {\n      // eps \u3092\u5F15\u304F, \u3042\
    \u3068\u3067\u3082\u3063\u3068\u5C0F\u3055\u3044 eps \u3092\u4F7F\u3063\u3066\u3044\
    \u308B !\n      x = x - from_ab(0, 2);\n    }\n    if (include_y && y != infinity())\
    \ {\n      // eps \u3092\u8DB3\u3059\n      y = y + from_ab(0, 2);\n    }\n  \
    \  assert(x < y);\n    if (y.a < 0) return -simplest(-y, -x);\n    {\n      INTEGER\
    \ l = x.a + 1;\n      INTEGER r = (y.b == 0 ? y.a - 1 : y.a);\n      if (l <=\
    \ 0 && 0 <= r) return X(0);\n      if (l <= r && 0 <= l) return X(l);\n      if\
    \ (l <= r && r <= 0) return X(r);\n    }\n\n    INTEGER l = x.b + 1;\n    INTEGER\
    \ r = (y.b == 0 ? (INTEGER(1) << M) - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a,\
    \ l);\n    int k = topbit(l ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return\
    \ from_ab(x.a, r);\n  }\n\n  static constexpr X infinity() { return from_ab(INTEGER(1)\
    \ << M, 0); }\n\n  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) <<\
    \ M;\n    while (y % 2 == 0 && z % 2 == 0) {\n      y /= 2, z /= 2;\n    }\n \
    \   y += x * z;\n    return std::to_string(y) + \"/\" + std::to_string(z);\n \
    \ }\n};"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: game/dyadic_rational.hpp
  requiredBy:
  - game/number_and_star.hpp
  - game/solve_partizan_game.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
