---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
    title: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2292.test.cpp
    title: test/3_yukicoder/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/789_2.test.cpp
    title: test/3_yukicoder/789_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(*x);  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u547C\u3073\u51FA\u3057\n  }\n\n  void destroy(np x) {\n  \
    \  if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\
    \n// Q*4logN \u7A0B\u5EA6\u5FC5\u8981? apply \u3067 4logN \u30CE\u30FC\u30C9\u4F5C\
    \u3063\u3066\u3044\u308B\u3068\u601D\u3046\ntemplate <typename ActedMonoid, bool\
    \ PERSISTENT>\nstruct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using\
    \ MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X\
    \ = typename AM::X;\n  using A = typename AM::A;\n  using F = function<X(ll, ll)>;\n\
    \  F default_prod;\n\n  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n\
    \  };\n\n  Node_Pool<Node> pool;\n  const ll L0, R0;\n  using np = Node *;\n\n\
    \  Dynamic_Lazy_SegTree(\n      ll L0, ll R0, F default_prod = [](ll, ll) -> X\
    \ { return MX::unit(); })\n      : default_prod(default_prod), L0(L0), R0(R0)\
    \ {}\n\n  np new_root() { return new_node(L0, R0); }\n\n  np new_node(const X\
    \ x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x, c->lazy\
    \ = MA::unit();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n    assert(l\
    \ < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node() { return\
    \ new_node(L0, R0); }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0 == 0\
    \ && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\n\
    \      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node(x);\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np root, ll l, ll r) {\n    if (l ==\
    \ r || !root) return MX::unit();\n    assert(L0 <= l && l < r && r <= R0);\n \
    \   X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x, MA::unit());\n    return\
    \ x;\n  }\n\n  X prod_all(np root) { return prod(root, L0, R0); }\n\n  np set(np\
    \ root, ll i, const X &x) {\n    assert(root && L0 <= i && i < R0);\n    return\
    \ set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i, const X &x)\
    \ {\n    assert(root && L0 <= i && i < R0);\n    return multiply_rec(root, L0,\
    \ R0, i, x);\n  }\n\n  np apply(np root, ll l, ll r, const A &a) {\n    if (l\
    \ == r) return root;\n    assert(root && L0 <= l && l < r && r <= R0);\n    return\
    \ apply_rec(root, L0, R0, l, r, a);\n  }\n\n  template <typename F>\n  ll max_right(np\
    \ root, F check, ll L) {\n    assert(root && L0 <= L && L <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return max_right_rec(root, check, L0, R0, L, x);\n\
    \  }\n\n  template <typename F>\n  ll min_left(np root, F check, ll R) {\n   \
    \ assert(root && L0 <= R && R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    auto dfs = [&](auto\
    \ &dfs, np c, ll l, ll r, A a) -> void {\n      if (!c) return;\n      if (r -\
    \ l == 1) {\n        f(l, AM::act(c->x, a, 1));\n        return;\n      }\n  \
    \    ll m = (l + r) / 2;\n      a = MA::op(c->lazy, a);\n      dfs(dfs, c->l,\
    \ l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::unit());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    if (root\
    \ == other) return root;\n    root = clone(root);\n    copy_interval_rec(root,\
    \ other, L0, R0, l, r, a);\n    return root;\n  }\n\n private:\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  void push(np c, ll l, ll r) {\n    assert(r - l >= 2);\n    ll m = (l + r)\
    \ / 2;\n    if (c->lazy == MA::unit()) return;\n    c->l = (c->l ? clone(c->l)\
    \ : new_node(l, m));\n    c->l->x = AM::act(c->l->x, c->lazy, m - l);\n    c->l->lazy\
    \ = MA::op(c->l->lazy, c->lazy);\n    c->r = (c->r ? clone(c->r) : new_node(m,\
    \ r));\n    c->r->x = AM::act(c->r->x, c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy,\
    \ c->lazy);\n    c->lazy = MA::unit();\n  }\n\n  void copy_interval_rec(np c,\
    \ np d, ll l, ll r, ll ql, ll qr, A a) {\n    // c[ql,qr) <- apply(d[ql,qr),a)\n\
    \    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n\
    \    chmax(ql, l), chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql &&\
    \ r == qr) {\n      if (d) {\n        c->x = AM::act(d->x, a, r - l), c->lazy\
    \ = MA::op(d->lazy, a);\n        c->l = d->l, c->r = d->r;\n      } else {\n \
    \       c->x = AM::act(default_prod(l, r), a, r - l), c->lazy = a;\n        c->l\
    \ = nullptr, c->r = nullptr;\n      }\n      return;\n    }\n    // push\n   \
    \ ll m = (l + r) / 2;\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r\
    \ = (c->r ? clone(c->r) : new_node());\n    c->l->x = AM::act(c->l->x, c->lazy,\
    \ m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r->x = AM::act(c->r->x,\
    \ c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy\
    \ = MA::unit();\n    if (d) a = MA::op(d->lazy, a);\n    copy_interval_rec(c->l,\
    \ (d && d->l ? d->l : nullptr), l, m, ql, qr, a);\n    copy_interval_rec(c->r,\
    \ (d && d->r ? d->r : nullptr), m, r, ql, qr, a);\n    c->x = MX::op(c->l->x,\
    \ c->r->x);\n    return;\n  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r == l + 1) {\n      c = clone(c);\n      c->x = x;\n      c->lazy\
    \ = MA::unit();\n      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r)\
    \ / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m,\
    \ r);\n\n    c = clone(c);\n    if (i < m) {\n      c->l = set_rec(c->l, l, m,\
    \ i, x);\n    } else {\n      c->r = set_rec(c->r, m, r, i, x);\n    }\n    c->x\
    \ = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  np multiply_rec(np c, ll\
    \ l, ll r, ll i, const X &x) {\n    if (r == l + 1) {\n      c = clone(c);\n \
    \     c->x = MX::op(c->x, x);\n      c->lazy = MA::unit();\n      return c;\n\
    \    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = clone(c);\n    if (i <\
    \ m) {\n      c->l = multiply_rec(c->l, l, m, i, x);\n    } else {\n      c->r\
    \ = multiply_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A\
    \ lazy) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n \
    \   if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql, qr), lazy, qr - ql));\n\
    \      return;\n    }\n    if (l == ql && r == qr) {\n      x = MX::op(x, AM::act(c->x,\
    \ lazy, r - l));\n      return;\n    }\n    ll m = (l + r) / 2;\n    lazy = MA::op(c->lazy,\
    \ lazy);\n    prod_rec(c->l, l, m, ql, qr, x, lazy);\n    prod_rec(c->r, m, r,\
    \ ql, qr, x, lazy);\n  }\n\n  np apply_rec(np c, ll l, ll r, ll ql, ll qr, const\
    \ A &a) {\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr) return c;\n    if (l == ql && r == qr) {\n      c = clone(c);\n\
    \      c->x = AM::act(c->x, a, r - l);\n      c->lazy = MA::op(c->lazy, a);\n\
    \      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    c =\
    \ clone(c);\n    c->l = apply_rec(c->l, l, m, ql, qr, a);\n    c->r = apply_rec(c->r,\
    \ m, r, ql, qr, a);\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\
    \n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x) {\n    if (r <= ql) return r;\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    if (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x,\
    \ c->x);\n      return r;\n    }\n    if (r == l + 1) return l;\n    push(c, l,\
    \ r);\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql,\
    \ x);\n    if (k < m) return k;\n    return max_right_rec(c->r, check, m, r, ql,\
    \ x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const F &check,\
    \ ll l, ll r, ll qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l,\
    \ r);\n    chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n     \
    \ x = MX::op(c->x, x);\n      return l;\n    }\n    if (r == l + 1) return r;\n\
    \    push(c, l, r);\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check,\
    \ m, r, qr, x);\n    if (m < k) return k;\n    return min_left_rec(c->l, check,\
    \ l, m, qr, x);\n  }\n};\n"
  code: "#pragma once\n#include \"ds/node_pool.hpp\"\n\n// Q*4logN \u7A0B\u5EA6\u5FC5\
    \u8981? apply \u3067 4logN \u30CE\u30FC\u30C9\u4F5C\u3063\u3066\u3044\u308B\u3068\
    \u601D\u3046\ntemplate <typename ActedMonoid, bool PERSISTENT>\nstruct Dynamic_Lazy_SegTree\
    \ {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA\
    \ = typename AM::Monoid_A;\n  using X = typename AM::X;\n  using A = typename\
    \ AM::A;\n  using F = function<X(ll, ll)>;\n  F default_prod;\n\n  struct Node\
    \ {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  Node_Pool<Node> pool;\n\
    \  const ll L0, R0;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(\n      ll\
    \ L0, ll R0, F default_prod = [](ll, ll) -> X { return MX::unit(); })\n      :\
    \ default_prod(default_prod), L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(L0,\
    \ R0); }\n\n  np new_node(const X x) {\n    np c = pool.create();\n    c->l =\
    \ c->r = nullptr;\n    c->x = x, c->lazy = MA::unit();\n    return c;\n  }\n\n\
    \  np new_node(ll l, ll r) {\n    assert(l < r);\n    return new_node(default_prod(l,\
    \ r));\n  }\n  np new_node() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    if (l == r || !root) return MX::unit();\n    assert(L0\
    \ <= l && l < r && r <= R0);\n    X x = MX::unit();\n    prod_rec(root, L0, R0,\
    \ l, r, x, MA::unit());\n    return x;\n  }\n\n  X prod_all(np root) { return\
    \ prod(root, L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    return set_rec(root, L0, R0, i, x);\n  }\n\n  np\
    \ multiply(np root, ll i, const X &x) {\n    assert(root && L0 <= i && i < R0);\n\
    \    return multiply_rec(root, L0, R0, i, x);\n  }\n\n  np apply(np root, ll l,\
    \ ll r, const A &a) {\n    if (l == r) return root;\n    assert(root && L0 <=\
    \ l && l < r && r <= R0);\n    return apply_rec(root, L0, R0, l, r, a);\n  }\n\
    \n  template <typename F>\n  ll max_right(np root, F check, ll L) {\n    assert(root\
    \ && L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n    return\
    \ max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename F>\n\
    \  ll min_left(np root, F check, ll R) {\n    assert(root && L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n  template <typename F>\n  void\
    \ enumerate(np root, F f) {\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A\
    \ a) -> void {\n      if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x,\
    \ a, 1));\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n\
    \    dfs(dfs, root, L0, R0, MA::unit());\n  }\n\n  void reset() { pool.reset();\
    \ }\n\n  // root[l:r) \u3092 apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\
    \u305F\u3082\u306E\u3092\u8FD4\u3059\n  np copy_interval(np root, np other, ll\
    \ l, ll r, A a) {\n    if (root == other) return root;\n    root = clone(root);\n\
    \    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return root;\n  }\n\
    \n private:\n  np clone(np c) {\n    if (!c || !PERSISTENT) return c;\n    return\
    \ pool.clone(c);\n  }\n\n  void push(np c, ll l, ll r) {\n    assert(r - l >=\
    \ 2);\n    ll m = (l + r) / 2;\n    if (c->lazy == MA::unit()) return;\n    c->l\
    \ = (c->l ? clone(c->l) : new_node(l, m));\n    c->l->x = AM::act(c->l->x, c->lazy,\
    \ m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r = (c->r ? clone(c->r)\
    \ : new_node(m, r));\n    c->r->x = AM::act(c->r->x, c->lazy, r - m);\n    c->r->lazy\
    \ = MA::op(c->r->lazy, c->lazy);\n    c->lazy = MA::unit();\n  }\n\n  void copy_interval_rec(np\
    \ c, np d, ll l, ll r, ll ql, ll qr, A a) {\n    // c[ql,qr) <- apply(d[ql,qr),a)\n\
    \    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n\
    \    chmax(ql, l), chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql &&\
    \ r == qr) {\n      if (d) {\n        c->x = AM::act(d->x, a, r - l), c->lazy\
    \ = MA::op(d->lazy, a);\n        c->l = d->l, c->r = d->r;\n      } else {\n \
    \       c->x = AM::act(default_prod(l, r), a, r - l), c->lazy = a;\n        c->l\
    \ = nullptr, c->r = nullptr;\n      }\n      return;\n    }\n    // push\n   \
    \ ll m = (l + r) / 2;\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r\
    \ = (c->r ? clone(c->r) : new_node());\n    c->l->x = AM::act(c->l->x, c->lazy,\
    \ m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r->x = AM::act(c->r->x,\
    \ c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy\
    \ = MA::unit();\n    if (d) a = MA::op(d->lazy, a);\n    copy_interval_rec(c->l,\
    \ (d && d->l ? d->l : nullptr), l, m, ql, qr, a);\n    copy_interval_rec(c->r,\
    \ (d && d->r ? d->r : nullptr), m, r, ql, qr, a);\n    c->x = MX::op(c->l->x,\
    \ c->r->x);\n    return;\n  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r == l + 1) {\n      c = clone(c);\n      c->x = x;\n      c->lazy\
    \ = MA::unit();\n      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r)\
    \ / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m,\
    \ r);\n\n    c = clone(c);\n    if (i < m) {\n      c->l = set_rec(c->l, l, m,\
    \ i, x);\n    } else {\n      c->r = set_rec(c->r, m, r, i, x);\n    }\n    c->x\
    \ = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  np multiply_rec(np c, ll\
    \ l, ll r, ll i, const X &x) {\n    if (r == l + 1) {\n      c = clone(c);\n \
    \     c->x = MX::op(c->x, x);\n      c->lazy = MA::unit();\n      return c;\n\
    \    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = clone(c);\n    if (i <\
    \ m) {\n      c->l = multiply_rec(c->l, l, m, i, x);\n    } else {\n      c->r\
    \ = multiply_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A\
    \ lazy) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n \
    \   if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql, qr), lazy, qr - ql));\n\
    \      return;\n    }\n    if (l == ql && r == qr) {\n      x = MX::op(x, AM::act(c->x,\
    \ lazy, r - l));\n      return;\n    }\n    ll m = (l + r) / 2;\n    lazy = MA::op(c->lazy,\
    \ lazy);\n    prod_rec(c->l, l, m, ql, qr, x, lazy);\n    prod_rec(c->r, m, r,\
    \ ql, qr, x, lazy);\n  }\n\n  np apply_rec(np c, ll l, ll r, ll ql, ll qr, const\
    \ A &a) {\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr) return c;\n    if (l == ql && r == qr) {\n      c = clone(c);\n\
    \      c->x = AM::act(c->x, a, r - l);\n      c->lazy = MA::op(c->lazy, a);\n\
    \      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    c =\
    \ clone(c);\n    c->l = apply_rec(c->l, l, m, ql, qr, a);\n    c->r = apply_rec(c->r,\
    \ m, r, ql, qr, a);\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\
    \n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x) {\n    if (r <= ql) return r;\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    if (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x,\
    \ c->x);\n      return r;\n    }\n    if (r == l + 1) return l;\n    push(c, l,\
    \ r);\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql,\
    \ x);\n    if (k < m) return k;\n    return max_right_rec(c->r, check, m, r, ql,\
    \ x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const F &check,\
    \ ll l, ll r, ll qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l,\
    \ r);\n    chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n     \
    \ x = MX::op(c->x, x);\n      return l;\n    }\n    if (r == l + 1) return r;\n\
    \    push(c, l, r);\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check,\
    \ m, r, qr, x);\n    if (m < k) return k;\n    return min_left_rec(c->l, check,\
    \ l, m, qr, x);\n  }\n};"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2025-09-16 20:49:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2292.test.cpp
  - test/3_yukicoder/789_2.test.cpp
  - test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/1_mytest/dynamic_lazy_segtree.test.cpp
  - test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
documentation_of: ds/segtree/dynamic_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_lazy_segtree.hpp
- /library/ds/segtree/dynamic_lazy_segtree.hpp.html
title: ds/segtree/dynamic_lazy_segtree.hpp
---
