---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/ARC30D.test.cpp
    title: test/mytest/ARC30D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am.test.cpp
    title: test/mytest/rbst_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am_2.test.cpp
    title: test/mytest/rbst_am_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am_persistent.test.cpp
    title: test/mytest/rbst_am_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/686.test.cpp
    title: test/yukicoder/686.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/randomized_bst/rbst_acted_monoid.hpp\"\ntemplate <typename\
    \ ActedMonoid, bool PERSISTENT, int NODES>\nstruct RBST_ActedMonoid {\n  using\
    \ Monoid_X = typename ActedMonoid::Monoid_X;\n  using Monoid_A = typename ActedMonoid::Monoid_A;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x, prod; // lazy, rev \u53CD\u6620\u6E08\
    \n    A lazy;\n    u32 size;\n    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n\
    \  using np = Node *;\n\n  RBST_ActedMonoid() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  np new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n  \
    \  pool[pid].lazy = Monoid_A::unit();\n    pool[pid].size = 1;\n    pool[pid].rev\
    \ = 0;\n    return &(pool[pid++]);\n  }\n\n  np new_node(const vc<X> &dat) {\n\
    \    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      u32 m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      update(root);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  np copy_node(np &n) {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l\
    \ = n->l, pool[pid].r = n->r;\n    pool[pid].x = n->x;\n    pool[pid].prod = n->prod;\n\
    \    pool[pid].lazy = n->lazy;\n    pool[pid].size = n->size;\n    pool[pid].rev\
    \ = n->rev;\n    return &(pool[pid++]);\n  }\n\n  np merge(np l_root, np r_root)\
    \ { return merge_rec(l_root, r_root); }\n  np merge3(np a, np b, np c) { return\
    \ merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n  \
    \    assert(k == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    return split_rec(root, k);\n  }\n  tuple<np, np,\
    \ np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root,\
    \ r);\n    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n\
    \  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n \
    \   tie(root, d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n\
    \    return {a, b, c, d};\n  }\n\n  X prod(np root, u32 l, u32 r) {\n    if (l\
    \ == r) return Monoid_X::unit();\n    return prod_rec(root, l, r, false);\n  }\n\
    \  X prod(np root) { return (root ? root->prod : Monoid_X::unit()); }\n\n  np\
    \ reverse(np root, u32 l, u32 r) {\n    assert(Monoid_X::commute);\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return root;\n    auto\
    \ [nl, nm, nr] = split3(root, l, r);\n    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n\
    \    return merge3(nl, nm, nr);\n  }\n\n  np apply(np root, u32 l, u32 r, const\
    \ A a) {\n    assert(0 <= l && l <= r && r <= root->size);\n    return apply_rec(root,\
    \ l, r, a);\n  }\n  np apply(np root, const A a) {\n    if (!root) return root;\n\
    \    return apply_rec(root, 0, root->size, a);\n  }\n\n  np set(np root, u32 k,\
    \ const X &x) { return set_rec(root, k, x); }\n  np multiply(np root, u32 k, const\
    \ X &x) { return multiply_rec(root, k, x); }\n  X get(np root, u32 k) { return\
    \ get_rec(root, k, false, Monoid_A::unit()); }\n\n  vc<X> get_all(np root) {\n\
    \    vc<X> res;\n    auto dfs = [&](auto &dfs, np root, bool rev, A lazy) -> void\
    \ {\n      if (!root) return;\n      X me = ActedMonoid::act(root->x, lazy, 1);\n\
    \      lazy = Monoid_A::op(root->lazy, lazy);\n      dfs(dfs, (rev ? root->r :\
    \ root->l), rev ^ root->rev, lazy);\n      res.eb(me);\n      dfs(dfs, (rev ?\
    \ root->l : root->r), rev ^ root->rev, lazy);\n    };\n    dfs(dfs, root, 0, Monoid_A::unit());\n\
    \    return res;\n  }\n\n  template <typename F>\n  pair<np, np> split_max_right(np\
    \ root, const F check) {\n    assert(check(Monoid_X::unit()));\n    X x = Monoid_X::unit();\n\
    \    return split_max_right_rec(root, check, x);\n  }\n\nprivate:\n  inline u32\
    \ xor128() {\n    static u32 x = 123456789;\n    static u32 y = 362436069;\n \
    \   static u32 z = 521288629;\n    static u32 w = 88675123;\n    u32 t = x ^ (x\
    \ << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    // \u81EA\u8EAB\u3092\u30B3\
    \u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n    // \u5B50\u3092\
    \u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\u8907\u6570\
    \u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\
    \u3002\n    bool bl_lazy = (c->lazy != Monoid_A::unit());\n    bool bl_rev = c->rev;\n\
    \    if (bl_lazy || bl_rev) {\n      c->l = copy_node(c->l);\n      c->r = copy_node(c->r);\n\
    \    }\n    if (c->lazy != Monoid_A::unit()) {\n      if (c->l) {\n        c->l->x\
    \ = ActedMonoid::act(c->l->x, c->lazy, 1);\n        c->l->prod = ActedMonoid::act(c->l->prod,\
    \ c->lazy, c->l->size);\n        c->l->lazy = Monoid_A::op(c->l->lazy, c->lazy);\n\
    \      }\n      if (c->r) {\n        c->r->x = ActedMonoid::act(c->r->x, c->lazy,\
    \ 1);\n        c->r->prod = ActedMonoid::act(c->r->prod, c->lazy, c->r->size);\n\
    \        c->r->lazy = Monoid_A::op(c->r->lazy, c->lazy);\n      }\n      c->lazy\
    \ = Monoid_A::unit();\n    }\n    if (c->rev) {\n      if (c->l) {\n        c->l->rev\
    \ ^= 1;\n        swap(c->l->l, c->l->r);\n      }\n      if (c->r) {\n       \
    \ c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n      }\n      c->rev = 0;\n\
    \    }\n  }\n\n  void update(np c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\u3063\
    \u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\u3060\u3051\u306A\u306E\u3067\
    \u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size = 1;\n    c->prod = c->x;\n\
    \    if (c->l) {\n      c->size += c->l->size;\n      c->prod = Monoid_X::op(c->l->prod,\
    \ c->prod);\n    }\n    if (c->r) {\n      c->size += c->r->size;\n      c->prod\
    \ = Monoid_X::op(c->prod, c->r->prod);\n    }\n  }\n\n  np merge_rec(np l_root,\
    \ np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n\
    \    u32 sl = l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) <\
    \ sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n      l_root->r\
    \ = merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<np, np>\
    \ split_rec(np root, u32 k) {\n    if (!root) return {nullptr, nullptr};\n   \
    \ prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n\
    \      auto [nl, nr] = split_rec(root->l, k);\n      root = copy_node(root);\n\
    \      root->l = nr;\n      update(root);\n      return {nl, root};\n    }\n \
    \   auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n    root = copy_node(root);\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n  np set_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root = copy_node(root);\n\
    \      root->l = set_rec(root->l, k, x);\n      update(root);\n      return root;\n\
    \    }\n    if (k == sl) {\n      root = copy_node(root);\n      root->x = x;\n\
    \      update(root);\n      return root;\n    }\n    root = copy_node(root);\n\
    \    root->r = set_rec(root->r, k - (1 + sl), x);\n    update(root);\n    return\
    \ root;\n  }\n\n  np multiply_rec(np root, u32 k, const X &x) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = multiply_rec(root->l,\
    \ k, x);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->x = Monoid_X::op(root->x, x);\n  \
    \    update(root);\n      return root;\n    }\n    root = copy_node(root);\n \
    \   root->r = multiply_rec(root->r, k - (1 + sl), x);\n    update(root);\n   \
    \ return root;\n  }\n\n  X prod_rec(np root, u32 l, u32 r, bool rev) {\n    if\
    \ (l == 0 && r == root->size) { return root->prod; }\n    np left = (rev ? root->r\
    \ : root->l);\n    np right = (rev ? root->l : root->r);\n    u32 sl = (left ?\
    \ left->size : 0);\n    X res = Monoid_X::unit();\n    if (l < sl) {\n      X\
    \ y = prod_rec(left, l, min(r, sl), rev ^ root->rev);\n      res = Monoid_X::op(res,\
    \ ActedMonoid::act(y, root->lazy, min(r, sl) - l));\n    }\n    if (l <= sl &&\
    \ sl < r) res = Monoid_X::op(res, root->x);\n    u32 k = 1 + sl;\n    if (k <\
    \ r) {\n      X y = prod_rec(right, max(k, l) - k, r - k, rev ^ root->rev);\n\
    \      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy, r - max(k, l)));\n\
    \    }\n    return res;\n  }\n\n  X get_rec(np root, u32 k, bool rev, A lazy)\
    \ {\n    np left = (rev ? root->r : root->l);\n    np right = (rev ? root->l :\
    \ root->r);\n    u32 sl = (left ? left->size : 0);\n    if (k == sl) return ActedMonoid::act(root->x,\
    \ lazy, 1);\n    lazy = Monoid_A::op(root->lazy, lazy);\n    rev ^= root->rev;\n\
    \    if (k < sl) return get_rec(left, k, rev, lazy);\n    return get_rec(right,\
    \ k - (1 + sl), rev, lazy);\n  }\n\n  np apply_rec(np root, u32 l, u32 r, const\
    \ A &a) {\n    prop(root);\n    root = copy_node(root);\n    if (l == 0 && r ==\
    \ root->size) {\n      root->x = ActedMonoid::act(root->x, a, 1);\n      root->prod\
    \ = ActedMonoid::act(root->prod, a, root->size);\n      root->lazy = a;\n    \
    \  return root;\n    }\n    u32 sl = (root->l ? root->l->size : 0);\n    if (l\
    \ < sl) root->l = apply_rec(root->l, l, min(r, sl), a);\n    if (l <= sl && sl\
    \ < r) root->x = ActedMonoid::act(root->x, a, 1);\n    u32 k = 1 + sl;\n    if\
    \ (k < r) root->r = apply_rec(root->r, max(k, l) - k, r - k, a);\n    update(root);\n\
    \    return root;\n  }\n\n  template <typename F>\n  pair<np, np> split_max_right_rec(np\
    \ root, F check, X &x) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n\
    \    root = copy_node(root);\n    X y = Monoid_X::op(x, root->prod);\n    if (check(y))\
    \ {\n      x = y;\n      return {root, nullptr};\n    }\n    np left = root->l,\
    \ right = root->r;\n    if (left) {\n      X y = Monoid_X::op(x, root->l->prod);\n\
    \      if (!check(y)) {\n        auto [n1, n2] = split_max_right_rec(left, check,\
    \ x);\n        root->l = n2;\n        update(root);\n        return {n1, root};\n\
    \      }\n      x = y;\n    }\n    y = Monoid_X::op(x, root->x);\n    if (!check(y))\
    \ {\n      root->l = nullptr;\n      update(root);\n      return {left, root};\n\
    \    }\n    x = y;\n    auto [n1, n2] = split_max_right_rec(right, check, x);\n\
    \    root->r = n1;\n    update(root);\n    return {root, n2};\n  }\n};\n"
  code: "template <typename ActedMonoid, bool PERSISTENT, int NODES>\nstruct RBST_ActedMonoid\
    \ {\n  using Monoid_X = typename ActedMonoid::Monoid_X;\n  using Monoid_A = typename\
    \ ActedMonoid::Monoid_A;\n  using X = typename Monoid_X::value_type;\n  using\
    \ A = typename Monoid_A::value_type;\n\n  struct Node {\n    Node *l, *r;\n  \
    \  X x, prod; // lazy, rev \u53CD\u6620\u6E08\n    A lazy;\n    u32 size;\n  \
    \  bool rev;\n  };\n\n  Node *pool;\n  int pid;\n  using np = Node *;\n\n  RBST_ActedMonoid()\
    \ : pid(0) { pool = new Node[NODES]; }\n\n  void reset() { pid = 0; }\n\n  np\
    \ new_node(const X &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].prod = x;\n    pool[pid].lazy = Monoid_A::unit();\n    pool[pid].size\
    \ = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n  }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {\n      if\
    \ (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n \
    \     u32 m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root\
    \ = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n      root->l = l_root,\
    \ root->r = r_root;\n      update(root);\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  np copy_node(np &n) {\n    if (!n || !PERSISTENT)\
    \ return n;\n    pool[pid].l = n->l, pool[pid].r = n->r;\n    pool[pid].x = n->x;\n\
    \    pool[pid].prod = n->prod;\n    pool[pid].lazy = n->lazy;\n    pool[pid].size\
    \ = n->size;\n    pool[pid].rev = n->rev;\n    return &(pool[pid++]);\n  }\n\n\
    \  np merge(np l_root, np r_root) { return merge_rec(l_root, r_root); }\n  np\
    \ merge3(np a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a,\
    \ np b, np c, np d) { return merge(merge(merge(a, b), c), d); }\n  pair<np, np>\
    \ split(np root, u32 k) {\n    if (!root) {\n      assert(k == 0);\n      return\
    \ {nullptr, nullptr};\n    }\n    assert(0 <= k && k <= root->size);\n    return\
    \ split_rec(root, k);\n  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r)\
    \ {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n    tie(root, nm) =\
    \ split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np\
    \ root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n\
    \    auto [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n \
    \ X prod(np root, u32 l, u32 r) {\n    if (l == r) return Monoid_X::unit();\n\
    \    return prod_rec(root, l, r, false);\n  }\n  X prod(np root) { return (root\
    \ ? root->prod : Monoid_X::unit()); }\n\n  np reverse(np root, u32 l, u32 r) {\n\
    \    assert(Monoid_X::commute);\n    assert(0 <= l && l <= r && r <= root->size);\n\
    \    if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n    return merge3(nl, nm, nr);\n\
    \  }\n\n  np apply(np root, u32 l, u32 r, const A a) {\n    assert(0 <= l && l\
    \ <= r && r <= root->size);\n    return apply_rec(root, l, r, a);\n  }\n  np apply(np\
    \ root, const A a) {\n    if (!root) return root;\n    return apply_rec(root,\
    \ 0, root->size, a);\n  }\n\n  np set(np root, u32 k, const X &x) { return set_rec(root,\
    \ k, x); }\n  np multiply(np root, u32 k, const X &x) { return multiply_rec(root,\
    \ k, x); }\n  X get(np root, u32 k) { return get_rec(root, k, false, Monoid_A::unit());\
    \ }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs,\
    \ np root, bool rev, A lazy) -> void {\n      if (!root) return;\n      X me =\
    \ ActedMonoid::act(root->x, lazy, 1);\n      lazy = Monoid_A::op(root->lazy, lazy);\n\
    \      dfs(dfs, (rev ? root->r : root->l), rev ^ root->rev, lazy);\n      res.eb(me);\n\
    \      dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev, lazy);\n    };\n \
    \   dfs(dfs, root, 0, Monoid_A::unit());\n    return res;\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right(np root, const F check) {\n    assert(check(Monoid_X::unit()));\n\
    \    X x = Monoid_X::unit();\n    return split_max_right_rec(root, check, x);\n\
    \  }\n\nprivate:\n  inline u32 xor128() {\n    static u32 x = 123456789;\n   \
    \ static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32 w =\
    \ 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n\
    \    // \u81EA\u8EAB\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\
    \u3044\u3002\n    // \u5B50\u3092\u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\u3002\u8907\u6570\u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\
    \u304C\u3042\u308B\u305F\u3081\u3002\n    bool bl_lazy = (c->lazy != Monoid_A::unit());\n\
    \    bool bl_rev = c->rev;\n    if (bl_lazy || bl_rev) {\n      c->l = copy_node(c->l);\n\
    \      c->r = copy_node(c->r);\n    }\n    if (c->lazy != Monoid_A::unit()) {\n\
    \      if (c->l) {\n        c->l->x = ActedMonoid::act(c->l->x, c->lazy, 1);\n\
    \        c->l->prod = ActedMonoid::act(c->l->prod, c->lazy, c->l->size);\n   \
    \     c->l->lazy = Monoid_A::op(c->l->lazy, c->lazy);\n      }\n      if (c->r)\
    \ {\n        c->r->x = ActedMonoid::act(c->r->x, c->lazy, 1);\n        c->r->prod\
    \ = ActedMonoid::act(c->r->prod, c->lazy, c->r->size);\n        c->r->lazy = Monoid_A::op(c->r->lazy,\
    \ c->lazy);\n      }\n      c->lazy = Monoid_A::unit();\n    }\n    if (c->rev)\
    \ {\n      if (c->l) {\n        c->l->rev ^= 1;\n        swap(c->l->l, c->l->r);\n\
    \      }\n      if (c->r) {\n        c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n\
    \      }\n      c->rev = 0;\n    }\n  }\n\n  void update(np c) {\n    // \u30C7\
    \u30FC\u30BF\u3092\u4FDD\u3063\u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\
    \u3060\u3051\u306A\u306E\u3067\u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size\
    \ = 1;\n    c->prod = c->x;\n    if (c->l) {\n      c->size += c->l->size;\n \
    \     c->prod = Monoid_X::op(c->l->prod, c->prod);\n    }\n    if (c->r) {\n \
    \     c->size += c->r->size;\n      c->prod = Monoid_X::op(c->prod, c->r->prod);\n\
    \    }\n  }\n\n  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return\
    \ r_root;\n    if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n\
    \    r_root->l = merge_rec(l_root, r_root->l);\n    update(r_root);\n    return\
    \ r_root;\n  }\n\n  pair<np, np> split_rec(np root, u32 k) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k <= sl) {\n      auto [nl, nr] = split_rec(root->l, k);\n  \
    \    root = copy_node(root);\n      root->l = nr;\n      update(root);\n     \
    \ return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root = copy_node(root);\n    root->r = nl;\n    update(root);\n    return\
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const X &x) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, x);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->x = x;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), x);\n    update(root);\n    return root;\n  }\n\n  np multiply_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root = copy_node(root);\n\
    \      root->l = multiply_rec(root->l, k, x);\n      update(root);\n      return\
    \ root;\n    }\n    if (k == sl) {\n      root = copy_node(root);\n      root->x\
    \ = Monoid_X::op(root->x, x);\n      update(root);\n      return root;\n    }\n\
    \    root = copy_node(root);\n    root->r = multiply_rec(root->r, k - (1 + sl),\
    \ x);\n    update(root);\n    return root;\n  }\n\n  X prod_rec(np root, u32 l,\
    \ u32 r, bool rev) {\n    if (l == 0 && r == root->size) { return root->prod;\
    \ }\n    np left = (rev ? root->r : root->l);\n    np right = (rev ? root->l :\
    \ root->r);\n    u32 sl = (left ? left->size : 0);\n    X res = Monoid_X::unit();\n\
    \    if (l < sl) {\n      X y = prod_rec(left, l, min(r, sl), rev ^ root->rev);\n\
    \      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy, min(r, sl) - l));\n\
    \    }\n    if (l <= sl && sl < r) res = Monoid_X::op(res, root->x);\n    u32\
    \ k = 1 + sl;\n    if (k < r) {\n      X y = prod_rec(right, max(k, l) - k, r\
    \ - k, rev ^ root->rev);\n      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy,\
    \ r - max(k, l)));\n    }\n    return res;\n  }\n\n  X get_rec(np root, u32 k,\
    \ bool rev, A lazy) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return ActedMonoid::act(root->x, lazy, 1);\n    lazy = Monoid_A::op(root->lazy,\
    \ lazy);\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left, k, rev,\
    \ lazy);\n    return get_rec(right, k - (1 + sl), rev, lazy);\n  }\n\n  np apply_rec(np\
    \ root, u32 l, u32 r, const A &a) {\n    prop(root);\n    root = copy_node(root);\n\
    \    if (l == 0 && r == root->size) {\n      root->x = ActedMonoid::act(root->x,\
    \ a, 1);\n      root->prod = ActedMonoid::act(root->prod, a, root->size);\n  \
    \    root->lazy = a;\n      return root;\n    }\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (l < sl) root->l = apply_rec(root->l, l, min(r, sl), a);\n   \
    \ if (l <= sl && sl < r) root->x = ActedMonoid::act(root->x, a, 1);\n    u32 k\
    \ = 1 + sl;\n    if (k < r) root->r = apply_rec(root->r, max(k, l) - k, r - k,\
    \ a);\n    update(root);\n    return root;\n  }\n\n  template <typename F>\n \
    \ pair<np, np> split_max_right_rec(np root, F check, X &x) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n    X y =\
    \ Monoid_X::op(x, root->prod);\n    if (check(y)) {\n      x = y;\n      return\
    \ {root, nullptr};\n    }\n    np left = root->l, right = root->r;\n    if (left)\
    \ {\n      X y = Monoid_X::op(x, root->l->prod);\n      if (!check(y)) {\n   \
    \     auto [n1, n2] = split_max_right_rec(left, check, x);\n        root->l =\
    \ n2;\n        update(root);\n        return {n1, root};\n      }\n      x = y;\n\
    \    }\n    y = Monoid_X::op(x, root->x);\n    if (!check(y)) {\n      root->l\
    \ = nullptr;\n      update(root);\n      return {left, root};\n    }\n    x =\
    \ y;\n    auto [n1, n2] = split_max_right_rec(right, check, x);\n    root->r =\
    \ n1;\n    update(root);\n    return {root, n2};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/randomized_bst/rbst_acted_monoid.hpp
  requiredBy: []
  timestamp: '2022-12-04 13:46:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/rbst_am.test.cpp
  - test/mytest/ARC30D.test.cpp
  - test/mytest/rbst_am_persistent.test.cpp
  - test/mytest/rbst_am_2.test.cpp
  - test/yukicoder/686.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: ds/randomized_bst/rbst_acted_monoid.hpp
layout: document
redirect_from:
- /library/ds/randomized_bst/rbst_acted_monoid.hpp
- /library/ds/randomized_bst/rbst_acted_monoid.hpp.html
title: ds/randomized_bst/rbst_acted_monoid.hpp
---
