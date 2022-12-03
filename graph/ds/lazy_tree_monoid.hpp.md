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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/lazysegtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/segtree/lazysegtree.hpp\"\r\n#include \"graph/tree.hpp\"\r\n\
    \r\ntemplate <typename TREE, typename ActedMonoid, bool edge = false>\r\nstruct\
    \ LazyTreeMonoid {\r\n  using MonoX = typename ActedMonoid::Monoid_X;\r\n  using\
    \ MonoA = typename ActedMonoid::Monoid_A;\r\n  using X = typename MonoX::value_type;\r\
    \n  using A = typename MonoA::value_type;\r\n  TREE &tree;\r\n  int N;\r\n  LazySegTree<ActedMonoid>\
    \ seg;\r\n\r\n  LazyTreeMonoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N)\
    \ {\r\n    assert(MonoX::commute);\r\n  }\r\n\r\n  LazyTreeMonoid(TREE &tree,\
    \ vc<X> dat) : tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, MonoX::unit());\r\
    \n    if (!edge) {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];\r\n    }\
    \ else {\r\n      FOR(e, N - 1) {\r\n        int v = tree.e_to_v(e);\r\n     \
    \   seg_raw[tree.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = LazySegTree<ActedMonoid>(seg_raw);\r\
    \n    assert(MonoX::commute);\r\n  }\r\n\r\n  void set(int i, X x) {\r\n    if\
    \ (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\n    seg.set(i, x);\r\n\
    \  }\r\n\r\n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      val\
    \ = MonoX::op(val, x);\r\n    }\r\n    return val;\r\n  }\r\n\r\n  X prod_subtree(int\
    \ u) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.prod(l +\
    \ edge, r);\r\n  }\r\n\r\n  X prod_all() { return seg.prod_all(); }\r\n\r\n  void\
    \ apply_path(int u, int v, A a) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    for (auto &&[x, y]: pd) {\r\n      int l = min(x, y), r = max(x,\
    \ y);\r\n      seg.apply(l, r + 1, a);\r\n    }\r\n  }\r\n\r\n  void apply_subtree(int\
    \ u, A a) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.apply(l\
    \ + edge, r, a);\r\n  }\r\n\r\n  template <class F>\r\n  int max_path(F &check,\
    \ int u, int v) {\r\n    if (edge) return max_path_edge(check, u, v);\r\n    if\
    \ (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MonoX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1) : seg.prod(b, a + 1));\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.V[b]);\r\n \
    \       continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\
    \r\n        auto i = seg.max_right(check_tmp, a);\r\n        return (i == a ?\
    \ u : tree.V[i - 1]);\r\n      } else {\r\n        // \u4E0A\u308A\r\n       \
    \ auto i = seg.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\
    \n        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    private:\r\n  template <class F>\r\n  int max_path_edge(F &check, int u, int v)\
    \ {\r\n    assert(edge);\r\n    if (!check(MonoX::unit())) return -1;\r\n    int\
    \ lca = tree.lca(u, v);\r\n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\
    \n    X val = MonoX::unit();\r\n\r\n    // climb\r\n    for (auto &&[a, b]: pd)\
    \ {\r\n      assert(a >= b);\r\n      X x = seg.prod(b, a + 1);\r\n      if (check(MonoX::op(val,\
    \ x))) {\r\n        val = MonoX::op(val, x);\r\n        u = (tree.parent[tree.V[b]]);\r\
    \n        continue;\r\n      }\r\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MonoX::op(val, x)); };\r\n      auto i = seg.min_left(check_tmp, a + 1);\r\
    \n      if (i == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n\
    \    }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\
    \n    for (auto &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = seg.prod(a,\
    \ b + 1);\r\n      if (check(MonoX::op(val, x))) {\r\n        val = MonoX::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(MonoX::op(val, x)); };\r\n     \
    \ auto i = seg.max_right(check_tmp, a);\r\n      return (i == a ? u : tree.V[i\
    \ - 1]);\r\n    }\r\n    return v;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/lazy_tree_monoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/lazy_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/lazy_tree_monoid.hpp
- /library/graph/ds/lazy_tree_monoid.hpp.html
title: graph/ds/lazy_tree_monoid.hpp
---
