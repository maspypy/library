---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix_mod_2\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"linalg/bitset/mat_inv.hpp\"\
    \n\nusing BS = My_Bitset;\n\nvoid solve() {\n  LL(N);\n  vc<BS> mat(N);\n  FOR(i,\
    \ N) {\n    STR(S);\n    mat[i].resize(N);\n    FOR(j, N) mat[i][j] = (S[j] ==\
    \ '1');\n  }\n  mat = mat_inv(mat);\n  if (mat.empty()) return print(-1);\n  FOR(i,\
    \ N) print(mat[i].to_string());\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/linear_algebra/inverse_matrix_mod_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/linear_algebra/inverse_matrix_mod_2.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/linear_algebra/inverse_matrix_mod_2.test.cpp
- /verify/test/2_library_checker/linear_algebra/inverse_matrix_mod_2.test.cpp.html
title: test/2_library_checker/linear_algebra/inverse_matrix_mod_2.test.cpp
---
