---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/sortable_array.test.cpp
    title: test/1_mytest/sortable_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2809.test.cpp
    title: test/3_yukicoder/2809.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/fastset.hpp\"\n\n\
    // 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr u32\
    \ B = 64;\n  int n = 0, log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int\
    \ n) { build(n); }\n\n  int size() { return n; }\n\n  void fill_one() {\n    int\
    \ cur = n;\n    for (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n\
    \      FOR(i, p) vs[i] = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur\
    \ = (cur + B - 1) / B;\n    }\n  }\n\n  template <typename F>\n  FastSet(int n,\
    \ F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    seg.clear();\n \
    \   n = m;\n    do {\n      seg.push_back(vc<u64>((m + B - 1) / B));\n      m\
    \ = (m + B - 1) / B;\n    } while (m > 1);\n    log = len(seg);\n  }\n  template\
    \ <typename F>\n  void build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i\
    \ / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const {\n    assert(0 <= i && i < n);\n\
    \    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int i) {\n    assert(0\
    \ <= i && i < n);\n    for (int h = 0; h < log; h++) {\n      seg[h][i / B] |=\
    \ u64(1) << (i % B), i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n \
    \ void erase(int i) {\n    assert(0 <= i && i < n);\n    u64 x = 0;\n    for (int\
    \ h = 0; h < log; h++) {\n      seg[h][i / B] &= ~(u64(1) << (i % B));\n     \
    \ seg[h][i / B] |= x << (i % B);\n      x = bool(seg[h][i / B]);\n      i /= B;\n\
    \    }\n  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n) or n\n  int next(int\
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
    \ l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n    return next(l) < r;\n\
    \  }\n\n  // [l, r)\n  template <typename F>\n  void enumerate(int l, int r, F\
    \ f) {\n    assert(0 <= l && l <= r && r <= n);\n    for (int x = next(l); x <\
    \ r; x = next(x + 1)) f(x);\n  }\n\n  void reset() {\n    enumerate(0, n, [&](int\
    \ i) -> void { erase(i); });\n  }\n\n  string to_string() {\n    string s(n, '?');\n\
    \    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\n    return\
    \ s;\n  }\n};\n#line 1 \"ds/node_pool.hpp\"\n// \u30DE\u30EB\u30C1\u30C6\u30B9\
    \u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\u6E08\u307F chunk \u3092\u518D\
    \u5229\u7528\u3059\u308B\ntemplate <class Node>\nstruct Node_Pool {\n  union Slot\
    \ {\n    Node node;\n    Slot* next;\n\n    Slot() {}\n    ~Slot() {}\n  };\n\
    \  using np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 << 12;\n\n  vc<unique_ptr<Slot[]>>\
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
    \    pos = 0;\n  }\n\n private:\n  static vc<unique_ptr<Slot[]>>& chunk_cache()\
    \ {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\u306B\u7834\u68C4\
    \u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\n    static auto*\
    \ cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n  }\n\n  void alloc_chunk()\
    \ {\n    auto& cache = chunk_cache();\n    if (cache.empty()) {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    } else {\n      chunks.eb(std::move(cache.back()));\n      cache.pop_back();\n\
    \    }\n  }\n\n  Slot* new_slot() {\n    if (free_head) {\n      Slot* s = free_head;\n\
    \      free_head = free_head->next;\n      return s;\n    }\n\n    if (chunk_id\
    \ == len(chunks)) alloc_chunk();\n\n    Slot* s = &chunks[chunk_id][pos++];\n\
    \    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n      pos = 0;\n    }\n    return\
    \ s;\n  }\n};\n#line 3 \"ds/sortable_array.hpp\"\n\n// int \u5217\u3092\u6271\u3046\
    . key \u306E\u91CD\u8907\u53EF.\nstruct Sortable_Array {\n  const int N, KEY_MAX;\n\
    \n  struct Node {\n    int size;\n    Node *l, *r;\n  };\n  Node_Pool<Node> pool;\n\
    \  using np = Node*;\n\n  FastSet ss;       // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\
    \u4F53\u3092\u8868\u3059 fastset\n  vector<np> root;  // \u533A\u9593\u306E\u5DE6\
    \u7AEF\u306B\u3001dynamic segtree \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool>\
    \ rev;\n\n  Sortable_Array(int NODES, int KEY_MAX, vector<int> key)\n      : N(key.size()),\
    \ KEY_MAX(KEY_MAX), ss(key.size()) {\n    init(key);\n  }\n\n  void set(int i,\
    \ int key) {\n    assert(0 <= key && key < KEY_MAX);\n    split_at(i), split_at(i\
    \ + 1);\n    rev[i] = 0, root[i] = new_node(0);\n    set_rec(root[i], 0, KEY_MAX,\
    \ key);\n  }\n\n  void sort_inc(int l, int r) {\n    if (l == r) return;\n   \
    \ split_at(l), split_at(r);\n    while (1) {\n      np c = root[l];\n      int\
    \ i = ss.next(l + 1);\n      if (i == r) break;\n      root[l] = merge(0, KEY_MAX,\
    \ c, root[i]);\n      ss.erase(i);\n    }\n    rev[l] = 0;\n  };\n\n  void sort_dec(int\
    \ l, int r) {\n    if (l == r) return;\n    sort_inc(l, r), rev[l] = 1;\n  };\n\
    \n  vc<int> get_all() {\n    vector<int> key;\n    key.reserve(N);\n    auto dfs\
    \ = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n      if (!n || !n->size)\
    \ return;\n      if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n        return;\n\
    \      }\n      int m = (l + r) / 2;\n      if (!rev) {\n        dfs(dfs, n->l,\
    \ l, m, rev), dfs(dfs, n->r, m, r, rev);\n      }\n      if (rev) {\n        dfs(dfs,\
    \ n->r, m, r, rev), dfs(dfs, n->l, l, m, rev);\n      }\n    };\n    for (int\
    \ i = 0; i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n\
    \    }\n    return key;\n  }\n\n  int get(int idx) {\n    auto dfs = [&](auto&\
    \ dfs, np n, int l, int r, int k) -> int {\n      if (r == l + 1) {\n        return\
    \ l;\n      }\n      int m = (l + r) / 2;\n      int s = (n->l ? n->l->size :\
    \ 0);\n      if (k < s) return dfs(dfs, n->l, l, m, k);\n      return dfs(dfs,\
    \ n->r, m, r, k - s);\n    };\n    int i = ss.prev(idx);\n    int k = idx - i;\n\
    \    int s = root[i]->size;\n    if (rev[i]) k = s - 1 - k;\n    return dfs(dfs,\
    \ root[i], 0, KEY_MAX, k);\n  }\n\n private:\n  void init(vector<int>& key) {\n\
    \    rev.assign(N, 0), root.clear(), root.reserve(N);\n    ss.build(N, [&](int\
    \ i) -> int { return 1; });\n    for (int i = 0; i < N; ++i) {\n      root.eb(new_node(0));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n      root[a] = nl,\
    \ root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n      auto [nl, nr]\
    \ = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr, root[x] = nl;\n  \
    \    rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n    auto key = get_all();\n\
    \    pool.reset();\n    init(key);\n  }\n\n  np new_node(int size) {\n    np c\
    \ = pool.create();\n    c->l = c->r = nullptr, c->size = size;\n    return c;\n\
    \  }\n\n  pair<np, np> split(np n, int l, int r, int k) {\n    if (k == 0) {\n\
    \      return {nullptr, n};\n    }\n    if (k == n->size) {\n      return {n,\
    \ nullptr};\n    }\n    if (r == l + 1) {\n      int s = n->size;\n      n->size\
    \ = k;\n      Node* b = new_node(s - k);\n      return {n, b};\n    }\n    int\
    \ s = (n->l ? n->l->size : 0);\n    Node* b = new_node(0);\n    int m = (l + r)\
    \ / 2;\n    if (k <= s) {\n      auto [nl, nr] = split(n->l, l, m, k);\n     \
    \ b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if (k > s) {\n\
    \      auto [nl, nr] = split(n->r, m, r, k - s);\n      n->l = n->l, n->r = nl,\
    \ b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return {n,\
    \ b};\n  }\n\n  np merge(int l, int r, np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    if (r == l + 1) {\n      a->size += b->size;\n   \
    \   return a;\n    }\n    int m = (l + r) / 2;\n    a->l = merge(l, m, a->l, b->l),\
    \ a->r = merge(m, r, a->r, b->r);\n    update(a);\n    return a;\n  }\n\n  void\
    \ update(np n) {\n    if (!(n->l) && !(n->r)) {\n      return;\n    }\n    if\
    \ (!(n->l)) {\n      n->size = n->r->size;\n      return;\n    }\n    if (!(n->r))\
    \ {\n      n->size = n->l->size;\n      return;\n    }\n    n->size = n->l->size\
    \ + n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k) {\n    if (r\
    \ == l + 1) {\n      n->size = 1;\n      return;\n    }\n    int m = (l + r) /\
    \ 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node(0);\n      set_rec(n->l,\
    \ l, m, k);\n    }\n    if (m <= k) {\n      if (!(n->r)) n->r = new_node(0);\n\
    \      set_rec(n->r, m, r, k);\n    }\n    update(n);\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n#include \"ds/node_pool.hpp\"\n\n// int \u5217\
    \u3092\u6271\u3046. key \u306E\u91CD\u8907\u53EF.\nstruct Sortable_Array {\n \
    \ const int N, KEY_MAX;\n\n  struct Node {\n    int size;\n    Node *l, *r;\n\
    \  };\n  Node_Pool<Node> pool;\n  using np = Node*;\n\n  FastSet ss;       //\
    \ \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n  vector<np>\
    \ root;  // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree \u306E node\
    \ \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_Array(int NODES,\
    \ int KEY_MAX, vector<int> key)\n      : N(key.size()), KEY_MAX(KEY_MAX), ss(key.size())\
    \ {\n    init(key);\n  }\n\n  void set(int i, int key) {\n    assert(0 <= key\
    \ && key < KEY_MAX);\n    split_at(i), split_at(i + 1);\n    rev[i] = 0, root[i]\
    \ = new_node(0);\n    set_rec(root[i], 0, KEY_MAX, key);\n  }\n\n  void sort_inc(int\
    \ l, int r) {\n    if (l == r) return;\n    split_at(l), split_at(r);\n    while\
    \ (1) {\n      np c = root[l];\n      int i = ss.next(l + 1);\n      if (i ==\
    \ r) break;\n      root[l] = merge(0, KEY_MAX, c, root[i]);\n      ss.erase(i);\n\
    \    }\n    rev[l] = 0;\n  };\n\n  void sort_dec(int l, int r) {\n    if (l ==\
    \ r) return;\n    sort_inc(l, r), rev[l] = 1;\n  };\n\n  vc<int> get_all() {\n\
    \    vector<int> key;\n    key.reserve(N);\n    auto dfs = [&](auto& dfs, np n,\
    \ int l, int r, bool rev) -> void {\n      if (!n || !n->size) return;\n     \
    \ if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n        return;\n      }\n\
    \      int m = (l + r) / 2;\n      if (!rev) {\n        dfs(dfs, n->l, l, m, rev),\
    \ dfs(dfs, n->r, m, r, rev);\n      }\n      if (rev) {\n        dfs(dfs, n->r,\
    \ m, r, rev), dfs(dfs, n->l, l, m, rev);\n      }\n    };\n    for (int i = 0;\
    \ i < N; ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n   \
    \ }\n    return key;\n  }\n\n  int get(int idx) {\n    auto dfs = [&](auto& dfs,\
    \ np n, int l, int r, int k) -> int {\n      if (r == l + 1) {\n        return\
    \ l;\n      }\n      int m = (l + r) / 2;\n      int s = (n->l ? n->l->size :\
    \ 0);\n      if (k < s) return dfs(dfs, n->l, l, m, k);\n      return dfs(dfs,\
    \ n->r, m, r, k - s);\n    };\n    int i = ss.prev(idx);\n    int k = idx - i;\n\
    \    int s = root[i]->size;\n    if (rev[i]) k = s - 1 - k;\n    return dfs(dfs,\
    \ root[i], 0, KEY_MAX, k);\n  }\n\n private:\n  void init(vector<int>& key) {\n\
    \    rev.assign(N, 0), root.clear(), root.reserve(N);\n    ss.build(N, [&](int\
    \ i) -> int { return 1; });\n    for (int i = 0; i < N; ++i) {\n      root.eb(new_node(0));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n      root[a] = nl,\
    \ root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n      auto [nl, nr]\
    \ = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr, root[x] = nl;\n  \
    \    rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n    auto key = get_all();\n\
    \    pool.reset();\n    init(key);\n  }\n\n  np new_node(int size) {\n    np c\
    \ = pool.create();\n    c->l = c->r = nullptr, c->size = size;\n    return c;\n\
    \  }\n\n  pair<np, np> split(np n, int l, int r, int k) {\n    if (k == 0) {\n\
    \      return {nullptr, n};\n    }\n    if (k == n->size) {\n      return {n,\
    \ nullptr};\n    }\n    if (r == l + 1) {\n      int s = n->size;\n      n->size\
    \ = k;\n      Node* b = new_node(s - k);\n      return {n, b};\n    }\n    int\
    \ s = (n->l ? n->l->size : 0);\n    Node* b = new_node(0);\n    int m = (l + r)\
    \ / 2;\n    if (k <= s) {\n      auto [nl, nr] = split(n->l, l, m, k);\n     \
    \ b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if (k > s) {\n\
    \      auto [nl, nr] = split(n->r, m, r, k - s);\n      n->l = n->l, n->r = nl,\
    \ b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return {n,\
    \ b};\n  }\n\n  np merge(int l, int r, np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    if (r == l + 1) {\n      a->size += b->size;\n   \
    \   return a;\n    }\n    int m = (l + r) / 2;\n    a->l = merge(l, m, a->l, b->l),\
    \ a->r = merge(m, r, a->r, b->r);\n    update(a);\n    return a;\n  }\n\n  void\
    \ update(np n) {\n    if (!(n->l) && !(n->r)) {\n      return;\n    }\n    if\
    \ (!(n->l)) {\n      n->size = n->r->size;\n      return;\n    }\n    if (!(n->r))\
    \ {\n      n->size = n->l->size;\n      return;\n    }\n    n->size = n->l->size\
    \ + n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k) {\n    if (r\
    \ == l + 1) {\n      n->size = 1;\n      return;\n    }\n    int m = (l + r) /\
    \ 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node(0);\n      set_rec(n->l,\
    \ l, m, k);\n    }\n    if (m <= k) {\n      if (!(n->r)) n->r = new_node(0);\n\
    \      set_rec(n->r, m, r, k);\n    }\n    update(n);\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  - other/bit.hpp
  - ds/node_pool.hpp
  isVerificationFile: false
  path: ds/sortable_array.hpp
  requiredBy: []
  timestamp: '2026-09-04 09:44:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/sortable_array.test.cpp
  - test/3_yukicoder/2809.test.cpp
documentation_of: ds/sortable_array.hpp
layout: document
redirect_from:
- /library/ds/sortable_array.hpp
- /library/ds/sortable_array.hpp.html
title: ds/sortable_array.hpp
---
