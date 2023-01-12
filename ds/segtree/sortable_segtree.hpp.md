---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree.test.cpp
    title: test/library_checker/datastructure/sort_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/sort_segtree_1.test.cpp
    title: test/library_checker/datastructure/sort_segtree_1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n  \
    \    seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1)\
    \ / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool\
    \ operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n\
    \  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int h = 0; h\
    \ < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull d = seg[h][i\
    \ / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1;\
    \ g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n  \
    \    }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\
    \u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if (i < 0) return\
    \ -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g\
    \ >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n    \
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l, r) \u5185\
    \u306E\u8981\u7D20\u3092\u5168\u90E8\u96C6\u3081\u308B\r\n  vector<int> collect(int\
    \ l, int r) {\r\n    vector<int> res;\r\n    int x = l - 1;\r\n    while (1) {\r\
    \n      x = next(x + 1);\r\n      if (x >= r) break;\r\n      res.emplace_back(x);\r\
    \n    }\r\n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    string s;\r\n\
    \    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\
    \n  }\r\n};\r\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\n\
    struct SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n\
    \  SegTree(int n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size)\
    \ update(i);\n  }\n\n  X get(int i) { return dat[size + i]; }\n  vc<X> get_all()\
    \ { return {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int\
    \ i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const\
    \ X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n    X vl =\
    \ Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n    while (L\
    \ < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr\
    \ = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int\
    \ max_right(F check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) { sm = Monoid::op(sm, dat[L++]); }\n        }\n        return L -\
    \ size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n    } while ((L & -L)\
    \ != L);\n    return n;\n  }\n\n  template <class F>\n  int min_left(F check,\
    \ int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R\
    \ == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n    \
    \  --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\
    \u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r} A[i xor x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 3 \"ds/segtree/sortable_segtree.hpp\"\n\ntemplate <typename Monoid,\
    \ int NODES>\nstruct Sortable_SegTree {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  const int N, KEY_MAX;\n\n  struct Node {\n    X x, rev_x;\n\
    \    int size;\n    Node *l, *r;\n  };\n  Node* pool;\n  int pid;\n  using np\
    \ = Node*;\n\n  FastSet ss;      // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\
    \u3092\u8868\u3059 fastset\n  SegTree<MX> seg; // \u533A\u9593\u3092\u96C6\u7D04\
    \u3057\u305F\u5024\u3092\u533A\u9593\u306E\u5DE6\u7AEF\u306B\u306E\u305B\u305F\
    \ segtree\n  vector<np> root; // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic\
    \ segtree \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_SegTree(int\
    \ KEY_MAX, vector<int> key, vector<X> dat)\n      : N(key.size()), KEY_MAX(KEY_MAX),\
    \ pid(0), ss(key.size()), seg(dat) {\n    pool = new Node[NODES];\n    init(key,\
    \ dat);\n  }\n\n  void set(int i, int key, const X& x) {\n    assert(key < KEY_MAX);\n\
    \    split_at(i), split_at(i + 1);\n    rev[i] = 0, root[i] = new_node();\n  \
    \  set_rec(root[i], 0, KEY_MAX, key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all()\
    \ { return seg.prod_all(); }\n\n  X prod(int l, int r) {\n    if (pid > NODES\
    \ * 0.9) rebuild();\n    split_at(l), split_at(r);\n    return seg.prod(l, r);\n\
    \  }\n\n  void sort_inc(int l, int r) {\n    split_at(l), split_at(r);\n    while\
    \ (1) {\n      if (pid > NODES * 0.9) rebuild();\n      np c = root[l];\n    \
    \  int i = ss.next(l + 1);\n      if (i == r) break;\n      root[l] = merge(c,\
    \ root[i]);\n      ss.erase(i), seg.set(i, MX::unit());\n    }\n    rev[l] = 0,\
    \ seg.set(l, root[l]->x);\n  };\n\n  void sort_dec(int l, int r) {\n    if (pid\
    \ > NODES * 0.9) rebuild();\n    sort_inc(l, r), rev[l] = 1;\n    seg.set(l, root[l]->rev_x);\n\
    \  };\n\nprivate:\n  void init(vector<int>& key, vector<X>& dat) {\n    rev.assign(N,\
    \ 0), root.clear(), root.reserve(N);\n    seg.build(N, [&](int i) -> X { return\
    \ dat[i]; });\n    for (int i = 0; i < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(MX::unit()));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n\
    \    } else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x),\
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    vector<int>\
    \ key;\n    vector<X> dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto\
    \ dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n      if (!n)\
    \ return;\n      if (r == l + 1) {\n        key.eb(l), dat.eb(n->x);\n       \
    \ return;\n      }\n      int m = (l + r) / 2;\n      if (!rev) { dfs(dfs, n->l,\
    \ l, m, rev), dfs(dfs, n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r, m,\
    \ r, rev), dfs(dfs, n->l, l, m, rev); }\n    };\n    for (int i = 0; i < N; ++i)\
    \ {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n    assert(int(key.size())\
    \ == N);\n    pid = 0;\n    init(key, dat);\n  }\n\n  np new_node(X x = MX::unit())\
    \ {\n    assert(pid < NODES);\n    pool[pid].x = pool[pid].rev_x = x;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].size = 1;\n    return &(pool[pid++]);\n\
    \  }\n\n  pair<np, np> split(np n, int k) {\n    if (k == 0) { return {nullptr,\
    \ n}; }\n    if (k == n->size) { return {n, nullptr}; }\n    int s = (n->l ? n->l->size\
    \ : 0);\n    Node* b = new_node();\n    if (k <= s) {\n      auto [nl, nr] = split(n->l,\
    \ k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if\
    \ (k > s) {\n      auto [nl, nr] = split(n->r, k - s);\n      n->l = n->l, n->r\
    \ = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return\
    \ {n, b};\n  }\n\n  np merge(np a, np b) {\n    if (!a) return b;\n    if (!b)\
    \ return a;\n    a->l = merge(a->l, b->l), a->r = merge(a->r, b->r);\n    update(a);\n\
    \    return a;\n  }\n\n  void update(np n) {\n    if (!(n->l) && !(n->r)) { return;\
    \ }\n    if (!(n->l)) {\n      n->x = n->r->x, n->rev_x = n->r->rev_x, n->size\
    \ = n->r->size;\n      return;\n    }\n    if (!(n->r)) {\n      n->x = n->l->x,\
    \ n->rev_x = n->l->rev_x, n->size = n->l->size;\n      return;\n    }\n    n->x\
    \ = MX::op(n->l->x, n->r->x);\n    n->rev_x = MX::op(n->r->rev_x, n->l->rev_x);\n\
    \    n->size = n->l->size + n->r->size;\n  }\n\n  void set_rec(np n, int l, int\
    \ r, int k, const X& x) {\n    if (r == l + 1) {\n      n->x = n->rev_x = x;\n\
    \      return;\n    }\n    int m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l))\
    \ n->l = new_node();\n      set_rec(n->l, l, m, k, x);\n    }\n    if (m <= k)\
    \ {\n      if (!(n->r)) n->r = new_node();\n      set_rec(n->r, m, r, k, x);\n\
    \    }\n    update(n);\n  }\n};\n"
  code: "#include \"ds/fastset.hpp\"\n#include \"ds/segtree/segtree.hpp\"\n\ntemplate\
    \ <typename Monoid, int NODES>\nstruct Sortable_SegTree {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  const int N, KEY_MAX;\n\n  struct Node\
    \ {\n    X x, rev_x;\n    int size;\n    Node *l, *r;\n  };\n  Node* pool;\n \
    \ int pid;\n  using np = Node*;\n\n  FastSet ss;      // \u533A\u9593\u306E\u5DE6\
    \u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n  SegTree<MX> seg; // \u533A\u9593\
    \u3092\u96C6\u7D04\u3057\u305F\u5024\u3092\u533A\u9593\u306E\u5DE6\u7AEF\u306B\
    \u306E\u305B\u305F segtree\n  vector<np> root; // \u533A\u9593\u306E\u5DE6\u7AEF\
    \u306B\u3001dynamic segtree \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool>\
    \ rev;\n\n  Sortable_SegTree(int KEY_MAX, vector<int> key, vector<X> dat)\n  \
    \    : N(key.size()), KEY_MAX(KEY_MAX), pid(0), ss(key.size()), seg(dat) {\n \
    \   pool = new Node[NODES];\n    init(key, dat);\n  }\n\n  void set(int i, int\
    \ key, const X& x) {\n    assert(key < KEY_MAX);\n    split_at(i), split_at(i\
    \ + 1);\n    rev[i] = 0, root[i] = new_node();\n    set_rec(root[i], 0, KEY_MAX,\
    \ key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all() { return seg.prod_all();\
    \ }\n\n  X prod(int l, int r) {\n    if (pid > NODES * 0.9) rebuild();\n    split_at(l),\
    \ split_at(r);\n    return seg.prod(l, r);\n  }\n\n  void sort_inc(int l, int\
    \ r) {\n    split_at(l), split_at(r);\n    while (1) {\n      if (pid > NODES\
    \ * 0.9) rebuild();\n      np c = root[l];\n      int i = ss.next(l + 1);\n  \
    \    if (i == r) break;\n      root[l] = merge(c, root[i]);\n      ss.erase(i),\
    \ seg.set(i, MX::unit());\n    }\n    rev[l] = 0, seg.set(l, root[l]->x);\n  };\n\
    \n  void sort_dec(int l, int r) {\n    if (pid > NODES * 0.9) rebuild();\n   \
    \ sort_inc(l, r), rev[l] = 1;\n    seg.set(l, root[l]->rev_x);\n  };\n\nprivate:\n\
    \  void init(vector<int>& key, vector<X>& dat) {\n    rev.assign(N, 0), root.clear(),\
    \ root.reserve(N);\n    seg.build(N, [&](int i) -> X { return dat[i]; });\n  \
    \  for (int i = 0; i < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(MX::unit()));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n\
    \    } else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x),\
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    vector<int>\
    \ key;\n    vector<X> dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto\
    \ dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n      if (!n)\
    \ return;\n      if (r == l + 1) {\n        key.eb(l), dat.eb(n->x);\n       \
    \ return;\n      }\n      int m = (l + r) / 2;\n      if (!rev) { dfs(dfs, n->l,\
    \ l, m, rev), dfs(dfs, n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r, m,\
    \ r, rev), dfs(dfs, n->l, l, m, rev); }\n    };\n    for (int i = 0; i < N; ++i)\
    \ {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n    assert(int(key.size())\
    \ == N);\n    pid = 0;\n    init(key, dat);\n  }\n\n  np new_node(X x = MX::unit())\
    \ {\n    assert(pid < NODES);\n    pool[pid].x = pool[pid].rev_x = x;\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].size = 1;\n    return &(pool[pid++]);\n\
    \  }\n\n  pair<np, np> split(np n, int k) {\n    if (k == 0) { return {nullptr,\
    \ n}; }\n    if (k == n->size) { return {n, nullptr}; }\n    int s = (n->l ? n->l->size\
    \ : 0);\n    Node* b = new_node();\n    if (k <= s) {\n      auto [nl, nr] = split(n->l,\
    \ k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n    }\n    if\
    \ (k > s) {\n      auto [nl, nr] = split(n->r, k - s);\n      n->l = n->l, n->r\
    \ = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n), update(b);\n    return\
    \ {n, b};\n  }\n\n  np merge(np a, np b) {\n    if (!a) return b;\n    if (!b)\
    \ return a;\n    a->l = merge(a->l, b->l), a->r = merge(a->r, b->r);\n    update(a);\n\
    \    return a;\n  }\n\n  void update(np n) {\n    if (!(n->l) && !(n->r)) { return;\
    \ }\n    if (!(n->l)) {\n      n->x = n->r->x, n->rev_x = n->r->rev_x, n->size\
    \ = n->r->size;\n      return;\n    }\n    if (!(n->r)) {\n      n->x = n->l->x,\
    \ n->rev_x = n->l->rev_x, n->size = n->l->size;\n      return;\n    }\n    n->x\
    \ = MX::op(n->l->x, n->r->x);\n    n->rev_x = MX::op(n->r->rev_x, n->l->rev_x);\n\
    \    n->size = n->l->size + n->r->size;\n  }\n\n  void set_rec(np n, int l, int\
    \ r, int k, const X& x) {\n    if (r == l + 1) {\n      n->x = n->rev_x = x;\n\
    \      return;\n    }\n    int m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l))\
    \ n->l = new_node();\n      set_rec(n->l, l, m, k, x);\n    }\n    if (m <= k)\
    \ {\n      if (!(n->r)) n->r = new_node();\n      set_rec(n->r, m, r, k, x);\n\
    \    }\n    update(n);\n  }\n};"
  dependsOn:
  - ds/fastset.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: false
  path: ds/segtree/sortable_segtree.hpp
  requiredBy: []
  timestamp: '2023-01-02 17:13:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/sort_segtree_1.test.cpp
  - test/library_checker/datastructure/sort_segtree.test.cpp
documentation_of: ds/segtree/sortable_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/sortable_segtree.hpp
- /library/ds/segtree/sortable_segtree.hpp.html
title: ds/segtree/sortable_segtree.hpp
---
