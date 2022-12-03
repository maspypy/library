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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/disjoint_sparse/disjointsparse.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/disjoint_sparse/disjointsparse.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"alg/monoid/monoid_reverse.hpp\"\n\ntemplate <typename TREE, typename\
    \ Monoid, bool edge = false>\nstruct Static_Tree_Monoid {\n  using RevMonoid =\
    \ Monoid_Reverse<Monoid>;\n  using X = typename Monoid::value_type;\n  TREE &tree;\n\
    \  int N;\n  DisjointSparse<Monoid> seg;\n  DisjointSparse<RevMonoid> seg_r;\n\
    \n  Static_Tree_Monoid(TREE &tree) : tree(tree), N(tree.N), seg(tree.N) {\n  \
    \  if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(tree.N);\n  }\n\n \
    \ Static_Tree_Monoid(TREE &tree, vc<X> &dat) : tree(tree), N(tree.N) {\n    vc<X>\
    \ seg_raw(N, Monoid::unit());\n    if (!edge) {\n      FOR(v, N) seg_raw[tree.LID[v]]\
    \ = dat[v];\n    } else {\n      FOR(e, N - 1) {\n        int v = tree.e_to_v(e);\n\
    \        seg_raw[tree.LID[v]] = dat[e];\n      }\n    }\n    seg = DisjointSparse<Monoid>(seg_raw);\n\
    \    if (!Monoid::commute) seg_r = DisjointSparse<RevMonoid>(seg_raw);\n  }\n\n\
    \  X prod_path(int u, int v) {\n    auto pd = tree.get_path_decomposition(u, v,\
    \ edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n      X\
    \ x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute ? seg.prod(b,\
    \ a + 1)\n                                       : seg_r.prod(b, a + 1)));\n \
    \     val = Monoid::op(val, x);\n    }\n    return val;\n  }\n\n  // uv path \u4E0A\
    \u3067 prod_path(u, x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ x\n  // \u306A\u3051\u308C\u3070 -1\n  // https://codeforces.com/contest/1059/problem/E\n\
    \  // https://codeforces.com/contest/1230/problem/E\n  // edge: https://atcoder.jp/contests/tkppc3/tasks/tkppc3_i\n\
    \  // edge \u304C\u7279\u306B\u602A\u3057\u3044\u304B\u3082\n  template <class\
    \ F>\n  int max_path(F &check, int u, int v) {\n    if (edge) return max_path_edge(check,\
    \ u, v);\n    if (!check(prod_path(u, u))) return -1;\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\n    X val = Monoid::unit();\n    for (auto &&[a, b]: pd) {\n    \
    \  X x = (a <= b ? seg.prod(a, b + 1)\n                    : (Monoid::commute\
    \ ? seg.prod(b, a + 1)\n                                       : seg_r.prod(b,\
    \ a + 1)));\n      if (check(Monoid::op(val, x))) {\n        val = Monoid::op(val,\
    \ x);\n        u = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(Monoid::op(val, x)); };\n      if (a <= b)\
    \ {\n        // \u4E0B\u308A\n        auto i = seg.max_right(check_tmp, a);\n\
    \        return (i == a ? u : tree.V[i - 1]);\n      } else {\n        // \u4E0A\
    \u308A\n        auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n \
    \                                 : seg_r.min_left(check_tmp, a + 1));\n     \
    \   if (i == a + 1) return u;\n        return (edge ? tree.parent[tree.V[i]] :\
    \ tree.V[i]);\n      }\n    }\n    return v;\n  }\n\n  X prod_subtree(int u) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return seg.prod(l + edge, r);\n\
    \  }\n\n  void debug() {\n    print(\"tree_monoid\");\n    tree.debug();\n   \
    \ seg.debug();\n    seg_r.debug();\n  }\n\nprivate:\n  template <class F>\n  int\
    \ max_path_edge(F &check, int u, int v) {\n    assert(edge);\n    if (!check(Monoid::unit()))\
    \ return -1;\n    int lca = tree.lca(u, v);\n    auto pd = tree.get_path_decomposition(u,\
    \ lca, edge);\n    X val = Monoid::unit();\n\n    // climb\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a >= b);\n      X x = (Monoid::commute ? seg.prod(b,\
    \ a + 1) : seg_r.prod(b, a + 1));\n      if (check(Monoid::op(val, x))) {\n  \
    \      val = Monoid::op(val, x);\n        u = (tree.parent[tree.V[b]]);\n    \
    \    continue;\n      }\n      auto check_tmp = [&](X x) -> bool { return check(Monoid::op(val,\
    \ x)); };\n      auto i = (Monoid::commute ? seg.min_left(check_tmp, a + 1)\n\
    \                                : seg_r.min_left(check_tmp, a + 1));\n      if\
    \ (i == a + 1) return u;\n      return tree.parent[tree.V[i]];\n    }\n    //\
    \ down\n    pd = tree.get_path_decomposition(lca, v, edge);\n    for (auto &&[a,\
    \ b]: pd) {\n      assert(a <= b);\n      X x = seg.prod(a, b + 1);\n      if\
    \ (check(Monoid::op(val, x))) {\n        val = Monoid::op(val, x);\n        u\
    \ = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp = [&](X x)\
    \ -> bool { return check(Monoid::op(val, x)); };\n      auto i = seg.max_right(check_tmp,\
    \ a);\n      return (i == a ? u : tree.V[i - 1]);\n    }\n    return v;\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/ds/static_tree_monoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/static_tree_monoid.hpp
layout: document
redirect_from:
- /library/graph/ds/static_tree_monoid.hpp
- /library/graph/ds/static_tree_monoid.hpp.html
title: graph/ds/static_tree_monoid.hpp
---
