---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: game/dyadic_rational.hpp
    title: game/dyadic_rational.hpp
  - icon: ':x:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':x:'
    path: other/mex.hpp
    title: other/mex.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/partizan.test.cpp
    title: test/1_mytest/partizan.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc229h.test.cpp
    title: test/5_atcoder/abc229h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qoj.ac/contest/1828/problem/9567
  bundledCode: "#line 1 \"game/solve_partizan_game.hpp\"\n\n#line 1 \"game/dyadic_rational.hpp\"\
    \n// a+b/2^M \u306E\u5F62\u3067\u6301\u3064\ntemplate <typename INTEGER>\nstruct\
    \ Dyadic_Rational {\n  using X = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr\
    \ int M = std::numeric_limits<INTEGER>::digits - 2;\n\n  Dyadic_Rational(INTEGER\
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
    \ std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n#line 1 \"other/mex.hpp\"\
    \nint mex(const vc<int>& A) {\n  int n = len(A);\n  vc<bool> aru(n + 1);\n  for\
    \ (auto& x: A)\n    if (x < n) aru[x] = 1;\n  int mex = 0;\n  while (aru[mex])\
    \ ++mex;\n  return mex;\n}\n#line 3 \"game/number_and_star.hpp\"\n\nstruct Number_And_Star\
    \ {\n  using A = Dyadic_Rational<ll>;\n  // a + *b\n  A a;\n  int b;\n  using\
    \ T = Number_And_Star;\n\n  Number_And_Star(A a = 0, ll b = 0) : a(a), b(b) {}\n\
    \  T& operator+=(const T& p) {\n    a += p.a, b ^= p.b;\n    return *this;\n \
    \ }\n  T& operator-=(const T& p) {\n    a -= p.a, b ^= p.b;\n    return *this;\n\
    \  }\n  T operator-() const { return T(-a, b); }\n  bool operator==(const T& p)\
    \ const { return (a == p.a && b == p.b); }\n\n  // {\u8A08\u7B97\u3067\u304D\u305F\
    \u304B, \u5024}\n  static pair<bool, T> from_options(vc<T> left_ops, vc<T> right_ops)\
    \ {\n    A xl = -A::infinity(), xr = A::infinity();\n    vc<int> Lb, Rb;\n   \
    \ for (auto&& t: left_ops) {\n      if (chmax(xl, t.a)) Lb.clear();\n      if\
    \ (xl == t.a) Lb.eb(t.b);\n    }\n    for (auto&& t: right_ops) {\n      if (chmin(xr,\
    \ t.a)) Rb.clear();\n      if (xr == t.a) Rb.eb(t.b);\n    }\n    int Lm = mex(Lb),\
    \ Rm = mex(Rb);\n    if (xl < xr) {\n      A a = A::simplest(xl, xr, Lm == 0,\
    \ Rm == 0);\n      return {true, T(a, 0)};\n    }\n    if (xl == xr) {\n     \
    \ if (Lm == Rm) return {true, T(xl, Lm)};\n    }\n    return {false, T(0, 0)};\n\
    \  }\n\n  string to_string() {\n    string x = a.to_string();\n    x += \" + *\"\
    ;\n    x += ::to_string(b);\n    return x;\n  }\n\n  // L, R \u306F\u305D\u308C\
    \u305E\u308C\u81EA\u5206\u624B\u756A\u306E\u3068\u304D\u306B\u52DD\u3066\u308B\
    \u304B\uFF1F\n  pair<bool, bool> outcome() {\n    if (a > 0) return {1, 0};\n\
    \    if (a < 0) return {0, 1};\n    if (b == 0) return {0, 0};\n    return {1,\
    \ 1};\n  }\n};\n#line 3 \"game/solve_partizan_game.hpp\"\n\n// number, star \u3067\
    \u3044\u3044\u611F\u3058\u306B\u8A08\u7B97\u3067\u304D\u305F\u3068\u304D\u3060\
    \u3051\u6210\u529F\n// \u5931\u6557\u3057\u305F\u3068\u304D\u306F\u3001empty map\
    \ \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\u8208\u5473\u306E\u3042\u308B state\
    \ \u5168\u4F53\n// \u30FBget_options\uFF1Apair<vc<STATE>, vc<STATE>>(STATE), left\
    \ ops / right ops\n// https://qoj.ac/contest/1828/problem/9567\ntemplate <typename\
    \ STATE, typename F>\nmap<STATE, Number_And_Star> solve_partizan_game(const vector<STATE>&\
    \ states, F get_options) {\n  using X = Number_And_Star;\n  map<STATE, X> MP;\n\
    \n  bool success = 1;\n\n  auto dfs = [&](auto& dfs, const STATE& s) -> X {\n\
    \    if (!success) return X();\n    if (MP.count(s)) return MP[s];\n    vc<X>\
    \ left, right;\n    auto [lop, rop] = get_options(s);\n    for (auto&& t: lop)\
    \ left.eb(dfs(dfs, t));\n    for (auto&& t: rop) right.eb(dfs(dfs, t));\n    auto\
    \ [ok, t] = X::from_options(left, right);\n    if (!success) return X{};\n   \
    \ if (!ok) {\n      // print(\"FAILED\");\n      // print(s);\n      // print(\"\
    LEFT\");\n      // for (auto& t: lop) {\n      //   X x = dfs(dfs, t);\n     \
    \ //   print(t, x.to_string());\n      // }\n      // print(\"RIGHT\");\n    \
    \  // for (auto& t: rop) {\n      //   X x = dfs(dfs, t);\n      //   print(t,\
    \ x.to_string());\n      // }\n      success = 0;\n      return X();\n    }\n\
    \    MP[s] = t;\n    return MP[s] = t;\n  };\n\n  for (auto&& s: states) dfs(dfs,\
    \ s);\n  if (!success) MP.clear();\n  return MP;\n}\n"
  code: "\n#include \"game/number_and_star.hpp\"\n\n// number, star \u3067\u3044\u3044\
    \u611F\u3058\u306B\u8A08\u7B97\u3067\u304D\u305F\u3068\u304D\u3060\u3051\u6210\
    \u529F\n// \u5931\u6557\u3057\u305F\u3068\u304D\u306F\u3001empty map \u304C\u8FD4\
    \u308B\n// \u30FBstates\uFF1A\u8208\u5473\u306E\u3042\u308B state \u5168\u4F53\
    \n// \u30FBget_options\uFF1Apair<vc<STATE>, vc<STATE>>(STATE), left ops / right\
    \ ops\n// https://qoj.ac/contest/1828/problem/9567\ntemplate <typename STATE,\
    \ typename F>\nmap<STATE, Number_And_Star> solve_partizan_game(const vector<STATE>&\
    \ states, F get_options) {\n  using X = Number_And_Star;\n  map<STATE, X> MP;\n\
    \n  bool success = 1;\n\n  auto dfs = [&](auto& dfs, const STATE& s) -> X {\n\
    \    if (!success) return X();\n    if (MP.count(s)) return MP[s];\n    vc<X>\
    \ left, right;\n    auto [lop, rop] = get_options(s);\n    for (auto&& t: lop)\
    \ left.eb(dfs(dfs, t));\n    for (auto&& t: rop) right.eb(dfs(dfs, t));\n    auto\
    \ [ok, t] = X::from_options(left, right);\n    if (!success) return X{};\n   \
    \ if (!ok) {\n      // print(\"FAILED\");\n      // print(s);\n      // print(\"\
    LEFT\");\n      // for (auto& t: lop) {\n      //   X x = dfs(dfs, t);\n     \
    \ //   print(t, x.to_string());\n      // }\n      // print(\"RIGHT\");\n    \
    \  // for (auto& t: rop) {\n      //   X x = dfs(dfs, t);\n      //   print(t,\
    \ x.to_string());\n      // }\n      success = 0;\n      return X();\n    }\n\
    \    MP[s] = t;\n    return MP[s] = t;\n  };\n\n  for (auto&& s: states) dfs(dfs,\
    \ s);\n  if (!success) MP.clear();\n  return MP;\n}\n"
  dependsOn:
  - game/number_and_star.hpp
  - game/dyadic_rational.hpp
  - other/mex.hpp
  isVerificationFile: false
  path: game/solve_partizan_game.hpp
  requiredBy: []
  timestamp: '2024-11-16 13:34:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/abc229h.test.cpp
  - test/1_mytest/partizan.test.cpp
documentation_of: game/solve_partizan_game.hpp
layout: document
redirect_from:
- /library/game/solve_partizan_game.hpp
- /library/game/solve_partizan_game.hpp.html
title: game/solve_partizan_game.hpp
---
