---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/sort_segtree.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
    title: test/2_library_checker/data_structure/sort_segtree_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"ds/fastset.hpp\"\n\n// 64-ary tree\n// space: (N/63)\
    \ * u64\nstruct FastSet {\n  static constexpr u32 B = 64;\n  int n = 0, log =\
    \ 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int n) { build(n); }\n\n  int\
    \ size() { return n; }\n\n  void fill_one() {\n    int cur = n;\n    for (auto&\
    \ vs : seg) {\n      int p = cur / B, q = cur % B;\n      FOR(i, p) vs[i] = -1ull;\n\
    \      if (q) vs[p] = full_mask(q);\n      cur = (cur + B - 1) / B;\n    }\n \
    \ }\n\n  template <typename F>\n  FastSet(int n, F f) {\n    build(n, f);\n  }\n\
    \n  void build(int m) {\n    seg.clear();\n    n = m;\n    do {\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\n      m = (m + B - 1) / B;\n    } while (m > 1);\n    log =\
    \ len(seg);\n  }\n  template <typename F>\n  void build(int n, F f) {\n    build(n);\n\
    \    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\n    FOR(h, log - 1)\
    \ {\n      FOR(i, len(seg[h])) {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\n      }\n    }\n  }\n\n  bool operator[](int i) const { return\
    \ seg[0][i / B] >> (i % B) & 1; }\n  void insert(int i) {\n    assert(0 <= i &&\
    \ i < n);\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] |= u64(1)\
    \ << (i % B), i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n  void erase(int\
    \ i) {\n    assert(0 <= i && i < n);\n    u64 x = 0;\n    for (int h = 0; h <\
    \ log; h++) {\n      seg[h][i / B] &= ~(u64(1) << (i % B));\n      seg[h][i /\
    \ B] |= x << (i % B);\n      x = bool(seg[h][i / B]);\n      i /= B;\n    }\n\
    \  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int\
    \ i) {\n    assert(i <= n);\n    chmax(i, 0);\n    for (int h = 0; h < log; h++)\
    \ {\n      if (i / B == seg[h].size()) break;\n      u64 d = seg[h][i / B] >>\
    \ (i % B);\n      if (!d) {\n        i = i / B + 1;\n        continue;\n     \
    \ }\n      i += lowbit(d);\n      for (int g = h - 1; g >= 0; g--) {\n       \
    \ i *= B;\n        i += lowbit(seg[g][i / B]);\n      }\n      return i;\n   \
    \ }\n    return n;\n  }\n\n  // max [0,x], or -1\n  int prev(int i) {\n    assert(i\
    \ >= -1);\n    if (i >= n) i = n - 1;\n    for (int h = 0; h < log; h++) {\n \
    \     if (i == -1) break;\n      u64 d = seg[h][i / B] << (63 - i % B);\n    \
    \  if (!d) {\n        i = i / B - 1;\n        continue;\n      }\n      i -= __builtin_clzll(d);\n\
    \      for (int g = h - 1; g >= 0; g--) {\n        i *= B;\n        i += topbit(seg[g][i\
    \ / B]);\n      }\n      return i;\n    }\n    return -1;\n  }\n\n  bool any(int\
    \ l, int r) { return next(l) < r; }\n\n  // [l, r)\n  template <typename F>\n\
    \  void enumerate(int l, int r, F f) {\n    for (int x = next(l); x < r; x = next(x\
    \ + 1)) f(x);\n  }\n\n  void reset() {\n    enumerate(0, n, [&](int i) -> void\
    \ { erase(i); });\n  }\n\n  string to_string() {\n    string s(n, '?');\n    for\
    \ (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return s;\n  }\n\
    };\n#line 1 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n   \
    \ while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R\
    \ & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return\
    \ Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n\
    \      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n   \
    \ return I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class\
    \ F>\n  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n\
    \          }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 1 \"ds/node_pool.hpp\"\n// \u30DE\
    \u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306B\u5F31\u3044\u306E\u3067\
    \ static \u3067\u78BA\u4FDD\u3059\u308B\u3053\u3068\ntemplate <class Node>\nstruct\
    \ Node_Pool {\n  union Slot {\n    Node node;\n    Slot* next;\n\n    Slot() {}\n\
    \    ~Slot() {}\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE\
    \ = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  int chunk_id = 0;\n  int pos\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  template <class... Args>\n  np create(Args&&...\
    \ args) {\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (&s->node) Node(*x);\n  }\n\n  void destroy(np x) {\n    if\
    \ (!x) return;\n    x->~Node();\n    Slot* s = reinterpret_cast<Slot*>(x);\n \
    \   s->next = free_head;\n    free_head = s;\n  }\n\n  // \u5168 node \u3092\u7121\
    \u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\u4FDD\u6E08\u307F chunk \u306F\u89E3\
    \u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\u964D\u306B\u518D\u5229\u7528\u3059\
    \u308B\u3002\n  void reset() {\n    free_head = nullptr;\n    chunk_id = 0;\n\
    \    pos = 0;\n  }\n\n private:\n  void alloc_chunk() { chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\
    \ }\n\n  Slot* new_slot() {\n    if (free_head) {\n      Slot* s = free_head;\n\
    \      free_head = free_head->next;\n      return s;\n    }\n\n    if (chunk_id\
    \ == len(chunks)) alloc_chunk();\n\n    Slot* s = &chunks[chunk_id][pos++];\n\
    \    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n      pos = 0;\n    }\n    return\
    \ s;\n  }\n};\n#line 4 \"ds/segtree/sortable_segtree.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct Sortable_SegTree {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  const int N, KEY_MAX;\n\n  struct Node {\n    X x, rev_x;\n\
    \    int size;\n    Node *l, *r;\n  };\n  Node_Pool<Node> pool;\n  using np =\
    \ Node*;\n\n  FastSet ss;       // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\
    \u8868\u3059 fastset\n  SegTree<MX> seg;  // \u533A\u9593\u3092\u96C6\u7D04\u3057\
    \u305F\u5024\u3092\u533A\u9593\u306E\u5DE6\u7AEF\u306B\u306E\u305B\u305F segtree\n\
    \  vector<np> root;  // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree\
    \ \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_SegTree(int\
    \ KEY_MAX, vector<int> key, vector<X> dat)\n      : N(key.size()), KEY_MAX(KEY_MAX),\
    \ ss(key.size()), seg(dat) {\n    init(key, dat);\n  }\n  void set(int i, int\
    \ key, const X& x) {\n    assert(key < KEY_MAX);\n    split_at(i), split_at(i\
    \ + 1);\n    rev[i] = 0, root[i] = new_node();\n    set_rec(root[i], 0, KEY_MAX,\
    \ key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all() { return seg.prod_all();\
    \ }\n\n  X prod(int l, int r) {\n    split_at(l), split_at(r);\n    return seg.prod(l,\
    \ r);\n  }\n\n  void sort_inc(int l, int r) {\n    split_at(l), split_at(r);\n\
    \    while (1) {\n      np c = root[l];\n      int i = ss.next(l + 1);\n     \
    \ if (i == r) break;\n      root[l] = merge(c, root[i]);\n      ss.erase(i), seg.set(i,\
    \ MX::unit());\n    }\n    rev[l] = 0, seg.set(l, root[l]->x);\n  };\n\n  void\
    \ sort_dec(int l, int r) {\n    sort_inc(l, r), rev[l] = 1;\n    seg.set(l, root[l]->rev_x);\n\
    \  };\n\n  pair<vc<int>, vc<X>> get_all() {\n    vector<int> key;\n    vector<X>\
    \ dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto dfs = [&](auto& dfs,\
    \ np n, int l, int r, bool rev) -> void {\n      if (!n) return;\n      if (r\
    \ == l + 1) {\n        key.eb(l), dat.eb(n->x);\n        return;\n      }\n  \
    \    int m = (l + r) / 2;\n      if (!rev) {\n        dfs(dfs, n->l, l, m, rev),\
    \ dfs(dfs, n->r, m, r, rev);\n      }\n      if (rev) {\n        dfs(dfs, n->r,\
    \ m, r, rev), dfs(dfs, n->l, l, m, rev);\n      }\n    };\n    for (int i = 0;\
    \ i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n   \
    \ }\n    return {key, dat};\n  }\n\n private:\n  void init(vector<int>& key, vector<X>&\
    \ dat) {\n    rev.assign(N, 0), root.clear(), root.reserve(N);\n    seg.build(N,\
    \ [&](int i) -> X { return dat[i]; });\n    for (int i = 0; i < N; ++i) {\n  \
    \    ss.insert(i);\n      root.eb(new_node(MX::unit()));\n      assert(key[i]\
    \ < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n    }\n  }\n\
    \n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a = ss.prev(x),\
    \ b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n      auto [nl,\
    \ nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n      rev[a]\
    \ = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n    }\
    \ else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr, root[x]\
    \ = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x), seg.set(x,\
    \ root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    auto [key, dat] = get_all();\n\
    \    pool.reset();\n    init(key, dat);\n  }\n\n  np new_node(X x = MX::unit())\
    \ {\n    np c = pool.create();\n    c->x = c->rev_x = x;\n    c->l = c->r = nullptr;\n\
    \    c->size = 1;\n    return c;\n  }\n\n  pair<np, np> split(np n, int k) {\n\
    \    if (k == 0) {\n      return {nullptr, n};\n    }\n    if (k == n->size) {\n\
    \      return {n, nullptr};\n    }\n    int s = (n->l ? n->l->size : 0);\n   \
    \ Node* b = new_node();\n    if (k <= s) {\n      auto [nl, nr] = split(n->l,\
    \ k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if\
    \ (k > s) {\n      auto [nl, nr] = split(n->r, k - s);\n      n->l = n->l, n->r\
    \ = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return\
    \ {n, b};\n  }\n\n  np merge(np a, np b) {\n    if (!a) return b;\n    if (!b)\
    \ return a;\n    a->l = merge(a->l, b->l), a->r = merge(a->r, b->r);\n    update(a);\n\
    \    return a;\n  }\n\n  void update(np n) {\n    if (!(n->l) && !(n->r)) {\n\
    \      return;\n    }\n    if (!(n->l)) {\n      n->x = n->r->x, n->rev_x = n->r->rev_x,\
    \ n->size = n->r->size;\n      return;\n    }\n    if (!(n->r)) {\n      n->x\
    \ = n->l->x, n->rev_x = n->l->rev_x, n->size = n->l->size;\n      return;\n  \
    \  }\n    n->x = MX::op(n->l->x, n->r->x);\n    n->rev_x = MX::op(n->r->rev_x,\
    \ n->l->rev_x);\n    n->size = n->l->size + n->r->size;\n  }\n\n  void set_rec(np\
    \ n, int l, int r, int k, const X& x) {\n    if (r == l + 1) {\n      n->x = n->rev_x\
    \ = x;\n      return;\n    }\n    int m = (l + r) / 2;\n    if (k < m) {\n   \
    \   if (!(n->l)) n->l = new_node();\n      set_rec(n->l, l, m, k, x);\n    }\n\
    \    if (m <= k) {\n      if (!(n->r)) n->r = new_node();\n      set_rec(n->r,\
    \ m, r, k, x);\n    }\n    update(n);\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n#include \"ds/segtree/segtree.hpp\"\n#include\
    \ \"ds/node_pool.hpp\"\n\ntemplate <typename Monoid>\nstruct Sortable_SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  const int N,\
    \ KEY_MAX;\n\n  struct Node {\n    X x, rev_x;\n    int size;\n    Node *l, *r;\n\
    \  };\n  Node_Pool<Node> pool;\n  using np = Node*;\n\n  FastSet ss;       //\
    \ \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n  SegTree<MX>\
    \ seg;  // \u533A\u9593\u3092\u96C6\u7D04\u3057\u305F\u5024\u3092\u533A\u9593\u306E\
    \u5DE6\u7AEF\u306B\u306E\u305B\u305F segtree\n  vector<np> root;  // \u533A\u9593\
    \u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree \u306E node \u3092\u4E57\u305B\u308B\
    \n  vector<bool> rev;\n\n  Sortable_SegTree(int KEY_MAX, vector<int> key, vector<X>\
    \ dat)\n      : N(key.size()), KEY_MAX(KEY_MAX), ss(key.size()), seg(dat) {\n\
    \    init(key, dat);\n  }\n  void set(int i, int key, const X& x) {\n    assert(key\
    \ < KEY_MAX);\n    split_at(i), split_at(i + 1);\n    rev[i] = 0, root[i] = new_node();\n\
    \    set_rec(root[i], 0, KEY_MAX, key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all()\
    \ { return seg.prod_all(); }\n\n  X prod(int l, int r) {\n    split_at(l), split_at(r);\n\
    \    return seg.prod(l, r);\n  }\n\n  void sort_inc(int l, int r) {\n    split_at(l),\
    \ split_at(r);\n    while (1) {\n      np c = root[l];\n      int i = ss.next(l\
    \ + 1);\n      if (i == r) break;\n      root[l] = merge(c, root[i]);\n      ss.erase(i),\
    \ seg.set(i, MX::unit());\n    }\n    rev[l] = 0, seg.set(l, root[l]->x);\n  };\n\
    \n  void sort_dec(int l, int r) {\n    sort_inc(l, r), rev[l] = 1;\n    seg.set(l,\
    \ root[l]->rev_x);\n  };\n\n  pair<vc<int>, vc<X>> get_all() {\n    vector<int>\
    \ key;\n    vector<X> dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto\
    \ dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n      if (!n)\
    \ return;\n      if (r == l + 1) {\n        key.eb(l), dat.eb(n->x);\n       \
    \ return;\n      }\n      int m = (l + r) / 2;\n      if (!rev) {\n        dfs(dfs,\
    \ n->l, l, m, rev), dfs(dfs, n->r, m, r, rev);\n      }\n      if (rev) {\n  \
    \      dfs(dfs, n->r, m, r, rev), dfs(dfs, n->l, l, m, rev);\n      }\n    };\n\
    \    for (int i = 0; i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX,\
    \ rev[i]);\n    }\n    return {key, dat};\n  }\n\n private:\n  void init(vector<int>&\
    \ key, vector<X>& dat) {\n    rev.assign(N, 0), root.clear(), root.reserve(N);\n\
    \    seg.build(N, [&](int i) -> X { return dat[i]; });\n    for (int i = 0; i\
    \ < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(MX::unit()));\n   \
    \   assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n\
    \    } else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x),\
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    auto [key,\
    \ dat] = get_all();\n    pool.reset();\n    init(key, dat);\n  }\n\n  np new_node(X\
    \ x = MX::unit()) {\n    np c = pool.create();\n    c->x = c->rev_x = x;\n   \
    \ c->l = c->r = nullptr;\n    c->size = 1;\n    return c;\n  }\n\n  pair<np, np>\
    \ split(np n, int k) {\n    if (k == 0) {\n      return {nullptr, n};\n    }\n\
    \    if (k == n->size) {\n      return {n, nullptr};\n    }\n    int s = (n->l\
    \ ? n->l->size : 0);\n    Node* b = new_node();\n    if (k <= s) {\n      auto\
    \ [nl, nr] = split(n->l, k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r =\
    \ nullptr;\n    }\n    if (k > s) {\n      auto [nl, nr] = split(n->r, k - s);\n\
    \      n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n),\
    \ update(b);\n    return {n, b};\n  }\n\n  np merge(np a, np b) {\n    if (!a)\
    \ return b;\n    if (!b) return a;\n    a->l = merge(a->l, b->l), a->r = merge(a->r,\
    \ b->r);\n    update(a);\n    return a;\n  }\n\n  void update(np n) {\n    if\
    \ (!(n->l) && !(n->r)) {\n      return;\n    }\n    if (!(n->l)) {\n      n->x\
    \ = n->r->x, n->rev_x = n->r->rev_x, n->size = n->r->size;\n      return;\n  \
    \  }\n    if (!(n->r)) {\n      n->x = n->l->x, n->rev_x = n->l->rev_x, n->size\
    \ = n->l->size;\n      return;\n    }\n    n->x = MX::op(n->l->x, n->r->x);\n\
    \    n->rev_x = MX::op(n->r->rev_x, n->l->rev_x);\n    n->size = n->l->size +\
    \ n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k, const X& x) {\n\
    \    if (r == l + 1) {\n      n->x = n->rev_x = x;\n      return;\n    }\n   \
    \ int m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node();\n\
    \      set_rec(n->l, l, m, k, x);\n    }\n    if (m <= k) {\n      if (!(n->r))\
    \ n->r = new_node();\n      set_rec(n->r, m, r, k, x);\n    }\n    update(n);\n\
    \  }\n};"
  dependsOn:
  - ds/fastset.hpp
  - other/bit.hpp
  - ds/segtree/segtree.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/segtree/sortable_segtree.hpp
  requiredBy: []
  timestamp: '2026-08-29 08:51:03+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/sort_segtree.test.cpp
  - test/2_library_checker/data_structure/sort_segtree_1.test.cpp
documentation_of: ds/segtree/sortable_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/sortable_segtree.hpp
- /library/ds/segtree/sortable_segtree.hpp.html
title: ds/segtree/sortable_segtree.hpp
---
