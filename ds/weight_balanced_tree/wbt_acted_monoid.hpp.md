---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\n// \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\
    \u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\u6E08\u307F chunk \u3092\u518D\u5229\
    \u7528\u3059\u308B\ntemplate <class Node>\nstruct Node_Pool {\n  union Slot {\n\
    \    Node node;\n    Slot* next;\n\n    Slot() {}\n    ~Slot() {}\n  };\n  using\
    \ np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 << 12;\n\n  vc<unique_ptr<Slot[]>>\
    \ chunks;\n  int chunk_id = 0;\n  int pos = 0;\n  Slot* free_head = nullptr;\n\
    \n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n    for (auto& p : chunks)\
    \ cache.eb(std::move(p));\n  }\n\n  template <class... Args>\n  np create(Args&&...\
    \ args) {\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (&s->node) Node(*x);\n  }\n\n  void destroy(np x) {\n    if\
    \ (!x) return;\n    x->~Node();\n    Slot* s = reinterpret_cast<Slot*>(x);\n \
    \   s->next = free_head;\n    free_head = s;\n  }\n\n  // \u5168 node \u3092\u7121\
    \u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\u4FDD\u6E08\u307F chunk \u306F\u89E3\
    \u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\u964D\u306B\u518D\u5229\u7528\u3059\
    \u308B\u3002\n  void reset() {\n    free_head = nullptr;\n    chunk_id = 0;\n\
    \    pos = 0;\n  }\n\n  int used() const { return chunk_id * CHUNK_SIZE + pos;\
    \ }\n\n private:\n  static vc<unique_ptr<Slot[]>>& chunk_cache() {\n    // static\
    \ Node_Pool \u306E destructor \u3088\u308A\u5148\u306B\u7834\u68C4\u3055\u308C\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\n    static auto* cache = new\
    \ vc<unique_ptr<Slot[]>>();\n    return *cache;\n  }\n\n  void alloc_chunk() {\n\
    \    auto& cache = chunk_cache();\n    if (cache.empty()) {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    } else {\n      chunks.eb(std::move(cache.back()));\n      cache.pop_back();\n\
    \    }\n  }\n\n  Slot* new_slot() {\n    if (free_head) {\n      Slot* s = free_head;\n\
    \      free_head = free_head->next;\n      return s;\n    }\n\n    if (chunk_id\
    \ == len(chunks)) alloc_chunk();\n\n    Slot* s = &chunks[chunk_id][pos++];\n\
    \    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n      pos = 0;\n    }\n    return\
    \ s;\n  }\n};\n#line 2 \"ds/weight_balanced_tree/wbt_base.hpp\"\n\n// Adams' weight\
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
    \ j);\n    return {a, b, c, d};\n  }\n};\n#line 4 \"ds/weight_balanced_tree/wbt_acted_monoid.hpp\"\
    \ntemplate <class X, class A>\nstruct WBT_Acted_Node {\n  WBT_Acted_Node *l, *r;\n\
    \  X x, prod, rev_prod;\n  A lazy;\n  u32 size;\n  bool rev;\n};\ntemplate <class\
    \ ActedMonoid, bool PERSISTENT>\nstruct WBT_ActedMonoid\n    : WBT_Sequence_Base<WBT_ActedMonoid<ActedMonoid,\
    \ PERSISTENT>,\n          WBT_Acted_Node<typename ActedMonoid::Monoid_X::value_type,\n\
    \              typename ActedMonoid::Monoid_A::value_type>,\n          PERSISTENT>\
    \ {\n  using MX = typename ActedMonoid::Monoid_X;\n  using MA = typename ActedMonoid::Monoid_A;\n\
    \  using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\
    \  using Node = WBT_Acted_Node<X, A>;\n  using np = Node *;\n  Node_Pool<Node>\
    \ pool;\n  void reset() { pool.reset(); }\n  np new_root() { return nullptr; }\n\
    \  np new_node(const X &x) {\n    np t = pool.create();\n    t->l = t->r = nullptr;\n\
    \    t->x = t->prod = t->rev_prod = x;\n    t->lazy = MA::id();\n    t->size =\
    \ 1;\n    t->rev = 0;\n    return t;\n  }\n  np new_node(const vc<X> &a) {\n \
    \   auto f = [&](auto &&f, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n\
    \      u32 m = (l + r) >> 1;\n      np t = new_node(a[m]);\n      t->l = f(f,\
    \ l, m), t->r = f(f, m + 1, r);\n      pull(t);\n      return t;\n    };\n   \
    \ return f(f, 0, a.size());\n  }\n  np clone(np t) { return (!t || !PERSISTENT)\
    \ ? t : pool.clone(t); }\n  void pull(np t) {\n    t->size = 1;\n    t->prod =\
    \ t->rev_prod = t->x;\n    if (t->l) {\n      t->size += t->l->size;\n      t->prod\
    \ = MX::op(t->l->prod, t->prod);\n      t->rev_prod = MX::op(t->rev_prod, t->l->rev_prod);\n\
    \    }\n    if (t->r) {\n      t->size += t->r->size;\n      t->prod = MX::op(t->prod,\
    \ t->r->prod);\n      t->rev_prod = MX::op(t->r->rev_prod, t->rev_prod);\n   \
    \ }\n  }\n  void all_apply(np t, const A &a) {\n    t->x = ActedMonoid::act(t->x,\
    \ a, 1);\n    t->prod = ActedMonoid::act(t->prod, a, t->size);\n    t->rev_prod\
    \ = ActedMonoid::act(t->rev_prod, a, t->size);\n    t->lazy = MA::op(t->lazy,\
    \ a);\n  }\n  void push(np t) {\n    if (t->lazy != MA::id())\n      for (np *q\
    \ : {&t->l, &t->r})\n        if (*q) {\n          *q = clone(*q);\n          all_apply(*q,\
    \ t->lazy);\n        }\n    t->lazy = MA::id();\n    if (t->rev)\n      for (np\
    \ *q : {&t->l, &t->r})\n        if (*q) {\n          *q = clone(*q);\n       \
    \   (*q)->rev ^= 1;\n          swap((*q)->l, (*q)->r);\n          swap((*q)->prod,\
    \ (*q)->rev_prod);\n        }\n    t->rev = 0;\n  }\n  np reverse(np t, u32 l,\
    \ u32 r) {\n    assert(l <= r && r <= t->size);\n    if (r - l <= 1) return t;\n\
    \    auto [a, b, c] = this->split3(t, l, r);\n    b = clone(b);\n    b->rev ^=\
    \ 1;\n    swap(b->l, b->r);\n    swap(b->prod, b->rev_prod);\n    return this->merge3(a,\
    \ b, c);\n  }\n  np apply(np t, const A &a) {\n    if (!t) return t;\n    t =\
    \ clone(t);\n    all_apply(t, a);\n    return t;\n  }\n  np apply(np t, u32 l,\
    \ u32 r, const A &a) {\n    auto [x, y, z] = this->split3(t, l, r);\n    y = apply(y,\
    \ a);\n    return this->merge3(x, y, z);\n  }\n  np set(np t, u32 k, const X &x)\
    \ {\n    auto [a, b, c] = this->split3(t, k, k + 1);\n    b = clone(b);\n    push(b);\n\
    \    b->x = x;\n    pull(b);\n    return this->merge3(a, b, c);\n  }\n  np multiply(np\
    \ t, u32 k, const X &x) {\n    return set(t, k, MX::op(get(t, k), x));\n  }\n\
    \  X prod(np t) { return t ? t->prod : MX::id(); }\n  X prod(np t, u32 l, u32\
    \ r) {\n    assert(l <= r && r <= t->size);\n    return prod_rec(t, l, r, 0, MA::id());\n\
    \  }\n  X get(np t, u32 k) {\n    bool z = 0;\n    A a = MA::id();\n    while\
    \ (1) {\n      np l = z ? t->r : t->l, r = z ? t->l : t->r;\n      u32 s = l ?\
    \ l->size : 0;\n      if (k == s) return ActedMonoid::act(t->x, a, 1);\n     \
    \ a = MA::op(t->lazy, a);\n      z ^= t->rev;\n      if (k < s)\n        t = l;\n\
    \      else\n        k -= s + 1, t = r;\n    }\n  }\n  vc<X> get_all(np t) {\n\
    \    vc<X> a;\n    auto f = [&](auto &&f, np q, bool z, A b) -> void {\n     \
    \ if (!q) return;\n      f(f, z ? q->r : q->l, z ^ q->rev, MA::op(q->lazy, b));\n\
    \      a.eb(ActedMonoid::act(q->x, b, 1));\n      f(f, z ? q->l : q->r, z ^ q->rev,\
    \ MA::op(q->lazy, b));\n    };\n    f(f, t, 0, MA::id());\n    return a;\n  }\n\
    \  template <class F>\n  pair<np, np> split_max_right(np t, const F &f) {\n  \
    \  assert(f(MX::id()));\n    X x = MX::id();\n    u32 k = 0;\n    for (auto &&y\
    \ : get_all(t)) {\n      if (!f(MX::op(x, y))) break;\n      x = MX::op(x, y);\n\
    \      ++k;\n    }\n    return this->split(t, k);\n  }\n  template <class F>\n\
    \  pair<np, np> split_max_right_prod(np t, const F &f) {\n    return split_max_right(t,\
    \ f);\n  }\n  void free_subtree(np t) {\n    if (!t) return;\n    free_subtree(t->l);\n\
    \    free_subtree(t->r);\n    pool.destroy(t);\n  }\n\n private:\n  X prod_rec(np\
    \ t, u32 l, u32 r, bool z, A a) {\n    if (l == 0 && r == t->size)\n      return\
    \ ActedMonoid::act(z ? t->rev_prod : t->prod, a, t->size);\n    np q = z ? t->r\
    \ : t->l, w = z ? t->l : t->r;\n    u32 s = q ? q->size : 0;\n    A b = MA::op(t->lazy,\
    \ a);\n    X x = MX::id();\n    if (l < s) x = MX::op(x, prod_rec(q, l, min(r,\
    \ s), z ^ t->rev, b));\n    if (l <= s && s < r) x = MX::op(x, ActedMonoid::act(t->x,\
    \ a, 1));\n    if (s + 1 < r)\n      x = MX::op(\n          x, prod_rec(w, max(l,\
    \ s + 1) - s - 1, r - s - 1, z ^ t->rev, b));\n    return x;\n  }\n};\n"
  code: "#pragma once\n#include \"ds/node_pool.hpp\"\n#include \"ds/weight_balanced_tree/wbt_base.hpp\"\
    \ntemplate <class X, class A>\nstruct WBT_Acted_Node {\n  WBT_Acted_Node *l, *r;\n\
    \  X x, prod, rev_prod;\n  A lazy;\n  u32 size;\n  bool rev;\n};\ntemplate <class\
    \ ActedMonoid, bool PERSISTENT>\nstruct WBT_ActedMonoid\n    : WBT_Sequence_Base<WBT_ActedMonoid<ActedMonoid,\
    \ PERSISTENT>,\n          WBT_Acted_Node<typename ActedMonoid::Monoid_X::value_type,\n\
    \              typename ActedMonoid::Monoid_A::value_type>,\n          PERSISTENT>\
    \ {\n  using MX = typename ActedMonoid::Monoid_X;\n  using MA = typename ActedMonoid::Monoid_A;\n\
    \  using X = typename MX::value_type;\n  using A = typename MA::value_type;\n\
    \  using Node = WBT_Acted_Node<X, A>;\n  using np = Node *;\n  Node_Pool<Node>\
    \ pool;\n  void reset() { pool.reset(); }\n  np new_root() { return nullptr; }\n\
    \  np new_node(const X &x) {\n    np t = pool.create();\n    t->l = t->r = nullptr;\n\
    \    t->x = t->prod = t->rev_prod = x;\n    t->lazy = MA::id();\n    t->size =\
    \ 1;\n    t->rev = 0;\n    return t;\n  }\n  np new_node(const vc<X> &a) {\n \
    \   auto f = [&](auto &&f, u32 l, u32 r) -> np {\n      if (l == r) return nullptr;\n\
    \      u32 m = (l + r) >> 1;\n      np t = new_node(a[m]);\n      t->l = f(f,\
    \ l, m), t->r = f(f, m + 1, r);\n      pull(t);\n      return t;\n    };\n   \
    \ return f(f, 0, a.size());\n  }\n  np clone(np t) { return (!t || !PERSISTENT)\
    \ ? t : pool.clone(t); }\n  void pull(np t) {\n    t->size = 1;\n    t->prod =\
    \ t->rev_prod = t->x;\n    if (t->l) {\n      t->size += t->l->size;\n      t->prod\
    \ = MX::op(t->l->prod, t->prod);\n      t->rev_prod = MX::op(t->rev_prod, t->l->rev_prod);\n\
    \    }\n    if (t->r) {\n      t->size += t->r->size;\n      t->prod = MX::op(t->prod,\
    \ t->r->prod);\n      t->rev_prod = MX::op(t->r->rev_prod, t->rev_prod);\n   \
    \ }\n  }\n  void all_apply(np t, const A &a) {\n    t->x = ActedMonoid::act(t->x,\
    \ a, 1);\n    t->prod = ActedMonoid::act(t->prod, a, t->size);\n    t->rev_prod\
    \ = ActedMonoid::act(t->rev_prod, a, t->size);\n    t->lazy = MA::op(t->lazy,\
    \ a);\n  }\n  void push(np t) {\n    if (t->lazy != MA::id())\n      for (np *q\
    \ : {&t->l, &t->r})\n        if (*q) {\n          *q = clone(*q);\n          all_apply(*q,\
    \ t->lazy);\n        }\n    t->lazy = MA::id();\n    if (t->rev)\n      for (np\
    \ *q : {&t->l, &t->r})\n        if (*q) {\n          *q = clone(*q);\n       \
    \   (*q)->rev ^= 1;\n          swap((*q)->l, (*q)->r);\n          swap((*q)->prod,\
    \ (*q)->rev_prod);\n        }\n    t->rev = 0;\n  }\n  np reverse(np t, u32 l,\
    \ u32 r) {\n    assert(l <= r && r <= t->size);\n    if (r - l <= 1) return t;\n\
    \    auto [a, b, c] = this->split3(t, l, r);\n    b = clone(b);\n    b->rev ^=\
    \ 1;\n    swap(b->l, b->r);\n    swap(b->prod, b->rev_prod);\n    return this->merge3(a,\
    \ b, c);\n  }\n  np apply(np t, const A &a) {\n    if (!t) return t;\n    t =\
    \ clone(t);\n    all_apply(t, a);\n    return t;\n  }\n  np apply(np t, u32 l,\
    \ u32 r, const A &a) {\n    auto [x, y, z] = this->split3(t, l, r);\n    y = apply(y,\
    \ a);\n    return this->merge3(x, y, z);\n  }\n  np set(np t, u32 k, const X &x)\
    \ {\n    auto [a, b, c] = this->split3(t, k, k + 1);\n    b = clone(b);\n    push(b);\n\
    \    b->x = x;\n    pull(b);\n    return this->merge3(a, b, c);\n  }\n  np multiply(np\
    \ t, u32 k, const X &x) {\n    return set(t, k, MX::op(get(t, k), x));\n  }\n\
    \  X prod(np t) { return t ? t->prod : MX::id(); }\n  X prod(np t, u32 l, u32\
    \ r) {\n    assert(l <= r && r <= t->size);\n    return prod_rec(t, l, r, 0, MA::id());\n\
    \  }\n  X get(np t, u32 k) {\n    bool z = 0;\n    A a = MA::id();\n    while\
    \ (1) {\n      np l = z ? t->r : t->l, r = z ? t->l : t->r;\n      u32 s = l ?\
    \ l->size : 0;\n      if (k == s) return ActedMonoid::act(t->x, a, 1);\n     \
    \ a = MA::op(t->lazy, a);\n      z ^= t->rev;\n      if (k < s)\n        t = l;\n\
    \      else\n        k -= s + 1, t = r;\n    }\n  }\n  vc<X> get_all(np t) {\n\
    \    vc<X> a;\n    auto f = [&](auto &&f, np q, bool z, A b) -> void {\n     \
    \ if (!q) return;\n      f(f, z ? q->r : q->l, z ^ q->rev, MA::op(q->lazy, b));\n\
    \      a.eb(ActedMonoid::act(q->x, b, 1));\n      f(f, z ? q->l : q->r, z ^ q->rev,\
    \ MA::op(q->lazy, b));\n    };\n    f(f, t, 0, MA::id());\n    return a;\n  }\n\
    \  template <class F>\n  pair<np, np> split_max_right(np t, const F &f) {\n  \
    \  assert(f(MX::id()));\n    X x = MX::id();\n    u32 k = 0;\n    for (auto &&y\
    \ : get_all(t)) {\n      if (!f(MX::op(x, y))) break;\n      x = MX::op(x, y);\n\
    \      ++k;\n    }\n    return this->split(t, k);\n  }\n  template <class F>\n\
    \  pair<np, np> split_max_right_prod(np t, const F &f) {\n    return split_max_right(t,\
    \ f);\n  }\n  void free_subtree(np t) {\n    if (!t) return;\n    free_subtree(t->l);\n\
    \    free_subtree(t->r);\n    pool.destroy(t);\n  }\n\n private:\n  X prod_rec(np\
    \ t, u32 l, u32 r, bool z, A a) {\n    if (l == 0 && r == t->size)\n      return\
    \ ActedMonoid::act(z ? t->rev_prod : t->prod, a, t->size);\n    np q = z ? t->r\
    \ : t->l, w = z ? t->l : t->r;\n    u32 s = q ? q->size : 0;\n    A b = MA::op(t->lazy,\
    \ a);\n    X x = MX::id();\n    if (l < s) x = MX::op(x, prod_rec(q, l, min(r,\
    \ s), z ^ t->rev, b));\n    if (l <= s && s < r) x = MX::op(x, ActedMonoid::act(t->x,\
    \ a, 1));\n    if (s + 1 < r)\n      x = MX::op(\n          x, prod_rec(w, max(l,\
    \ s + 1) - s - 1, r - s - 1, z ^ t->rev, b));\n    return x;\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  - ds/weight_balanced_tree/wbt_base.hpp
  isVerificationFile: false
  path: ds/weight_balanced_tree/wbt_acted_monoid.hpp
  requiredBy: []
  timestamp: '2026-10-04 10:39:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/weight_balanced_tree/wbt_acted_monoid.hpp
layout: document
redirect_from:
- /library/ds/weight_balanced_tree/wbt_acted_monoid.hpp
- /library/ds/weight_balanced_tree/wbt_acted_monoid.hpp.html
title: ds/weight_balanced_tree/wbt_acted_monoid.hpp
---
