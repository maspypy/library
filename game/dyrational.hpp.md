---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc229h.test.cpp
    title: test/atcoder/abc229h.test.cpp
  - icon: ':x:'
    path: test/mytest/dyrational.test.cpp
    title: test/mytest/dyrational.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ / 4, 0); }\n\n  void debug() { print(a, \"/\", INTEGER(1) << b); }\n};\n"
  code: "// a/2^b \u306E\u5F62\u3067\u6301\u3064\n// a \u306F i128 \u306B\u3082\u3067\
    \u304D\u308B\u304C\u3001\u5B9F\u7528\u4E0A\u8DB3\u308A\u308B\u304B\u306F\u3001\
    \u6F14\u7FD2\u91CF\u304C\u8DB3\u308A\u3066\u3044\u306A\u304F\u3066\u4E0D\u660E\
    \ntemplate <typename INTEGER = ll>\nstruct DyRational {\n  using X = DyRational;\n\
    \  INTEGER a;\n  int b;\n\n  DyRational(INTEGER _a = 0, int _b = 0) : a(_a), b(_b)\
    \ {\n    while (b && a % 2 == 0) { a /= 2, b--; }\n  }\n\n  friend X operator+(const\
    \ X& x, const X& y) {\n    int b = max(x.b, y.b);\n    INTEGER a = ((x.a) << (b\
    \ - x.b)) + ((y.a) << (b - y.b));\n    return X(a, b);\n  }\n  friend X operator-(const\
    \ X& x, const X& y) {\n    int b = max(x.b, y.b);\n    INTEGER a = ((x.a) << (b\
    \ - x.b)) - ((y.a) << (b - y.b));\n    return X(a, b);\n  }\n  friend X operator-(const\
    \ X& x) { return X(-x.a, x.b); }\n  X& operator+=(const X& x) { return (*this)\
    \ = (*this) + x; }\n  X& operator-=(const X& x) { return (*this) = (*this) - x;\
    \ }\n\n  friend bool operator<(const X& x, const X& y) { return (x - y).a < 0;\
    \ }\n  friend bool operator<=(const X& x, const X& y) { return (x - y).a <= 0;\
    \ }\n  friend bool operator>(const X& x, const X& y) { return (x - y).a > 0; }\n\
    \  friend bool operator>=(const X& x, const X& y) { return (x - y).a >= 0; }\n\
    \  friend bool operator==(const X& x, const X& y) { return (x - y).a == 0; }\n\
    \  friend bool operator!=(const X& x, const X& y) { return (x - y).a != 0; }\n\
    \n  // x, y \u306E\u9593\u306E simplest dyrational number \u3092\u898B\u3064\u3051\
    \u308B\n  static X find(const X& x, const X& y) {\n    assert(x < y);\n    FOR(k,\
    \ max(x.b, y.b) + 2) {\n      // floor(x)\n      INTEGER xx = (x.b >= k ? (x.a)\
    \ >> (x.b - k) : (x.a) << (k - x.b));\n      // ceil(y)\n      INTEGER yy\n  \
    \        = (y.b >= k ? ((y.a - 1) >> (y.b - k)) + 1 : (y.a) << (k - y.b));\n \
    \     if (xx + 2 <= yy) {\n        if (k != 0) {\n          assert(xx + 2 == yy);\n\
    \          return X(xx + 1, k);\n        }\n        // [xx+1, yy-1] \u306E\u3046\
    \u3061\u3067\u3001\u7D76\u5BFE\u5024\u6700\u5C0F\u306E\u3082\u306E\u3092\u9078\
    \u3076\n        if (xx + 1 >= 0) return X(xx + 1, 0);\n        if (yy - 1 <= 0)\
    \ return X(yy - 1, 0);\n        return X(0, 0);\n      }\n    }\n    assert(false);\n\
    \    return X(0);\n  }\n\n  static constexpr X infinity() { return X(numeric_limits<int>::max()\
    \ / 4, 0); }\n\n  void debug() { print(a, \"/\", INTEGER(1) << b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: game/dyrational.hpp
  requiredBy: []
  timestamp: '2022-09-01 21:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/dyrational.test.cpp
  - test/atcoder/abc229h.test.cpp
documentation_of: game/dyrational.hpp
layout: document
redirect_from:
- /library/game/dyrational.hpp
- /library/game/dyrational.hpp.html
title: game/dyrational.hpp
---
