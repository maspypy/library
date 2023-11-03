---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_A.test.cpp
    title: test/aoj/ITP1_11_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_B.test.cpp
    title: test/aoj/ITP1_11_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_C.test.cpp
    title: test/aoj/ITP1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/tenka1-2012-final/tasks/tenka1_2012_final_e
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 2 \"other/dice.hpp\"\n\n// \u6B21\u306E\u756A\u53F7\u4ED8\u3051\
    \u308B\u306B\u5F93\u3046\uFF1AUFRLBD\n// i, 5-i \u304C\u53CD\u5BFE\u306E\u9762\
    \u306B\u306A\u3063\u3066\u3044\u308B\n// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n\
    // https://atcoder.jp/contests/tenka1-2012-final/tasks/tenka1_2012_final_e\ntemplate\
    \ <typename X>\nstruct Dice {\n  using ARR = array<X, 6>;\n  ARR A;\n\n  Dice(ARR\
    \ A) : A(A) {}\n\n  X U() { return A[0]; }\n  X F() { return A[1]; }\n  X R()\
    \ { return A[2]; }\n  X L() { return A[3]; }\n  X B() { return A[4]; }\n  X D()\
    \ { return A[5]; }\n\n  // U \u306E\u3046\u3064\u308B\u5148\u3068\u306A\u308B\
    \ FRLB \u3092\u6307\u5B9A\u3059\u308B or \u65B9\u89D2 NWES \u3092\u6307\u5B9A\u3059\
    \u308B\n  void rotate(char c) {\n    if (c == 'F' || c == 'S') A = {A[4], A[0],\
    \ A[2], A[3], A[5], A[1]};\n    elif (c == 'R' || c == 'E') A = {A[3], A[1], A[0],\
    \ A[5], A[4], A[2]};\n    elif (c == 'L' || c == 'W') A = {A[2], A[1], A[5], A[0],\
    \ A[4], A[3]};\n    elif (c == 'B' || c == 'N') A = {A[1], A[5], A[2], A[3], A[0],\
    \ A[4]};\n    elif (c == 'U') A = {A[0], A[2], A[4], A[1], A[3], A[5]};\n    elif\
    \ (c == 'D') A = {A[0], A[3], A[1], A[4], A[2], A[5]};\n    else {\n      assert(false);\n\
    \    }\n  }\n\n  vc<ARR> gen_all() {\n    vc<ARR> res(24);\n    vc<tuple<int,\
    \ int, int>> tmp(24);\n    tmp[0] = {0, 1, 2};\n    tmp[1] = {0, 4, 3};\n    tmp[2]\
    \ = {5, 1, 3};\n    tmp[3] = {5, 4, 2};\n\n    FOR(i, 4) {\n      auto [a, b,\
    \ c] = tmp[i];\n      tmp[4 + i] = {b, c, a};\n      tmp[8 + i] = {c, a, b};\n\
    \    }\n\n    FOR(i, 12) {\n      auto [a, b, c] = tmp[i];\n      tmp[12 + i]\
    \ = {5 - b, a, c};\n    }\n\n    FOR(i, 24) {\n      auto [a, b, c] = tmp[i];\n\
    \      res[i] = {A[a], A[b], A[c], A[5 - c], A[5 - b], A[5 - a]};\n    }\n   \
    \ return res;\n  }\n\n  // 24 \u9802\u70B9 6 \u9077\u79FB\u306E\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u308B\n  Graph<int, 0> to_graph() {\n    int N = 24;\n    Graph<int,\
    \ 0> G(N);\n    auto dat = gen_all();\n    FOR(i, N) {\n      array<X, 6> A =\
    \ dat[i];\n      for (char ch: {'U', 'F', 'R', 'L', 'B', 'D'}) {\n        Dice<X>\
    \ d(A);\n        d.rotate(ch);\n        int idx = -1;\n        FOR(j, N) if (dat[j]\
    \ == d.A) idx = j;\n        assert(idx != -1);\n        if (i < idx) G.add(i,\
    \ idx);\n      }\n    }\n    G.build();\n    return G;\n  }\n};\n"
  code: "#include \"graph/base.hpp\"\n\n// \u6B21\u306E\u756A\u53F7\u4ED8\u3051\u308B\
    \u306B\u5F93\u3046\uFF1AUFRLBD\n// i, 5-i \u304C\u53CD\u5BFE\u306E\u9762\u306B\
    \u306A\u3063\u3066\u3044\u308B\n// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_11_A\n\
    // https://atcoder.jp/contests/tenka1-2012-final/tasks/tenka1_2012_final_e\ntemplate\
    \ <typename X>\nstruct Dice {\n  using ARR = array<X, 6>;\n  ARR A;\n\n  Dice(ARR\
    \ A) : A(A) {}\n\n  X U() { return A[0]; }\n  X F() { return A[1]; }\n  X R()\
    \ { return A[2]; }\n  X L() { return A[3]; }\n  X B() { return A[4]; }\n  X D()\
    \ { return A[5]; }\n\n  // U \u306E\u3046\u3064\u308B\u5148\u3068\u306A\u308B\
    \ FRLB \u3092\u6307\u5B9A\u3059\u308B or \u65B9\u89D2 NWES \u3092\u6307\u5B9A\u3059\
    \u308B\n  void rotate(char c) {\n    if (c == 'F' || c == 'S') A = {A[4], A[0],\
    \ A[2], A[3], A[5], A[1]};\n    elif (c == 'R' || c == 'E') A = {A[3], A[1], A[0],\
    \ A[5], A[4], A[2]};\n    elif (c == 'L' || c == 'W') A = {A[2], A[1], A[5], A[0],\
    \ A[4], A[3]};\n    elif (c == 'B' || c == 'N') A = {A[1], A[5], A[2], A[3], A[0],\
    \ A[4]};\n    elif (c == 'U') A = {A[0], A[2], A[4], A[1], A[3], A[5]};\n    elif\
    \ (c == 'D') A = {A[0], A[3], A[1], A[4], A[2], A[5]};\n    else {\n      assert(false);\n\
    \    }\n  }\n\n  vc<ARR> gen_all() {\n    vc<ARR> res(24);\n    vc<tuple<int,\
    \ int, int>> tmp(24);\n    tmp[0] = {0, 1, 2};\n    tmp[1] = {0, 4, 3};\n    tmp[2]\
    \ = {5, 1, 3};\n    tmp[3] = {5, 4, 2};\n\n    FOR(i, 4) {\n      auto [a, b,\
    \ c] = tmp[i];\n      tmp[4 + i] = {b, c, a};\n      tmp[8 + i] = {c, a, b};\n\
    \    }\n\n    FOR(i, 12) {\n      auto [a, b, c] = tmp[i];\n      tmp[12 + i]\
    \ = {5 - b, a, c};\n    }\n\n    FOR(i, 24) {\n      auto [a, b, c] = tmp[i];\n\
    \      res[i] = {A[a], A[b], A[c], A[5 - c], A[5 - b], A[5 - a]};\n    }\n   \
    \ return res;\n  }\n\n  // 24 \u9802\u70B9 6 \u9077\u79FB\u306E\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u308B\n  Graph<int, 0> to_graph() {\n    int N = 24;\n    Graph<int,\
    \ 0> G(N);\n    auto dat = gen_all();\n    FOR(i, N) {\n      array<X, 6> A =\
    \ dat[i];\n      for (char ch: {'U', 'F', 'R', 'L', 'B', 'D'}) {\n        Dice<X>\
    \ d(A);\n        d.rotate(ch);\n        int idx = -1;\n        FOR(j, N) if (dat[j]\
    \ == d.A) idx = j;\n        assert(idx != -1);\n        if (i < idx) G.add(i,\
    \ idx);\n      }\n    }\n    G.build();\n    return G;\n  }\n};\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: other/dice.hpp
  requiredBy: []
  timestamp: '2023-11-01 01:33:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_11_B.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/ITP1_11_D.test.cpp
  - test/aoj/ITP1_11_C.test.cpp
documentation_of: other/dice.hpp
layout: document
redirect_from:
- /library/other/dice.hpp
- /library/other/dice.hpp.html
title: other/dice.hpp
---
