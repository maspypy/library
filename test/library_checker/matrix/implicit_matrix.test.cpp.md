---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/implicit_matrix/det.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sparse_matrix_det\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"linalg/implicit_matrix/det.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n \
    \ LL(N, K);\n  using T = tuple<int, int, mint>;\n  VEC(T, dat, K);\n  auto f =\
    \ [&](vc<mint> v) -> vc<mint> {\n    vc<mint> w(N);\n    for (auto&& [a, b, c]:\
    \ dat) { w[b] += v[a] * c; }\n    return w;\n  };\n  mint det = implicit_matrix_det<mint>(N,\
    \ f);\n  print(det);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/matrix/implicit_matrix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/matrix/implicit_matrix.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/matrix/implicit_matrix.test.cpp
- /verify/test/library_checker/matrix/implicit_matrix.test.cpp.html
title: test/library_checker/matrix/implicit_matrix.test.cpp
---
