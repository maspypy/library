---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':x:'
    path: other/mex.hpp
    title: other/mex.hpp
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
    \ (*this)[i];\n    return A;\n  }\n};\n#line 1 \"other/mex.hpp\"\nint mex(const\
    \ vc<int>& A) {\n  int n = len(A);\n  vc<bool> aru(n + 1);\n  for (auto& x: A)\n\
    \    if (x < n) aru[x] = 1;\n  int mex = 0;\n  while (aru[mex]) ++mex;\n  return\
    \ mex;\n}\n#line 3 \"string/inverse_manacher.hpp\"\n\n// \u5404\u70B9\u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u6975\u5927\u56DE\u6587\u306E\u9577\u3055 (in [1,3,5,...])\n\
    // \u8F9E\u66F8\u6700\u5C0F OR empty\nvc<int> inverse_manacher(vc<int> R) {\n\
    \  for (auto& x: R) assert(x & 1), x = (x + 1) / 2;\n  ll N = len(R);\n  UnionFind\
    \ uf(N);\n  vvc<int> DIFF(N);\n  int i = 0;\n  int j = 0;\n  while (i < N) {\n\
    \    while (i >= j && i + j < N) {\n      if (R[i] != j) {\n        if (j) { uf.merge(i\
    \ + j, i - j); }\n        j += 1;\n      } else {\n        DIFF[i + j].eb(i -\
    \ j);\n        DIFF[i - j].eb(i + j);\n        break;\n      }\n    }\n    if\
    \ (R[i] != j) return {};\n    int k = 1;\n    while (i >= k && i + k < N && k\
    \ + R[i - k] < j) {\n      if (R[i + k] != R[i - k]) return {};\n      k += 1;\n\
    \    }\n    i += k;\n    j -= k;\n  }\n  vvc<int> vs(N);\n  FOR(v, N) vs[uf[v]].eb(v);\n\
    \  vc<int> ANS(N, -1);\n  FOR(v, N) {\n    int r = uf[v];\n    if (ANS[r] != -1)\
    \ continue;\n    vc<int> tmp;\n    for (auto& w: vs[r]) {\n      for (auto& to:\
    \ DIFF[w]) {\n        if (ANS[to] != -1) tmp.eb(ANS[to]);\n      }\n    }\n  \
    \  int x = mex(tmp);\n    for (auto& w: vs[r]) ANS[w] = x;\n  }\n  return ANS;\n\
    }\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n#include \"other/mex.hpp\"\n\n//\
    \ \u5404\u70B9\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6975\u5927\u56DE\u6587\u306E\
    \u9577\u3055 (in [1,3,5,...])\n// \u8F9E\u66F8\u6700\u5C0F OR empty\nvc<int> inverse_manacher(vc<int>\
    \ R) {\n  for (auto& x: R) assert(x & 1), x = (x + 1) / 2;\n  ll N = len(R);\n\
    \  UnionFind uf(N);\n  vvc<int> DIFF(N);\n  int i = 0;\n  int j = 0;\n  while\
    \ (i < N) {\n    while (i >= j && i + j < N) {\n      if (R[i] != j) {\n     \
    \   if (j) { uf.merge(i + j, i - j); }\n        j += 1;\n      } else {\n    \
    \    DIFF[i + j].eb(i - j);\n        DIFF[i - j].eb(i + j);\n        break;\n\
    \      }\n    }\n    if (R[i] != j) return {};\n    int k = 1;\n    while (i >=\
    \ k && i + k < N && k + R[i - k] < j) {\n      if (R[i + k] != R[i - k]) return\
    \ {};\n      k += 1;\n    }\n    i += k;\n    j -= k;\n  }\n  vvc<int> vs(N);\n\
    \  FOR(v, N) vs[uf[v]].eb(v);\n  vc<int> ANS(N, -1);\n  FOR(v, N) {\n    int r\
    \ = uf[v];\n    if (ANS[r] != -1) continue;\n    vc<int> tmp;\n    for (auto&\
    \ w: vs[r]) {\n      for (auto& to: DIFF[w]) {\n        if (ANS[to] != -1) tmp.eb(ANS[to]);\n\
    \      }\n    }\n    int x = mex(tmp);\n    for (auto& w: vs[r]) ANS[w] = x;\n\
    \  }\n  return ANS;\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  - other/mex.hpp
  isVerificationFile: false
  path: string/inverse_manacher.hpp
  requiredBy: []
  timestamp: '2024-10-11 20:53:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/inverse_manacher.hpp
layout: document
redirect_from:
- /library/string/inverse_manacher.hpp
- /library/string/inverse_manacher.hpp.html
title: string/inverse_manacher.hpp
---
