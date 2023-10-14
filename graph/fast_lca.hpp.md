---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/fast_lca.hpp\"\n\n#line 2 \"alg/monoid/min_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return\
    \ true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se\
    \ < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x,\
    \ y) ? x : y); }\r\n  static constexpr X unit() { return {infty<T>, -1}; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return infty<E>; }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n#line 1 \"ds/sparse_table/sparse_table.hpp\"\
    \n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\
    \u3092\u4EEE\u5B9A\u3002disjoint sparse table \u3088\u308A x \u500D\u9AD8\u901F\
    \ntemplate <class Monoid>\nstruct Sparse_Table {\n  using MX = Monoid;\n  using\
    \ X = typename MX::value_type;\n  int n, log;\n  vvc<X> dat;\n\n  Sparse_Table()\
    \ {}\n  Sparse_Table(int n) { build(n); }\n  template <typename F>\n  Sparse_Table(int\
    \ n, F f) {\n    build(n, f);\n  }\n  Sparse_Table(const vc<X>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return MX::unit();\
    \ });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    dat.resize(log);\n\
    \    dat[0].resize(n);\n    FOR(i, n) dat[0][i] = f(i);\n\n    FOR(i, log - 1)\
    \ {\n      dat[i + 1].resize(len(dat[i]) - (1 << i));\n      FOR(j, len(dat[i])\
    \ - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);\n\
    \      }\n    }\n  }\n\n  X prod(int L, int R) {\n    if (L == R) return MX::unit();\n\
    \    if (R == L + 1) return dat[0][L];\n    int k = topbit(R - L - 1);\n    return\
    \ MX::op(dat[k][L], dat[k][R - (1 << k)]);\n  }\n\n  template <class F>\n  int\
    \ max_right(const F check, int L) {\n    assert(0 <= L && L <= n && check(MX::unit()));\n\
    \    if (L == n) return n;\n    int ok = L, ng = n + 1;\n    while (ok + 1 < ng)\
    \ {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(L, k));\n      if\
    \ (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n\n  template\
    \ <class F>\n  int min_left(const F check, int R) {\n    assert(0 <= R && R <=\
    \ n && check(MX::unit()));\n    if (R == 0) return 0;\n    int ok = R, ng = -1;\n\
    \    while (ng + 1 < ok) {\n      int k = (ok + ng) / 2;\n      bool bl = check(prod(k,\
    \ R));\n      if (bl) ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n\
    \  }\n};\n#line 5 \"graph/fast_lca.hpp\"\n\n// sparse table \u3092\u4F7F\u3046\
    \ <O(NlogN),O(1)>\n// dist_only \u306E\u65B9\u304C 2 \u5272\u304F\u3089\u3044\u9AD8\
    \u901F\u304B\ntemplate <typename TREE, bool dist_only>\nstruct Fast_Lca {\n  TREE&\
    \ tree;\n  Sparse_Table<Monoid_Min<int>> seg_mi;\n  Sparse_Table<Monoid_Min_Idx<int>>\
    \ seg_mi_idx;\n  vc<int> pos;\n\n  Fast_Lca(TREE& tree) : tree(tree) {\n    int\
    \ N = tree.N;\n    pos.resize(N);\n    if constexpr (dist_only) {\n      vc<int>\
    \ dat(2 * N - 1);\n      FOR(v, N) {\n        int a = tree.ELID(v);\n        int\
    \ b = tree.ERID(v);\n        int d = tree.depth[v];\n        dat[a] = d;\n   \
    \     pos[v] = a;\n        if (b < 2 * N - 1) dat[b] = d - 1;\n      }\n     \
    \ seg_mi.build(dat);\n    } else {\n      vc<pair<int, int>> dat(2 * N - 1);\n\
    \      FOR(v, N) {\n        int a = tree.ELID(v);\n        int b = tree.ERID(v);\n\
    \        int d = tree.depth[v];\n        pos[v] = a;\n        dat[a] = {d, v};\n\
    \        if (b < 2 * N - 1) dat[b] = {d - 1, tree.parent[v]};\n      }\n     \
    \ seg_mi_idx.build(dat);\n    }\n  }\n\n  int lca(int a, int b) {\n    static_assert(!dist_only);\n\
    \    return lca_and_dist(a, b).fi;\n  }\n\n  int dist(int a, int b) {\n    if\
    \ constexpr (dist_only) {\n      int da = tree.depth[a], db = tree.depth[b];\n\
    \      int p = pos[a], q = pos[b];\n      if (p > q) swap(p, q);\n      return\
    \ da + db - 2 * seg_mi.prod(p, q + 1);\n    } else {\n      return lca_and_dist(a,\
    \ b).se;\n    }\n  }\n\n  pair<int, int> lca_and_dist(int a, int b) {\n    int\
    \ da = tree.depth[a], db = tree.depth[b];\n    int p = pos[a], q = pos[b];\n \
    \   if (p > q) swap(p, q);\n    auto [dc, c] = seg_mi_idx.prod(p, q + 1);\n  \
    \  return {c, da + db - dc - dc};\n  }\n};\n"
  code: "\n#include \"alg/monoid/min_idx.hpp\"\n#include \"alg/monoid/min.hpp\"\n\
    #include \"ds/sparse_table/sparse_table.hpp\"\n\n// sparse table \u3092\u4F7F\u3046\
    \ <O(NlogN),O(1)>\n// dist_only \u306E\u65B9\u304C 2 \u5272\u304F\u3089\u3044\u9AD8\
    \u901F\u304B\ntemplate <typename TREE, bool dist_only>\nstruct Fast_Lca {\n  TREE&\
    \ tree;\n  Sparse_Table<Monoid_Min<int>> seg_mi;\n  Sparse_Table<Monoid_Min_Idx<int>>\
    \ seg_mi_idx;\n  vc<int> pos;\n\n  Fast_Lca(TREE& tree) : tree(tree) {\n    int\
    \ N = tree.N;\n    pos.resize(N);\n    if constexpr (dist_only) {\n      vc<int>\
    \ dat(2 * N - 1);\n      FOR(v, N) {\n        int a = tree.ELID(v);\n        int\
    \ b = tree.ERID(v);\n        int d = tree.depth[v];\n        dat[a] = d;\n   \
    \     pos[v] = a;\n        if (b < 2 * N - 1) dat[b] = d - 1;\n      }\n     \
    \ seg_mi.build(dat);\n    } else {\n      vc<pair<int, int>> dat(2 * N - 1);\n\
    \      FOR(v, N) {\n        int a = tree.ELID(v);\n        int b = tree.ERID(v);\n\
    \        int d = tree.depth[v];\n        pos[v] = a;\n        dat[a] = {d, v};\n\
    \        if (b < 2 * N - 1) dat[b] = {d - 1, tree.parent[v]};\n      }\n     \
    \ seg_mi_idx.build(dat);\n    }\n  }\n\n  int lca(int a, int b) {\n    static_assert(!dist_only);\n\
    \    return lca_and_dist(a, b).fi;\n  }\n\n  int dist(int a, int b) {\n    if\
    \ constexpr (dist_only) {\n      int da = tree.depth[a], db = tree.depth[b];\n\
    \      int p = pos[a], q = pos[b];\n      if (p > q) swap(p, q);\n      return\
    \ da + db - 2 * seg_mi.prod(p, q + 1);\n    } else {\n      return lca_and_dist(a,\
    \ b).se;\n    }\n  }\n\n  pair<int, int> lca_and_dist(int a, int b) {\n    int\
    \ da = tree.depth[a], db = tree.depth[b];\n    int p = pos[a], q = pos[b];\n \
    \   if (p > q) swap(p, q);\n    auto [dc, c] = seg_mi_idx.prod(p, q + 1);\n  \
    \  return {c, da + db - dc - dc};\n  }\n};\n"
  dependsOn:
  - alg/monoid/min_idx.hpp
  - alg/monoid/min.hpp
  - ds/sparse_table/sparse_table.hpp
  isVerificationFile: false
  path: graph/fast_lca.hpp
  requiredBy: []
  timestamp: '2023-10-06 05:10:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/fast_lca.hpp
layout: document
redirect_from:
- /library/graph/fast_lca.hpp
- /library/graph/fast_lca.hpp.html
title: graph/fast_lca.hpp
---
