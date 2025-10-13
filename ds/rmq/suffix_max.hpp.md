---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/rmq/suffix_max.hpp\"\n\n//\
    \ \u672B\u5C3E\u4EE3\u5165\n// find min of (a[i],...,a[p-1])\ntemplate <typename\
    \ T>\nstruct Suffix_Max {\n  // \u5185\u90E8\u7684\u306A\u51E6\u7406\u3068\u3057\
    \u3066\u306F a \u3067\u306F\u306A\u304F ANS \u3092\u7BA1\u7406\u3059\u308B.\n\
    \  // ANS[0],...,ANS[p] \u306B chmax(x) \u304C\u6765\u308B\u3068\u601D\u3046\n\
    \  int N, p;\n  UnionFind uf;\n  vc<T> ANS;\n  vc<pair<T, int>> st;  // (value,\
    \ uf root)\n  Suffix_Max(int N) : N(N), p(0), uf(N + 1), ANS(N + 1, -infty<T>)\
    \ {\n    st.reserve(N);\n  }\n\n  void reset() {\n    uf.reset();\n    fill(all(ANS),\
    \ -infty<T>);\n    st.clear();\n    p = 0;\n  }\n\n  void set(int i, T x) {\n\
    \    assert(p == i);\n    while (!st.empty() && st.back().fi <= x) {\n      uf.merge(p,\
    \ st.back().se);\n      st.pop_back();\n    }\n    int r = uf[p++];\n    ANS[r]\
    \ = x, st.eb(x, r);\n  }\n  T query(int i) {\n    assert(i <= p);\n    return\
    \ ANS[uf[i]];\n  }\n};\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// \u672B\u5C3E\u4EE3\u5165\n\
    // find min of (a[i],...,a[p-1])\ntemplate <typename T>\nstruct Suffix_Max {\n\
    \  // \u5185\u90E8\u7684\u306A\u51E6\u7406\u3068\u3057\u3066\u306F a \u3067\u306F\
    \u306A\u304F ANS \u3092\u7BA1\u7406\u3059\u308B.\n  // ANS[0],...,ANS[p] \u306B\
    \ chmax(x) \u304C\u6765\u308B\u3068\u601D\u3046\n  int N, p;\n  UnionFind uf;\n\
    \  vc<T> ANS;\n  vc<pair<T, int>> st;  // (value, uf root)\n  Suffix_Max(int N)\
    \ : N(N), p(0), uf(N + 1), ANS(N + 1, -infty<T>) {\n    st.reserve(N);\n  }\n\n\
    \  void reset() {\n    uf.reset();\n    fill(all(ANS), -infty<T>);\n    st.clear();\n\
    \    p = 0;\n  }\n\n  void set(int i, T x) {\n    assert(p == i);\n    while (!st.empty()\
    \ && st.back().fi <= x) {\n      uf.merge(p, st.back().se);\n      st.pop_back();\n\
    \    }\n    int r = uf[p++];\n    ANS[r] = x, st.eb(x, r);\n  }\n  T query(int\
    \ i) {\n    assert(i <= p);\n    return ANS[uf[i]];\n  }\n};"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: ds/rmq/suffix_max.hpp
  requiredBy: []
  timestamp: '2025-10-13 18:56:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/rmq/suffix_max.hpp
layout: document
redirect_from:
- /library/ds/rmq/suffix_max.hpp
- /library/ds/rmq/suffix_max.hpp.html
title: ds/rmq/suffix_max.hpp
---
