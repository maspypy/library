---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/kdtree/kdtree.hpp
    title: ds/kdtree/kdtree.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc234/tasks/abc234_Ex
    links:
    - https://atcoder.jp/contests/abc234/tasks/abc234_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/kdtree/kdtree.hpp\"\
    \n\nvoid solve() {\n  LL(N, K);\n  vc<int> X(N), Y(N);\n  FOR(i, N) {\n    INT(a,\
    \ b);\n    X[i] = a, Y[i] = b;\n  }\n  KDTree<int> KDT(X, Y);\n\n  int x_min =\
    \ MIN(X);\n  int x_max = MAX(X);\n  int y_min = MIN(Y);\n  int y_max = MAX(Y);\n\
    \n  vc<pair<int, int>> ANS;\n  FOR(i, N) {\n    ll a = X[i] - K, b = X[i] + K\
    \ + 1, c = Y[i] - K, d = Y[i] + K + 1;\n    chmax(a, x_min), chmin(b, x_max +\
    \ 1);\n    chmax(c, y_min), chmin(d, y_max + 1);\n    vc<int> I = KDT.collect_rect(a,\
    \ b, c, d);\n    sort(all(I));\n    for (auto&& j: I) {\n      if (i >= j) continue;\n\
    \      ll dx = X[i] - X[j], dy = Y[i] - Y[j];\n      if (dx * dx + dy * dy <=\
    \ K * K) { ANS.eb(i, j); }\n    }\n  }\n  print(len(ANS));\n  for (auto&& [i,\
    \ j]: ANS) print(1 + i, 1 + j);\n}\n\nsigned main() {\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/kdtree/kdtree.hpp
  isVerificationFile: true
  path: test_atcoder/abc234ex.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc234ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc234ex.test.cpp
- /verify/test_atcoder/abc234ex.test.cpp.html
title: test_atcoder/abc234ex.test.cpp
---
