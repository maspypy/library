---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/dsu_on_tree.hpp
    title: graph/dsu_on_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ~~~~~~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ~~~~~~~~~~~~~~~~~~~~~~~^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 472, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \               **kwargs).stdout\n               ^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/subprocess.py\"\
    , line 577, in run\n    raise CalledProcessError(retcode, process.args,\n    \
    \                         output=stdout, stderr=stderr)\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/library/library', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/library/library/other/io.hpp']' returned non-zero\
    \ exit status 1.\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dsu_on_tree.hpp\"\
    \n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n\
    \  VEC(ll, A, N);\n  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    LL(p);\n    G.add(p,\
    \ v);\n  }\n  G.build();\n  Tree tree(G);\n\n  vi ANS(Q, -1);\n  vvc<pair<int,\
    \ int>> query(N);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v, x);\n\
    \      query[v].eb(q, x);\n    }\n    if (t == 1) {\n      LL(v);\n      query[v].eb(q,\
    \ -1);\n    }\n  }\n\n  FenwickTree<Monoid_Add<ll>> bit(Q);\n  vc<pair<int, int>>\
    \ history;\n  ll base_sum = 0;\n\n  auto ADD = [&](int v) -> void {\n    base_sum\
    \ += A[v];\n    for (auto&& [q, x]: query[v]) {\n      if (x != -1) {\n      \
    \  bit.add(q, x);\n        history.eb(q, x);\n      }\n    }\n  };\n  auto QUERY\
    \ = [&](int v) -> void {\n    for (auto&& [q, x]: query[v]) {\n      if (x ==\
    \ -1) ANS[q] = base_sum + bit.sum(q);\n    }\n  };\n  auto RESET = [&]() -> void\
    \ {\n    base_sum = 0;\n    for (auto&& [q, x]: history) bit.add(q, -x);\n   \
    \ history.clear();\n  };\n  DSU_on_Tree(tree, ADD, QUERY, RESET);\n  for (auto&&\
    \ ans: ANS)\n    if (ans != -1) print(ans);\n}\n\nsigned main() {\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/dsu_on_tree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
- /verify/test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp.html
title: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
---
