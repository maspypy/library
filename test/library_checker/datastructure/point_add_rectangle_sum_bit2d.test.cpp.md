---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"ds/fenwick2d.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  vi X(N), Y(N),\
    \ W(N);\r\n  FOR(i, N) {\r\n    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] =\
    \ w;\r\n  }\r\n  using QQ = tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n \
    \ FOR(q, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(x, y, w);\r\n   \
    \   X.eb(x);\r\n      Y.eb(y);\r\n      W.eb(0);\r\n      query[q] = mt(-1, x,\
    \ y, w);\r\n    } else {\r\n      LL(a, b, c, d);\r\n      query[q] = mt(a, c,\
    \ b, d);\r\n    }\r\n  }\r\n\r\n  Fenwick2D<Group_Add<ll>, ll, false> bit(X, Y,\
    \ W);\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\n    if (a == -1)\
    \ {\r\n      bit.add(b, c, d);\r\n    } else {\r\n      print(bit.prod(a, b, c,\
    \ d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
---
