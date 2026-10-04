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
    \ seg.set(i, MX::id());\n    }\n    rev[l] = 0, seg.set(l, root[l]->x);\n  };\n\
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
    \ < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(MX::id()));\n     \
    \ assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n\
    \    } else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x),\
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    auto [key,\
    \ dat] = get_all();\n    pool.reset();\n    init(key, dat);\n  }\n\n  np new_node(X\
    \ x = MX::id()) {\n    np c = pool.create();\n    c->x = c->rev_x = x;\n    c->l\
    \ = c->r = nullptr;\n    c->size = 1;\n    return c;\n  }\n\n  pair<np, np> split(np\
    \ n, int k) {\n    if (k == 0) {\n      return {nullptr, n};\n    }\n    if (k\
    \ == n->size) {\n      return {n, nullptr};\n    }\n    int s = (n->l ? n->l->size\
    \ : 0);\n    Node* b = new_node();\n    if (k <= s) {\n      auto [nl, nr] = split(n->l,\
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
    \ m, r, k, x);\n    }\n    update(n);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/sortable_segtree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/sortable_segtree.hpp
layout: document
redirect_from:
- /library/ds/segtree/sortable_segtree.hpp
- /library/ds/segtree/sortable_segtree.hpp.html
title: ds/segtree/sortable_segtree.hpp
---
