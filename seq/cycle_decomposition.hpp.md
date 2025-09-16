---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/jag2017summer-day3/tasks/jag2017summer_day3_k
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"ds/splaytree/splaytree_basic.hpp\"\n\n// \u9806\u5217\u306E\u30B5\
    \u30A4\u30AF\u30EB\u5206\u89E3\u3092\u7BA1\u7406\n// https://atcoder.jp/contests/jag2017summer-day3/tasks/jag2017summer_day3_k\n\
    struct Cycle_Decomposition {\n  int N, n_comp;\n  SplayTree_Basic<int> ST;\n \
    \ using np = decltype(ST)::np;\n  vc<np> node;\n\n  Cycle_Decomposition(int N)\
    \ : N(N), n_comp(N), ST(N), node(N) { FOR(i, N) node[i] = ST.new_node(i); }\n\n\
    \  // v \u304C\u5C5E\u3059\u308B\u6210\u5206\u306E\u756A\u53F7, \u305D\u306E\u6210\
    \u5206\u306E\u4F55\u756A\u76EE\u304B\n  pair<int, int> get(int v) {\n    ST.splay(node[v],\
    \ true);\n    np root = node[v];\n    int idx = (root->l ? root->l->size : 0);\n\
    \    ST.splay_kth(root, 0);\n    return {root->x, idx};\n  }\n\n  int get_comp(int\
    \ v) { return get(v).fi; }\n  int size(int v) {\n    ST.splay(node[v], true);\n\
    \    return node[v]->size;\n  }\n\n  // \u672B\u5C3E\u306B\u79FB\u52D5\n  // [a,b,...,v,...]\
    \ \u306E\u3068\u304D\u306B [...,a,b,...,v] \u306B\u5909\u5F62\n  void rotate(int\
    \ v) {\n    ST.splay(node[v], true);\n    int ls = (node[v]->l ? node[v]->l->size\
    \ : 0);\n    auto [l, r] = ST.split(node[v], ls + 1);\n    ST.merge(r, l);\n \
    \ }\n\n  void swap(int i, int j) {\n    if (get_comp(i) != get_comp(j)) {\n  \
    \    --n_comp;\n      rotate(i), rotate(j);\n      ST.splay(node[i], true), ST.splay(node[j],\
    \ true);\n      ST.merge(node[i], node[j]);\n    } else {\n      ++n_comp;\n \
    \     rotate(j);\n      ST.splay(node[i], true);\n      int k = (node[i]->l ?\
    \ node[i]->l->size : 0) + 1;\n      ST.split(node[i], k);\n      ST.splay(node[i],\
    \ true), ST.splay(node[j], true);\n    }\n  }\n};"
  dependsOn:
  - ds/splaytree/splaytree_basic.hpp
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: seq/cycle_decomposition.hpp
  requiredBy: []
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/cycle_decomposition.hpp
layout: document
redirect_from:
- /library/seq/cycle_decomposition.hpp
- /library/seq/cycle_decomposition.hpp.html
title: seq/cycle_decomposition.hpp
---
