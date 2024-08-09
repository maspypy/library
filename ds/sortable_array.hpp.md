---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/sortable_array.test.cpp
    title: test/mytest/sortable_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2809.test.cpp
    title: test/yukicoder/2809.test.cpp
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
  bundledCode: "#line 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63)\
    \ * u64\r\nstruct FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\
    \n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\
    \n  int size() { return n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\
    \n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n\
    \      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n\
    \  }\r\n  template <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\
    \n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log -\
    \ 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\r\n      }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const\
    \ { return seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    for\
    \ (int h = 0; h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /=\
    \ B;\r\n    }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i)\
    \ {\r\n    u64 x = 0;\r\n    for (int h = 0; h < log; h++) {\r\n      seg[h][i\
    \ / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B] |= x << (i % B);\r\n  \
    \    x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int next(int i) {\r\n    assert(i\
    \ <= n);\r\n    chmax(i, 0);\r\n    for (int h = 0; h < log; h++) {\r\n      if\
    \ (i / B == seg[h].size()) break;\r\n      u64 d = seg[h][i / B] >> (i % B);\r\
    \n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\n      }\r\n\
    \      i += lowbit(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n       \
    \ i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\
    \n    }\r\n    return n;\r\n  }\r\n\r\n  // max [0,x], or -1\r\n  int prev(int\
    \ i) {\r\n    assert(i >= -1);\r\n    if (i >= n) i = n - 1;\r\n    for (int h\
    \ = 0; h < log; h++) {\r\n      if (i == -1) break;\r\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n     \
    \   continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += topbit(seg[g][i /\
    \ B]);\r\n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n\
    \  bool any(int l, int r) { return next(l) < r; }\r\n\r\n  // [l, r)\r\n  template\
    \ <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    for (int x = next(l);\
    \ x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n  string to_string() {\r\n    string\
    \ s(n, '?');\r\n    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\
    \n    return s;\r\n  }\r\n};\n#line 2 \"ds/sortable_array.hpp\"\n\n// int \u5217\
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
    \ root.reserve(N);\n    ss.build(N, [&](int i) -> int { return 1; });\n    for\
    \ (int i = 0; i < N; ++i) {\n      root.eb(new_node(0));\n      assert(key[i]\
    \ < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i]);\n    }\n  }\n\n  //\
    \ x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n  void\
    \ split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a = ss.prev(x),\
    \ b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n      auto [nl,\
    \ nr] = split(root[a], 0, KEY_MAX, x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n    } else {\n      auto [nl, nr] = split(root[a],\
    \ 0, KEY_MAX, b - x);\n      root[a] = nr, root[x] = nl;\n      rev[a] = rev[x]\
    \ = 1;\n    }\n  }\n\n  void rebuild() {\n    auto key = get_all();\n    pid =\
    \ 0;\n    init(key);\n  }\n\n  np new_node(int size) {\n    assert(pid < NODES);\n\
    \    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].size = size;\n    return\
    \ &(pool[pid++]);\n  }\n\n  pair<np, np> split(np n, int l, int r, int k) {\n\
    \    if (k == 0) { return {nullptr, n}; }\n    if (k == n->size) { return {n,\
    \ nullptr}; }\n    if (r == l + 1) {\n      int s = n->size;\n      n->size =\
    \ k;\n      Node* b = new_node(s - k);\n      return {n, b};\n    }\n    int s\
    \ = (n->l ? n->l->size : 0);\n    Node* b = new_node(0);\n    int m = (l + r)\
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
    \ key) {\n    rev.assign(N, 0), root.clear(), root.reserve(N);\n    ss.build(N,\
    \ [&](int i) -> int { return 1; });\n    for (int i = 0; i < N; ++i) {\n     \
    \ root.eb(new_node(0));\n      assert(key[i] < KEY_MAX);\n      set_rec(root[i],\
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
  dependsOn:
  - ds/fastset.hpp
  isVerificationFile: false
  path: ds/sortable_array.hpp
  requiredBy: []
  timestamp: '2024-04-27 11:55:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2809.test.cpp
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
