---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':x:'
    path: graph/tree_dp/rerooting_dp.hpp
    title: graph/tree_dp/rerooting_dp.hpp
  - icon: ':x:'
    path: graph/tree_dp/subtree_depth_sum.hpp
    title: graph/tree_dp/subtree_depth_sum.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc298/tasks/abc298_Ex
    links:
    - https://atcoder.jp/contests/abc298/tasks/abc298_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc298/tasks/abc298_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/tree_dp/subtree_depth_sum.hpp\"\
    \n#include \"graph/base.hpp\"\n\nvoid solve() {\n  LL(N);\n  Graph<int, 0> G(N);\n\
    \  G.read_tree();\n  Tree<decltype(G)> tree(G);\n\n  SubTree_DepthSum<decltype(tree),\
    \ ll> DP(tree);\n\n  LL(Q);\n  FOR(Q) {\n    LL(A, B);\n    --A, --B;\n    ll\
    \ d = tree.dist(A, B);\n\n    ll ANS = 0;\n    if (d == 0) { ANS = DP[A].se; }\n\
    \    elif (d % 2 == 1) {\n      ll A1 = tree.jump(A, B, d / 2);\n      ll B1 =\
    \ tree.jump(B, A, d / 2);\n      ANS += DP[A].se;\n      ANS -= DP.get(B1, A).se\
    \ + ll(tree.dist(A, B1)) * DP.get(B1, A).fi;\n      ANS += DP[B].se;\n      ANS\
    \ -= DP.get(A1, B).se + ll(tree.dist(B, A1)) * DP.get(A1, B).fi;\n    }\n    else\
    \ {\n      ll C = tree.jump(A, B, d / 2);\n      ll A1 = tree.jump(C, A, 1);\n\
    \      ll B1 = tree.jump(C, B, 1);\n      ANS += DP[A].se;\n      ANS -= DP.get(C,\
    \ A).se + ll(tree.dist(A, C)) * DP.get(C, A).fi;\n      ANS += DP[B].se;\n   \
    \   ANS -= DP.get(C, B).se + ll(tree.dist(B, C)) * DP.get(C, B).fi;\n      ll\
    \ x = 0;\n      ll n = 0;\n      x += DP[C].se;\n      x -= DP.get(A1, C).se +\
    \ DP.get(A1, C).fi;\n      x -= DP.get(B1, C).se + DP.get(B1, C).fi;\n      n\
    \ += DP[C].fi - DP.get(A1, C).fi - DP.get(B1, C).fi;\n      ANS += x + n * d /\
    \ 2;\n    }\n    print(ANS);\n  }\n}\n\nsigned main() {\n  solve();\n  return\
    \ 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/tree_dp/subtree_depth_sum.hpp
  - graph/tree_dp/rerooting_dp.hpp
  - graph/base.hpp
  - graph/tree.hpp
  isVerificationFile: true
  path: test_atcoder/abc298ex.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc298ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc298ex.test.cpp
- /verify/test_atcoder/abc298ex.test.cpp.html
title: test_atcoder/abc298ex.test.cpp
---
