---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
    title: test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2292.test.cpp
    title: test/3_yukicoder/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/789_2.test.cpp
    title: test/3_yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp
  bundledCode: "#line 1 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp\n\
    #line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
    // \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\
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
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n  int used() const { return\
    \ chunk_id * CHUNK_SIZE + pos; }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Default_Prod {\n  using\
    \ MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// set, multiply: 2H nodes \u7A0B\u5EA6\
    \n// apply: 4H nodes \u7A0B\u5EA6\ntemplate <typename ActedMonoid, bool PERSISTENT,\n\
    \    typename DefaultProd = Dynamic_Lazy_SegTree_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename AM::X;\n\
    \  using A = typename AM::A;\n  using F = DefaultProd;\n  F default_prod;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(ll\
    \ L0, ll R0, F default_prod = F{})\n      : default_prod(std::move(default_prod)),\
    \ L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(); }\n\n  np new_node(const\
    \ X x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x,\
    \ c->lazy = MA::id();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n   \
    \ assert(l < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node()\
    \ { return L0 == R0 ? nullptr : new_node(L0, R0); }\n\n  np new_node(const vc<X>\
    \ &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs,\
    \ ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r - l\
    \ == 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root =\
    \ dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    if (l == r || !root) return MX::id();\n    assert(L0\
    \ <= l && l < r && r <= R0);\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x, MA::id());\n    return x;\n  }\n\n  X prod_all(np root) { return prod(root,\
    \ L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = clone(root);\n    set_rec(root, L0, R0, i, x);\n \
    \   return root;\n  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = clone(root);\n    multiply_rec(root, L0,\
    \ R0, i, x);\n    return root;\n  }\n\n  np apply(np root, ll l, ll r, const A\
    \ &a) {\n    if (l == r) return root;\n    assert(root && L0 <= l && l < r &&\
    \ r <= R0);\n    root = clone(root);\n    apply_rec(root, L0, R0, l, r, a);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    if (L == R0)\
    \ return R0;\n    assert(root);\n    X x = MX::id();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x, MA::id());\n  }\n\n  template <typename F>\n  ll min_left(np\
    \ root, F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::id()));\n\
    \    if (R == L0) return L0;\n    assert(root);\n    X x = MX::id();\n    return\
    \ min_left_rec(root, check, L0, R0, R, x, MA::id());\n  }\n\n  // \u751F\u6210\
    \u6E08\u307F\u306E\u8449\u306B\u3064\u3044\u3066 f(idx, val, end) \u3092\u547C\
    \u3076\n  template <typename F>\n  void enumerate(np root, F f) {\n    bool end\
    \ = false;\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {\n \
    \     if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x, a,\
    \ 1), end);\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      if (end) return;\n      dfs(dfs,\
    \ c->r, m, r, a);\n      if (end) return;\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::id());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    static_assert(PERSISTENT);\n\
    \    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n   \
    \ assert(root);\n    if (root == other) return apply(root, l, r, a);\n    root\
    \ = clone(root);\n    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return\
    \ root;\n  }\n\n private:\n  np clone(np c) {\n    if (!c || !PERSISTENT) return\
    \ c;\n    return pool.clone(c);\n  }\n\n  np own(np c, ll l, ll r) { return c\
    \ ? clone(c) : new_node(l, r); }\n\n  X value(np c, ll l, ll r) { return c ? c->x\
    \ : default_prod(l, r); }\n\n  void tag(np c, const A &a, ll len) {\n    c->x\
    \ = AM::act(c->x, a, len);\n    c->lazy = MA::op(c->lazy, a);\n  }\n\n  // c \u306F\
    \u66F8\u304D\u63DB\u3048\u53EF\u80FD\u3002\u5DE6\u53F3\u306E\u5B50\u3082\u66F8\
    \u304D\u63DB\u3048\u53EF\u80FD\u306B\u306A\u3063\u305F\u304B\u3092\u8FD4\u3059\
    \n  bool push(np c, ll l, ll m, ll r) {\n    assert(r - l >= 2);\n    if (c->lazy\
    \ == MA::id()) return false;\n    c->l = own(c->l, l, m);\n    c->r = own(c->r,\
    \ m, r);\n    tag(c->l, c->lazy, m - l);\n    tag(c->r, c->lazy, r - m);\n   \
    \ c->lazy = MA::id();\n    return true;\n  }\n\n  void pull(np c, ll l, ll m,\
    \ ll r) {\n    c->x = MX::op(value(c->l, l, m), value(c->r, m, r));\n  }\n\n \
    \ void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {\n    //\
    \ c[ql,qr) <- apply(d[ql,qr),a)\n    // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n    if (ql <= l && r <= qr) {\n      if (d) {\n\
    \        c->x = d->x;\n        c->lazy = d->lazy;\n        c->l = d->l, c->r =\
    \ d->r;\n      } else {\n        c->x = default_prod(l, r);\n        c->lazy =\
    \ MA::id();\n        c->l = c->r = nullptr;\n      }\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (d) a = MA::op(d->lazy, a);\n    if (ql < m) {\n      if (!pushed)\
    \ c->l = own(c->l, l, m);\n      copy_interval_rec(c->l, d ? d->l : nullptr, l,\
    \ m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      copy_interval_rec(c->r, d ? d->r : nullptr, m, r, ql, qr, a);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n  void set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r - l == 1) {\n      c->x = x;\n      c->lazy = MA::id();\n \
    \     return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (i < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      set_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      if (!pushed) c->r = own(c->r, m, r);\n   \
    \   set_rec(c->r, m, r, i, x);\n    }\n    pull(c, l, m, r);\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r - l == 1) {\n      c->x = MX::op(c->x,\
    \ x);\n      c->lazy = MA::id();\n      return;\n    }\n    ll m = (l + r) / 2;\n\
    \    bool pushed = push(c, l, m, r);\n    if (i < m) {\n      if (!pushed) c->l\
    \ = own(c->l, l, m);\n      multiply_rec(c->l, l, m, i, x);\n    } else {\n  \
    \    if (!pushed) c->r = own(c->r, m, r);\n      multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  void apply_rec(np c, ll l, ll r, ll ql,\
    \ ll qr, const A &a) {\n    if (ql <= l && r <= qr) {\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (ql < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      apply_rec(c->r, m, r, ql, qr, a);\n    }\n    pull(c, l, m, r);\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A a) {\n    if (!c)\
    \ {\n      ll L = max(l, ql), R = min(r, qr);\n      x = MX::op(x, AM::act(default_prod(L,\
    \ R), a, R - L));\n      return;\n    }\n    if (ql <= l && r <= qr) {\n     \
    \ x = MX::op(x, AM::act(c->x, a, r - l));\n      return;\n    }\n    ll m = (l\
    \ + r) / 2;\n    a = MA::op(c->lazy, a);\n    if (ql < m) prod_rec(c->l, l, m,\
    \ ql, qr, x, a);\n    if (m < qr) prod_rec(c->r, m, r, ql, qr, x, a);\n  }\n\n\
    \  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x, A a) {\n    if (r <= ql) return r;\n    if (ql <= l) {\n      X\
    \ y = MX::op(x, AM::act(value(c, l, r), a, r - l));\n      if (check(y)) {\n \
    \       x = y;\n        return r;\n      }\n    }\n    if (r - l == 1) return\
    \ l;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy, a);\n    if (ql\
    \ < m) {\n      ll k = max_right_rec(c ? c->l : nullptr, check, l, m, ql, x, a);\n\
    \      if (k < m) return k;\n    }\n    return max_right_rec(c ? c->r : nullptr,\
    \ check, m, r, ql, x, a);\n  }\n\n  template <typename F>\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x, A a) {\n    if (qr <= l) return\
    \ l;\n    if (r <= qr) {\n      X y = MX::op(AM::act(value(c, l, r), a, r - l),\
    \ x);\n      if (check(y)) {\n        x = y;\n        return l;\n      }\n   \
    \ }\n    if (r - l == 1) return r;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy,\
    \ a);\n    if (m < qr) {\n      ll k = min_left_rec(c ? c->r : nullptr, check,\
    \ m, r, qr, x, a);\n      if (m < k) return k;\n    }\n    return min_left_rec(c\
    \ ? c->l : nullptr, check, l, m, qr, x, a);\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp\n\
    #include \"ds/node_pool.hpp\"\n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Default_Prod\
    \ {\n  using MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// set, multiply: 2H nodes \u7A0B\u5EA6\
    \n// apply: 4H nodes \u7A0B\u5EA6\ntemplate <typename ActedMonoid, bool PERSISTENT,\n\
    \    typename DefaultProd = Dynamic_Lazy_SegTree_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename AM::X;\n\
    \  using A = typename AM::A;\n  using F = DefaultProd;\n  F default_prod;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(ll\
    \ L0, ll R0, F default_prod = F{})\n      : default_prod(std::move(default_prod)),\
    \ L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(); }\n\n  np new_node(const\
    \ X x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x,\
    \ c->lazy = MA::id();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n   \
    \ assert(l < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node()\
    \ { return L0 == R0 ? nullptr : new_node(L0, R0); }\n\n  np new_node(const vc<X>\
    \ &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs,\
    \ ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r - l\
    \ == 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root =\
    \ dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    if (l == r || !root) return MX::id();\n    assert(L0\
    \ <= l && l < r && r <= R0);\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x, MA::id());\n    return x;\n  }\n\n  X prod_all(np root) { return prod(root,\
    \ L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = clone(root);\n    set_rec(root, L0, R0, i, x);\n \
    \   return root;\n  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = clone(root);\n    multiply_rec(root, L0,\
    \ R0, i, x);\n    return root;\n  }\n\n  np apply(np root, ll l, ll r, const A\
    \ &a) {\n    if (l == r) return root;\n    assert(root && L0 <= l && l < r &&\
    \ r <= R0);\n    root = clone(root);\n    apply_rec(root, L0, R0, l, r, a);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    if (L == R0)\
    \ return R0;\n    assert(root);\n    X x = MX::id();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x, MA::id());\n  }\n\n  template <typename F>\n  ll min_left(np\
    \ root, F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::id()));\n\
    \    if (R == L0) return L0;\n    assert(root);\n    X x = MX::id();\n    return\
    \ min_left_rec(root, check, L0, R0, R, x, MA::id());\n  }\n\n  // \u751F\u6210\
    \u6E08\u307F\u306E\u8449\u306B\u3064\u3044\u3066 f(idx, val, end) \u3092\u547C\
    \u3076\n  template <typename F>\n  void enumerate(np root, F f) {\n    bool end\
    \ = false;\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {\n \
    \     if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x, a,\
    \ 1), end);\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      if (end) return;\n      dfs(dfs,\
    \ c->r, m, r, a);\n      if (end) return;\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::id());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    static_assert(PERSISTENT);\n\
    \    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n   \
    \ assert(root);\n    if (root == other) return apply(root, l, r, a);\n    root\
    \ = clone(root);\n    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return\
    \ root;\n  }\n\n private:\n  np clone(np c) {\n    if (!c || !PERSISTENT) return\
    \ c;\n    return pool.clone(c);\n  }\n\n  np own(np c, ll l, ll r) { return c\
    \ ? clone(c) : new_node(l, r); }\n\n  X value(np c, ll l, ll r) { return c ? c->x\
    \ : default_prod(l, r); }\n\n  void tag(np c, const A &a, ll len) {\n    c->x\
    \ = AM::act(c->x, a, len);\n    c->lazy = MA::op(c->lazy, a);\n  }\n\n  // c \u306F\
    \u66F8\u304D\u63DB\u3048\u53EF\u80FD\u3002\u5DE6\u53F3\u306E\u5B50\u3082\u66F8\
    \u304D\u63DB\u3048\u53EF\u80FD\u306B\u306A\u3063\u305F\u304B\u3092\u8FD4\u3059\
    \n  bool push(np c, ll l, ll m, ll r) {\n    assert(r - l >= 2);\n    if (c->lazy\
    \ == MA::id()) return false;\n    c->l = own(c->l, l, m);\n    c->r = own(c->r,\
    \ m, r);\n    tag(c->l, c->lazy, m - l);\n    tag(c->r, c->lazy, r - m);\n   \
    \ c->lazy = MA::id();\n    return true;\n  }\n\n  void pull(np c, ll l, ll m,\
    \ ll r) {\n    c->x = MX::op(value(c->l, l, m), value(c->r, m, r));\n  }\n\n \
    \ void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {\n    //\
    \ c[ql,qr) <- apply(d[ql,qr),a)\n    // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n    if (ql <= l && r <= qr) {\n      if (d) {\n\
    \        c->x = d->x;\n        c->lazy = d->lazy;\n        c->l = d->l, c->r =\
    \ d->r;\n      } else {\n        c->x = default_prod(l, r);\n        c->lazy =\
    \ MA::id();\n        c->l = c->r = nullptr;\n      }\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (d) a = MA::op(d->lazy, a);\n    if (ql < m) {\n      if (!pushed)\
    \ c->l = own(c->l, l, m);\n      copy_interval_rec(c->l, d ? d->l : nullptr, l,\
    \ m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      copy_interval_rec(c->r, d ? d->r : nullptr, m, r, ql, qr, a);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n  void set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r - l == 1) {\n      c->x = x;\n      c->lazy = MA::id();\n \
    \     return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (i < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      set_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      if (!pushed) c->r = own(c->r, m, r);\n   \
    \   set_rec(c->r, m, r, i, x);\n    }\n    pull(c, l, m, r);\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r - l == 1) {\n      c->x = MX::op(c->x,\
    \ x);\n      c->lazy = MA::id();\n      return;\n    }\n    ll m = (l + r) / 2;\n\
    \    bool pushed = push(c, l, m, r);\n    if (i < m) {\n      if (!pushed) c->l\
    \ = own(c->l, l, m);\n      multiply_rec(c->l, l, m, i, x);\n    } else {\n  \
    \    if (!pushed) c->r = own(c->r, m, r);\n      multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  void apply_rec(np c, ll l, ll r, ll ql,\
    \ ll qr, const A &a) {\n    if (ql <= l && r <= qr) {\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (ql < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      apply_rec(c->r, m, r, ql, qr, a);\n    }\n    pull(c, l, m, r);\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A a) {\n    if (!c)\
    \ {\n      ll L = max(l, ql), R = min(r, qr);\n      x = MX::op(x, AM::act(default_prod(L,\
    \ R), a, R - L));\n      return;\n    }\n    if (ql <= l && r <= qr) {\n     \
    \ x = MX::op(x, AM::act(c->x, a, r - l));\n      return;\n    }\n    ll m = (l\
    \ + r) / 2;\n    a = MA::op(c->lazy, a);\n    if (ql < m) prod_rec(c->l, l, m,\
    \ ql, qr, x, a);\n    if (m < qr) prod_rec(c->r, m, r, ql, qr, x, a);\n  }\n\n\
    \  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x, A a) {\n    if (r <= ql) return r;\n    if (ql <= l) {\n      X\
    \ y = MX::op(x, AM::act(value(c, l, r), a, r - l));\n      if (check(y)) {\n \
    \       x = y;\n        return r;\n      }\n    }\n    if (r - l == 1) return\
    \ l;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy, a);\n    if (ql\
    \ < m) {\n      ll k = max_right_rec(c ? c->l : nullptr, check, l, m, ql, x, a);\n\
    \      if (k < m) return k;\n    }\n    return max_right_rec(c ? c->r : nullptr,\
    \ check, m, r, ql, x, a);\n  }\n\n  template <typename F>\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x, A a) {\n    if (qr <= l) return\
    \ l;\n    if (r <= qr) {\n      X y = MX::op(AM::act(value(c, l, r), a, r - l),\
    \ x);\n      if (check(y)) {\n        x = y;\n        return l;\n      }\n   \
    \ }\n    if (r - l == 1) return r;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy,\
    \ a);\n    if (m < qr) {\n      ll k = min_left_rec(c ? c->r : nullptr, check,\
    \ m, r, qr, x, a);\n      if (m < k) return k;\n    }\n    return min_left_rec(c\
    \ ? c->l : nullptr, check, l, m, qr, x, a);\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_lazy_segtree.hpp
  requiredBy: []
  timestamp: '2026-11-25 16:46:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/dynamic_lazy_segtree.test.cpp
  - test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/3_yukicoder/789_2.test.cpp
  - test/3_yukicoder/2292.test.cpp
  - test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  - test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
documentation_of: ds/segtree/dynamic_lazy_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_lazy_segtree.hpp
- /library/ds/segtree/dynamic_lazy_segtree.hpp.html
title: ds/segtree/dynamic_lazy_segtree.hpp
---
