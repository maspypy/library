---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
    title: test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1036.test.cpp
    title: test/3_yukicoder/1036.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1649.test.cpp
    title: test/3_yukicoder/1649.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1826.test.cpp
    title: test/3_yukicoder/1826.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2935.test.cpp
    title: test/3_yukicoder/2935.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/789.test.cpp
    title: test/3_yukicoder/789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/dynamic_segtree.hpp\"\n\n#line 1 \"ds/node_pool.hpp\"\
    \n// \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\
    \u6E08\u307F chunk \u3092\u518D\u5229\u7528\u3059\u308B\ntemplate <class Node>\n\
    struct Node_Pool {\n  union Slot {\n    Node node;\n    Slot* next;\n\n    Slot()\
    \ {}\n    ~Slot() {}\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE\
    \ = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  int chunk_id = 0;\n  int pos\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n\
    \    for (auto& p : chunks) cache.eb(std::move(p));\n  }\n\n  template <class...\
    \ Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n    return\
    \ ::new (&s->node) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np x)\
    \ {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(*x);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    Slot*\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  // \u5168 node \u3092\u7121\u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\
    \u4FDD\u6E08\u307F chunk \u306F\u89E3\u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\
    \u964D\u306B\u518D\u5229\u7528\u3059\u308B\u3002\n  void reset() {\n    free_head\
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/segtree/dynamic_segtree.hpp\"\
    \n\n// sparse \u3082\u3042\u308B\u306E\u3067\u72B6\u6CC1\u306B\u3088\u3063\u3066\
    \u306F\u305D\u3063\u3061\u3067\ntemplate <typename Monoid, bool PERSISTENT>\n\
    struct Dynamic_SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using F = function<X(ll, ll)>;\n  F default_prod;\n\n  struct Node {\n    Node\
    \ *l, *r;\n    X x;\n  };\n\n  const ll L0, R0;\n  Node_Pool<Node> pool;\n  using\
    \ np = Node *;\n\n  Dynamic_SegTree(\n      ll L0, ll R0, F default_prod = [](ll\
    \ l, ll r) -> X { return MX::id(); })\n      : default_prod(default_prod), L0(L0),\
    \ R0(R0) {}\n\n  np new_root() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ X x) {\n    np n = pool.create();\n    n->l = nullptr, n->r = nullptr, n->x\
    \ = x;\n    return n;\n  }\n\n  np new_node(ll l, ll r) { return new_node(default_prod(l,\
    \ r)); }\n  np new_node() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> np {\n      if (l == r) return nullptr;\n      if (r ==\
    \ l + 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    assert(L0 <= l && l <= r && r <= R0);\n    if (!root\
    \ || l == r) return MX::id();\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x);\n    return x;\n  }\n\n  np set(np root, ll i, const X &x) {\n   \
    \ assert(root && L0 <= i && i < R0);\n    root = (root ? copy_node(root) : new_node());\n\
    \    set_rec(root, L0, R0, i, x);\n    return root;\n  }\n\n  np multiply(np root,\
    \ ll i, const X &x) {\n    assert(root && L0 <= i && i < R0);\n    root = (root\
    \ ? copy_node(root) : new_node());\n    multiply_rec(root, L0, R0, i, x);\n  \
    \  return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(root && L0 <= L && L <= R0 && check(MX::id()));\n    X x\
    \ = MX::id();\n    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n \
    \ template <typename F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0\
    \ <= R && R <= R0 && check(MX::id()));\n    X x = MX::id();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  // (idx, val)\n  template <typename F>\n  void\
    \ enumerate(np root, F f) {\n    if (!root) return;\n    auto dfs = [&](auto &dfs,\
    \ np c, ll l, ll r) -> void {\n      if (!c) return;\n      if (r - l == 1) {\n\
    \        f(l, c->x);\n        return;\n      }\n      ll m = (l + r) / 2;\n  \
    \    dfs(dfs, c->l, l, m);\n      dfs(dfs, c->r, m, r);\n    };\n    dfs(dfs,\
    \ root, L0, R0);\n    return;\n  }\n\n  void reset() { pool.reset(); }\n\n private:\n\
    \  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    np n = pool.create();\n\
    \    n->l = c->l, n->r = c->r, n->x = c->x;\n    return n;\n  }\n\n  void set_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    assert(c);\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    if (r == l + 1) {\n      c->x\
    \ = x;\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (l <= i && i < m)\
    \ {\n      c->l = (c->l ? copy_node(c->l) : new_node());\n      set_rec(c->l,\
    \ l, m, i, x);\n    }\n    if (m <= i && i < r) {\n      c->r = (c->r ? copy_node(c->r)\
    \ : new_node());\n      set_rec(c->r, m, r, i, x);\n    }\n    X xl = (c->l ?\
    \ c->l->x : default_prod(l, m));\n    X xr = (c->r ? c->r->x : default_prod(m,\
    \ r));\n    c->x = MX::op(xl, xr);\n    return;\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    assert(c);\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    if (r == l + 1) {\n      c->x\
    \ = MX::op(c->x, x);\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (l\
    \ <= i && i < m) {\n      c->l = (c->l ? copy_node(c->l) : new_node());\n    \
    \  multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i && i < r) {\n      c->r\
    \ = (c->r ? copy_node(c->r) : new_node());\n      multiply_rec(c->r, m, r, i,\
    \ x);\n    }\n    X xl = (c->l ? c->l->x : default_prod(l, m));\n    X xr = (c->r\
    \ ? c->r->x : default_prod(m, r));\n    c->x = MX::op(xl, xr);\n    return;\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql,\
    \ l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n    if (!c) {\n      x =\
    \ MX::op(x, default_prod(ql, qr));\n      return;\n    }\n    if (l == ql && r\
    \ == qr) {\n      x = MX::op(x, c->x);\n      return;\n    }\n    ll m = (l +\
    \ r) / 2;\n    prod_rec(c->l, l, m, ql, qr, x);\n    prod_rec(c->r, m, r, ql,\
    \ qr, x);\n  }\n\n  // \u3053\u308C new node \u4F5C\u3063\u3066\u308B\u306E\u306F\
    \u3055\u307C\u308A\n  template <typename F>\n  ll max_right_rec(np c, const F\
    \ &check, ll l, ll r, ll ql, X &x) {\n    if (r <= ql) return R0;\n    if (ql\
    \ <= l && check(MX::op(x, c->x))) {\n      x = MX::op(x, c->x);\n      return\
    \ R0;\n    }\n    if (r == l + 1) return l;\n    ll m = (l + r) / 2;\n    if (!c->l)\
    \ c->l = new_node(l, m);\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n\
    \    if (k != R0) return k;\n    if (!c->r) c->r = new_node(m, r);\n    return\
    \ max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n  // \u3053\u308C new node\
    \ \u4F5C\u3063\u3066\u308B\u306E\u306F\u3055\u307C\u308A\n  template <typename\
    \ F>\n  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {\n   \
    \ if (qr <= l) return L0;\n    if (r <= qr && check(MX::op(c->x, x))) {\n    \
    \  x = MX::op(x, c->x);\n      return L0;\n    }\n    if (r == l + 1) return r;\n\
    \    ll m = (l + r) / 2;\n    if (!c->r) c->r = new_node(m, r);\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    return min_left_rec(c->l, check, l, m, qr, x);\n  }\n};\n"
  code: "\n#include \"ds/node_pool.hpp\"\n\n// sparse \u3082\u3042\u308B\u306E\u3067\
    \u72B6\u6CC1\u306B\u3088\u3063\u3066\u306F\u305D\u3063\u3061\u3067\ntemplate <typename\
    \ Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree {\n  using MX = Monoid;\n \
    \ using X = typename MX::value_type;\n  using F = function<X(ll, ll)>;\n  F default_prod;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x;\n  };\n\n  const ll L0, R0;\n  Node_Pool<Node>\
    \ pool;\n  using np = Node *;\n\n  Dynamic_SegTree(\n      ll L0, ll R0, F default_prod\
    \ = [](ll l, ll r) -> X { return MX::id(); })\n      : default_prod(default_prod),\
    \ L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ X x) {\n    np n = pool.create();\n    n->l = nullptr, n->r = nullptr, n->x\
    \ = x;\n    return n;\n  }\n\n  np new_node(ll l, ll r) { return new_node(default_prod(l,\
    \ r)); }\n  np new_node() { return new_node(L0, R0); }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto\
    \ &dfs, ll l, ll r) -> np {\n      if (l == r) return nullptr;\n      if (r ==\
    \ l + 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    assert(L0 <= l && l <= r && r <= R0);\n    if (!root\
    \ || l == r) return MX::id();\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x);\n    return x;\n  }\n\n  np set(np root, ll i, const X &x) {\n   \
    \ assert(root && L0 <= i && i < R0);\n    root = (root ? copy_node(root) : new_node());\n\
    \    set_rec(root, L0, R0, i, x);\n    return root;\n  }\n\n  np multiply(np root,\
    \ ll i, const X &x) {\n    assert(root && L0 <= i && i < R0);\n    root = (root\
    \ ? copy_node(root) : new_node());\n    multiply_rec(root, L0, R0, i, x);\n  \
    \  return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(root && L0 <= L && L <= R0 && check(MX::id()));\n    X x\
    \ = MX::id();\n    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n \
    \ template <typename F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0\
    \ <= R && R <= R0 && check(MX::id()));\n    X x = MX::id();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  // (idx, val)\n  template <typename F>\n  void\
    \ enumerate(np root, F f) {\n    if (!root) return;\n    auto dfs = [&](auto &dfs,\
    \ np c, ll l, ll r) -> void {\n      if (!c) return;\n      if (r - l == 1) {\n\
    \        f(l, c->x);\n        return;\n      }\n      ll m = (l + r) / 2;\n  \
    \    dfs(dfs, c->l, l, m);\n      dfs(dfs, c->r, m, r);\n    };\n    dfs(dfs,\
    \ root, L0, R0);\n    return;\n  }\n\n  void reset() { pool.reset(); }\n\n private:\n\
    \  np copy_node(np c) {\n    if (!c || !PERSISTENT) return c;\n    np n = pool.create();\n\
    \    n->l = c->l, n->r = c->r, n->x = c->x;\n    return n;\n  }\n\n  void set_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    assert(c);\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    if (r == l + 1) {\n      c->x\
    \ = x;\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (l <= i && i < m)\
    \ {\n      c->l = (c->l ? copy_node(c->l) : new_node());\n      set_rec(c->l,\
    \ l, m, i, x);\n    }\n    if (m <= i && i < r) {\n      c->r = (c->r ? copy_node(c->r)\
    \ : new_node());\n      set_rec(c->r, m, r, i, x);\n    }\n    X xl = (c->l ?\
    \ c->l->x : default_prod(l, m));\n    X xr = (c->r ? c->r->x : default_prod(m,\
    \ r));\n    c->x = MX::op(xl, xr);\n    return;\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    assert(c);\n    // \u3082\u3046 c \u306F\
    \u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    if (r == l + 1) {\n      c->x\
    \ = MX::op(c->x, x);\n      return;\n    }\n    ll m = (l + r) / 2;\n    if (l\
    \ <= i && i < m) {\n      c->l = (c->l ? copy_node(c->l) : new_node());\n    \
    \  multiply_rec(c->l, l, m, i, x);\n    }\n    if (m <= i && i < r) {\n      c->r\
    \ = (c->r ? copy_node(c->r) : new_node());\n      multiply_rec(c->r, m, r, i,\
    \ x);\n    }\n    X xl = (c->l ? c->l->x : default_prod(l, m));\n    X xr = (c->r\
    \ ? c->r->x : default_prod(m, r));\n    c->x = MX::op(xl, xr);\n    return;\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\n    chmax(ql,\
    \ l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n    if (!c) {\n      x =\
    \ MX::op(x, default_prod(ql, qr));\n      return;\n    }\n    if (l == ql && r\
    \ == qr) {\n      x = MX::op(x, c->x);\n      return;\n    }\n    ll m = (l +\
    \ r) / 2;\n    prod_rec(c->l, l, m, ql, qr, x);\n    prod_rec(c->r, m, r, ql,\
    \ qr, x);\n  }\n\n  // \u3053\u308C new node \u4F5C\u3063\u3066\u308B\u306E\u306F\
    \u3055\u307C\u308A\n  template <typename F>\n  ll max_right_rec(np c, const F\
    \ &check, ll l, ll r, ll ql, X &x) {\n    if (r <= ql) return R0;\n    if (ql\
    \ <= l && check(MX::op(x, c->x))) {\n      x = MX::op(x, c->x);\n      return\
    \ R0;\n    }\n    if (r == l + 1) return l;\n    ll m = (l + r) / 2;\n    if (!c->l)\
    \ c->l = new_node(l, m);\n    ll k = max_right_rec(c->l, check, l, m, ql, x);\n\
    \    if (k != R0) return k;\n    if (!c->r) c->r = new_node(m, r);\n    return\
    \ max_right_rec(c->r, check, m, r, ql, x);\n  }\n\n  // \u3053\u308C new node\
    \ \u4F5C\u3063\u3066\u308B\u306E\u306F\u3055\u307C\u308A\n  template <typename\
    \ F>\n  ll min_left_rec(np c, const F &check, ll l, ll r, ll qr, X &x) {\n   \
    \ if (qr <= l) return L0;\n    if (r <= qr && check(MX::op(c->x, x))) {\n    \
    \  x = MX::op(x, c->x);\n      return L0;\n    }\n    if (r == l + 1) return r;\n\
    \    ll m = (l + r) / 2;\n    if (!c->r) c->r = new_node(m, r);\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    return min_left_rec(c->l, check, l, m, qr, x);\n  }\n};"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_segtree.hpp
  requiredBy: []
  timestamp: '2026-08-31 12:03:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
  - test/2_library_checker/data_structure/point_set_range_composite_dynamic.test.cpp
  - test/3_yukicoder/1826.test.cpp
  - test/3_yukicoder/1036.test.cpp
  - test/3_yukicoder/2935.test.cpp
  - test/3_yukicoder/1649.test.cpp
  - test/3_yukicoder/789.test.cpp
documentation_of: ds/segtree/dynamic_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_segtree.hpp
- /library/ds/segtree/dynamic_segtree.hpp.html
title: ds/segtree/dynamic_segtree.hpp
---
