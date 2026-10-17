---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':warning:'
    path: ds/weight_balanced_tree/wbt_base.hpp
    title: ds/weight_balanced_tree/wbt_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/weight_balanced_tree/wbt_basic.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/weight_balanced_tree/wbt_basic.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/weight_balanced_tree/wbt_basic.hpp\n\
    #pragma once\n#include \"ds/node_pool.hpp\"\n#include \"ds/weight_balanced_tree/wbt_base.hpp\"\
    \n\ntemplate <typename S>\nstruct WBT_Basic_Node {\n  WBT_Basic_Node *l, *r;\n\
    \  S s;\n  u32 size;\n  bool rev;\n};\n\ntemplate <typename S, bool PERSISTENT>\n\
    struct WBT_Basic : WBT_Sequence_Base<WBT_Basic<S, PERSISTENT>,\n             \
    \          WBT_Basic_Node<S>, PERSISTENT> {\n  using Node = WBT_Basic_Node<S>;\n\
    \  using Base = WBT_Sequence_Base<WBT_Basic, Node, PERSISTENT>;\n  using np =\
    \ Node*;\n  Node_Pool<Node> pool;\n  void reset() { pool.reset(); }\n  np new_root()\
    \ { return nullptr; }\n  np new_node(const S& s) {\n    np t = pool.create();\n\
    \    t->l = t->r = nullptr, t->s = s, t->size = 1, t->rev = 0;\n    return t;\n\
    \  }\n  np new_node(const vc<S>& a) {\n    auto f = [&](auto&& f, u32 l, u32 r)\
    \ -> np {\n      if (l == r) return nullptr;\n      u32 m = (l + r) >> 1;\n  \
    \    np t = new_node(a[m]);\n      t->l = f(f, l, m), t->r = f(f, m + 1, r);\n\
    \      pull(t);\n      return t;\n    };\n    return f(f, 0, a.size());\n  }\n\
    \  np clone(np t) { return (!t || !PERSISTENT) ? t : pool.clone(t); }\n  void\
    \ pull(np t) {\n    t->size = 1 + (t->l ? t->l->size : 0) + (t->r ? t->r->size\
    \ : 0);\n  }\n  void push(np t) {\n    if (!t->rev) return;\n    if (t->l) {\n\
    \      t->l = clone(t->l);\n      t->l->rev ^= 1;\n      swap(t->l->l, t->l->r);\n\
    \    }\n    if (t->r) {\n      t->r = clone(t->r);\n      t->r->rev ^= 1;\n  \
    \    swap(t->r->l, t->r->r);\n    }\n    t->rev = 0;\n  }\n  np reverse(np t,\
    \ u32 l, u32 r) {\n    assert(l <= r && r <= t->size);\n    if (r - l <= 1) return\
    \ t;\n    auto [a, b, c] = this->split3(t, l, r);\n    b = clone(b);\n    b->rev\
    \ ^= 1;\n    swap(b->l, b->r);\n    return this->merge3(a, b, c);\n  }\n  np set(np\
    \ t, u32 k, const S& x) {\n    auto [a, b, c] = this->split3(t, k, k + 1);\n \
    \   b = clone(b);\n    b->s = x;\n    pull(b);\n    return this->merge3(a, b,\
    \ c);\n  }\n  S get(np t, u32 k) {\n    bool z = 0;\n    while (1) {\n      np\
    \ l = z ? t->r : t->l, r = z ? t->l : t->r;\n      u32 s = l ? l->size : 0;\n\
    \      if (k == s) return t->s;\n      z ^= t->rev;\n      if (k < s)\n      \
    \  t = l;\n      else {\n        k -= s + 1;\n        t = r;\n      }\n    }\n\
    \  }\n  vc<S> get_all(np t) {\n    vc<S> a;\n    auto f = [&](auto&& f, np x,\
    \ bool z) -> void {\n      if (!x) return;\n      f(f, z ? x->r : x->l, z ^ x->rev);\n\
    \      a.eb(x->s);\n      f(f, z ? x->l : x->r, z ^ x->rev);\n    };\n    f(f,\
    \ t, 0);\n    return a;\n  }\n\n  template <class F>\n  pair<np, np> split_max_right(np\
    \ t, const F& check) {\n    return split_max_right_rec(t, check);\n  }\n\n  void\
    \ free_subtree(np t) {\n    if (!t) return;\n    free_subtree(t->l);\n    free_subtree(t->r);\n\
    \    pool.destroy(t);\n  }\n\n private:\n  template <class F>\n  pair<np, np>\
    \ split_max_right_rec(np t, const F& check) {\n    if (!t) return {nullptr, nullptr};\n\
    \    t = clone(t);  // Must precede push() when PERSISTENT=true.\n    push(t);\n\
    \    np l = t->l, r = t->r;\n    t->l = t->r = nullptr;\n    pull(t);  // t is\
    \ the singleton x required by join().\n    if (check(t->s)) {\n      auto [a,\
    \ b] = split_max_right_rec(r, check);\n      return {this->join(l, t, a), b};\n\
    \    }\n    auto [a, b] = split_max_right_rec(l, check);\n    return {a, this->join(b,\
    \ t, r)};\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  - ds/weight_balanced_tree/wbt_base.hpp
  isVerificationFile: false
  path: ds/weight_balanced_tree/wbt_basic.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/weight_balanced_tree/wbt_basic.hpp
layout: document
redirect_from:
- /library/ds/weight_balanced_tree/wbt_basic.hpp
- /library/ds/weight_balanced_tree/wbt_basic.hpp.html
title: ds/weight_balanced_tree/wbt_basic.hpp
---
