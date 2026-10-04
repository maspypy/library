---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.14/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: ds/sortable_array.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/sortable_array.hpp
layout: document
redirect_from:
- /library/ds/sortable_array.hpp
- /library/ds/sortable_array.hpp.html
title: ds/sortable_array.hpp
---
