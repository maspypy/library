---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/ds/dynamic_tree_dp.hpp
    title: graph/ds/dynamic_tree_dp.hpp
  - icon: ':x:'
    path: graph/ds/static_toptree.hpp
    title: graph/ds/static_toptree.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/dynamic_tree_dp.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nstruct Data {\n  mint\
    \ a, b; // path composition = x -> ax+b\n  mint cnt;\n  mint ans;\n};\n\nstruct\
    \ TREE_DP {\n  using value_type = Data;\n  using X = value_type;\n  static X rake(X\
    \ &L, X &R) { return {L.a, L.b, L.cnt + R.cnt, L.ans + R.ans}; }\n  static X compress(X\
    \ &L, X &R) {\n    mint a = L.a, b = L.b;\n    mint c = R.a, d = R.b;\n    //\
    \ x -> (cx+d) -> a(cx+d)+b\n    mint aa = a * c, bb = a * d + b;\n    mint cnt\
    \ = L.cnt + R.cnt;\n    mint ans = L.ans + a * R.ans + b * R.cnt;\n    return\
    \ {aa, bb, cnt, ans};\n  }\n};\n\nvoid solve() {\n  LL(N, Q);\n  VEC(mint, A,\
    \ N);\n  vc<mint> B(N - 1), C(N - 1);\n  Graph<int, 0> G(N);\n  FOR(i, N - 1)\
    \ {\n    INT(u, v);\n    G.add(u, v);\n    read(B[i], C[i]);\n  }\n  G.build();\n\
    \n  Tree<decltype(G)> tree(G);\n\n  auto single = [&](int v) -> Data {\n    if\
    \ (v == 0) { return {1, 0, 1, A[v]}; }\n    int e = tree.v_to_e(v);\n    return\
    \ {B[e], C[e], 1, B[e] * A[v] + C[e]};\n  };\n\n  Dynamic_Tree_Dp<decltype(tree),\
    \ TREE_DP> DP(tree, single);\n\n  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n \
    \     INT(w, x);\n      A[w] = x;\n      DP.set(w, single(w));\n    }\n    if\
    \ (t == 1) {\n      INT(e, b, c);\n      B[e] = b, C[e] = c;\n      int v = tree.e_to_v(e);\n\
    \      DP.set(v, single(v));\n    }\n    Data x = DP.prod_all();\n    print(x.ans);\n\
    \  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/dynamic_tree_dp.hpp
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/2_library_checker/tree/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
