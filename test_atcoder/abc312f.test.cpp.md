---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/removable_queue.hpp
    title: ds/removable_queue.hpp
  - icon: ':x:'
    path: ds/slide_split_sum.hpp
    title: ds/slide_split_sum.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc312/tasks/abc312_f
    links:
    - https://atcoder.jp/contests/abc312/tasks/abc312_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc312/tasks/abc312_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/slide_split_sum.hpp\"\
    \n\nvoid solve() {\n  LL(N, M);\n  vi A, B, C;\n  ll ANS = 0;\n  FOR(N) {\n  \
    \  LL(t, x);\n    if (t == 0) C.eb(x);\n    if (t == 1) B.eb(x);\n    if (t ==\
    \ 2) A.eb(x);\n  }\n  sort(all(A));\n  reverse(all(A));\n  sort(all(B));\n  reverse(all(B));\n\
    \  sort(all(C));\n  reverse(all(C));\n\n  Slide_Split_Sum<ll> SSS;\n  auto calc\
    \ = [&](ll n) -> void {\n    int k = min(n, len(SSS));\n    chmax(ANS, SSS.query_r(k));\n\
    \  };\n  for (auto&& x: C) SSS.insert(x);\n  calc(M);\n\n  ll p = 0;\n  for (auto&&\
    \ a: A) {\n    FOR(i, p, p + a) {\n      if (i >= len(B)) break;\n      SSS.insert(B[i]);\n\
    \    }\n    M -= 1;\n    p += a;\n    if (M == 0) break;\n    calc(M);\n  }\n\
    \  print(ANS);\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/slide_split_sum.hpp
  - ds/removable_queue.hpp
  isVerificationFile: true
  path: test_atcoder/abc312f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc312f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc312f.test.cpp
- /verify/test_atcoder/abc312f.test.cpp.html
title: test_atcoder/abc312f.test.cpp
---
