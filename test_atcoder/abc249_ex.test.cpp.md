---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/solve_linear_lower.hpp
    title: linalg/solve_linear_lower.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc249/tasks/abc249_Ex
    links:
    - https://atcoder.jp/contests/abc249/tasks/abc249_Ex
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc249/tasks/abc249_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"mod/powertable.hpp\"\n#include \"linalg/solve_linear_lower.hpp\"\n\
    \nusing mint = modint998;\n\nvoid solve() {\n  LL(N);\n  VEC(ll, A, N);\n  for\
    \ (auto&& x: A) --x;\n  vi CNT(N);\n  for (auto&& x: A) CNT[x]++;\n  vc<mint>\
    \ iPOW = powertable_1<mint>(mint(2).inverse(), N);\n\n  auto f = [&]() -> vc<mint>\
    \ {\n    // \u3044\u307E x \u500B\u3067\u3042\u308B\u3082\u306E\u3092\u30B3\u30F3\
    \u30D7\u3059\u308B\u56DE\u6570\u671F\u5F85\u5024 f(x) \u3092\u6C42\u3081\u308B\
    \n    vv(mint, mat, N + 1, N + 1);\n    vc<mint> rhs(N + 1, mint(1));\n    rhs[N]\
    \ = mint(0);\n    mat[N][N] = mint(1);\n    FOR(x, N) {\n      mat[x][x] = 1;\n\
    \      mint p = mint(x) * inv<mint>(N);\n      FOR(y, x) { mat[x][y + 1] -= p\
    \ * iPOW[x - 1] * C<mint, 0, 1>(x - 1, y); }\n      p = mint(N - x) * inv<mint>(N);\n\
    \      FOR(y, x + 1) {\n        mat[x][y] -= p * iPOW[x + 1] * C<mint, 0, 1>(x,\
    \ y);\n        mat[x][y + 1] -= p * iPOW[x + 1] * C<mint, 0, 1>(x, y);\n     \
    \ }\n    }\n    vv(mint, sub, N, N);\n    FOR(i, N) FOR(j, N) sub[i][j] = mat[i][j\
    \ + 1];\n    vc<mint> x = solve_linear_lower(sub, vc<mint>(N, mint(1)));\n   \
    \ x.insert(x.begin(), mint(0));\n    mint add = -mint(x.back());\n    for (auto&&\
    \ a: x) a += add;\n    return x;\n  }();\n  mint ANS = 0;\n  FOR(i, N) ANS +=\
    \ f[CNT[i]];\n  ANS -= mint(N - 1) * f[0];\n  ANS /= mint(N);\n  print(ANS);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  solve();\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - linalg/solve_linear_lower.hpp
  isVerificationFile: true
  path: test_atcoder/abc249_ex.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc249_ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc249_ex.test.cpp
- /verify/test_atcoder/abc249_ex.test.cpp.html
title: test_atcoder/abc249_ex.test.cpp
---
