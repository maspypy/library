---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/sortable_array.test.cpp
    title: test/mytest/sortable_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc217e.test.cpp
    title: test_atcoder/abc217e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc237g1.test.cpp
    title: test_atcoder/abc237g1.test.cpp
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
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void add(int\
    \ i) { insert(i); }\r\n  void erase(int i) {\r\n    for (int h = 0; h < lg; h++)\
    \ {\r\n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B])\
    \ break;\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int i) { erase(i);\
    \ }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\
    \u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i) {\r\n\
    \    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int h = 0; h < lg;\
    \ h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull d = seg[h][i\
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
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l, r)\r\
    \n  template <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    int\
    \ x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n      if (x >= r)\
    \ break;\r\n      f(x);\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    string\
    \ s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n   \
    \ print(s);\r\n  }\r\n};\r\n#line 2 \"ds/sortable_array.hpp\"\n\n// int \u5217\
    \u3092\u6271\u3046. key \u306E\u91CD\u8907\u53EF.\ntemplate <int NODES>\nstruct\
    \ Sortable_Array {\n  const int N, KEY_MAX;\n\n  struct Node {\n    int size;\n\
    \    Node *l, *r;\n  };\n  Node* pool;\n  int pid;\n  using np = Node*;\n\n  FastSet\
    \ ss;      // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n\
    \  vector<np> root; // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree\
    \ \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_Array(int\
    \ KEY_MAX, vector<int> key)\n      : N(key.size()), KEY_MAX(KEY_MAX), pid(0),\
    \ ss(key.size()) {\n    pool = new Node[NODES];\n    init(key);\n  }\n\n  void\
    \ set(int i, int key) {\n    assert(0 <= key && key < KEY_MAX);\n    split_at(i),\
    \ split_at(i + 1);\n    rev[i] = 0, root[i] = new_node(0);\n    set_rec(root[i],\
    \ 0, KEY_MAX, key);\n  }\n\n  void sort_inc(int l, int r) {\n    if (l == r) return;\n\
    \    split_at(l), split_at(r);\n    while (1) {\n      if (pid > NODES * 0.9)\
    \ rebuild();\n      np c = root[l];\n      int i = ss.next(l + 1);\n      if (i\
    \ == r) break;\n      root[l] = merge(0, KEY_MAX, c, root[i]);\n      ss.erase(i);\n\
    \    }\n    rev[l] = 0;\n  };\n\n  void sort_dec(int l, int r) {\n    if (l ==\
    \ r) return;\n    if (pid > NODES * 0.9) rebuild();\n    sort_inc(l, r), rev[l]\
    \ = 1;\n  };\n\n  vc<int> get_all() {\n    vector<int> key;\n    key.reserve(N);\n\
    \    auto dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n     \
    \ if (!n || !n->size) return;\n      if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n\
    \        return;\n      }\n      int m = (l + r) / 2;\n      if (!rev) { dfs(dfs,\
    \ n->l, l, m, rev), dfs(dfs, n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r,\
    \ m, r, rev), dfs(dfs, n->l, l, m, rev); }\n    };\n    for (int i = 0; i < N;\
    \ ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n   \
    \ return key;\n  }\n\n  int get(int idx) {\n    auto dfs = [&](auto& dfs, np n,\
    \ int l, int r, int k) -> int {\n      if (r == l + 1) { return l; }\n      int\
    \ m = (l + r) / 2;\n      int s = (n->l ? n->l->size : 0);\n      if (k < s) return\
    \ dfs(dfs, n->l, l, m, k);\n      return dfs(dfs, n->r, m, r, k - s);\n    };\n\
    \    int i = ss.prev(idx);\n    int k = idx - i;\n    int s = root[i]->size;\n\
    \    if (rev[i]) k = s - 1 - k;\n    return dfs(dfs, root[i], 0, KEY_MAX, k);\n\
    \  }\n\nprivate:\n  void init(vector<int>& key) {\n    rev.assign(N, 0), root.clear(),\
    \ root.reserve(N);\n    for (int i = 0; i < N; ++i) {\n      ss.insert(i);\n \
    \     root.eb(new_node(0));\n      assert(key[i] < KEY_MAX);\n      set_rec(root[i],\
    \ 0, KEY_MAX, key[i]);\n    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\
    \u3088\u3046\u306B\u3059\u308B\n  void split_at(int x) {\n    if (x == N || ss[x])\
    \ return;\n    int a = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n  \
    \  if (!rev[a]) {\n      auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n\
    \      root[a] = nl, root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n\
    \      auto [nl, nr] = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n\
    \    auto key = get_all();\n    pid = 0;\n    init(key);\n  }\n\n  np new_node(int\
    \ size) {\n    assert(pid < NODES);\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].size = size;\n    return &(pool[pid++]);\n  }\n\n  pair<np, np>\
    \ split(np n, int l, int r, int k) {\n    if (k == 0) { return {nullptr, n}; }\n\
    \    if (k == n->size) { return {n, nullptr}; }\n    if (r == l + 1) {\n     \
    \ int s = n->size;\n      n->size = k;\n      Node* b = new_node(s - k);\n   \
    \   return {n, b};\n    }\n    int s = (n->l ? n->l->size : 0);\n    Node* b =\
    \ new_node(0);\n    int m = (l + r) / 2;\n    if (k <= s) {\n      auto [nl, nr]\
    \ = split(n->l, l, m, k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n\
    \    }\n    if (k > s) {\n      auto [nl, nr] = split(n->r, m, r, k - s);\n  \
    \    n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n),\
    \ update(b);\n    return {n, b};\n  }\n\n  np merge(int l, int r, np a, np b)\
    \ {\n    if (!a) return b;\n    if (!b) return a;\n    if (r == l + 1) {\n   \
    \   a->size += b->size;\n      return a;\n    }\n    int m = (l + r) / 2;\n  \
    \  a->l = merge(l, m, a->l, b->l), a->r = merge(m, r, a->r, b->r);\n    update(a);\n\
    \    return a;\n  }\n\n  void update(np n) {\n    if (!(n->l) && !(n->r)) { return;\
    \ }\n    if (!(n->l)) {\n      n->size = n->r->size;\n      return;\n    }\n \
    \   if (!(n->r)) {\n      n->size = n->l->size;\n      return;\n    }\n    n->size\
    \ = n->l->size + n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k)\
    \ {\n    if (r == l + 1) {\n      n->size = 1;\n      return;\n    }\n    int\
    \ m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node(0);\n\
    \      set_rec(n->l, l, m, k);\n    }\n    if (m <= k) {\n      if (!(n->r)) n->r\
    \ = new_node(0);\n      set_rec(n->r, m, r, k);\n    }\n    update(n);\n  }\n\
    };\n"
  code: "#include \"ds/fastset.hpp\"\n\n// int \u5217\u3092\u6271\u3046. key \u306E\
    \u91CD\u8907\u53EF.\ntemplate <int NODES>\nstruct Sortable_Array {\n  const int\
    \ N, KEY_MAX;\n\n  struct Node {\n    int size;\n    Node *l, *r;\n  };\n  Node*\
    \ pool;\n  int pid;\n  using np = Node*;\n\n  FastSet ss;      // \u533A\u9593\
    \u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n  vector<np> root; //\
    \ \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree \u306E node \u3092\
    \u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_Array(int KEY_MAX, vector<int>\
    \ key)\n      : N(key.size()), KEY_MAX(KEY_MAX), pid(0), ss(key.size()) {\n  \
    \  pool = new Node[NODES];\n    init(key);\n  }\n\n  void set(int i, int key)\
    \ {\n    assert(0 <= key && key < KEY_MAX);\n    split_at(i), split_at(i + 1);\n\
    \    rev[i] = 0, root[i] = new_node(0);\n    set_rec(root[i], 0, KEY_MAX, key);\n\
    \  }\n\n  void sort_inc(int l, int r) {\n    if (l == r) return;\n    split_at(l),\
    \ split_at(r);\n    while (1) {\n      if (pid > NODES * 0.9) rebuild();\n   \
    \   np c = root[l];\n      int i = ss.next(l + 1);\n      if (i == r) break;\n\
    \      root[l] = merge(0, KEY_MAX, c, root[i]);\n      ss.erase(i);\n    }\n \
    \   rev[l] = 0;\n  };\n\n  void sort_dec(int l, int r) {\n    if (l == r) return;\n\
    \    if (pid > NODES * 0.9) rebuild();\n    sort_inc(l, r), rev[l] = 1;\n  };\n\
    \n  vc<int> get_all() {\n    vector<int> key;\n    key.reserve(N);\n    auto dfs\
    \ = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n      if (!n || !n->size)\
    \ return;\n      if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n        return;\n\
    \      }\n      int m = (l + r) / 2;\n      if (!rev) { dfs(dfs, n->l, l, m, rev),\
    \ dfs(dfs, n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r, m, r, rev), dfs(dfs,\
    \ n->l, l, m, rev); }\n    };\n    for (int i = 0; i < N; ++i) {\n      if (ss[i])\
    \ dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n    return key;\n  }\n\n  int\
    \ get(int idx) {\n    auto dfs = [&](auto& dfs, np n, int l, int r, int k) ->\
    \ int {\n      if (r == l + 1) { return l; }\n      int m = (l + r) / 2;\n   \
    \   int s = (n->l ? n->l->size : 0);\n      if (k < s) return dfs(dfs, n->l, l,\
    \ m, k);\n      return dfs(dfs, n->r, m, r, k - s);\n    };\n    int i = ss.prev(idx);\n\
    \    int k = idx - i;\n    int s = root[i]->size;\n    if (rev[i]) k = s - 1 -\
    \ k;\n    return dfs(dfs, root[i], 0, KEY_MAX, k);\n  }\n\nprivate:\n  void init(vector<int>&\
    \ key) {\n    rev.assign(N, 0), root.clear(), root.reserve(N);\n    for (int i\
    \ = 0; i < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(0));\n     \
    \ assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i]);\n   \
    \ }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n      root[a] = nl,\
    \ root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n      auto [nl, nr]\
    \ = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr, root[x] = nl;\n  \
    \    rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n    auto key = get_all();\n\
    \    pid = 0;\n    init(key);\n  }\n\n  np new_node(int size) {\n    assert(pid\
    \ < NODES);\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].size = size;\n\
    \    return &(pool[pid++]);\n  }\n\n  pair<np, np> split(np n, int l, int r, int\
    \ k) {\n    if (k == 0) { return {nullptr, n}; }\n    if (k == n->size) { return\
    \ {n, nullptr}; }\n    if (r == l + 1) {\n      int s = n->size;\n      n->size\
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
    \ update(np n) {\n    if (!(n->l) && !(n->r)) { return; }\n    if (!(n->l)) {\n\
    \      n->size = n->r->size;\n      return;\n    }\n    if (!(n->r)) {\n     \
    \ n->size = n->l->size;\n      return;\n    }\n    n->size = n->l->size + n->r->size;\n\
    \  }\n\n  void set_rec(np n, int l, int r, int k) {\n    if (r == l + 1) {\n \
    \     n->size = 1;\n      return;\n    }\n    int m = (l + r) / 2;\n    if (k\
    \ < m) {\n      if (!(n->l)) n->l = new_node(0);\n      set_rec(n->l, l, m, k);\n\
    \    }\n    if (m <= k) {\n      if (!(n->r)) n->r = new_node(0);\n      set_rec(n->r,\
    \ m, r, k);\n    }\n    update(n);\n  }\n};\n"
  dependsOn:
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/sortable_array.hpp
  requiredBy: []
  timestamp: '2023-08-13 11:37:00+05:30'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/sortable_array.test.cpp
  - test_atcoder/abc217e.test.cpp
  - test_atcoder/abc237g1.test.cpp
documentation_of: ds/sortable_array.hpp
layout: document
redirect_from:
- /library/ds/sortable_array.hpp
- /library/ds/sortable_array.hpp.html
title: ds/sortable_array.hpp
---
