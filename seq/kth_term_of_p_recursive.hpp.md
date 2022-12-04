---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/swag.hpp: line\
    \ -1: no such header\n"
  code: "#include \"poly/prefix_product_of_poly.hpp\"\n\n// a0, ..., a_{r-1} \u304A\
    \u3088\u3073 f_0, ..., f_r \u3092\u4E0E\u3048\u308B\n// a_r f_0(0) + a_{r-1}f_1(0)\
    \ + ... = 0\n// a_{r+1} f_0(1) + a_{r}f_1(1) + ... = 0\ntemplate <typename T>\n\
    T kth_term_of_p_recursive(vc<T> a, vc<vc<T>>& fs, ll k) {\n  int r = len(a);\n\
    \  assert(len(fs) == r + 1);\n  if (k < r) return a[k];\n\n  vc<vc<vc<T>>> A;\n\
    \  A.resize(r);\n  FOR(i, r) A[i].resize(r);\n  FOR(i, r) {\n    // A[0][i] =\
    \ -fs[i + 1];\n    for (auto&& x: fs[i + 1]) A[0][i].eb(-x);\n  }\n  FOR3(i, 1,\
    \ r) A[i][i - 1] = fs[0];\n  vc<T> den = fs[0];\n  auto res = prefix_product_of_poly_matrix(A,\
    \ k - r + 1);\n  reverse(all(a));\n  T ANS = 0;\n  FOR(j, r) ANS += res[0][j]\
    \ * a[j];\n  ANS /= prefix_product_of_poly(den, k - r + 1);\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/kth_term_of_p_recursive.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/kth_term_of_p_recursive.hpp
layout: document
redirect_from:
- /library/seq/kth_term_of_p_recursive.hpp
- /library/seq/kth_term_of_p_recursive.hpp.html
title: seq/kth_term_of_p_recursive.hpp
---
