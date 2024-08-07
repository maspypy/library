---
data:
  _extendedDependsOn:
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
    PROBLEM: https://atcoder.jp/contests/abc326/tasks/abc326_g
    links:
    - https://atcoder.jp/contests/abc326/tasks/abc326_g
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc326/tasks/abc326_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"flow/maxflow.hpp\"\
    \n\nvoid solve() {\n  LL(N, M);\n  VEC(ll, C, N);\n  VEC(ll, A, M);\n\n  int s\
    \ = 0;\n  int t = 1;\n  auto idx = [&](int i, int j) -> int {\n    if (j == 0)\
    \ return s;\n    if (j == 5) return t;\n    return 2 + 4 * i + (j - 1);\n  };\n\
    \  auto idx_a = [&](int i) -> int { return idx(N, 1) + i; };\n\n  MaxFlow<ll>\
    \ G(idx_a(M), s, t);\n\n  FOR(i, N) {\n    FOR(j, 5) G.add(idx(i, j + 1), idx(i,\
    \ j), infty<ll>);\n    FOR(j, 1, 5) G.add(idx(i, j), idx(i, j + 1), C[i] * j);\n\
    \  }\n\n  FOR(j, M) { G.add(s, idx_a(j), A[j]); }\n\n  FOR(j, M) FOR(i, N) {\n\
    \    INT(x);\n    if (x == 1) continue;\n    G.add(idx_a(j), idx(i, x - 1), infty<ll>);\n\
    \  }\n\n  // G.debug();\n\n  ll ANS = SUM<ll>(A);\n  ANS -= G.flow();\n  // print(G.flow_ans);\n\
    \  print(ANS);\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/maxflow.hpp
  isVerificationFile: true
  path: test_atcoder/abc326g.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc326g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc326g.test.cpp
- /verify/test_atcoder/abc326g.test.cpp.html
title: test_atcoder/abc326g.test.cpp
---
