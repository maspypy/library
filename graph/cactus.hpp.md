---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/csr.hpp
    title: ds/csr.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/graph/cactus.hpp
  bundledCode: "#line 1 \"graph/cactus.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/cactus.hpp\n\
    \n#line 1 \"ds/csr.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/csr.hpp\n\
    \ntemplate <typename T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int> ptr;\n\
    \  vc<int> I;\n  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false) {}\n \
    \ void reserve(int n) { dat.reserve(n); }\n\n  void add(int i, const T& x) {\n\
    \    assert(0 <= i && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n \
    \ void build() {\n    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n\
    \ + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i\
    \ + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int\
    \ i = I[k];\n      tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n\
    \    ptr.insert(ptr.begin(), 0);\n    I.clear();\n  }\n\n  struct range {\n  \
    \  T *first, *last;\n    T* begin() const { return first; }\n    T* end() const\
    \ { return last; }\n    bool empty() const { return first == last; }\n    int\
    \ size() const { return last - first; }\n  };\n\n  range operator[](int i) {\n\
    \    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data() + ptr[i\
    \ + 1]};\n  }\n};\n#line 4 \"graph/cactus.hpp\"\n\n// block \u306E index \u306B\
    \u9802\u70B9\u5217\u304C\u5165\u308B\nCSR<int> get_cactus_cycles(\n    Graph<int,\
    \ 0>& G, Graph<int, 0>& BCT, Tree<Graph<int, 0>>& tree) {\n  CSR<pair<int, int>>\
    \ es(BCT.N);\n  CSR<int> cs(BCT.N);\n  for (auto& e : G.edges) {\n    int a =\
    \ e.frm, b = e.to;\n    int k = tree.jump(a, b, 1);\n    es.add(k, {a, b});\n\
    \  }\n  es.build();\n  vc<int> SM(G.N);\n\n  vc<pair<int, int>> E;\n  vc<int>\
    \ C;\n  FOR(k, G.N, BCT.N) {\n    E.clear();\n    for (auto& [a, b] : es[k]) E.eb(a,\
    \ b);\n    if (len(E) == 1) continue;\n    for (auto& [a, b] : E) SM[a] += b,\
    \ SM[b] += a;\n    C.clear();\n    C.eb(E[0].fi);\n    C.eb(E[0].se);\n    while\
    \ (C.back() != C[0]) {\n      int a = C[len(C) - 2], b = C[len(C) - 1];\n    \
    \  C.eb(SM[b] - a);\n    }\n    POP(C);\n    for (int v : C) cs.add(k, v);\n \
    \   for (auto& [a, b] : E) SM[a] -= b, SM[b] -= a;\n  }\n  cs.build();\n  return\
    \ cs;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/cactus.hpp\n\
    \n#include \"ds/csr.hpp\"\n\n// block \u306E index \u306B\u9802\u70B9\u5217\u304C\
    \u5165\u308B\nCSR<int> get_cactus_cycles(\n    Graph<int, 0>& G, Graph<int, 0>&\
    \ BCT, Tree<Graph<int, 0>>& tree) {\n  CSR<pair<int, int>> es(BCT.N);\n  CSR<int>\
    \ cs(BCT.N);\n  for (auto& e : G.edges) {\n    int a = e.frm, b = e.to;\n    int\
    \ k = tree.jump(a, b, 1);\n    es.add(k, {a, b});\n  }\n  es.build();\n  vc<int>\
    \ SM(G.N);\n\n  vc<pair<int, int>> E;\n  vc<int> C;\n  FOR(k, G.N, BCT.N) {\n\
    \    E.clear();\n    for (auto& [a, b] : es[k]) E.eb(a, b);\n    if (len(E) ==\
    \ 1) continue;\n    for (auto& [a, b] : E) SM[a] += b, SM[b] += a;\n    C.clear();\n\
    \    C.eb(E[0].fi);\n    C.eb(E[0].se);\n    while (C.back() != C[0]) {\n    \
    \  int a = C[len(C) - 2], b = C[len(C) - 1];\n      C.eb(SM[b] - a);\n    }\n\
    \    POP(C);\n    for (int v : C) cs.add(k, v);\n    for (auto& [a, b] : E) SM[a]\
    \ -= b, SM[b] -= a;\n  }\n  cs.build();\n  return cs;\n}"
  dependsOn:
  - ds/csr.hpp
  isVerificationFile: false
  path: graph/cactus.hpp
  requiredBy: []
  timestamp: '2026-10-17 16:27:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cactus.hpp
layout: document
redirect_from:
- /library/graph/cactus.hpp
- /library/graph/cactus.hpp.html
title: graph/cactus.hpp
---
