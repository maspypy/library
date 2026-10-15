---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    - https://github.com/maspypy/library/blob/main/ds/weight_balanced_tree/wbt_monoid.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/weight_balanced_tree/wbt_monoid.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/weight_balanced_tree/wbt_monoid.hpp\n\
    #pragma once\n#include \"ds/node_pool.hpp\"\n#include \"ds/weight_balanced_tree/wbt_base.hpp\"\
    \n\ntemplate <class X>\nstruct WBT_Monoid_Node {\n  WBT_Monoid_Node *l, *r;\n\
    \  X x, prod, rev_prod;\n  u32 size;\n  bool rev;\n};\ntemplate <class Monoid,\
    \ bool PERSISTENT>\nstruct WBT_Monoid\n    : WBT_Sequence_Base<WBT_Monoid<Monoid,\
    \ PERSISTENT>,\n          WBT_Monoid_Node<typename Monoid::value_type>, PERSISTENT>\
    \ {\n  using X = typename Monoid::value_type;\n  using Node = WBT_Monoid_Node<X>;\n\
    \  using np = Node*;\n  using Base = WBT_Sequence_Base<WBT_Monoid, Node, PERSISTENT>;\n\
    \  Node_Pool<Node> pool;\n  void reset() { pool.reset(); }\n  np new_root() {\
    \ return nullptr; }\n  np new_node(const X& x) {\n    np t = pool.create();\n\
    \    t->l = t->r = nullptr;\n    t->x = t->prod = t->rev_prod = x;\n    t->size\
    \ = 1;\n    t->rev = 0;\n    return t;\n  }\n  np new_node(const vc<X>& a) {\n\
    \    auto f = [&](auto&& f, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n\
    \      u32 m = (l + r) >> 1;\n      np t = new_node(a[m]);\n      t->l = f(f,\
    \ l, m), t->r = f(f, m + 1, r);\n      pull(t);\n      return t;\n    };\n   \
    \ return f(f, 0, a.size());\n  }\n  np clone(np t) { return (!t || !PERSISTENT)\
    \ ? t : pool.clone(t); }\n  void pull(np t) {\n    t->size = 1;\n    t->prod =\
    \ t->rev_prod = t->x;\n    if (t->l) {\n      t->size += t->l->size;\n      t->prod\
    \ = Monoid::op(t->l->prod, t->prod);\n      t->rev_prod = Monoid::op(t->rev_prod,\
    \ t->l->rev_prod);\n    }\n    if (t->r) {\n      t->size += t->r->size;\n   \
    \   t->prod = Monoid::op(t->prod, t->r->prod);\n      t->rev_prod = Monoid::op(t->r->rev_prod,\
    \ t->rev_prod);\n    }\n  }\n  void push(np t) {\n    if (!t->rev) return;\n \
    \   for (np* q : {&t->l, &t->r})\n      if (*q) {\n        *q = clone(*q);\n \
    \       (*q)->rev ^= 1;\n        swap((*q)->l, (*q)->r);\n        swap((*q)->prod,\
    \ (*q)->rev_prod);\n      }\n    t->rev = 0;\n  }\n  np reverse(np t, u32 l, u32\
    \ r) {\n    assert(l <= r && r <= t->size);\n    if (r - l <= 1) return t;\n \
    \   auto [a, b, c] = this->split3(t, l, r);\n    b = clone(b);\n    b->rev ^=\
    \ 1;\n    swap(b->l, b->r);\n    swap(b->prod, b->rev_prod);\n    return this->merge3(a,\
    \ b, c);\n  }\n  np set(np t, u32 k, const X& x) {\n    auto [a, b, c] = this->split3(t,\
    \ k, k + 1);\n    b = clone(b);\n    b->x = x;\n    pull(b);\n    return this->merge3(a,\
    \ b, c);\n  }\n  np multiply(np t, u32 k, const X& x) {\n    return set(t, k,\
    \ Monoid::op(get(t, k), x));\n  }\n  X prod(np t) { return t ? t->prod : Monoid::id();\
    \ }\n  X prod(np t, u32 l, u32 r) {\n    assert(l <= r && r <= t->size);\n   \
    \ return prod_rec(t, l, r, 0);\n  }\n  X get(np t, u32 k) {\n    bool z = 0;\n\
    \    while (1) {\n      np l = z ? t->r : t->l, r = z ? t->l : t->r;\n      u32\
    \ s = l ? l->size : 0;\n      if (k == s) return t->x;\n      z ^= t->rev;\n \
    \     if (k < s)\n        t = l;\n      else\n        k -= s + 1, t = r;\n   \
    \ }\n  }\n  vc<X> get_all(np t) {\n    vc<X> a;\n    auto f = [&](auto&& f, np\
    \ q, bool z) -> void {\n      if (!q) return;\n      f(f, z ? q->r : q->l, z ^\
    \ q->rev);\n      a.eb(q->x);\n      f(f, z ? q->l : q->r, z ^ q->rev);\n    };\n\
    \    f(f, t, 0);\n    return a;\n  }\n  template <class F>\n  pair<np, np> split_max_right(np\
    \ t, const F& check) {\n    assert(check(Monoid::id()));\n    X x = Monoid::id();\n\
    \    return split_max_right_rec(t, check, x);\n  }\n  template <class F>\n  pair<np,\
    \ np> split_max_right_prod(np t, const F& f) {\n    return split_max_right(t,\
    \ f);\n  }\n\n  void free_subtree(np t) {\n    if (!t) return;\n    free_subtree(t->l);\n\
    \    free_subtree(t->r);\n    pool.destroy(t);\n  }\n\n private:\n  X prod_rec(np\
    \ t, u32 l, u32 r, bool z) {\n    if (l == 0 && r == t->size) return z ? t->rev_prod\
    \ : t->prod;\n    np a = z ? t->r : t->l, b = z ? t->l : t->r;\n    u32 s = a\
    \ ? a->size : 0;\n    X x = Monoid::id();\n    if (l < s) x = Monoid::op(x, prod_rec(a,\
    \ l, min(r, s), z ^ t->rev));\n    if (l <= s && s < r) x = Monoid::op(x, t->x);\n\
    \    if (s + 1 < r)\n      x = Monoid::op(\n          x, prod_rec(b, max(l, s\
    \ + 1) - s - 1, r - s - 1, z ^ t->rev));\n    return x;\n  }\n\n  // Add under\
    \ private: in WBT_Monoid.\n  template <class F>\n  pair<np, np> split_max_right_rec(np\
    \ t, const F& check, X& x) {\n    if (!t) return {nullptr, nullptr};\n    X y\
    \ = Monoid::op(x, t->prod);\n    if (check(y)) {\n      x = y;\n      return {t,\
    \ nullptr};\n    }\n    t = clone(t);  // Must precede push() when PERSISTENT=true.\n\
    \    push(t);\n    np l = t->l, r = t->r;\n    if (l) {\n      y = Monoid::op(x,\
    \ l->prod);\n      if (!check(y)) {\n        auto [a, b] = split_max_right_rec(l,\
    \ check, x);\n        t->l = b;\n        pull(t);\n        return {a, t};\n  \
    \    }\n      x = y;\n    }\n    y = Monoid::op(x, t->x);\n    if (!check(y))\
    \ {\n      t->l = nullptr;\n      pull(t);\n      return {l, t};\n    }\n    x\
    \ = y;\n    auto [a, b] = split_max_right_rec(r, check, x);\n    t->r = a;\n \
    \   pull(t);\n    return {t, b};\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  - ds/weight_balanced_tree/wbt_base.hpp
  isVerificationFile: false
  path: ds/weight_balanced_tree/wbt_monoid.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/weight_balanced_tree/wbt_monoid.hpp
layout: document
redirect_from:
- /library/ds/weight_balanced_tree/wbt_monoid.hpp
- /library/ds/weight_balanced_tree/wbt_monoid.hpp.html
title: ds/weight_balanced_tree/wbt_monoid.hpp
---
