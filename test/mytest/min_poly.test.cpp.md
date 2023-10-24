---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/mat_mul.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\n#include \"linalg/spmat_min_poly.hpp\"\
    \n#include \"linalg/implicit_matrix/min_poly.hpp\"\n#include \"linalg/mat_mul.hpp\"\
    \n\nusing mint = modint998;\n\nvoid test() {\n  vc<tuple<int, int, mint>> A;\n\
    \  A.eb(0, 0, 1);\n  A.eb(0, 1, 2);\n  A.eb(1, 0, 3);\n  A.eb(1, 1, 4);\n  vc<mint>\
    \ f = spmat_min_poly<mint>(2, A);\n  assert(f == vc<mint>({mint(-2), mint(-5),\
    \ mint(1)}));\n\n  A.clear();\n  A.eb(0, 1, 1);\n  f = spmat_min_poly<mint>(2,\
    \ A);\n  assert(f == vc<mint>({mint(0), mint(0), mint(1)}));\n  assert(f == implicit_matrix_min_poly<mint>(2,\
    \ [&](vc<mint> a) -> vc<mint> {\n           vc<mint> b(2);\n           for (auto&&\
    \ [i, j, x]: A) b[j] += a[i] * x;\n           return b;\n         }));\n\n  A.clear();\n\
    \  f = spmat_min_poly<mint>(2, A);\n  assert(f == vc<mint>({mint(0), mint(1)}));\n\
    \  assert(f == implicit_matrix_min_poly<mint>(2, [&](vc<mint> a) -> vc<mint> {\n\
    \           vc<mint> b(2);\n           for (auto&& [i, j, x]: A) b[j] += a[i]\
    \ * x;\n           return b;\n         }));\n\n  A.clear();\n  f = spmat_min_poly<mint>(0,\
    \ A);\n  assert(f == vc<mint>({mint(1)}));\n  assert(f == implicit_matrix_min_poly<mint>(0,\
    \ [&](vc<mint> a) -> vc<mint> {\n           vc<mint> b(0);\n           for (auto&&\
    \ [i, j, x]: A) b[j] += a[i] * x;\n           return b;\n         }));\n\n  A.clear();\n\
    \  A.eb(0, 1, 1);\n  A.eb(0, 2, 1);\n  A.eb(1, 2, 1);\n  f = spmat_min_poly<mint>(3,\
    \ A);\n  assert(f == vc<mint>({mint(0), mint(0), mint(0), mint(1)}));\n  assert(f\
    \ == implicit_matrix_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {\n       \
    \    vc<mint> b(3);\n           for (auto&& [i, j, x]: A) b[j] += a[i] * x;\n\
    \           return b;\n         }));\n\n  A.clear();\n  A.eb(0, 2, 1);\n  f =\
    \ spmat_min_poly<mint>(3, A);\n  assert(f == vc<mint>({mint(0), mint(0), mint(1)}));\n\
    \  assert(f == implicit_matrix_min_poly<mint>(3, [&](vc<mint> a) -> vc<mint> {\n\
    \           vc<mint> b(3);\n           for (auto&& [i, j, x]: A) b[j] += a[i]\
    \ * x;\n           return b;\n         }));\n\n  A.clear();\n  f = spmat_min_poly<mint>(3,\
    \ A);\n  assert(f == vc<mint>({mint(0), mint(1)}));\n  assert(f == implicit_matrix_min_poly<mint>(3,\
    \ [&](vc<mint> a) -> vc<mint> {\n           vc<mint> b(3);\n           for (auto&&\
    \ [i, j, x]: A) b[j] += a[i] * x;\n           return b;\n         }));\n\n  //\
    \ random matrix\n  FOR(N, 1, 20) {\n    vv(mint, mat, N, N);\n    FOR(i, N) FOR(j,\
    \ N) mat[i][j] = RNG(0, 998244353);\n    A.clear();\n    FOR(i, N) FOR(j, N) A.eb(i,\
    \ j, mat[i][j]);\n    f = spmat_min_poly(N, A);\n    assert(f == implicit_matrix_min_poly<mint>(N,\
    \ [&](vc<mint> a) -> vc<mint> {\n             vc<mint> b(N);\n             for\
    \ (auto&& [i, j, x]: A) b[j] += a[i] * x;\n             return b;\n          \
    \ }));\n    vv(mint, B, N, N);\n    FOR(i, N) B[i][i] = 1;\n    vv(mint, C, N,\
    \ N);\n    FOR(d, len(f)) {\n      FOR(i, N) FOR(j, N) C[i][j] += f[d] * B[i][j];\n\
    \      B = mat_mul(mat, B);\n    }\n    FOR(i, N) FOR(j, N) assert(C[i][j] ==\
    \ mint(0));\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned\
    \ main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/min_poly.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/min_poly.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/min_poly.test.cpp
- /verify/test/mytest/min_poly.test.cpp.html
title: test/mytest/min_poly.test.cpp
---
