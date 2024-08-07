---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  - icon: ':question:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc193/tasks/abc193_f
    links:
    - https://atcoder.jp/contests/abc193/tasks/abc193_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc193/tasks/abc193_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/binary_optimization.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(string, G, N);\n  const int INF = infty<int>;\n\
    \  Binary_Optimization<ll, 0> X(N * N);\n  auto idx = [&](int i, int j) -> int\
    \ { return N * i + j; };\n\n  FOR(i, N) FOR(j, N) {\n    int sgn = (i + j) % 2;\n\
    \    if (G[i][j] == 'B' && sgn == 0) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j]\
    \ == 'W' && sgn == 1) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j] == 'B' &&\
    \ sgn == 1) X.add_1(idx(i, j), 0, -INF);\n    if (G[i][j] == 'W' && sgn == 0)\
    \ X.add_1(idx(i, j), 0, -INF);\n  }\n\n  int dx[] = {0, 1};\n  int dy[] = {1,\
    \ 0};\n\n  FOR(x, N) FOR(y, N) {\n    FOR(d, 2) {\n      int nx = x + dx[d], ny\
    \ = y + dy[d];\n      if (nx >= N || ny >= N) continue;\n      int a = idx(x,\
    \ y), b = idx(nx, ny);\n      X.add_2(a, b, 1, 0, 0, 1);\n    }\n  }\n\n  ll ANS\
    \ = X.calc().fi;\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/binary_optimization.hpp
  - flow/maxflow.hpp
  isVerificationFile: true
  path: test_atcoder/abc193f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc193f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc193f.test.cpp
- /verify/test_atcoder/abc193f.test.cpp.html
title: test_atcoder/abc193f.test.cpp
---
