---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/splay/splaytree_acted_monoid.hpp
    title: ds/splay/splaytree_acted_monoid.hpp
  - icon: ':x:'
    path: ds/splay/splaytree_acted_set.hpp
    title: ds/splay/splaytree_acted_set.hpp
  - icon: ':x:'
    path: ds/splay/splaytree_commutative_monoid.hpp
    title: ds/splay/splaytree_commutative_monoid.hpp
  - icon: ':question:'
    path: ds/splay/splaytree_monoid.hpp
    title: ds/splay/splaytree_monoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508.test.cpp
    title: test/aoj/1508.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
  - icon: ':x:'
    path: test/mytest/cf702_F_splay.test.cpp
    title: test/mytest/cf702_F_splay.test.cpp
  - icon: ':x:'
    path: test/mytest/splay.test.cpp
    title: test/mytest/splay.test.cpp
  - icon: ':x:'
    path: test/mytest/splay_am.test.cpp
    title: test/mytest/splay_am.test.cpp
  - icon: ':x:'
    path: test/mytest/splay_cm.test.cpp
    title: test/mytest/splay_cm.test.cpp
  - icon: ':x:'
    path: test/mytest/splay_monoid.test.cpp
    title: test/mytest/splay_monoid.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1441.test.cpp
    title: test/yukicoder/1441.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/splay/splaytree.hpp\"\n// Node \u578B\u3092\u5225\u306B\
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
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    splay_kth(r_root, 0); // splay \u3057\u305F\u306E\u3067 prop \u6E08\
    \n    r_root->l = l_root;\n    l_root->p = r_root;\n    r_root->update();\n  \
    \  return r_root;\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n    if (k == (root->size))\
    \ return {root, nullptr};\n    if (k == 0) return {nullptr, root};\n    splay_kth(root,\
    \ k - 1);\n    np right = root->r;\n    root->r = nullptr, right->p = nullptr;\n\
    \    root->update();\n    return {root, right};\n  }\n  tuple<np, np, np> split3(np\
    \ root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n\
    \    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np,\
    \ np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root,\
    \ d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a,\
    \ b, c, d};\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\
    \u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\
    \u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\
    \u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay\
    \ \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np\
    \ &root, u32 l, u32 r) {\n    if (l == 0 && r == root->size) return;\n    if (l\
    \ == 0) {\n      splay_kth(root, r);\n      root = root->l;\n      return;\n \
    \   }\n    if (r == root->size) {\n      splay_kth(root, l - 1);\n      root =\
    \ root->r;\n      return;\n    }\n    splay_kth(root, r);\n    np rp = root;\n\
    \    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root, l - 1);\n    root->p\
    \ = rp;\n    rp->l = root;\n    rp->update();\n    root = root->r;\n  }\n\n  vc<X>\
    \ get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np\
    \ root) -> void {\n      if (!root) return;\n      root->prop();\n      dfs(dfs,\
    \ root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n  \
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    splay_kth(root,\
    \ k);\n    return root->get();\n  }\n\n  void set(np &root, u32 k, const X &x)\
    \ {\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np &root,\
    \ u32 k, const X &x) {\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\
    \n  X prod(np &root, u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root);\n  \
    \  return res;\n  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n  \
    \  assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root);\n  }\n  void apply(np &root, const A &a)\
    \ {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np &root,\
    \ u32 l, u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root);\n  }\n  void reverse(np &root)\
    \ {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node *n)\
    \ {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update \u306F\
    \ rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n    p =\
    \ n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r = p;\n\
    \      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n      p->r =\
    \ c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r\
    \ = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  void splay(Node\
    \ *me) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\
    \u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\
    \u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\
    \u4E86\u6642\u70B9\u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    me->prop();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      u32 sl = (root->l ? root->l->size : 0);\n      if (k == sl) break;\n  \
    \    root->prop();\n      if (k < sl)\n        root = root->l;\n      else {\n\
    \        k -= sl + 1;\n        root = root->r;\n      }\n    }\n    splay(root);\n\
    \  }\n\n  // \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\
    \u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right(np root, F check) {\n    if (!root) return {nullptr, nullptr};\n\
    \    np c = find_max_right(root, check);\n    if (!c) {\n      splay(root);\n\
    \      return {nullptr, root};\n    }\n    splay(c);\n    np right = c->r;\n \
    \   if (!right) return {c, nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n\
    \    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\u5074\u306E\u30CE\
    \u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right_prod(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right_prod(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last);\n \
    \   return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_prod(np\
    \ root, const F &check) {\n    using Mono = typename Node::Monoid_X;\n    X prod\
    \ = Mono::unit();\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\
    \u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok =\
    \ nullptr, last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      X lprod = prod;\n      if (root->l) lprod = Mono::op(lprod, root->l->prod);\n\
    \      lprod = Mono::op(lprod, root->x);\n      if (check(lprod)) {\n        prod\
    \ = lprod;\n        last_ok = root;\n        root = root->r;\n      } else {\n\
    \        root = root->l;\n      }\n    }\n    splay(last);\n    return last_ok;\n\
    \  }\n};\n"
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
    \    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  u32 get_size(np root) { return\
    \ (root ? root->size : 0); }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root)\
    \ return r_root;\n    if (!r_root) return l_root;\n    splay_kth(r_root, 0); //\
    \ splay \u3057\u305F\u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n    l_root->p\
    \ = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np merge3(np a,\
    \ np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np c,\
    \ np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np\
    \ root, u32 k) {\n    if (k == (root->size)) return {root, nullptr};\n    if (k\
    \ == 0) return {nullptr, root};\n    splay_kth(root, k - 1);\n    np right = root->r;\n\
    \    root->r = nullptr, right->p = nullptr;\n    root->update();\n    return {root,\
    \ right};\n  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm,\
    \ nr;\n    tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n\
    \    return {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32\
    \ i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto\
    \ [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  // \u90E8\
    \u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\u5FDC\u3059\u308B\u3088\u3046\
    \u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\u8FD4\u3059\n  // \u305D\u306E\
    \u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\u308F\u3051\u3067\u306F\u306A\
    \u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u53C2\u7167\
    \u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay \u3057\u3066\u6839\u306B\u6301\
    \u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np &root, u32 l, u32\
    \ r) {\n    if (l == 0 && r == root->size) return;\n    if (l == 0) {\n      splay_kth(root,\
    \ r);\n      root = root->l;\n      return;\n    }\n    if (r == root->size) {\n\
    \      splay_kth(root, l - 1);\n      root = root->r;\n      return;\n    }\n\
    \    splay_kth(root, r);\n    np rp = root;\n    root = rp->l;\n    root->p =\
    \ nullptr;\n    splay_kth(root, l - 1);\n    root->p = rp;\n    rp->l = root;\n\
    \    rp->update();\n    root = root->r;\n  }\n\n  vc<X> get_all(const np &root)\
    \ {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np root) -> void {\n      if\
    \ (!root) return;\n      root->prop();\n      dfs(dfs, root->l);\n      res.eb(root->get());\n\
    \      dfs(dfs, root->r);\n    };\n    dfs(dfs, root);\n    return res;\n  }\n\
    \n  X get(np &root, u32 k) {\n    splay_kth(root, k);\n    return root->get();\n\
    \  }\n\n  void set(np &root, u32 k, const X &x) {\n    splay_kth(root, k);\n \
    \   root->set(x);\n  }\n\n  void multiply(np &root, u32 k, const X &x) {\n   \
    \ splay_kth(root, k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l,\
    \ u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    X res = root->prod;\n    splay(root);\n    return res;\n  }\n\n\
    \  void apply(np &root, u32 l, u32 r, const A &a) {\n    assert(0 <= l && l <\
    \ r && r <= root->size);\n    goto_between(root, l, r);\n    root->apply(a);\n\
    \    splay(root);\n  }\n  void apply(np &root, const A &a) {\n    if (!root) return;\n\
    \    root->apply(a);\n  }\n\n  void reverse(np &root, u32 l, u32 r) {\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    root->reverse();\n\
    \    splay(root);\n  }\n  void reverse(np &root) {\n    if (!root) return;\n \
    \   root->reverse();\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\u3002prop, update \u306F rotate \u306E\u5916\u3067\u884C\
    \u3046\u3002\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  void splay(Node *me) {\n    // \u3053\
    \u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\u7956\u5148\uFF08me\
    \ \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\u4E86\u6642\u70B9\
    \u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    me->prop();\n    while\
    \ (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp) {\n    \
    \    rotate(me);\n        p->update();\n        break;\n      }\n      bool same\
    \ = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n      if (same)\
    \ rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n      pp->update(),\
    \ p->update();\n    }\n    // me \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\
    \u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np &root, u32 k) {\n\
    \    assert(0 <= k && k < (root->size));\n    while (1) {\n      u32 sl = (root->l\
    \ ? root->l->size : 0);\n      if (k == sl) break;\n      root->prop();\n    \
    \  if (k < sl)\n        root = root->l;\n      else {\n        k -= sl + 1;\n\
    \        root = root->r;\n      }\n    }\n    splay(root);\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  // \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E\
    \ prod \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n \
    \ template <typename F>\n  pair<np, np> split_max_right_prod(np root, F check)\
    \ {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right_prod(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last);\n \
    \   return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_prod(np\
    \ root, const F &check) {\n    using Mono = typename Node::Monoid_X;\n    X prod\
    \ = Mono::unit();\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\
    \u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok =\
    \ nullptr, last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      X lprod = prod;\n      if (root->l) lprod = Mono::op(lprod, root->l->prod);\n\
    \      lprod = Mono::op(lprod, root->x);\n      if (check(lprod)) {\n        prod\
    \ = lprod;\n        last_ok = root;\n        root = root->r;\n      } else {\n\
    \        root = root->l;\n      }\n    }\n    splay(last);\n    return last_ok;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/splay/splaytree.hpp
  requiredBy:
  - ds/splay/splaytree_acted_set.hpp
  - ds/splay/splaytree_monoid.hpp
  - ds/splay/splaytree_commutative_monoid.hpp
  - ds/splay/splaytree_acted_monoid.hpp
  timestamp: '2022-12-01 12:32:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1441.test.cpp
  - test/mytest/cf702_F_splay.test.cpp
  - test/mytest/splay_monoid.test.cpp
  - test/mytest/splay_cm.test.cpp
  - test/mytest/splay_am.test.cpp
  - test/mytest/splay.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/aoj/1508.test.cpp
documentation_of: ds/splay/splaytree.hpp
layout: document
redirect_from:
- /library/ds/splay/splaytree.hpp
- /library/ds/splay/splaytree.hpp.html
title: ds/splay/splaytree.hpp
---
