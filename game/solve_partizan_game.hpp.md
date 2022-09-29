---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: game/dyrational.hpp
    title: game/dyrational.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc229h.test.cpp
    title: test/atcoder/abc229h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/partizan.test.cpp
    title: test/mytest/partizan.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"game/dyrational.hpp\"\n// a/2^b \u306E\u5F62\u3067\u6301\
    \u3064\n// a \u306F i128 \u306B\u3082\u3067\u304D\u308B\u304C\u3001\u5B9F\u7528\
    \u4E0A\u8DB3\u308A\u308B\u304B\u306F\u3001\u6F14\u7FD2\u91CF\u304C\u8DB3\u308A\
    \u3066\u3044\u306A\u304F\u3066\u4E0D\u660E\ntemplate <typename INTEGER = ll>\n\
    struct DyRational {\n  using X = DyRational;\n  INTEGER a;\n  int b;\n\n  DyRational(INTEGER\
    \ _a = 0, int _b = 0) : a(_a), b(_b) {\n    while (b && a % 2 == 0) { a /= 2,\
    \ b--; }\n  }\n\n  friend X operator+(const X& x, const X& y) {\n    int b = max(x.b,\
    \ y.b);\n    INTEGER a = ((x.a) << (b - x.b)) + ((y.a) << (b - y.b));\n    return\
    \ X(a, b);\n  }\n  friend X operator-(const X& x, const X& y) {\n    int b = max(x.b,\
    \ y.b);\n    INTEGER a = ((x.a) << (b - x.b)) - ((y.a) << (b - y.b));\n    return\
    \ X(a, b);\n  }\n  friend X operator-(const X& x) { return X(-x.a, x.b); }\n \
    \ X& operator+=(const X& x) { return (*this) = (*this) + x; }\n  X& operator-=(const\
    \ X& x) { return (*this) = (*this) - x; }\n\n  friend bool operator<(const X&\
    \ x, const X& y) { return (x - y).a < 0; }\n  friend bool operator<=(const X&\
    \ x, const X& y) { return (x - y).a <= 0; }\n  friend bool operator>(const X&\
    \ x, const X& y) { return (x - y).a > 0; }\n  friend bool operator>=(const X&\
    \ x, const X& y) { return (x - y).a >= 0; }\n  friend bool operator==(const X&\
    \ x, const X& y) { return (x - y).a == 0; }\n  friend bool operator!=(const X&\
    \ x, const X& y) { return (x - y).a != 0; }\n\n  // x, y \u306E\u9593\u306E simplest\
    \ dyrational number \u3092\u898B\u3064\u3051\u308B\n  static X find(const X& x,\
    \ const X& y) {\n    assert(x < y);\n    FOR(k, max(x.b, y.b) + 2) {\n      //\
    \ floor(x)\n      INTEGER xx = (x.b >= k ? (x.a) >> (x.b - k) : (x.a) << (k -\
    \ x.b));\n      // ceil(y)\n      INTEGER yy\n          = (y.b >= k ? ((y.a -\
    \ 1) >> (y.b - k)) + 1 : (y.a) << (k - y.b));\n      if (xx + 2 <= yy) {\n   \
    \     if (k != 0) {\n          assert(xx + 2 == yy);\n          return X(xx +\
    \ 1, k);\n        }\n        // [xx+1, yy-1] \u306E\u3046\u3061\u3067\u3001\u7D76\
    \u5BFE\u5024\u6700\u5C0F\u306E\u3082\u306E\u3092\u9078\u3076\n        if (xx +\
    \ 1 >= 0) return X(xx + 1, 0);\n        if (yy - 1 <= 0) return X(yy - 1, 0);\n\
    \        return X(0, 0);\n      }\n    }\n    assert(false);\n    return X(0);\n\
    \  }\n\n  static constexpr X infinity() { return X(numeric_limits<int>::max()\
    \ / 4, 0); }\n\n  string to_string() {\n    return std::to_string(a) + \"/\" +\
    \ std::to_string(INTEGER(1) << b);\n  }\n};\n#line 2 \"game/solve_partizan_game.hpp\"\
    \n\n// \u5168\u90E8 dyadic rational number \u306B\u306A\u308B\u3068\u304D\u3060\
    \u3051\u89E3\u3051\u308B\n// \u5931\u6557\u3057\u305F\u3068\u304D\u306F\u3001\
    empty map \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\u8208\u5473\u306E\u3042\u308B\
    \ state \u5168\u4F53\n// \u30FBget_options\uFF1Apair<vc<STATE>, vc<STATE>>(STATE),\
    \ left ops / right ops\ntemplate <typename STATE, typename INTEGER, typename F>\n\
    map<STATE, DyRational<INTEGER>> solve_partizan_game(const vector<STATE>& states,\n\
    \                                                    F get_options) {\n  using\
    \ X = DyRational<INTEGER>;\n  map<STATE, X> MP;\n\n  bool success = 1;\n\n  auto\
    \ dfs = [&](auto& dfs, const STATE& s) -> X {\n    if (!success) return X();\n\
    \    if (MP.count(s)) return MP[s];\n    vc<X> left, right;\n    X xl = -X::infinity(),\
    \ xr = X::infinity();\n    auto [left_ops, right_ops] = get_options(s);\n    for\
    \ (auto&& t: left_ops) chmax(xl, dfs(dfs, t));\n    for (auto&& t: right_ops)\
    \ chmin(xr, dfs(dfs, t));\n\n    if (xl >= xr) {\n      // switch\n      success\
    \ = 0;\n      MP.clear();\n      return X();\n    }\n    return (MP[s] = X::find(xl,\
    \ xr));\n  };\n\n  for (auto&& s: states) dfs(dfs, s);\n  return MP;\n}\n"
  code: "#include \"game/dyrational.hpp\"\n\n// \u5168\u90E8 dyadic rational number\
    \ \u306B\u306A\u308B\u3068\u304D\u3060\u3051\u89E3\u3051\u308B\n// \u5931\u6557\
    \u3057\u305F\u3068\u304D\u306F\u3001empty map \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\
    \u8208\u5473\u306E\u3042\u308B state \u5168\u4F53\n// \u30FBget_options\uFF1A\
    pair<vc<STATE>, vc<STATE>>(STATE), left ops / right ops\ntemplate <typename STATE,\
    \ typename INTEGER, typename F>\nmap<STATE, DyRational<INTEGER>> solve_partizan_game(const\
    \ vector<STATE>& states,\n                                                   \
    \ F get_options) {\n  using X = DyRational<INTEGER>;\n  map<STATE, X> MP;\n\n\
    \  bool success = 1;\n\n  auto dfs = [&](auto& dfs, const STATE& s) -> X {\n \
    \   if (!success) return X();\n    if (MP.count(s)) return MP[s];\n    vc<X> left,\
    \ right;\n    X xl = -X::infinity(), xr = X::infinity();\n    auto [left_ops,\
    \ right_ops] = get_options(s);\n    for (auto&& t: left_ops) chmax(xl, dfs(dfs,\
    \ t));\n    for (auto&& t: right_ops) chmin(xr, dfs(dfs, t));\n\n    if (xl >=\
    \ xr) {\n      // switch\n      success = 0;\n      MP.clear();\n      return\
    \ X();\n    }\n    return (MP[s] = X::find(xl, xr));\n  };\n\n  for (auto&& s:\
    \ states) dfs(dfs, s);\n  return MP;\n}"
  dependsOn:
  - game/dyrational.hpp
  isVerificationFile: false
  path: game/solve_partizan_game.hpp
  requiredBy: []
  timestamp: '2022-09-26 19:35:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/partizan.test.cpp
  - test/atcoder/abc229h.test.cpp
documentation_of: game/solve_partizan_game.hpp
layout: document
redirect_from:
- /library/game/solve_partizan_game.hpp
- /library/game/solve_partizan_game.hpp.html
title: game/solve_partizan_game.hpp
---
