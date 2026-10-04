---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/weight_balanced_tree/wbt_acted_monoid.hpp
    title: ds/weight_balanced_tree/wbt_acted_monoid.hpp
  - icon: ':warning:'
    path: ds/weight_balanced_tree/wbt_basic.hpp
    title: ds/weight_balanced_tree/wbt_basic.hpp
  - icon: ':warning:'
    path: ds/weight_balanced_tree/wbt_monoid.hpp
    title: ds/weight_balanced_tree/wbt_monoid.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/weight_balanced_tree/wbt_base.hpp\"\n\n// Adams' weight\
    \ balanced trees (JFP 1993), with weight(t)=size(t)+1,\n// DELTA=3 and RATIO=2.\
    \  All rebalancing is done by join(L,x,R).\ntemplate <class Derived, class Node,\
    \ bool PERSISTENT>\nstruct WBT_Sequence_Base {\n  using np = Node*;\n  static\
    \ constexpr u32 DELTA = 3, RATIO = 2;\n\n protected:\n  Derived& self() { return\
    \ static_cast<Derived&>(*this); }\n  u32 sz(np t) const { return t ? t->size :\
    \ 0; }\n  u64 wt(np t) const { return u64(sz(t)) + 1; }\n\n  np join(np l, np\
    \ x, np r) {\n    assert(x && !x->l && !x->r);\n    if (u64(DELTA) * wt(l) < wt(r))\
    \ {\n      r = self().clone(r);\n      self().push(r);\n      r->l = join(l, x,\
    \ r->l);\n      self().pull(r);\n      return balance(r);\n    }\n    if (u64(DELTA)\
    \ * wt(r) < wt(l)) {\n      l = self().clone(l);\n      self().push(l);\n    \
    \  l->r = join(l->r, x, r);\n      self().pull(l);\n      return balance(l);\n\
    \    }\n    x->l = l, x->r = r;\n    self().pull(x);\n    return x;\n  }\n\n \
    \ np balance(np t) {\n    if (u64(DELTA) * wt(t->r) < wt(t->l)) return rotate_right(t);\n\
    \    if (u64(DELTA) * wt(t->l) < wt(t->r)) return rotate_left(t);\n    return\
    \ t;\n  }\n\n  np rotate_right(np t) {\n    np l = self().clone(t->l);\n    self().push(l);\n\
    \    if (wt(l->r) < u64(RATIO) * wt(l->l)) {\n      t->l = l->r;\n      l->r =\
    \ t;\n      self().pull(t), self().pull(l);\n      return l;\n    }\n    np m\
    \ = self().clone(l->r);\n    self().push(m);\n    l->r = m->l, t->l = m->r;\n\
    \    m->l = l, m->r = t;\n    self().pull(l), self().pull(t), self().pull(m);\n\
    \    return m;\n  }\n\n  np rotate_left(np t) {\n    np r = self().clone(t->r);\n\
    \    self().push(r);\n    if (wt(r->l) < u64(RATIO) * wt(r->r)) {\n      t->r\
    \ = r->l;\n      r->l = t;\n      self().pull(t), self().pull(r);\n      return\
    \ r;\n    }\n    np m = self().clone(r->l);\n    self().push(m);\n    r->l = m->r,\
    \ t->r = m->l;\n    m->r = r, m->l = t;\n    self().pull(t), self().pull(r), self().pull(m);\n\
    \    return m;\n  }\n\n  pair<np, np> extract_min(np t) {\n    t = self().clone(t);\n\
    \    self().push(t);\n    if (!t->l) {\n      np rest = t->r;\n      t->r = nullptr;\n\
    \      self().pull(t);\n      return {t, rest};\n    }\n    auto [x, nl] = extract_min(t->l);\n\
    \    np r = t->r;\n    t->l = t->r = nullptr;\n    self().pull(t);\n    return\
    \ {x, join(nl, t, r)};\n  }\n\n public:\n  np merge(np a, np b) {\n    if (!a)\
    \ return b;\n    if (!b) return a;\n    auto [x, b1] = extract_min(b);\n    return\
    \ join(a, x, b1);\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np t, u32 k) {\n    assert(k <= sz(t));\n\
    \    if (!t) return {nullptr, nullptr};\n    t = self().clone(t);\n    self().push(t);\n\
    \    u32 sl = sz(t->l);\n    np l = t->l, r = t->r;\n    t->l = t->r = nullptr;\n\
    \    self().pull(t);\n    if (k <= sl) {\n      auto [a, b] = split(l, k);\n \
    \     return {a, join(b, t, r)};\n    }\n    auto [a, b] = split(r, k - sl - 1);\n\
    \    return {join(l, t, a), b};\n  }\n  tuple<np, np, np> split3(np t, u32 l,\
    \ u32 r) {\n    assert(l <= r && r <= sz(t));\n    auto [a, bc] = split(t, l);\n\
    \    auto [b, c] = split(bc, r - l);\n    return {a, b, c};\n  }\n  tuple<np,\
    \ np, np, np> split4(np t, u32 i, u32 j, u32 k) {\n    auto [a, bcd] = split(t,\
    \ i);\n    auto [b, cd] = split(bcd, j - i);\n    auto [c, d] = split(cd, k -\
    \ j);\n    return {a, b, c, d};\n  }\n};\n"
  code: "#pragma once\n\n// Adams' weight balanced trees (JFP 1993), with weight(t)=size(t)+1,\n\
    // DELTA=3 and RATIO=2.  All rebalancing is done by join(L,x,R).\ntemplate <class\
    \ Derived, class Node, bool PERSISTENT>\nstruct WBT_Sequence_Base {\n  using np\
    \ = Node*;\n  static constexpr u32 DELTA = 3, RATIO = 2;\n\n protected:\n  Derived&\
    \ self() { return static_cast<Derived&>(*this); }\n  u32 sz(np t) const { return\
    \ t ? t->size : 0; }\n  u64 wt(np t) const { return u64(sz(t)) + 1; }\n\n  np\
    \ join(np l, np x, np r) {\n    assert(x && !x->l && !x->r);\n    if (u64(DELTA)\
    \ * wt(l) < wt(r)) {\n      r = self().clone(r);\n      self().push(r);\n    \
    \  r->l = join(l, x, r->l);\n      self().pull(r);\n      return balance(r);\n\
    \    }\n    if (u64(DELTA) * wt(r) < wt(l)) {\n      l = self().clone(l);\n  \
    \    self().push(l);\n      l->r = join(l->r, x, r);\n      self().pull(l);\n\
    \      return balance(l);\n    }\n    x->l = l, x->r = r;\n    self().pull(x);\n\
    \    return x;\n  }\n\n  np balance(np t) {\n    if (u64(DELTA) * wt(t->r) < wt(t->l))\
    \ return rotate_right(t);\n    if (u64(DELTA) * wt(t->l) < wt(t->r)) return rotate_left(t);\n\
    \    return t;\n  }\n\n  np rotate_right(np t) {\n    np l = self().clone(t->l);\n\
    \    self().push(l);\n    if (wt(l->r) < u64(RATIO) * wt(l->l)) {\n      t->l\
    \ = l->r;\n      l->r = t;\n      self().pull(t), self().pull(l);\n      return\
    \ l;\n    }\n    np m = self().clone(l->r);\n    self().push(m);\n    l->r = m->l,\
    \ t->l = m->r;\n    m->l = l, m->r = t;\n    self().pull(l), self().pull(t), self().pull(m);\n\
    \    return m;\n  }\n\n  np rotate_left(np t) {\n    np r = self().clone(t->r);\n\
    \    self().push(r);\n    if (wt(r->l) < u64(RATIO) * wt(r->r)) {\n      t->r\
    \ = r->l;\n      r->l = t;\n      self().pull(t), self().pull(r);\n      return\
    \ r;\n    }\n    np m = self().clone(r->l);\n    self().push(m);\n    r->l = m->r,\
    \ t->r = m->l;\n    m->r = r, m->l = t;\n    self().pull(t), self().pull(r), self().pull(m);\n\
    \    return m;\n  }\n\n  pair<np, np> extract_min(np t) {\n    t = self().clone(t);\n\
    \    self().push(t);\n    if (!t->l) {\n      np rest = t->r;\n      t->r = nullptr;\n\
    \      self().pull(t);\n      return {t, rest};\n    }\n    auto [x, nl] = extract_min(t->l);\n\
    \    np r = t->r;\n    t->l = t->r = nullptr;\n    self().pull(t);\n    return\
    \ {x, join(nl, t, r)};\n  }\n\n public:\n  np merge(np a, np b) {\n    if (!a)\
    \ return b;\n    if (!b) return a;\n    auto [x, b1] = extract_min(b);\n    return\
    \ join(a, x, b1);\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np t, u32 k) {\n    assert(k <= sz(t));\n\
    \    if (!t) return {nullptr, nullptr};\n    t = self().clone(t);\n    self().push(t);\n\
    \    u32 sl = sz(t->l);\n    np l = t->l, r = t->r;\n    t->l = t->r = nullptr;\n\
    \    self().pull(t);\n    if (k <= sl) {\n      auto [a, b] = split(l, k);\n \
    \     return {a, join(b, t, r)};\n    }\n    auto [a, b] = split(r, k - sl - 1);\n\
    \    return {join(l, t, a), b};\n  }\n  tuple<np, np, np> split3(np t, u32 l,\
    \ u32 r) {\n    assert(l <= r && r <= sz(t));\n    auto [a, bc] = split(t, l);\n\
    \    auto [b, c] = split(bc, r - l);\n    return {a, b, c};\n  }\n  tuple<np,\
    \ np, np, np> split4(np t, u32 i, u32 j, u32 k) {\n    auto [a, bcd] = split(t,\
    \ i);\n    auto [b, cd] = split(bcd, j - i);\n    auto [c, d] = split(cd, k -\
    \ j);\n    return {a, b, c, d};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/weight_balanced_tree/wbt_base.hpp
  requiredBy:
  - ds/weight_balanced_tree/wbt_acted_monoid.hpp
  - ds/weight_balanced_tree/wbt_monoid.hpp
  - ds/weight_balanced_tree/wbt_basic.hpp
  timestamp: '2026-10-04 10:39:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/weight_balanced_tree/wbt_base.hpp
layout: document
redirect_from:
- /library/ds/weight_balanced_tree/wbt_base.hpp
- /library/ds/weight_balanced_tree/wbt_base.hpp.html
title: ds/weight_balanced_tree/wbt_base.hpp
---
