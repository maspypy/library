---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1297.test.cpp
    title: test/3_yukicoder/1297.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/913.test.cpp
    title: test/3_yukicoder/913.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/convex/cht_monotone.hpp
  bundledCode: "#line 1 \"convex/cht_monotone.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/convex/cht_monotone.hpp\n\
    template <typename T, bool isMin>\nstruct CHT_Monotone {\n  static_assert(is_same_v<T,\
    \ ll> || std::is_floating_point_v<T>);\n  struct Line {\n    T a, b;\n    int\
    \ idx;\n  };\n  deque<Line> H;\n  int nxt_idx = 0;\n\n  CHT_Monotone() = default;\n\
    \n  bool empty() const { return H.empty(); }\n  void clear() { H.clear(); }\n\n\
    \  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }\n  using D =\
    \ long double;\n  inline bool check(const Line &a, const Line &b, const Line &c)\
    \ {\n    if (b.b == a.b || c.b == b.b)\n      return sgn(b.a - a.a) * sgn(c.b\
    \ - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);\n    // return (b.a-a.a)*(c.b-b.b)\
    \ >= (b.b-a.b)*(c.a-b.a);\n    return D(b.a - a.a) * sgn(c.b - b.b) / D(abs(b.b\
    \ - a.b)) >=\n           D(c.a - b.a) * sgn(b.b - a.b) / D(abs(c.b - b.b));\n\
    \  }\n\n  void add(T a, T b, int idx = -1) {\n    if (idx == -1) {\n      idx\
    \ = nxt_idx++;\n    }\n    if (!isMin) a *= -1, b *= -1;\n    Line L{a, b, idx};\n\
    \    if (empty()) {\n      H.emplace_front(L);\n      return;\n    }\n    if (H.front().a\
    \ <= a) {\n      if (H.front().a == a) {\n        if (H.front().b <= b) return;\n\
    \        H.pop_front();\n      }\n      while (H.size() >= 2 && check(L, H.front(),\
    \ H[1])) {\n        H.pop_front();\n      }\n      H.emplace_front(L);\n    }\
    \ else {\n      assert(a <= H.back().a);\n      if (H.back().a == a) {\n     \
    \   if (H.back().b <= b) return;\n        H.pop_back();\n      }\n      while\
    \ (H.size() >= 2 && check(H[H.size() - 2], H.back(), L)) H.pop_back();\n     \
    \ H.emplace_back(L);\n    }\n  }\n\n  inline T get_y(const Line &a, const T &x)\
    \ { return a.a * x + a.b; }\n\n  pair<T, int> query(T x) {\n    assert(!empty());\n\
    \    int l = -1, r = H.size() - 1;\n    while (l + 1 < r) {\n      int m = (l\
    \ + r) >> 1;\n      if (get_y(H[m], x) >= get_y(H[m + 1], x))\n        l = m;\n\
    \      else\n        r = m;\n    }\n    if (isMin) return {get_y(H[r], x), H[r].idx};\n\
    \    return {-get_y(H[r], x), H[r].idx};\n  }\n\n  pair<T, int> query_monotone_inc(T\
    \ x) {\n    assert(!empty());\n    while (H.size() >= 2 && get_y(H.front(), x)\
    \ >= get_y(H[1], x))\n      H.pop_front();\n    if (isMin) return {get_y(H.front(),\
    \ x), H.front().idx};\n    return {-get_y(H.front(), x), H.front().idx};\n  }\n\
    \n  pair<T, int> query_monotone_dec(T x) {\n    assert(!empty());\n    while (H.size()\
    \ >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\n      H.pop_back();\n\
    \    if (isMin) return {get_y(H.back(), x), H.back().idx};\n    return {-get_y(H.back(),\
    \ x), H.back().idx};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/convex/cht_monotone.hpp\n\
    template <typename T, bool isMin>\nstruct CHT_Monotone {\n  static_assert(is_same_v<T,\
    \ ll> || std::is_floating_point_v<T>);\n  struct Line {\n    T a, b;\n    int\
    \ idx;\n  };\n  deque<Line> H;\n  int nxt_idx = 0;\n\n  CHT_Monotone() = default;\n\
    \n  bool empty() const { return H.empty(); }\n  void clear() { H.clear(); }\n\n\
    \  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }\n  using D =\
    \ long double;\n  inline bool check(const Line &a, const Line &b, const Line &c)\
    \ {\n    if (b.b == a.b || c.b == b.b)\n      return sgn(b.a - a.a) * sgn(c.b\
    \ - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);\n    // return (b.a-a.a)*(c.b-b.b)\
    \ >= (b.b-a.b)*(c.a-b.a);\n    return D(b.a - a.a) * sgn(c.b - b.b) / D(abs(b.b\
    \ - a.b)) >=\n           D(c.a - b.a) * sgn(b.b - a.b) / D(abs(c.b - b.b));\n\
    \  }\n\n  void add(T a, T b, int idx = -1) {\n    if (idx == -1) {\n      idx\
    \ = nxt_idx++;\n    }\n    if (!isMin) a *= -1, b *= -1;\n    Line L{a, b, idx};\n\
    \    if (empty()) {\n      H.emplace_front(L);\n      return;\n    }\n    if (H.front().a\
    \ <= a) {\n      if (H.front().a == a) {\n        if (H.front().b <= b) return;\n\
    \        H.pop_front();\n      }\n      while (H.size() >= 2 && check(L, H.front(),\
    \ H[1])) {\n        H.pop_front();\n      }\n      H.emplace_front(L);\n    }\
    \ else {\n      assert(a <= H.back().a);\n      if (H.back().a == a) {\n     \
    \   if (H.back().b <= b) return;\n        H.pop_back();\n      }\n      while\
    \ (H.size() >= 2 && check(H[H.size() - 2], H.back(), L)) H.pop_back();\n     \
    \ H.emplace_back(L);\n    }\n  }\n\n  inline T get_y(const Line &a, const T &x)\
    \ { return a.a * x + a.b; }\n\n  pair<T, int> query(T x) {\n    assert(!empty());\n\
    \    int l = -1, r = H.size() - 1;\n    while (l + 1 < r) {\n      int m = (l\
    \ + r) >> 1;\n      if (get_y(H[m], x) >= get_y(H[m + 1], x))\n        l = m;\n\
    \      else\n        r = m;\n    }\n    if (isMin) return {get_y(H[r], x), H[r].idx};\n\
    \    return {-get_y(H[r], x), H[r].idx};\n  }\n\n  pair<T, int> query_monotone_inc(T\
    \ x) {\n    assert(!empty());\n    while (H.size() >= 2 && get_y(H.front(), x)\
    \ >= get_y(H[1], x))\n      H.pop_front();\n    if (isMin) return {get_y(H.front(),\
    \ x), H.front().idx};\n    return {-get_y(H.front(), x), H.front().idx};\n  }\n\
    \n  pair<T, int> query_monotone_dec(T x) {\n    assert(!empty());\n    while (H.size()\
    \ >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))\n      H.pop_back();\n\
    \    if (isMin) return {get_y(H.back(), x), H.back().idx};\n    return {-get_y(H.back(),\
    \ x), H.back().idx};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht_monotone.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1297.test.cpp
  - test/3_yukicoder/913.test.cpp
documentation_of: convex/cht_monotone.hpp
layout: document
redirect_from:
- /library/convex/cht_monotone.hpp
- /library/convex/cht_monotone.hpp.html
title: convex/cht_monotone.hpp
---
