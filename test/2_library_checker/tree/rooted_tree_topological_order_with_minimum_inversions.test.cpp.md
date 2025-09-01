---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/optimal_product_on_tree.hpp
    title: graph/optimal_product_on_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_topological_order_with_minimum_inversions\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/optimal_product_on_tree.hpp\"\
    \n\nstruct Data {\n  ll ans, x0, x1;\n};\n\nstruct Mono {\n  using value_type\
    \ = Data;\n  using X = value_type;\n  static X op(X x, X y) {\n    X z;\n    z.ans\
    \ = x.ans + y.ans + x.x1 * y.x0;\n    z.x0 = x.x0 + y.x0, z.x1 = x.x1 + y.x1;\n\
    \    return z;\n  }\n  static constexpr X unit() { return Data{0, 0, 0}; }\n \
    \ static constexpr bool commute = 0;\n};\n\nvoid solve() {\n  INT(N);\n  Graph<int,\
    \ 1> G(N);\n  FOR(v, 1, N) {\n    INT(p);\n    G.add(p, v);\n  }\n  G.build();\n\
    \  Tree<decltype(G)> tree(G);\n\n  vc<Data> A(N);\n  FOR(i, N) A[i].ans = 0;\n\
    \  FOR(i, N) {\n    INT(x);\n    A[i].x0 = x;\n  }\n  FOR(i, N) {\n    INT(x);\n\
    \    A[i].x1 = x;\n  }\n\n  auto comp = [&](Data x, Data y) -> bool {\n    if\
    \ (x.x0 == 0 && x.x1 == 0) return false;\n    if (y.x0 == 0 && y.x1 == 0) return\
    \ true;\n    return x.x0 * y.x1 > x.x1 * y.x0;\n  };\n  auto [ord, x] = optimal_product_on_tree<decltype(tree),\
    \ Mono, true>(tree, A, comp);\n  print(x.ans);\n  print(ord);\n}\n\nsigned main()\
    \ { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/optimal_product_on_tree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
- /verify/test/2_library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp.html
title: test/2_library_checker/tree/rooted_tree_topological_order_with_minimum_inversions.test.cpp
---
