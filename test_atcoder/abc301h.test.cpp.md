---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  - icon: ':question:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':x:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':question:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/ds/dual_tree_monoid.hpp
    title: graph/ds/dual_tree_monoid.hpp
  - icon: ':x:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc301/tasks/abc301_Ex
    links:
    - https://atcoder.jp/contests/abc301/tasks/abc301_Ex
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc301/tasks/abc301_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/unionfind/unionfind.hpp\"\
    \n#include \"graph/ds/tree_monoid.hpp\"\n#include \"alg/monoid/max.hpp\"\n#include\
    \ \"alg/monoid/min_idx.hpp\"\n#include \"graph/ds/dual_tree_monoid.hpp\"\n\nvoid\
    \ solve() {\n  LL(N, M);\n  using T = tuple<int, int, int>;\n  vc<T> dat;\n  FOR(i,\
    \ M) {\n    LL(a, b, c);\n    --a, --b;\n    dat.eb(c, a, b);\n  }\n  auto I =\
    \ argsort(dat);\n  dat = rearrange(dat, I);\n  auto new_idx = argsort(I);\n\n\
    \  vc<bool> used(M);\n  vc<int> tree_idx(M, -1);\n  Graph<int, 0> G(N);\n  UnionFind\
    \ uf(N);\n  int p = 0;\n  FOR(i, M) {\n    auto [c, a, b] = dat[i];\n    if (uf.merge(a,\
    \ b)) {\n      G.add(a, b, c);\n      used[i] = 1;\n      tree_idx[i] = p++;\n\
    \    }\n  }\n  G.build();\n\n  Tree<decltype(G)> tree(G);\n  Tree_Monoid<decltype(tree),\
    \ Monoid_Max<int>, true> TM(\n      tree, [&](int eid) -> int { return G.edges[eid].cost;\
    \ });\n\n  // \u5404\u8FBA\u306B\u3064\u3044\u3066\u3001\u7981\u6B62\u3057\u305F\
    \u3068\u304D\u306B\u3069\u308C\u304C\u4F7F\u308F\u308C\u308B\u304B\uFF1F\n  Dual_Tree_Monoid<decltype(tree),\
    \ Monoid_Min_Idx<int>, true> DTM(tree);\n\n  FOR(eid, M) {\n    if (used[eid])\
    \ continue;\n    auto [c, a, b] = dat[eid];\n    DTM.apply_path(a, b, {c, eid});\n\
    \  }\n\n  vc<int> new_use(N - 1);\n  {\n    auto tmp = DTM.get_all();\n    assert(len(tmp)\
    \ == N - 1);\n    FOR(i, N - 1) new_use[i] = tmp[i].se;\n  }\n\n  auto calc =\
    \ [&](int eid, int s, int t) -> int {\n    if (!used[eid]) return 0;\n    int\
    \ c = get<0>(dat[eid]);\n    eid = tree_idx[eid];\n    ll now = TM.prod_path(s,\
    \ t);\n    TM.set(eid, c + 1);\n\n    ll after = TM.prod_path(s, t);\n\n    if\
    \ (now == after) return 0;\n    int k = new_use[eid];\n    if (k == -1) return\
    \ 1;\n    auto [cc, a, b] = dat[k];\n    ll x = max<int>({TM.prod_path(s, a),\
    \ cc, TM.prod_path(b, t)});\n    ll y = max<int>({TM.prod_path(s, b), cc, TM.prod_path(a,\
    \ t)});\n    chmin(after, x);\n    chmin(after, y);\n    return abs(after - now);\n\
    \  };\n\n  LL(Q);\n  FOR(Q) {\n    LL(eid, s, t);\n    --eid, --s, --t;\n    eid\
    \ = new_idx[eid];\n    print(calc(eid, s, t));\n    if (used[eid]) {\n      int\
    \ c = get<0>(dat[eid]);\n      eid = tree_idx[eid];\n      TM.set(eid, c);\n \
    \   }\n  }\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/unionfind/unionfind.hpp
  - graph/ds/tree_monoid.hpp
  - ds/segtree/segtree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - alg/monoid/monoid_reverse.hpp
  - alg/monoid/max.hpp
  - alg/monoid/min_idx.hpp
  - graph/ds/dual_tree_monoid.hpp
  - ds/segtree/dual_segtree.hpp
  isVerificationFile: true
  path: test_atcoder/abc301h.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc301h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc301h.test.cpp
- /verify/test_atcoder/abc301h.test.cpp.html
title: test_atcoder/abc301h.test.cpp
---
