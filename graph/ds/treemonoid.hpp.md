---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i
    - https://codeforces.com/contest/1059/problem/E
    - https://codeforces.com/contest/1230/problem/E
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/reverse_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"ds/segtree.hpp\"\r\n#include \"graph/tree.hpp\"\
    \r\n#include \"alg/monoid/reverse_monoid.hpp\"\r\n\r\ntemplate <typename TREE,\
    \ typename Monoid, bool edge = false>\r\nstruct TreeMonoid {\r\n  using RevMonoid\
    \ = Monoid_Reverse<Monoid>;\r\n  using X = typename Monoid::value_type;\r\n  TREE\
    \ &tree;\r\n  int N;\r\n  SegTree<Monoid> seg;\r\n  SegTree<RevMonoid> seg_r;\r\
    \n\r\n  TreeMonoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {\r\n    if\
    \ (!Monoid::commute) seg_r = SegTree<RevMonoid>(tree.N);\r\n  }\r\n\r\n  TreeMonoid(TREE\
    \ &tree, vc<X> &dat) : tree(tree), N(tree.N) {\r\n    vc<X> seg_raw(N, Monoid::unit());\r\
    \n    if (!edge) {\r\n      FOR(v, N) seg_raw[tree.LID[v]] = dat[v];\r\n    }\
    \ else {\r\n      FOR(e, N - 1) {\r\n        int v = tree.e_to_v(e);\r\n     \
    \   seg_raw[tree.LID[v]] = dat[e];\r\n      }\r\n    }\r\n    seg = SegTree<Monoid>(seg_raw);\r\
    \n    if (!Monoid::commute) seg_r = SegTree<RevMonoid>(seg_raw);\r\n  }\r\n\r\n\
    \  void set(int i, X x) {\r\n    if (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\
    \n    seg.set(i, x);\r\n    if (!Monoid::commute) seg_r.set(i, x);\r\n  }\r\n\r\
    \n  X prod_path(int u, int v) {\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      val = Monoid::op(val, x);\r\n    }\r\n    return val;\r\n\
    \  }\r\n\r\n  // uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\
    \u305F\u3059\u6700\u5F8C\u306E x\r\n  // \u306A\u3051\u308C\u3070 -1\r\n  // https://codeforces.com/contest/1059/problem/E\r\
    \n  // https://codeforces.com/contest/1230/problem/E\r\n  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i\r\
    \n  // edge \u304C\u7279\u306B\u602A\u3057\u3044\u304B\u3082\r\n  template <class\
    \ F>\r\n  int max_path(F &check, int u, int v) {\r\n    if (edge) return max_path_edge(check,\
    \ u, v);\r\n    if (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = Monoid::unit();\r\n    for (auto &&[a, b]: pd) {\r\n\
    \      X x = (a <= b ? seg.prod(a, b + 1)\r\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\r\n                                       : seg_r.prod(b,\
    \ a + 1)));\r\n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val,\
    \ x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\n    \
    \  if (a <= b) {\r\n        // \u4E0B\u308A\r\n        auto i = seg.max_right(check_tmp,\
    \ a);\r\n        return (i == a ? u : tree.V[i - 1]);\r\n      } else {\r\n  \
    \      // \u4E0A\u308A\r\n        auto i = (Monoid::commute ? seg.min_left(check_tmp,\
    \ a + 1)\r\n                                  : seg_r.min_left(check_tmp, a +\
    \ 1));\r\n        if (i == a + 1) return u;\r\n        return tree.V[i];\r\n \
    \     }\r\n    }\r\n    return v;\r\n  }\r\n\r\n  X prod_subtree(int u) {\r\n\
    \    int l = tree.LID[u], r = tree.RID[u];\r\n    return seg.prod(l + edge, r);\r\
    \n  }\r\n\r\n  void debug() {\r\n    print(\"tree_monoid\");\r\n    tree.debug();\r\
    \n    seg.debug();\r\n    seg_r.debug();\r\n  }\r\n\r\nprivate:\r\n  template\
    \ <class F>\r\n  int max_path_edge(F &check, int u, int v) {\r\n    assert(edge);\r\
    \n    if (!check(Monoid::unit())) return -1;\r\n    int lca = tree.lca(u, v);\r\
    \n    auto pd = tree.get_path_decomposition(u, lca, edge);\r\n    X val = Monoid::unit();\r\
    \n\r\n    // climb\r\n    for (auto &&[a, b]: pd) {\r\n      assert(a >= b);\r\
    \n      X x = (Monoid::commute ? seg.prod(b, a + 1) : seg_r.prod(b, a + 1));\r\
    \n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val, x);\r\
    \n        u = (tree.parent[tree.V[b]]);\r\n        continue;\r\n      }\r\n  \
    \    auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\
    \n      auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\r\n       \
    \                         : seg_r.min_left(check_tmp, a + 1));\r\n      if (i\
    \ == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n    }\r\n   \
    \ // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\n    for (auto\
    \ &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = seg.prod(a, b + 1);\r\
    \n      if (check(Monoid::op(val, x))) {\r\n        val = Monoid::op(val, x);\r\
    \n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(Monoid::op(val, x)); };\r\n      auto i =\
    \ seg.max_right(check_tmp, a);\r\n      return (i == a ? u : tree.V[i - 1]);\r\
    \n    }\r\n    return v;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/treemonoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/treemonoid.hpp
layout: document
redirect_from:
- /library/graph/ds/treemonoid.hpp
- /library/graph/ds/treemonoid.hpp.html
title: graph/ds/treemonoid.hpp
---
