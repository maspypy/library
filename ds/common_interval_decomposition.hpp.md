---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/lazy/min_add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree.hpp\"\n#include \"alg/lazy/min_add.hpp\"\n\ntemplate\
    \ <int NODES>\nstruct Common_Inverval_Decomposition {\n  struct Node {\n    vc<Node*>\
    \ ch;\n    bool inc, dec;\n    int l, r, lo, hi;\n  };\n\n  Node* pool;\n  Node*\
    \ root;\n  int pid;\n\n  Common_Inverval_Decomposition(vc<int>& P) : pid(0) {\n\
    \    pool = new Node[NODES];\n    build(P);\n  }\n\n  Node* new_node(bool inc,\
    \ bool dec, int l, int r, int lo, int hi) {\n    pool[pid].inc = inc;\n    pool[pid].dec\
    \ = dec;\n    pool[pid].l = l;\n    pool[pid].r = r;\n    pool[pid].lo = lo;\n\
    \    pool[pid].hi = hi;\n    return &(pool[pid++]);\n  }\n\n  void build(vc<int>&\
    \ P) {\n    int N = len(P);\n    using Lazy = Lazy_Min_Add<int>;\n    LazySegTree<Lazy>\
    \ seg(vc<int>(N, 0));\n\n    vc<Node*> st;\n    vc<int> mi = {-1}, ma = {-1};\n\
    \    FOR(i, N) {\n      while (mi.back() != -1 && P[i] < P[mi.back()]) {\n   \
    \     int j = pick(mi);\n        seg.apply(mi.back() + 1, j + 1, P[j] - P[i]);\n\
    \      }\n      while (ma.back() != -1 && P[i] > P[ma.back()]) {\n        int\
    \ j = pick(ma);\n        seg.apply(ma.back() + 1, j + 1, P[i] - P[j]);\n     \
    \ }\n      mi.eb(i), ma.eb(i);\n\n      Node* now = new_node(0, 0, i, i + 1, P[i],\
    \ P[i] + 1);\n      while (len(st)) {\n        Node* n = st.back();\n        if\
    \ (n->hi == now->lo) {\n          if (n->inc) {\n            n->ch.eb(now);\n\
    \            n->r = now->r;\n            n->hi = now->hi;\n            now = n;\n\
    \            st.pop_back();\n          } else {\n            Node* p = new_node(1,\
    \ 0, n->l, now->r, n->lo, now->hi);\n            p->ch.eb(n);\n            p->ch.eb(now);\n\
    \            now = p;\n            st.pop_back();\n          }\n          continue;\n\
    \        }\n        if (n->lo == now->hi) {\n          if (n->dec) {\n       \
    \     n->ch.eb(now);\n            n->r = now->r;\n            n->lo = now->lo;\n\
    \            now = n;\n            st.pop_back();\n          } else {\n      \
    \      Node* p = new_node(0, 1, n->l, now->r, now->lo, n->hi);\n            p->ch.eb(n);\n\
    \            p->ch.eb(now);\n            now = p;\n            st.pop_back();\n\
    \          }\n          continue;\n        }\n        // prime supernode creation\n\
    \        if (seg.prod(0, now->l) != 0) break;\n        Node* p = new_node(0, 0,\
    \ now->l, now->r, now->lo, now->hi);\n        p->ch.eb(now);\n        now = p;\n\
    \        while (1) {\n          auto c = pick(st);\n          now->l = c->l;\n\
    \          chmin(now->lo, c->lo);\n          chmax(now->hi, c->hi);\n        \
    \  now->ch.eb(c);\n          if (now->r - now->l == now->hi - now->lo) break;\n\
    \        }\n        reverse(all(now->ch));\n      }\n      st.eb(now);\n     \
    \ seg.apply(0, i + 1, -1);\n    }\n    assert(len(st) == 1);\n    root = pick(st);\n\
    \    return;\n  }\n\n  void debug() {\n    auto dfs = [&](auto& dfs, Node* n)\
    \ -> void {\n      print(\"l, r, lo, hi\", n->l, n->r, n->lo, n->hi);\n      for\
    \ (auto&& c: n->ch) dfs(dfs, c);\n    };\n    dfs(dfs, root);\n  };\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/common_interval_decomposition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/common_interval_decomposition.hpp
layout: document
redirect_from:
- /library/ds/common_interval_decomposition.hpp
- /library/ds/common_interval_decomposition.hpp.html
title: ds/common_interval_decomposition.hpp
---
