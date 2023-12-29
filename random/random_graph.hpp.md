---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/count_clique.test.cpp
    title: test/mytest/count_clique.test.cpp
  - icon: ':x:'
    path: test/mytest/count_indep_set.test.cpp
    title: test/mytest/count_indep_set.test.cpp
  - icon: ':x:'
    path: test/mytest/find_odd_cycle.test.cpp
    title: test/mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_ve.test.cpp
    title: test/mytest/matching_ve.test.cpp
  - icon: ':x:'
    path: test/mytest/tree_walk_gf.test.cpp
    title: test/mytest/tree_walk_gf.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) swap(A[i],\
    \ A[RNG(0, i + 1)]);\n}\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind\
    \ {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0)\
    \ { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 4 \"random/random_graph.hpp\"\n\nvoid random_relabel(int\
    \ N, vc<pair<int, int>>& G) {\n  shuffle(G);\n  vc<int> A(N);\n  FOR(i, N) A[i]\
    \ = i;\n  shuffle(A);\n  for (auto& [a, b]: G) a = A[a], b = A[b];\n}\n\ntemplate\
    \ <int DIRECTED>\nvc<pair<int, int>> random_graph(int n, bool simple) {\n  vc<pair<int,\
    \ int>> G, cand;\n  FOR(a, n) FOR(b, n) {\n    if (simple && a == b) continue;\n\
    \    if (!DIRECTED && a > b) continue;\n    cand.eb(a, b);\n  }\n  int m = RNG(0,\
    \ len(cand) + 1);\n  set<int> ss;\n  FOR(m) {\n    while (1) {\n      int i =\
    \ RNG(0, len(cand));\n      if (simple && ss.count(i)) continue;\n      ss.insert(i);\n\
    \      auto [a, b] = cand[i];\n      G.eb(a, b);\n      break;\n    }\n  }\n \
    \ random_relabel(n, G);\n  return G;\n}\n\nvc<pair<int, int>> random_tree(int\
    \ n) {\n  vc<pair<int, int>> G;\n  FOR(i, 1, n) { G.eb(RNG(0, i), i); }\n  random_relabel(n,\
    \ G);\n  return G;\n}\n\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\
    \u30A4\u30AF\u30EB\uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\
    \u305F\u306F\u8FBA\uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\
    \u4E00\u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\
    \u307E\u305F\u306F\u8FBA\uFF09\nvc<pair<int, int>> random_cactus(int N, bool EDGE)\
    \ {\n  if (!EDGE) {\n    // n \u9802\u70B9\u3092 1 \u307E\u305F\u306F 3 \u4EE5\
    \u4E0A\u306B\u5206\u5272\n    vvc<int> A;\n    int n = RNG(1, N + 1);\n    vc<int>\
    \ S(n, 1);\n    int rest = N - n;\n    while (rest > 0) {\n      int k = RNG(0,\
    \ n);\n      if (S[k] == 1) {\n        if (rest == 1) {\n          S.eb(1), rest\
    \ = 0;\n        } else {\n          S[k] += 2, rest -= 2;\n        }\n      }\
    \ else {\n        S[k]++, rest--;\n      }\n    }\n    n = len(S);\n    int p\
    \ = 0;\n    FOR(i, n) {\n      vc<int> C;\n      FOR(v, p, p + S[i]) C.eb(v);\n\
    \      A.eb(C);\n      p += S[i];\n    }\n    int m = len(A);\n    auto H = random_tree(m);\n\
    \    vc<pair<int, int>> G;\n    FOR(i, m) {\n      vc<int>& V = A[i];\n      if\
    \ (len(V) == 1) continue;\n      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]);\
    \ }\n    }\n    for (auto& [c1, c2]: H) {\n      int a = A[c1][RNG(0, len(A[c1]))];\n\
    \      int b = A[c2][RNG(0, len(A[c2]))];\n      G.eb(a, b);\n    }\n    random_relabel(N,\
    \ G);\n    return G;\n  }\n  assert(EDGE);\n  if (N == 1) return {};\n  int n\
    \ = RNG(1, N);\n  vc<int> S(n, 2);\n  int rest = N - 1 - n;\n  while (rest > 0)\
    \ {\n    int k = RNG(0, n);\n    S[k]++, --rest;\n  }\n  vvc<int> A;\n  int p\
    \ = 0;\n  FOR(i, n) {\n    vc<int> C;\n    FOR(v, p, p + S[i]) C.eb(v);\n    A.eb(C);\n\
    \    p += S[i];\n  }\n  assert(p == N + n - 1);\n  UnionFind uf(p);\n  auto H\
    \ = random_tree(n);\n  for (auto& [c1, c2]: H) {\n    int a = A[c1][RNG(0, len(A[c1]))];\n\
    \    int b = A[c2][RNG(0, len(A[c2]))];\n    uf.merge(a, b);\n  }\n  vc<int> new_idx(p);\n\
    \  int x = 0;\n  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;\n  assert(x == N);\n\
    \  FOR(i, p) new_idx[i] = new_idx[uf[i]];\n  vc<pair<int, int>> G;\n  FOR(i, n)\
    \ {\n    vc<int>& V = A[i];\n    for (auto& v: V) v = new_idx[v];\n    if (len(V)\
    \ == 2) {\n      G.eb(V[0], V[1]);\n    } else {\n      FOR(k, len(V)) { G.eb(V[k],\
    \ V[(1 + k) % len(V)]); }\n    }\n  }\n  random_relabel(N, G);\n  return G;\n\
    }\n"
  code: "#include \"random/base.hpp\"\n#include \"random/shuffle.hpp\"\n#include \"\
    ds/unionfind/unionfind.hpp\"\n\nvoid random_relabel(int N, vc<pair<int, int>>&\
    \ G) {\n  shuffle(G);\n  vc<int> A(N);\n  FOR(i, N) A[i] = i;\n  shuffle(A);\n\
    \  for (auto& [a, b]: G) a = A[a], b = A[b];\n}\n\ntemplate <int DIRECTED>\nvc<pair<int,\
    \ int>> random_graph(int n, bool simple) {\n  vc<pair<int, int>> G, cand;\n  FOR(a,\
    \ n) FOR(b, n) {\n    if (simple && a == b) continue;\n    if (!DIRECTED && a\
    \ > b) continue;\n    cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n\
    \  set<int> ss;\n  FOR(m) {\n    while (1) {\n      int i = RNG(0, len(cand));\n\
    \      if (simple && ss.count(i)) continue;\n      ss.insert(i);\n      auto [a,\
    \ b] = cand[i];\n      G.eb(a, b);\n      break;\n    }\n  }\n  random_relabel(n,\
    \ G);\n  return G;\n}\n\nvc<pair<int, int>> random_tree(int n) {\n  vc<pair<int,\
    \ int>> G;\n  FOR(i, 1, n) { G.eb(RNG(0, i), i); }\n  random_relabel(n, G);\n\
    \  return G;\n}\n\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\u30A4\
    \u30AF\u30EB\uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\
    \u306F\u8FBA\uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\u4E00\
    \u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\u307E\
    \u305F\u306F\u8FBA\uFF09\nvc<pair<int, int>> random_cactus(int N, bool EDGE) {\n\
    \  if (!EDGE) {\n    // n \u9802\u70B9\u3092 1 \u307E\u305F\u306F 3 \u4EE5\u4E0A\
    \u306B\u5206\u5272\n    vvc<int> A;\n    int n = RNG(1, N + 1);\n    vc<int> S(n,\
    \ 1);\n    int rest = N - n;\n    while (rest > 0) {\n      int k = RNG(0, n);\n\
    \      if (S[k] == 1) {\n        if (rest == 1) {\n          S.eb(1), rest = 0;\n\
    \        } else {\n          S[k] += 2, rest -= 2;\n        }\n      } else {\n\
    \        S[k]++, rest--;\n      }\n    }\n    n = len(S);\n    int p = 0;\n  \
    \  FOR(i, n) {\n      vc<int> C;\n      FOR(v, p, p + S[i]) C.eb(v);\n      A.eb(C);\n\
    \      p += S[i];\n    }\n    int m = len(A);\n    auto H = random_tree(m);\n\
    \    vc<pair<int, int>> G;\n    FOR(i, m) {\n      vc<int>& V = A[i];\n      if\
    \ (len(V) == 1) continue;\n      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]);\
    \ }\n    }\n    for (auto& [c1, c2]: H) {\n      int a = A[c1][RNG(0, len(A[c1]))];\n\
    \      int b = A[c2][RNG(0, len(A[c2]))];\n      G.eb(a, b);\n    }\n    random_relabel(N,\
    \ G);\n    return G;\n  }\n  assert(EDGE);\n  if (N == 1) return {};\n  int n\
    \ = RNG(1, N);\n  vc<int> S(n, 2);\n  int rest = N - 1 - n;\n  while (rest > 0)\
    \ {\n    int k = RNG(0, n);\n    S[k]++, --rest;\n  }\n  vvc<int> A;\n  int p\
    \ = 0;\n  FOR(i, n) {\n    vc<int> C;\n    FOR(v, p, p + S[i]) C.eb(v);\n    A.eb(C);\n\
    \    p += S[i];\n  }\n  assert(p == N + n - 1);\n  UnionFind uf(p);\n  auto H\
    \ = random_tree(n);\n  for (auto& [c1, c2]: H) {\n    int a = A[c1][RNG(0, len(A[c1]))];\n\
    \    int b = A[c2][RNG(0, len(A[c2]))];\n    uf.merge(a, b);\n  }\n  vc<int> new_idx(p);\n\
    \  int x = 0;\n  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;\n  assert(x == N);\n\
    \  FOR(i, p) new_idx[i] = new_idx[uf[i]];\n  vc<pair<int, int>> G;\n  FOR(i, n)\
    \ {\n    vc<int>& V = A[i];\n    for (auto& v: V) v = new_idx[v];\n    if (len(V)\
    \ == 2) {\n      G.eb(V[0], V[1]);\n    } else {\n      FOR(k, len(V)) { G.eb(V[k],\
    \ V[(1 + k) % len(V)]); }\n    }\n  }\n  random_relabel(N, G);\n  return G;\n\
    }\n"
  dependsOn:
  - random/base.hpp
  - random/shuffle.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: random/random_graph.hpp
  requiredBy: []
  timestamp: '2023-12-14 00:43:16+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/count_clique.test.cpp
  - test/mytest/matching_ve.test.cpp
  - test/mytest/matching_line_graph.test.cpp
  - test/mytest/find_odd_cycle.test.cpp
  - test/mytest/count_indep_set.test.cpp
  - test/mytest/tree_walk_gf.test.cpp
documentation_of: random/random_graph.hpp
layout: document
redirect_from:
- /library/random/random_graph.hpp
- /library/random/random_graph.hpp.html
title: random/random_graph.hpp
---
