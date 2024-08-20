---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/pell_equation.hpp\"\n// x^2 - Dy^2 == pm 1, \u6B63\u306E\
    \u6700\u5C0F\u89E3 1<=x<=LIM_X, \u306A\u3051\u308C\u3070 (0,0), O(log(ANS))\n\
    // T \u3067 (LIM_X)^2 \u7A0B\u5EA6\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\ntemplate <typename T>\npair<T, T> pell_equation(ll D, const\
    \ bool RHS_EQUAL_ONE, T LIM_X = -1) {\n  static_assert(!std::is_same<T, u32>::value);\n\
    \  static_assert(!std::is_same<T, u64>::value);\n  static_assert(!std::is_same<T,\
    \ u128>::value);\n  assert(D > 0);\n  ll x0 = sqrtl(D);\n  if (x0 * x0 == D) return\
    \ {0, 0};\n  T a = x0, b = 1, c = x0 + 1, d = 1;\n\n  auto f = [&](T x, T y) ->\
    \ T { return x * x - y * y * T(D); };\n\n  auto dfs = [&](auto& dfs, auto check,\
    \ T& a, T& b, T c, T d) -> void {\n    if (LIM_X != -1 && a + c > LIM_X) return;\n\
    \    if (check(a + c, b + d)) { dfs(dfs, check, a, b, c + c, d + d); }\n    if\
    \ (check(a + c, b + d)) a += c, b += d;\n  };\n\n  if (f(a, b) == T(-1)) return\
    \ {a, b};\n  if (f(c, d) == T(1)) return {c, d};\n  while (1) {\n    auto check_1\
    \ = [&](T x, T y) -> bool { return f(x, y) < 0; };\n    dfs(dfs, check_1, a, b,\
    \ c, d);\n    if (!RHS_EQUAL_ONE && f(a, b) == T(-1)) { return {a, b}; }\n   \
    \ auto check_2 = [&](T x, T y) -> bool { return f(x, y) > 0; };\n    dfs(dfs,\
    \ check_2, c, d, a, b);\n    if (f(c, d) == T(1)) return {c, d};\n    if (LIM_X\
    \ != -1 && a + c > LIM_X) break;\n  }\n  return {0, 0};\n}\n"
  code: "// x^2 - Dy^2 == pm 1, \u6B63\u306E\u6700\u5C0F\u89E3 1<=x<=LIM_X, \u306A\
    \u3051\u308C\u3070 (0,0), O(log(ANS))\n// T \u3067 (LIM_X)^2 \u7A0B\u5EA6\u304C\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\ntemplate <typename\
    \ T>\npair<T, T> pell_equation(ll D, const bool RHS_EQUAL_ONE, T LIM_X = -1) {\n\
    \  static_assert(!std::is_same<T, u32>::value);\n  static_assert(!std::is_same<T,\
    \ u64>::value);\n  static_assert(!std::is_same<T, u128>::value);\n  assert(D >\
    \ 0);\n  ll x0 = sqrtl(D);\n  if (x0 * x0 == D) return {0, 0};\n  T a = x0, b\
    \ = 1, c = x0 + 1, d = 1;\n\n  auto f = [&](T x, T y) -> T { return x * x - y\
    \ * y * T(D); };\n\n  auto dfs = [&](auto& dfs, auto check, T& a, T& b, T c, T\
    \ d) -> void {\n    if (LIM_X != -1 && a + c > LIM_X) return;\n    if (check(a\
    \ + c, b + d)) { dfs(dfs, check, a, b, c + c, d + d); }\n    if (check(a + c,\
    \ b + d)) a += c, b += d;\n  };\n\n  if (f(a, b) == T(-1)) return {a, b};\n  if\
    \ (f(c, d) == T(1)) return {c, d};\n  while (1) {\n    auto check_1 = [&](T x,\
    \ T y) -> bool { return f(x, y) < 0; };\n    dfs(dfs, check_1, a, b, c, d);\n\
    \    if (!RHS_EQUAL_ONE && f(a, b) == T(-1)) { return {a, b}; }\n    auto check_2\
    \ = [&](T x, T y) -> bool { return f(x, y) > 0; };\n    dfs(dfs, check_2, c, d,\
    \ a, b);\n    if (f(c, d) == T(1)) return {c, d};\n    if (LIM_X != -1 && a +\
    \ c > LIM_X) break;\n  }\n  return {0, 0};\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/pell_equation.hpp
  requiredBy: []
  timestamp: '2024-08-20 10:42:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/pell_equation.hpp
layout: document
redirect_from:
- /library/nt/pell_equation.hpp
- /library/nt/pell_equation.hpp.html
title: nt/pell_equation.hpp
---
