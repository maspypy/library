---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/polygon_triangulation.hpp
    title: geo/polygon_triangulation.hpp
  - icon: ':warning:'
    path: seq/cycle_decomposition.hpp
    title: seq/cycle_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/splaytree/splaytree.hpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"ds/splaytree/splaytree.hpp\"\n\nnamespace SplayTreeNodes {\ntemplate\
    \ <typename S>\nstruct Node_Basic {\n  using value_type = S;\n  using operator_type\
    \ = int;\n  using np = Node_Basic *;\n\n  np p, l, r;\n  bool rev;\n  S x;\n \
    \ u32 size;\n\n  static void new_node(np n, const S &x) {\n    n->p = n->l = n->r\
    \ = nullptr;\n    n->x = x, n->size = 1, n->rev = 0;\n  }\n\n  void update() {\n\
    \    size = 1;\n    if (l) { size += l->size; }\n    if (r) { size += r->size;\
    \ }\n  }\n\n  void prop() {\n    if (rev) {\n      if (l) { l->rev ^= 1, swap(l->l,\
    \ l->r); }\n      if (r) { r->rev ^= 1, swap(r->l, r->r); }\n      rev = 0;\n\
    \    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\
    \u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\
    \u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\u305D\
    \u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\
    \u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  S get() { return x; }\n  void set(const\
    \ S &xx) {\n    x = xx;\n    update();\n  }\n  void reverse() {\n    swap(l, r);\n\
    \    rev ^= 1;\n  }\n};\ntemplate <typename S>\nusing SplayTree_Basic = SplayTree<Node_Basic<S>>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Basic;\n"
  dependsOn:
  - ds/splaytree/splaytree.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/splaytree/splaytree_basic.hpp
  requiredBy:
  - seq/cycle_decomposition.hpp
  - geo/polygon_triangulation.hpp
  timestamp: '2025-09-16 13:47:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: ds/splaytree/splaytree_basic.hpp
layout: document
redirect_from:
- /library/ds/splaytree/splaytree_basic.hpp
- /library/ds/splaytree/splaytree_basic.hpp.html
title: ds/splaytree/splaytree_basic.hpp
---
