---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid_pow.hpp
    title: alg/monoid_pow.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc200/tasks/abc200_f
    links:
    - https://atcoder.jp/contests/abc200/tasks/abc200_f
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
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc200/tasks/abc200_f\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"alg/monoid_pow.hpp\"\n\nusing mint = modint107;\n\nusing P = pair<mint,\
    \ mint>;\nusing ARR = array<array<P, 2>, 2>;\n\nstruct Mono {\n  using value_type\
    \ = ARR;\n  using X = value_type;\n  static X op(X x, X y) {\n    if (x == unit())\
    \ return y;\n    if (y == unit()) return x;\n    X z = unit();\n    FOR(i, 2)\
    \ FOR(j, 2) z[i][j] = {mint(0), mint(0)};\n    FOR(a, 2) FOR(b, 2) FOR(c, 2) FOR(d,\
    \ 2) {\n      auto& dp1 = x[a][b];\n      auto& dp2 = y[c][d];\n      z[a][d].fi\
    \ += dp1.fi * dp2.fi;\n      z[a][d].se += dp1.fi * dp2.se + dp2.fi * dp1.se;\n\
    \      if (b != c) z[a][b].se += dp1.fi * dp2.fi;\n    }\n    return z;\n  }\n\
    \  static X unit() {\n    X x;\n    FOR(i, 2) FOR(j, 2) x[i][j] = {mint(0), mint(0)};\n\
    \    return x;\n  }\n  static X from_element(char c) {\n    X t = unit();\n  \
    \  FOR(x, 2) {\n      if (x == 0 && c == '1') continue;\n      if (x == 1 && c\
    \ == '0') continue;\n      t[x][x] = {1, 0};\n    }\n    return t;\n  }\n  static\
    \ constexpr bool commute = 0;\n};\n\nvoid solve() {\n  STR(S);\n  INT(K);\n  ARR\
    \ x = Mono::unit();\n  for (auto&& c: S) x = Mono::op(x, Mono::from_element(c));\n\
    \n  ARR e = monoid_pow<Mono>(x, K);\n  mint ANS = 0;\n  FOR(a, 2) FOR(b, 2) {\n\
    \    auto [cnt, sm] = e[a][b];\n    if (a != b) ANS += (sm + cnt) * inv<mint>(2);\n\
    \    if (a == b) ANS += sm * inv<mint>(2);\n  }\n  print(ANS);\n}\n\nsigned main()\
    \ {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - alg/monoid_pow.hpp
  isVerificationFile: true
  path: test_atcoder/abc200f.test.cpp
  requiredBy: []
  timestamp: '2024-08-07 16:19:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc200f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc200f.test.cpp
- /verify/test_atcoder/abc200f.test.cpp.html
title: test_atcoder/abc200f.test.cpp
---
