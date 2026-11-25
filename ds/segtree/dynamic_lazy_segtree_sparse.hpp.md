---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/range_affine_range_sum_large_2.test.cpp
    title: test/2_library_checker/data_structure/range_affine_range_sum_large_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
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
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 2 \"ds/segtree/dynamic_lazy_segtree_sparse.hpp\"\
    \n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Sparse_Default_Prod {\n\
    \  using MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// \u533A\u9593\u306E\u5DE6\u7AEF\u3092\
    \u30AD\u30FC\u3068\u3057\u3066\u3001Dynamic_SegTree_Sparse \u3068\u540C\u69D8\u306B\
    \u633F\u5165\u3059\u308B\n// PERSISTENT=false \u3068\u3057\u3066\n// set, multiply,\
    \ apply: \u9AD8\u3005 2 \u30CE\u30FC\u30C9\n// prod, max_right, min_left: \u30CE\
    \u30FC\u30C9\u3092\u8FFD\u52A0\u3057\u306A\u3044\ntemplate <typename ActedMonoid,\
    \ bool PERSISTENT,\n    typename DefaultProd =\n        Dynamic_Lazy_SegTree_Sparse_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree_Sparse {\n  using AM = ActedMonoid;\n  using MX =\
    \ typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename\
    \ AM::X;\n  using A = typename AM::A;\n  using F = DefaultProd;\n  // \u81EA\u8EAB\
    \u306E\u533A\u9593\u3068\u305D\u306E\u533A\u9593\u7A4D\u3001\u7D2F\u7A4D\u4F5C\
    \u7528\n  struct Piece {\n    ll l, r;\n    X x;\n    A own;\n  };\n  struct Node\
    \ {\n    Node *l, *r;\n    Piece d;\n    ll lo, hi;  // \u90E8\u5206\u6728\u5168\
    \u4F53\u306E\u5EA7\u6A19\u7BC4\u56F2\n    X x;        // \u90E8\u5206\u6728\u5168\
    \u4F53\u306E\u533A\u9593\u7A4D\n    A lazy;     // \u5B50\u3078\u306E\u672A\u4F1D\
    \u64AD\u306E\u4F5C\u7528\n  };\n  using np = Node *;\n  F default_prod;\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n\n  Dynamic_Lazy_SegTree_Sparse(ll L0, ll R0, F default_prod\
    \ = F{})\n      : default_prod(std::move(default_prod)), L0(L0), R0(R0) {\n  \
    \  assert(-infty<ll> <= L0 && L0 <= R0 && R0 <= infty<ll>);\n  }\n\n  np new_root()\
    \ { return L0 == R0 ? nullptr : make(piece(L0, R0, MA::id())); }\n  np new_node()\
    \ { return new_root(); }\n  np new_node(const vc<X> &dat) {\n    assert(L0 ==\
    \ 0 && R0 == ll(dat.size()));\n    auto dfs = [&](auto &dfs, ll l, ll r, ll a,\
    \ ll b) -> np {\n      if (a == b) return nullptr;\n      ll m = l + (r - l) /\
    \ 2;\n      ll k = min(max(m, a), b - 1);\n      np c = make(Piece{k, k + 1, dat[k],\
    \ MA::id()});\n      c->l = dfs(dfs, l, m, a, k);\n      c->r = dfs(dfs, m, r,\
    \ k + 1, b);\n      pull(c);\n      return c;\n    };\n    return dfs(dfs, L0,\
    \ R0, L0, R0);\n  }\n  void reset() { pool.reset(); }\n\n  X prod(np root, ll\
    \ l, ll r) {\n    assert(L0 <= l && l <= r && r <= R0);\n    X x = MX::id();\n\
    \    if (root && l < r) prod_rec(root, l, r, MA::id(), x);\n    return x;\n  }\n\
    \  X prod_all(np root) { return root ? root->x : MX::id(); }\n  X get(np root,\
    \ ll i) { return prod(root, i, i + 1); }\n\n  np apply(np root, ll l, ll r, const\
    \ A &a) {\n    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n\
    \    assert(root);\n    root = ensure(root, L0, R0, l);\n    root = ensure(root,\
    \ L0, R0, r);\n    root = clone(root);\n    apply_rec(root, l, r, a);\n    return\
    \ root;\n  }\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = ensure(root, L0, R0, i);\n    root = ensure(root,\
    \ L0, R0, i + 1);\n    root = clone(root);\n    point_rec<false>(root, i, x);\n\
    \    return root;\n  }\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = ensure(root, L0, R0, i);\n    root = ensure(root,\
    \ L0, R0, i + 1);\n    root = clone(root);\n    point_rec<true>(root, i, x);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    X x = MX::id();\n\
    \    return max_right_rec(root, check, L, MA::id(), x);\n  }\n  template <typename\
    \ F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0 <= R && R <= R0 &&\
    \ check(MX::id()));\n    X x = MX::id();\n    return min_left_rec(root, check,\
    \ R, MA::id(), x);\n  }\n\n private:\n  np clone(np c) {\n    if constexpr (PERSISTENT)\
    \ {\n      if (c) return pool.clone(c);\n    }\n    return c;\n  }\n  Piece piece(ll\
    \ l, ll r, const A &a) {\n    return {l, r, AM::act(default_prod(l, r), a, r -\
    \ l), a};\n  }\n  np make(const Piece &d) {\n    np c = pool.create();\n    c->l\
    \ = c->r = nullptr;\n    c->d = d;\n    c->lo = d.l, c->hi = d.r;\n    c->x =\
    \ d.x, c->lazy = MA::id();\n    return c;\n  }\n  void tag_own(np c, const A &a)\
    \ {\n    Piece &d = c->d;\n    d.x = AM::act(d.x, a, d.r - d.l);\n    d.own =\
    \ MA::op(d.own, a);\n  }\n  void tag(np c, const A &a) {\n    c->x = AM::act(c->x,\
    \ a, c->hi - c->lo);\n    tag_own(c, a);\n    c->lazy = MA::op(c->lazy, a);\n\
    \  }\n  bool push(np c) {\n    if (c->lazy == MA::id()) return false;\n    if\
    \ (c->l) {\n      c->l = clone(c->l);\n      tag(c->l, c->lazy);\n    }\n    if\
    \ (c->r) {\n      c->r = clone(c->r);\n      tag(c->r, c->lazy);\n    }\n    c->lazy\
    \ = MA::id();\n    return true;\n  }\n  void pull(np c) {\n    c->lo = c->l ?\
    \ c->l->lo : c->d.l;\n    c->hi = c->r ? c->r->hi : c->d.r;\n    c->x = c->d.x;\n\
    \    if (c->l) c->x = MX::op(c->l->x, c->x);\n    if (c->r) c->x = MX::op(c->x,\
    \ c->r->x);\n  }\n  // \u533A\u9593\u306E\u5DE6\u7AEF\u3092\u30AD\u30FC\u3068\u3057\
    \u3066\u633F\u5165\u3059\u308B\uFF08Dynamic_SegTree_Sparse \u3068\u540C\u69D8\uFF09\
    \n  np insert(np c, ll l, ll r, Piece d, bool owned) {\n    if (!c) return make(d);\n\
    \    if (!owned) c = clone(c);\n    bool pushed = push(c);\n    insert_here(c,\
    \ l, r, std::move(d), pushed);\n    pull(c);\n    return c;\n  }\n  void insert_here(np\
    \ c, ll l, ll r, Piece d, bool pushed) {\n    ll m = l + (r - l) / 2;\n    assert(l\
    \ <= d.l && d.l < r && d.l != c->d.l);\n    if (d.l < m) {\n      if (c->d.l <\
    \ d.l) swap(c->d, d);\n      c->l = insert(c->l, l, m, std::move(d), pushed);\n\
    \    } else {\n      if (d.l < c->d.l) swap(c->d, d);\n      c->r = insert(c->r,\
    \ m, r, std::move(d), pushed);\n    }\n  }\n  Piece split_own(np c, ll k) {\n\
    \    assert(c->d.l < k && k < c->d.r);\n    Piece d = piece(k, c->d.r, c->d.own);\n\
    \    c->d = piece(c->d.l, k, c->d.own);\n    return d;\n  }\n  // k \u3092\u542B\
    \u3080\u533A\u9593\u3092\u5206\u5272\u3057\u3001\u53F3\u5074\u306E\u533A\u9593\
    \u3092 out \u306B\u53D6\u308A\u51FA\u3059\n  // \u53D6\u308A\u51FA\u3057\u305F\
    \u533A\u9593\u306F insert_here \u306B\u3088\u3063\u3066\u623B\u3059\n  np cut(np\
    \ c, ll l, ll r, ll k, optional<Piece> &out, bool owned) {\n    assert(c);\n \
    \   if (k == c->lo || k == c->hi || k == c->d.l || k == c->d.r) return c;\n  \
    \  if (!owned) c = clone(c);\n    bool pushed = push(c);\n    ll m = l + (r -\
    \ l) / 2;\n    if (k < c->d.l)\n      c->l = cut(c->l, l, m, k, out, pushed);\n\
    \    else if (c->d.r < k)\n      c->r = cut(c->r, m, r, k, out, pushed);\n   \
    \ else\n      out = split_own(c, k);\n    pull(c);\n    return c;\n  }\n  // k\
    \ \u3092\u533A\u9593\u306E\u5883\u754C\u306B\u3059\u308B\u3002cut \u3068 insert\
    \ \u306E\u5171\u901A\u3059\u308B\u7D4C\u8DEF\u306F\u4E00\u5EA6\u3060\u3051\u305F\
    \u3069\u308B\n  // \u30AD\u30FC\u306E\u4E8C\u5206\u4F4D\u7F6E\u3068\u3001k \u3092\
    \u542B\u3080\u533A\u9593\u306E\u4F4D\u7F6E\u306F\u4E00\u81F4\u3059\u308B\u3068\
    \u306F\u9650\u3089\u306A\u3044\n  np ensure(np c, ll l, ll r, ll k, bool owned\
    \ = false) {\n    assert(c);\n    if (k == c->lo || k == c->hi || k == c->d.l\
    \ || k == c->d.r) return c;\n    if (!owned) c = clone(c);\n    bool pushed =\
    \ push(c);\n    ll m = l + (r - l) / 2;\n    if (k < c->d.l) {\n      if (k <\
    \ m)\n        c->l = ensure(c->l, l, m, k, pushed);\n      else {\n        optional<Piece>\
    \ d;\n        c->l = cut(c->l, l, m, k, d, pushed);\n        if (d) insert_here(c,\
    \ l, r, std::move(*d), pushed);\n      }\n    } else if (c->d.r < k) {\n     \
    \ if (m <= k)\n        c->r = ensure(c->r, m, r, k, pushed);\n      else {\n \
    \       optional<Piece> d;\n        c->r = cut(c->r, m, r, k, d, pushed);\n  \
    \      if (d) insert_here(c, l, r, std::move(*d), pushed);\n      }\n    } else\
    \ {\n      Piece d = split_own(c, k);\n      insert_here(c, l, r, std::move(d),\
    \ pushed);\n    }\n    pull(c);\n    return c;\n  }\n  void apply_rec(np c, ll\
    \ l, ll r, const A &a) {\n    if (l <= c->lo && c->hi <= r) {\n      tag(c, a);\n\
    \      return;\n    }\n    bool pushed = push(c);\n    if (c->l && l < c->l->hi\
    \ && c->l->lo < r) {\n      if (!pushed) c->l = clone(c->l);\n      apply_rec(c->l,\
    \ l, r, a);\n    }\n    if (l < c->d.r && c->d.l < r) {\n      assert(l <= c->d.l\
    \ && c->d.r <= r);\n      tag_own(c, a);\n    }\n    if (c->r && l < c->r->hi\
    \ && c->r->lo < r) {\n      if (!pushed) c->r = clone(c->r);\n      apply_rec(c->r,\
    \ l, r, a);\n    }\n    pull(c);\n  }\n  template <bool MULTIPLY>\n  void point_rec(np\
    \ c, ll i, const X &x) {\n    bool pushed = push(c);\n    if (i < c->d.l) {\n\
    \      if (!pushed) c->l = clone(c->l);\n      point_rec<MULTIPLY>(c->l, i, x);\n\
    \    } else if (c->d.r <= i) {\n      if (!pushed) c->r = clone(c->r);\n     \
    \ point_rec<MULTIPLY>(c->r, i, x);\n    } else {\n      assert(c->d.l == i &&\
    \ c->d.r == i + 1);\n      if constexpr (MULTIPLY)\n        c->d.x = MX::op(c->d.x,\
    \ x);\n      else\n        c->d.x = x;\n      // \u9577\u3055 1 \u306E\u533A\u9593\
    \u306F\u5206\u5272\u3055\u308C\u306A\u3044\u306E\u3067\u3001own \u306F\u4E0D\u8981\
    \n      c->d.own = MA::id();\n    }\n    pull(c);\n  }\n  X piece_prod(const Piece\
    \ &d, ll l, ll r, const A &a) {\n    if (l == d.l && r == d.r) return AM::act(d.x,\
    \ a, r - l);\n    return AM::act(default_prod(l, r), MA::op(d.own, a), r - l);\n\
    \  }\n  void prod_rec(np c, ll l, ll r, A a, X &x) {\n    if (!c || r <= c->lo\
    \ || c->hi <= l) return;\n    if (l <= c->lo && c->hi <= r) {\n      x = MX::op(x,\
    \ AM::act(c->x, a, c->hi - c->lo));\n      return;\n    }\n    A b = MA::op(c->lazy,\
    \ a);\n    prod_rec(c->l, l, r, b, x);\n    ll L = max(l, c->d.l), R = min(r,\
    \ c->d.r);\n    if (L < R) x = MX::op(x, piece_prod(c->d, L, R, a));\n    prod_rec(c->r,\
    \ l, r, b, x);\n  }\n  template <typename F>\n  ll max_right_rec(np c, const F\
    \ &check, ll l, A a, X &x) {\n    if (!c || c->hi <= l) return R0;\n    if (l\
    \ <= c->lo) {\n      X y = MX::op(x, AM::act(c->x, a, c->hi - c->lo));\n     \
    \ if (check(y)) {\n        x = y;\n        return R0;\n      }\n    }\n    A b\
    \ = MA::op(c->lazy, a);\n    ll k = max_right_rec(c->l, check, l, b, x);\n   \
    \ if (k != R0) return k;\n    if (l < c->d.r) {\n      ll L = max(l, c->d.l),\
    \ R = c->d.r;\n      X y = MX::op(x, piece_prod(c->d, L, R, a));\n      if (!check(y))\
    \ {\n        ll ok = L, ng = R;\n        while (ng - ok > 1) {\n          ll m\
    \ = ok + (ng - ok) / 2;\n          if (check(MX::op(x, piece_prod(c->d, L, m,\
    \ a))))\n            ok = m;\n          else\n            ng = m;\n        }\n\
    \        return ok;\n      }\n      x = y;\n    }\n    return max_right_rec(c->r,\
    \ check, l, b, x);\n  }\n  template <typename F>\n  ll min_left_rec(np c, const\
    \ F &check, ll r, A a, X &x) {\n    if (!c || r <= c->lo) return L0;\n    if (c->hi\
    \ <= r) {\n      X y = MX::op(AM::act(c->x, a, c->hi - c->lo), x);\n      if (check(y))\
    \ {\n        x = y;\n        return L0;\n      }\n    }\n    A b = MA::op(c->lazy,\
    \ a);\n    ll k = min_left_rec(c->r, check, r, b, x);\n    if (k != L0) return\
    \ k;\n    if (c->d.l < r) {\n      ll L = c->d.l, R = min(r, c->d.r);\n      X\
    \ y = MX::op(piece_prod(c->d, L, R, a), x);\n      if (!check(y)) {\n        ll\
    \ ng = L, ok = R;\n        while (ok - ng > 1) {\n          ll m = ng + (ok -\
    \ ng) / 2;\n          if (check(MX::op(piece_prod(c->d, m, R, a), x)))\n     \
    \       ok = m;\n          else\n            ng = m;\n        }\n        return\
    \ ok;\n      }\n      x = y;\n    }\n    return min_left_rec(c->l, check, r, b,\
    \ x);\n  }\n};\n"
  code: "#include \"ds/node_pool.hpp\"\n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Sparse_Default_Prod\
    \ {\n  using MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// \u533A\u9593\u306E\u5DE6\u7AEF\u3092\
    \u30AD\u30FC\u3068\u3057\u3066\u3001Dynamic_SegTree_Sparse \u3068\u540C\u69D8\u306B\
    \u633F\u5165\u3059\u308B\n// PERSISTENT=false \u3068\u3057\u3066\n// set, multiply,\
    \ apply: \u9AD8\u3005 2 \u30CE\u30FC\u30C9\n// prod, max_right, min_left: \u30CE\
    \u30FC\u30C9\u3092\u8FFD\u52A0\u3057\u306A\u3044\ntemplate <typename ActedMonoid,\
    \ bool PERSISTENT,\n    typename DefaultProd =\n        Dynamic_Lazy_SegTree_Sparse_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree_Sparse {\n  using AM = ActedMonoid;\n  using MX =\
    \ typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename\
    \ AM::X;\n  using A = typename AM::A;\n  using F = DefaultProd;\n  // \u81EA\u8EAB\
    \u306E\u533A\u9593\u3068\u305D\u306E\u533A\u9593\u7A4D\u3001\u7D2F\u7A4D\u4F5C\
    \u7528\n  struct Piece {\n    ll l, r;\n    X x;\n    A own;\n  };\n  struct Node\
    \ {\n    Node *l, *r;\n    Piece d;\n    ll lo, hi;  // \u90E8\u5206\u6728\u5168\
    \u4F53\u306E\u5EA7\u6A19\u7BC4\u56F2\n    X x;        // \u90E8\u5206\u6728\u5168\
    \u4F53\u306E\u533A\u9593\u7A4D\n    A lazy;     // \u5B50\u3078\u306E\u672A\u4F1D\
    \u64AD\u306E\u4F5C\u7528\n  };\n  using np = Node *;\n  F default_prod;\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n\n  Dynamic_Lazy_SegTree_Sparse(ll L0, ll R0, F default_prod\
    \ = F{})\n      : default_prod(std::move(default_prod)), L0(L0), R0(R0) {\n  \
    \  assert(-infty<ll> <= L0 && L0 <= R0 && R0 <= infty<ll>);\n  }\n\n  np new_root()\
    \ { return L0 == R0 ? nullptr : make(piece(L0, R0, MA::id())); }\n  np new_node()\
    \ { return new_root(); }\n  np new_node(const vc<X> &dat) {\n    assert(L0 ==\
    \ 0 && R0 == ll(dat.size()));\n    auto dfs = [&](auto &dfs, ll l, ll r, ll a,\
    \ ll b) -> np {\n      if (a == b) return nullptr;\n      ll m = l + (r - l) /\
    \ 2;\n      ll k = min(max(m, a), b - 1);\n      np c = make(Piece{k, k + 1, dat[k],\
    \ MA::id()});\n      c->l = dfs(dfs, l, m, a, k);\n      c->r = dfs(dfs, m, r,\
    \ k + 1, b);\n      pull(c);\n      return c;\n    };\n    return dfs(dfs, L0,\
    \ R0, L0, R0);\n  }\n  void reset() { pool.reset(); }\n\n  X prod(np root, ll\
    \ l, ll r) {\n    assert(L0 <= l && l <= r && r <= R0);\n    X x = MX::id();\n\
    \    if (root && l < r) prod_rec(root, l, r, MA::id(), x);\n    return x;\n  }\n\
    \  X prod_all(np root) { return root ? root->x : MX::id(); }\n  X get(np root,\
    \ ll i) { return prod(root, i, i + 1); }\n\n  np apply(np root, ll l, ll r, const\
    \ A &a) {\n    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n\
    \    assert(root);\n    root = ensure(root, L0, R0, l);\n    root = ensure(root,\
    \ L0, R0, r);\n    root = clone(root);\n    apply_rec(root, l, r, a);\n    return\
    \ root;\n  }\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = ensure(root, L0, R0, i);\n    root = ensure(root,\
    \ L0, R0, i + 1);\n    root = clone(root);\n    point_rec<false>(root, i, x);\n\
    \    return root;\n  }\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = ensure(root, L0, R0, i);\n    root = ensure(root,\
    \ L0, R0, i + 1);\n    root = clone(root);\n    point_rec<true>(root, i, x);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    X x = MX::id();\n\
    \    return max_right_rec(root, check, L, MA::id(), x);\n  }\n  template <typename\
    \ F>\n  ll min_left(np root, F check, ll R) {\n    assert(L0 <= R && R <= R0 &&\
    \ check(MX::id()));\n    X x = MX::id();\n    return min_left_rec(root, check,\
    \ R, MA::id(), x);\n  }\n\n private:\n  np clone(np c) {\n    if constexpr (PERSISTENT)\
    \ {\n      if (c) return pool.clone(c);\n    }\n    return c;\n  }\n  Piece piece(ll\
    \ l, ll r, const A &a) {\n    return {l, r, AM::act(default_prod(l, r), a, r -\
    \ l), a};\n  }\n  np make(const Piece &d) {\n    np c = pool.create();\n    c->l\
    \ = c->r = nullptr;\n    c->d = d;\n    c->lo = d.l, c->hi = d.r;\n    c->x =\
    \ d.x, c->lazy = MA::id();\n    return c;\n  }\n  void tag_own(np c, const A &a)\
    \ {\n    Piece &d = c->d;\n    d.x = AM::act(d.x, a, d.r - d.l);\n    d.own =\
    \ MA::op(d.own, a);\n  }\n  void tag(np c, const A &a) {\n    c->x = AM::act(c->x,\
    \ a, c->hi - c->lo);\n    tag_own(c, a);\n    c->lazy = MA::op(c->lazy, a);\n\
    \  }\n  bool push(np c) {\n    if (c->lazy == MA::id()) return false;\n    if\
    \ (c->l) {\n      c->l = clone(c->l);\n      tag(c->l, c->lazy);\n    }\n    if\
    \ (c->r) {\n      c->r = clone(c->r);\n      tag(c->r, c->lazy);\n    }\n    c->lazy\
    \ = MA::id();\n    return true;\n  }\n  void pull(np c) {\n    c->lo = c->l ?\
    \ c->l->lo : c->d.l;\n    c->hi = c->r ? c->r->hi : c->d.r;\n    c->x = c->d.x;\n\
    \    if (c->l) c->x = MX::op(c->l->x, c->x);\n    if (c->r) c->x = MX::op(c->x,\
    \ c->r->x);\n  }\n  // \u533A\u9593\u306E\u5DE6\u7AEF\u3092\u30AD\u30FC\u3068\u3057\
    \u3066\u633F\u5165\u3059\u308B\uFF08Dynamic_SegTree_Sparse \u3068\u540C\u69D8\uFF09\
    \n  np insert(np c, ll l, ll r, Piece d, bool owned) {\n    if (!c) return make(d);\n\
    \    if (!owned) c = clone(c);\n    bool pushed = push(c);\n    insert_here(c,\
    \ l, r, std::move(d), pushed);\n    pull(c);\n    return c;\n  }\n  void insert_here(np\
    \ c, ll l, ll r, Piece d, bool pushed) {\n    ll m = l + (r - l) / 2;\n    assert(l\
    \ <= d.l && d.l < r && d.l != c->d.l);\n    if (d.l < m) {\n      if (c->d.l <\
    \ d.l) swap(c->d, d);\n      c->l = insert(c->l, l, m, std::move(d), pushed);\n\
    \    } else {\n      if (d.l < c->d.l) swap(c->d, d);\n      c->r = insert(c->r,\
    \ m, r, std::move(d), pushed);\n    }\n  }\n  Piece split_own(np c, ll k) {\n\
    \    assert(c->d.l < k && k < c->d.r);\n    Piece d = piece(k, c->d.r, c->d.own);\n\
    \    c->d = piece(c->d.l, k, c->d.own);\n    return d;\n  }\n  // k \u3092\u542B\
    \u3080\u533A\u9593\u3092\u5206\u5272\u3057\u3001\u53F3\u5074\u306E\u533A\u9593\
    \u3092 out \u306B\u53D6\u308A\u51FA\u3059\n  // \u53D6\u308A\u51FA\u3057\u305F\
    \u533A\u9593\u306F insert_here \u306B\u3088\u3063\u3066\u623B\u3059\n  np cut(np\
    \ c, ll l, ll r, ll k, optional<Piece> &out, bool owned) {\n    assert(c);\n \
    \   if (k == c->lo || k == c->hi || k == c->d.l || k == c->d.r) return c;\n  \
    \  if (!owned) c = clone(c);\n    bool pushed = push(c);\n    ll m = l + (r -\
    \ l) / 2;\n    if (k < c->d.l)\n      c->l = cut(c->l, l, m, k, out, pushed);\n\
    \    else if (c->d.r < k)\n      c->r = cut(c->r, m, r, k, out, pushed);\n   \
    \ else\n      out = split_own(c, k);\n    pull(c);\n    return c;\n  }\n  // k\
    \ \u3092\u533A\u9593\u306E\u5883\u754C\u306B\u3059\u308B\u3002cut \u3068 insert\
    \ \u306E\u5171\u901A\u3059\u308B\u7D4C\u8DEF\u306F\u4E00\u5EA6\u3060\u3051\u305F\
    \u3069\u308B\n  // \u30AD\u30FC\u306E\u4E8C\u5206\u4F4D\u7F6E\u3068\u3001k \u3092\
    \u542B\u3080\u533A\u9593\u306E\u4F4D\u7F6E\u306F\u4E00\u81F4\u3059\u308B\u3068\
    \u306F\u9650\u3089\u306A\u3044\n  np ensure(np c, ll l, ll r, ll k, bool owned\
    \ = false) {\n    assert(c);\n    if (k == c->lo || k == c->hi || k == c->d.l\
    \ || k == c->d.r) return c;\n    if (!owned) c = clone(c);\n    bool pushed =\
    \ push(c);\n    ll m = l + (r - l) / 2;\n    if (k < c->d.l) {\n      if (k <\
    \ m)\n        c->l = ensure(c->l, l, m, k, pushed);\n      else {\n        optional<Piece>\
    \ d;\n        c->l = cut(c->l, l, m, k, d, pushed);\n        if (d) insert_here(c,\
    \ l, r, std::move(*d), pushed);\n      }\n    } else if (c->d.r < k) {\n     \
    \ if (m <= k)\n        c->r = ensure(c->r, m, r, k, pushed);\n      else {\n \
    \       optional<Piece> d;\n        c->r = cut(c->r, m, r, k, d, pushed);\n  \
    \      if (d) insert_here(c, l, r, std::move(*d), pushed);\n      }\n    } else\
    \ {\n      Piece d = split_own(c, k);\n      insert_here(c, l, r, std::move(d),\
    \ pushed);\n    }\n    pull(c);\n    return c;\n  }\n  void apply_rec(np c, ll\
    \ l, ll r, const A &a) {\n    if (l <= c->lo && c->hi <= r) {\n      tag(c, a);\n\
    \      return;\n    }\n    bool pushed = push(c);\n    if (c->l && l < c->l->hi\
    \ && c->l->lo < r) {\n      if (!pushed) c->l = clone(c->l);\n      apply_rec(c->l,\
    \ l, r, a);\n    }\n    if (l < c->d.r && c->d.l < r) {\n      assert(l <= c->d.l\
    \ && c->d.r <= r);\n      tag_own(c, a);\n    }\n    if (c->r && l < c->r->hi\
    \ && c->r->lo < r) {\n      if (!pushed) c->r = clone(c->r);\n      apply_rec(c->r,\
    \ l, r, a);\n    }\n    pull(c);\n  }\n  template <bool MULTIPLY>\n  void point_rec(np\
    \ c, ll i, const X &x) {\n    bool pushed = push(c);\n    if (i < c->d.l) {\n\
    \      if (!pushed) c->l = clone(c->l);\n      point_rec<MULTIPLY>(c->l, i, x);\n\
    \    } else if (c->d.r <= i) {\n      if (!pushed) c->r = clone(c->r);\n     \
    \ point_rec<MULTIPLY>(c->r, i, x);\n    } else {\n      assert(c->d.l == i &&\
    \ c->d.r == i + 1);\n      if constexpr (MULTIPLY)\n        c->d.x = MX::op(c->d.x,\
    \ x);\n      else\n        c->d.x = x;\n      // \u9577\u3055 1 \u306E\u533A\u9593\
    \u306F\u5206\u5272\u3055\u308C\u306A\u3044\u306E\u3067\u3001own \u306F\u4E0D\u8981\
    \n      c->d.own = MA::id();\n    }\n    pull(c);\n  }\n  X piece_prod(const Piece\
    \ &d, ll l, ll r, const A &a) {\n    if (l == d.l && r == d.r) return AM::act(d.x,\
    \ a, r - l);\n    return AM::act(default_prod(l, r), MA::op(d.own, a), r - l);\n\
    \  }\n  void prod_rec(np c, ll l, ll r, A a, X &x) {\n    if (!c || r <= c->lo\
    \ || c->hi <= l) return;\n    if (l <= c->lo && c->hi <= r) {\n      x = MX::op(x,\
    \ AM::act(c->x, a, c->hi - c->lo));\n      return;\n    }\n    A b = MA::op(c->lazy,\
    \ a);\n    prod_rec(c->l, l, r, b, x);\n    ll L = max(l, c->d.l), R = min(r,\
    \ c->d.r);\n    if (L < R) x = MX::op(x, piece_prod(c->d, L, R, a));\n    prod_rec(c->r,\
    \ l, r, b, x);\n  }\n  template <typename F>\n  ll max_right_rec(np c, const F\
    \ &check, ll l, A a, X &x) {\n    if (!c || c->hi <= l) return R0;\n    if (l\
    \ <= c->lo) {\n      X y = MX::op(x, AM::act(c->x, a, c->hi - c->lo));\n     \
    \ if (check(y)) {\n        x = y;\n        return R0;\n      }\n    }\n    A b\
    \ = MA::op(c->lazy, a);\n    ll k = max_right_rec(c->l, check, l, b, x);\n   \
    \ if (k != R0) return k;\n    if (l < c->d.r) {\n      ll L = max(l, c->d.l),\
    \ R = c->d.r;\n      X y = MX::op(x, piece_prod(c->d, L, R, a));\n      if (!check(y))\
    \ {\n        ll ok = L, ng = R;\n        while (ng - ok > 1) {\n          ll m\
    \ = ok + (ng - ok) / 2;\n          if (check(MX::op(x, piece_prod(c->d, L, m,\
    \ a))))\n            ok = m;\n          else\n            ng = m;\n        }\n\
    \        return ok;\n      }\n      x = y;\n    }\n    return max_right_rec(c->r,\
    \ check, l, b, x);\n  }\n  template <typename F>\n  ll min_left_rec(np c, const\
    \ F &check, ll r, A a, X &x) {\n    if (!c || r <= c->lo) return L0;\n    if (c->hi\
    \ <= r) {\n      X y = MX::op(AM::act(c->x, a, c->hi - c->lo), x);\n      if (check(y))\
    \ {\n        x = y;\n        return L0;\n      }\n    }\n    A b = MA::op(c->lazy,\
    \ a);\n    ll k = min_left_rec(c->r, check, r, b, x);\n    if (k != L0) return\
    \ k;\n    if (c->d.l < r) {\n      ll L = c->d.l, R = min(r, c->d.r);\n      X\
    \ y = MX::op(piece_prod(c->d, L, R, a), x);\n      if (!check(y)) {\n        ll\
    \ ng = L, ok = R;\n        while (ok - ng > 1) {\n          ll m = ng + (ok -\
    \ ng) / 2;\n          if (check(MX::op(piece_prod(c->d, m, R, a), x)))\n     \
    \       ok = m;\n          else\n            ng = m;\n        }\n        return\
    \ ok;\n      }\n      x = y;\n    }\n    return min_left_rec(c->l, check, r, b,\
    \ x);\n  }\n};\n"
  dependsOn:
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/dynamic_lazy_segtree_sparse.hpp
  requiredBy: []
  timestamp: '2026-11-25 16:46:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/range_affine_range_sum_large_2.test.cpp
documentation_of: ds/segtree/dynamic_lazy_segtree_sparse.hpp
layout: document
redirect_from:
- /library/ds/segtree/dynamic_lazy_segtree_sparse.hpp
- /library/ds/segtree/dynamic_lazy_segtree_sparse.hpp.html
title: ds/segtree/dynamic_lazy_segtree_sparse.hpp
---
