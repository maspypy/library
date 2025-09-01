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
    path: graph/ds/dynamic_rerooting_tree_dp.hpp
    title: graph/ds/dynamic_rerooting_tree_dp.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"graph/ds/dynamic_rerooting_tree_dp.hpp\"\n\nusing mint = modint998;\n\
    \nstruct Data {\n  // type, s, t \u306F\u5FC5\u305A\u5B9A\u7FA9\u3059\u308B. \uFF08\
    \u7D4C\u9A13\u4E0A\u3069\u3046\u305B\u30C7\u30D0\u30C3\u30B0\u3067\u5FC5\u8981\
    \u306B\u306A\u308B\uFF09. s \u304C\u6839.\n  // type==0: s\u304C virtual. type==1:\
    \ t \u304C virtual.\n  int type, s, t;\n  mint a, b; // path composition\n  mint\
    \ cnt, ans;\n};\n\nstruct TREE_DP {\n  using value_type = Data;\n  using X = value_type;\n\
    \n  static X rake(const X& L, const X& R) {\n    assert(L.type == 0 && R.type\
    \ == 0 && L.s == R.s);\n    X ANS = {0, L.s, L.t};\n\n    ANS.a = L.a, ANS.b =\
    \ L.b;\n    ANS.cnt = L.cnt + R.cnt, ANS.ans = L.ans + R.ans;\n    return ANS;\n\
    \  }\n  static X rake2(const X& L, const X& R) {\n    assert(L.type == 1 && R.type\
    \ == 0 && L.s == R.s);\n    X ANS = {1, L.s, L.t};\n\n    ANS.a = L.a, ANS.b =\
    \ L.b;\n    ANS.cnt = L.cnt + R.cnt, ANS.ans = L.ans + R.ans;\n    return ANS;\n\
    \  }\n  static X compress(const X& L, const X& R) {\n    assert(L.type == 0 &&\
    \ R.type == 0 && L.t == R.s);\n    X ANS = {0, L.s, R.t};\n\n    ANS.a = L.a *\
    \ R.a, ANS.b = L.a * R.b + L.b;\n    ANS.cnt = L.cnt + R.cnt, ANS.ans = L.ans\
    \ + (L.a * R.ans + L.b * R.cnt);\n    return ANS;\n  }\n  static X compress2(const\
    \ X& L, const X& R) {\n    assert(L.type == 1 && R.type == 1 && L.t == R.s);\n\
    \    X ANS = {1, L.s, R.t};\n\n    ANS.a = L.a * R.a, ANS.b = L.a * R.b + L.b;\n\
    \    ANS.cnt = L.cnt + R.cnt, ANS.ans = L.ans + (L.a * R.ans + L.b * R.cnt);\n\
    \    return ANS;\n  }\n  static X compress3(const X& L, const X& R) {\n    assert(L.type\
    \ == 1 && R.type == 0 && L.t == R.s);\n    X ANS = {1, L.s, L.t};\n\n    ANS.a\
    \ = L.a, ANS.b = L.b;\n    ANS.cnt = L.cnt + R.cnt, ANS.ans = L.ans + (L.a * R.ans\
    \ + L.b * R.cnt);\n    return ANS;\n  }\n};\n\nvoid solve() {\n  LL(N, Q);\n \
    \ VEC(mint, A, N);\n  vc<mint> B(N - 1), C(N - 1);\n  Graph<int, 0> G(N);\n  FOR(i,\
    \ N - 1) {\n    INT(u, v);\n    G.add(u, v);\n    read(B[i], C[i]);\n  }\n  G.build();\n\
    \n  Tree<decltype(G)> tree(G);\n\n  auto single = [&](int v) -> pair<Data, Data>\
    \ {\n    if (v == 0) {\n      Data up = {0, -1, 0, 1, 0, 1, A[v]};\n      Data\
    \ down = {1, 0, -1, 1, 0, 1, A[v]};\n      return {up, down};\n    }\n    int\
    \ e = tree.v_to_e(v);\n    int p = tree.parent[v];\n    Data up = {0, p, v, B[e],\
    \ C[e], 1, B[e] * A[v] + C[e]};\n    Data down = {1, v, p, B[e], C[e], 1, A[v]};\n\
    \    return {up, down};\n  };\n\n  Dynamic_Rerooting_Tree_Dp<decltype(tree), TREE_DP>\
    \ DP(tree, single);\n  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      INT(w,\
    \ x);\n      A[w] = x;\n      DP.set(w, single(w));\n    }\n    if (t == 1) {\n\
    \      INT(e, b, c);\n      B[e] = b, C[e] = c;\n      int v = tree.e_to_v(e);\n\
    \      DP.set(v, single(v));\n    }\n    INT(r);\n    Data x = DP.prod_all(r);\n\
    \    print(x.ans);\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - graph/ds/dynamic_rerooting_tree_dp.hpp
  - graph/ds/static_toptree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
- /verify/test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp.html
title: test/2_library_checker/tree/point_set_tree_path_composite_sum.test.cpp
---
