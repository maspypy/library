---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/restore_euler_tour.hpp
    title: graph/restore_euler_tour.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/decremental_fastset.test.cpp
    title: test/1_mytest/decremental_fastset.test.cpp
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
    \ : (1ULL << n) - 1; }\n#line 1 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind\
    \ {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0)\
    \ { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 3 \"ds/decremental_fastset.hpp\"\
    \n\n// amortized linear\n// MoFR \u306A\u3057\u3060\u3068 FastSet \u3088\u308A\
    \u9045\u304B\u3063\u305F\nstruct Decremental_FastSet {\n  struct Decremental_Neighbor_UF\
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
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F&&\
    \ f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n  string\
    \ to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0' + (dat[i / 64]\
    \ >> (i & 63) & 1);\n    return S;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\n//\
    \ amortized linear\n// MoFR \u306A\u3057\u3060\u3068 FastSet \u3088\u308A\u9045\
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
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F&&\
    \ f) {\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\n  }\n\n  string\
    \ to_string() {\n    string S(N, '.');\n    FOR(i, N) S[i] = '0' + (dat[i / 64]\
    \ >> (i & 63) & 1);\n    return S;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: ds/decremental_fastset.hpp
  requiredBy:
  - graph/restore_euler_tour.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
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
