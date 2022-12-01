---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/bbst/splaytree_acted_monoid.hpp
    title: ds/bbst/splaytree_acted_monoid.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/splay_am.test.cpp
    title: test/mytest/splay_am.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/bbst/splaytree.hpp\"\n// Node \u578B\u3092\u5225\u306B\
    \u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename Node, int NODES = 1'000'000>\n\
    struct SplayTree {\n  Node *pool;\n  int pid;\n  using np = Node *;\n  using X\
    \ = typename Node::value_type;\n  using A = typename Node::operator_type;\n\n\
    \  SplayTree() : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid =\
    \ 0; }\n\n  np new_node(const X &x) {\n    np n = &(pool[pid++]);\n    Node::new_node(n,\
    \ x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs =\
    \ [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n  \
    \    if (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n  \
    \    np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n    \
    \  np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n  \
    \    if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n    \
    \  root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root) return r_root;\n\
    \    if (!r_root) return l_root;\n    splay_kth(r_root, 0); // splay \u3057\u305F\
    \u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n    l_root->p = r_root;\n \
    \   r_root->update();\n    return r_root;\n  }\n  np merge3(np a, np b, np c)\
    \ { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return\
    \ merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n\
    \    if (k == (root->size)) return {root, nullptr};\n    if (k == 0) return {nullptr,\
    \ root};\n    splay_kth(root, k - 1);\n    np right = root->r;\n    root->r =\
    \ nullptr, right->p = nullptr;\n    root->update();\n    return {root, right};\n\
    \  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n  \
    \  tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32 i, u32 j,\
    \ u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto [a, b, c]\
    \ = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  vc<X> get_all(const\
    \ np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np root) -> void\
    \ {\n      if (!root) return;\n      root->prop();\n      dfs(dfs, root->l);\n\
    \      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n    dfs(dfs, root);\n\
    \    return res;\n  }\n\n  X get(np &root, u32 k) {\n    splay_kth(root, k);\n\
    \    return root->get();\n  }\n\n  void set(np &root, u32 k, const X &x) {\n \
    \   splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np &root, u32\
    \ k, const X &x) {\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\n \
    \ X prod(np &root, u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    auto [c1, c2, c3] = split3(root, l, r);\n    X res = c2->prod;\n    root\
    \ = merge3(c1, c2, c3);\n    return res;\n  }\n\n  void apply(np &root, u32 l,\
    \ u32 r, const A &a) {\n    assert(0 <= l && l < r && r <= root->size);\n    auto\
    \ [c1, c2, c3] = split3(root, l, r);\n    c2->apply(a);\n    root = merge3(c1,\
    \ c2, c3);\n  }\n\n  void reverse(np &root, u32 l, u32 r) {\n    assert(0 <= l\
    \ && l < r && r <= root->size);\n    auto [c1, c2, c3] = split3(root, l, r);\n\
    \    c2->reverse();\n    root = merge3(c1, c2, c3);\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void splay(Node *me) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\
    \u3001\u6839\u304B\u3089 me \u307E\u3067\u306E\u30D1\u30B9\u306F\u65E2\u306B prop\
    \ \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001\
    splay \u7D42\u4E86\u6642\u70B9\u3067\u3082 me \u306F prop \u6E08\u3067\u3042\u308B\
    \u3068\u3057\u3066\u3088\u3044\n    while (me->p) {\n      np p = me->p;\n   \
    \   np pp = p->p;\n      if (!pp) {\n        rotate(me);\n        p->update();\n\
    \        break;\n      }\n      bool same = (p->l == me && pp->l == p) || (p->r\
    \ == me && pp->r == p);\n      if (same) rotate(p), rotate(me);\n      if (!same)\
    \ rotate(me), rotate(me);\n      pp->update(), p->update();\n    }\n    // me\
    \ \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n\
    \  }\n\n  void splay_kth(np &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n\
    \    while (1) {\n      root->prop();\n      u32 sl = (root->l ? root->l->size\
    \ : 0);\n      if (k < sl) root = root->l;\n      elif (k == sl) break;\n    \
    \  else {\n        k -= sl + 1;\n        root = root->r;\n      }\n    }\n   \
    \ splay(root);\n  }\n};\n"
  code: "#pragma once\n// Node \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\
    \u3046\ntemplate <typename Node, int NODES = 1'000'000>\nstruct SplayTree {\n\
    \  Node *pool;\n  int pid;\n  using np = Node *;\n  using X = typename Node::value_type;\n\
    \  using A = typename Node::operator_type;\n\n  SplayTree() : pid(0) { pool =\
    \ new Node[NODES]; }\n\n  void reset() { pid = 0; }\n\n  np new_node(const X &x)\
    \ {\n    np n = &(pool[pid++]);\n    Node::new_node(n, x);\n    return n;\n  }\n\
    \n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int\
    \ r) -> np {\n      if (l == r) return nullptr;\n      if (r == l + 1) return\
    \ new_node(dat[l]);\n      int m = (l + r) / 2;\n      np l_root = dfs(dfs, l,\
    \ m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      if (l_root) l_root->p = root;\n\
    \      if (r_root) r_root->p = root;\n      root->update();\n      return root;\n\
    \    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  np merge(np l_root, np r_root)\
    \ {\n    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n    splay_kth(r_root,\
    \ 0); // splay \u3057\u305F\u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n\
    \    l_root->p = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np\
    \ merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a,\
    \ np b, np c, np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np,\
    \ np> split(np root, u32 k) {\n    if (k == (root->size)) return {root, nullptr};\n\
    \    if (k == 0) return {nullptr, root};\n    splay_kth(root, k - 1);\n    np\
    \ right = root->r;\n    root->r = nullptr, right->p = nullptr;\n    root->update();\n\
    \    return {root, right};\n  }\n  tuple<np, np, np> split3(np root, u32 l, u32\
    \ r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root, nm)\
    \ = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np, np>\
    \ split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root,\
    \ k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\
    \n  vc<X> get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ np root) -> void {\n      if (!root) return;\n      root->prop();\n      dfs(dfs,\
    \ root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n  \
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    splay_kth(root,\
    \ k);\n    return root->get();\n  }\n\n  void set(np &root, u32 k, const X &x)\
    \ {\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np &root,\
    \ u32 k, const X &x) {\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\
    \n  X prod(np &root, u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    auto [c1, c2, c3] = split3(root, l, r);\n    X res = c2->prod;\n    root\
    \ = merge3(c1, c2, c3);\n    return res;\n  }\n\n  void apply(np &root, u32 l,\
    \ u32 r, const A &a) {\n    assert(0 <= l && l < r && r <= root->size);\n    auto\
    \ [c1, c2, c3] = split3(root, l, r);\n    c2->apply(a);\n    root = merge3(c1,\
    \ c2, c3);\n  }\n\n  void reverse(np &root, u32 l, u32 r) {\n    assert(0 <= l\
    \ && l < r && r <= root->size);\n    auto [c1, c2, c3] = split3(root, l, r);\n\
    \    c2->reverse();\n    root = merge3(c1, c2, c3);\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void splay(Node *me) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\
    \u3001\u6839\u304B\u3089 me \u307E\u3067\u306E\u30D1\u30B9\u306F\u65E2\u306B prop\
    \ \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001\
    splay \u7D42\u4E86\u6642\u70B9\u3067\u3082 me \u306F prop \u6E08\u3067\u3042\u308B\
    \u3068\u3057\u3066\u3088\u3044\n    while (me->p) {\n      np p = me->p;\n   \
    \   np pp = p->p;\n      if (!pp) {\n        rotate(me);\n        p->update();\n\
    \        break;\n      }\n      bool same = (p->l == me && pp->l == p) || (p->r\
    \ == me && pp->r == p);\n      if (same) rotate(p), rotate(me);\n      if (!same)\
    \ rotate(me), rotate(me);\n      pp->update(), p->update();\n    }\n    // me\
    \ \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n\
    \  }\n\n  void splay_kth(np &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n\
    \    while (1) {\n      root->prop();\n      u32 sl = (root->l ? root->l->size\
    \ : 0);\n      if (k < sl) root = root->l;\n      elif (k == sl) break;\n    \
    \  else {\n        k -= sl + 1;\n        root = root->r;\n      }\n    }\n   \
    \ splay(root);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/bbst/splaytree.hpp
  requiredBy:
  - ds/bbst/splaytree_acted_monoid.hpp
  timestamp: '2022-12-01 09:04:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/splay_am.test.cpp
documentation_of: ds/bbst/splaytree.hpp
layout: document
redirect_from:
- /library/ds/bbst/splaytree.hpp
- /library/ds/bbst/splaytree.hpp.html
title: ds/bbst/splaytree.hpp
---
