---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/lichao.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"convex/lichao.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  using T = tuple<ll, ll, ll, ll, ll>;\n  vc<T>\
    \ dat(N + Q);\n  FOR(i, N) {\n    LL(l, r, a, b);\n    dat[i] = {0, l, r, a, b};\n\
    \  }\n  vi X;\n  FOR3(i, N, N + Q) {\n    LL(t);\n    if (t == 1) {\n      LL(x);\n\
    \      dat[i] = {1, x, 0, 0, 0};\n      X.eb(x);\n    } else {\n      LL(l, r,\
    \ a, b);\n      dat[i] = {0, l, r, a, b};\n    }\n  }\n\n  LiChaoTree<ll> seg(X);\n\
    \  FOR(i, N + Q) {\n    auto [t, l, r, a, b] = dat[i];\n    if (t == 0) {\n  \
    \    seg.add(l, r, a, b);\n    } else {\n      ll y = seg.get_min(l);\n      if\
    \ (y == infty<ll>)\n        print(\"INFINITY\");\n      else\n        print(y);\n\
    \    }\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/segment_add_get_min.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/segment_add_get_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/segment_add_get_min.test.cpp
- /verify/test/library_checker/datastructure/segment_add_get_min.test.cpp.html
title: test/library_checker/datastructure/segment_add_get_min.test.cpp
---
