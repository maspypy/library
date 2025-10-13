---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/decremental_fastset.test.cpp
    title: test/1_mytest/decremental_fastset.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/decremental_fastset.hpp\"\n\
    \n// amortized linear\n// MoFR \u306A\u3057\u3060\u3068 FastSet \u3088\u308A\u9045\
    \u304B\u3063\u305F\nstruct Decremental_FastSet {\n  struct Decremental_Neighbor_UF\
    \ {\n    int n;\n    UnionFind uf;\n    vc<int> L, R;\n    Decremental_Neighbor_UF(int\
    \ n) : n(n), uf(n + 2), L(n + 2), R(n + 2) {\n      FOR(i, n + 2) L[i] = i, R[i]\
    \ = i;\n    }\n    void erase(int i) {\n      assert(0 <= i && i < n);\n     \
    \ ++i;\n      int l = L[uf[i - 1]], r = R[uf[i]];\n      uf.merge(i, i - 1);\n\
    \      L[uf[i]] = l, R[uf[i]] = r;\n    }\n    int prev(int i) {\n      assert(-1\
    \ <= i);\n      chmin(i, n - 1);\n      return L[uf[i + 1]] - 1;\n    }\n    int\
    \ next(int i) {\n      assert(i <= n);\n      chmax(i, 0);\n      return R[uf[i]];\n\
    \    }\n  };\n  int N, n;\n  vc<u64> dat;\n  Decremental_Neighbor_UF X;\n  Decremental_FastSet(int\
    \ N) : N(N), n((N + 63) / 64), X(n) {\n    dat.assign(n, u64(-1));\n    if (n)\
    \ dat.back() = u64(-1) >> (64 * n - N);\n  }\n\n  bool operator[](int i) { return\
    \ (dat[i / 64] >> (i & 63) & 1); }\n\n  void erase(int i) {\n    int a = i / 64,\
    \ b = i & 63;\n    if (!(dat[a] >> b & 1)) return;\n    dat[a] &= ~(u64(1) <<\
    \ b);\n    if (dat[a] == 0) {\n      X.erase(a);\n    }\n  }\n  int prev(int i)\
    \ {\n    assert(-1 <= i);\n    chmin(i, N - 1);\n    if (i == -1) return -1;\n\
    \    int a = i / 64, b = i & 63;\n    u64 x = dat[a] & (u64(-1) >> (63 - b));\n\
    \    if (x != 0) return 64 * a + topbit(x);\n    a = X.prev(a - 1);\n    return\
    \ (a == -1 ? -1 : 64 * a + topbit(dat[a]));\n  }\n  int next(int i) {\n    assert(i\
    \ <= N);\n    chmax(i, 0);\n    if (i == N) return N;\n    int a = i / 64, b =\
    \ i & 63;\n    u64 x = dat[a] >> b;\n    if (x != 0) return 64 * a + b + lowbit(x);\n\
    \    a = X.next(a + 1);\n    return (a == n ? N : 64 * a + lowbit(dat[a]));\n\
    \  }\n\n  string to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0'\
    \ + (dat[i / 64] >> (i & 63) & 1);\n    return S;\n  }\n};\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// amortized linear\n// MoFR \u306A\
    \u3057\u3060\u3068 FastSet \u3088\u308A\u9045\u304B\u3063\u305F\nstruct Decremental_FastSet\
    \ {\n  struct Decremental_Neighbor_UF {\n    int n;\n    UnionFind uf;\n    vc<int>\
    \ L, R;\n    Decremental_Neighbor_UF(int n) : n(n), uf(n + 2), L(n + 2), R(n +\
    \ 2) {\n      FOR(i, n + 2) L[i] = i, R[i] = i;\n    }\n    void erase(int i)\
    \ {\n      assert(0 <= i && i < n);\n      ++i;\n      int l = L[uf[i - 1]], r\
    \ = R[uf[i]];\n      uf.merge(i, i - 1);\n      L[uf[i]] = l, R[uf[i]] = r;\n\
    \    }\n    int prev(int i) {\n      assert(-1 <= i);\n      chmin(i, n - 1);\n\
    \      return L[uf[i + 1]] - 1;\n    }\n    int next(int i) {\n      assert(i\
    \ <= n);\n      chmax(i, 0);\n      return R[uf[i]];\n    }\n  };\n  int N, n;\n\
    \  vc<u64> dat;\n  Decremental_Neighbor_UF X;\n  Decremental_FastSet(int N) :\
    \ N(N), n((N + 63) / 64), X(n) {\n    dat.assign(n, u64(-1));\n    if (n) dat.back()\
    \ = u64(-1) >> (64 * n - N);\n  }\n\n  bool operator[](int i) { return (dat[i\
    \ / 64] >> (i & 63) & 1); }\n\n  void erase(int i) {\n    int a = i / 64, b =\
    \ i & 63;\n    if (!(dat[a] >> b & 1)) return;\n    dat[a] &= ~(u64(1) << b);\n\
    \    if (dat[a] == 0) {\n      X.erase(a);\n    }\n  }\n  int prev(int i) {\n\
    \    assert(-1 <= i);\n    chmin(i, N - 1);\n    if (i == -1) return -1;\n   \
    \ int a = i / 64, b = i & 63;\n    u64 x = dat[a] & (u64(-1) >> (63 - b));\n \
    \   if (x != 0) return 64 * a + topbit(x);\n    a = X.prev(a - 1);\n    return\
    \ (a == -1 ? -1 : 64 * a + topbit(dat[a]));\n  }\n  int next(int i) {\n    assert(i\
    \ <= N);\n    chmax(i, 0);\n    if (i == N) return N;\n    int a = i / 64, b =\
    \ i & 63;\n    u64 x = dat[a] >> b;\n    if (x != 0) return 64 * a + b + lowbit(x);\n\
    \    a = X.next(a + 1);\n    return (a == n ? N : 64 * a + lowbit(dat[a]));\n\
    \  }\n\n  string to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0'\
    \ + (dat[i / 64] >> (i & 63) & 1);\n    return S;\n  }\n};\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: ds/decremental_fastset.hpp
  requiredBy: []
  timestamp: '2025-10-13 19:02:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/decremental_fastset.test.cpp
documentation_of: ds/decremental_fastset.hpp
layout: document
redirect_from:
- /library/ds/decremental_fastset.hpp
- /library/ds/decremental_fastset.hpp.html
title: ds/decremental_fastset.hpp
---
