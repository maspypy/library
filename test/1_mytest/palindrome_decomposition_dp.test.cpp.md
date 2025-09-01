---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: string/palindrome_decomposition_dp.hpp
    title: string/palindrome_decomposition_dp.hpp
  - icon: ':x:'
    path: string/palindromic_tree.hpp
    title: string/palindromic_tree.hpp
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"string/palindrome_decomposition_dp.hpp\"\
    \n\nvoid test_min_palindrome_decomposition() {\n  FOR(N, 30) {\n    FOR(K, 1,\
    \ 5) {\n      FOR(10) {\n        string S;\n        FOR(N) {\n          char c\
    \ = 'a' + RNG(0, K);\n          S += c;\n        }\n        vv(int, is_pal, N\
    \ + 1, N + 1);\n        FOR_R(L, N + 1) {\n          FOR(R, N + 1) {\n       \
    \     if (R - L <= 1) {\n              is_pal[L][R] = 1;\n              continue;\n\
    \            }\n            is_pal[L][R] = (S[L] == S[R - 1]) && is_pal[L + 1][R\
    \ - 1];\n          }\n        }\n        vc<int> DP(N + 1, infty<int>);\n    \
    \    DP[0] = 0;\n        FOR(R, 1, N + 1) {\n          FOR(L, R) {\n         \
    \   if (is_pal[L][R]) chmin(DP[R], DP[L] + 1);\n          }\n        }\n     \
    \   vc<int> dp_init(N + 1, infty<int>);\n        dp_init[0] = 0;\n        auto\
    \ F = [&](int i, int a, int g) -> int { return min(a, g + 1); };\n        auto\
    \ G = [&](int i, int g, int a) -> int { return min(g, a); };\n\n        vc<int>\
    \ dp = palindrome_decomposition_dp<int, int>(S, dp_init,\n                   \
    \                                        infty<int>, F, G);\n        assert(dp\
    \ == DP);\n      }\n    }\n  }\n}\n\nvoid test_cnt_palindrome_decomposition()\
    \ {\n  FOR(N, 30) {\n    FOR(K, 1, 5) {\n      FOR(10) {\n        string S;\n\
    \        FOR(N) {\n          char c = 'a' + RNG(0, K);\n          S += c;\n  \
    \      }\n        vv(int, is_pal, N + 1, N + 1);\n        FOR_R(L, N + 1) {\n\
    \          FOR(R, N + 1) {\n            if (R - L <= 1) {\n              is_pal[L][R]\
    \ = 1;\n              continue;\n            }\n            is_pal[L][R] = (S[L]\
    \ == S[R - 1]) && is_pal[L + 1][R - 1];\n          }\n        }\n        vc<int>\
    \ DP(N + 1, 0);\n        DP[0] = 1;\n        FOR(R, 1, N + 1) {\n          FOR(L,\
    \ R) {\n            if (is_pal[L][R]) DP[R] += DP[L];\n          }\n        }\n\
    \        vc<int> dp_init(N + 1);\n        dp_init[0] = 1;\n        auto F = [&](int\
    \ i, int a, int g) -> int { return a + g; };\n        auto G = [&](int i, int\
    \ g, int a) -> int { return g + a; };\n\n        vc<int> dp = palindrome_decomposition_dp<int,\
    \ int>(S, dp_init, 0, F, G);\n        assert(dp == DP);\n      }\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_min_palindrome_decomposition();\n  test_cnt_palindrome_decomposition();\n\
    \  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - string/palindrome_decomposition_dp.hpp
  - string/palindromic_tree.hpp
  isVerificationFile: true
  path: test/1_mytest/palindrome_decomposition_dp.test.cpp
  requiredBy: []
  timestamp: '2025-09-01 20:17:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/palindrome_decomposition_dp.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/palindrome_decomposition_dp.test.cpp
- /verify/test/1_mytest/palindrome_decomposition_dp.test.cpp.html
title: test/1_mytest/palindrome_decomposition_dp.test.cpp
---
