---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i,\
    \ N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ>\
    \ query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n\
    \      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y,\
    \ w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n\
    \    }\n  }\n\n  Wavelet_Matrix_2D_Range_Dynamic_AbelGroup<Monoid_Add<ll>, int,\
    \ false, false>\n      WM(len(X), [&](int i) -> tuple<int, int, ll> {\n      \
    \  return {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n    auto\
    \ [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.add(idx++, d);\n\
    \    } else {\n      print(WM.sum(a, b, c, d));\n    }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
---
