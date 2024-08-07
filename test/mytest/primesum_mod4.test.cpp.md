---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/primesum.hpp
    title: nt/primesum.hpp
  - icon: ':x:'
    path: nt/primesum_mod4.hpp
    title: nt/primesum_mod4.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"nt/primesum_mod4.hpp\"\n\nvoid test_count()\
    \ {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A3(LIM);\n  for (auto&& p: primetable(LIM))\n\
    \    if (p % 4 == 1) { A1[p]++; }\n  for (auto&& p: primetable(LIM))\n    if (p\
    \ % 4 == 3) { A3[p]++; }\n  A1 = cumsum<int>(A1, 0);\n  A3 = cumsum<int>(A3, 0);\n\
    \n  FOR(N, LIM) {\n    PrimeSum_Mod_4<int> X(N);\n    X.calc_count();\n    FOR(K,\
    \ 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }\n  }\n}\n\nvoid\
    \ test_sum() {\n  ll LIM = 10000;\n  vc<int> A1(LIM), A3(LIM);\n  for (auto&&\
    \ p: primetable(LIM))\n    if (p % 4 == 1) { A1[p] += p; }\n  for (auto&& p: primetable(LIM))\n\
    \    if (p % 4 == 3) { A3[p] += p; }\n  A1 = cumsum<int>(A1, 0);\n  A3 = cumsum<int>(A3,\
    \ 0);\n\n  FOR(N, LIM) {\n    PrimeSum_Mod_4<int> X(N);\n    X.calc_sum();\n \
    \   FOR(K, 1, N + 10) { assert(X[N / K] == mp(A1[N / K], A3[N / K])); }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_count();\n  test_sum();\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/primesum_mod4.hpp
  - nt/primesum.hpp
  - nt/primetable.hpp
  isVerificationFile: true
  path: test/mytest/primesum_mod4.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/primesum_mod4.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/primesum_mod4.test.cpp
- /verify/test/mytest/primesum_mod4.test.cpp.html
title: test/mytest/primesum_mod4.test.cpp
---
