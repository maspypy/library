---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1209/problem/G1
  bundledCode: "#line 1 \"graph/blackbox/interval_graph_unionfind.hpp\"\n\n#line 2\
    \ \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int>\
    \ dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void build(int\
    \ m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void reset()\
    \ { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0) {\n    \
    \  int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n      x = dat[x]\
    \ = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n\n\
    \  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] = (*this)[i];\n\
    \    return A;\n  }\n};\n#line 3 \"graph/blackbox/interval_graph_unionfind.hpp\"\
    \n\n// \u533A\u9593\u306F [L, R). \u4EA4\u308F\u308A\u304C\u7A7A\u3067\u306A\u3044\
    \u3082\u306E\u3092 union\uFF0E\n// https://codeforces.com/contest/1209/problem/G1\n\
    UnionFind interval_graph_unionfind(int N, vc<int> L, vc<int> R) {\n  // \u5305\
    \u542B\u306E\u3042\u308B\u5834\u5408\u542B\u307E\u308C\u3066\u3044\u308B\u3082\
    \u306E\u3092\u30DE\u30FC\u30B8\u3057\u3066\u524A\u9664\u3059\u308B\n  // \u5305\
    \u542B\u304C\u306A\u304F\u306A\u3063\u305F\u3089\u96A3\u63A5\u3057\u3066\u3044\
    \u308B\u3082\u306E\u3092\u30DE\u30FC\u30B8\u3059\u308B\n  assert(len(L) == N &&\
    \ len(R) == N);\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n\n  sort(all(I), [&](auto&\
    \ a, auto& b) -> bool {\n    if (L[a] != L[b]) return L[a] < L[b];\n    return\
    \ R[a] > R[b];\n  });\n\n  UnionFind uf(N);\n  vc<int> keep;\n  for (auto& j:\
    \ I) {\n    if (!keep.empty()) {\n      int i = keep.back();\n      if (R[j] <=\
    \ R[i] && R[j] - L[j] < R[i] - L[i]) {\n        uf.merge(i, j);\n        continue;\n\
    \      }\n    }\n    keep.eb(j);\n  }\n  FOR(k, len(keep) - 1) {\n    int i =\
    \ keep[k], j = keep[k + 1];\n    if (max(L[i], L[j]) < min(R[i], R[j])) uf.merge(i,\
    \ j);\n  }\n  return uf;\n}\n"
  code: "\n#include \"ds/unionfind/unionfind.hpp\"\n\n// \u533A\u9593\u306F [L, R).\
    \ \u4EA4\u308F\u308A\u304C\u7A7A\u3067\u306A\u3044\u3082\u306E\u3092 union\uFF0E\
    \n// https://codeforces.com/contest/1209/problem/G1\nUnionFind interval_graph_unionfind(int\
    \ N, vc<int> L, vc<int> R) {\n  // \u5305\u542B\u306E\u3042\u308B\u5834\u5408\u542B\
    \u307E\u308C\u3066\u3044\u308B\u3082\u306E\u3092\u30DE\u30FC\u30B8\u3057\u3066\
    \u524A\u9664\u3059\u308B\n  // \u5305\u542B\u304C\u306A\u304F\u306A\u3063\u305F\
    \u3089\u96A3\u63A5\u3057\u3066\u3044\u308B\u3082\u306E\u3092\u30DE\u30FC\u30B8\
    \u3059\u308B\n  assert(len(L) == N && len(R) == N);\n  vc<int> I(N);\n  FOR(i,\
    \ N) I[i] = i;\n\n  sort(all(I), [&](auto& a, auto& b) -> bool {\n    if (L[a]\
    \ != L[b]) return L[a] < L[b];\n    return R[a] > R[b];\n  });\n\n  UnionFind\
    \ uf(N);\n  vc<int> keep;\n  for (auto& j: I) {\n    if (!keep.empty()) {\n  \
    \    int i = keep.back();\n      if (R[j] <= R[i] && R[j] - L[j] < R[i] - L[i])\
    \ {\n        uf.merge(i, j);\n        continue;\n      }\n    }\n    keep.eb(j);\n\
    \  }\n  FOR(k, len(keep) - 1) {\n    int i = keep[k], j = keep[k + 1];\n    if\
    \ (max(L[i], L[j]) < min(R[i], R[j])) uf.merge(i, j);\n  }\n  return uf;\n}\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/blackbox/interval_graph_unionfind.hpp
  requiredBy: []
  timestamp: '2024-03-10 03:27:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/interval_graph_unionfind.hpp
layout: document
redirect_from:
- /library/graph/blackbox/interval_graph_unionfind.hpp
- /library/graph/blackbox/interval_graph_unionfind.hpp.html
title: graph/blackbox/interval_graph_unionfind.hpp
---
